#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    // Number of test cases
    ll numTestCases;
    cin >> numTestCases;

    while (numTestCases--)
    {
        // Number of students, teachers, and queries
        ll numStudents, numTeachers, numQueries;
        cin >> numStudents >> numTeachers >> numQueries;

        // Vector to store teacher positions
        vector<ll> teacherPositions(numTeachers);

        // Input teacher positions
        for (ll i = 0; i < numTeachers; i++)
        {
            cin >> teacherPositions[i];
        }

        // Sort teacher positions for easy access to nearest teachers
        sort(teacherPositions.begin(), teacherPositions.end());

        // Minimum and maximum teacher positions
        ll minTeacherPos = teacherPositions[0];
        ll maxTeacherPos = teacherPositions[numTeachers - 1];

        // Process each query
        while (numQueries--)
        {
            // Student's position
            ll studentPos;
            cin >> studentPos;

            // Minimum distance to a teacher
            ll minDistToTeacher = 0;

            // Case 1: If student is below the minimum teacher position
            if (studentPos < minTeacherPos)
            {
                minDistToTeacher = minTeacherPos - 1;
            }
            // Case 2: If student is above the maximum teacher position
            else if (studentPos > maxTeacherPos)
            {
                minDistToTeacher = numStudents - maxTeacherPos;
            }
            // Case 3: If student is between teachers
            else
            {
                // Find the nearest teacher below and above the student
                auto itUpper = upper_bound(teacherPositions.begin(), teacherPositions.end(), studentPos);
                auto itLower = prev(itUpper);

                ll teacherBelow = *itLower;
                ll teacherAbove = *itUpper;

                // Calculate the median position between the nearest teachers
                ll medianTeacherPos = (teacherBelow + teacherAbove) / 2;

                // Calculate the minimum distance to the median from both sides
                minDistToTeacher = min(abs(medianTeacherPos - teacherBelow), abs(teacherAbove - medianTeacherPos));
            }

            // Output the minimum distance to a teacher
            cout << minDistToTeacher << endl;
        }
    }
}