#include <bits/stdc++.h>

using namespace std;


void dfs(vector<string>& vc, int i, int j){
    if(i<0 || i>=vc.size()) return;
    if(j<0 || j>=vc[i].size()) return;

    if(vc[i][j]=='0') return;

    char c = vc[i][j];
    vc[i][j] = '0';
    
    if(i<vc.size()-1 && vc[i+1][j]==c) dfs(vc,i+1,j);
    if(i>0 && vc[i-1][j]==c) dfs(vc,i-1,j);
    if(j<vc[i].size()-1 && vc[i][j+1]==c) dfs(vc,i,j+1);
    if(j>0 && vc[i][j-1]==c) dfs(vc,i,j-1);

}

int main(){
    int n; cin >> n;
    vector<string> vc_RGB;
    while(n--){
        string s; cin >> s;
        vc_RGB.push_back(s);
    }
    vector<string> vc_RB(vc_RGB);
    for(int i=0; i<vc_RB.size(); i++){
        for(int j=0; j<vc_RB[i].size(); j++){
            if(vc_RB[i][j]=='G') vc_RB[i][j]='R';
        }
    }
    pair<int,int> ans = {0,0};

    for(int i=0; i<vc_RGB.size(); i++){
        for(int j=0; j<vc_RGB[i].size(); j++){
            if(vc_RGB[i][j]!='0') {
                dfs(vc_RGB,i,j);
                ans.first++;
            }
            if(vc_RB[i][j]!='0') {
                dfs(vc_RB,i,j);
                ans.second++;
            }
        }
    }

    cout << ans.first << " " << ans.second;
}