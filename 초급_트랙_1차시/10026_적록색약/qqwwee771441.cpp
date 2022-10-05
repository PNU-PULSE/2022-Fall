#include <iostream>
#include <string>
#include <vector>
#define TEST for(int i=0; i<N; i++, cout<<"\n") for(int j=0; j<N; j++) cout<<visited[i][j]<<" ";

using namespace std;

int Y[] = { 0, 0, 1,-1 };
int X[] = { 1,-1, 0, 0 };

void erase(vector<string>& P, int N, int y, int x, vector< vector<bool> >& visited, char C1, char C2) {
	if(x<0 || y<0 || x>=N || y>=N || visited[y][x]) return;
	if(P[y][x]==C1 || P[y][x]==C2) visited[y][x] = true; else return;
	for(int i=0; i<4; i++) erase(P, N, y+Y[i], x+X[i], visited, C1, C2);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin>>N;
	
	vector<string> P(N);
	for(int i=0; i<N; i++) cin>>P[i];
	
	int num = 0;
	vector< vector<bool> > visited(N, vector<bool>(N, false));
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(!visited[i][j]) {
				erase(P, N, i, j, visited, P[i][j], 0);
				num++;
			}
	cout<<num<<" ";
	
	num = 0;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) visited[i][j] = false;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(!visited[i][j]) {
				erase(P, N, i, j, visited, P[i][j], (P[i][j]=='R')?('G'):(P[i][j]=='G'?'R':0));
				num++;
			}
	cout<<num;
}
