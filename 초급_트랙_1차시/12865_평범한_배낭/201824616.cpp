#include <iostream>
#include <algorithm>

using namespace std;

void fastio();
void input();
void solution();
void output();

int N, K, W, V, result;

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
    cin >> N >> K;
}

void solution() {
    int arr[101][100001];

    for (int i = 0; i < 100001; i++) arr[0][i] = 0;
    for (int i = 0; i < 101; i++) arr[i][0] = 0;

    for (int i = 1; i <= N; i++) {
        cin >> W >> V;

        for (int j = 0; j <= K; j++) {
            if (W > j) arr[i][j] = arr[i - 1][j];
            else arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - W] + V);
        }
    }

    result = arr[N][K];
}

void output() {
    cout << result;
}

