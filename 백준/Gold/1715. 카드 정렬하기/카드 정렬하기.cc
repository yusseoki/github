#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> my; //우선순위 큐 사용하여 오름차순 정렬

	for (int i = 0; i < n; i++) {
		int data;
		cin >> data;
		my.push(data);
	}

	int data1 = 0; //가장 작은 값
	int data2 = 0; //다음으로 작은 값
	int sum = 0;

	while (my.size() != 1) {
		data1 = my.top();
		my.pop();
		data2 = my.top();
		my.pop();
		sum += data1 + data2;
		my.push(data1 + data2);
	}

	cout << sum << "\n";
}