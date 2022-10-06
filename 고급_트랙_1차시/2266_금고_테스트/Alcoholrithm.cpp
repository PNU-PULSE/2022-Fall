#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(K + 1, vector<int>(N + 1));

	for (int k = 1; k <= K; ++k) {
		dp[k][1] = 1;
	}

	for (int n = 2; n <= N; ++n) {
		dp[1][n] = n;
	}

	for (int k = 2; k <= K; ++k) {
		for (int n = 2; n <= N; ++n) {
			dp[k][n] = 987654321;
			for (int f = 1; f <= n; ++f) {
				dp[k][n] = min(dp[k][n], 1 + max(dp[k - 1][f - 1], dp[k][n - f]));
			}
		}
	}

	cout << dp[K][N];

	return 0;
}