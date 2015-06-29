def heapify(a, i, heap_size):
    l = 2*i
    r = 2*i + 1
    if l < heap_size and a[l] > a[i] :
        largest = l
    else:
        largest = i
    if r < heap_size and a[r] > a[largest]:
        largest = r
    if largest != i:
        temp = a[i]
        a[i] = a[largest]
        a[largest] = temp
        heapify(a, largest, heap_size)

def build_heap(a, heap_size):
    for i in range(int((heap_size-1)/2), 0, -1):
        heapify(a, i, heap_size - 1)

        
a = input().split()
a = [0] + a
a = list(map(int, a))


build_heap(a, len(a))
heap_size = len(a) 
for i in range(len(a) -1, 0, -1):
    temp = a[i]
    a[i] = a[1]
    a[1] = temp
    heap_size -= 1
    heapify(a, 1, heap_size)

a.remove(0)
print(a)
