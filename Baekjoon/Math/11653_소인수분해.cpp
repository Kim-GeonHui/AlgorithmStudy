#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	int temp = N;
	vector<int> ans;

	for (int i = 2; i * i <= N; i++) {
		while (temp % i == 0) {
			ans.push_back(i);
			temp /= i;
		}
	}

	for (int i : ans) {
		cout << i << '\n';
	}
	if (temp != 1) cout << temp;

	return 0;
}