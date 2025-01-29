#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int>arr(n);

	int start = 0;
	int end = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (start < arr[i]) //최대값 찾기
			start = arr[i];
		end += arr[i]; //시간의 총 합
	}

	while (start <= end) {
		int middle = (start + end) / 2; //총 시간의 중간 값
		int sum = 0;
		int count = 0; //블루레이 개수

		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > middle) { //저장할 수 있는 용량보다 커지면
				count++; //블루레이 수 + 1
				sum = 0; //총 합 초기화
			}
			sum += arr[i];
		}

		if (sum != 0) //남은 시간에 블루레이를 하나 더 써야 하므로
			count++;
		if (count > m) //블루레이를 줄여야 한다면
			start = middle + 1; //시간을 늘려줌
		else //블루레이가 남는다면
			end = middle - 1;
	}

	cout << start << "\n";
}