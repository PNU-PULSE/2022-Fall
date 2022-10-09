# 11497_통나무_건너뛰기
## 접근방식
단순히 정렬만 해주면 될 줄 았았지만 그렇게 될 시 맨처음과 맨 마지막이 만나는 원형구조에서 맨처음과 맨마지막 값의 차이가
매우 커질 수 있음을 알고 한쪽이 솟아오른 피라미드 구조로 풀면 될 거 같다는 생각이 들었다. 가장 쉽게 접근 할 수 있는 방식이
deque라고 생각하고 접근하였다.
## 문제풀이
처음 통나무의 높이들을 받아 배열에 저장하였다. 그후 내림차순(풀이에서는 내림차순으로 하였지만 오름차순도 상관없다.)
``` c++
int n;
cin >> n;
int log[n];
for(int j=0;j<n;j++) {
    cin >> log[j];
}
sort(log,log+n);
reverse(log,log+n);
```
그 후 deque를 선언 후 배열의 인덱스가 홀수인 경우는 front에서 push를, 짝수인 경우는 back에서 push를 함을 통해
처음에 생각했던 피라미드 구조를 만들었다.
```c++
for(int j=0;j<n;j++) {
    if(j%2==0) {
        dq.push_front(log[j]);
    }
    else {
        dq.push_back(log[j]);
    }
}
```
deque의 front와 back의 값을 비교해 차이를 max_gap 변수에 저장 후 front에서 back쪽으로 요소들을 비교해 max_gap을
이끌어 내었다.
```c++
int max_gap = abs(dq.front()-dq.back());
while(dq.size() > 1) {
    int temp = dq.front();
    dq.pop_front();
    int gap = abs(dq.front()-temp);
    if(max_gap < gap) {
        max_gap = gap;
    }
}
 ```
