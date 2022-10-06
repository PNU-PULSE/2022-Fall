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