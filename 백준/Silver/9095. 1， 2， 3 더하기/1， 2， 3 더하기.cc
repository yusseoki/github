#include<iostream>
using namespace std;

int main() {
	int T;
	int n;
	cin >> T;
	int dp[11]; //11이전까지의 수
	
	dp[0] = 0; // 0
	dp[1] = 1; // 1
	dp[2] = 2; // 1+1 , 2
	dp[3] = 4; // 1+1+1, 1+2, 2+1, 3

	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]; //dp[4]부터 1, 2, 3을 사용하여 차례로 구함
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << dp[n] << endl;
	}
}