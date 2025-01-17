#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	vector<int>arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cout << arr[k - 1] << "\n";
}