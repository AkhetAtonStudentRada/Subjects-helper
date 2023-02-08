#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cstdlib>
#include <Windows.h>

typedef struct {
    char name[256];
    float value;
    float weight;
} item_t;

int* count;
int* best;
double best_value;

void knapsack(int i, float value, float weight, item_t* items,int n){
    int j, m;
    if (i == n) {
        if (value > best_value) {
            best_value = value;
            for (j = 0; j < n; j++) {
                best[j] = count[j];
            }
        }
        return;
    }
    m = weight / items[i].weight;   
    for (count[i] = m; count[i] >= 0; count[i]--) {
        knapsack(i + 1,value + count[i] * items[i].value, weight - count[i] * items[i].weight,items,n);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N=0, W=0;
    printf("������ ������� ���� ������: ");
    scanf("%i",&N);
    printf("������ ������� �������: ");
    scanf("%i",&W);
    count = (int*)malloc(N * sizeof(int));
    best = (int*)malloc(N * sizeof(int));
    item_t* items = (item_t*)malloc(N*sizeof(item_t));
    for (int i = 0; i < N; i++)
    {
        printf("������ ����� %i-�� ������: ",i+1);
        scanf("%s",items[i].name);
        printf("������ ���� ������: ");
        scanf("%f", &items[i].weight);
        printf("������ ������� ������: ");
        scanf("%f", &items[i].value);
    }
    best_value = 0;
    knapsack(0, 0.0, W, items,N);
    int i;
    printf("������ � �������:\n");
    for (i = 0; i < N; i++) {
        printf("%d %s\n", best[i], items[i].name);
    }
    printf("���������� ������ � �������: %.0f\n", best_value);
    free(count); free(best);
    return 0;
}