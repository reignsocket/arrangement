
#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1024
int an[MAX_NUM + 10];
//Comparison function for sorting
int MyCompare( const void * e1, const void * e2)
{
	return * ((int *) e1) - * ((int *) e2);
}
main()
{
	int M;
	int n, k, i, j;
	scanf("%d", & M);
	for (int m = 0; m < M; m ++ ) {
		scanf("%d%d", &n, &k);
		//Arranged in an[1] .... an[n]
		for( i = 1; i <= n; i ++ )
			scanf("%d", &an[i]);
		an[0] = 100000;//Make sure an[0] is larger than all the numbers in the array
		for( i = 0; i < k ;i ++ ) { //Find the next alignment every cycle
			for( j = n ; j >= 1 && an[j-1] > an[j] ; j -- ) ;
			if( j >= 1 ) {
				int nMinLarger = an[j];
				int nMinIdx = j;
				//Let's find out the element from an[j] and the smallest ratio an[j-1] after it, and remember its subscript
				for( int kk = j; kk <= n; kk ++)
					if( nMinLarger > an[kk] && an[kk] > an[j-1]) {
						nMinLarger = an[kk];
						nMinIdx = kk;
					}
				//Exchange location
				an[nMinIdx] = an[j-1];
				an[j-1] = nMinLarger;
				qsort( an + j, n - j + 1 , sizeof(int), MyCompare);//sort

			}
			else{//The arrangement in /an is already in descending order, then the next permutation is 1 2 3 . . . . n
				for( j = 1; j <= n; j ++ )
					an[j] = j;
			}
		}
		for( j = 1; j <= n; j ++ )
			printf("%d ", an[j]);
		printf("\n");
	}
}
