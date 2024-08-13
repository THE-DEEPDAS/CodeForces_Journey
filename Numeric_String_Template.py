# template array has n integers 
# we also have m strings and want to check which string matches template
# it is a match if length of string = size of template
# if template[i] = template[j] then s[i] = s[j]
# if s[i] = s[j] then template[i] = template[j]
testcases = int(input())

for _ in range(testcases):
    n = int(input())
    template = list(map(int, input().split()))
    m = int(input())

    template_map = {}
    for i in range(n):
        value = template[i]
        if value not in template_map:
            template_map[value] = []
        template_map[value].append(i)
    
    for _ in range(m):
        s = input().strip()
        
        if len(s) != n:
            print("NO")
            continue
        
        s_map = {}
        for i in range(n):
            char = s[i]
            if char not in s_map:
                s_map[char] = []
            s_map[char].append(i)
        
        match = True
        for indices in template_map.values():
            found_match = False
            for s_indices in s_map.values():
                if sorted(indices) == sorted(s_indices):
                    found_match = True
                    break
            if not found_match:
                match = False
                break
        
        if match:
            print("YES")
        else:
            print("NO")