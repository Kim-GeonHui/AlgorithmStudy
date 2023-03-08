#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> dot(N);
	for (int i = 0; i < N; i++) cin >> dot[i];

	sort(dot.begin(), dot.end());

	vector<pair<int, int>> line(M);
	for (int i = 0; i < M; i++)
		cin >> line[i].first >> line[i].second;

	for (int i = 0; i < M; i++) 
		cout << upper_bound(dot.begin(), dot.end(), line[i].second) - lower_bound(dot.begin(), dot.end(), line[i].first) << '\n';

	return 0;
}