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
