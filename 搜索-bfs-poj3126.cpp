#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int N = 10005;
bool prime[N];
int a,b;
int qd[10005],qt[10005];
int st,ed;
bool is_end = 0;
int time_end = 0;
int passed[N];

int mypow(int p){
    switch(p){
        case 0:return 1;
        case 1:return 10;
        case 2:return 100;
        case 3:return 1000;
        default:return 0;
    };
}

void bfs(){
    qd[ed]=a;qt[ed]=0;ed++;
    passed[a] = 1;
    while(st!=ed){
        int n=qd[st],t=qt[st];st++;
        if (n==b){
            is_end = 1;
            time_end = t;
            return;
        }
        for (int i=0;i<=3;i++){
            for (int j=0;j<=9;j++){
                int tmp = (n/mypow(i))%10;
                int nn = n-(tmp-j)*mypow(i);
                int nt = t+1;
                if (nn<1000||nn>=10000)continue;
                if (passed[nn])continue;
                if (!prime[nn])continue;
                qd[ed]=nn;qt[ed]=nt;ed++;
                passed[nn] = n;

            }
        }
    }

}

void init(){
    fill(prime,prime+N,true);
    for (int i=2;i<=N;i++){
        if (!prime[i])continue;
        for (int j=2;j*i<=N;j++)
            prime[j*i] = false;
    }
}

int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d%d",&a,&b);
        is_end = 0;
        time_end = 0;
        fill(qd,qd+10005,0);
        fill(qt,qt+10005,0);
        fill(passed,passed+N,0);
        bfs();
        if (is_end){
            printf("%d\n",time_end);
//            int tmp = b;
//            while(tmp != a){
//                printf("%d ",tmp);
//                tmp = passed[tmp];
//            }
//            printf("%d\n",a);
        }
        else printf("Impossible\n");
    }
}

