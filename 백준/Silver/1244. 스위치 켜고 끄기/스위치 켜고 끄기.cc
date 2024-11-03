#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; // 총 스위치 수
	cin >> n;
	vector<int> list(n); // 스위치 상태 저장 벡터

	for (int i = 0; i < n; i++)
		cin >> list[i];

	int person; //사람 수
	cin >> person;
	for (int i = 0; i < person; i++) {
		int sex, position;
		cin >> sex >> position; //성별과 위치 저장

		if (sex == 1) { //남자이면
			for (int j = position - 1; j < n; j += position) //숫자의 배수만 바꿔준다
				list[j] = 1 - list[j]; //1과 0만 있기 떄문에 1에서 빼면 반대의 값이 나온다
		}
		else { //여자이면
			int index = position - 1; //인덱스 위치 저장
			list[index] = 1 - list[index]; //현재의 스위치 값 바꿔줌
			int plus_minus = 1; //더하거나 빼서 현재와 대칭을 이룰 수를 1로 초기화
			while (index - plus_minus >= 0 && index + plus_minus < n && list[index + plus_minus] == list[index - plus_minus]) {
				//인덱스가 0과 마지막 인덱스 사이이고 대칭 값이 같을 때만 실행
				list[index - plus_minus] = 1 - list[index - plus_minus]; //스위치 값을 반대로 바꿔줌
				list[index + plus_minus] = 1 - list[index + plus_minus];
				plus_minus++; //더하거나 빼는 수를 1씩 증가
			}
		}
	}



	for (int i = 0; i < n; i++) {
		cout << list[i] << " ";
		if ((i + 1) % 20 == 0) // 20개마다 줄바꿈
			cout << "\n";
	}
	cout << "\n";

	return 0;
}