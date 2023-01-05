#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	map<int, int> line;
	queue<int> q;

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		line[temp] = 0;
		q.push(temp);
	}

	int dx[2] = { 1, -1 };
	int next;
	int count = 0;
	long long int answer = 0;
	bool isEnd = false;

	while (!q.empty()) {
		temp = q.front();
		q.pop();

		for (int i = 0; i < 2; i++) {
			next = temp + dx[i];

			if (line.find(next) != line.end()) continue;

			line[next] = line[temp] + 1;
			q.push(next);
			count++;
			answer += line[temp] + 1;

			if (count == K) {
				isEnd = true;
				break;
			}
		}

		if (isEnd) break;
	}

	cout << answer;

	return 0;
}