# 13335_트럭

## 접근방식
처음에는 배열로 접근하려다가 다리위에 트럭의 갯수, 총 무게, 걸린시간들을 처리하기 힘들것 같아서 Queue 개념을 사용함

## 문제풀이
트럭의 수, 다리 길이, 최대하중을 입력받고 트럭의 수 만큼의 트럭무게들을 queue에 push해주었습니다.
``` C++
int n,w,l;
cin >> n >> w >> l;
queue<int> truck;
for(int i=0;i<n;i++) {
    int temp;
    cin >> temp;
    truck.push(temp);
}
```

bridge라는 queue를 하나의 다리라고 생각하고 다리위에 올라온 트럭을 push해준다.
on_bridge_weight라는 변수로 다리위의 트럭들의 총 무게를 갱신해주고, all_time라는 변수를 통해 총 걸린시간을 기록해준다.\
트럭이 모두 다리에 올라왔을때까지 반복하여 아직 올라오지 않은 맨 앞에 위치한 트럭을 다리에 올릴 수 있는지 확인후
올려준다.\
만약 다음 트럭이 올라왔을 때 다리의 최대하중보다 커질 경우 트럭을 올리지 않고(bridge에 push하지 않고)
bridge에 0을 push해준다.(트럭사이 간격에 무게가 0인 트럭을 이어서 보내준다고 생각했다.)
``` c++
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
```
위의 반복문은 마지막트럭이 다리위에 처음 올라왔을 때 끝나기 때문에
all_time(총 걸린시간)에 다리의 길이만큼을 더해준다.
``` c++
all_time += w;
```
