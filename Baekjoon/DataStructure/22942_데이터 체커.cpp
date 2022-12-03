#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<tuple<int, int, bool>> arr;

	bool isFalse = false;

	int x, r;
	for (int i = 0; i < N; i++) {
		cin >> x >> r;
		arr.push_back({ x - r, i, 0 });
		arr.push_back({ x + r, i, 1 });
	}

	sort(arr.begin(), arr.end());
	
	stack<tuple<int, int, bool>> stk;

	for (int i = 0; i < arr.size(); i++) {
		if (get<2>(arr[i]) == 0) stk.push(arr[i]);
		else {
			if (get<1>(stk.top()) == get<1>(arr[i])) stk.pop();
			else {
				isFalse = true;
				break;
			}
		}
	}

	if (!isFalse) cout << "YES" << '\n';
	else cout << "NO" << '\n';

	return 0;
}