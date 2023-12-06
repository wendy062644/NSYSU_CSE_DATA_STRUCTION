//Author: B113040052
//Date: 2023/09/11
//Purpose: ��Xn����
#include <bits/stdc++.h>
using namespace std;

void f(int n)
{
    int num[200] = {0}, m, carry = 0, Max = 1; //�}�C�����j�ƹB��
    num[0] = 1; //��l�Ȭ�1
    for(int i = 1; i <= n; i++) //�]n���A�p��n������
    {
        m = 0; //������U���
        carry = 0; //�����i��
        while(carry|| m < Max) //�P�_�O�_�n�i��ΨS���]��̤j���
        {
            num[m] = num[m] * i + carry; //�����A�[
            carry = num[m]/10; //�p��ݶi�쪺��
            num[m] %= 10; //�u�d�U�Ӧ��
            m++; //��e���+1
        }
        Max = m+bool(carry); //������U�̤j���
    }
    while(Max > 0)
    {
        cout << num[--Max]; //�C�C��X
    }
    cout << endl;
}

int main() {
    int n;
    while(cin >> n)
    {
        if(!n) //�P�_��J�O�_��0
            break;
        for(int i = 1; i <= n; i++) //�p�ⶥ��
        {
            printf("%d!=", i);
            f(i);
        }
    }
    return 0;
}
