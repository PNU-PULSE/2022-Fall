#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> bin_2_ip(int ip[32]) {
    vector<int> ret(4);

    int idx = 31;
    for (int i=3; i>=0; i--) {
        int num = 0;
        int mul = 1;
        for (int j=0; j<8; j++) {
            num += ip[idx] * mul;
            mul = mul * 2;
            idx--;
        }

        ret[i] = num;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;

    int ip_frame[32];
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;

        int ip[32];

        int idx = s.length() - 1;
        int ip_idx = 31;
        for (int k=3; k>=0; k--) {
            int num = 0;
            int mul = 1;
            for (int j=0; ; j++) {
                if (idx == -1 || s[idx] == '.') {
                    idx--;
                    mul = 1;
                    break;
                }
                num += (s[idx] - '0') * mul;
                mul *= 10;
                idx--;
            }

            for (int j=0; j<8; j++) {
                if (num % 2 == 1) {
                    ip[ip_idx] = 1;
                }
                else {
                    ip[ip_idx] = 0;
                }
                ip_idx--;
                num /= 2;
            }
        }

        if (i == 0) {
            for (int j=0; j<32; j++) {
                ip_frame[j] = ip[j];
            }
        }
        else {
            for (int j=0; j<32; j++) {
                if (ip_frame[j] != ip[j]) {
                    ip_frame[j] = 2;
                }
            }
        }
    }

    int mask[32];
    for (int i =0; i<32; i++)
        mask[i] = 1;

    bool mask_start = false;
    for (int j=0; j<32; j++) {
        if (ip_frame[j] == 2) mask_start = true;
        if (mask_start) {
            mask[j] = 0;
            ip_frame[j] = 0;
        }
    }

    vector<int> ans1 = bin_2_ip(ip_frame);
    vector<int> ans2 = bin_2_ip(mask);

    cout << ans1[0] << '.' << ans1[1] << '.' << ans1[2] << '.' << ans1[3] << endl;
    cout << ans2[0] << '.' << ans2[1] << '.' << ans2[2] << '.' << ans2[3] << endl;
}
