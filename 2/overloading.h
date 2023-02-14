#ifndef OVERLOADING_H
#define OVERLOADING_H
#include<string.h>
using namespace std;
class TSet{
	public:
		bool B[256] = {0};
		TSet(){
		}
		TSet(const char input[]){
			for(int i = 0; strlen(input) > i; i++){
				B[input[i]] = 1;
			}
		}
		TSet operator+(const TSet &b){
			TSet c;
			for(int i = 0; 256 > i; i++)
			{
				if(B[i] == 1||b.B[i] == 1)
				{
					c.B[i] = 1;
				}
			}
			return c;
		}
		TSet operator-(const TSet &b){
			TSet c;
			for(int i = 0; 256 > i; i++)
			{
				if(B[i] == 1&&b.B[i] == 0)
				{
					c.B[i] = 1;
				}
			}
			return c;
		}
		TSet operator*(const TSet &b){
			TSet c;
			for(int i = 0; 256 > i; i++)
			{
				if(B[i] == 1&&b.B[i] == 1)
				{
					c.B[i] = 1;
				}
			}
			return c;
		}
		TSet operator>=(const TSet &b){

		}
};
#endif
