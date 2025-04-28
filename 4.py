def main():
    t = int(input()) 
    for _ in range(t):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        a.sort()
        m = n - k

        intervals = []
        for i in range(n - m + 1):
            if m % 2 == 1:
                median_pos = i + (m - 1) // 2
                start = a[median_pos]
                end = start
            else:
                left_pos = i + (m // 2 - 1)
                right_pos = i + m // 2
                start = a[left_pos]
                end = a[right_pos]
            intervals.append((start, end))

        intervals.sort()

        merged = []
        for interval in intervals:
            if not merged:
                merged.append(interval)
            else:
                last_start, last_end = merged[-1]
                current_start, current_end = interval
                if current_start <= last_end + 1:
                    merged[-1] = (last_start, max(last_end, current_end))
                else:
                    merged.append(interval)
        total = 0
        for start, end in merged:
            total += end - start + 1
        print(total)

main()