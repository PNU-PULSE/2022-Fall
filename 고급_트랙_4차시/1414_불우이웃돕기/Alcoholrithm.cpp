#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;
using ppii = pair<int, pii>;

int mapping['z' + 1];
int parents[50];

int find_parent(int i) {
	int parent = parents[i];
	if (parent == i) {
		return i;
	}
	else {
		return parents[i] = find_parent(parent);
	}
}

void merge(int a, int b) {
	int pa = find_parent(a), pb = find_parent(b);
	if (pa < pb) {
		parents[pb] = pa;
	}
	else {
		parents[pa] = pb;
	}
	return;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 'a'; i <= 'z'; ++i) {
		mapping[i] = i - 'a' + 1;
	}
	for (int i = 'A'; i <= 'Z'; ++i) {
		mapping[i] = i - 'A' + 27;
	}

	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i) {
		parents[i] = i;
	}

	char c;
	vector<ppii> vec;
	
	int summation = 0;
	int cost = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> c;
			if (i != j && c != '0') {
				vec.push_back({ mapping[c], {i, j} });
			}
			summation += mapping[c];
		}
	}

	sort(vec.begin(), vec.end());


	
	int start, end;

	for (const auto& v : vec) {
		start = v.second.first;
		end = v.second.second;

		if (find_parent(start) != find_parent(end)) {
			merge(start, end);
			cost += v.first;
		}
	}

	int i = 0;
	int pre_parent = find_parent(0);
	for (i = 1; i < N ; ++i) {
		int parent = find_parent(i);
		if (parent != pre_parent) {
			break;
		}
		pre_parent = parent;
	}
	if (i < N) {
		cout << -1;
	}
	else {
		cout << summation - cost;
	}
	return 0;
}
