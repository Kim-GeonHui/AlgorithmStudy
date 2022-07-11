#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<vector<int>> data(N);
	vector<int> tempData;

	vector<vector<int>> maxData(N);
	vector<int> tempMaxData;

	vector <int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	tempData.push_back(0);
	tempData.push_back(1);

	data[0] = tempData;
	tempData.clear();

	tempMaxData.push_back(0);
	tempMaxData.push_back(arr[0]);
	
	maxData[0] = tempMaxData;
	tempMaxData.clear();

	// BottomUp
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < pow(2, i + 1); j++) {

			if (j % 2 == 0) {
				tempMaxData.push_back(maxData[i - 1][j / 2]);
				tempData.push_back(data[i - 1][j / 2]);
			}
			else {
				if (maxData[i - 1][j / 2] < arr[i]) {
					tempMaxData.push_back(arr[i]);
					tempData.push_back(data[i - 1][j / 2] + 1);
				}
				else {
					tempMaxData.push_back(maxData[i - 1][j / 2]);
					tempData.push_back(data[i - 1][j / 2]);
				}
			}
		}

		maxData[i] = tempMaxData;
		data[i] = tempData;

		tempMaxData.clear();
		tempData.clear();
	}
	
	int max = *max_element(data[N - 1].begin(), data[N - 1].end());
	cout << max;

	return 0;
}