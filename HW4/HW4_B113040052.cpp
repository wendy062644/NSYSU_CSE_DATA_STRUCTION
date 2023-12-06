//Author: B113040052
//Date: 2023/09/20
//Purpose: ��v���M�h�����ѽL������(recursion)
#include<bits/stdc++.h>
using namespace std;

int pos[10][10], t = 7, newX, newY; //pos������m�Bt��������
int x[8] = {1, 2, 2, 1, -1, -2, -2, -1}, y[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //�y�в��ʤ�V

bool Move(int Y, int X, int m) //���j
{
    pos[Y][X] = m; //������m�Ʀr
    if(m == t*t) //�P�_�O�_��쵪��
        return true;
    for(int i = 0; i < 8; i++) //��8�Ӥ�V
    {
        newX = X + x[i], newY = Y + y[i];
        if(newX > -1&&newX < t&&newY > -1&&newY < t&&pos[newY][newX] == 0) //�P�_�O�_�W�X�ɽu�Φ��Ʀr
        {
            if(Move(newY, newX, m+1))
                return true;
        }
    }
    pos[Y][X] = 0; //�Ʀr�k0
    return false; //�^��0�A�N��S���A�X��
}

int main()
{
    while(--t)
    {
        cout << endl << t << endl;
        for(int i = 0; i < t*t; i++) //�y�мƦr�k0
            pos[i/t][i%t] = 0;
        if(Move(0, 0, 1)) //�p�G��쵪�סA�|�@���^��true�A����^��o
        {
            for(int i = 0; i < t; i++) //��X����
            {
                for(int j = 0; j < t; j++)
                    cout << setw(2) << pos[i][j] << ' ';
                cout << endl;
            }
        }
        else //�S��쵪��
            cout << "no solution\n";
    }
    return 0;
}
