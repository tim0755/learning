/*
2016-04-06
http://blog.csdn.net/hguisu/article/details/7776068
¿ìËÙÅÅĞòËã·¨ 
*/

#include <stdio.h> 

#include "get_input_data.h"

void swap(int *a, int *b)
{
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int sort_patition(int a[], int start, int end)
{
	int key = a[start];
	
	while(start < end)
	{
		while(start < end && key <= a[end])
			end--;
		if(start != end && a[start] != a[end])
			swap(&a[start], &a[end]);
		
		while(start < end && key >= a[start])
		    start++;
		if(start != end && a[start] != a[end])
			swap(&a[start], &a[end]);
	}
	return start;
}

void quick_sort(int a[], int start, int end)
{
    int index = 0;
	
	if(start < end)
	{
		index = sort_patition(a, start, end);
		quick_sort(a, start, index);
		quick_sort(a, index+1, end);
	}
}

int main(void)
{
    int iii = 0;
    int data_number = 0;
    int* source_data = 0;
	
	source_data = get_input_data(&data_number);
	
    printf("before sort:\n");
    for (iii = 0; iii < data_number; iii++)
	{
        printf("%d,", source_data[iii]);
    }
    printf("\n");
	
    quick_sort(source_data, 0, data_number);
	
    printf("after sort:\n");
    for (iii = 0; iii < data_number; iii++)
	{
        printf("%d,", source_data[iii]);
    }
    printf("\n");
    
    if(source_data)
    	free(source_data);
    return 0;
}
