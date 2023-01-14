#include<stdio.h>
#define ARR_SIZE 1000

void sort(int* array, int* size);
void minVal(int* array, int* size);
void oddEvenNr(int* array, int* size);
void mergeArrays(int* array, int* size);
void negativeNumbers(int* array, int* size);

int main(void)
{
	int array[ARR_SIZE];
	int size;
	printf("Please select the size of array:\n");
	scanf_s("%d", &size);
	printf("Please add values to \n");
	for (int i = 0; i < size; i++)
	{
		printf("array[%d] = ", i);
		scanf_s("%d", &array[i]);
	}
	printf("1. Sort\n2. Min/Max value\n3. Odd/Even number\n4. Merge arrays \n5. Negative numbers\n");
	int short unsigned option;
	scanf_s("%hu", &option);
	while (option > 5)
	{
		printf("invalid option. please try another number. \n");
		scanf_s("%hu", &option);
	}
	switch (option)
	{
		case 1:
			sort(array, &size);
			break;
		case 2:
			minVal(array, &size);
			break;
		case 3:
			oddEvenNr(array, &size);
			break;
		case 4:
			mergeArrays(array, &size);
			break;
		case 5:
			negativeNumbers(array, &size);
			break;
		case 0:
			printf("Success\n");
			return 0;
			break;
	}
	
	
	
	
	
}


void sort(int* array, int* size)
{
	for (int i = 0; i < *size; i++)
	{
		for (int j = 0; j < *size - 1; j++)
		{
			if (*(array + j) > *(array + j + 1))
			{
				int temp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = temp;
			}
		}
	}
	for (int i = 0; i < *size; i++)
	{
		printf("%d \t", *(array + i));
	}
	printf("\n");
}
void minVal(int *array, int* size)
{
	int minVal, i;
	minVal = *(array + 1);
	int maxVal = *(array + *size-1);
	for (i = 0; i < *size; i++)
	{
		
		if (*(array + i) < minVal)
		{
			minVal = *(array + i);
		}
		else if (*(array + i) > maxVal)
		{
			maxVal = (*array + i);
		}
	}
	printf("The minimum value is %d\n", minVal);
	printf("The maximum value is %d\n", maxVal);
}

void oddEvenNr(int* array, int* size)
{
	int count = 0;
	int odd = 0;
	printf("Even numbers: ");
	for (int i = 0; i < *size; i++)
	{
		if (*(array + i) % 2 == 0)
		{
			count++;
			printf("%d ", *(array + i));
		}
	}
	printf("\nOdd numbers: ");
	for(int i=0; i<*size; i++)
	{
		if (*(array + i) % 2 != 0)
		{
			printf("%d ", *(array + i));
			odd++;
		}
	}
	printf("\nThere are %d even numbers\n", count);
	printf("There are %d odd numbers\n", odd);
}
void mergeArrays(int* array, int* size)
{
	int array2[ARR_SIZE];
	int sizearr2, k, i;
	printf("Let's create one more array.\nType the size of array:");
	scanf_s("%d", &sizearr2);
	printf("Let's add values: \n");
	for (int i = 0; i < sizearr2; i++)
	{
		printf("array[%d] = ", i);
		scanf_s("%d", &array2[i]);
	}
	int maxSize = sizearr2 + *size;
	int arrMerged[ARR_SIZE];

	for (i = 0; i < *size; i++)
	{
		arrMerged[i] = array[i]; 
	}
	k = i;
	for (i = 0; i < sizearr2; i++)
	{
		arrMerged[k] = array2[i];
		k++;
	}
	printf("\nMerged arrays: ");
	for (i = 0; i < k; i++)
	{
		printf(" %d\t", arrMerged[i]);
		
	}
	printf("\n");
}
void negativeNumbers(int* array, int *size)
{
	int i;
	for (i = 0; i < *size; i++)
	{
		if (*(array + i) < 0)
		{
			printf("%d\t", *(array + i));
			i++;
		}
	}
	if (i == *size)
	{
		printf("No negative number found\n");
	}
}