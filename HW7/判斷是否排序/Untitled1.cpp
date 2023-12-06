#include<bits/stdc++.h>
using namespace std;
ifstream in;
int n = 5000, input;
void judge(string file_name)
{
    in.open(file_name);
    string sort_name;
    getline(in, sort_name);
    cout << sort_name << endl;
    for(int i = 1; i <= n; i++)
    {
        in >> input;
        if(input != i)
        {
            cout << "wrong at " << i << "\n\n";
            in.close();
            return;
        }
    }
    cout << "correct\n\n";
    in.close();
}
int main()
{
    judge("outputA.txt");
    judge("outputB.txt");
    judge("outputC.txt");
    judge("outputD.txt");
    judge("outputE.txt");
    return 0;
}
