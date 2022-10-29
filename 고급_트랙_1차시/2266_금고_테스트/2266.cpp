#include <iostream>
#include <vector>
#define MaxN 2100000000
#define Max(a,b) ((a>b?a:b))
#define Min(a,b) ((a<b?a:b))
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;
    vector<vector<int> >ARR(k+1,vector<int>(n+1,MaxN));

    for(int i=0;i<=n;i++) ARR[1][i]=i;

    for(int i=2;i<=k;i++){
        ARR[i][0]=0;
        for(int j=1;j<=n;j++){
            for(int x=1;x<=j;x++){
                ARR[i][j]=Min(ARR[i][j],Max(ARR[i-1][j-x],ARR[i][x-1])+1);
            }
        }
    }

    cout<<ARR[k][n];
    return 0;
}
