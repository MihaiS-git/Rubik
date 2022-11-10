// Faces positions:
//   A
// E B C 
//   F 
//   D

//Functions:
//solved(A,B,C,D,E,F);	Reset the cube at a solved state
//arot(A,B,C,D,E,F);	Face A rotation clockwise
//arotcc(A,B,C,D,E,F);	Face A rotation counterclockwise
//brot(A,B,C,D,E,F);	Face B rotation clockwise
//brotcc(A,B,C,D,E,F);	Face B rotation counterclockwise
//crot(A,B,C,D,E,F);	Face C rotation clockwise
//crotcc(A,B,C,D,E,F);	Face C rotation counterclockwise
//drot(A,B,C,D,E,F);	Face D rotation clockwise
//drotcc(A,B,C,D,E,F);	Face D rotation counterclockwise
//erot(A,B,C,D,E,F);	Face E rotation clockwise
//erotcc(A,B,C,D,E,F);	Face E rotation counterclockwise
//frot(A,B,C,D,E,F);	Face F rotation clockwise
//frotcc(A,B,C,D,E,F);	Face F rotation counterclockwise
//hspin(A,B,C,D,E,F);	Cube horizontal spin clockwise
//hspincc(A,B,C,D,E,F);	Cube horizontal spin counterclockwise
//vecspin(A,B,C,D,E,F);	Cube vertical spin clockwise (rotation of faces E & C)
//vecspincc(A,B,C,D,E,F);	Cube vertical spin counterclockwise (rotation of faces E & C)
//vbdspin(A,B,C,D,E,F);	Cube vertical spin clockwise (rotation of faces B & D)
//vbdspincc(A,B,C,D,E,F);Cube vertical spin counterclockwise (rotation of faces B & D)
//hmrot(A,B,C,D,E,F);	Cube horizontal middle layer rotation clockwise
//hmrotcc(A,B,C,D,E,F);	Cube horizontal middle layer rotation counterclockwise
//vmbrot(A,B,C,D,E,F);	Cube vertical middle layer parallel to B rotation clockwise
//vmbrotcc(A,B,C,D,E,F);Cube vertical middle layer parallel to B rotation counterclockwise
//vmcrot(A,B,C,D,E,F);	Cube vertical middle layer parallel to C rotation clockwise
//vmcrotcc(A,B,C,D,E,F);Cube vertical middle layer parallel to C rotation counterclockwise
//positions();			Faces positions sketch
//printcube(A,B,C,D,E,F);Prints actual state of the cube


#include <stdio.h>


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
			printf("%2d",E[i][j]);
		}
		//print B
		for (j=0;j<=n-1;j++){
			printf("%2d",B[i][j]);
		}
		//print C
		for (j=0;j<=n-1;j++){
			printf("%2d",C[i][j]);
		}
		printf("\n");
	}

	//print F
	for (i=0;i<=n-1;i++){
		printf("      ");
		for (j=0;j<=n-1;j++){
			printf("%2d",F[i][j]);
		}
		printf("\n");
	}
	
	//print D
	for (i=0;i<=n-1;i++){
		printf("      ");
		for (j=0;j<=n-1;j++){
			printf("%2d",D[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//rotation of face A clockwise
int arot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
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


//rotation of face A counter-clockwise
int arotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=T[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[0][i]=B[0][i];
	}	
	
	for (i=0;i<=2;i++){
		B[0][i]=E[0][i];
	}	
	
	for (i=0;i<=2;i++){
		E[0][i]=D[2][2-i];
	}	
	
	for (i=0;i<=2;i++){
		D[2][i]=C[0][2-i];
	}
	
	for (i=0;i<=2;i++){
		C[0][i]=T[0][i];
	}
}
	

//rotation of face B clockwise
int brot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[2][i]=A[2][i];
	}		
	
	for (i=0;i<=2;i++){
		A[2][i]=E[2-i][2];
	}	

	for (i=0;i<=2;i++){
		E[i][2]=F[0][i];
	}
	
	for (i=0;i<=2;i++){
		F[0][i]=C[2-i][0];
	}
	
	for (i=0;i<=2;i++){
		C[i][0]=T[2][i];
	}
}

//rotation of face B counter-clockwise
int brotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=T[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[2][i]=A[2][i];
	}		
	
	for (i=0;i<=2;i++){
		A[2][i]=C[i][0];
	}

	for (i=0;i<=2;i++){
		C[i][0]=F[0][2-i];
	}
	
	for (i=0;i<=2;i++){
		F[0][i]=E[i][2];
	}
	
	for (i=0;i<=2;i++){
		E[i][2]=T[2][i];
	}
}
	
	
//rotation of face C clockwise
int crot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
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
		T[i][2]=A[i][2];
	}		
	
	for (i=0;i<=2;i++){
		A[i][2]=B[i][2];
	}	

	for (i=0;i<=2;i++){
		B[i][2]=F[i][2];
	}
	
	for (i=0;i<=2;i++){
		F[i][2]=D[2-i][2];
	}
	
	for (i=0;i<=2;i++){
		D[i][2]=T[i][2];
	}
}


