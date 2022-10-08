#include <bits/stdc++.h>

using namespace std;

queue<int> truck;

int main(){
    int n,w,l;
    cin >> n >> w >> l;
    while (n--){
        int in; cin >> in;
        truck.push(in);
    }
    int NofT=0, WofT=0;
    queue<pair<int,int>> bridge; // weight, left length
    int count = 0;
    while(!truck.empty()){
        if(!bridge.empty() && bridge.front().first == count){
            NofT --; WofT-=bridge.front().second;
            bridge.pop();
        }
        if(NofT + 1<=w && WofT + truck.front() <=l){
            bridge.push(make_pair(count+w,truck.front()));
            NofT++; WofT+=truck.front();
            truck.pop();
        }
        count++;
    }
    while(!bridge.empty()){
        if(bridge.front().first == count){
            bridge.pop();
        }
        count ++;
    }
    cout << count << "\n";
    return 0;
}