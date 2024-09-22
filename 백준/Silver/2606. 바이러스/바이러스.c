#include<stdio.h>

int arr[100][100] = { 0 }; //컴퓨터가 연결된 상태를 나타내는 배열(인접행렬 사용)
int visited[100] = { 0 }; //방문 컴퓨터 확인용 배열
int n; //총 컴퓨터 대수
int count = 0; //감염 컴퓨터 대수

void dfs(int number) {
    visited[number] = 1; //방문 확인을 위해 1로 나타냄
    count++; //감염 여부 증가
    for (int i = 1; i <= n; i++) { //컴퓨터 번호에 맞춰 1부터 시작
        if (arr[number][i] == 1 && !visited[i]) //현재 컴퓨터와 연결되어 있고 방문하지 않았다면
            dfs(i);
    }
}

int main() {
    int m, a, b;
    scanf("%d", &n); //총 컴퓨터 대수
    scanf("%d", &m); //연결된 컴퓨터 대수

    for (int i = 0; i < m; i++) { //연결 컴퓨터 입력
        scanf("%d %d", &a, &b);
        arr[a][b] = arr[b][a] = 1; //양방향 그래프에 의해
    }

    dfs(1); //바이러스 시작 컴 번호

    printf("%d\n", count - 1); //1번 컴퓨터 제외하고 출력

    return 0;
}