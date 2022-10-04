#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char grid[101][101];

int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};
int W, H;
int minimum = 987654321;

vector<pair<int,int>> point;
int bfs(void) {
    queue<vector<int>> q;
    vector<vector<int>> visited(100, vector<int>(100, 987654321));
    visited[point[0].first][point[0].second] = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = point[0].second + dx[i];
        int ny = point[0].first + dy[i];
        if (nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] != '*' ) {
            q.push({ny, nx, i, 0});
            visited[ny][nx] = 0;
        }
    }
    while(!q.empty()) {
        vector<int> front = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int nx = front[1] + dx[i];
            int ny = front[0] + dy[i];
            if (nx >= 0 && nx < W && ny >= 0 && ny < H && grid[ny][nx] != '*' ) {
                int next = front[3];
                if (front[2] != i) {
                    next += 1;
                }
                if (visited[ny][nx] >= next) {
                    visited[ny][nx] = next;
                    q.push({ny, nx, i, next});
                }
        }
        }
        
    }

    return visited[point[1].first][point[1].second];
}
int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> W >> H;
    
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j< W; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                point.push_back({i, j});
            }
        }
    }

    
    cout << bfs();
}