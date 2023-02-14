#include<stdio.h>

void print(int n){
	int map[n][n], x = n/2, y = 0;
	for(int i = 0; n > i; i++)
	{
		for(int j = 0; n > j; j++)
		{
			map[j][i] = 0;
		}
	}
	for(int i = 1; n*n >= i; i++)
	{
		map[x][y] = i;
		int tx = x-1, ty = y-1;
		if(tx == -1){tx = n-1;}
		if(ty == -1){ty = n-1;}
		if(map[tx][ty] != 0){
			y++;
			if(y >= n){y = 0;}
		}
		else{
			x--;
			y--;
			if(x == -1){x = n-1;}
			if(y == -1){y = n-1;}
		}
	}
	for(int i = 0; n > i; i++)
	{
		for(int j = 0; n > j; j++)
		{
			printf("%2d ", map[j][i]);
		}
		printf("\n");
	}
}

int main(){
	for(int i = 1; 9 >= i; i += 2)
	{
		print(i);
		printf("\n");
	}
}
