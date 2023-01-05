#include<iostream>
using namespace std;

struct node{
	int c, e;
	struct node *next;
};

class Poly{
	public:
		struct node *list = NULL;
		struct node *sorted = NULL;
		add(int c, int e){
			struct node *p = new node();
			p -> c = c;
			p -> e = e;
			if(list == NULL){
				p -> next = NULL;
			}
			else{
				p -> next = list;
			}
			list = p;
		}
		sort(){
			while(list != NULL)
			{
				struct node *p = new node();
				p -> c = list -> c;
				p -> e = list -> e;
				if(sorted == NULL){
					sorted = p;
					sorted -> next = NULL;
				}
				else{
					struct node *n = sorted;
					struct node *t = sorted;
					while(n -> next != NULL&&n -> e > list -> e){
						t = n;
						n = n -> next;
					}
					if(n -> e > list -> e)
					{
						t = n;
						n = n -> next;
					}
					if(n != NULL&&n -> e == list -> e)
					{
						n -> c += list -> c;
						if(n -> c == 0)
						{
							if(t != n)t -> next = n -> next;
							else{
								sorted = NULL;
							}
							delete(n);
						}
					}
					else if(n == NULL){
						t -> next = p;
						p -> next = NULL;
					}
					else if(n == sorted)
					{
						p -> next = n;
						sorted = p;
					}
					else{
						t -> next = p;
						p -> next = n;
					}
				}
				struct node *t = list;
				list = list -> next;
				delete(t);
			}
		}
		Poly operator+(const Poly B){
			Poly C;
			struct node *p = sorted;
			while(p != NULL)
			{
				C.add(p -> c, p -> e);
				p = p -> next;
			}
			p = B.sorted;
			while(p != NULL)
			{
				C.add(p -> c, p -> e);
				p = p -> next;
			}
			return C;
		}
		print(){
			if(sorted == NULL){cout << "0 0" << endl;}
			while(sorted != NULL)
			{
				cout << sorted -> c << " " << sorted -> e << endl;
				sorted = sorted -> next;
			}
		}
};

int main(){
	int n, q, c, e, t = 0;
	while(cin >> n)
	{
		t++;
		Poly A, B, C, D;
		for(int i = 0; n > i; i++)
		{
			cin >> c >> e;
			A.add(c, e);
		}
		cin >> q;
		for(int i = 0; q > i; i++)
		{
			cin >> c >> e;
			B.add(c, e);
		}
		if(q == 0&&n == 0){break;}
		A.sort();
		B.sort();
		C = A + B;
		C.sort();
		cout << "Case" << t << ":" << endl << "ADD" << endl;
		C.print();
		cout << "MULTIPLY" << endl;
	}
	
} 
