#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while(1){
		int s;
		long n;
		cin>>s>>n;

		if(s == 0 or n == 0) break;

		int posy = s/2+1, posx = s/2+1, dir = 1;
		long num = 1, step = 1;
		bool f1 = false;
		for(long i = 2; i < n+1; i++){
			if(!f1){
				posy += dir*1;
				if(i-num == step)f1 = true, num = i;
			}
			else if(f1){
				posx -= dir*1;
				if(i-num == step)f1 = false, num = i, step++, dir *= -1;
			}
		}
		cout<<"Line = "<<posy<<", column = "<<posx<<'\n';
	}
    
}