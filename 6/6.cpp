//Author: B113040052
//Date: 2023/09/22
//Purpose: binary tree之應用
#include<bits/stdc++.h>
using namespace std;

class node{ //點
    private:
        int value;
        node* right;
        node* left;
    public:
        node(int n) // construct
        {
            value = n;
            right = nullptr;
            left = nullptr;
        }
        bool add_node(node* p, int n);
        void print_node(node* root);
        void print_left(node* root);
        void print_right(node* root);
        node* del(node* root, int n);
        int right_subtree(node *root);
};

int node::right_subtree(node *root) //找right subtree的value
{
    if(root -> left != nullptr)
        return right_subtree(root -> left);
    else{
        int n = root -> value;
        return n;
    }
}

node* node::del(node* root, int n) //刪除相同的點
{
    if(n > root -> value) //大於value，往右找
        root -> right = del(root -> right, n);
    else if(n < root -> value) //小於value，往左找
        root -> left = del(root -> left, n);
    else //等於value，找到了
    {
        node *Right = root -> right, *Left = root -> left;
        if(Right != nullptr&&Left != nullptr) //如果有2個child
        {
            int temp = right_subtree(root -> right); //找right subtree值
            root -> value = temp; //將點更新為right subtree的最左側值
            root -> right = del(root -> right, temp); //將樹右邊的點更新，使用遞迴，因為抽走的點可能也有2個child
        }
        else if(Right != nullptr) //如果只有右邊
        {
            delete root;
            return Right;
        }
        else if(Left != nullptr) //如果只有左邊
        {
            delete root;
            return Left;
        }
        else //如果都沒有child，可直接刪除
        {
            delete root;
            return nullptr;
        }
    }
    return root; //value不等於n，直接回傳
}

bool node::add_node(node* p, int n) //新增點
{
    while(p -> value != n) //找到適合的位置
    {

        if(n > p -> value)
            if(p -> right == nullptr)
                break;
            else
            {
                p = p -> right;
            }
        else
            if(p -> left == nullptr)
                break;
            else
            {
                p = p -> left;
            }
    }
    if(p -> value == n) //判斷有沒有重複
        return 1;
    else
    {
        if(n > p -> value)
            p -> right = new node(n); //新增在右邊
        else
            p -> left = new node(n); //新增在左邊
    }
    return 0;
}

void node::print_node(node* root) //輸出根的狀況，使用遞迴
{
    if(root -> left != nullptr)
        print_node(root -> left);
    cout << setw(3) << root -> value << " ";
    if(root -> right != nullptr)
        print_node(root -> right);
}

void node::print_left(node* root) //輸出左邊的狀況，使用遞迴
{
    if(root -> left != nullptr)
    {
        print_left(root -> left);
        cout << setw(3) << root -> left -> value << " ";
    }
    else
        cout << setw(3) << 0 << " ";
    if(root -> right != nullptr)
        print_left(root -> right);
}

void node::print_right(node* root) //輸出右邊的狀況，使用遞迴
{
    if(root -> left != nullptr)
        print_right(root -> left);
    if(root -> right != nullptr)
    {
        cout << setw(3) << root -> right -> value << " ";
        print_right(root -> right);
    }
    else
        cout << setw(3) << 0 << " ";
}

int main()
{
    int n;
    node *root = nullptr; //設定根初始值
    while(cin >> n)
    {
        if(n == -1) //判斷是否結束
            break;
        if(root == nullptr) //判斷是否有根
            root = new node(n);
        else if(root -> add_node(root, n)) //如果有根，就正常插入
        {
            root = root -> del(root, n);
        }
    }
    cout << "node:  ";
    root -> print_node(root); //輸出根
    cout << "\nleft:  ";
    root -> print_left(root); //輸出左葉
    cout << "\nright: ";
    root -> print_right(root); //輸出右葉
    return 0;
}
