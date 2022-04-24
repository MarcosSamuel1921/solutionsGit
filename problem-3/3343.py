
n, x = map(int, input().split())

str = input()

p, m, g= map(int, input().split())

w = y = z = 0

for i in range(len(str)):
    if str[i] == 'P':
        w += p
    if str[i] == 'M':
        y += m
    if str[i] == 'G':
        z += g

totalTitans = w + y +z
minimoMura = 0

while totalTitans > x or totalTitans > 0:
    minimoMura += 1
    totalTitans -= x
print(minimoMura)
