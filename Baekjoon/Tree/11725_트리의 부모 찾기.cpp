#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#pragma warning (disable:4996)

using namespace std;

multimap<int, int> nodeMap;
map<int, int> answerMap;

void findAnswer(int num) {
	auto it = nodeMap.lower_bound(num);
	
	while (it != nodeMap.end()) {
		if (it->first != num) break;

		answerMap[it->second] = it->first;
		for (auto it2 = nodeMap.lower_bound(it->second); it2->first == it->second; it2++) {
			if (it2->second == it->first) {
				nodeMap.erase(it2);
				break;
			}
		}
		findAnswer(it->second);
		it++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int node1, node2;
	for (int i = 0; i < N - 1; i++) {
		cin >> node1 >> node2;

		nodeMap.insert({ node1, node2 });
		nodeMap.insert({ node2, node1 });
	}

	findAnswer(1);

	auto it = answerMap.begin();
	while (it != answerMap.end()) {
		cout << it->second << '\n';
		it++;
	}

	return 0;
}