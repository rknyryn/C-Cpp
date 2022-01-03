#include <stdio.h>
#include <stdlib.h>

void writeArray(int array[], int length)
{
	int i;
	for(i= 0; i<length; i++)
		printf("%d ", array[i]);
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void bubbleSort(int array[], int length)
{
	int i,j;
	for(j=0; j<length-1; j++)
	{
		for(i=0; i<length-j-1; i++)
		{
			if(array[i] > array[i+1])
			{
				swap(&array[i], &array[i+1]);
				printf("\n - "); writeArray(array, length);
			}
		}
	}	
}

void insertionSort(int array[], int length)
{
	int i, key, j;
    	for (i = 1; i < length; i++) 
	{ 
        	key = array[i]; 
        	j = i - 1; 
        	while (j >= 0 && array[j] > key) 
		{ 
            	array[j + 1] = array[j]; 
            	j = j - 1; 
        } 
        	array[j + 1] = key;
        	printf("\n - "); writeArray(array, length);
	} 
}

void selectionSort(int array[], int length)
{
	int i, j, minIndex; 
    	for (i = 0; i < length-1; i++) 
    	{ 
        	minIndex = i; 
        	for (j = i+1; j < length; j++) 
          		if (array[j] < array[minIndex]) 
            			minIndex = j; 
 
        	swap(&array[minIndex], &array[i]);
        	printf("\n - "); writeArray(array, length);
    	} 
}

int main()
{
	int bubbleArray[] = {8, 5, 2, 6, 12};
	printf("Bubble Sort");
	printf("\noriginal: "); writeArray(bubbleArray, 5);
	bubbleSort(bubbleArray, 5);
	printf("\nbubble sort: "); writeArray(bubbleArray, 5);
	
	int insertionArray[] = {4, 3, 2, 10, 12, 1, 5, 6};
	printf("\n\nInsertion Sort");
	printf("\noriginal: "); writeArray(insertionArray, 8);
	insertionSort(insertionArray, 8);
	printf("\ninsertion sort: "); writeArray(insertionArray, 8);
	
	int selectionArray[] = {8, 5, 2, 6, 9, 3, 1, 0, 4, 7};
	printf("\n\nSelection Sort");
	printf("\noriginal: "); writeArray(selectionArray, 10);
	selectionSort(selectionArray, 10);
	printf("\nselection sort: "); writeArray(selectionArray, 10);
	return 0;
}
