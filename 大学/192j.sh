#!/bin/sh

python << EOF
import sys
import operator
fp = open("words.txt", "r")
content = fp.read()
fp.close()

stat = {}

for word in content.strip().split():
	if word not in stat:
		stat[word] = 1
	else:
		stat[word] += 1

sor = sorted(stat.items(), key=operator.itemgetter(1))
sor.reverse()

for word, freq in sor:
	print("%s %d" % (word, freq))
EOF

