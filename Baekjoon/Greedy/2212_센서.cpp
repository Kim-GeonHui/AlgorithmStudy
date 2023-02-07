#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> sensor(N);
	for (int i = 0; i < N; i++) 
		cin >> sensor[i];
	sort(sensor.begin(), sensor.end());
	
	vector<int> gap;
	for (int i = 1; i < N; i++) gap.push_back(sensor[i] - sensor[i - 1]);
	sort(gap.rbegin(), gap.rend());
	
	int ans = 0;
	for (int i = K - 1; i < N - 1; i++) ans += gap[i];
	cout << ans;

	return 0;
}