#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>

#define MAX 1000

int A[MAX][MAX], B[MAX][MAX];
int m, n, p,max;
void parallelMultiply(int *C,double *F) {
    int i, j, k;

    for (i = 0; i < m; i++) {
        if (fork() == 0) {
                struct timespec st,end;
                int start=clock_gettime(CLOCK_MONOTONIC,&st);
            for (j = 0; j < p; j++) {
                C[i * p + j] = 0;
                for (k = 0; k < n; k++)
                    C[i * p + j] += A[i][k] * B[k][j];
            }
                 int ed=clock_gettime(CLOCK_MONOTONIC,&end);
                double parallel_time = (double)(end.tv_sec - st.tv_sec)+((double)(end.tv_nsec-st.tv_nsec))/1e9;
                F[i]=parallel_time;
            exit(0);
        }
    }
      for (i = 0; i < m; i++)
              wait(NULL);
}
double find_max(double *F)
{
        double temp=0.0;
        for(int i=0;i<m;i++)
        {
                if(temp<F[i])
                {
                        temp=F[i];
                }
        }
        return temp;
}

int main() {
    int i, j;

    printf("Enter m n p: ");
    scanf("%d %d %d", &m, &n, &p);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            A[i][j]=rand()%10;
    for (i = 0; i < n; i++)
        for (j = 0; j < p; j++)
            B[i][j]=rand()%10;
    int shmid = shmget(IPC_PRIVATE, sizeof(int) * m * p, IPC_CREAT | 0666);
    int sid = shmget(123, sizeof(double)*m+1, IPC_CREAT | 0666);
    double *C_time=(double *)shmat(sid,NULL,0);
    int *C_parallel = (int *)shmat(shmid, NULL, 0);
    parallelMultiply(C_parallel,C_time);
    double temp=find_max(C_time);
    printf("\nResult Matrix:\n");
    printf("\nParallel Time : %f seconds\n",temp);
    shmdt(C_time);
    shmdt(C_parallel);
    shmctl(shmid, IPC_RMID, NULL);
    shmctl(sid,IPC_RMID,NULL);

    return 0;
}

