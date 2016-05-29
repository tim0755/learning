/*
2016-04-05
http://blog.csdn.net/hguisu/article/details/7776068
√∞≈›≈≈–ÚÀ„∑®
*/

#include <stdio.h> 

#include "get_input_data.h"

void bubble_sort(int a[], int length)
{
    int iii = 0;
    int jjj = 0;
    int tmp = 0;
	
    for (iii = 0; iii < length; iii++)
	{
        for (jjj = 0; jjj < length - iii - 1; jjj++)
		{
            if (a[jjj] > a[jjj+1])
			{
				tmp = a[jjj+1];
				a[jjj+1] = a[jjj];
				a[jjj] = tmp;
            }
        }
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
	
    bubble_sort(source_data, data_number);
	
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
