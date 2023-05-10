#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 1000

typedef struct Book {
    char name[101];
    int price;
} Book;

// 比較函數，用來排序書籍名稱
int cmp(const void *a, const void *b) {
    return strcmp(((Book*)a)->name, ((Book*)b)->name);
}

int main() {
    // 讀取小明的購書清單
    char list_filename[101];
    scanf("%s", list_filename);
    FILE *list_file = fopen(list_filename, "r");
    if (!list_file) {
        printf("Failed to open file %s.\n", list_filename);
        return 1;
    }

    // 讀取書店目錄
    char store_filename[101];
    scanf("%s", store_filename);
    FILE *store_file = fopen(store_filename, "r");
    if (!store_file) {
        printf("Failed to open file %s.\n", store_filename);
        return 1;
    }
    int n;
    fscanf(store_file, "%d", &n);
    Book books[MAX_BOOKS];
    for (int i = 0; i < n; i++) {
        fscanf(store_file, "%s%d", books[i].name, &books[i].price);
    }

    // 將list_file中的書籍名稱排序
    int m = 0;
    char book_names[MAX_BOOKS][101];
    // while (!feof(list_file)) {
    //     fscanf(list_file, "%s", book_names[m]);
    //     printf("#%02d: %s\n", m, book_names[m]);
    //     m++;
    // }
    while (1) {
        if (fscanf(list_file, "%s", book_names[m]) != 1) {
            break;
        }
        m++;
    }
    qsort(book_names, m, sizeof(book_names[0]), cmp);

    // 計算花費的總金額
    int total_price = 0;

    // 輸出購書清單
    char note_filename[101] = "noteXX.txt";
    int num_pos = 4; // 預設檔名中的數字部分在第4個字元位置
    char num_str[3];
    memset(num_str, 0, sizeof(num_str)); // 初始化 num_str 為空字串
    strncpy(num_str, list_filename + num_pos, 2); // 擷取 list_filename 變數中的數字部分
    note_filename[4] = num_str[0];
    note_filename[5] = num_str[1];
    FILE *note_file = fopen(note_filename, "w");
    if (!note_file) {
        printf("Failed to create file %s.\n", note_filename);
        return 1;
    }
    
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(book_names[i], books[j].name) == 0) {
                found = 1;
                total_price += books[j].price;
                fprintf(note_file, "%s %d\n", book_names[i], books[j].price);
                break;
            }
        }
        if (!found) {
            fprintf(note_file, "%s None\n", book_names[i]);
        }
    }
    fclose(note_file);
    fclose(list_file);
    fclose(store_file);

    printf("%d\n", total_price);
    return 0;
}
