#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	set<string> s;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		s.insert(str);
	}

	int answer = 0;

	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) answer++;
	}

	cout << answer << '\n';

	return 0;
}