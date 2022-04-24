import math

a,b,c = map(int, input().split(" ")) 

maior = (a+b+abs(a-b))/2
maiorABC = (maior + c+abs(maior-c))/2

print("%d eh o maior"%maiorABC)
