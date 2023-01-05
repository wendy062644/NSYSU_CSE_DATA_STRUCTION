#include<iostream>
#include"stack.h"
using namespace std;
int main(){
	int t = 1;
	int mx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, my[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	while(6 >= t)
	{
		int map[t][t], x = 0, y = 0, n = 0, m = 0;
		bool ans = 1;
		for(int i = 0; t > i; i++)
		{
			for(int j = 0; t > j; j++)
			{
				map[i][j] = 0;
			}
		}
		while(1){
			push(x, y, m);
			n++;
			map[x][y] = n;
			if(n == t*t){
				break;
			}
			m = 0;
			while(x+mx[m] >= t||y+my[m] >= t||x+mx[m] < 0||y+my[m] < 0||map[x+mx[m]][y+my[m]] != 0)
			{
				if(m > 7){
					map[x][y] = 0;
					m = pop();
					n--;
					if(n == 0){ans = 0; break;}
					x -= mx[m];
					y -= my[m];
				}
				m++;
			}
			if(ans == 0){
				break;
			}
			x += mx[m];
			y += my[m];
		}
		if(!ans){cout << "no solution" << endl << endl;}
		else{
			for(int i = 0; t > i; i++)
			{
				for(int j = 0; t > j; j++)
				{
					printf("%3d ", map[i][j]);
				}
				cout << endl;
			}
			cout << endl;
		}
		t++;
	}
}
