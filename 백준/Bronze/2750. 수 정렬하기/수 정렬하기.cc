#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>arr(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n - 1; i++) { //맨 마지막은 이미 정렬 되기 때문에 -1 해줌
		for (int j = 0; j < n - i - 1; j++) { //가장 큰 수가 맨 뒤로 차레로 정렬되기에 i를 게속해서 반복회수에서 빼줌
			if (arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}


	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";
}