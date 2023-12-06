#include<bits/stdc++.h>
using namespace std;

struct node{
    node* Right;
    node* Left;
    int number;
    char data;
};

int main()
{
    string str;
    cin >> str;
    int n[26] = {0};
    for(int i = 0; i < str.length(); i++)
    {
        n[str[i]-'A']++;
    }
    return 0;
}
