#include <iostream>
#include <queue>

using namespace std;

void fastio();
void input();
void solution();
void output();

int n, w, L, arr[1000], result = 1;
queue<int> q;
queue<pair<int, int>> b;

int main() {
    fastio();
    input();
    solution();
    output();
}

void fastio() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}

void input() {
    cin >> n >> w >> L;

    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }
}

void solution() {
    int cL = 0;

    for (int T = 1; ; T++) {
        if (!b.empty() && T == b.front().second) {
            cL -= b.front().first;
            b.pop();
        }

        if (b.size() == w) continue;

        if (q.empty() && b.empty()) {
            result = T;
            break;
        }

        if (!q.empty() && cL + q.front() <= L) {
            cL += q.front();
            b.push({q.front(), T + w});
            q.pop();
        }
    }
}

void output() {
    cout << result;
}