//rotation of face C counter-clockwise
int crotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=C[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=T[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[i][2]=A[i][2];
	}		
	
	for (i=0;i<=2;i++){
		A[i][2]=D[i][2];
	}	

	for (i=0;i<=2;i++){
		D[i][2]=F[i][2];
	}
	
	for (i=0;i<=2;i++){
		F[i][2]=B[i][2];
	}
	
	for (i=0;i<=2;i++){
		B[i][2]=T[i][2];
	}
}


//rotation of face D clockwise
int drot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=D[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[0][i]=A[0][i];
	}		
	
	for (i=0;i<=2;i++){
		A[0][i]=C[i][2];
	}	

	for (i=0;i<=2;i++){
		C[i][2]=F[2][2-i];
	}
	
	for (i=0;i<=2;i++){
		F[2][i]=E[i][0];
	}
	
	for (i=0;i<=2;i++){
		E[i][0]=T[0][2-i];
	}
}


//rotation of face D counter-clockwise
int drotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=D[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=T[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[0][i]=A[0][i];
	}		
	
	for (i=0;i<=2;i++){
		A[0][i]=E[2-i][0];
	}	

	for (i=0;i<=2;i++){
		E[i][0]=F[2][i];
	}
	
	for (i=0;i<=2;i++){
		F[2][i]=C[2-i][2];
	}
	
	for (i=0;i<=2;i++){
		C[i][2]=T[0][i];
	}
}


//rotation of face E clockwise
int erot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=E[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[i][0]=A[i][0];
	}		
	
	for (i=0;i<=2;i++){
		A[i][0]=D[i][0];
	}	

	for (i=0;i<=2;i++){
		D[i][0]=F[i][0];
	}
	
	for (i=0;i<=2;i++){
		F[i][0]=B[i][0];
	}
	
	for (i=0;i<=2;i++){
		B[i][0]=T[i][0];
	}
}


//rotation of face E counter-clockwise
int erotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=E[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=T[j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[i][0]=A[i][0];
	}		
	
	for (i=0;i<=2;i++){
		A[i][0]=B[i][0];
	}	

	for (i=0;i<=2;i++){
		B[i][0]=F[i][0];
	}
	
	for (i=0;i<=2;i++){
		F[i][0]=D[i][0];
	}
	
	for (i=0;i<=2;i++){
		D[i][0]=T[i][0];
	}
}


//rotation of face F clockwise
int frot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=F[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		T[2][i]=B[2][i];
	}		
	
	for (i=0;i<=2;i++){
		B[2][i]=E[2][i];
	}	

	for (i=0;i<=2;i++){
		E[2][i]=D[0][2-i];
	}
	
	for (i=0;i<=2;i++){
		D[0][i]=C[2][2-i];
	}
	
	for (i=0;i<=2;i++){
		C[2][i]=T[2][i];
	}
}


