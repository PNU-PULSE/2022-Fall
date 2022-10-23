#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	int result = 0;
	for(string str; N--; ) {
		cin>>str;
		stack<char> S;
		for(int i=0; i<str.length(); i++) {
			if(str[i] == 'A') {
				if(S.empty()) S.push('A');
				else if(S.top()=='B') S.push('A');
				else S.pop();
			}
			else {
				if(S.empty()) S.push('B');
				else if(S.top()=='A') S.push('B');
				else S.pop();
			}
		}
		if(S.size() == 0) result ++;
	}
	cout<<result;
}
