# BOJ 1561 놀이 공원

![문제 이미지](https://user-images.githubusercontent.com/29500858/200120864-d52e018f-1c0b-499e-a55a-9c5e48567a52.png)

### 이분 탐색

이 문제를 풀려면 문제를 변경해서 모든 아이가 탑승할 수 있는 운행 시간을 찾는 문제로 바꾸어서 생각해야 한다. <br>
먼저 t 시간에 탑승할 수 있는 사람의 최댓값은 t를 M개의 놀이기구들의 운행 시간의 총합으로 나눈 몫의 합이 된다. <br>

따라서 모든 아이들이 탑승할 수 있는 t초를 이분 탐색으로 찾고, <br>
t-1초까지 탑승할 수 있는 사람의 수를 $\hat{N}$ 이라고 할 때, 놀이기구의 번호가 빠른 순으로 <br>
t를 해당 놀이기구의 운행 시간으로 나눴을 떄 나머지가 0이 되면 t초 그 놀이기구에 사람을 태울 수 있으므로 $\hat{N}$에 1을 더해주고, <br>
$\hat{N} == N$이 될 때까지 위 과정을 반복하면 마지막 아이가 타는 놀이기구를 알 수 있게 된다. <br> 

```C++

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

using ll = long long;

int N, M;
vector<int> vec(10001);

ll binarySearch(void) {
    ll low = 0, high = 2000000000LL * 30;

    ll cnt;
    ll res;
    while(low<=high) {
        ll mid = (high + low) / 2;
        cnt = M;
        for(int i = 0; i < M; ++i) {
            cnt += mid / vec[i];
        }  
        if (cnt >= N) {
            res =  mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return res;
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;

    
    for(int i = 0; i < M; ++i) {
        cin >> vec[i];
    }

    if (N <= M) {
        cout << N;
        return 0;
    }

    ll time = binarySearch();
    ll cnt = M;
    for(int i =0 ;i < M; ++i) {
        cnt += (time - 1) / vec[i];
    }

    for(int i = 0; i < M; ++i) {
        if (time % vec[i] == 0) {
            ++cnt;
        }
        if (cnt == N) {
            cout << i + 1;
            break;
        }
    }
    
    return 0;
}
```
