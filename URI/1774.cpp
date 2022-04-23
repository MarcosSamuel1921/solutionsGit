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
    int R, C;
    vector<Arestas> A;
    vector<Vertice> V(61);
    Vertice Vaux;
    Arestas Aux;
    Vertice *X, *Y;
    int total = 0;

    cin >> R >> C;

    for(int i = 0;i<C;i++){
        cin >> Aux.x >> Aux.y >> Aux.z;
        A.push_back(Aux);
    }

    sort(A.begin(), A.end(), Compare);

    for(int i=0; i<R; i++){
        V[i].Pai = &V[i];
    }
    for(int i=0; i< C; i++){
        X = Find_Set(&V[(A[i].x-1)]);
        Y = Find_Set(&V[(A[i].y-1)]);
        if(X!=Y){
            Union(X, Y);
            total += A[i].z;
        }
    }

    cout << total << endl;

    return 0;
}
