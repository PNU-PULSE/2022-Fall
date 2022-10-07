#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

void fastio();
void input();
void solution();
void output();

int D, K, arr[2][30], temp;

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
    cin >> D >> K;
}

void solution() {
    arr[0][0] = K;
    arr[1][0] = 0;
    arr[0][1] = 0;
    arr[1][1] = 1;

    for (int i = 2; i < D; i++) {
        arr[0][i] = arr[0][i - 2] - arr[0][i - 1];
        arr[1][i] = arr[1][i - 2] - arr[1][i - 1];
    }

    temp = max(abs(arr[0][D - 1] / arr[1][D - 1]), abs(arr[0][D - 2] / arr[1][D - 2]));
}

void output() {
    while (true) {
        int l = arr[0][D - 1] + (arr[1][D - 1] * temp);
        int r = arr[0][D - 2] + (arr[1][D - 2] * temp);

        if (l > 0 && r > 0 && l <= r) {
            cout << l << endl << r;
            break;
        }

        temp--;
    }
}

