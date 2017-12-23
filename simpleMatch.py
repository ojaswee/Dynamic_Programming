# simple pattern match

def simpleMatch(text, pattern):
    lenText = len(text) +1
    lenPattern = len (pattern) + 1
    mat = [[0 for x in range(lenText)] for y in range(lenPattern)]
    for t in range(1,lenText):
        for p in range (1,lenPattern):


mat = (simpleMatch("HelloWorld", "World"))

