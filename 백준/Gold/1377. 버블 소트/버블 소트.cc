#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first; //값 저장
		arr[i].second = i; //인덱스 저장
	}
	
	sort(arr.begin(), arr.end()); //nlogn 정렬

	int max = 0;
	
	for (int i = 0; i < n; i++) {
		if (max < arr[i].second - i) //원래 인덱스에서 정렬된 인덱스를 뺌, 최댓값이 버블정렬 시 반복 횟수
			max = arr[i].second - i;
	}
	cout << max + 1 << "\n"; //swap이 이루어지지 않은 반복횟수 1을 더함
}