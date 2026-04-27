#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#define MAX 50
int n;
int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX],D[MAX][MAX],E[MAX][MAX],F[MAX][MAX];
long timediff(struct timespec st,struct timespec ed){
	return (st.tv_sec-ed.tv_sec);
}
void add(){
   struct timespec s,e;
   clock_gettime(CLOCK_MONOTONIC, &s);
   for(int i=0;i<n;i++){
   	for(j=0;j<n;j++){
		d[i][j]=A[I][]	
	}}

}



