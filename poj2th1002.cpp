#include <iostream>
#include <cstring>
using namespace std ;
int data[100005] ;
char str[300] ;
int f[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9} ;
void Get(char str[], int k){
	int id = 0, num = 0 ;
	for(int i=0; id<7; i++){
		if (isdigit(str[i])) 
			num = num*10+str[i]-'0', id++ ;
		else if (isupper(str[i]))
			num = num*10+f[str[i]-'A'], id++ ;
	}
	 data[k] = num ;
}
int main(){
	freopen("in.txt","r",stdin) ;
	freopen("out.txt","w", stdout) ;
	int n ,i ;
	scanf("%d",&n) ;
	// string str ;
	for(int i=0; i<n; i++){
		scanf("%s",str) ;
		Get(str,i) ;
	}
	
	sort(data,data+n) ;
	bool flag = true ;
	int p = data[0] ,tmp = 1;
	for(i=0; i<n; i++){
		if (p==data[i] && i!=0) 
		{
			flag = false ;
			tmp++ ;
		}
		else {
			if(tmp>1)
			printf("%03d-%04d %d\n",p/10000,p%10000,tmp) ;
			p = data[i] ;
			tmp = 1 ;
		}

	}



	if(tmp>1){
		printf("%03d-%04d %d\n",p/10000,p%10000,tmp) ;
	}
	if(flag){
		printf("No duplicates.\n") ;
	}

}