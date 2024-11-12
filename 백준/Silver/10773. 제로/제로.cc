#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0 && !arr.empty()) //입력한 숫자가 0이고 배열이 비어있지 않을 때
			arr.pop_back();
		else
			arr.push_back(num);
	}

	int sum = 0; 

	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];

	cout << sum << endl;

	return 0;
}