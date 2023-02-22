#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> fiboPlus(1000001);
	vector<int> fiboMinus(1000001);
	fiboPlus[1] = 1;
	for (int i = 2; i <= 1000000; i++) fiboPlus[i] = (fiboPlus[i - 1] + fiboPlus[i - 2]) % 1000000000;
	fiboMinus[1] = 1;
	fiboMinus[2] = -1;
	for (int i = 3; i <= 1000000; i++) fiboMinus[i] = (fiboMinus[i - 2] - fiboMinus[i - 1]) % 1000000000;
	
	if (n < 0) {
		if (fiboMinus[-n] < 0) cout << -1 << '\n' << -fiboMinus[-n];
		else if (fiboMinus[-n] == 0) cout << 0 << '\n' << 0;
		else cout << 1 << '\n' << fiboMinus[-n];
	}
	else if (n == 0) cout << 0 << '\n' << fiboPlus[n];
	else cout << 1 << '\n' << fiboPlus[n];

	return 0;
}