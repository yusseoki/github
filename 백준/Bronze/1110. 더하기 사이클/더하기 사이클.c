#include <stdio.h>
#include <stdlib.h>

int main() {
    int num; //원래의 수
    int count = 0; //사이클 수
    int sum = 0; //자리수 합
    int make; //만들어진 새로운 수
    int original; //원래 수를 저장할 변수
    int first, second;
    scanf("%d", &num);
    original = num;
    while (1) {
        count++;
        if (num < 10) {
            first = 0;
            second = num;
        }
        else {
            first = num / 10;
            second = num % 10;
        }
        make = second * 10 + (first + second) % 10;
        num = make;
        if (make == original)
            break;
    }
    
    printf("%d\n", count);
    return 0;
}