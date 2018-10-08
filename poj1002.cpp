#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std ;

char output[100010][10] ;//char output[1000][10]//数组开小会超时！！
int Map[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1} ;
void trans(char *str,char *output) ;
int Strcmp(const void *a, const void *b) ;
int main(void){
	// freopen("in.txt","r",stdin) ;
	// freopen("out.txt","w", stdout) ;
	int T ;
	scanf("%d",&T) ;
	getchar() ;
	char Tmp[50] ;
	for(int i=0; i<T;i++){
		gets(Tmp);
		trans(Tmp,output[i]) ;

	}

	int tmp = 1 ;
	bool flag = false ;
	// for(int i=0; i<T; i++){
	// 	cout<<output[i]<<endl ;
	// }	
		qsort(output,T,sizeof(output[0]),Strcmp) ;


		strcpy(output[T],"");
	for(int i=0 ;i<T; i++){
		if(strcmp(output[i],output[i+1])==0)
			{
			tmp++ ;}
		else {
			if(tmp>1){
				printf("%s %d\n", output[i],tmp) ;
				flag = true ;
			}
			tmp = 1 ;
		}
	}
	if(flag==false)
		printf("No duplicates.\n") ;
	return 0 ;

}
void trans(char *str, char *output){
	int j = 0;
	output[3] = '-' ;
	output[8] = '\0' ;
	for(int i =0; i<strlen(str); i++){

		if(str[i]>='0'&& str[i]<='9'){
			output[j]=str[i] ;
			j++ ;
			if(j==3)
				j++ ;
			else if(j==8) 
				return ;
		}
		else if(str[i]>='A'&&str[i]<='Z'){
			output[j] = Map[str[i]-'A'] + '0' ;
			j++ ;
			if(j==3)
				j++ ;
			else if(j==8) 
				return ;
		}
	}
}

int Strcmp(const void *a, const void *b){
	return strcmp((char*)a, (char*)b) ;
}
