
int* get_input_data(int* data_number)
{
	int iii=0;
	int data = 0;
	int *pData = 0;
	
	if(0 == freopen("input.txt", "r", stdin))
	{
		printf("not find the file!\n");
		return 0;
	}
	
	scanf("%d", data_number);
	
	pData = (int *)malloc(*data_number * sizeof(int));
	if(0 == pData)
	{
		printf("malloc error! size:%d\n", *data_number);
		*data_number = 0;
		return 0;
	}
	
	for(iii=0; iii<*data_number; iii++)
	{
		scanf("%d", &pData[iii]);
	}
	
	fclose(stdin);
	return pData;
}
