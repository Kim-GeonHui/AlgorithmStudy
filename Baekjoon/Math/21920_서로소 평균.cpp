#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num, X;
	vector<int> arr;
	cin >> N;
	while (N--) {
		cin >> num;
		arr.push_back(num);
	}
	cin >> X;

	long long ans = 0;
	int idx = 0;
	for (int n : arr) {
		if (gcd(n, X) == 1) {
			ans += n;
			idx++;
		}
	}

	cout << (double)ans / (double)idx;

	return 0;
}