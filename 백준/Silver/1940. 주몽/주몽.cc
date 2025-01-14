#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	cin >> M;
	int start = 0;
	int end = N - 1;
	int sum = 0;
	int count = 0;


	vector<int> arr(N, 0);
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	while (start < end) {
		sum = arr[start] + arr[end];
		if (sum == M) {
			count++;
			start++;
			end--;
		}
		else if (sum > M) {
			end--;
		}
		else {
			start++;
		}
	}

	cout << count << "\n";
}