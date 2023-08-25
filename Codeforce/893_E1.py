q = int(input())
stack = []
distinct_set = set()

for _ in range(q):
    query = input().split()
    if query[0] == '+':
        x = int(query[1])
        stack.append(('+', x))
        distinct_set.add(x)
    elif query[0] == '-':
        k = int(query[1])
        removed = []
        for _ in range(k):
            change_type, val = stack.pop()
            if change_type == '+':
                removed.append(val)
        for val in removed:
            distinct_set.discard(val)
    elif query[0] == '!':
        while stack and stack[-1][0] != '+':
            change_type, val = stack.pop()
            if change_type == '-':
                distinct_set.add(val)
            else:  # Rollback operation reached
                distinct_set.discard(val)
        if stack:
            change_type, val = stack.pop()
            distinct_set = set(x[1] for x in stack if x[0] == '+')
    elif query[0] == '?':
        print(len(distinct_set))

