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

	int N;
	cin >> N;
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.size() - 1; i++) 
		if (str[i] != str[i + 1]) count++;

	int ans = 0;
	if (count % 2 == 1) {
		ans++;
		count--;
	}
	while (count >= 2) {
		count -= 2;
		ans++;
	}

	cout << ans + 1;

	return 0;
}