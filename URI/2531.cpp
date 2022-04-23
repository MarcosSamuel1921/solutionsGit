#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

#include <bits/stdc++.h>

using namespace std;

int arvore[300001][2];
int Entrada[100001];
//parâmetros
//no – nó da arvore, inicio e fim do vetor
void constroi_arvore(int no, int inicio, int fim)
{
    if(inicio == fim)    // Folha da arvore
    {
        arvore[no][0] = Entrada[inicio];
        arvore[no][1] = Entrada[inicio];
        return;
    }
    constroi_arvore(no*2, inicio, (inicio+fim)/2); // Inicia o filho da esquerda
    constroi_arvore(no*2+1, 1+(inicio+fim)/2, fim); // Inicia o filho da direita
    if(arvore[no*2][0] <= arvore[no*2+1][0])
        arvore[no][0] = arvore[no*2][0];
    else
        arvore[no][0] = arvore[no*2+1][0];
    if(arvore[no*2][1] >= arvore[no*2+1][1])
        arvore[no][1] = arvore[no*2][1];
    else
        arvore[no][1] = arvore[no*2+1][1];
}
//parâmetros
//no-nó da arvore, a e b – inicio e fim do vetor, i e j – inicio e fim do intervalo
void atualiza_arvore(int no, int a, int b, int i, int v)
{
    if(i < a || i > b) return;
    if(a == b)
    {
        arvore[no][0] = v;
        arvore[no][1] = v;
        return;
    }
    atualiza_arvore(no*2, a, (a+b)/2, i, v); // atualiza filho da esquerda
    atualiza_arvore(no*2+1, 1+(a+b)/2, b, i, v); // atualiza filho da direita


// atualiza contagem de elementos nos nós intermediários
    if(arvore[no*2][0] <= arvore[no*2+1][0])
        arvore[no][0] = arvore[no*2][0];
    else
        arvore[no][0] = arvore[no*2+1][0];
    if(arvore[no*2][1] >= arvore[no*2+1][1])
        arvore[no][1] = arvore[no*2][1];
    else
        arvore[no][1] = arvore[no*2+1][1];
}
//parâmetros
//no-nó da arvore, a e b – inicio e fim do vetor, i e j – inicio e fim do intervalo
int consulta_arvore(int no, int a, int b, int i, int j, int& Ma, int& Me)
{
    if(a > b || a > j || b < i){ //segmento não esta no intervalo[i, j]
        return 0;
    }
    if (a >= i && b <= j)  //Segmento está totalmente dentro do intervalo [i, j]
    {
        Me =  arvore[no][0];
        Ma =  arvore[no][1];
        return 1; //Retorna o maior
    }
    if (a == b)    // Folha da arvore
    {
        Me =  arvore[no][0];
        Ma =  arvore[no][1];
        return 1; //Retorna o maior
    }


    int r1 = consulta_arvore(no*2, a, (a+b)/2, i, j, Ma, Me);//Consulta intervalo da esquerda
    int iMa = Ma;
    int iMe = Me;
    int r2 = consulta_arvore(1+no*2, 1+(a+b)/2, b, i, j, Ma, Me);//Consulta intervalo da direita
    if(r1 != 0){
        if(iMa > Ma) Ma = iMa;
        if(iMe < Me) Me = iMe;
    }
    return 1;
}

int main()
{

    int j, p, N, Q, C, M, m;

    while(scanf("%d", &N) != EOF){


        for(int i = 1; i <= N; i++)
            scanf("%d", &Entrada[i]);

        constroi_arvore(1, 1, N);

        scanf("%d",&Q);
        for(int i = 0; i < Q; i++){

            scanf("%d %d %d", &C, &j, &p);

            if(C == 1){
                atualiza_arvore(1, 1, N, j, p);
            }

            else{
                consulta_arvore(1, 1, N, j, p, M, m);
                printf("%d\n", M - m);
            }
        }

    }

    return 0;
}
