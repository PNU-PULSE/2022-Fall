# BOJ 2515 전시장

![문제 이미지](https://user-images.githubusercontent.com/29500858/194723104-76669f6b-7d19-4ec0-9ef1-4410536bf1d9.png)

### 점화식 세우기

이 문제도 전형적인 dp 문제 답게 dp 배열을 생성하면 풀 수 있는 문제이다. <br>

먼저 그림을 정렬한 후에, <br>

dp 배열의 i번째 값이 의미하는 것이 첫번째부터 i번째 그림까지 배치했을 때 가능한 최댓값이라고 할 경우 <br>

첫번째 그림부터 <br>

1. 해당 그림을 전시했을 때
2. 전시하지 않았을 때, 즉 이전 최대값
<br>
중 최댓값을 선택해서 dp 배열을 채워주면 된다. <br>
<br>

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using mypair = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;
	vector<mypair> vec(n + 1);
	vector<mypair> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i].first >> vec[i].second;
	}

	auto comp = [](mypair a, mypair b) {return a.first == b.first ? a.second > b.second : a.first < b.first; };

	sort(vec.begin(), vec.end(), comp);


	for (int i = 1, idx, target; i <= n; ++i) {
		target = vec[i].first - s;

		if (target >= dp[i - 1].first) {
			dp[i] = mypair({ vec[i].first, dp[i - 1].second + vec[i].second });
		}
		else {
			idx = upper_bound(&dp[0], &dp[i], mypair({ target, -1 }), comp) - &dp[0] - 1;
			if (dp[idx].second + vec[i].second > dp[i - 1].second) {
				dp[i] = mypair({ vec[i].first, dp[idx].second + vec[i].second });
			}
			else {
				dp[i] = dp[i - 1];
			}
		}

	}

	cout << dp[n].second;
	return 0;
}
```
