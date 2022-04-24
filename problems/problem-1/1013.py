import math

a,b,c = map(int, input().split(" ")) #map para converter em cada valor da lista em um inteiro e o slip para quebrar a string

maior = (a+b+abs(a-b))/2
maiorABC = (maior + c+abs(maior-c))/2
