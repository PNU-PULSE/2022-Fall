#include <iostream>
#include <vector>

using namespace std;

int a, b;

void fibo(int D) {
	if(D == 1) { a++; return; }
	if(D == 2) { b++; return; }
	fibo(D-1); fibo(D-2);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int D, K;
	cin>>D>>K;
	
	fibo(D);
	
	int x, y = 1;
	for( ; y<K; y++)
		if((K - b*y)%a == 0) {
			x = (K - b*y)/a;
			if(x <= y) break;
		}
	
	cout<<x<<"\n"<<y;
}
