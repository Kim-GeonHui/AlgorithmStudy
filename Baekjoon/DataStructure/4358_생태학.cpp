#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#pragma warning (disable:4996)

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;

	map<string, double> nameMap;

	string str;
	while (getline(cin, str)) {
		if (nameMap.find(str) == nameMap.end())
			nameMap.insert({ str, 1 });
		else
			nameMap[str]++;
		N++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto it = nameMap.begin(); it != nameMap.end(); it++) {
		cout << it->first << ' ' << (it->second / N) * 100 << '\n';
	}

	return 0;
}