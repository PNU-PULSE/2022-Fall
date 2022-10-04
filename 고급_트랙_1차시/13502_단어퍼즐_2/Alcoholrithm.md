# BOJ 13502 단어퍼즐 2

![문제 이미지](https://user-images.githubusercontent.com/29500858/193895912-b358c912-8803-4d9a-8eb5-c5e777722fa6.png)

## Trie와 DFS

문제를 해결하기 위해서는 문제를 크게 2가지 하위 단계로 나눌 수 있다.

1. dict.txt의 단어들을 효율적으로 저장하고 꺼내볼 수 있는 자료 구조
2. 퍼즐에서 구성할 수 있는 단어 찾기

dict.txt에는 2만개가 넘는 단어들이 저장되어 있기 때문에 이를 단순히 배열에 저장하기에는 
특정 단어를 찾는 것에 많은 시간이 소요된다. 
따라서 이 문제는 대용량의 단어를 효율적으로 저장하고 꺼내볼 수 있는 Trie를 구현해서 dict.txt를 저장해야 한다.

### Trie

![Trie](https://w.namu.la/s/5167a33dff28cc735f1e0dd6d755038bceb42436343b95c234e82206542e94583533ae86f3bb0f7a8d8310f478be505e973d31dbcce037c83a156bb61610f235310a59279bc17e2654321b22917aca2e3dcaf08d4388fc87a0c91a8cea9bbec6)

Trie는 위와 같이 정점가 현재 정점까지 만들어진 단어, 간선이 다음 정점에서 추가될 글자를 나타내고 있는 자료 구조이다.
Trie에서 특정 단어를 찾기 위해서는 그 단어의 길이가 m이라면 탐색 시간은 O(m) 임이 보장되기에 
대용량의 문자열을 저장 및 검색을 하는 작업에 적합한 자료 구조이다.

```C++

#define T_IDX t->c[target[idx]-'A']

struct Trie{
    Trie* c['Z' - 'A' + 1] = {nullptr,};
    bool end = false;
};

void insert(Trie* t, string target, int idx) {
    if (idx == target.length()) {
        t->end = true;
        return;
    }
    if (T_IDX == nullptr) {
        T_IDX = new Trie;
    }
    return insert(T_IDX, target, idx + 1);
}
```

Trie의 구현과 문자열을 저장하는 기능 구현은 위와 같다.
Trie 객체는 단순히 간선 정보와 해당 정점까지 만들어진 문자열이 실제 단어인지 표시하는 flag로 구성되며,
Trie에 문자열을 저장하는 insert 함수는 단어의 앞자리 문자부터 Trie에 추가하며, 만약 단어가 끝이나면
Trie의 flag에 표시를 해준다.

### DFS

퍼즐에서 만들어질 수 있는 단어를 찾는 DFS는 간단하다.
하지만 퍼즐에서는 일반적인 그리드에서의 DFS 문제처럼 상하좌우로만 이동이 가능한 것이 아닌 대각선으로도 움직일 수 있기에 더 이상 탐색할 가치가 없으면 DFS를 탈출하는 코드를 추가해주어야 한다.
탈출 조건을 찾는 것은 간단하다. Trie에서 문자열 탐색 과정에서 만약 중간에 간선이 없어서 더 이상 탐색을 진행하지 못할 경우, 찾을 문자열에 아무리 문자를 추가해도 의미 없다. 따라서 Trie 탐색 과정에서 다음 문자를 나타내는 간선이 없는 경우
DFS에서 즉각적인 백트래킹이 이루어지도록 했다.

```C++
int check(Trie* t, string target, int idx) {
    if (idx == target.length()){
        if (t -> end){
            return 1;  
        }
        else {
            return 2;
        }
    }
    if (T_IDX == nullptr) {
        return 0;
    }
    else {
        return check(T_IDX, target, idx + 1);
    }
}

void dfs(vector<vector<bool>>& visited, string curr, int x, int y) {
    switch(check(trie, curr, 0)) {
        case 0:
            return;
        case 1:
            us.insert(curr);
            break;
    }

    for(int i = 0; i< 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >=0 && ny < 5 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(visited, curr + puzzle[nx][ny], nx, ny);
            visited[nx][ny] = false;
        }
    }    
}

```

이상, 위 2 가지 요소에 기반해서 구현한 전체 코드는 다음과 같다.

```C++
#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

#define T_IDX t->c[target[idx]-'A']

string str = "AARGH AARON ... ZURICH ZUWAYA ZZAP";

struct Trie{
    Trie* c['Z' - 'A' + 1] = {nullptr,};
    bool end = false;
};

void insert(Trie* t, string target, int idx) {
    if (idx == target.length()) {
        t->end = true;
        return;
    }
    if (T_IDX == nullptr) {
        T_IDX = new Trie;
    }
    return insert(T_IDX, target, idx + 1);
}

 

Trie* trie;

void init() {
    trie = new Trie;
    stringstream ss;
    ss << str;

    while(!ss.eof()) {
        string temp;
        ss >> temp;
        insert(trie, temp, 0);
    }

}

 

int check(Trie* t, string target, int idx) {
    if (idx == target.length()){
        if (t -> end){
            return 1;  
        }
        else {
            return 2;
        }
    }
    if (T_IDX == nullptr) {
        return 0;
    }
    else {
        return check(T_IDX, target, idx + 1);
    }
}

char puzzle[5][5]; 

unordered_set<string> us;

int dx[] = {1, 0, 0, -1, -1, -1, 1, 1};
int dy[] = {0, 1, -1, 0, -1, 1, -1, 1};

void dfs(vector<vector<bool>>& visited, string curr, int x, int y) {
    switch(check(trie, curr, 0)) {
        case 0:
            return;
        case 1:
            us.insert(curr);
            break;
    }

    for(int i = 0; i< 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >=0 && ny < 5 && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(visited, curr + puzzle[nx][ny], nx, ny);
            visited[nx][ny] = false;
        }
    }    
}

int main(void)

{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    init();

    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> puzzle[i][j];
        }
    }    

    

    vector<vector<bool>> visited(5, vector<bool>(5));

    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            visited[i][j] = true;
            dfs(visited, string()+puzzle[i][j], i, j);
            visited[i][j] = false;
        }
    }    

    cout << us.size();

    return 0;

}
```