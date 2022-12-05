#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<int> vc;
        for(int i=0; i<N; i++){
            int in; cin >> in;
            vc.push_back(in);
        }
        sort(vc.begin(),vc.end());
        int max=0;
        for(int i=0; i+2<N; i++){
            if(max < vc[i+2]-vc[i]) max = vc[i+2]-vc[i];
        }
        cout << max << "\n";
    }
}