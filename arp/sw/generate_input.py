from random import randint

NL = "\n"
limits = 1000
dimensions = 10000

f1 = open('v1', 'w')
f2 = open('v2', 'w')

f1.write(str(dimensions) + NL)
f2.write(str(dimensions) + NL)

for i in range(dimensions):
	f1.write(str(randint(-limits, limits)) + NL)
	f2.write(str(randint(-limits, limits)) + NL)

f1.close()
f2.close()

