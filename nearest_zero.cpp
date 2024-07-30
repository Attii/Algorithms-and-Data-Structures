// https://contest.yandex.ru/contest/22450/run-report/94411199/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> getNearestZeros(const vector<int>& houses) {
	vector<int> result(houses.size(), numeric_limits<int>::max());

	int last_zero = -1;
	for (size_t i = 0; i < houses.size(); ++i) {
		if (houses[i] == 0) {
			result[i] = 0;
			last_zero = i;
			continue; 
		}

		if(last_zero != -1)
			result[i] = (i - last_zero);
	}

	for (int i = last_zero; i >= 0; --i) {
		if (houses[i] == 0) {
			last_zero = i;
			continue;
		}
		
		result[i] = min(result[i], result[i+1] + 1);
	}

	return result;
}

void Print(vector<int> vec) {
	for (size_t i = 0; i < vec.size(); ++i){
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n; 
	vector<int> houses(n); 
	for (int i = 0; i < n; ++i) {
		cin >> houses[i];
	}	
	Print(getNearestZeros(houses));
}