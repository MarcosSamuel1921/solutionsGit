horaIncial, minInicial, horaFinal, minFinal = map(int, input().split())

minInicial += horaIncial*60
minFinal += horaFinal*60

temp = minFinal - minInicial
if temp<=0:
    temp += 24*60

horas = temp//60
minutos = temp%60

print("O JOGO DUROU {} HORA(S) E {} MINUTO(S)".format(horas, minutos))
