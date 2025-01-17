#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>A(n, 0); //입력 받을 수
	vector<int>S(n, 0); //누적 합 배열

	for (int i = 0; i < n; i++)
		cin >> A[i];

	sort(A.begin(), A.end()); //내림차순 정렬

	int sum = 0;
	int result = 0;
	sum += A[0];
	S[0] = sum;
	result += S[0];
	for (int i = 1; i < n; i++) {
		sum += A[i]; //합을 누적
		S[i] = sum; //누적 값 배열에 저장
		result += S[i]; 
	}
	cout << result << "\n";
}