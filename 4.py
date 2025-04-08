import sys
import heapq

def can_form_permutation(N, P):
    # Max heap to store segments (-dist, -left_index, left, right)
    max_heap = []
    heapq.heappush(max_heap, (-N, -1, 1, N))  # (-distance, -index, left, right)
    
    seating = [0] * (N + 1)  # Stores the seating order
    for i in range(1, N + 1):  # People arrive in order
        while max_heap:
            _, neg_left, left, right = heapq.heappop(max_heap)
            mid = (left + right) // 2
            
            if seating[mid] == 0:  # Check if the seat is free
                seating[mid] = i  # Seat the person
                break
        
        # Check if the placement doesn't match the required permutation
        if seating[mid] != P[i - 1]:
            return "NO"
        
        # Push new segments to the heap if valid
        if left <= mid - 1:
            heapq.heappush(max_heap, (-(mid - left), -left, left, mid - 1))
        if mid + 1 <= right:
            heapq.heappush(max_heap, (-(right - mid), -mid, mid + 1, right))
    
    return "YES"

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        N = int(data[index])
        index += 1
        P = list(map(int, data[index:index + N]))
        index += N
        results.append(can_form_permutation(N, P))
    
    sys.stdout.write("\n".join(results) + "\n")

if __name__ == "__main__":
    main()
