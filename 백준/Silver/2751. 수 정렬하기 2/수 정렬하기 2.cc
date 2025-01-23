#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>arr;
vector<int>temp;

void merge_sort(int start, int end) {
	if (end - start < 1)
		return;

	int middle = start + (end - start) / 2;

	merge_sort(start, middle);
	merge_sort(middle + 1, end);

	for (int i = start; i <= end; i++)
		temp[i] = arr[i];

	int k = start;
	int index1 = start;
	int index2 = middle + 1;

	while (index1 <= middle && index2 <= end) {
		if (temp[index1] < temp[index2])
			arr[k++] = temp[index1++];
		else
			arr[k++] = temp[index2++];
	}

	while (index1 <= middle) {
		arr[k++] = temp[index1++];
	}
	while (index2 <= end) {
		arr[k++] = temp[index2++];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	arr = vector<int>(n + 1, 0);
	temp = vector<int>(n + 1, 0);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	merge_sort(1, n);

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << "\n";
	}
}