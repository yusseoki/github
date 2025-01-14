#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N, 0);

	int count = 0;

	for (int i = 0; i < N; i++) //수 입력
		cin >> arr[i];

	sort(arr.begin(), arr.end()); //입력 받은 수 정렬

	for (int i = 0; i < N; i++) {
		long find = arr[i]; //처음부터 차례로 찾을 수로 저장
		int start = 0; //맨 앞과 끝 투 포인터 설정
		int end = N - 1;

		while (start < end) {
			if (arr[start] + arr[end] == find) {
				if (start != i && end != i) { //자기 자신은 포함하면 안됨
					count++;
					break;
				}
				else if (start == i) //start가 자기 자신이면
					start++;
				else if (end == i) //end가 자기 자신이면
					end--;
			}
			else if (arr[start] + arr[end] < find) {
				start++;
			}
			else
				end--;
		}
	}
	cout << count << "\n";
}