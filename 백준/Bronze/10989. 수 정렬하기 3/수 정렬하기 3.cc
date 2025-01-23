#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10001] = { 0 };

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = 0;
		cin >> num;
		arr[num]++;
	}
	for (int i = 0; i <= 10000; i++) {
		if (arr[i] != 0)
			for (int j = 0; j < arr[i]; j++)
				cout << i << "\n";
	}
}