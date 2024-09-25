#include <stdio.h>

int main() {
    char arr[8][8];
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf(" %c", &arr[i][j]);//개행문자 무시를 위해 띄어줌
            if (i % 2 == 0) { //짝수행일 때
                if (j % 2 == 0 && arr[i][j] == 'F') { //흰색칸이 (0,0)부터 시작이므로 짝수열 일 때만 흰색칸
                    count++;
                }
            }
            else { //홀수행일 때
                if (j % 2 == 1 && arr[i][j] == 'F') //홀수열 일 때만 흰색칸
                    count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}