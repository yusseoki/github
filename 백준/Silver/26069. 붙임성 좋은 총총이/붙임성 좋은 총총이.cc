#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<string>list;
	list.insert("ChongChong");
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		if (list.count(a) == 1 || list.count(b) == 1) {
			list.insert(a);
			list.insert(b);
		}
	}
	cout << list.size();
	return 0;
}