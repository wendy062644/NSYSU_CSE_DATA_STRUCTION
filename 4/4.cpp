#include<iostream>
using namespace std;

int map[10][10], t;
int mx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, my[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int move(int x, int y, int n){
	if(map[x][y] == 0&&x >= 0&&y >=0&&x < t&&y < t)
	{
		map[x][y] = n;
		if(n == t*t){return 1;}
		for(int i = 0; 7 > i; i++)
		{
			if(move(x+mx[i], y+my[i], n+1) == 1){return 1;}
		}
	}
	else{
		return 0;
	}
	map[x][y] = 0;
	return 0;
}

int main(){
	bool ans = 0;
	for(t = 1; 6 >= t; t++){
		for(int i = 0; t > i; i++)
		{
			for(int j = 0; t > j; j++)
			{
				map[i][j] = 0;
			}
		}
		ans = move(0, 0, 1);
		if(ans){
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
		else{
			cout << "no solution" << endl << endl;
		}
	}
}
