#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int o1, int o2) {
		int first_abs = abs(o1);
		int second_abs = abs(o2);
		if (first_abs == second_abs) //절대값이 같으면
			return o1 > o2; //첫번째 수가 크면 양수 반환, 두번째가 크면 음수 반환
		else
			return first_abs > second_abs; //첫번째 수가 크면 양수 반환, 두번째가 크면 음수 반환
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, compare>Myqueue;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0){
			if (Myqueue.empty()) { //비교할 수가 큐에 없으면 0반환
				cout << "0\n";
			}
			else
			{
				cout << Myqueue.top() << '\n'; //정렬된 우선순위 큐 출력
				Myqueue.pop();
			}
		}
		else //0이 아니라면 추가
			Myqueue.push(num);
	}
}