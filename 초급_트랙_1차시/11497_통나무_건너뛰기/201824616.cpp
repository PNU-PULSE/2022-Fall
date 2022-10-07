#include <iostream>
#include <queue>

using namespace std;

void fastio();
void input();
void solution();
void output();

int T, N, temp, result;

int main() {
    fastio();
    cin >> T;
    for (int i = 0; i < T; i++) {
        input();
        solution();
        output();
    }
}

void fastio() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}

void input() {
    cin >> N;
}

void solution() {
    priority_queue<int> pq;
    queue<int> q;
    result = 0;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(temp);
    }

    q.push(pq.top());
    pq.pop();
    
    for (int i = 0; i < 2; i++) {
        if (result < q.front() - pq.top()) result = q.front() - pq.top();
        q.push(pq.top());
        pq.pop();
    }
    q.pop();

    while (!pq.empty()) {
        if (result < q.front() - pq.top()) result = q.front() - pq.top();
        q.push(pq.top());
        q.pop();
        pq.pop();
    }

    temp = q.front();
    q.pop();

    if (result < temp - q.front()) result = temp - q.front();
}

void output() {
    cout << result << "\n";
}

