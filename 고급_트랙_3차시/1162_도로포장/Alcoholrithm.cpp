#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll dp[10001][21];

struct mystruct {
	ll arr[3];
	bool operator<( const mystruct& b) const{
		return arr[0] > b.arr[0];
	}
};
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<pll>> vec(N + 1);
	ll c1, c2, t;
	for (int i = 0; i < M; ++i) {
		cin >> c1 >> c2 >> t;
		vec[c1].push_back({ c2, t });
		vec[c2].push_back({ c1, t });
	}
	
	memset(dp, 0x3f, sizeof(dp));

	priority_queue<mystruct> pq; // cost, city, k
	pq.push({ 0, 1, 0 });

	dp[1][0] = 0;

	ll curr_cost, curr_city, curr_k;
	ll next_city, time;
	mystruct top;

	while (!pq.empty()) {
		top = pq.top();
		curr_cost = top.arr[0];
		curr_city = top.arr[1];
		curr_k = top.arr[2];
		pq.pop();
		if (curr_cost > dp[curr_city][curr_k]) {
			continue;
		}
		for (pll& c : vec[curr_city]) {
			next_city = c.first;
			time = c.second + dp[curr_city][curr_k];
			if (time < dp[next_city][curr_k]) {
				pq.push({ time, next_city, curr_k} );
				dp[next_city][curr_k] = time;
			}
			if (curr_k < K && curr_cost < dp[next_city][curr_k + 1]) {
				pq.push({ curr_cost, next_city, curr_k + 1});
				dp[c.first][curr_k + 1] = curr_cost;
			}
		}
	}

	ll minimum = 9223372036854775800;
	for (auto c : dp[N]) {
		minimum = min(c, minimum);
	}
	cout << minimum;
	return 0;
}