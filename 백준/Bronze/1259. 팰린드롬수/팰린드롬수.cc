#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string arr;
    string a;
	while(1){
		cin >> arr;
		a = arr;
		if (arr[0] == '0')
			break;
		reverse(arr.begin(), arr.end());
		if (a == arr) {
			cout << "yes\n";
		}
		else
			cout << "no\n";
	}
	return 0;
}