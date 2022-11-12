// Faces positions:
//    A
// E B C 
//    F 
//    D

//Functions:
//solved(A,B,C,D,E,F);	Reset the cube at a solved state
//frot(A,B,C,D,E,F);	Face A rotation clockwise
//hspin(A,B,C,D,E,F);	Cube horizontal spin clockwise
//vspin(A,B,C,D,E,F);	Cube vertical spin clockwise (rotation of faces E & C)
//positions();			Faces positions sketch
//printcube(A,B,C,D,E,F);Prints actual state of the cube


#include <stdio.h>
#include <time.h> 
#define ANSI_RED "\x1b[31m" 
#define ANSI_GREEN "\x1b[32m" 
#define ANSI_YELLOW "\x1b[33m" 
#define ANSI_BLUE "\x1b[34m" 
#define ANSI_MAGENTA "\x1b[35m" 
#define ANSI_CYAN "\x1b[36m" 
#define ANSI_RESET "\x1b[0m" 

int solved(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=1;
			B[i][j]=2;
			C[i][j]=3;
			D[i][j]=4;
			E[i][j]=5;
			F[i][j]=6;
		}
	}
}


int printcube(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int i,j,n;
	n=3;
	printf("Actual state of the Rubik Cube:\n");
	printf("\n");
	//print A
	for (i=0;i<=n-1;i++){
		printf("      ");
		for (j=0;j<=n-1;j++){
			printf("%2d",A[i][j]);
		}
		printf("\n");
	}

	//print E,B,C
	for (i=0;i<=n-1;i++){
		//print E
		for (j=0;j<=n-1;j++){
			printf(ANSI_RED "%2d",E[i][j]);
		}
		
		//print B
		for (j=0;j<=n-1;j++){
			printf(ANSI_GREEN "%2d",B[i][j]);
		}
		
		//print C
		for (j=0;j<=n-1;j++){
			printf(ANSI_YELLOW "%2d",C[i][j]);
		}
		printf("\n");
	}

	//print F
	for (i=0;i<=n-1;i++){
		printf("      ");
		for (j=0;j<=n-1;j++){
			printf(ANSI_CYAN "%2d",F[i][j]);
		}
		printf("\n");
	}
	
	//print D
	for (i=0;i<=n-1;i++){
		printf("      ");
		for (j=0;j<=n-1;j++){
			printf(ANSI_MAGENTA "%2d",D[i][j]);
		}
		printf("\n");
	}
	printf(ANSI_RESET "\n");
	
}


//rotation of face A clockwise
int frot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[0][i]=B[0][i];
	}	
	
	for (i=0;i<=2;i++){
		B[0][i]=C[0][i];
	}

	for (i=0;i<=2;i++){
		C[0][i]=D[2][2-i];
	}

	for (i=0;i<=2;i++){
		D[2][i]=E[0][2-i];
	}
	
	for (i=0;i<=2;i++){
		E[0][i]=T[0][i];
	}
}


//cube - clockwise rotation in horizontal plan (rotation of faces A & F)
int hspin(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=T[2-j][i];
		}
	}
			
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}		
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=C[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=D[2-i][2-j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=E[2-i][2-j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=T[i][j];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=F[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=T[j][2-i];
		}
	}
}


//cube - clockwise(upwards) rotation in vertical plan (rotation of faces E & C)
int vspin(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=C[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=T[2-j][i];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=F[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=D[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=A[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=B[i][j];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=T[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=E[i][j];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=T[j][2-i];
		}
	}	
}


int positions(){
	printf("\n");
	printf("Cube faces positions:\n");
	printf("	  A\n");
	printf("	E B C\n");
	printf("	  F\n");
	printf("	  D\n");
	printf("\n");
}


int shuff(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int i;
	
	srand(time(NULL));

	for (i=0;i<=1000;i++){
		int nb=rand()%3;
		switch(nb){
			case 0:
				frot(A,B,C,D,E,F);
			case 1:
				hspin(A,B,C,D,E,F);
			case 2:
				vspin(A,B,C,D,E,F);
		} 
	}
}


int cond(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int i,j,flag,v1,v2,v3,v4,v5,v6;
	flag=1;
	v1=A[1][1];
	v2=B[1][1];
	v3=C[1][1];
	v4=D[1][1];
	v5=E[1][1];
	v6=F[1][1];
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			if (A[i][j]!=v1 || B[i][j]!=v2 || C[i][j]!=v3 || D[i][j]!=v4 || E[i][j]!=v5 || F[i][j]!=v6){
				flag=0;
			}
		}
	}
	return flag;
}


void main(){
	int A[100][100],B[100][100],C[100][100],D[100][100],E[100][100],F[100][100],step;
	time_t t;
    
	time(&t);
    printf("\n Start: %s", ctime(&t));
	
	//showing the cube faces sketch
	positions();
	
	//showing the cube solved state
	printf("Solved cube:\n");
	solved(A,B,C,D,E,F);
	printcube(A,B,C,D,E,F);
	
	//shuffeling the cube in a random way
	printf(ANSI_RED "***Random shuffeled cube***\n");
	shuff(A,B,C,D,E,F);
 	printcube(A,B,C,D,E,F);
	sleep(3);
	
	//solving the cube
	step=0;
	while (cond(A,B,C,D,E,F)==0){
		step++;
		printf(ANSI_RED"Step: %d\n",step);
		shuff(A,B,C,D,E,F);
		printcube(A,B,C,D,E,F);
	}
	printf("\n End: %s", ctime(&t));
}

