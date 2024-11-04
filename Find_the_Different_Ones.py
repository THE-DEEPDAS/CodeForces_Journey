def process_queries(testcases):
    results = []
    
    for _ in range(testcases):
        n = int(input())
        a = list(map(int, input().split()))
        
        q = int(input())
        queries = [tuple(map(int, input().split())) for _ in range(q)]

        # Preprocess to find the first occurrence of each value
        first_occurrence = {}
        for i in range(n):
            if a[i] not in first_occurrence:
                first_occurrence[a[i]] = i + 1  # Store 1-based index

        # Answer each query
        for left, right in queries:
            if a[left - 1] != a[right - 1]:  # Convert to 0-based index
                results.append(f"{left} {right}")
            else:
                found = False
                for key, index in first_occurrence.items():
                    if index >= left and index <= right and key != a[left - 1]:
                        results.append(f"{left} {index}")
                        found = True
                        break
                if not found:
                    results.append("-1 -1")
    
    print("\n".join(results))

# Input reading
t = int(input())
process_queries(t)
