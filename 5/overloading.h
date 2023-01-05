#include<iostream>
using namespace std;
struct node{
	int c;
	int e;
	node* next;
};
struct node* list;
struct node* sorted;
class Set{
	public:
		add(int c, int e){
			struct node* p = new node();
			p -> c = c;
			p -> e = e;
			if(list = NULL){
				p -> next = NULL;
			}
			else{
				p -> next = list;
				cout << list << " " << p -> next << endl; 
			}
			list = p;
		}
		sort(){
			while(list != NULL)
			{
				struct node* p = new node();
				struct node* n = sorted;
				struct node* l = sorted;
				p -> c = list -> c;
				p -> e = list -> e;
				p -> next = NULL;
				if(sorted == NULL){
					sorted = p;
				}
				else{
					while(n != NULL&&p -> e < n -> e)
					{
						l = n;
						n = n -> next;
					}
					if(p -> e == n -> e){
						n -> e += p -> e;
						delete(p);
					}
					else{
						l -> next = p;
						if(n != NULL)p -> next = n;
					}
				}
				n = list;
				list = list -> next;
				delete(n);
			}
		}
		print(){
			while(sorted != NULL)
			{
				cout << sorted -> e << endl;
				sorted = sorted -> next;
			}
		}
		Set operator+(Set input){
			
		}
};
