#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long cache[100][100];

long long dp(vector< vector<int> >& vec, int y, int x) {
	if(x<0 || y<0 || x>=vec.size() || y>=vec.size()) return 0LL;
	
	long long & ret = cache[y][x];
	if(ret != -1LL) return ret;
	
	int jump = vec[y][x];
	if(jump == 0) {
		if(y==vec.size()-1 && x==vec.size()-1) return ret = 1LL;
		else return ret = 0LL;
	}
	
	return ret = dp(vec, y, x+jump) + dp(vec, y+jump, x);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	vector< vector<int> > vec(N, vector<int>(N));
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
		cin>>vec[i][j];
		cache[i][j] = -1LL;
	}
	
	cout<<dp(vec, 0, 0);
}
