#this is bottom-up approach
# test 

def findnumofchange(change,n):
    mat = [[0 for x in range(n+1)] for y in range(len(change)+1)]
    for c in range(1,len(change)+1): # available coins
        for m in range(1,n+1):  # change needed
            if c ==1:
                mat[c][m] = mat[c][m-1]+1
            elif (m >= change[c-1]):
                mat[c][m] = min(1+ mat[c][m-change[c-1]],mat[c-1][m])
            else:
                mat[c][m] = mat[c-1][m]
    return mat

mat = (findnumofchange([1,6,10],12))
for i in mat:
    print i


