#include <iostream>
#include <cstring>
using namespace std ;
void swap(string &a,string &b){
	string tmp = a ;
	a = b ;
	b = tmp ;
}
string proc(string str){
	int start = 0 ;
	int end = str.length() - 1 ;
	for(;start<end; ){

		while(str[start]>='a' && str[start]<='z' &&start<end)
			start++ ;

		
			while(str[end]>='A'&&str[end]<='Z' &&start<end)
				end-- ;
		

				swap(str[start], str[end]) ;
			
		
	}

	return str ;

}

int main(){
	string a = "FFasdfG" ;
	string s = proc(a); 
	cout<<s<<endl ;
}