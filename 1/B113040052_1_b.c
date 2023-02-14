#include<stdio.h>

void print(int n){
	int num[100] = {0}, l = 1;
	num[0] = 1;
	for(int i = 1; n >= i; i++)
	{
		for(int j = 0; l > j; j++)
		{
			num[j] *= i;
		}
		for(int j = 0; l > j; j++)
		{
			if(num[j] >= 10){
				num[j+1] += num[j]/10;
				num[j] = num[j]%10;
				if(j == l-1){l++;}
			}
		}
	}
	printf("%d!=", n);
	for(int i = l-1; i >= 0; i--)
	{
		printf("%d", num[i]);
	}
}

int main(){
	while(1)
	{
		int input;
		scanf("%d", &input);
		if(input == 0){return 0;}
		for(int i = 1; input >= i; i++)
		{
			print(i);
			printf("\n");
		}
		printf("\n");
	}
} 
