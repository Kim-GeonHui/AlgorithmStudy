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

	int n, num1, num2, num3, temp, idx;
	vector<int> arr;
	cin >> n;
	if (n == 2) {
		cin >> num1 >> num2;
		temp = gcd(num1, num2);
	}
	else {
		cin >> num1 >> num2 >> num3;
		temp = gcd(num1, num2);
		temp = gcd(temp, num3);
	}

	for (int i = 1; i * i <= temp; i++)
		if (temp % i == 0) arr.push_back(i);

	idx = arr.size() - 1;
	if (arr[idx] * arr[idx] == temp) idx--;

	while (idx >= 0) {
		arr.push_back(temp / arr[idx]);
		idx--;
	}

	for (int num : arr) cout << num << '\n';

	return 0;
}