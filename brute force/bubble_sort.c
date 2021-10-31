#include <stdio.h>
#include <string.h>
#include <math.h> 
#include<stdlib.h>
/*Working Efficiency O(n^2)*/

int main()
{
	int* arr = (int*)malloc(sizeof(int));
	int i = 0;
	int j = 0;
	int c ;
	
	while ((scanf("%d",&c))!=EOF)
	{
		arr[i] = c;
		i++;
		arr = (int*)realloc(arr, (i + 1) * sizeof(int));
	}

	int n = i; 
	printf("%d\n", n);
	for (i = 0; i < n - 1; i++) //bubble sort
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);



}