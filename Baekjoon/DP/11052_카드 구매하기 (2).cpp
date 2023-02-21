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

	vector<int> card(N + 1);
	for (int i = 1; i <= N; i++) cin >> card[i];

	vector<int> ans(N + 1);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= i; j++) ans[i] = max(ans[i], ans[i - j] + card[j]);


	cout << ans[N];

	return 0;
}