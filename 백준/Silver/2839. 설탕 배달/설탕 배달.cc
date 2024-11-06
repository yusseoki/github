#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int kg; //입력받을 무게
	int count = 0; //봉지 수
	cin >> kg;
	while (kg >= 0) {
		if (kg % 5 == 0) { //봉지 최소 개수이기에 가장 큰 수로 먼저 나눔, 나누어 떨어지면 count 출력 후 종료
			count += kg / 5; //봉지 개수 count에 더해줌
			cout << count << endl;
			return 0;
		}
		kg -= 3; //5로 나누어 떨어지지 않았을 때 3씩 줄여가며 5로 나누어지는지 확인
		count++;
	}
	cout << -1 << endl; //어떠한 방법에도 나누어 떨어지지 않을 때 -1 출력
	return 0;
}