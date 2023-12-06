/*
Author: B113040052
Date: 2023/11/05
Purpose: 排序演算法執行效率
*/
#include<bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
int n, test_times = 1; //test_times 設定測資測試次數
int num[5000000], temp[5000000]; //紀錄排序好的資料
string file_name = "input.txt"; //讀取的測資檔名

void write_result(string str, string title) //寫出檔案
{
    out.open(str);
    out << title; //放入排序名稱
    for(int i = 0; i < n; i++) //依序寫入
    {
        out << num[i] << endl;
    }
    out.close();
}

void selection_sort(int times) //選擇排序
{
    in.open(file_name);
    in >> n;

    for(int i = 0; i < n; i++) //讀取測資
    {
        in >> num[i];
    }
    for(int i = 0; i < n-1; i++) //選擇排序
    {
        int index = i;
        for(int j = i+1; j < n; j++)
            if(num[j] < num[index])
                index = j;
        swap(num[i], num[index]);
    }
    if(!times)
        write_result("outputA.txt", "Selection Sort\n");
    in.close();
}

void Merge(int left, int right, int mid) //合併排序中的合併
{
    int left_n = left, right_n = mid + 1, index = 0;

    while (left_n <= mid && right_n <= right) //將兩者合併排序
    {
        if (right_n <= right&&num[left_n] > num[right_n])
            temp[index++] = num[right_n++];
        else
            temp[index++] = num[left_n++];
    }

    while (left_n <= mid)
    {
        temp[index++] = num[left_n++];
    }

    while (right_n <= right)
    {
        temp[index++] = num[right_n++];
    }

    for (int i = left; i <= right; i++)
    {
        num[i] = temp[i - left];
    }
}

void Merge_sort(int left, int right) //合併排序中的拆分
{
    if(left < right)
    {

        int mid = (right + left)/2;
        Merge_sort(left, mid);
        Merge_sort(mid+1, right);
        Merge(left, right, mid);
    }
}

void merge_sort(int times) //合併排序的寫入與寫出
{
    in.open(file_name);

    in >> n;

    for(int i = 0; i < n; i++) //寫入測資
    {
        in >> num[i];
    }
    Merge_sort(0, n-1);
    if(!times)
        write_result("outputB.txt", "Merge Sort\n");
    in.close();
}

/*void Quick_sort(int l, int r) //快速排序中的大小分類
{
    if(r > l)
    {
        int mid = (l + r) / 2;
        int pivot = num[mid];
        int i = l;
        int j = r;

        while (i <= j)
        {
            while (num[i] < pivot)
                i++;
            while (num[j] > pivot)
                j--;

            if (i <= j)
            {
                swap(num[i], num[j]);
                i++;
                j--;
            }
        }
        Quick_sort(l, j); //拆分左邊
        Quick_sort(i, r); //拆分右邊
    }
}

void quick_sort(int times) //快速排序的寫入與寫出
{
    in.open(file_name);
    in >> n;
    for(int i = 0; i < n; i++) //寫入測資
    {
        in >> num[i];
    }
    Quick_sort(0, n-1);
    if(!times)
        write_result("outputC.txt", "Quick Sort\n");

    in.close();
}*/

int value_length(int number)
{
    int length = 0;
    while(number)
    {
        length++;
        number /= 10;
    }
    return length;
}

int get_digitcount(int num, int i)
{
    num = num/pow(10, i);
    return num%10;
}

void radix_sort(int times)
{
    int length = 0;
    in.open(file_name);
    in >> n;
    for(int i = 0; i < n; i++)
    {
        in >> num[i];
        length = max(value_length(num[i]), length);
    }
    for(int i = 0; i < length; i++)
    {
        vector<int> v[10];
        int index = 0;
        for(int j = 0; j < n; j++)
        {
            v[get_digitcount(num[j], i)].push_back(num[j]);
        }
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < v[j].size(); k++)
                num[index++] = v[j][k];
    }
    if(!times)
        write_result("outputC.txt", "Radix Sort\n");
    in.close();
}

int cmp(const void* a, const void* b) //C的qsort排序設定
{
    return ( *(int*)a - *(int*)b );
}

void c_qsort(int times) //C的qsort寫入與寫出
{
    in.open(file_name);
    in >> n;
    for(int i = 0; i < n; i++) //測資寫入
        in >> num[i];
    qsort(num, n, sizeof(int), cmp); //呼叫函式
    if(!times)
        write_result("outputD.txt", "qSort\n");

    in.close();
}

void cpp_sort(int times) //C++的sort寫入與寫出
{
    out << "sort function\n";
    in >> n;

    for(int i = 0; i < n; i++) //寫入測資
        in >> num[i];
    sort(num, num+n); //呼叫函式
    if(!times)
        write_result("outputE.txt", "Sort\n");
    in.close();
}

int main() // 主程式
{
    int start = 0;

    cout << "selection sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //選擇排序測試
        selection_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "merge sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //合併排序測試
        merge_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "radix sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //快速排序測試
        radix_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "qsort function\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //qsort測試
        c_qsort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "sort function\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //sort測試
        cpp_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";
    return 0;
}
