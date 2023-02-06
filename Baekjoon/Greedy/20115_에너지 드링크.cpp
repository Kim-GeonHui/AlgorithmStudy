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
	vector<double> arr;
	double drink;
	for (int i = 0; i < N; i++) {
		cin >> drink;
		arr.push_back(drink);
	}

	sort(arr.rbegin(), arr.rend());
	double ans = arr[0];
	for (int i = 1; i < N; i++) 
		ans += arr[i] / 2;

	cout << ans;

	return 0;
}