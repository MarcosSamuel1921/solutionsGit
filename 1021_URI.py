valor = float(input())
dinheiro = valor
n100 = dinheiro/100
a = dinheiro%100
n50 = a/50
b = a%50
n20 = b/20
c = b%20
n10 = c/10
d = c%10
n5 = d/5
e = d%5
n2 = e/2
m1 = e%2
A = valor*100 #transformei os centavos em inteiros
B = (int(A))
C = B%100
m50 = C/50
D = C%50
m25 = D/25
E = D%25
m10 = E/10
F = E%10
m5 = F/5
m01 = F%5
print('NOTAS:')
print("{} nota(s) de R$ 100.00".format(int(n100)))
print("{} nota(s) de R$ 50.00".format(int(n50)))
print("{} nota(s) de R$ 20.00".format(int(n20)))
print("{} nota(s) de R$ 10.00".format(int(n10)))
print("{} nota(s) de R$ 5.00".format(int(n5)))
print("{} nota(s) de R$ 2.00".format(int(n2)))
print("MOEDAS:")
print("{} moeda(s) de R$ 1.00".format(int(m1)))
print("{} moeda(s) de R$ 0.50".format(int(m50)))
print("{} moeda(s) de R$ 0.25".format(int(m25)))
print("{} moeda(s) de R$ 0.10".format(int(m10)))
print("{} moeda(s) de R$ 0.05".format(int(m5)))
print("{} moeda(s) de R$ 0.01".format(int(m01)))    