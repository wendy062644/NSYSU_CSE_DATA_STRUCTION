#include <bits/stdc++.h>
using namespace std;
ofstream out;
void random_data(int Case, int n)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    out.open(to_string(Case)+".txt");
    out << n << endl;
    vector<int> num;
    for(int i = 1; i <= n; i++)
    {
        num.push_back(i);
    }
    random_device rd;
    mt19937 generator(rd());
    shuffle(num.begin(), num.end(), generator);
    for(int i = 0; i < n; i++)
    {
        out << num[i] << ' ';
    }
    out.close();
}
int main()
{
    int data[2] = {100, 500};
    for(int i = 0; i < 10; i++)
    {
        random_data(i, data[i%2]*pow(10, i/2));
        cout << "Case " << i << " finish" << endl;
    }
    return 0;
}
