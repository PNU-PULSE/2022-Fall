#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	priority_queue< int, vector<int>, greater<int> > Q;
	for(int i=0, num; i<N; i++) {
		cin>>num;
		Q.push(num);
	}
	
	int result = 0;
	while(Q.size() > 1) {
		int sum = 0;
		sum += Q.top(); Q.pop();
		sum += Q.top(); Q.pop();
		Q.push(sum);
		result += sum;
	}
	
	cout<<result;
}
