#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>arr;
	vector<int>result;

	for (int i = 0; i < n; i++)
		arr.push_back(i + 1);
	int index = 0;
	while (!arr.empty()) {
		index = (index + k - 1) % arr.size();
		result.push_back(arr[index]);
		arr.erase(arr.begin() + index);
	}
	cout << "<";
	for (int i = 0; i < result.size(); i++) {
		if (i>0)
			cout << ", ";
		cout << result[i];
	}
	cout << ">";
	return 0;
}