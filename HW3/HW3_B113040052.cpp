//Author: B113040052
//Date: 2023/09/20
//Purpose: 西洋棋騎士走完棋盤的順序
#include<bits/stdc++.h>
using namespace std;

int x[8] = {1, 2, 2, 1, -1, -2, -2, -1}, y[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; //座標移動方向

int pos[10][10], i, t, n = 7; //紀錄位置

class node //建立物件
{
    private: //紀錄x、y、m方向與上個點
        node* next;
        int X;
        int Y;
        int m;

    public:
        void push(); //定義stack push函式
        void pop(); //定義stack pop函式
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

node* S; //建立stack記錄點

void node::pop() //stack pop功能
{
    pos[Y][X] = 0; //座標歸0
    node* p = S; //紀錄S當下記憶體位置
    if(i > 1) //判斷是否為最後一個
    {
        S = S -> next;
        S -> m++;
    }
    else
        S = nullptr; //如果是最後一個則變成指標的null
    delete p; //刪除紀錄的S點
}

void node::push() //stack push功能
{
    while (m < 8)
    {
        int newX = X + x[m]; //計算當前X加上移動的格數
        int newY = Y + y[m]; //計算當前Y加上移動的格數

        if (newX >= 0 && newX < t && newY >= 0 && newY < t && pos[newY][newX] == 0) //判斷是否超出範圍
        {
            i++; //如果沒有，則當前數字+1
            pos[newY][newX] = i; //紀錄當前數字及位置
            node* p = S; //紀錄當前S點
            S = new node(newY, newX, 0); //將S點更新
            S->next = p; //將上個點紀錄到當前S的next中
            return; //直接return，找下一個點
        }
        m++; //如果超過或那位置走過，則繼續找下個
    }
    i--; //代表8個方向都走過，且沒適合的位置，需退後一個
    pop(); //刪除當下的點，繼續從上一個找
}

int main()
{
    while(--n) //n = 6 ~ 1
    {
        bool ans = 1; //預設有答案
        t = 7-n; //當下n數
        cout << t << endl; //輸出當下個n數
        i = 1; //從第一個開始找
        S = new node(); //建立第一個點
        pos[0][0] = 1; //起始點為左上角
        for(int k = 1; k < t*t; k++) //先歸0
            pos[k/t][k%t] = 0;
        while(i < t*t) //i沒有到n*n之前，繼續找
        {
            S -> push(); //找下個適合的點
            if(S == nullptr) //如果起始點的m超過8，則會在pop消失變成nullptr
            {
                ans = 0; //沒有答案
                break; //直接結束
            }
        }
        if(!ans) //判斷是否有答案
        {
            cout << "no solution\n";
            continue; //直接跳過下方輸出
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
