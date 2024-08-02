
//�ؽ����̺�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 20  // �ǵ������� �۰� �����Ͽ� �浹 ���ɼ� ����
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char key[MAX_KEYWORD_LENGTH];
    bool use;
    bool deleted;
} Slot;

typedef struct {
    Slot* table; //���� �迭�� ����Ŵ
    int size;
} HashTable;

// �ؽ� �Լ� (���� �Լ�)
int hash(const char* key, int size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c

    return hash % size;
}

// �ؽ� ���̺� �ʱ�ȭ
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

// ���� ������� �̿��� ����
bool insert(HashTable* ht, char* key) { //�ؽ� ���̺�� ������ Ű�� ���ڷ� �޾� ���� ���θ� ��ȯ
    int hashkey = hash(key, ht->size); //�ؽð� ���
    int i = 0;

    while (i < ht->size) { //��� ���� ����
        int index = (hashkey + i) % ht->size; //�浹 �߻��� ���� ���� Ȯ��
        if (!ht->table[index].use || ht->table[index].deleted) { //������ ����ְų� ������ �������� Ȯ��
            copyString(ht->table[index].key, key); //���ڿ� ����
            ht->table[index].use = true; //���ǰ� ������ ǥ��
            ht->table[index].deleted = false; //�������� ������ ǥ��
            printf("'%s' -> �ε��� %d (�ؽð�: %d)\n", key, index, hashkey);
            return true; //������ ��ȯ
        }
        printf("\n�浹 �߻� '%s' -> �ε��� %d, ���� ���Կ� ����\n", key, index);
        i++; //�浹�� ���� �ε����� �Ѿ
    }
    printf("���� ���� '%s'\n", key);
    return false;  // ���̺��� ���� ��
}

// ���� ������� �̿��� �˻�
bool search(HashTable* ht, const char* key) {
    int hashkey = hash(key, ht->size);
    int i = 0;

    while (i < ht->size) {
        int index = (hashkey + i) % ht->size; //+i�� �Ͽ� �浹�� ���� �ε��� Ȯ��
        if (!ht->table[index].use) //����ִٸ�
            break; //�ݺ��� ����
        if (ht->table[index].use && !ht->table[index].deleted &&
            strcmp(ht->table[index].key, key) == 0) { //������̰� �������� �ʰ� Ű�� ���� ��ġ�Ѵٸ�
            printf("'%s' -> �ε��� %d (�ؽð�:  %d)\n", key, index, hashkey);
            return true;
        }
        i++;
    }
    printf("'%s'�� ���� �����Դϴ�\n", key);
    return false;
}

// ���� ������� �̿��� ����
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
            printf("'%s' ������, �ε��� -> %d (�ؽð�: %d)\n", key, index, hashkey);
            return true;
        }
        i++;
    }
    printf("'%s'�� ���� �����Դϴ�\n", key);
    return false;
}

// �ؽ� ���̺� ����
void freeHashTable(HashTable* ht) {
    free(ht->table);
    free(ht);
}

// �ؽ� ���̺� ���� ���
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

// C ��� Ű���� �迭
const char* keywords[] = {
    "char", "for", "if", "else", "while", "break", "char", "int", "double"
};
#define NUM_KEYWORDS (sizeof(keywords) / sizeof(keywords[0]))

int main() {
    HashTable* ht = initHashTable();

    // Ű���� ����
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        insert(ht, keywords[i]);
    }

    printHashTable(ht);

    char input[MAX_KEYWORD_LENGTH];
    char operation;

    while (1) {
        printf("\n (i:����, s:�˻�, d:����, p:���, q:������): ");
        scanf_s(" %c", &operation);

        if (operation == 'q') break;

        if (operation == 'p') {
            printHashTable(ht);
            continue;
        }

        printf("���ڸ� �Է��Ͻÿ�: ");
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

    // �ؽ� ���̺� ����
    freeHashTable(ht);

    return 0;
}