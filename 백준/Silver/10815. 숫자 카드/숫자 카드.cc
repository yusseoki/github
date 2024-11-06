#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n;

	int* list = new int[n]; //상근이가 가지고 있는 숫자
	for (int i = 0; i < n; i++)
		cin >> list[i];

	cin >> m;
	int* answer = new int[m]; //있는지 없는지 확인 할 숫자
	for (int i = 0; i < m; i++)
		cin >> answer[i];

	sort(list, list+n); //퀵소트 사용해서 가지고 있는 카드 오름차순으로 정렬

	for (int i = 0; i < m; i++) {
		if (binary_search(list, list + n, answer[i])) //이진탐색으로 해당 값 찾음
			answer[i] = 1; //같은 숫자가 있으면 1
		else
			answer[i] = 0; //같은 숫자가 없으면 0
	}

	for (int i = 0; i < m; i++)
		cout << answer[i] << " ";

	delete[] list;
	delete[] answer;

	return 0;
}