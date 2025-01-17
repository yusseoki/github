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

	stack<int>stack;
	vector<int>arr(n, 0);
	vector<int>result(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	stack.push(0);

	for (int i = 1; i < n; i++) {
		while (!stack.empty() && arr[stack.top()] < arr[i]) { //스택이 차있고 top 값보다 큰 값이 들어오면 오큰수
			result[stack.top()] = arr[i]; //오큰수로 지정
			stack.pop();
		}
		stack.push(i);
	}
	while (!stack.empty()) { //오큰수가 지정되지 않은 수
		result[stack.top()] = -1; //-1로 지정
		stack.pop();
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}