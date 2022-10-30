#include <iostream>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<bool> isPrime(500001, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 500000; i++)
		if (isPrime[i])
			for (int j = i * i; j <= 500000; j += i)
				isPrime[j] = false;

	int N;
	cin >> N;

	map<int, int> M;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		if (M.count(K) == 0) M.insert(make_pair(K, 1));
		else M[K]++;
	}
	vector<pair<int, int>> vec(M.begin(), M.end());

	vector<vector<ll>> dp(2, vector<ll>(500001, 0LL));
	for (int i = 0; i <= vec[0].second; i++) dp[0][vec[0].first * i]++;
	for (int idx = 1; idx < vec.size(); idx++) {
		for (int i = 0; i <= vec[idx].second; i++)
			for (int total = 0; total <= 500000; total++) {
				if (total + vec[idx].first * i > 500000) break;
				dp[1][total + vec[idx].first * i] += dp[0][total];
			}
		for (int total = 0; total <= 500000; total++) {
			dp[0][total] = dp[1][total];
			dp[1][total] = 0;
		}
	}

	ll result = 0;
	for (int total = 0; total <= 500000; total++)
		if (isPrime[total]) result += dp[0][total];
	cout << result;
}
