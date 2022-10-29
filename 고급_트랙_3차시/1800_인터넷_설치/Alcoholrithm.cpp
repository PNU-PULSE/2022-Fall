#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

using pii = pair<int, int>;

int dp[1001][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, P, K;
	cin >> N >> P >> K;

	vector<vector<pii>> vec(N + 1);

	int c1, c2, m;
	for (int i = 0; i < P; ++i) {
		cin >> c1 >> c2 >> m;
		vec[c1].push_back({ c2, m });
		vec[c2].push_back({ c1, m });
	}

	memset(dp, 0x3f, sizeof(dp));

	const int MAXIMUM = dp[0][0];

	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

	pq.push({ 0, {1, 0} });

	memset(dp[1], 0, sizeof(dp[0]));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr_computer = pq.top().second.first;
		int curr_free = pq.top().second.second;
		pq.pop();

		for (auto nc : vec[curr_computer]) {
			if (curr_free < K && dp[curr_computer][curr_free] < dp[nc.first][curr_free + 1]) {
				pq.push({ cost, {nc.first, curr_free + 1} });
				dp[nc.first][curr_free + 1] = dp[curr_computer][curr_free];
			}
			
			if (max(cost, nc.second) < dp[nc.first][curr_free]) {
				pq.push({ max(cost, nc.second), {nc.first, curr_free} });
				dp[nc.first][curr_free] = max(cost, nc.second);
			}
		}
	}

	int minimum = MAXIMUM;
	for (auto m : dp[N]) {
		minimum = min(minimum, m);
	}
	if (minimum == MAXIMUM) {
		minimum = -1;
	}
	cout << minimum;
	return 0;
}