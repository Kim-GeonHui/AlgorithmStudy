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

	int ans = 0;
	for (int i = 0; i < str.size() - 1; i++)
		if (str[i] != str[i + 1]) ans++;

	cout << (ans + 1) / 2;

	return 0;
}