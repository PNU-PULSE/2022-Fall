#include <iostream>
#include <vector>

using namespace std;

bool isPrime[500001];
long long cnt[500001];
long long dp[500001];

void getPrime(void) {
     
    for(int i = 2; i <= 500000; ++i) {
        isPrime[i] = true;
    }
    for(int i = 2; i * i <= 500000; ++i) {
        if (isPrime[i] == false) {
            continue;
        }
        for(int  j = i * i ; j <= 500000; j += i) {
            isPrime[j] = false;
        }
    }
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    vector<int> vec;
    
    
    int zeros = 1;
    int candy;
    for(int i = 0; i < N; ++i){
        cin >> candy;
        if (!candy) {
            ++zeros;
            continue;
        }
        if (!cnt[candy]) {
            vec.push_back(candy);
        }
        cnt[candy]++;
    }

    getPrime();

    
    long long ans = 0;
    dp[0] = 1;
    for(auto v : vec) {
        for(int i = 500000; i >= 0; --i) {
            for(int j = 1; j <= cnt[v] && i >= j * v; ++j) {
                dp[i] += dp[i - j * v];
            }
        }
    }
    for(int i = 2; i <= 500000; ++i) {
        if (isPrime[i]){
            ans += dp[i];
        }
    }

    cout << ans * zeros;

    return 0;
}
