#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int>arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		arr.push(i+1);

	while (arr.size() != 1) {
		int temp = 0;
		arr.pop(); //맨 앞의 카드 pop
		temp = arr.front(); //첫 번째 원소 저장
		arr.pop(); //맨 위 원소는 pop
		arr.push(temp); //맨 뒤에 맨 앞 원소 삽입
	}
	
	cout << arr.front()<<endl;

}