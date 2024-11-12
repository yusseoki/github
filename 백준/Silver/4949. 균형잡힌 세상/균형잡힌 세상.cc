#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool result(string& s) {

	vector<char>stack;
	for (char a : s) {
		if (a == '(' || a == '[')
			stack.push_back(a);
		else if (a == ')') {
			if (stack.empty() || stack.back() != '(')
				return false;
			stack.pop_back();
		}
		else if (a == ']') {
			if (stack.empty() || stack.back() != '[')
				return false;
			stack.pop_back();
		}
	}
	return stack.empty();
}

int main() {

	while (true) {
		string list;
		getline(cin, list);
		if (list == ".")
			break;
		if (result(list))
			cout << "yes\n";
		else
			cout << "no\n";

	}
	return 0;
}