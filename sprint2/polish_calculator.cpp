// https://contest.yandex.ru/contest/22781/run-report/95326400/

/*
--Principle of Operation--

To solve this task, I used a custom implementation of a stack.

Numbers are pushed onto the stack. If an operation sign is encountered, two 
top numbers are taken from the stack, and the result of the operation is pushed 
back onto the top of the stack. The result of the expression will be at the top of 
the stack.

In the case of negative numbers, I used the `floor` function to round the result down.

For convenience in working with the string, I wrote a function to split the string into 
individual substrings, which are stored in a vector.

--Time Complexity--

To process the string, we require O(n) time, as we traverse the string once.

To compute the result of the expression also requires O(n) time, as we traverse the vector 
once. For storing numbers and intermediate results, we use a stack, and the `push` and `pop` 
operations take O(1) time.

--Space Complexity--
The amount of memory used depends on the size of the input string.
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
