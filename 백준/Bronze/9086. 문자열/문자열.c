#include <stdio.h>
#include <string.h>

int main() {
    char word[1000]; //단어 길이 최대 1000으로 설정
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &word, sizeof(word)); //단어 입력 받기
        size_t length = strlen(word); //strlen 함수를 사용해서 문자의 길이 length에 저장
        printf("%c%c\n", word[0], word[length-1]); //인덱스 고려하여 -1
    }
    return 0;
}