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
	cin >> str;

	vector<int> arr;
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') {
			if (num % 2 == 1) {
				cout << -1;
				return 0;
			}
			if (num != 0) arr.push_back(num);
			num = 0;
		}
		else 
			num++;
	}
	if (num % 2 == 1) {
		cout << -1;
		return 0;
	}
	if (num != 0) arr.push_back(num);

	string ans;
	int idx = 0;
	int temp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.') ans += '.';
		else {
			temp = arr[idx];
			for (int j = 0; j < temp / 4; j++) ans += "AAAA";
			for (int j = 0; j < temp % 4; j++) ans += 'B';
			i += arr[idx] - 1;
			idx++;
		}
	}

	cout << ans;

	return 0;
}