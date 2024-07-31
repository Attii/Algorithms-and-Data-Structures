// https://contest.yandex.ru/contest/22781/run-report/95326400/

/*
--Принцип работы--

Для решение этой задачи я использовал собственную реализацию стэка. 

Числа складываются в стэк. Если попадается знак операции, то берутся два верхних
числа из стэка и результат операции опять кладется на вершину стэка. Результат 
выражения будет находится на вершине стэка.

В случае отрицательных чисел я использовал функцию floor для округления результата вниз. 

Для удобства работы со строкой я написал функцию для разделения строки на отдельные 
строки, которые сохраняю в векторе. 

--Временная сложность--

Для обработки строки нам требуется O(n) времени, так так проходим по строке один раз. 

Для вычисления резельтата выраения также требуется O(n) времени, так как мы проходим по 
вектору один раз. Для хранения чисел и промежуточных результатов используется стэк, а операции 
push и pop занимают O(1) времени. 

--Пространственная сложность--
Объем памяти занимаемой памяти зависит от размера входной строки. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std; 

class MyStack
{
private:
	vector<int> stack_;

public:
	void push(int x) {
		stack_.push_back(x);
	}

	int size() {
		return stack_.size();
	}

	int pop() {
		if (this->size() != 0)
		{
			int res = stack_.back();
			stack_.pop_back();
			return res;
		}
		throw out_of_range("stack is empty");
	}
};

vector<string> parse_string(const string& str) {
	vector<string> result;
	string buffer;

	for (char ch : str) {
		if (ch == ' ') {
			result.push_back(buffer);
			buffer.clear();
			continue;
		}
		buffer.push_back(ch);
	}

	if (!buffer.empty()) 
		result.push_back(buffer);

	return result;
}

int calculate(const vector<string>& exp) {
	MyStack nums;

	for (const string& var : exp) {
		if (var.size() == 1 && (var == "*" || var == "/" || var == "+" || var == "-")) {
			int rhs = nums.pop();
			int lhs = nums.pop();

			switch (var[0])
			{
			case '*':
				nums.push(lhs * rhs);
				break;

			case '/':
				nums.push(floor(lhs * 1.0 / rhs));	 
				break;

			case '+':
				nums.push(lhs + rhs);
				break;
			
			case '-':
				nums.push(lhs - rhs);
				break;
			
			default:
				break;
			}
		}
		else {
			nums.push(stoi(var));
		}
	}

	return nums.pop();
}

int main() {
	string str;
	getline(cin, str);
	cout << calculate(parse_string(str)) << endl;
}