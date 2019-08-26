/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>

#define N_ROW 100
#define M_COL 20


int Answer,circuit[N_ROW][M_COL],maxoutput,sumrow[N_ROW],refrow[M_COL];


/*function to calculate the output on the basis of a given refrowindex*/
int calculateamp(int refrowindex,int m, int n)
{
	int index, index1, count = 0, sum;
	/*loop to find out which columns we need to toggle*/
	for(index = 0 ; index < m; index++)
	{
		if(circuit[refrowindex][index] == 0)
			refrow[index] = 1;
		else 
			refrow[index] = 0;
	}
	/*calculate the sum of matrix. We have the refrow varible so on the basis of refrow value we will toggle the column value.*/
	for(index = 0 ; index < n; index++)
	{
		sum = 0;
		for(index1 = 0 ; index1 < m ; index1++)
		{
			/*Logic to change the column value*/
			if(refrow[index1] == 1)
			{
				if(circuit[index][index1] == 0)
					sum++;
			}
			else 
				sum += circuit[index][index1];
		}
		/*If final sum is equal to the number of columns then only the row return positive.*/
		if(sum == m)
			count++;
	}
	return count;
}

/*function to find out all the combination for which we have to calculate the amplification value.*/
int findmax(int n, int m, int k)
{
	int index, index1,val;
	maxoutput = 0;
	/*loop for appling laser.*/
	for(index = k; index>=0; index= index-2)
	{
		/*loop to go through all the rows*/
		for(index1 = 0 ; index1 < n; index1++)
		{
			/* logic to check whether apply laser or not. If number of laser and number of 1's sum is equal to the 
			column number then we can apply laser on the basis of that row. We will store the 0's column index in array
			and then apply laser on those columns.*/
			if(sumrow[index1]+index == m)
			{
				val = calculateamp(index1,m,n);
				if(val > maxoutput)
					maxoutput = val;
			}
		}
	}
	return maxoutput;
}

int main(void)
{
	int T, test_case,n,m,k,index,index1,sum;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d %d %d",&n,&m,&k);
		for(index = 0 ; index < n; index++)
		{
			sum = 0;
			for(index1 = 0; index1 < m;index1++)
			{
				scanf("%d",&circuit[index][index1]);
				sum +=  circuit[index][index1];
			}
			sumrow[index] = sum;
		}
		Answer = findmax(n,m,k);

		// Print the answer to standard output(screen).
		printf("Case #%d %d\n", test_case+1,Answer);
		
	}

	return 0;//Your program should return 0 on normal termination.
}
