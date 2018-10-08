#include <iostream>
using namespace std ;
int subString(const char *str){
    // cout<<str<<endl ;
    const char *current = str ;
    int maxlen = 1;
    int len = 1 ;
    while(*current){
        const char *begin = current-1 ;
        
        const char *end = current+1 ;
        while(*begin==*end && begin>=str && *end){
            begin-- ;
            end++ ;
        }
        len = end-begin-1 ;
        if(maxlen < len){
            maxlen = len ;
        }
        begin = current ;
        end = current + 1 ;
        while(*begin==*end&& begin>=str&&*end){
            begin-- ;
            end++ ;
        }
        len = end-begin-1 ;
        if(maxlen < len){
            maxlen = len ;
        }
        current++ ;

    }
    return maxlen ;

}



int main(){
    const char * str = "google" ;
    int tep = subString(str) ; 
    cout<<tep<<endl ;
    return 0 ;
}