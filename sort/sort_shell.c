/*
2016-04-05
Ï£¶ûÅÅĞò£¬²åÈëÅÅĞòËã·¨ÓÅ»¯
http://blog.csdn.net/hguisu/article/details/7776068
*/

#include <stdio.h> 

#include "get_input_data.h"

void shell_insert_sort(int a[], int length, int dk)
{
    int iii = 0;
    int jjj = 0;
    int key = 0;

	for (iii = dk; iii < length; iii++)
	{
        if(a[iii] >= a[iii-dk])
       	    continue;
        key = a[iii];
        jjj = iii - dk;
        while (jjj >= 0)
		{
			if(key < a[jjj])
   			{
   				a[jjj+dk] = a[jjj];
   				jjj -= dk;
   				continue;
			}
			break;
        }
       	a[jjj+dk] = key;
    }
}

void shell_sort(int a[], int length)
{
	int dk = length / 2;
	
	while(dk > 0)
	{
		shell_insert_sort(a, length, dk);
		dk = dk / 2;
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
	
    shell_sort(source_data, data_number);
	
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
