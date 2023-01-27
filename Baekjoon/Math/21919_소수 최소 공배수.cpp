#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool> prime(1000001, false);
	prime[1] = true;
	for (long long i = 2; i <= 1000000; i++) {
		if (prime[i]) continue;
		for (long long j = i * i; j <= 1000000; j += i)
			prime[j] = true;
	}

	int N, num;
	vector<int> arr;
	
	cin >> N;
	while (N--) {
		cin >> num;
		if (!prime[num]) arr.push_back(num);
	}

	long long ans;
	if (arr.size() == 0) cout << -1;
	else {
		ans = arr[0];
		for (int i = 1; i < arr.size(); i++)
			ans = ans / gcd(ans, arr[i]) * arr[i];
		cout << ans;
	}

	return 0;
}