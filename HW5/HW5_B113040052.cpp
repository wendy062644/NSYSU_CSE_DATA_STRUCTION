//Author: B113040052
//Date: 2023/09/21
//Purpose: linked list ²�椧�[������
#include<bits/stdc++.h>
using namespace std;

class Poly { // linked list �� Node
    private:
        Poly *next; //�����U�ӰO�����m
        int exp; // ��������
        int coef; // ��������
    public:
        Poly(); //construct
        Poly(int e, int c); //construct
        void add(int e, int c); //�s�Wnode
        void print(); //��Xlinked list�Ҧ����
        Poly operator+(Poly B) //�����B��l +
        {
            Poly result; //�nreturn�����G
            Poly *a = next, *b = B.next; //�����}�Y�O�����m
            while(a != nullptr) //���Na����Ʃ�J
            {
                result.add(a -> exp, a -> coef);
                a = a -> next;
            }
            while(b != nullptr) //�A��B����Ʃ�J
            {
                result.add(b -> exp, b -> coef);
                b = b -> next;
            }
            return result; //�^�ǵ��G
        }
        Poly operator*(Poly B)  //�����B��l *
        {
            Poly result; //�nreturn�����G
            Poly *a = next, *b; //�����}�Y�O�����m
            while(a != nullptr) // ���Na����Ƶ�b�������@���Aa�A���U�@��
            {
                b = B.next;
                while(b != nullptr)
                {
                    result.add(a -> exp + b -> exp, a -> coef * b -> coef);
                    b = b -> next;
                }
                a = a -> next;
            }
            return result; //�^�ǵ��G
        }
        void operator=(Poly *b) //�n�Nreturn��result�s�JC��D�A
        {
            exp = b -> exp;
            coef = b -> coef;
            next = b -> next;
        }
};

Poly::Poly(int e, int c){ //construct
    exp = e;
    coef = c;
    next = nullptr;
}

Poly::Poly(){ //construct
    exp = 0;
    coef = 0;
    next = nullptr;
}

void Poly::add(int e, int c) //�s�W�I
{
    if(next == nullptr) //�P�_�O�_���}�Y
    {
        next = new Poly(e, c);
        return;
    }
    Poly *p = this;
    while(p -> next != nullptr&&p -> next -> exp > e) //���A�X����m�A�Ѥj��p�ƧǡA���J�Ƨ�
    {
        p = p -> next;
    }
    if(p -> next != nullptr&&p -> next -> exp == e) //�P�_�O�_���ۦP������
    {
        p -> next -> coef += c; //�N���Ƭۥ[
        if(p -> next -> coef == 0) //�p�G�[���ܦ�0�A�h�ndelete node
        {
            Poly *temp = p -> next;
            p -> next = temp -> next;
            delete temp;
        }
    }
    else //�p�G�S���A�h�s�W�I
    {
        Poly *temp = new Poly(e, c);
        temp -> next = p -> next;
        p -> next = temp;
    }
}

void Poly::print() //��Xlinked list�����
{
    Poly *p = next;
    if(p == nullptr) //�p�G���Ū��A�N��S��ơA�h��X0 0
        cout << "0 0\n";
    while(p != nullptr)
    {
        cout << p -> coef << " " << p -> exp << endl;
        p = p -> next;
    }
}

int main()
{
    int p, q, e, c, t = 1;
    while(cin >> p) //�P�_�O�_��J
    {
        Poly A, B, C, D;
        for(int i = 0; i < p; i++) //��J�Ĥ@�Ӧh����
        {
            cin >> c >> e;
            A.add(e, c);
        }
        cin >> q;
        if(!p&&!q) //�p�Gq�Mp��0�A�h!q��!p�|��1�A�N��true�A�|����
            break;
        for(int i = 0; i < q; i++) //��J�ĤG�Ӧh����
        {
            cin >> c >> e;
            B.add(e, c);
        }
        cout << "Case" << t << ":\n";
        C = A + B;
        cout << "ADD\n";
        C.print();
        cout << "MULTIPLY\n";
        D = A * B;
        D.print();
        t++;
    }
    return 0;
}
