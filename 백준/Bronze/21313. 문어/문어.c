#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i = 0;
    scanf("%d", &n);

    //수열을 담을 배열
    int* arr = (int*)malloc(n * sizeof(int));

    // 수열 생성
    //문어가 짝수개이면 1 2 를 반복
    for (i = 0; i < n; i++)
        arr[i] = (i % 2) + 1;

    // 수열 출력
    if (n % 2 == 0) {
        //짝수개이면
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else { //홀수이면
        for (int i = 0; i < n-1; i++)
            printf("%d ", arr[i]);
        printf("3\n"); //최선의 방법을 고려하여 문어가 홀수 개 이면 무조건 3번으로 잡게 됨
    }

    free(arr);

    return 0;
}