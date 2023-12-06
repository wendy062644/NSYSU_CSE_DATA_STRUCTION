//Author: B113040052
//Date: 2023/09/11
//Purpose: 輸出n階魔方
#include <bits/stdc++.h>
using namespace std;
void print(int n) //輸出圖形
{
    int now = 1, num[n][n], i = 0, j = n/2; //now為紀錄當下需填入的數字
    while(now <= n*n)
    {
        num[i][j] = now; //將數字存入陣列
        now++; //將需填的數字+1
        if(!((now-1)%n)) //判斷是否填入n個數字了
            i++; //如果是，代表下個數字須往下填
        else //如果不是，代表下個數字照常填入
        {
            i--;
            j--;
        }
        if(i < 0) //判斷是否超出陣列範圍
            i = n+i;
        if(j < 0) //判斷是否超出陣列範圍
            j = n+j;
    }
    for(i = 0; i < n; i++) //輸出陣列數字
    {
        for(j = 0; j < n; j++)
            cout << " " << num[i][j];
        cout << endl;
    }
}
int main() {
    for(int i = 1; i < 10; i += 2)
    {
        cout << i << endl;
        print(i);
        cout << endl;
    }
    return 0;
}
