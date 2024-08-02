
//해시테이블
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 20  // 의도적으로 작게 설정하여 충돌 가능성 증가
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char key[MAX_KEYWORD_LENGTH];
    bool use;
    bool deleted;
} Slot;

typedef struct {
    Slot* table; //슬롯 배열을 가리킴
    int size;
} HashTable;

// 해시 함수 (제산 함수)
int hash(const char* key, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c

    return hash % size;
}

// 해시 테이블 초기화
HashTable* initHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = TABLE_SIZE;
    ht->table = (Slot*)calloc(ht->size, sizeof(Slot));
    return ht;
}

void copyString(char* dest, const char* src) {
    int i;
    for (i = 0; i < src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

// 선형 조사법을 이용한 삽입
bool insert(HashTable* ht, char* key) { //해시 테이블과 삽입할 키를 인자로 받아 성공 여부를 반환
    int hashkey = hash(key, ht->size); //해시값 계산
    int i = 0;

    while (i < ht->size) { //모든 슬롯 조사
        int index = (hashkey + i) % ht->size; //충돌 발생시 다음 슬롯 확인
        if (!ht->table[index].use || ht->table[index].deleted) { //슬롯이 비어있거나 삭제된 상태인지 확인
            copyString(ht->table[index].key, key); //문자열 복사
            ht->table[index].use = true; //사용되고 있음을 표시
            ht->table[index].deleted = false; //삭제되지 않음을 표시
            printf("'%s' -> 인덱스 %d (해시값: %d)\n", key, index, hashkey);
            return true; //성공을 반환
        }
        printf("\n충돌 발생 '%s' -> 인덱스 %d, 다음 슬롯에 삽입\n", key, index);
        i++; //충돌시 다음 인덱스로 넘어감
    }
    printf("삽입 실패 '%s'\n", key);
    return false;  // 테이블이 가득 참
}

// 선형 조사법을 이용한 검색
bool search(HashTable* ht, const char* key) {
    int hashkey = hash(key, ht->size);
    int i = 0;

    while (i < ht->size) {
        int index = (hashkey + i) % ht->size; //+i를 하여 충돌시 다음 인덱스 확인
        if (!ht->table[index].use) //비어있다면
            break; //반복문 종료
        if (ht->table[index].use && !ht->table[index].deleted &&
            strcmp(ht->table[index].key, key) == 0) { //사용중이고 삭제되지 않고 키의 값이 일치한다면
            printf("'%s' -> 인덱스 %d (해시값:  %d)\n", key, index, hashkey);
            return true;
        }
        i++;
    }
    printf("'%s'는 없는 문자입니다\n", key);
    return false;
}

// 선형 조사법을 이용한 삭제
bool delete(HashTable* ht, const char* key) {
    int hashkey = hash(key, ht->size);
    int i = 0;

    while (i < ht->size) {
        int index = (hashkey + i) % ht->size;
        if (!ht->table[index].use)
            break;
        if (ht->table[index].use && !ht->table[index].deleted &&
            strcmp(ht->table[index].key, key) == 0) {
            ht->table[index].deleted = true;
            printf("'%s' 삭제함, 인덱스 -> %d (해시값: %d)\n", key, index, hashkey);
            return true;
        }
        i++;
    }
    printf("'%s'는 없는 문자입니다\n", key);
    return false;
}

// 해시 테이블 해제
void freeHashTable(HashTable* ht) {
    free(ht->table);
    free(ht);
}

// 해시 테이블 내용 출력
void printHashTable(HashTable* ht) {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i].use && !ht->table[i].deleted) {
            printf("[%d]: %s\n", i, ht->table[i].key);
        }
        else {
            printf("[%d]: ----\n", i);
        }
    }
    printf("\n");
}

// C 언어 키워드 배열
const char* keywords[] = {
    "char", "for", "if", "else", "while", "break", "char", "int", "double"
};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

int main() {
    HashTable* ht = initHashTable();

    // 키워드 삽입
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        insert(ht, keywords[i]);
    }

    printHashTable(ht);

    char input[MAX_KEYWORD_LENGTH];
    char operation;

    while (1) {
        printf("\n (i:삽입, s:검색, d:삭제, p:출력, q:나가기): ");
        scanf_s(" %c", &operation);

        if (operation == 'q') break;

        if (operation == 'p') {
            printHashTable(ht);
            continue;
        }

        printf("문자를 입력하시오: ");
        scanf_s("%s", &input, (unsigned)_countof(input));

        switch (operation) {
        case 'i':
            insert(ht, input);
            break;
        case 's':
            search(ht, input);
            break;
        case 'd':
            delete(ht, input);
            break;
        default:
            printf("Invalid operation\n");
        }
    }

    // 해시 테이블 해제
    freeHashTable(ht);

    return 0;
}