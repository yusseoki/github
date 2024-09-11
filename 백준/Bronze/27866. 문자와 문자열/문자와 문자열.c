#include <stdio.h>

int main() {
    char arr[1001];
    int i;
    scanf("%s", arr, sizeof(arr));
    scanf("%d", &i);
    printf("%c\n", arr[i - 1]);
    return 0;
}