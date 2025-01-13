#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M; //N개의 수, M번의 케이스
	int arr[100001] = {}; //각 구간의 합을 저장할 배열, 인덱스 1부터 시작

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num; // 숫자를 입력 받고
		arr[i] = arr[i - 1] + num; //배열의 1번째 인덱스부터 구간의 합을 저장
	}

	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << arr[end] - arr[start - 1] << "\n";
	}

}