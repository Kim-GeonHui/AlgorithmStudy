#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	vector<int> arr1;
	vector<char> arr2;

	int pre = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			arr1.push_back(stoi(str.substr(pre, i)));
			arr2.push_back(str[i]);
			pre = i + 1;
		}
	}
	arr1.push_back(stoi(str.substr(pre, str.size())));

	int ans = arr1[0];
	int k = 1;
	for (int i = 0; i < arr2.size(); i++) {
		if (arr2[i] == '-') break;
		ans += arr1[k];
		k++;
	}

	int temp = 0;
	if (k != arr1.size()) temp = arr1[k];
	for (int i = k; i < arr2.size(); i++) {
		if (arr2[i] == '-') {
			ans -= temp;
			temp = arr1[i + 1];
		}
		else 
			temp += arr1[i + 1];
	}

	if (temp != 0) ans -= temp;
	cout << ans;

	return 0;
}