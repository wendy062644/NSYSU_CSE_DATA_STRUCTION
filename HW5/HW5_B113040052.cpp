//Author: B113040052
//Date: 2023/09/21
//Purpose: linked list 簡單之加乘應用
#include<bits/stdc++.h>
using namespace std;

class Poly { // linked list 之 Node
    private:
        Poly *next; //紀錄下個記憶體位置
        int exp; // 紀錄指數
        int coef; // 紀錄底數
    public:
        Poly(); //construct
        Poly(int e, int c); //construct
        void add(int e, int c); //新增node
        void print(); //輸出linked list所有資料
        Poly operator+(Poly B) //重載運算子 +
        {
            Poly result; //要return的結果
            Poly *a = next, *b = B.next; //紀錄開頭記憶體位置
            while(a != nullptr) //先將a的資料放入
            {
                result.add(a -> exp, a -> coef);
                a = a -> next;
            }
            while(b != nullptr) //再把B的資料放入
            {
                result.add(b -> exp, b -> coef);
                b = b -> next;
            }
            return result; //回傳結果
        }
        Poly operator*(Poly B)  //重載運算子 *
        {
            Poly result; //要return的結果
            Poly *a = next, *b; //紀錄開頭記憶體位置
            while(a != nullptr) // 先將a的資料給b全部乘一次，a再換下一個
            {
                b = B.next;
                while(b != nullptr)
                {
                    result.add(a -> exp + b -> exp, a -> coef * b -> coef);
                    b = b -> next;
                }
                a = a -> next;
            }
            return result; //回傳結果
        }
        void operator=(Poly *b) //要將return的result存入C或D，
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

void Poly::add(int e, int c) //新增點
{
    if(next == nullptr) //判斷是否為開頭
    {
        next = new Poly(e, c);
        return;
    }
    Poly *p = this;
    while(p -> next != nullptr&&p -> next -> exp > e) //找到適合的位置，由大到小排序，插入排序
    {
        p = p -> next;
    }
    if(p -> next != nullptr&&p -> next -> exp == e) //判斷是否有相同的指數
    {
        p -> next -> coef += c; //將底數相加
        if(p -> next -> coef == 0) //如果加完變成0，則要delete node
        {
            Poly *temp = p -> next;
            p -> next = temp -> next;
            delete temp;
        }
    }
    else //如果沒有，則新增點
    {
        Poly *temp = new Poly(e, c);
        temp -> next = p -> next;
        p -> next = temp;
    }
}

void Poly::print() //輸出linked list內資料
{
    Poly *p = next;
    if(p == nullptr) //如果為空的，代表沒資料，則輸出0 0
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
    while(cin >> p) //判斷是否輸入
    {
        Poly A, B, C, D;
        for(int i = 0; i < p; i++) //輸入第一個多項式
        {
            cin >> c >> e;
            A.add(e, c);
        }
        cin >> q;
        if(!p&&!q) //如果q和p為0，則!q及!p會為1，代表true，會結束
            break;
        for(int i = 0; i < q; i++) //輸入第二個多項式
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
