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

using namespace std;
int arvore[300001][4];
int auxiliar[300001];
//parâmetros
//no – nó da arvore, inicio e fim do vetor
void constroi_arvore(int no, int inicio, int fim)
{
    auxiliar[no] = 0;
    if(inicio == fim)    // Folha da arvore
    {
        arvore[no][0] = 1; // inicia com valor 1 (homem) todos os nós
        arvore[no][1] = 1; // quantidade de homens para o nó
        arvore[no][2] = 0; // quantidade de elefantes para o nó
        arvore[no][3] = 0; // quantidade de ratos para o nó
        return;
    }
    constroi_arvore(no*2, inicio, (inicio+fim)/2); // Inicia o filho da esquerda
    constroi_arvore(no*2+1, 1+(inicio+fim)/2, fim); // Inicia o filho da direita
    arvore[no][1]=arvore[no*2][1]+arvore[no*2+1][1];//contagem de homens nos nós intermediários
    arvore[no][2]=0;//contagem de elefantes será 0 na inicialização
    arvore[no][3]=0;//contagem de ratos será 0 na inicialização
}
//parâmetros
//no-nó da arvore, a e b – inicio e fim do vetor, i e j – inicio e fim do intervalo
void atualiza_arvore(int no, int a, int b, int i, int j)
{
    int AUX;
    auxiliar[no] %= 3;
    while(auxiliar[no]>0)  // nó marcado para atualização
    {
        arvore[no][0]++; //seta para o próximo elemento
        if (arvore[no][0] == 4)
            arvore[no][0] = 1;//se for rato vai para homem
        //atualiza contagem de elementos
        AUX = arvore[no][3];
        arvore[no][3] = arvore[no][2];
        arvore[no][2] = arvore[no][1];
        arvore[no][1] = AUX;
        auxiliar[no]--;
        if(a != b)
        {
            auxiliar[no*2]++;
            auxiliar[no*2 + 1]++;
        }
    }
    if(a > b || a > j || b < i) //segmento não esta no intervalo[i, j]
        return;
    if (a >= i && b <= j)  //Segmento está totalmente dentro do intervalo [i, j]
    {
        arvore[no][0]++; //seta para o próximo elemento
        if (arvore[no][0] == 4)
            arvore[no][0] = 1;//se for rato vai para homem
        //atualiza contagem de elementos
        AUX = arvore[no][3];
        arvore[no][3] = arvore[no][2];
        arvore[no][2] = arvore[no][1];
        arvore[no][1] = AUX;
        if(a != b)
        {
            auxiliar[no*2]++;
            auxiliar[no*2 + 1]++;
        }
        return;
    }
    atualiza_arvore(no*2, a, (a+b)/2, i, j); // atualiza filho da esquerda
    atualiza_arvore(no*2+1, 1+(a+b)/2, b, i, j); // atualiza filho da direita


// atualiza contagem de elementos nos nós intermediários
    arvore[no][1] = arvore[no*2][1] + arvore[no*2+1][1];
    arvore[no][2] = arvore[no*2][2] + arvore[no*2+1][2];
    arvore[no][3] = arvore[no*2][3] + arvore[no*2+1][3];
}
//parâmetros
//no-nó da arvore, a e b – inicio e fim do vetor, i e j – inicio e fim do intervalo
void consulta_arvore(int no, int a, int b, int i, int j, int& H, int& E, int& R)
{
    int AUX;
    if(a > b || a > j || b < i) //segmento não esta no intervalo[i, j]
        return;
    auxiliar[no] %= 3;
    while(auxiliar[no]>0)  // nó marcado para atualização
    {
        arvore[no][0]++; //seta para o próximo elemento
        if (arvore[no][0] == 4)
            arvore[no][0] = 1;//se for rato vai para homem
        //atualiza contagem de elementos
        AUX = arvore[no][3];
        arvore[no][3] = arvore[no][2];
        arvore[no][2] = arvore[no][1];
        arvore[no][1] = AUX;
        auxiliar[no]--;
        if(a != b)
        {
            auxiliar[no*2]++;
            auxiliar[no*2 + 1]++;
        }
    }
    if (a >= i && b <= j)  //Segmento está totalmente dentro do intervalo [i, j]
    {
        H += arvore[no][1];
        E += arvore[no][2];
        R += arvore[no][3];
        //auxiliar[no] = 1;
        //auxiliar[no*2]++;
        //auxiliar[no*2 + 1]++;
        return ; //Retorna contagem de homem, elefante, rato
    }
    if (a == b)
    {
        return;
    }


    consulta_arvore(no*2, a, (a+b)/2, i, j, H, E, R);//Consulta intervalo da esquerda
    consulta_arvore(1+no*2, 1+(a+b)/2, b, i, j, H, E, R);//Consulta intervalo da direita
// atualiza contagem de elementos nos nós intermediários
    // arvore[no][1] = arvore[no*2][1] + arvore[no*2+1][1];
    // arvore[no][2] = arvore[no*2][2] + arvore[no*2+1][2];
    // arvore[no][3] = arvore[no*2][3] + arvore[no*2+1][3];
    return;
}
int main()
{
    int N, M, A, H, B, R, E;

    char L[2];

    while(cin >> N >> M){

        constroi_arvore(1, 1, N);

        for(int i=0; i<M; i++){
            cin >> L >> A >> B;
            if(L[0] == 'M'){
                atualiza_arvore(1, 1, N, A, B);
            }
            else{
                H = E = R = 0;
                consulta_arvore(1, 1, N, A, B, H, E, R);
                cout << H << " " << E << " " << R << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
