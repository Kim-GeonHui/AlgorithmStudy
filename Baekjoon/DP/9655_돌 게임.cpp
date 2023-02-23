#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N % 2 == 1) cout << "SK" << '\n';
	else cout << "CY" << '\n';

	return 0;
}