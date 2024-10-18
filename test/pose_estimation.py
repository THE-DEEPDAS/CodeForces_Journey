import numpy as np
import cv2
import sys
import time
from dronekit import connect, VehicleMode

# Connect to the Vehicle
connection_string = 'udp:142.0.0.1:14550'  # Change this to your connection string
vehicle = connect(connection_string, wait_ready=True)

ARUCO_DICT = {
	"DICT_4X4_50": cv2.aruco.DICT_4X4_50,
	"DICT_4X4_100": cv2.aruco.DICT_4X4_100,
	"DICT_4X4_250": cv2.aruco.DICT_4X4_250,
	"DICT_4X4_1000": cv2.aruco.DICT_4X4_1000,
	"DICT_5X5_50": cv2.aruco.DICT_5X5_50,
	"DICT_5X5_100": cv2.aruco.DICT_5X5_100,
	"DICT_5X5_250": cv2.aruco.DICT_5X5_250,
	"DICT_5X5_1000": cv2.aruco.DICT_5X5_1000,
	"DICT_6X6_50": cv2.aruco.DICT_6X6_50,
	"DICT_6X6_100": cv2.aruco.DICT_6X6_100,
	"DICT_6X6_250": cv2.aruco.DICT_6X6_250,
	"DICT_6X6_1000": cv2.aruco.DICT_6X6_1000,
	"DICT_7X7_50": cv2.aruco.DICT_7X7_50,
	"DICT_7X7_100": cv2.aruco.DICT_7X7_100,
	"DICT_7X7_250": cv2.aruco.DICT_7X7_250,
	"DICT_7X7_1000": cv2.aruco.DICT_7X7_1000,
	"DICT_ARUCO_ORIGINAL": cv2.aruco.DICT_ARUCO_ORIGINAL,
	"DICT_APRILTAG_16h5": cv2.aruco.DICT_APRILTAG_16h5,
	"DICT_APRILTAG_25h9": cv2.aruco.DICT_APRILTAG_25h9,
	"DICT_APRILTAG_36h10": cv2.aruco.DICT_APRILTAG_36h10,
	"DICT_APRILTAG_36h11": cv2.aruco.DICT_APRILTAG_36h11
}

def aruco_display(corners, ids, rejected, image):
    
	if len(corners) > 0:
		
		ids = ids.flatten()
		
		for (markerCorner, markerID) in zip(corners, ids):
			
			corners = markerCorner.reshape((4, 2))
			(topLeft, topRight, bottomRight, bottomLeft) = corners
			
			topRight = (int(topRight[0]), int(topRight[1]))
			bottomRight = (int(bottomRight[0]), int(bottomRight[1]))
			bottomLeft = (int(bottomLeft[0]), int(bottomLeft[1]))
			topLeft = (int(topLeft[0]), int(topLeft[1]))

			cv2.line(image, topLeft, topRight, (0, 255, 0), 2)
			cv2.line(image, topRight, bottomRight, (0, 255, 0), 2)
			cv2.line(image, bottomRight, bottomLeft, (0, 255, 0), 2)
			cv2.line(image, bottomLeft, topLeft, (0, 255, 0), 2)
			
			cX = int((topLeft[0] + bottomRight[0]) / 2.0)
			cY = int((topLeft[1] + bottomRight[1]) / 2.0)
			cv2.circle(image, (cX, cY), 4, (0, 0, 255), -1)
			
			cv2.putText(image, str(markerID),(topLeft[0], topLeft[1] - 10), cv2.FONT_HERSHEY_SIMPLEX,
				0.5, (0, 255, 0), 2)
			print("[Inference] ArUco marker ID: {}".format(markerID))
			
	return image

def send_attitude_commands(yaw, pitch, roll):
	# Set the vehicle mode to GUIDED
	vehicle.mode = VehicleMode("GUIDED")
	time.sleep(1)

	# Send the command to set the desired attitude
	vehicle.attitude = (roll, pitch, yaw)

def pose_estimation(frame, aruco_dict_type, matrix_coefficients, distortion_coefficients):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Use getPredefinedDictionary instead of Dictionary_get
    aruco_dict = cv2.aruco.getPredefinedDictionary(aruco_dict_type)
    parameters = cv2.aruco.DetectorParameters_create()

    corners, ids, rejected_img_points = cv2.aruco.detectMarkers(gray, aruco_dict, parameters=parameters,
        cameraMatrix=matrix_coefficients,
        distCoeff=distortion_coefficients)

    if len(corners) > 0:
        for i in range(len(ids)):
            marker_id = ids[i][0]
            rvec, tvec, markerPoints = cv2.aruco.estimatePoseSingleMarkers(corners[i], 0.02, matrix_coefficients,
                                                                           distortion_coefficients)

            # Convert rotation vector to rotation matrix
            R, _ = cv2.Rodrigues(rvec[0])

            # Check if the detected marker ID is 72
            if marker_id == 72:
                # Calculate the required rotation to face the camera
                desired_orientation = np.array([[0, 0, 1],  # Front
                                                 [0, 1, 0],  # Up
                                                 [-1, 0, 0]]) # Right

                # Calculate the current orientation
                current_orientation = R[:, 0:3]  # Get the rotation matrix

                # Calculate the rotation needed to align with the desired orientation
                rotation_needed = np.dot(desired_orientation, current_orientation.T)

                # Extract yaw, pitch, roll from the rotation matrix
                yaw = np.arctan2(rotation_needed[1][0], rotation_needed[0][0])
                pitch = np.arctan2(-rotation_needed[2][0], np.sqrt(rotation_needed[2][1]**2 + rotation_needed[2][2]**2))
                roll = np.arctan2(rotation_needed[2][1], rotation_needed[2][2])

                # Convert radians to degrees
                yaw = np.degrees(yaw)
                pitch = np.degrees(pitch)
                roll = np.degrees(roll)

                # Send commands to the drone to adjust its orientation
                send_attitude_commands(yaw, pitch, roll)

                # Draw the axes based on the adjusted orientation
                cv2.aruco.drawAxis(frame, matrix_coefficients, distortion_coefficients, rvec, tvec, 0.01)

            # Draw the detected markers and axes
            cv2.aruco.drawDetectedMarkers(frame, corners)
            cv2.aruco.drawAxis(frame, matrix_coefficients, distortion_coefficients, rvec, tvec, 0.01)

    return frame

# Main code to run the pose estimation and control the drone
aruco_type = "DICT_5X5_100"
intrinsic_camera = np.array(((933.15867, 0, 657.59), (0, 933.1586, 400.36993), (0, 0, 1)))
distortion = np.array((-0.43948, 0.18514, 0, 0))

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)

while cap.isOpened():
    ret, img = cap.read()
    output = pose_estimation(img, ARUCO_DICT[aruco_type], intrinsic_camera, distortion)
    cv2.imshow('Estimated Pose', output)

    key = cv2.waitKey(1) & 0xFF
    if key == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
vehicle.close()
