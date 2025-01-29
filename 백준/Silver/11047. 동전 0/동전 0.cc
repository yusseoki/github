#include <iostream>
#include <vector>
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

	int count = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) {
			count += k / arr[i]; //최대 동전으로 나누어 개수 누적
			k = k % arr[i]; //나머지로 다시 찾기
		}
	}

	cout << count << "\n";
}