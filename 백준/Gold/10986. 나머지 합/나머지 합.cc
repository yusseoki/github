#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<long> sum(N, 0); //구간 합 벡터
	vector<long> mod(M, 0); //인덱스의 나머지

	long answer = 0;
	cin >> sum[0];

	for (int i = 1; i < N; i++) {
		int temp = 0;
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}

	for (int i = 0; i < N; i++) {
		int modula = sum[i] % M;
		if (modula == 0)
			answer++;
		mod[modula]++;
	}

	for (int i = 0; i < M; i++) {
		if (mod[i] > 1)
			answer += (mod[i] * (mod[i] - 1)) / 2;

	}

	cout << answer << "\n";
}