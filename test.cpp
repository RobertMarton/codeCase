#include <iostream>
#include <cstring>
int get_maxlen(const char *str){
    
    const char * current=str;
    int max_len=1;
    int temp_len=1;
    
    while(*current){
        //奇数长度对称字符串处理
        const char * begin=current-1;
        const char * end=current+1;
        while(begin>=str && *end && *begin==*end){
            begin--;
            end++;
        }
        temp_len=end-begin-1;
        if(temp_len>max_len)
            max_len=temp_len;
        //偶数长度对称字符串处理
        begin=current;
        end=current+1;
        while(begin>=str && *end && *begin==*end){
            begin--;
            end++;
        }
        temp_len=end-begin-1;
        if(temp_len>max_len)
            max_len=temp_len;
        current++;
    }
    return max_len;
}
int main()
{
    const char * str="googleaelg";
    int ret = get_maxlen(str);
    std::cout<<ret<<std::endl;
    return 0;
}