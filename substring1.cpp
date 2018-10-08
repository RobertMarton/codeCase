#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std  ;

int maxlength(int *a, int length){
    int *pos = (int *)malloc(sizeof(int)*2*length) ;
    pos[2*(length-1)] = 1 ;
    pos[2*length - 1] = length-1 ;
    for(int i =length-2; i>=0; i--){
 
        int nextpos = i ;
        for( int j=i+1; j<length;++j){
        	       int maxlen = 0;
            if(a[j]<a[i]){
                if(pos[2*i]>maxlen){
                    maxlen = pos[2*i] ;
                    nextpos = j ;
                }
            }
            pos[2*i] = maxlen + 1 ;
            cout<<"maxlen:"<<pos[2*i]<<"," ;
            pos[2*i+1] = nextpos ;
        }

        
    }
    for(int i=0;i<length*2;++i){
        cout<<pos[i]<<" " ;
    }
    cout<<"end"<<endl ;
    int maxstart = 0;
    int max  = 0 ;
    for(int i =0; i<length; ++i){
        if (max<pos[2*i]){
            
            max = pos[2*i] ;
            maxstart = i ;
        }
    }
    
    int next = maxstart ;
    do{
        
        cout<<a[next]<<"," ;
        next = pos[2*next+1] ;
    }while(next!=pos[2*next+1]) ;
    cout<<a[next]<<endl ;
    free(pos) ;
    return max ;
}


int main(){
    int a[8] = {9,4,3,2,5,4,3,2} ;
    int len = maxlength(a,8) ;
    return 0 ;
    
}

