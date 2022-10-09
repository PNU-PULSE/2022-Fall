#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0;i<t;i++) {
        int n;
        cin >> n;
        int log[n];
        for(int j=0;j<n;j++) {
            cin >> log[j];
        }
        sort(log,log+n);
        reverse(log,log+n);
        deque<int> dq;
        for(int j=0;j<n;j++) {
            if(j%2==0) {
                dq.push_front(log[j]);
            }
            else {
                dq.push_back(log[j]);
            }
        }
        int max_gap = abs(dq.front()-dq.back());
        while(dq.size() > 1) {
            int temp = dq.front();
            dq.pop_front();
            int gap = abs(dq.front()-temp);
            if(max_gap < gap) {
                max_gap = gap;
            }
        }
        cout << max_gap << endl;
    }

}