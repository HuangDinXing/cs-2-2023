#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 10
#define PRINT_MEM() printf("Memory status: %010d\n", mem_status())

// 記錄 g_mem[10] 的使用情況
struct mem_info {
    int is_used[MEM_SIZE];
    int data[MEM_SIZE];
};

// 全域變數 g_mem[10] 和 mem_info
int g_mem[MEM_SIZE];
struct mem_info g_mem_info;

// 初始化 g_mem_info
void init_mem_info() {
    for (int i = 0; i < MEM_SIZE; i++) {
        g_mem_info.is_used[i] = 0;
        g_mem_info.data[i] = 0;
    }
}

// 計算 g_mem[10] 中已使用的記憶體空間大小
int mem_status() {
    int status = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (g_mem_info.is_used[i]) {
            status++;
        }
    }
    return status;
}

// 分配 n 個 size 大小的記憶體空間
char* my_calloc(int n, size_t size) {
    if (mem_status() + n > MEM_SIZE) {
        printf("Error: Memory is full.\n");
        return NULL;
    }

    char* ptr = NULL;
    for (int i = 0; i < MEM_SIZE && n > 0; i++) {
        if (!g_mem_info.is_used[i]) {
            g_mem_info.is_used[i] = 1;
            g_mem_info.data[i] = size;
            ptr = (char*)&g_mem[i];
            n--;
        }
    }
    PRINT_MEM();
    return ptr;
}

// 釋放指標 p 所指向的記憶體空間
void my_free(char* p) {
    if (p == NULL) {
        printf("Error: Invalid pointer.\n");
        return;
    }

    int index = (int)(p - (char*)g_mem) / sizeof(int);
    if (index < 0 || index >= MEM_SIZE || !g_mem_info.is_used[index]) {
        printf("Error: Invalid pointer.\n");
        return;
    }

    g_mem_info.is_used[index] = 0;
    PRINT_MEM();
}

int main() {
    // 初始化 g_mem_info
    init_mem_info();

    // 測試 my_calloc 和 my_free
    char* p1 = my_calloc(2, sizeof(int));
    int* p2 = (int*)my_calloc(1, sizeof(int));
    char* p3 = my_calloc(3, sizeof(int));
    my_free(p1);
    my_free((char*)p2);
    my_free(p3);
    char* p4 = my_calloc(5, sizeof(int));
    my_free(p4);

    return 0;
}
