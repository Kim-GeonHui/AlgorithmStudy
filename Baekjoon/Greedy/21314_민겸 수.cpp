#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	string ans1 = "";
	string ans2 = "";
	cin >> str;
	int len = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'M') len++;
		else {
			ans1 += '5';
			if (len > 0) ans2 += '1';
			for (int j = 0; j < len; j++) ans1 += '0';
			for (int j = 0; j < len - 1; j++) ans2 += '0';
			ans2 += '5';
			len = 0;
		}
	}
	if (len > 0) {
		ans1 += '1';
		ans2 += '1';
	}
	for (int i = 0; i < len - 1; i++) {
		ans1 += '1';
		ans2 += '0';
	}

	cout << ans1 << '\n' << ans2;

	return 0;
}