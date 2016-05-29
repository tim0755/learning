/*
2016-04-05
¼òµ¥Ñ¡ÔñÅÅĞò 
http://blog.csdn.net/hguisu/article/details/7776068
*/

#include <stdio.h> 

#include "get_input_data.h"

int select_min(int a[], int start, int length)
{
	int iii = start;
	int kkk = start;
	
	for(iii = start; iii < length; iii++)
	{
		if(a[iii] < a[kkk])
			kkk = iii;
	}
	return kkk;
}

void select_sort(int a[], int length)
{
    int iii = 0;
    int min = 0;
    int tmp = 0;

	for (iii = 0; iii < length; iii++)
	{
		min = select_min(a, iii, length);
		if(min != iii)
		{
			tmp = a[iii];
			a[iii] = a[min];
			a[min] = tmp;
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
