#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>

#define MAX 10

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

 //   printf("Enter matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            A[i][j]=rand();

   // printf("Enter matrix B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            B[i][j]=rand();
     struct timespec st,end;
     int start=clock_gettime(CLOCK_MONOTONIC,&st);
     serialMultiply(C_serial);
     int ed=clock_gettime(CLOCK_MONOTONIC,&end);
    double serial_time = (double)( end.tv_nsec- st.tv_nsec);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
                printf("\t%d",C_serial[i][j]);
        }
        printf("\n");
    }
        printf("the serial time is %.1f",serial_time);
}
