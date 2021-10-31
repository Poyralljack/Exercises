#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Working efficiency is O(n^2)*/
struct Task
{
	int id;
	int deadline;
	int profit;

};
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main()
{
	int t;
	scanf("%d", &t);
	struct Task* task = (struct Task*)malloc(t * sizeof(struct Task));
	int i,j;
	for (i = 0; i < t; i++) // Take values from user
	{
		scanf("%d %d %d", &(task+i)->id, &(task+i)->deadline, &(task+i)->profit);
	}
	for (i = 0; i < t; i++) // Struct task's profit values will be sorted with decreasing by bubble sort
	{
		for (j = i+1; j < t; j++)
		{
			if ((task + i)->profit < (task + j)->profit)
			{
				swap(&(task+i)->deadline,&(task+j)->deadline);
				swap(&(task + i)->id, &(task + j)->id);
				swap(&(task + i)->profit, &(task + j)->profit);

			}
		}
	}
	int max = task->deadline;
	for (i = 1; i < t; i++)// find max value of deadline
	{
		if ((task + i)->deadline > max)
		{
			max = (task + i)->deadline;
		}

	}
	int* chart = (int*)malloc(max * sizeof(int));
	for (i = 0; i < max; i++)//Create empty chart which shows the id's
		chart[i] = -1;
	for (i = 0; i < t; i++)
	{
		if (chart[((task + i)->deadline) - 1] == -1)/*Take a index from task's deadline and put it chart which shows id's of algorithm*/
		{
			chart[(task + i)->deadline - 1] = (task + i)->id;
		}
		else/*if array's index is not empty then decrease the index*/
		{
			int k = 0;
			for (k = (task + i)->deadline - 1; k >= 0; k--)
			{
				if (chart[k] == -1)
				{
					chart[k] = (task + i)->id;
					break;
				}
			}
		}
	}
	for (i = 0; i < t; i++)
	{
		if (chart[i]!=-1 && chart[i]!=0)
		printf("%d ", chart[i]);
	}
	
	return 0;
}