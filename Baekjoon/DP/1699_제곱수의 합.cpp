#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#pragma warning (disable:4996)

using namespace std;

int main() {

	int N;
	cin >> N;

	int tempIndex = 0;
	
	vector<long long int> resultArr(N);
	vector<long long int> tempArr;
	resultArr[0] = 1;
	tempArr.push_back(1);

	for (int i = 1; i < N; i++) {
		if (i == pow(tempIndex + 2, 2) - 1) {
			tempIndex++;
			tempArr.push_back(1);
			resultArr[pow(tempIndex + 1, 2) - 1] = 1;
			continue;
		}

		for (int j = 0; j < tempIndex + 1; j++) {
			if (resultArr[i - pow(j + 1, 2)] != 0) {
				tempArr[j] = resultArr[i - pow(j + 1, 2)] + 1;
			}
		}

		resultArr[i] = *min_element(tempArr.begin(), tempArr.end());
	}
	
	cout << resultArr[N - 1];

	return 0;
}