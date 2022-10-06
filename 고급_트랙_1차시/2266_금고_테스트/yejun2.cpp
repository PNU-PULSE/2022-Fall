//
//  yejun2.cpp
//  Backjoon
//
//  Created by YejunJung on 2022/10/06.
//

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;
int N, K;
int dp[501][501];

void read() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == 1) {
                dp[i][j] = j;
                continue;
            }
            if (i > j) {
                dp[i][j]=dp[i-1][j];
                continue;
            }
            dp[i][j] = INF;
            for (int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1], dp[i][j - k]));
            }
        }
    }
    cout << dp[K][N] << endl;
    return 0;
}
