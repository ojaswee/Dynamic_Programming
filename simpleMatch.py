# simple pattern match

def simplematch(word,pattern):
    for w in range(len(word)):
        p =0
        word2=word[w:]
        while pattern[p] == word2[p]:
            p += 1
            if p==len(pattern):
                print "occurs at ", w
                break

simplematch("abcdefacdeabc", "abc")


len('abc')