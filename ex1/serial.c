#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#define MAX 1000

int A[MAX][MAX], B[MAX][MAX];
int m, n, p;
void serialMultiply(int C[MAX][MAX]) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
                C[i][j]=0;
            for (k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    int i, j;
    int C_serial[MAX][MAX];

    printf("Enter m n p: ");
    scanf("%d %d %d", &m, &n, &p);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            A[i][j]=rand()%10;

    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            B[i][j]=rand()%10;
     struct timespec st,end;
     int start=clock_gettime(CLOCK_MONOTONIC,&st);
     serialMultiply(C_serial);
     int ed=clock_gettime(CLOCK_MONOTONIC,&end);
     double serial_time = (double)(end.tv_sec - st.tv_sec)+((double)(end.tv_nsec-st.tv_nsec))/1e9;
     printf("The time taken for serial multiplication %f",serial_time);
}

