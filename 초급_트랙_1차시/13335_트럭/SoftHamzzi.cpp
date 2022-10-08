#include <iostream>
#include <queue>

using namespace std;

int main(void) {

  int n,w,l; cin>>n>>w>>l;

  queue<int> bridge;
  queue<int> truck;

  int curWeight = 0;
  int time = 0;

  int temp;
  for(int i=0; i<n; i++) { // 트럭들을 큐에 넣어줌
    cin>>temp;
    truck.push(temp);
  }

  for(int i=0; i<w; i++) // 다리에 빈 공간들을 넣어줌
    bridge.push(0);

  while(!truck.empty()) { // 트럭이 남아있지 않을때까지

    // 다리 도착점에 있는 트럭or빈자리(공기)를 먼저 탈출시켜줌
    curWeight -= bridge.front();
    bridge.pop();

    // 넣어야할 트럭을 넣었을때 다리 무게를 초과하지 않는다면,
    if(truck.front() + curWeight <= l) {

      curWeight += truck.front();
      bridge.push(truck.front());
      truck.pop();

    }
    else // 무게를 초과한다면 빈자리(공기)를 넣어줌
        bridge.push(0);
    time++;

  }

  // 트럭을 다 출발시켰지만 다리에 남아있는 경우를 위해,
  // 다리에 남아있는 트럭들을 모두 탈출시켜 줌
  while(!bridge.empty()) {

    bridge.pop();
    time++;

  }

  cout << time << endl;

}