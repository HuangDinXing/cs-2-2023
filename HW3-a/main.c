#include <stdio.h>
#include <time.h>

void hanoi(int n, char from, char to, char aux, FILE *fp) {
    if (n == 1) {
        time_t now = time(NULL);
        fprintf(fp, "%d (%s) : 1P from %c to %c\n", (int)now, ctime(&now), from, to);
        return;
    }
    hanoi(n-1, from, aux, to, fp);
    time_t now = time(NULL);
    fprintf(fp, "%d (%s) : %dP from %c to %c\n", (int)now, ctime(&now), n, from, to);
    hanoi(n-1, aux, to, from, fp);
}

int main() {
    int n = 20;  // 盤子的數量
    char from = 'A', to = 'C', aux = 'B';  // 三根柱子的名字
    FILE *fp = fopen("hanoi.txt", "w");  // 打開檔案
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    time_t start_time = time(NULL);  // 開始時間
    fprintf(fp, "Start time: %s", ctime(&start_time));
    hanoi(n, from, to, aux, fp);  // 遞迴求解河內塔問題
    time_t end_time = time(NULL);  // 結束時間
    fprintf(fp, "End time: %s", ctime(&end_time));
    fclose(fp);  // 關閉檔案
    return 0;
}
