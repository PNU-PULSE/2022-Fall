#include <iostream>
#include <vector>

using namespace std;

int result = 0;

int dfs(vector< vector< pair<int, int> > >& E, vector<bool>& visited, int cur) {
	visited[cur] = true;
	int max1 = 0, max2 = 0;
	
	for(int i=0, next, cost, ret; i<E[cur].size(); i++) {
		next = E[cur][i].first;
		cost = E[cur][i].second;
		
		if(!visited[next]) {
			ret = dfs(E, visited, next);
			if(ret + cost > max1) {
				max2 = max1;
				max1 = ret + cost;
			} else if(ret + cost > max2) {
				max2 = ret + cost;
			}
		}
	}
	
	result = max(result, max1 + max2);
	visited[cur] = false;

	return max1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	vector< vector< pair<int, int> > > E(10000);
	for(int A, B, C; ; ) {
		cin>>A>>B>>C; if(cin.eof()) break; A--; B--;
		E[A].push_back(make_pair(B, C));
		E[B].push_back(make_pair(A, C));
	}
	
	vector<bool> visited(10000, false);
	for(int i=0; i<10000; i++) result = max(result, dfs(E, visited, 0));
	
	cout<<result;
}
