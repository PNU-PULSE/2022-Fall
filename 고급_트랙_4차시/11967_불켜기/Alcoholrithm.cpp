#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;

bool rooms[101][101];
bool visited[101][101];
vector<pii> switchs[101][101];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int x, y;
    pii target;

    for (int i = 0; i < M; ++i) {
        cin >> x >> y >> target.first >> target.second;
        switchs[x][y].push_back(target);
    }

    queue<pii> q;
    q.push({ 1, 1 });
    int cnt = 1;
    rooms[1][1] = true;
    visited[1][1] = true;

    while (!q.empty()) {
        pii front = q.front();
        q.pop();
        for (auto s : switchs[front.first][front.second]) {
            if (!rooms[s.first][s.second]) {
                rooms[s.first][s.second] = true;
                ++cnt;
                for (int i = 0; i < 4; ++i) {
                    int nx = s.first + dx[i];
                    int ny = s.second + dy[i];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && visited[nx][ny]) {
                        q.push(s);
                        visited[s.first][s.second] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && rooms[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    cout << cnt;

    return 0;
}
