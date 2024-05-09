#include <stdio.h>
#define MAX_SIZE 100

int count(int list[], int size, int element) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            count++;
        }
    }
    return count;
}

int index(int list[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (list[i] == element) {
            return i;
        }
    }
    return -1;
}

void reverse(int list[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = list[i];
        list[i] = list[size - i - 1];
        list[size - i - 1] = temp;
    }
}

void sort(int list[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void append(int list[], int *size, int element) {
    list[*size] = element;
    (*size)++;
}

void insert(int list[], int *size, int index, int element) {
    for (int i = *size; i > index; i--) {
        list[i] = list[i - 1];
    }
    list[index] = element;
    (*size)++;
}

int pop(int list[], int *size, int index) {
    int popped = list[index];
    for (int i = index; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }
    (*size)--;
    return popped;
}

void remove_list(int list[], int *size, int element) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if (list[i] == element) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < *size - 1; i++) {
            list[i] = list[i + 1];
        }
        (*size)--;
    }
}

int main() {
    int list[MAX_SIZE] = {5, 3, 7};
    int size = 3;

    printf("Count of 3: %d\n", count(list, size, 3));
    printf("Index of 7: %d\n", index(list, size, 7));

    insert(list, &size, 1, 2);
    printf("Lista com inserção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    int popped = pop(list, &size, 1);
    printf("Popped element: %d\n", popped);
    printf("Lista com pop: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    remove_list(list, &size, 2);
    printf("Lista com remoção: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    reverse(list, size);
    printf("Lista com reversão: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    sort(list, size);
    printf("Lista com ordenação: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}