//rotation of face F counter-clockwise
int frotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
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
	
	for (i=0;i<=2;i++){
		T[2][i]=B[2][i];
	}		
	
	for (i=0;i<=2;i++){
		B[2][i]=C[2][i];
	}	

	for (i=0;i<=2;i++){
		C[2][i]=D[0][2-i];
	}
	
	for (i=0;i<=2;i++){
		D[0][i]=E[2][2-i];
	}
	
	for (i=0;i<=2;i++){
		E[2][i]=T[2][i];
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


//cube - counter-clockwise rotation in horizontal plan (rotation of faces A & F)
int hspincc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=T[j][2-i];
		}
	}
			
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}		
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=E[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=D[2-i][2-j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=C[2-i][2-j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=T[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=F[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=T[2-j][i];
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


//cube - counter-clockwise(downwards) rotation in vertical plan (rotation of faces E & C)
int vspincc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=C[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=T[j][2-i];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=D[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=F[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=B[i][j];
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
			E[i][j]=T[2-j][i];
		}
	}	
}


//cube - clockwise rotation in vertical plan (rotation of faces B & D)
int vbdspin(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=T[2-j][i];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=E[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=F[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=C[2-j][i];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=T[2-j][i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=D[i][j];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=T[j][2-i];
		}
	}	
}


//cube - counterclockwise rotation in vertical plan (rotation of faces B & D)
int vbdspincc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=B[i][j];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			B[i][j]=T[j][2-i];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=A[i][j];
		}
	}

	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			A[i][j]=C[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			C[i][j]=F[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			F[i][j]=E[j][2-i];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			E[i][j]=T[j][2-i];
		}
	}
	
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			T[i][j]=D[i][j];
		}
	}
		
	for (i=0;i<=2;i++){
		for (j=0;j<=2;j++){
			D[i][j]=T[2-j][i];
		}
	}	
}
//cube - middle plan clockwise rotation in horizontal plan
int hmrot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[1][i]=B[1][i];
	}
	
	for (i=0;i<=2;i++){
		B[1][i]=C[1][i];
	}
	
	for (i=0;i<=2;i++){
		C[1][i]=D[1][2-i];
	}
	
	for (i=0;i<=2;i++){
		D[1][i]=E[1][2-i];
	}
	
	for (i=0;i<=2;i++){
		E[1][i]=T[1][i];
	}
}


//cube - middle plan counterclockwise rotation in horizontal plan
int hmrotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[1][i]=B[1][i];
	}
	
	for (i=0;i<=2;i++){
		B[1][i]=E[1][i];
	}
	
	for (i=0;i<=2;i++){
		E[1][i]=D[1][2-i];
	}
	
	for (i=0;i<=2;i++){
		D[1][i]=C[1][2-i];
	}
	
	for (i=0;i<=2;i++){
		C[1][i]=T[1][i];
	}
}


//cube - middle plan clockwise rotation in vertical plan(parallel to B)
int vmbrot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[1][i]=A[1][i];
	}
	
	for (i=0;i<=2;i++){
		A[1][i]=E[2-i][1];
	}
	
	for (i=0;i<=2;i++){
		E[i][1]=F[1][i];
	}
	
	for (i=0;i<=2;i++){
		F[1][i]=C[2-i][1];
	}
	
	for (i=0;i<=2;i++){
		C[i][1]=T[1][i];
	}
}


//cube - middle plan counterclockwise rotation in vertical plan(parallel to B)
int vmbrotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[1][i]=A[1][i];
	}
	
	for (i=0;i<=2;i++){
		A[1][i]=C[i][1];
	}
	
	for (i=0;i<=2;i++){
		C[i][1]=F[1][2-i];
	}
	
	for (i=0;i<=2;i++){
		F[1][i]=E[i][1];
	}
	
	for (i=0;i<=2;i++){
		E[i][1]=T[1][2-i];
	}
}


