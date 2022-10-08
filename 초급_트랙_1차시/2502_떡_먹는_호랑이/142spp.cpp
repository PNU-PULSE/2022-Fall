#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> table(31);
pair<int,int> fibo(int x){
    if(table[x].first || table[x].second) return table[x];
    pair<int,int> p = {0,0};
    if(x==1){ p.first++; }
    else if (x==2){ p.second++; }
    else if(!table[x].first && !table[x].second){
        p.first += fibo(x-1).first + fibo(x-2).first;
        p.second += fibo(x-1).second + fibo(x-2).second;
    }
    table[x] = p;
    return table[x];
}

int main(){
    int x,y ; cin >> x >> y;
    pair<int,int> p = fibo(x);
    for(int i=1; i<=y; i++){
        for(int j=i; j<=y; j++){
            if(p.first*i + p.second*j == y) {
                cout << i << "\n" << j << "\n";
                return 0;
            }
            if(p.first*i + p.second*j > y) break; 
        }
    }
    return 0;
}