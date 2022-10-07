#include <iostream>
#include <queue>

using namespace std;

void fastio();
void input();
void solution();
void output();

char arr[100][100];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int N, r1 = 0, r2 = 0;
queue<pair<int, int>> q;

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
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}

void change_arr(int x, int y) {
    if (arr[x][y] == 'R' || arr[x][y] == 'G') arr[x][y] = 'X';
    else if (arr[x][y] == 'B') arr[x][y] = 'Y';
    else arr[x][y] = '0';
}

void bfs(int x, int y) {
    char temp = arr[x][y];
    q.push({x, y});

    change_arr(x, y);

    while (!q.empty()) {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];

            if (xx >= 0 && xx < N && yy >= 0 && yy < N) {
                if (arr[xx][yy] == temp) {
                    change_arr(xx, yy);
                    q.push({xx, yy});
                }
            }
        }
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'R' || arr[i][j] == 'G' || arr[i][j] == 'B') { 
              bfs(i, j); 
              r1++; 
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 'X' || arr[i][j] == 'Y') { 
              bfs(i, j); 
              r2++;
            }
        }
    }
}

void output() {
    cout << r1 << " " << r2;
}
