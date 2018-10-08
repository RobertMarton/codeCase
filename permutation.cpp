#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std ;
class Solution{
public:
    vector<string> permutation(string str){
        vector<string> res ;
        if(str.empty()) return res ;
        permutation(res,str,0) ;
        sort(res.begin(),res.end()) ;
        return res ;
    }
    
    void permutation(vector<string> &array,string str,int begin){
        if(begin == str.size()-1) {
            array.push_back(s) ;
        }
        for(int i=0; i<str.size(); i++){
            int begin = i ;
            if(i!=begin&&str[i]==str[begin]) continue ;
            swap(str[i],str[begin]) ;
            permutation(s,str,begin+1) ;
            swap(str[i],str[begin]) ;
        }
    }
    
} ;

int main(){
//    cout<<"sfsdf"<<endl ;
    string a = "abc";
    Solution tmp ;
    vector<string> tar ;
    tar = tmp.permutation(a) ;
    for (int i=0; i<tar.size();i++){
        cout<<tar[i]<<endl ;
    }
    return 0 ;
}
