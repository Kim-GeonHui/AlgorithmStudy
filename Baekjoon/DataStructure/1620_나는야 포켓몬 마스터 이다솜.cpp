#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> poketmonMap;
	vector<string> poketmonArr;

	int N, M;
	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		poketmonMap.insert({str, i + 1});
		poketmonArr.push_back(str);
	}

	for (int i = 0; i < M; i++) {
		cin >> str;

		if (0 < isdigit(str[0]))
			cout << poketmonArr[stoi(str) - 1] << '\n';
		else
			cout << poketmonMap.find(str)->second << '\n';
	}

	return 0;
}