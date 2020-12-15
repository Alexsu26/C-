def sum(list):
    if list == []:
        return 0
    return list[0] + sum(list[1:])

def couNum(list):
    if list == []:
        return 0
    return 1 + couNum((list[1:]))

def max(list):
    if len(list) == 2:
        return list[0] if list[0] > list[1] else list[1]
    max_rest = max(list[1:])
    return list[0] if list[0] > max_rest else max_rest

list1 = [1,2,3,4]
print(sum(list1))
print(couNum(list1))
print(max(list1))
