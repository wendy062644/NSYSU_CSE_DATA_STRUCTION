/*
Author: B113040052
Date: 2023/11/05
Purpose: �ƧǺt��k����Ĳv
*/
#include<bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
int n, test_times = 1; //test_times �]�w������զ���
int num[5000000], temp[5000000]; //�����ƧǦn�����
string file_name = "input.txt"; //Ū���������ɦW

void write_result(string str, string title) //�g�X�ɮ�
{
    out.open(str);
    out << title; //��J�ƧǦW��
    for(int i = 0; i < n; i++) //�̧Ǽg�J
    {
        out << num[i] << endl;
    }
    out.close();
}

void selection_sort(int times) //��ܱƧ�
{
    in.open(file_name);
    in >> n;

    for(int i = 0; i < n; i++) //Ū������
    {
        in >> num[i];
    }
    for(int i = 0; i < n-1; i++) //��ܱƧ�
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

void Merge(int left, int right, int mid) //�X�ֱƧǤ����X��
{
    int left_n = left, right_n = mid + 1, index = 0;

    while (left_n <= mid && right_n <= right) //�N��̦X�ֱƧ�
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

void Merge_sort(int left, int right) //�X�ֱƧǤ������
{
    if(left < right)
    {

        int mid = (right + left)/2;
        Merge_sort(left, mid);
        Merge_sort(mid+1, right);
        Merge(left, right, mid);
    }
}

void merge_sort(int times) //�X�ֱƧǪ��g�J�P�g�X
{
    in.open(file_name);

    in >> n;

    for(int i = 0; i < n; i++) //�g�J����
    {
        in >> num[i];
    }
    Merge_sort(0, n-1);
    if(!times)
        write_result("outputB.txt", "Merge Sort\n");
    in.close();
}

/*void Quick_sort(int l, int r) //�ֳt�ƧǤ����j�p����
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
        Quick_sort(l, j); //�������
        Quick_sort(i, r); //����k��
    }
}

void quick_sort(int times) //�ֳt�ƧǪ��g�J�P�g�X
{
    in.open(file_name);
    in >> n;
    for(int i = 0; i < n; i++) //�g�J����
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

int cmp(const void* a, const void* b) //C��qsort�Ƨǳ]�w
{
    return ( *(int*)a - *(int*)b );
}

void c_qsort(int times) //C��qsort�g�J�P�g�X
{
    in.open(file_name);
    in >> n;
    for(int i = 0; i < n; i++) //����g�J
        in >> num[i];
    qsort(num, n, sizeof(int), cmp); //�I�s�禡
    if(!times)
        write_result("outputD.txt", "qSort\n");

    in.close();
}

void cpp_sort(int times) //C++��sort�g�J�P�g�X
{
    out << "sort function\n";
    in >> n;

    for(int i = 0; i < n; i++) //�g�J����
        in >> num[i];
    sort(num, num+n); //�I�s�禡
    if(!times)
        write_result("outputE.txt", "Sort\n");
    in.close();
}

int main() // �D�{��
{
    int start = 0;

    cout << "selection sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //��ܱƧǴ���
        selection_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "merge sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //�X�ֱƧǴ���
        merge_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "radix sort\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //�ֳt�ƧǴ���
        radix_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "qsort function\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //qsort����
        c_qsort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";

    cout << "sort function\n";
    start = clock();
    for(int i = 0; i < test_times; i++) //sort����
        cpp_sort(i);
    cout << "Average time spent is " << (clock()-start)/1000.0/test_times << "s\n\n";
    return 0;
}
