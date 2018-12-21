#include<stdio.h>
#include<math.h>
int chessb[20],n,i,j,count=0,flag=0;
void nqueen(int row);
int pos(int row,int col);
void print();
void main()
{
	printf("\nEnter no. of Queens:");
	scanf("%d",&n);
	if(n<4)
	{
		printf("n should be greater then or equal to 4");
		flag=1;
	}
	if(flag==0)
	{
		nqueen(1);
		printf("\nTotal no. of solution=%d\n",count);
	}
}
void nqueen(int row)
{
	int col;
	for(col=1;col<=n;col++)
	{
		 if(pos(row,col))
		 {
		 	chessb[row]=col;
		 	if(row==n)
		 		print();
		 	else
		 		nqueen(row+1);
		 }
	}
}
int pos(int row,int col)
{
	for(i=1;i<=row-1;i++)
	{
		if(chessb[i]==col)
			return 0;
		else
		{
			if(abs(chessb[i]-col)==abs(i-row))
				return 0;
		}
	}
	return 1;
}
void print()
{
	count++;
	printf("\nSolution=%d\n",count);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(chessb[i]==j)
				printf("Q\t");
			else
				printf("-\t");
		}
		printf("\n");
	}
}
/*Output:
students@CELAB4-17:~/Desktop$ gcc daa7.c
students@CELAB4-17:~/Desktop$ ./a.out

Enter no. of Queens:4

Solution=1
-	Q	-	-	
-	-	-	Q	
Q	-	-	-	
-	-	Q	-
		
Solution=2
-	-	Q	-	
Q	-	-	-	
-	-	-	Q	
-	Q	-	-
		
Total no. of solution=2
students@CELAB4-17:~/Desktop$ ./a.out

Enter no. of Queens:6

Solution=1
-	Q	-	-	-	-	
-	-	-	Q	-	-	
-	-	-	-	-	Q	
Q	-	-	-	-	-	
-	-	Q	-	-	-	
-	-	-	-	Q	-
		
Solution=2
-	-	Q	-	-	-	
-	-	-	-	-	Q	
-	Q	-	-	-	-	
-	-	-	-	Q	-	
Q	-	-	-	-	-	
-	-	-	Q	-	-
		
Solution=3
-	-	-	Q	-	-	
Q	-	-	-	-	-	
-	-	-	-	Q	-	
-	Q	-	-	-	-	
-	-	-	-	-	Q	
-	-	Q	-	-	-
		
Solution=4
-	-	-	-	Q	-	
-	-	Q	-	-	-	
Q	-	-	-	-	-	
-	-	-	-	-	Q	
-	-	-	Q	-	-	
-	Q	-	-	-	-	
	
Total no. of solution=4

students@CELAB4-17:~/Desktop$ ./a.out

Enter no. of Queens:8
Total no. of solution=92
students@CELAB4-17:~/Desktop$ 

*/		
