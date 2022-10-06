#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, W, L;
	cin>>N>>W>>L;
	
	vector<int> A(N);
	for(int i=0; i<N; i++) cin>>A[i];
	
	queue<int> B;
	for(int i=0; i<W; i++) B.push(0);
	
	int time = 0;
	for(int i=0, sum=0; ; time++) {
		sum -= B.front();
		B.pop();
		if(i == N) {
			time += W;
			break;
		} else {
			if(sum+A[i] <= L) {
				B.push(A[i]);
				sum += A[i];
				i++;
			} else {
				B.push(0);
			}
		}
	}
	
	cout<<time;
}
