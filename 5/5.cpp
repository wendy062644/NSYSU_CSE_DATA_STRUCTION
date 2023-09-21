#include<bits/stdc++.h>
using namespace std;

class Poly {
    private:
        Poly *next;
        int exp;
        int coef;
    public:
        Poly();
        Poly(int e, int c);
        void add(int e, int c);
        void print();
        Poly operator+(Poly B)
        {
            Poly result;
            Poly *a = next, *b = B.next;
            while(a != nullptr)
            {
                result.add(a -> exp, a -> coef);
                a = a -> next;
            }
            while(b != nullptr)
            {
                result.add(b -> exp, b -> coef);
                b = b -> next;
            }
            return result;
        }
        Poly operator*(Poly B)
        {
            Poly result;
            Poly *a = next, *b;
            while(a != nullptr)
            {
                b = B.next;
                while(b != nullptr)
                {
                    result.add(a -> exp + b -> exp, a -> coef * b -> coef);
                    b = b -> next;
                }
                a = a -> next;
            }
            return result;
        }
        void operator=(Poly *b)
        {
            exp = b -> exp;
            coef = b -> coef;
            next = b -> next;
        }
};

Poly::Poly(int e, int c){
    exp = e;
    coef = c;
    next = nullptr;
}

Poly::Poly(){
    exp = 0;
    coef = 0;
    next = nullptr;
}

void Poly::add(int e, int c)
{
    if(next == nullptr)
    {
        next = new Poly(e, c);
        return;
    }
    Poly *p = this;
    while(p -> next != nullptr&&p -> next -> exp > e)
    {
        p = p -> next;
    }
    if(p -> next != nullptr&&p -> next -> exp == e)
    {
        p -> next -> coef += c;
        if(p -> next -> coef == 0)
        {
            Poly *temp = p -> next;
            p -> next = temp -> next;
            delete temp;
        }
    }
    else
    {
        Poly *temp = new Poly(e, c);
        temp -> next = p -> next;
        p -> next = temp;
    }
}

void Poly::print()
{
    Poly *p = next;
    if(p == nullptr)
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
    while(cin >> p)
    {
        Poly A, B, C, D;
        for(int i = 0; i < p; i++)
        {
            cin >> c >> e;
            A.add(e, c);
        }
        cin >> q;
        if(!p&&!q)
            break;
        for(int i = 0; i < q; i++)
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
