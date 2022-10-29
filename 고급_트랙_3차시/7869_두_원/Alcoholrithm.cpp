#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed;
	cout.precision(3);

	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	auto get_dist = [&]() {return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); };

	double dist = get_dist();

	if (r1 > r2) {
		swap(x1, x2);
		swap(y1, y2);
		swap(r1, r2);
	}

	if (dist >= r1 + r2) {
		cout << 0.000 << '\n';
	}
	else if (dist + r1 <= r2) {
		cout << r1 * r1 * M_PI;
	}
	else {
		double theta1 = acos((r1 * r1 + dist * dist - r2 * r2) / (2 * dist * r1));
		double theta2 = acos((r2 * r2 + dist * dist - r1 * r1) / (2 * dist * r2));

		double S1 = (r1 * r1 * theta1) - (r1 * r1 * sin(2 * theta1) / 2);
		double S2 = (r2 * r2 * theta2) - (r2 * r2 * sin(2 * theta2) / 2);

		cout << S1 + S2;

	}
	return 0;
}