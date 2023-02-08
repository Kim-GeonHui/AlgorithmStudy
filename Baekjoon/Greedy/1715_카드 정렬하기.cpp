#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long num, ans;
	multiset<long long> s;
	for (int i = 0; i < N; i++) {
		cin >> num;
		s.insert(num);
	}

	ans = 0;
	while (s.size() > 1) {
		auto it1 = s.begin();
		auto it2 = s.begin();
		it2++;
		ans += *it1 + *it2;
		s.insert(*it1 + *it2);
		s.erase(it1);
		s.erase(it2);
	}
	cout << ans;

	return 0;
}