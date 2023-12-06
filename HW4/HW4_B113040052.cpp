//Author: B113040052
//Date: 2023/09/20
//Purpose: 西洋棋騎士走完棋盤的順序(recursion)
#include<bits/stdc++.h>
using namespace std;

int pos[10][10], t = 7, newX, newY; //pos紀錄位置、t紀錄次數
int x[8] = {1, 2, 2, 1, -1, -2, -2, -1}, y[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //座標移動方向

bool Move(int Y, int X, int m) //遞迴
{
    pos[Y][X] = m; //紀錄位置數字
    if(m == t*t) //判斷是否找到答案
        return true;
    for(int i = 0; i < 8; i++) //找8個方向
    {
        newX = X + x[i], newY = Y + y[i];
        if(newX > -1&&newX < t&&newY > -1&&newY < t&&pos[newY][newX] == 0) //判斷是否超出界線或有數字
        {
            if(Move(newY, newX, m+1))
                return true;
        }
    }
    pos[Y][X] = 0; //數字歸0
    return false; //回傳0，代表沒找到適合的
}

int main()
{
    while(--t)
    {
        cout << endl << t << endl;
        for(int i = 0; i < t*t; i++) //座標數字歸0
            pos[i/t][i%t] = 0;
        if(Move(0, 0, 1)) //如果找到答案，會一直回傳true，直到回到這
        {
            for(int i = 0; i < t; i++) //輸出答案
            {
                for(int j = 0; j < t; j++)
                    cout << setw(2) << pos[i][j] << ' ';
                cout << endl;
            }
        }
        else //沒找到答案
            cout << "no solution\n";
    }
    return 0;
}
