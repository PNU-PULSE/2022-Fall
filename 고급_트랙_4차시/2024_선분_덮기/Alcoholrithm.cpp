#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;
	cin >> M;

	vector<pii> vec;
	int l, r;
	while (true) {
		cin >> l >> r;
		if (l == 0 && r == 0) {
			break;
		}
		if (r >= 0 && l <= M && l != r) {
			vec.push_back({l, r});
		}
	}

	sort(vec.begin(), vec.end());

	int right = 0;
	int idx = 0;
	int cnt = 0;

	while (true) {
		int curr_right = -1;
		for (; idx < vec.size(); ++idx) {
			if (vec[idx].first <= right) {
				if (vec[idx].second > curr_right)
					curr_right = vec[idx].second;
			}
			else {
				break;
			}
		}

		if (curr_right == -1) {
			cout << 0;
			break;
		}
		++cnt;
		right = curr_right;
		if (right >= M) {
			cout << cnt;
			break;
		}
	}
	return 0;
}
