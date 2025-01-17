#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	vector<int> arr(str.size(), 0);

	for (int i = 0; i < str.size(); i++)
		arr[i] = stoi(str.substr(i, 1)); //문자 한개씩 분리
	for (int i = 0; i < str.length(); i++) {
		int max = i;
		for (int j = i + 1; j < str.size(); j++) { //최대값 찾기
			if (arr[j] > arr[max])
				max = j;
		}
		if (arr[i] < arr[max]) { //최대값과 루프의 가장 앞 인덱스 데이터와 swap
			swap(arr[i], arr[max]);
		}
	}

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
}