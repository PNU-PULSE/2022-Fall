#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n,w,l;
    cin >> n >> w >> l;
    queue<int> truck;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        truck.push(temp);
    }

    queue<int> bridge;
    int on_bridge_weight = 0;
    int all_time = 0;
    while(!truck.empty()) {
        if(bridge.size() == w) {
            on_bridge_weight -= bridge.front();
            bridge.pop();
        }
        int front_truck = truck.front();
        if(on_bridge_weight + front_truck <= l) {
            bridge.push(front_truck);
            on_bridge_weight += front_truck;
            truck.pop();
            all_time++;
        }
        else {
            bridge.push(0);
            all_time++;
        }   
    }
    all_time += w;
    cout << all_time << endl;
    
}
