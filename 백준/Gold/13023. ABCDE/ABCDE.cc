#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>>arr; //인접행렬
static vector<bool>visited; //방문배열
static bool arrive; //도착이 되었는지 확인

void DFS(int now, int depth) {
	if (depth == 5) {
		arrive = true;
		return;
	}
	visited[now] = true;

	for (int i : arr[now]) { //현재 노드와 연결된 모든 노드 탐색
		if (!visited[i])
			DFS(i, depth + 1);
	}
	visited[now] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	arrive = false;
	arr.resize(n);
	visited = vector<bool>(n, false);

	for (int i = 0; i < m; i++) { //인접행렬 저장
		int start, end;
		cin >> start >> end;
		//양방향으로 저장
		arr[start].push_back(end);
		arr[end].push_back(start);
	}

	for (int i = 0; i < n; i++) {
		DFS(i, 1);
		if (arrive)
			break;
	}
	if (arrive)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}