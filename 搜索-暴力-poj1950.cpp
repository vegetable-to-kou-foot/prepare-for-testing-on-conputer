#include <stdio.h>
#include <iostream>
using namespace std;

int N,cnt;
char ch[20];

__int64 add(__int64 sum,char op,__int64 tmp){
    if (op=='+'){
        return sum+tmp;
    }else{
        return sum-tmp;
    }
}

void solve(int deep,__int64 sum,char op,__int64 tmp){
    if (deep >= N){
        __int64 sum_tmp = add(sum,op,tmp);
        if (sum_tmp==0){
            cnt++;
            if (cnt>20){
                return;
            }
            for (int i=1;i<=N-1;i++){
                printf("%d %c ",i,ch[i]);
            }
            printf("%d\n",N);
        }
        return;
    }

    ch[deep] = '+';
    solve(deep+1,add(sum,op,tmp),'+',deep+1);
    ch[deep] = '-';
    solve(deep+1,add(sum,op,tmp),'-',deep+1);
    ch[deep] = '.';
    if (deep+1<=9)
        solve(deep+1,sum,op,tmp*10+deep+1);
    else
        solve(deep+1,sum,op,tmp*100+deep+1);
    ch[deep] = 0;
}

int main(){
    while(scanf("%d",&N)!=EOF&&N){
        cnt = 0;
        fill(ch,ch+20,0);
        solve(1,0,'+',1);
        printf("%d\n",cnt);
    }
    return 0;
}

