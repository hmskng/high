#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	int roll;
	float total_mark;
	char grade;
} student;
char find_grade(float mark){
	if(marks>=90) return 'A';
	else if(marks>=75) return 'B';
	else if(marks>=60) return 'C';
	else if(marks>=50) return 'D';
	else return 'F';
}
int main(int argc,int *argv[]){
	int rank,size,n,i;
	MPI_Data_type MPI_STUDENT;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int blocklength[4]={50,1,1,1};
	MPI_Aint displacements[4];
	MPI_aint address[4];
	student temp;
	MPI_Get_address(&temp.name,&address[0]);
	MPI_Get_address(&temp.roll,&address[1]);
	MPI_Get_address(&temp.total_marks,&address[2]);
	MPI_Get_address(&temp.grade,&address[3]);
	displacement[0]=0;
	for(i=0;i<4;i++){
		displacements[i]=address[i]-address[0]	;
	}
	MPI_Datattype types[4]={MPI_CHAR,MPI_INT,MPI_FLOAT,MPI_CHAR};
	MPI_Type_create_struct(4,blocklength,displacements,types,&MPI_STUDENT);
	MPI_Type_Commit(&MPI_STUDENT);
	student *students=NULL;
	student *local_students;
	int local_n;
	if(rank==0){
		FILE *fp=fopen("tem.txt","r");
		if(!fp){
			printf("FILE NOT FOUND");
			MPI_A
		}
	}
}
