#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int M;
	cin >> M;

	vector<pair<int, int>> vec;
	while (true) {
		int L, R;
		cin >> L >> R;
		if (L == 0 && R == 0) break;
		vec.push_back(make_pair(L, -R));
	}
	sort(vec.begin(), vec.end());

	int covered = 0;
	int result = 0;
	for (int i=0; i<vec.size(); i++) {
		if (covered >= M) break;
		vector<pair<int, int>> cand;
		for (int j = i; j < vec.size(); j++)
			if (vec[j].first <= covered && -vec[j].second > covered)
				cand.push_back(make_pair(vec[j].second, vec[j].first));
		sort(cand.begin(), cand.end());
		if (cand.empty()) break;
		covered = -cand[0].first;
		result++;
	}

	if (covered >= M) cout << result;
	else cout << "0";
}
/*
10
0 1
0 5
2 4
3 6
4 8
7 8
7 10
0 0
*/
