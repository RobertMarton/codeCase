

#include<cstdio>
 
#include<cstring>
 
#include<cstdlib>
#include <iostream>
 
using namespace std;
 
char Stand[100010][10];
 
//建立26个字母对应的数字键,如A-2,B-2,D-3此时Map【0】=2,Map【1】=2,Map【3】=3.即Map的下标为字母在字母表中的序列号,从0开始
 
int Map[]= {2,2,2,3,3,3, 4,4,4, 5,5,5, 6,6,6, 7,-1,7,7, 8,8,8, 9,9,9,-1};
 
 
 
//将PhoneNO转换成标准号码
 
void TransToStand(char* PhoneNO,char* StandNO);
 
//用于qsort字符串排序的比较函数
 
int StrCmp(const void *a, const void *b);
 
int main(void)
 
{
 
//printf("%d", sizeof(Map)/sizeof(int));
    freopen("in.txt","r",stdin) ;
    freopen("out.txt","w", stdout) ;
    int T;
 
    int i;
 
    char Tmp[50];
 
    scanf("%d", &T);
 
    getchar();
 
    for (i=0; i<T; i++)
 
    {
 
        gets(Tmp);
 
        TransToStand(Tmp, Stand[i]);
 
    }

    //     for(int i=0; i<T; i++){
    //     cout<<Stand[i]<<endl ;
    // }
    qsort(Stand, T, sizeof(Stand[0]), StrCmp);
 
 
    int Cnt = 1;//当前相同标准号码的数量
 
    bool IsDuplicate = false;
 
    strcpy(Stand[T], "");
 
    for (i=0; i<T; i++)
 
    {
 
        if (strcmp(Stand[i], Stand[i+1]) == 0)
 
        {
 
            Cnt++;
 
        }
 
        else
 
        {
 
            if (Cnt > 1)
 
            {
 
                printf("%s %d\n", Stand[i], Cnt);
 
                IsDuplicate = true;
 
            }
 
            Cnt = 1;
 
        }
 
    }
 
    if (!IsDuplicate)
 
    {
 
        printf("No duplicates.\n");
 
    }
 
    return 0;
 
}
 
//将PhoneNO转换成标准号码
 
void TransToStand(char* PhoneNO,char* StandNO)
 
{
 
    int i,j=0;
 
    int Len = strlen(PhoneNO);
 
    StandNO[3] = '-';
 
    StandNO[8] = '\0';
 
    for (i=0; i<Len; i++)
 
    {
 
        if (PhoneNO[i] >= '0' && PhoneNO[i] <= '9')//是数字则直接转换
 
        {
 
            StandNO[j] = PhoneNO[i];
 
            j++;
 
            if (3 == j)
 
            {
 
                j++;
 
            }
 
            else if (8 == j)
 
            {
 
                return ;
 
            }
 
        }
 
        else if (PhoneNO[i] >= 'A' && PhoneNO[i] <= 'Z')
 
        {
 
            StandNO[j] = Map[PhoneNO[i] - 'A'] + '0';
 
            j++;
 
            if (3 == j)
 
            {
 
                j++;
 
            }
 
            else if (8 == j)
 
            {
 
                return ;
 
            }
 
        }
 
    }
 
}
 
//用于qsort字符串排序的比较函数
 
int StrCmp(const void *a, const void *b)
 
{
 
    return strcmp((char*)a, (char*)b);
 
}