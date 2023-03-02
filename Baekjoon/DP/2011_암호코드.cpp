#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	if (str[0] == '0') {
		cout << 0;
		return 0;
	}

	vector<int> ans(str.size() + 1);
	ans[1] = 1;
	if (str.size() > 1) {
		if (str[0] == '1') {
			if (str[1] == '0')
				ans[2] = 1;
			else ans[2] = 2;
		}
		else if (str[0] == '2') {
			if (1 <= str[1] - 48 && str[1] - 48 <= 6)
				ans[2] = 2;
			else ans[2] = 1;
		}			
		else if (str[1] == '0') {
			cout << 0;
			return 0;
		}
		else
			ans[2] = 1;
	}

	for (int i = 2; i < str.size(); i++) {
		if (str[i - 1] == '1') {
			if (str[i] == '0') ans[i + 1] = ans[i - 1];
			else ans[i + 1] = (ans[i] + ans[i - 1]) % 1000000;
		}
		else if (str[i - 1] == '2') {
			if (1 <= str[i] - 48 && str[i] - 48 <= 6)
				ans[i + 1] = (ans[i] + ans[i - 1]) % 1000000;
			else ans[i + 1] = ans[i - 1];
		}
		else if (str[i] == '0') {
			cout << 0;
			return 0;
		}
		else ans[i + 1] = ans[i];
	}

	cout << ans[str.size()];

	return 0;
}