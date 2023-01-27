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

	vector<bool> prime(1003002, false);
	int N;
	cin >> N;

	prime[1] = true;
	for (long long i = 2; i <= 1003001; i++) {
		if (prime[i]) continue;
		for (long long j = i * i; j <= 1003001; j += i)
			prime[j] = true;
	}

	string str;
	bool palin;
	for (int i = N; i <= 1003001; i++) {
		if (prime[i]) continue;
		str = to_string(i);
		palin = true;
		for (int j = 0; j < str.size() / 2; j++) {
			if (str[j] == str[str.size() - 1 - j]) continue;
			palin = false;
		}
		if (palin) {
			cout << i;
			break;
		}
	}

	return 0;
}