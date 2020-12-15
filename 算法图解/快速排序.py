def qsort(array):
    if len(array) < 2:
        return array
    else:
        privot = array[0]
        less = [ i for i in array[1:] if i <= privot]
        more = [ i for i in array[1:] if i > privot]
        return qsort(less)+[privot]+qsort(more)

array = [1,2,55,23,4,2]
print(qsort(array))
