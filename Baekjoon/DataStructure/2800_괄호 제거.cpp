#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <stack>
#pragma warning (disable:4996)

using namespace std;

set<string> stringSet;
vector<pair<int, int>> indexArr;
vector<bool> visitArr;
vector<bool> visitStr;
string str;

void DFS(int count, int index, int max) {
	if (count >= 1) {
		string tempStr = "";
		for (int j = 0; j < str.size(); j++) {
			if (visitStr[j]) continue;
			tempStr += str[j];
		}
		
		stringSet.insert(tempStr);
	}

	if (count == max) return;

	for (int i = index; i < max; i++) {
		if (visitArr[i]) continue;

		visitStr[indexArr[i].first] = true;
		visitStr[indexArr[i].second] = true;
		visitArr[i] = true;
		DFS(count + 1, index + 1, max);
		visitStr[indexArr[i].first] = false;
		visitStr[indexArr[i].second] = false;
		visitArr[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;

	stack<int> stk;
	for (int i = 0; i < str.size(); i++) {
		visitStr.push_back(false);
		if (str[i] == '(') stk.push(i);
		else if (str[i] == ')') {
			indexArr.push_back({ stk.top(), i });
			visitArr.push_back(false);
			stk.pop();
		}
	}


	DFS(0, 0, indexArr.size());
	for (auto it = stringSet.begin(); it != stringSet.end(); it++) {
		cout << *it << '\n';
	}

	return 0;
}