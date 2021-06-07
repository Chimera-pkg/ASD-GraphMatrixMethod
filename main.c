#include <stdio.h>
#include <stdlib.h>
#define M 1000
#define MAX 100

typedef struct stack tumpuk;
struct stack{
    int data[MAX];
    int count;
};
int bebanOld[MAX][MAX];
int beban[MAX][MAX] = {{M, 1, 3, M, M}, {M, M, 1, M, 5}, {3, M, M, 2, M}, {M, M, M, M, 1}, {M, M, M, M, M}};
int jalur[MAX][MAX] = {{0, 1, 1, 0, 0},{0, 0, 1, 0, 1}, {1, 0, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};
int rute[MAX][MAX] = {{M, 1, 1, M, M},{M, M, 1, M, 1}, {1, M, M, 1, M}, {M, M, M, M, 1}, {M, M, M, M, M}};
tumpuk stRute;

int main()
{
    int i, j;
    int awal, akhir;

    inisial(&stRute);

    tampil();

    bebanWarshall(beban);
    jalurWarshall(jalur);
    ruteWarshall();

    printf("\nAFTER\n");

    tampil();

    find();
    return 0;
}


void inisial(tumpuk *s)
{
    s->count = 0;
}

void push(int e, tumpuk *s)
{
    s->data[s->count] = e;
    s->count++;
}

int pop(tumpuk *s)
{
    int temp;

    --s->count;
    temp = s->data[s->count];

    return temp;
}

void cetakArray(int arr[MAX][MAX])
{
    int i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("%4d\t", arr[i][j]);
        }
        puts("");
    }
}

void bebanWarshall(int arr[MAX][MAX])
{
    int i, j, k;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 5; k++){
                if((arr[j][i] + arr[i][k]) < arr[j][k])
                    arr[j][k] = (arr[j][i] + arr[i][k]);
            }
        }
    }
}

void jalurWarshall(int arr[MAX][MAX])
{
    int i, j, k;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            for(k = 0; k < 5; k++){
                arr[j][k] = arr[j][k] || (arr[j][i] && arr[i][k]);
            }
        }
    }
}

void ruteWarshall()
{
    int i, j, k;

    for(k = 0; k < 5; k++){
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(bebanOld[i][k] + bebanOld[k][j] < bebanOld[i][j]){
                }
            }
        }
    }
}

void cariRute(int awal, int akhir)
{
    int i;

    for(i = akhir; i > 0; i--){
        if(rute[awal - 1][i - 1] != 0){
            push(rute[awal-1][i-1], &stRute);
        }
        else
            return;
    }
}

void tampil()
{
    printf("Matriks Beban(Q)\n");
    cetakArray(beban);

    printf("\nMatriks Jalur(P)\n");
    cetakArray(jalur);

    printf("\nMatriks Rute(R)\n");
    cetakArray(rute);


}

void find()
{
    int awal,akhir;

    printf("Tujuan asal : ");
    scanf("%d", &awal);
    printf("Tujuan akhir : ");
    scanf("%d", &akhir);

    printf("\nst Count = %d\n", stRute.count);

    printf("\nRute Terpendek : %d ", awal);

    while(stRute.count != 0){
        printf("%d ", pop(&stRute));
    }

    printf("%d", akhir);
}
