#! /usr/bin/python

from sys import argv

f=open(argv[1], "r")
t=f.read()

l = t.split("\n")

l2 = l[0].split()
indisp = int(l2[2])
nranger = int(l2[0])


Ranger = []
#[num, lobs[]]


#[num, size, restant, serv]
x=0
while x!=nranger:
	L.append([x, []])
	x+=1

for i in l[1:1+indisp]:
	L[int(i[0])][1].append(int(i[1]))


for i in L:
	



l = l[1+indisp:]
sum = 0
for i in l:
	tmp = i.split()
	if len(tmp) !=0:
		sum += int(tmp[0])

print(sum)




