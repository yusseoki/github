#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarysearch(int* arr, int num, int end) {

	int left = 0;
	int right = end - 1;
	while (left <= right) {
		int middle = (left+right) / 2;
		if (arr[middle] == num)
			return true;
		else if (arr[middle] > num)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n); //퀵소트 사용하여 정렬
	cin >> m;
	int* result = new int[m];

	for (int i = 0; i < m; i++) {
		int input;
		cin >> input;
		if (binarysearch(arr, input, n))
			result[i] = 1;
		else
			result[i] = 0;
	}

	for (int i = 0; i < m; i++)
		cout << result[i] << " ";

	return 0;
}