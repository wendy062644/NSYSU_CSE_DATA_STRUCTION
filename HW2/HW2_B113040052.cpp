//Author: B113040052
//Date: 2023/09/11
//Purpose: 集合類別
#include<bits/stdc++.h>
using namespace std;
char str[256], str1[256], x; //定義字串
class Tset{ //建立class
    public:
        Tset operator+(Tset a);
        void operator=(Tset a);
        Tset operator*(Tset a);
        Tset operator-(Tset a);
        bool operator>=(Tset a);
        bool str[256] = {0};
};
Tset Tset::operator+(Tset a) //運算子重載 +
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = (str[i] || a.str[i]); //其一為true，則為true
    return temp;
}
Tset Tset::operator-(Tset a) //運算子重載 -
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = str[i]&&!a.str[i]; //第一個為true，第二個為false，則為true
    return temp;
}
Tset Tset::operator*(Tset a) //運算子重載 *
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = (str[i] * a.str[i]); //其一為false，則為false
    return temp;
}
void Tset::operator=(Tset a) //運算子重載 =
{
    for(int i = 0; i < 256; i++)
        str[i] = a.str[i];
}
bool Tset::operator>=(Tset a) //運算子重載 >=
{
    for(int i = 0; i < 256; i++)
        if(a.str[i] && !str[i]) //如果被判斷的組合內為true，但本身卻為false時，則直接回傳false代表沒有contain
            return 0;
    return 1;//當陣列內的數字跑完都沒有return時，代表a內的true都有包含在內
}
void print(int n)
{
    Tset A, B; //建立組合

    cin.getline(str, 256); //輸入字串1
    for(int i = 0; i < strlen(str); i++)
    {
        A.str[str[i]] = 1;
    }

    cin.getline(str1, 256); //輸入字串2
    for(int i = 0; i < strlen(str1); i++)
    {
        B.str[str1[i]] = 1;
    }
    cin >> x; //輸入字元
    cout << "Test Case " << n << ":\nA: {";
    for(int i = 0; i < 256; i++) //輸出組合A
        if(A.str[i])
            cout << char(i);
    cout << "}\nB: {";
    for(int i = 0; i < 256; i++) //輸出組合B
        if(B.str[i])
            cout << char(i);
    cout << "}\n";

    Tset C = A+B; //建立組合C為A+B
    cout << "A+B: {";
    for(int i = 0; i < 256; i++) //輸出組合C
        if(C.str[i])
            cout << char(i);
    cout << "}\n";

    Tset D = A*B; //建立組合C為A*B
    cout << "A*B: {";
    for(int i = 0; i < 256; i++) //輸出組合D
        if(D.str[i])
            cout << char(i);
    cout << "}\n";
    Tset E = A-B; //建立組合E為A-B
    cout << "A-B: {";
    for(int i = 0; i < 256; i++) //輸出組合E
        if(E.str[i])
            cout << char(i);
    cout << "}\n";
    Tset F = B-A; //建立組合F為B-A
    cout << "B-A: {";
    for(int i = 0; i < 256; i++) //輸出組合F
        if(F.str[i])
            cout << char(i);
    cout << "}\n";
    if(A >= B) //判斷A是否包含B
        cout << "A contains B\n";
    else
        cout << "A does not contain B\n";
    if(B >= A) //判斷B是否包含A
        cout << "B contains A\n";
    else
        cout << "B does not contain A\n";
    if(A.str[x]) //直接找A內的x位置是否為true
        printf("'%c' is in A\n", x);
    else
        printf("'%c' is not in A\n", x);
    if(B.str[x]) //直接找B內的x位置是否為true
        printf("'%c' is in B\n", x);
    else
        printf("'%c' is not in B\n", x);
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin.getline(str, 256); //輸入緩衝
        print(i+1);
    }
    return 0;
}
