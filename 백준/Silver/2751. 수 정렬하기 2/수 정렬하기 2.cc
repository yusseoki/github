#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
}