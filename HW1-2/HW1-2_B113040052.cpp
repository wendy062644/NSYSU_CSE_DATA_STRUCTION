//Author: B113040052
//Date: 2023/09/11
//Purpose: 輸出n階乘
#include <bits/stdc++.h>
using namespace std;

void f(int n)
{
    int num[200] = {0}, m, carry = 0, Max = 1; //陣列紀錄大數運算
    num[0] = 1; //初始值為1
    for(int i = 1; i <= n; i++) //跑n次，計算n的階乘
    {
        m = 0; //紀錄當下位數
        carry = 0; //紀錄進位
        while(carry|| m < Max) //判斷是否要進位或沒有跑到最大位數
        {
            num[m] = num[m] * i + carry; //先乘再加
            carry = num[m]/10; //計算需進位的數
            num[m] %= 10; //只留下個位數
            m++; //當前位數+1
        }
        Max = m+bool(carry); //紀錄當下最大位數
    }
    while(Max > 0)
    {
        cout << num[--Max]; //慢慢輸出
    }
    cout << endl;
}

int main() {
    int n;
    while(cin >> n)
    {
        if(!n) //判斷輸入是否為0
            break;
        for(int i = 1; i <= n; i++) //計算階乘
        {
            printf("%d!=", i);
            f(i);
        }
    }
    return 0;
}
