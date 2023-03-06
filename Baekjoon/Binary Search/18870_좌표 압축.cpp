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
	vector<int> arr(N);
	set<int> s;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}

	vector<int> list;
	auto it = s.begin();
	while (it != s.end()) {
		list.push_back(*it);
		it++;
	}

	for (int target : arr) {
		cout << lower_bound(list.begin(), list.end(), target) - list.begin() << ' ';
	}

	return 0;
}