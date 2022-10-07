# BOJ 2266 금고 테스트

![문제 이미지](https://user-images.githubusercontent.com/29500858/194590754-7fafa3a5-a864-4297-81eb-20438772c34a.png)

## 금고가 깨진 경우 / 금고가 깨지지 않은 경우

전형적인 dp 문제답게 점화식을 세우면 풀 수 있는 문제이다. <br>

k개의 금고를 가졌으며, n층의 건물에서 f층에서 금고를 떨어뜨렸을 때, <br>
만약 금고가 깨졌으면 k - 1개의 금고를 가지고 f - 1층에서 금고를 떨어뜨렸을때의 최소 낙하 회수보다 1만큼 큰 횟수가 필요하거나 <br>
만약 금고가 깨지지 않았다면 k개의 금고를 가지고  n - f층에서 금고를 떨어뜨렸을 때의 최소 낙하 회수보다 1만큼 큰 횟수가 필요할 것이다. <br>

문제에서는 항상 최악의 경우를 고려해야 하므로 둘 중의 최댓값을 선택하면 되며, 그리고 그것들을 f를 1부터 n까지 전수조사해서 가장 큰 값을 선택하면 된다. <br>

해당 점화식을 적용한 전체 코드는 아래와 같다. <br>

```C++
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
```