//cube - middle plan clockwise rotation in vertical plan(parallel to C)
int vmcrot(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[i][1]=A[i][1];
	}
	
	for (i=0;i<=2;i++){
		A[i][1]=B[i][1];
	}
	
	for (i=0;i<=2;i++){
		B[i][1]=F[i][1];
	}
	
	for (i=0;i<=2;i++){
		F[i][1]=D[i][1];
	}
	
	for (i=0;i<=2;i++){
		D[i][1]=T[i][1];
	}
}


//cube - middle plan counterclockwise rotation in vertical plan(parallel to C)
int vmcrotcc(int A[100][100],int B[100][100],int C[100][100],int D[100][100],int E[100][100],int F[100][100]){
	int T[100][100],i,j;
	
	for (i=0;i<=2;i++){
		T[i][1]=A[i][1];
	}
	
	for (i=0;i<=2;i++){
		A[i][1]=D[i][1];
	}
	
	for (i=0;i<=2;i++){
		D[i][1]=F[i][1];
	}
	
	for (i=0;i<=2;i++){
		F[i][1]=B[i][1];
	}
	
	for (i=0;i<=2;i++){
		B[i][1]=T[i][1];
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


void main(){
	int A[100][100],B[100][100],C[100][100],D[100][100],E[100][100],F[100][100];
	int i,j,k;
	
	positions();
	printf("Solved cube:\n");
	solved(A,B,C,D,E,F);
	printcube(A,B,C,D,E,F);
		
	//Functions:
	//solved(A,B,C,D,E,F);	Reset the cube at a solved state
	//arot(A,B,C,D,E,F);	Face A rotation clockwise
	//arotcc(A,B,C,D,E,F);	Face A rotation counterclockwise
	//brot(A,B,C,D,E,F);	Face B rotation clockwise
	//brotcc(A,B,C,D,E,F);	Face B rotation counterclockwise
	//crot(A,B,C,D,E,F);	Face C rotation clockwise
	//crotcc(A,B,C,D,E,F);	Face C rotation counterclockwise
	//drot(A,B,C,D,E,F);	Face D rotation clockwise
	//drotcc(A,B,C,D,E,F);	Face D rotation counterclockwise
	//erot(A,B,C,D,E,F);	Face E rotation clockwise
	//erotcc(A,B,C,D,E,F);	Face E rotation counterclockwise
	//frot(A,B,C,D,E,F);	Face F rotation clockwise
	//frotcc(A,B,C,D,E,F);	Face F rotation counterclockwise
	//hspin(A,B,C,D,E,F);	Cube horizontal spin clockwise
	//hspincc(A,B,C,D,E,F);	Cube horizontal spin counterclockwise
	//vecspin(A,B,C,D,E,F);	Cube vertical spin clockwise (rotation of faces E & C)
	//vecspincc(A,B,C,D,E,F);	Cube vertical spin counterclockwise (rotation of faces E & C)
	//vbdspin(A,B,C,D,E,F);	Cube vertical spin clockwise (rotation of faces B & D)
	//vbdspincc(A,B,C,D,E,F);Cube vertical spin counterclockwise (rotation of faces B & D)
	//hmrot(A,B,C,D,E,F);	Cube horizontal middle layer rotation clockwise
	//hmrotcc(A,B,C,D,E,F);	Cube horizontal middle layer rotation counterclockwise
	//vmbrot(A,B,C,D,E,F);	Cube vertical middle layer parallel to B rotation clockwise
	//vmbrotcc(A,B,C,D,E,F);Cube vertical middle layer parallel to B rotation counterclockwise
	//vmcrot(A,B,C,D,E,F);	Cube vertical middle layer parallel to C rotation clockwise
	//vmcrotcc(A,B,C,D,E,F);Cube vertical middle layer parallel to C rotation counterclockwise
	//positions();			Faces positions sketch
	//printcube(A,B,C,D,E,F);Prints actual state of the cube
	
}
