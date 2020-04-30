#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 305;
bool passed[N][N];
int boom[N][N];
int dx[4]={1,-1,0,0};
int dy[4] = {0,0,1,-1};
int qx[100005],qy[100005],qt[100005];
int st=0,ed=0;
bool is_end = 0;
int time_end = 0;

void bfs(){
    qx[ed]=0;qy[ed]=0;qt[ed]=0;ed++;
    passed[0][0]=1;
    while(st!=ed){
        int nx=qx[st],ny=qy[st],nt=qt[st];st++;
        for (int i=0;i<=3;i++){
            int nnx=nx+dx[i],nny=ny+dy[i],nnt=nt+1;
            if (nnx<0||nnx>N||nny<0||nny>N)continue;
            if (passed[nnx][nny])continue;
            if (boom[nnx][nny]<=nnt)continue;
            if (boom[nnx][nny]>=1005){
                is_end = 1;
                time_end = nnt;
                return;
            }
            qx[ed]=nnx;qy[ed]=nny;qt[ed]=nnt;ed++;
            passed[nnx][nny]=1;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    memset(passed,0,sizeof(passed));
    memset(boom,0x7f,sizeof(boom));
    while(T--){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        boom[x][y] = min(boom[x][y],t);
        boom[x+1][y] = min(boom[x+1][y],t);
        boom[x][y+1] = min(boom[x][y+1],t);
        if(x>=1)boom[x-1][y] = min(boom[x-1][y],t);
        if(y>=1)boom[x][y-1] = min(boom[x][y-1],t);
    }
    bfs();
    if (is_end)printf("%d\n",time_end);
    else printf("-1\n");
}

