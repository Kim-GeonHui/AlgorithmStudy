#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long S;

bool solve(long long n) {
	long long answer;
	if (n % 2 == 0) answer = (n / 2) * (n + 1);
	else answer = (n + 1) / 2 * n;
	return answer > S;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;

	long long front = 1;
	long long end = 92682;
	long long mid = (front + end) / 2;

	while (front < end) {
		if (solve(mid)) end = mid;
		else front = mid + 1;
		mid = (front + end) / 2;
	}

	cout << end - 1;

	return 0;
}