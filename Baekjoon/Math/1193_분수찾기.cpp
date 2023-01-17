#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X;
	cin >> X;

	int idx, cnt, temp;
	for (int i = 1; i < 10000000; i++) {
		temp = (i * (i + 1)) / 2;
		if (temp >= X) {
			idx = i;
			cnt = X - temp + i;
			break;
		}
	}

	if (idx % 2 == 0) {
		for (int i = 1; i < cnt; i++) idx--;
		cout << cnt << '/' << idx;
	}
	else {
		for (int i = 1; i < cnt; i++) idx--;
		cout << idx << '/' << cnt;
	}
	
	

	return 0;
}