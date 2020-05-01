#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int MOD = 3333331;
int a[7],p[7];
int val[MOD],f[MOD],Next[MOD],Last[MOD],nn=1,lim;
int cnt;
int N,M;

void Add(int x){
    int w = abs(x)%MOD;
    for (int i = Last[w];i;i = Next[i]){
        if (val[i]==x){
            f[i]++;
            return;
        }
    }
    val[nn]=x;
    f[nn]=1;
    Next[nn]=Last[w];
    Last[w]=nn;
    nn++;
}

int Get(int x){
    int w = abs(x)%MOD;
    for (int i=Last[w];i;i=Next[i])
        if (val[i]==x)
            return f[i];
    return 0;
}

int pp(int b,int e){
    return int(pow(b,e)+0.5);
}

void right_dfs(int deep,int sum){
    if (deep <= lim){
        cnt += Get(-sum);
        return;
    }
    for (int i=1;i<=M;i++)
        right_dfs(deep-1,sum+a[deep]*pp(i,p[deep]));
}

void left_dfs(int deep,int sum){
    if (deep > lim){
        Add(sum);
        return;
    }
    for (int i=1;i<=M;i++)
        left_dfs(deep+1,sum+a[deep]*pp(i,p[deep]));
}

int main(){
    scanf("%d%d",&N,&M);
    for (int n=1;n<=N;n++)
        scanf("%d%d",&a[n],&p[n]);

    lim = N/2;

    left_dfs(1,0);
    right_dfs(N,0);

    printf("%d\n",cnt);
}

