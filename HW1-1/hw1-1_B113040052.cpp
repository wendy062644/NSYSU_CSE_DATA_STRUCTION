//Author: B113040052
//Date: 2023/09/11
//Purpose: ��Xn���]��
#include <bits/stdc++.h>
using namespace std;
void print(int n) //��X�ϧ�
{
    int now = 1, num[n][n], i = 0, j = n/2; //now��������U�ݶ�J���Ʀr
    while(now <= n*n)
    {
        num[i][j] = now; //�N�Ʀr�s�J�}�C
        now++; //�N�ݶ񪺼Ʀr+1
        if(!((now-1)%n)) //�P�_�O�_��Jn�ӼƦr�F
            i++; //�p�G�O�A�N��U�ӼƦr�����U��
        else //�p�G���O�A�N��U�ӼƦr�ӱ`��J
        {
            i--;
            j--;
        }
        if(i < 0) //�P�_�O�_�W�X�}�C�d��
            i = n+i;
        if(j < 0) //�P�_�O�_�W�X�}�C�d��
            j = n+j;
    }
    for(i = 0; i < n; i++) //��X�}�C�Ʀr
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
