#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int>>arr;
static vector<bool>visited_DFS;
static vector<bool>visited_BFS;

void DFS(int s) {
	cout << s << " ";
	visited_DFS[s] = true;

	for (int i : arr[s]) { //모든 연결 노드 탐색
		if (!visited_DFS[i])
			DFS(i);
	}
}

void BFS(int s) {
	queue<int>my; //큐 생성
	my.push(s);
	visited_BFS[s] = true;

	while (!my.empty()) {
		int now = my.front(); //현재 첫 노드 큐에 삽입
		my.pop(); //pop하고
		cout << now << " ";
		for (int i : arr[now]) { //pop한 노드의 연결 노드 탐색
			if (!visited_BFS[i]) {
				visited_BFS[i] = true;
				my.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	arr.resize(n + 1);
	visited_DFS = vector<bool>(n + 1, false);
	visited_BFS = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++) { //노드 입력
		int start, end;
		cin >> start >> end;
		arr[start].push_back(end);
		arr[end].push_back(start);
	}

	for (int i = 1; i <= n; i++)
		sort(arr[i].begin(), arr[i].end());

	DFS(v);
	cout << "\n";
	BFS(v);

}