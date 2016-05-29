/*
2016-04-05
选择排序优化，二元选择排序 
http://blog.csdn.net/hguisu/article/details/7776068
*/

#include <stdio.h> 

#include "get_input_data.h"

void select_min_max(int a[], int start, int end, int *min_o, int *max_o)
{
	int iii = 0;
	int min = start;
	int max = start;
	
	for(iii = start + 1; iii < end; iii++)
	{
		if(a[iii] < a[min])
			min = iii;
		if(a[iii] > a[max])
		    max = iii;
	}

	*min_o = min;
	*max_o = max;
}

void select_sort(int a[], int length)
{
    int iii = 0;
    int tmp = 0;
    int min_o = 0;
    int max_o = 0;
    int rest = length;
    
	while (rest > 1)
	{
		select_min_max(a, iii, iii+rest, &min_o, &max_o);
		if(min_o == iii + rest - 1 && max_o == iii)//刚好最大的和最小的位置对调一下即可 
		{
			tmp = a[iii];
			a[iii] = a[iii + rest -1];
			a[iii + rest -1] = tmp;
		}
		else
		{
			if(min_o != iii)
			{	
				tmp = a[iii];
				a[iii] = a[min_o];
				a[min_o] = tmp;
			}
			if(max_o != iii + rest - 1)
			{
				tmp = a[iii + rest - 1];
				a[iii + rest -1] = a[max_o];
				a[max_o] = tmp;
			}	
		}		
		iii++;
		rest -= 2;
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
	
    select_sort(source_data, data_number);
	
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
