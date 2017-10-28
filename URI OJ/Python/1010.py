c1, n1, v1 = raw_input().split()
c2, n2, v2 = raw_input().split()
n1 = int(n1)
v1 = float(v1)
n2 = int(n2)
v2 = float(v2)

total = n1 * v1 + n2 * v2
print 'VALOR A PAGAR: R$ %.2f' %total
