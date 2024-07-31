// https://contest.yandex.ru/contest/22450/run-report/94411007/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int countPoints(int k, const vector<string>& table) {
	vector<int> number_of_signs(10, 0);

	for(const string& row : table) {
		for (char sign : row) {
			if (sign != '.') {
				number_of_signs[sign - '0'] += 1;
			}
		}
	}

	int points = count_if(number_of_signs.begin(), number_of_signs.end(), 
							[k](int  num){
								return ((num > 0) && (num <= 2 * k));
							});

	return points;
}

int main() {
	int k;
	cin >> k;
	string line;
	vector<string> table;
	getline(cin, line);
	for (size_t i = 0; i < 4; i++) {
		getline(cin, line);
		table.push_back(line);
	}

	cout << countPoints(k, table) << endl;
}