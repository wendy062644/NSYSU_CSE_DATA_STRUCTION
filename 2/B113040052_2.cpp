#include <iostream>
#include <string.h>
#include"overloading.h"

using namespace std;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 0; n > i; i++)
	{
		char input1[80], input2[80], x;
		cin.getline(input1, 80);
		cin.getline(input2, 80);
		TSet a(input1), b(input2), c, d, e, f;
		c = a + b;
		d = a * b;
		e = a - b;
		f = b - a;
		cin >> x;
		cin.ignore();
		printf("Test Case %d:\n", i+1);
		cout << "A:{";
		for(int i = 0; 256 > i; i++)
		{
			if(a.B[i]){cout << (char)i;}
		}
		cout << "}\n" << "B:{";
		for(int i = 0; 256 > i; i++)
		{
			if(b.B[i]){cout << (char)i;}
		}
		cout << "}\n" << "A+B:{";
		for(int i = 0; 256 > i; i++)
		{
			if(c.B[i]){cout << (char)i;}
		}
		cout << "}\n" << "A*B:{";
		for(int i = 0; 256 > i; i++)
		{
			if(d.B[i]){cout << (char)i;}
		}
		cout << "}\n" << "A-B:{";
		for(int i = 0; 256 > i; i++)
		{
			if(e.B[i]){cout << (char)i;}
		}
		cout << "}\n" << "B-A:{";
		for(int i = 0; 256 > i; i++)
		{
			if(f.B[i]){cout << (char)i;}
		}
		cout << "}\n";
		for(int i = 0; 256 > i; i++)
		{
			if(b.B[i] == 1&&a.B[i] == 0){
				cout << "A does not contain B" << endl;
				break;
			}
			else if(i == 255){
				cout << "A contains B" << endl; 
			}
		}
		for(int i = 0; 256 > i; i++)
		{
			if(a.B[i] == 1&&b.B[i] == 0){
				cout << "B does not contain A" << endl;
				break;
			}
			else if(i == 255){
				cout << "B contains A" << endl; 
			}
		}
		if(a.B[x]){printf("'%c' is in A\n", x);}
		else{printf("'%c' is not in A\n", x);}
		if(b.B[x]){printf("'%c' is in B\n\n", x);}
		else{printf("'%c' is not in B\n\n", x);}
	}
}
