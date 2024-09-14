#include <stdio.h>

int main() {
    int n, f, num;
    scanf("%d %d", &n, &f);
    num = (n / 100) * 100; //십의자리, 일의자리를 배재하고 생각
    for (int i = 0; i < 100; i++) {
        if ((num + i) % f == 0) { //나머지가 0인 수를 찾음
            printf("%02d\n", i); //두자리 형식으로 출력
            break;
        }
    }
    return 0;
}