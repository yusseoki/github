#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	// 입력 및 누적합 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j]; //구간들의 합 저장, sum[i - 1][j - 1]을 빼주는 이유는 한번 겹치기 때문
		}
	}

	// 쿼리 처리
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int result = sum[x2][y2]  //구간 합을 사용하여 원하는 좌표까지의 합에서 포함되지 않는 좌표의 구간합을 빼주고 [x1 - 1][y1 - 1]을 다시 한번 더해주는 이유는 중복으로 2번 빼주었기 때문
			- sum[x1 - 1][y2]
			- sum[x2][y1 - 1]
			+ sum[x1 - 1][y1 - 1];

		cout << result << "\n";
	}

	return 0;
}