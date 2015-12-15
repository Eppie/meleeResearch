#!/usr/bin/python

import binascii
import Levenshtein
from collections import Counter


def findSubstring(a):
    times=10
    for n in range(1,len(a)/times+1)[::-1]:
        substrings=[a[i:i+n] for i in range(len(a)-n+1)]
        freqs=Counter(substrings)
        if freqs.most_common(1)[0][1]>=times:
            seq=freqs.most_common(1)[0][0]
            break
    print "sequence '%s' of length %s occurs %s or more times"%(seq,n,times)

# content = map(ord, content.decode('hex'))
# findSubstring(content[4000:10000])


def shift(s, n):
    return s[-n:] + s[:-n]


def stringSimilarity(s1, s2):
    l = len(s1)
    result = 0
    for i in range(l):
        if s1[i] == s2[i]:
            result += 1
    return result / float(l)


filename = 'saveCOMPLETE.gci'
with open(filename, 'rb') as f:
    content = f.read()
with open('saveEMPTY.gci', 'rb') as f:
    emptyContent = f.read()

content = binascii.hexlify(content)
emptyContent = binascii.hexlify(emptyContent)
# content = content[12544:]
# content = map(ord, content.decode('hex'))
# results = []
# for i in range(1000):
    # shiftedContent = shift(content, i)
    # results.append((stringSimilarity(content, shiftedContent), i))

# print sorted(results)


print Levenshtein.ratio(content, emptyContent)
