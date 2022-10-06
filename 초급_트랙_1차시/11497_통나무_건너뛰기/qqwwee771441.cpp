#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> L(100000);
	int T, N, result;
	cin>>T;
	while(T--) {
		cin>>N;
		for(int i=0; i<N; i++) cin>>L[i];
		sort(L.begin(), L.begin()+N);
		result = 0;
		for(int i=0, j=2; j<N; i++, j++)
			result = max(result, L[j] - L[i]);
		cout<<result<<"\n";
	}
}
