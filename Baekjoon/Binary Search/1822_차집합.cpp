#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int nA, nB;
	cin >> nA >> nB;
	vector<int> A(nA);
	vector<int> B(nB);

	for (int i = 0; i < nA; i++) cin >> A[i];
	for (int i = 0; i < nB; i++) cin >> B[i];

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	vector<int> ans;
	for (int target : A) {
		if (!binary_search(B.begin(), B.end(), target))
			ans.push_back(target);
	}

	cout << ans.size() << '\n';
	for (int answer : ans) cout << answer << ' ';

	return 0;
}