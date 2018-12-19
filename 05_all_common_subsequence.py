def com_sub(text, pattern):
    rows = len (pattern)
    col = len (text)

    mat = [[0]* col for i in range (rows)]

    match = []

    for p in range (rows):
        for t in range (col):
            if (pattern[p]== text[t]):
                mat[p][t] = mat[p-1][t-1] + 1;
                if (pattern[p] not in match ):
                    match.append (pattern[p])
            else:
                mat[p][t] = max (mat[p-1][t], mat [p][t-1])

    return mat,match

text = "abcdaf"
pattern = "acbcf"

matrix, subseq = com_sub (text, pattern)

# print (matrix)
print (subseq)
