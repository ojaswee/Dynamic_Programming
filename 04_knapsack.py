
def knapsack(bag_size,wt, value ):
    rows = len(wt)
    col = bag_size+1
    mat = [[0]*col for i in range (rows)]
    for w in range (rows):
        for bag in range (col):
            if (bag == 0):
                mat [w] [bag]= 0
            elif(bag < wt[w]):
                mat[w][bag] = mat[w-1][bag]
            elif(bag == wt[w]):
                v = value[w]
                mat [w][bag]= max(v,mat[w-1][bag])
            elif(bag > wt[w]):
                v = value[w]
                rem = bag - wt [w]
                v = v+ mat[w-1][rem]
                mat[w][bag]= max(v, mat [w-1][bag])

    return (mat)

bag_size = 7
wt = [1,3,4,5]
value = [1,4,5,7]

mat = knapsack(bag_size,wt,value)

print (mat)

print ("Maximum value:", mat[len(wt)-1][bag_size])
