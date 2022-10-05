# BOJ 2064 IP 주소

![문제 이미지](https://user-images.githubusercontent.com/29500858/194119054-16df7c5b-e30a-4763-8a3f-f537a2112aeb.png)

## Bitshift / Bitmask

이 문제는 문제 설명처럼 특정 네트워크의 연결 정보가 주어지면, 그 네트워크의 네트워크 주소와 네트워크 마스크를 알아내는 것이 목표이다.

일단 네트워크 주소는 그 네트워크에 속한 IP 주소를 AND 연산을 수행한 것이다.

따라서 가장 먼저 10진수로 들어오는 IP 주소를 이진수로 바꾸어 32비트로 아래와 같이 변경해주어야 한다.

```C++
  vector<unsigned> ips;
	unsigned _32 = 0;
	for (int i = 0; i < n; ++i) {
		_32 = 0;
		char temp;
		int _8;
		
		for (int j = 0; j < 3; ++j) {
			cin >> _8 >> temp;
			_32 |= _8;
			_32 <<= 8;
		}
		cin >> _8;
		_32 |= _8;
		ips.push_back(_32);
	}
```

그리고 네트워크 마스크는 아래와 같이 해당 네트워크 상의 모든 IP 주소가 앞에서부터 서로 다른 부분이 나올때까지 1로 채우고, 나머지는 0으로 채우면 된다.

```C++
  unsigned _mask = 0;
	for (int i = 31; i >= 0; --i) {
		bit = 1 << i;
		bool flag = false;

		for (auto ip : ips) {
			if ((ips[0] & bit) != (ip & bit)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		else {
			_mask |= bit;
		}
	}
```

이상 모든 과정을 종합한 전체 코드이다.

```C++
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<unsigned> ips;
	unsigned _32 = 0;
	for (int i = 0; i < n; ++i) {
		_32 = 0;
		char temp;
		int _8;
		
		for (int j = 0; j < 3; ++j) {
			cin >> _8 >> temp;
			_32 |= _8;
			_32 <<= 8;
		}
		cin >> _8;
		_32 |= _8;
		ips.push_back(_32);
	}

	vector<int> nip;
	vector<int> mask;

	unsigned bit;
	unsigned _mask = 0;
	for (int i = 31; i >= 0; --i) {
		bit = 1 << i;
		bool flag = false;

		for (auto ip : ips) {
			if ((ips[0] & bit) != (ip & bit)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
		else {
			_mask |= bit;
		}
	}
	
	_32 = _mask & ips[0];
	while (_32) {
		unsigned _8 = 255;
		nip.push_back((_8 & _32));
		//cout << (_8 & _32) << ' ';
		_32 >>= 8;
	}
	while (nip.size() < 4) {
		nip.push_back(0);
	}
	for (int i = nip.size() - 1; i >= 0; --i) {
		cout << nip[i];
		if (i > 0) {
			cout << '.';
		}
	}
	cout << '\n';

	while (_mask) {
		unsigned _8 = 255;
		mask.push_back((_8 & _mask));
		//cout << (_8 & _32) << ' ';
		_mask >>= 8;
	}
	while (mask.size() < 4) {
		mask.push_back(0);
	}
	for (int i = mask.size() - 1; i >= 0; --i) {
		cout << mask[i];
		if (i > 0) {
			cout << '.';
		}
	}
	return 0;
}
```
