//Author: B113040052
//Date: 2023/09/11
//Purpose: ���X���O
#include<bits/stdc++.h>
using namespace std;
char str[256], str1[256], x; //�w�q�r��
class Tset{ //�إ�class
    public:
        Tset operator+(Tset a);
        void operator=(Tset a);
        Tset operator*(Tset a);
        Tset operator-(Tset a);
        bool operator>=(Tset a);
        bool str[256] = {0};
};
Tset Tset::operator+(Tset a) //�B��l���� +
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = (str[i] || a.str[i]); //��@��true�A�h��true
    return temp;
}
Tset Tset::operator-(Tset a) //�B��l���� -
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = str[i]&&!a.str[i]; //�Ĥ@�Ӭ�true�A�ĤG�Ӭ�false�A�h��true
    return temp;
}
Tset Tset::operator*(Tset a) //�B��l���� *
{
    Tset temp;
    for(int i = 0; i < 256; i++)
        temp.str[i] = (str[i] * a.str[i]); //��@��false�A�h��false
    return temp;
}
void Tset::operator=(Tset a) //�B��l���� =
{
    for(int i = 0; i < 256; i++)
        str[i] = a.str[i];
}
bool Tset::operator>=(Tset a) //�B��l���� >=
{
    for(int i = 0; i < 256; i++)
        if(a.str[i] && !str[i]) //�p�G�Q�P�_���զX����true�A�������o��false�ɡA�h�����^��false�N��S��contain
            return 0;
    return 1;//��}�C�����Ʀr�]�����S��return�ɡA�N��a����true�����]�t�b��
}
void print(int n)
{
    Tset A, B; //�إ߲զX

    cin.getline(str, 256); //��J�r��1
    for(int i = 0; i < strlen(str); i++)
    {
        A.str[str[i]] = 1;
    }

    cin.getline(str1, 256); //��J�r��2
    for(int i = 0; i < strlen(str1); i++)
    {
        B.str[str1[i]] = 1;
    }
    cin >> x; //��J�r��
    cout << "Test Case " << n << ":\nA: {";
    for(int i = 0; i < 256; i++) //��X�զXA
        if(A.str[i])
            cout << char(i);
    cout << "}\nB: {";
    for(int i = 0; i < 256; i++) //��X�զXB
        if(B.str[i])
            cout << char(i);
    cout << "}\n";

    Tset C = A+B; //�إ߲զXC��A+B
    cout << "A+B: {";
    for(int i = 0; i < 256; i++) //��X�զXC
        if(C.str[i])
            cout << char(i);
    cout << "}\n";

    Tset D = A*B; //�إ߲զXC��A*B
    cout << "A*B: {";
    for(int i = 0; i < 256; i++) //��X�զXD
        if(D.str[i])
            cout << char(i);
    cout << "}\n";
    Tset E = A-B; //�إ߲զXE��A-B
    cout << "A-B: {";
    for(int i = 0; i < 256; i++) //��X�զXE
        if(E.str[i])
            cout << char(i);
    cout << "}\n";
    Tset F = B-A; //�إ߲զXF��B-A
    cout << "B-A: {";
    for(int i = 0; i < 256; i++) //��X�զXF
        if(F.str[i])
            cout << char(i);
    cout << "}\n";
    if(A >= B) //�P�_A�O�_�]�tB
        cout << "A contains B\n";
    else
        cout << "A does not contain B\n";
    if(B >= A) //�P�_B�O�_�]�tA
        cout << "B contains A\n";
    else
        cout << "B does not contain A\n";
    if(A.str[x]) //������A����x��m�O�_��true
        printf("'%c' is in A\n", x);
    else
        printf("'%c' is not in A\n", x);
    if(B.str[x]) //������B����x��m�O�_��true
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
        cin.getline(str, 256); //��J�w��
        print(i+1);
    }
    return 0;
}
