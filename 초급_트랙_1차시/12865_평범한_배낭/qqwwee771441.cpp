#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

int cache[101][100001];

int dp(vector< pair<int, int> >& vec, int idx, int K) {
	if(K < 0) return INT_MIN;
	if(idx == vec.size() || K==0) return 0;
	
	int& ret = cache[idx][K];
	if(ret != -1) return ret;
	
	ret = max(dp(vec, idx+1, K), dp(vec, idx+1, K-vec[idx].first) + vec[idx].second);
	return ret;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, K;
	cin>>N>>K;
	
	vector< pair<int, int> > vec;
	for(int i=0, w, v; i<N; i++) {
		cin>>w>>v;
		vec.push_back(make_pair(w, v));
	}
	
	memset(cache, -1, sizeof(cache));
	cout<<dp(vec, 0, K);
}
