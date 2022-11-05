# BOJ 11967 불켜기

![문제 이미지](https://user-images.githubusercontent.com/29500858/200119803-4118e522-24b8-4e42-9340-a29413bf0886.png)

### BFS

베시가 방을 이동하려면 현재 위치에서 상하좌우 인접한 방이면서도, 불이 켜져 있는 방이어야한다. <br>
따라서 상하좌우 인접한 방이지만 처음에는 불이 꺼져 있어 갈 수 없었다가 나중에 불이 켜져서 이동할 수 있게 될 수 도 있다. <br>

따라서 BFS를 수행하는 큐에 현 위치에서 이동 가능한 방 외에도 특정 방에 불을 킬때 마다, <br>
만약 그 방에 인접한 방의 불에 방문 기록이 있다면, 새로 불을 킨 방은 새롭게 이동 가능한 방이 되므로 큐에 넣어주면 된다. <br>

```C++
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
```
