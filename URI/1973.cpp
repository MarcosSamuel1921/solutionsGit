#include <vector>
#include <iostream>

using namespace std;

int main()
{
    long long n, aux, i = 0, total = 0, estrelas = 0;
    vector<long long> C1, C2;

    cin >> n;

    while(n--){
        cin >> aux;
        C1.push_back(aux);
        C2.push_back(aux);
    }

    while(1){
        if(i<0) break;
        if(i>=(int)C1.size()) break;

        C1[i]--;

        if((C1[i]+1)%2!=0) i++;
        else i--;
    }

    for(int j=0;j<(int)C1.size();j++){
        if(C1[j]>0) total+=C1[j];
        if(C1[j]!=C2[j]) estrelas++;
    }

    cout << estrelas << " " << total << endl;

    return 0;
}
