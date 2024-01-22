#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - will partition the array using Lomuto scheme
 *
 * @arr: the array to split
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 * Return: index of the pivot.
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot;
	int j, i;

	pivot = arr[high];
	i = low - 1;

	if (low > high || low < 0)
		return  (1);

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	/* Swap the pivot to its correct position */
	if ((i + 1) != high)
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	/* Return final position of pivot */
	return (i + 1);
}

/**
 * sort - recursively sort an array
 *
 * @arr: array to split
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 */
void sort(int arr[], int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high, size);
		sort(arr, low, pivot_index - 1, size);
		sort(arr, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *
 * @array: array to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}
