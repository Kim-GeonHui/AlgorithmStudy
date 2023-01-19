#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str, ans;
	vector<char> arr;
	cin >> str;
	bool zero = false;
	int num = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0' && !zero) {
			zero = true;
			continue;
		}
		num += str[i] - 48;
		arr.push_back(str[i]);
	}
	
	if (!zero) cout << -1;
	else if (num % 3 != 0) cout << -1;
	else {
		sort(arr.rbegin(), arr.rend());
		for (char c : arr) cout << c;
		cout << '0';
	}

	return 0;
}