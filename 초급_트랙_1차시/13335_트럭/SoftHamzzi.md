# 13335 트럭 문제 풀이

먼저 <b>남은 트럭을 저장할 큐</b>와 <b>다리의 상태를 저장할 큐</b>를 만들고,<br>큐를 채워줬습니다.

```c++
	int temp;
  for(int i=0; i<n; i++) { // 트럭들을 큐에 넣어줌
    cin>>temp;
    truck.push(temp);
  }

  for(int i=0; i<w; i++) // 다리에 빈 공간들을 넣어줌
    bridge.push(0);
```

그리고 </b>보낼 트럭이 없을때까지</b>,<br>매 초마다 다리의 상태를 갱신시켜주는 방식으로 구현했습니다.

```c++
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
```

보낼 트럭이 더 이상 없더라도, 다리 위에는 아직 트럭들이 남아있을 것이기 때문에<br>
<b>마지막 트럭이 다리를 지나갈때까지</b> 다리 큐를 비워주었습니다.

```c++
  // 트럭을 다 출발시켰지만 다리에 남아있는 경우를 위해,
  // 다리에 남아있는 트럭들을 모두 탈출시켜 줌
  while(!bridge.empty()) {

    bridge.pop();
    time++;

  }
```