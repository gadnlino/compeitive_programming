from collections import Counter

def primeCheck(n):
    primes = []
    for j in range(2,n):
        isPrime = True
        for i in range(2,j):
            if j%i==0:
                isPrime = False
        if isPrime:
            primes.append(j)
    return primes

#n = input()

def korselt(list,x):
    isTrue = True
    for n in list:
        if (x % n*n == 0) and (n-1 % x-1 == 0):
            pass
        else:
            isTrue = False

    if isTrue:
        return "SIM"
    else:
        return "NAO"


def iFat(n):
    for i in range(n):
    	a = input()
    	pList = primeCheck(a)
    	fats = []
    	for j in pList:
    		if a%j==0:
    			fats.append(j)
    			pList.append(j)
    			a = a/j
    	exps = Counter(fats)
    	exps = exps.items()
    	for k in exps:
    		print k[0],k[1]
        print korselt(fats,a)
    	print "---"


iFat(1)
