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

struct Arestas{
    int x,y,z;
};

struct Vertice{
    Vertice *Pai;
};


void Link(Vertice* x, Vertice* y){
    x->Pai = y->Pai;
}

Vertice* Find_Set(Vertice *v){
    if(v != v->Pai)
        v->Pai = Find_Set(v->Pai);
    return v->Pai;
}

bool Compare(Arestas A, Arestas B){
    if(A.z < B.z) return true;
    return false;
}
void Union(Vertice* x, Vertice* y){
    Link(Find_Set(x), Find_Set(y));
}
int main()
{
    int N, M;
    vector<Vertice> V(1024*1024);
    string linha, ANTlinha;

    cin >> N >> M;

    for(int i=0; i <N; i++)
    {
        cin >> linha;
        for(int j=0; j<M; j++)
        {
            int P = (i*M) + j;
            if(linha[j]=='o') V[P].Pai = NULL;
            else{
                V[P].Pai = &V[P];
                if(i > 0)
                {
                    if(linha[j] == '.' && ANTlinha[j] == '.')
                    {
                        int Y = ((i-1)*M) + j;
                        Union(&V[P], &V[Y]);
                    }

                  }
                if(j>0)
                    {
                        if(linha[j]=='.' && linha[(j-1)]=='.')
                        {
                            int Y = P-1;
                            Union(&V[P], &V[Y]);
                        }
                    }
                }
        }
                ANTlinha = linha;
    }
    set<Vertice *> Resultado;
    for(int i=0; i < M*N; i++)
    {
        if(V[i].Pai == NULL) continue;
        Resultado.insert(Find_Set(&V[i]));
    }
    cout << (int) Resultado.size() << endl;
    return 0;
}
