#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//투포인터 사용
	int start_index = 1;
	int end_index = 1;

	int count = 1; //N의 값을 0+N으로 이미 찾았다고 가정하고 1로 초기화
	int sum = 1; //1부터 시작이므로 합을 1로 초기화

	while (end_index != N) { //마지막 N을 찾으면 종료
		if (sum == N) { //합의 값이 일치하면
			count++; //count 증가해주고
			end_index++; //끝 포인터를 옮겨줌
			sum += end_index; //end_index 값을 더해주고 다시 찾음 -> 이후 sum이 N보다 커지므로 start_index 값을 늘려주며 다시 찾음
		}
		else if(sum>N){
			sum -= start_index;
			start_index++;
		}
		else {
			end_index++;
			sum += end_index;
		}
	}
	cout << count << "\n";
}