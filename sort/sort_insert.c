/*
2016-04-05
http://blog.csdn.net/hguisu/article/details/7776068
²åÈëÅÅĞòËã·¨ 
*/

#include <stdio.h> 

#include "get_input_data.h"

void insert_sort(int a[], int length)
{
    int iii = 0;
    int jjj = 0;
    int key = 0;
	
    for (iii = 1; iii < length; iii++)
	{
        key = a[iii];
        for (jjj = iii - 1; jjj >= 0; jjj--)
		{
            if (a[jjj] > key)
			{
                a[jjj + 1] = a[jjj];
            }
			else
			{
                break;
            }
        }
        a[jjj + 1] = key;
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
	
    insert_sort(source_data, data_number);
	
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
