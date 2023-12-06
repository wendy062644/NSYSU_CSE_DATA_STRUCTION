//Author: B113040052
//Date: 2023/09/22
//Purpose: binary tree������
#include<bits/stdc++.h>
using namespace std;

class node{ //�I
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

int node::right_subtree(node *root) //��right subtree��value
{
    if(root -> left != nullptr)
        return right_subtree(root -> left);
    else{
        int n = root -> value;
        return n;
    }
}

node* node::del(node* root, int n) //�R���ۦP���I
{
    if(n > root -> value) //�j��value�A���k��
        root -> right = del(root -> right, n);
    else if(n < root -> value) //�p��value�A������
        root -> left = del(root -> left, n);
    else //����value�A���F
    {
        node *Right = root -> right, *Left = root -> left;
        if(Right != nullptr&&Left != nullptr) //�p�G��2��child
        {
            int temp = right_subtree(root -> right); //��right subtree��
            root -> value = temp; //�N�I��s��right subtree���̥�����
            root -> right = del(root -> right, temp); //�N��k�䪺�I��s�A�ϥλ��j�A�]���⨫���I�i��]��2��child
        }
        else if(Right != nullptr) //�p�G�u���k��
        {
            delete root;
            return Right;
        }
        else if(Left != nullptr) //�p�G�u������
        {
            delete root;
            return Left;
        }
        else //�p�G���S��child�A�i�����R��
        {
            delete root;
            return nullptr;
        }
    }
    return root; //value������n�A�����^��
}

bool node::add_node(node* p, int n) //�s�W�I
{
    while(p -> value != n) //���A�X����m
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
    if(p -> value == n) //�P�_���S������
        return 1;
    else
    {
        if(n > p -> value)
            p -> right = new node(n); //�s�W�b�k��
        else
            p -> left = new node(n); //�s�W�b����
    }
    return 0;
}

void node::print_node(node* root) //��X�ڪ����p�A�ϥλ��j
{
    if(root -> left != nullptr)
        print_node(root -> left);
    cout << setw(3) << root -> value << " ";
    if(root -> right != nullptr)
        print_node(root -> right);
}

void node::print_left(node* root) //��X���䪺���p�A�ϥλ��j
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

void node::print_right(node* root) //��X�k�䪺���p�A�ϥλ��j
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

void each_case()
{
    int n;
    node *root = nullptr; //�]�w�ڪ�l��
    while(cin >> n)
    {
        if(n == -1) //�P�_�O�_����
            break;
        if(root == nullptr) //�P�_�O�_����
            root = new node(n);
        else if(root -> add_node(root, n)) //�p�G���ڡA�N���`���J
        {
            root = root -> del(root, n);
        }
    }
    cout << "node:  ";
    root -> print_node(root); //��X��
    cout << "\nleft:  ";
    root -> print_left(root); //��X����
    cout << "\nright: ";
    root -> print_right(root); //��X�k��
    cout << endl;
}

int main()
{
    while(1)
    {
        each_case();
    }
    return 0;
}
