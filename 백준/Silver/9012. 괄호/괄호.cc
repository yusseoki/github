#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 50

bool result(string& s) {
	vector<char> stack;
	for (char a : s) {
		if (a == '(')
			stack.push_back(a);
		else if (a == ')') {
			if (stack.empty()) return false;
			stack.pop_back();
		}
	}
	return stack.empty();
}

int main() {
	int n;
	cin >> n;
    cin.ignore();
	vector<string>list(n);
	for (int i = 0; i < n; i++)
		getline(cin, list[i]);
	for (int i = 0; i < n; i++) {
		if (result(list[i]))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}