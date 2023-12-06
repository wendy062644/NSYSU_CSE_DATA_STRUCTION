/*
Author: B113040052
Date: 2023/11/24
Purpose: Huffman 壓縮練習
*/
#include<bits/stdc++.h>
using namespace std;
map<int, string> encode; //紀錄編碼
ofstream out;

class node{ //Huffman Tree 點
    private:
        int data; //紀錄資料內容
        int number = 0; //紀錄出現次數
        node* left;
        node* right;
    public:
        node(int d, int n) //建立點
        {
            data = d;
            number = n;
            right = nullptr;
            left = nullptr;
        }
        node(node* a, node* b, int n, int d) //建立點
        {
            left = a;
            right = b;
            number = n;
            data = d;
        }
        int Number(){ //讀取次數
            return number;
        }
        char Data(){ //讀取資料內容
            return data;
        }
        void view_tree(node* root, string str);
};

node* tree_root; //huffman tree root

bool cmp(pair<int, int> a, pair<int, int> b){ //排序設定
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

void node::view_tree(node* root, string str) //跑一遍樹的內容
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

void compress(string input_file, string output_file) //壓縮
{
    ifstream in (input_file.c_str(), ios::binary); //讀檔案
    out.open(output_file); //寫檔案
    string after_compress = ""; //紀錄壓縮後的資料內容
    in.seekg(0, ios::end); //資料最尾部
    int length =in.tellg(); //計算資料長度
    in.seekg(0, ios::beg); //資料最前面
    char str[length];
    in.read(str, length); //讀取檔案內的資料
    vector<pair<int, int>>data(512); //紀錄資料及出現次數
    vector<pair<int, int>>temp; //排序用
    vector<node*> tree; //建立huffman tree用
    for (int i = 0; i < 512; i++) { //歸零
        data[i] = {i, 0};
    }
    for(int i = 0; i < length; i++){ //計算出現次數
        data[str[i]+256].second++;
    }
    for(int i = 0; i < 512; i++) //過濾未出現的資料
    {
        if(data[i].second > 0)
        {
            temp.push_back(data[i]);
        }
    }
    sort(temp.begin(), temp.end(), cmp); //排序
    for(int i = 0; i < temp.size(); i++) //將資料放入vector中
    {
        node *p = new node(temp[i].first, temp[i].second);
        tree.push_back(p);
    }
    while(tree.size() > 1) //判斷vector內是否還有資料未放入樹中
    {
        node *p;
        if(tree[0] -> Data() > tree[1] -> Data()) //判斷哪個放左邊
            p = new node(tree[1], tree[0], tree[0] -> Number() + tree[1] -> Number(), tree[1] -> Data());
        else
            p = new node(tree[0], tree[1], tree[0] -> Number() + tree[1] -> Number(), tree[0] -> Data());
        for(int i = 0; i < tree.size()-1; i++) //將新的點插入對應位置
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
        tree.erase(tree.begin()); //刪除已建立的點
        tree.erase(tree.begin());
    }
    tree_root = tree[0];
    tree_root -> view_tree(tree_root, "");
    for(int i = 0; i < length; i++) //將壓縮後的資料產出
    {
        after_compress += encode[str[i]+256];
    }
    cout << "壓縮前/後: " << length * 8 << '/' << after_compress.size() << " bits 壓縮率: " << (double)after_compress.size()/length/8*100 << "%\n";
    out << "壓縮前/後: " << length * 8 << '/' << after_compress.size() << " bits 壓縮率: " << (double)after_compress.size()/length/8*100 << "%\n";
    for(auto item : encode) //將對應的表存入檔案內
    {
        out << char(item.first-256) << '=' << item.second << endl;
    }

    out << endl << after_compress << endl; //將壓縮後的內容放入檔案

    in.close(); //關閉檔案
    out.close();
}

void decompress(string input_file, string output_file) //解壓縮
{
    ifstream in(input_file); //讀取檔案
    map<string, char> decode; //紀錄壓縮的資料表
    out.open(output_file); //讀取檔案
    string str, key, temp;
    char value;
    getline(in, str); //temp
    while(getline(in, str)) //讀取壓縮的資料表
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
    for(int i = 0; i < str.size(); i++) //將壓縮後的代碼解壓縮
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
    in.close(); //關閉檔案
    out.close();
}

int main(int argc, char* argv[]) {
    if (argc < 7) { //判斷輸入資料是否正確
        cerr << "Usage: " << argv[0] << " -c/-u -i input_file -o output_file" << endl;
        return 1;
    }
    string mode = argv[2]; //紀錄壓縮或解壓縮
    string input_file = argv[4]; //紀錄寫入檔案
    string output_file = argv[6]; //紀錄寫出檔案

    if (mode == "-c") { //判斷壓縮
        compress(input_file, output_file);
    } else if (mode == "-u") { //解壓縮
        decompress(input_file, output_file);
    } else { //錯誤
        cerr << "Invalid mode. Use -c for compression or -u for decompression." << endl;
        return 1;
    }
    return 0;
}
