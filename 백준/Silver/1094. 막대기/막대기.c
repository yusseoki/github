#include <stdio.h>

int main() {
    int n; //원하는 막대 길이
    scanf("%d", &n);

    int x = 64; //원래 막대
    int count = 0;

    while (n > 0) { //빼서 0이 될 때까지
        if (x > n) { //자른 길이가 원하는 길이보다 크면
            x /= 2; //반을 자름
        }
        else { //자른 길이가 원하는 길이보다 작으면
            count++;
            n -= x; //원하는 길이에서 자른 길이를 뺌
        }
    }

    printf("%d\n", count);
    
    return 0;
}