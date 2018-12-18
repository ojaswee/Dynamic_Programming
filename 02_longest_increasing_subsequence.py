# Longest increasing sub sequence problem in python
# Using bottom-up approach

def longest_substring(arr):
    size = len(arr)
    mat = [1 for x in range(size)]
    for i in range(size):
        for j in range(i):
            if arr[i] > arr[j]:
                mat[i] = max(mat[i],mat[j]+1)
    return mat

mat = (longest_substring([-1,0,6,2]))
print mat
