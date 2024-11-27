#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_set<int>A, B;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		A.insert(num);
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		B.insert(num);
	}
	int count_a = 0;
	int count_b = 0;
	for (const int& a : A) //A에서 B에 존재하지 않는 원소 개수
		if (B.find(a) == B.end())
			count_a++;

	for (const int& b : B) //B에서 A에 존재하지 않는 원소 개수
		if (A.find(b) == A.end())
			count_b++;

	cout << count_a + count_b;
}