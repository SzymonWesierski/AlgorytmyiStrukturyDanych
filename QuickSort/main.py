import random

def partition(list,p,r):
    i = p - 1
    x = list[r]

    for j in range(p, r):
        if list[j] <= x:
            i = i + 1
            list[i], list[j] = list[j], list[i]
    list[i + 1], list[r] = list[r], list[i + 1]
    return i + 1

def random_p(list,p,r):
    i = random.randrange(p, r)

    list[p], list[i] = list[i], list[p]
    return partition(list, p, r)

def quick_sort(list,p,r):
    if p < r:
        q = random_p(list, p, r)
        quick_sort(list, p, q - 1)
        quick_sort(list, q + 1, r)


list = input().split()
r = len(list) - 1
p = 0

quick_sort(list, p, r)

array = ""

for l in list:
    array += l + " "

print(array[:-1])


