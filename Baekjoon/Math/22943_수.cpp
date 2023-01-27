#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, M;
	cin >> K >> M;

	int temp = 1;
	vector<bool> prime(100001, false);
	set<char> s;
	string str;
	prime[1] = true;

	for (long long i = 2; i <= 100000; i++) {
		if (prime[i]) continue;
		for (long long j = i * i; j <= 100000; j += i)
			prime[j] = true;
	}

	for (int i = 1; i < K; i++) temp *= 10;

	bool check1, check2;
	int temp2;
	int ans = 0;
	for (int i = temp; i < temp * 10; i++) {
		s.clear();
		str = to_string(i);
		for (int i = 0; i < str.size(); i++) s.insert(str[i]);
		if (s.size() != K) continue;

		check1 = false;
		for (int j = 2; j < i / 2; j++) {
			if (prime[j]) continue;
			if (prime[i - j]) continue;

			check1 = true;
			break;
		}
		
		if (!check1) continue;

		check2 = false;
		temp2 = i;
		while (temp2 % M == 0) temp2 /= M;
		for (int j = 2; j * j <= temp2; j++) {
			if (prime[j]) continue;
			if (temp2 % j != 0) continue;
			if (prime[temp2 / j]) continue;

			check2 = true;
			break;
		}

		if (check2) ans++;
	}

	cout << ans;

	return 0;
}