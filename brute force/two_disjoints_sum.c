#include <stdio.h>
#include <string.h>
#include <math.h> 
#include<stdlib.h>
/*This algorithm shows all subsets which to subset equals to each other*/
int pow1(int i1, int i2)
{
    int i = 0;
    int result = 1;
    for (i = 0; i < i2; i++)
    {
        result = result * 2;
    }
    return result;
}
int decToBinary(int n, int arr[], int size, int sum1)
{
    int i = 0;
    char* a = malloc(sizeof(char) * size);
    char* b = malloc(sizeof(char) * size);
    for (i = 0; i < size; i++)
    {
        a[i] = '0';
        b[i] = '0';
    }
    // Size of an integer is assumed to be size-1 bits

    for (i = size - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
        {
            a[i] = '1';
        }
        else
        {
            a[i] = '0';
        }
    }
    for (i = size - 1; i >= 0; i--)//reverse array
    {
        b[size - 1 - i] = a[i];
    }
    int sum = 0;
    int j = 0;
    for (j = 0; j < size; j++)//  we calculate sum of arr[] corresponding '1' in b array
    {
        if (b[j] == '1')
        {
            sum = sum + arr[j];
        }


    }
    if (sum == sum1) /*If the sum is equal to the sum of arr[]'s  half then subset1's sum and subset2's sum equals to each other */
    {
        int zero = 0;
        int one = 0;
        for (i = 0; i < size; i++)
        {
            if (b[i] == '0')
                zero++;
            else
                one++;
        }
        int* subset1 = malloc(sizeof(int) * size);
        int* subset2 = malloc(sizeof(int) * size);
        for (i = 0; i < size; i++)
        {
            subset1[i] = 0;
            subset2[i] = 0;
        }
        j = 0;
        int k = 0;
        for (i = 0; i < size; i++)
        {
            if (b[i] == '0')
            {
                subset1[j] = arr[i];
                j++;
            }
            else
            {
                subset2[k] = arr[i];
                k++;
            }
        }
        for (i = 0; i < zero; i++)
        {
            printf("%d ", subset1[i]);
        }
        printf("\n");
        for (i = 0; i < one; i++)
        {
            printf("%d ", subset2[i]);
        }
        printf("\n");
        return 1;

        ///return 1; if i write this code , it will returns just two disjoint subset
    }
    return 0;

}
int main()
{

    int i = 0, j = 0;
    int* arr = (int*)malloc(sizeof(int) );
    int n;
    while ((scanf("%d", &n)) != EOF)
    {
        arr[i] = n;
        i++;
        arr = (int*)realloc(arr, (i + 1) * sizeof(int));
    }
    int power = pow1(2, i);
    int size = i;
    int sum = 0;
    for (i = 0; i < size; i++)// sum of all array values
    {
        sum = sum + arr[i];
    }
    sum = sum / 2;
    for (i = 0; i < power; i++)// Minus and pluses problem algorithm but i use ' 000000000' like that 1 refers to '+' 0 refers nothing in my code .  
    {
        int b = decToBinary(i, arr, size, sum);
        if (b == 1)
            break;
    }
    return 0;
}
