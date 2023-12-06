//Author: B113040052
//Date: 2023/09/20
//Purpose: ��v���M�h�����ѽL������
#include<bits/stdc++.h>
using namespace std;

int x[8] = {1, 2, 2, 1, -1, -2, -2, -1}, y[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //�y�в��ʤ�V

int pos[10][10], i, t, n = 7; //������m

class node //�إߪ���
{
    private: //����x�By�Bm��V�P�W���I
        node* next;
        int X;
        int Y;
        int m;

    public:
        void push(); //�w�qstack push�禡
        void pop(); //�w�qstack pop�禡
        node() //construct
        {
            X = 0;
            Y = 0;
            m = 0;
            next = nullptr;
        }
        node(int y, int x, int M)
        {
            X = x;
            Y = y;
            m = M;
            next = nullptr;
        }
};

node* S; //�إ�stack�O���I

void node::pop() //stack pop�\��
{
    pos[Y][X] = 0; //�y���k0
    node* p = S; //����S��U�O�����m
    if(i > 1) //�P�_�O�_���̫�@��
    {
        S = S -> next;
        S -> m++;
    }
    else
        S = nullptr; //�p�G�O�̫�@�ӫh�ܦ����Ъ�null
    delete p; //�R��������S�I
}

void node::push() //stack push�\��
{
    while (m < 8)
    {
        int newX = X + x[m]; //�p���eX�[�W���ʪ����
        int newY = Y + y[m]; //�p���eY�[�W���ʪ����

        if (newX >= 0 && newX < t && newY >= 0 && newY < t && pos[newY][newX] == 0) //�P�_�O�_�W�X�d��
        {
            i++; //�p�G�S���A�h��e�Ʀr+1
            pos[newY][newX] = i; //������e�Ʀr�Φ�m
            node* p = S; //������eS�I
            S = new node(newY, newX, 0); //�NS�I��s
            S->next = p; //�N�W���I�������eS��next��
            return; //����return�A��U�@���I
        }
        m++; //�p�G�W�L�Ψ���m���L�A�h�~���U��
    }
    i--; //�N��8�Ӥ�V�����L�A�B�S�A�X����m�A�ݰh��@��
    pop(); //�R����U���I�A�~��q�W�@�ӧ�
}

int main()
{
    while(--n) //n = 6 ~ 1
    {
        bool ans = 1; //�w�]������
        t = 7-n; //��Un��
        cout << t << endl; //��X��U��n��
        i = 1; //�q�Ĥ@�Ӷ}�l��
        S = new node(); //�إ߲Ĥ@���I
        pos[0][0] = 1; //�_�l�I�����W��
        for(int k = 1; k < t*t; k++) //���k0
            pos[k/t][k%t] = 0;
        while(i < t*t) //i�S����n*n���e�A�~���
        {
            S -> push(); //��U�ӾA�X���I
            if(S == nullptr) //�p�G�_�l�I��m�W�L8�A�h�|�bpop�����ܦ�nullptr
            {
                ans = 0; //�S������
                break; //��������
            }
        }
        if(!ans) //�P�_�O�_������
        {
            cout << "no solution\n";
            continue; //�������L�U���X
        }
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                cout << setw(2) << pos[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
