#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet {
	vector<int> parent;
	DisjointSet(int N) : parent(N) {
		for (int i = 0; i < N; i++) parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		parent[u] = v;
		return true;
	}
};

int lanlen(char ch) {
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 1;
	else if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 27;
	else return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<tuple<int, int, int>> edge;
	int totalLanLen = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == '0') continue;
			edge.push_back(make_tuple(lanlen(str[j]), i, j));
			edge.push_back(make_tuple(lanlen(str[j]), j, i));
			totalLanLen += lanlen(str[j]);
		}
	}
	sort(edge.begin(), edge.end());

	DisjointSet uf(N);
	int sumLanLen = 0, conNum = 0;
	for (int i = 0; i < edge.size(); i++)
		if (uf.merge(get<1>(edge[i]), get<2>(edge[i]))) {
			sumLanLen += get<0>(edge[i]);
			conNum++;
		}

	if (conNum == N - 1) cout << (totalLanLen - sumLanLen);
	else cout << "-1";
}
