def heapify(a, i):
    l = 2*i
    r = 2*i + 1
    if l < len(a) and a[l] > a[i] :
        largest = l
    else:
        largest = i
    if r < len(a) and a[r] > a[largest]:
        largest = r
    if largest != i:
        temp = a[i]
        a[i] = a[largest]
        a[largest] = temp
        heapify(a, largest)

def build_heap(a):
    for i in range(int((len(a)-1)/2), 0, -1):
        heapify(a, i)

        
def print_heap(a, i):
    if i < len(a):
        l = 2*i
        r = 2*i + 1
        if l < len(a) and r < len(a):
            print("parent = ", a[i], "left child = ", a[l], "right child = ",a[r])
        elif l < len(a) and r >= len(a):
            print("parent = ", a[i], "left child = ", a[l], "right child = NULL")
        else:
            print("leaf = ", a[i])
        print_heap(a, i+1)

a = input().split()
a = [0] + a
a = list(map(int, a))

build_heap(a)

print_heap(a, 1)
            
    
