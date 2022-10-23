#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	vector<int> vec(N);
	for(int i=0; i<N; i++) cin>>vec[i];
	sort(vec.begin(), vec.end());
	
	long long sum = 0LL;
	for(int i=0; i<N; i++)
		if(vec[N-i-1]-i > 0) sum += (long long)vec[N-i-1]-i;
	
	cout<<sum;
}
