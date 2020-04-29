#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

long long int target;
long long int base[30][6];
int op[30];

int solve(int deep,vector<int> ch,long long int ans){
	if (deep>=6){
//	    for (vector<int>::const_iterator iter = ch.cbegin();iter != ch.cend();iter++){
//                printf("%c ",(*iter)+'A'-1);
//			}
//        cout<<endl;
		if (ans == target){
			for (vector<int>::const_iterator iter = ch.begin();iter != ch.end();iter++){
                printf("%c",(*iter)+'A'-1);
			}
            cout<<'\n';
			return 1;
		}
		return 0;
	}
	for (int i=1;i<=op[0];i++){
        int flag = 0;
        for (vector<int>::const_iterator iter = ch.begin();iter != ch.end();iter++){
            if (op[i] == (*iter)){
                flag = 1;
                break;
            }
        }
        if (flag)continue;
		ch.push_back(op[i]);
		int sign = 1;
		if (deep==2||deep==4)sign = -1;
		ans += sign*base[op[i]][deep];

		if(solve(deep+1,ch,ans))
            return 1;

		ans -= sign*base[op[i]][deep];
		ch.pop_back();
	}
	return 0;
}

int main(){
	for (int i=1;i<=26;i++){
		for (int j=1;j<=5;j++){
			base[i][j] = pow(i,j);
		}
	}
	string s;
	while(1){
		cin>>target>>s;
		if (target==0&&s=="END")
			break;
		op[0] = s.length();
		for (int i=1;i<=s.length();i++){
			op[i] = s[i-1]-'A'+1;
		}
		sort(op+1,op+1+op[0],greater<int>());
		vector<int> ch;

		if(!solve(1,ch,0))cout<<"no solution"<<endl;
	}
	return 0;
}

