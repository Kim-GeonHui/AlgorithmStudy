#include <stdio.h>
#include <iostream>
#include <vector>
#pragma warning (disable:4996)

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> resultArr;
	vector<int> visitArr(N + 1);

	int count = 0;
	
	while (resultArr.size() != N) {

		for (int i = 1; i < N + 1; i++) {
			if (visitArr[i])
				continue;

			count++;
			if (count % K == 0) {
				resultArr.push_back(i);
				visitArr[i] = true;
			}
		}
	}

	cout << '<';
	for (int i = 0; i < resultArr.size() - 1; i++) {
		cout << resultArr[i] << ',' << ' ';
	}
	cout << *(resultArr.end() - 1) << '>';

	return 0;
}