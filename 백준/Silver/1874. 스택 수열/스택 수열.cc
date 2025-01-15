#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> list(n, 0); //수열 저장 벡터
	vector<char> result; //push, pop 저장 벡터

	for (int i = 0; i < n; i++) {
		cin >> list[i]; //수열 입력
	}

	stack<int> stack; // 스택 배열
	int num = 1; //기본 수 1부터 증가
	bool yn = true;

	for (int i = 0; i < list.size(); i++) {
		int su = list[i]; //수열의 첫 수부터 찾음
		if (su >= num) { //현재 숫자가 찾는 숫자보다 작으면
			while (su >= num) {
				stack.push(num++); //1씩 늘려주며 push
				result.push_back('+'); //결과 벡터에 + 저장
			}
			stack.pop(); //찾을 수까지 추가하고 pop하여 원하는 수를 찾음
			result.push_back('-'); //결과 벡터에 pop 표시
		}
		else { //현재 숫자가 찾는 수보다 크면
			int top = stack.top(); //스택의 가장 윗 숫자 저장
			stack.pop();
			if (su < top) { //가장 윗 수가 찾는 수보다 크면
				cout << "NO\n"; //수열 만들 수 없음 1부터 오름차순으로 증가하기 때문
				yn = false;
				break;
			}
			else
				result.push_back('-');
		}
	}
	if (yn) {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}

	return 0;
}