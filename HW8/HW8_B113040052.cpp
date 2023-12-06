/*
Author: B113040052
Date: 2023/11/24
Purpose: Huffman ���Y�m��
*/
#include<bits/stdc++.h>
using namespace std;
map<int, string> encode; //�����s�X
ofstream out;

class node{ //Huffman Tree �I
    private:
        int data; //������Ƥ��e
        int number = 0; //�����X�{����
        node* left;
        node* right;
    public:
        node(int d, int n) //�إ��I
        {
            data = d;
            number = n;
            right = nullptr;
            left = nullptr;
        }
        node(node* a, node* b, int n, int d) //�إ��I
        {
            left = a;
            right = b;
            number = n;
            data = d;
        }
        int Number(){ //Ū������
            return number;
        }
        char Data(){ //Ū����Ƥ��e
            return data;
        }
        void view_tree(node* root, string str);
};

node* tree_root; //huffman tree root

bool cmp(pair<int, int> a, pair<int, int> b){ //�Ƨǳ]�w
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void node::view_tree(node* root, string str) //�]�@�M�𪺤��e
{
    if(root == nullptr)
        return;
    view_tree(root -> left, str+"0");
    view_tree(root -> right, str+"1");
    if(root -> right == nullptr&&root -> left == nullptr)
    {
        encode[root -> data] = str;
    }

}

void compress(string input_file, string output_file) //���Y
{
    ifstream in (input_file.c_str(), ios::binary); //Ū�ɮ�
    out.open(output_file); //�g�ɮ�
    string after_compress = ""; //�������Y�᪺��Ƥ��e
    in.seekg(0, ios::end); //��Ƴ̧���
    int length =in.tellg(); //�p���ƪ���
    in.seekg(0, ios::beg); //��Ƴ̫e��
    char str[length];
    in.read(str, length); //Ū���ɮפ������
    vector<pair<int, int>>data(512); //������ƤΥX�{����
    vector<pair<int, int>>temp; //�Ƨǥ�
    vector<node*> tree; //�إ�huffman tree��
    for (int i = 0; i < 512; i++) { //�k�s
        data[i] = {i, 0};
    }
    for(int i = 0; i < length; i++){ //�p��X�{����
        data[str[i]+256].second++;
    }
    for(int i = 0; i < 512; i++) //�L�o���X�{�����
    {
        if(data[i].second > 0)
        {
            temp.push_back(data[i]);
        }
    }
    sort(temp.begin(), temp.end(), cmp); //�Ƨ�
    for(int i = 0; i < temp.size(); i++) //�N��Ʃ�Jvector��
    {
        node *p = new node(temp[i].first, temp[i].second);
        tree.push_back(p);
    }
    while(tree.size() > 1) //�P�_vector���O�_�٦���ƥ���J��
    {
        node *p;
        if(tree[0] -> Data() > tree[1] -> Data()) //�P�_���ө���
            p = new node(tree[1], tree[0], tree[0] -> Number() + tree[1] -> Number(), tree[1] -> Data());
        else
            p = new node(tree[0], tree[1], tree[0] -> Number() + tree[1] -> Number(), tree[0] -> Data());
        for(int i = 0; i < tree.size()-1; i++) //�N�s���I���J������m
        {
            if(tree[i+1] -> Number() >= p -> Number())
            {
                tree.insert(tree.begin()+i+1, 1, p);
                break;
            }
            else if(i == tree.size()-2)
            {
                tree.push_back(p);
                break;
            }
        }
        tree.erase(tree.begin()); //�R���w�إߪ��I
        tree.erase(tree.begin());
    }
    tree_root = tree[0];
    tree_root -> view_tree(tree_root, "");
    for(int i = 0; i < length; i++) //�N���Y�᪺��Ʋ��X
    {
        after_compress += encode[str[i]+256];
    }
    cout << "���Y�e/��: " << length * 8 << '/' << after_compress.size() << " bits ���Y�v: " << (double)after_compress.size()/length/8*100 << "%\n";
    out << "���Y�e/��: " << length * 8 << '/' << after_compress.size() << " bits ���Y�v: " << (double)after_compress.size()/length/8*100 << "%\n";
    for(auto item : encode) //�N��������s�J�ɮפ�
    {
        out << char(item.first-256) << '=' << item.second << endl;
    }

    out << endl << after_compress << endl; //�N���Y�᪺���e��J�ɮ�

    in.close(); //�����ɮ�
    out.close();
}

void decompress(string input_file, string output_file) //�����Y
{
    ifstream in(input_file); //Ū���ɮ�
    map<string, char> decode; //�������Y����ƪ�
    out.open(output_file); //Ū���ɮ�
    string str, key, temp;
    char value;
    getline(in, str); //temp
    while(getline(in, str)) //Ū�����Y����ƪ�
    {
        if(str == "")
            break;
        key = "";
        value = str[0];
        for(int i = 2; i < str.size(); i++)
        {
            key += str[i];
        }
        decode[key] = value;
    }
    in >> str;
    key = "";
    for(int i = 0; i < str.size(); i++) //�N���Y�᪺�N�X�����Y
    {
        if(decode[key])
        {
            out << decode[key];
            key = str[i];
        }
        else
        {
            key += str[i];
        }
    }
    out << decode[key];
    in.close(); //�����ɮ�
    out.close();
}

int main(int argc, char* argv[]) {
    if (argc < 7) { //�P�_��J��ƬO�_���T
        cerr << "Usage: " << argv[0] << " -c/-u -i input_file -o output_file" << endl;
        return 1;
    }
    string mode = argv[2]; //�������Y�θ����Y
    string input_file = argv[4]; //�����g�J�ɮ�
    string output_file = argv[6]; //�����g�X�ɮ�

    if (mode == "-c") { //�P�_���Y
        compress(input_file, output_file);
    } else if (mode == "-u") { //�����Y
        decompress(input_file, output_file);
    } else { //���~
        cerr << "Invalid mode. Use -c for compression or -u for decompression." << endl;
        return 1;
    }
    return 0;
}
