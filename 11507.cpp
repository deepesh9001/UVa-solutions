#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;


int main(){
	freopen("in.txt", "r", stdin);

	int L;
	while(si(L) and L > 0){
		string dir;

		string ans = "+x";

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(L-->1){
			
			cin>>dir;
			if(dir == "+z") {
				if(ans == "+x") ans = "+z";
				else if(ans == "-x") ans = "-z";
				else if(ans == "+z") ans = "-x";
				else if(ans == "-z") ans = "+x";
			}
			else if(dir == "-z") {
				if(ans == "+x") ans = "-z";
				else if(ans == "-x") ans = "+z";
				else if(ans == "+z") ans = "+x";
				else if(ans == "-z") ans = "-x";
			}
			if(dir == "+y") {
				if(ans == "+x") ans = "+y";
				else if(ans == "-x") ans = "-y";
				else if(ans == "+y") ans = "-x";
				else if(ans == "-y") ans = "+x";
			}
			else if(dir == "-y") {
				if(ans == "+x") ans = "-y";
				else if(ans == "-x") ans = "+y";
				else if(ans == "+y") ans = "+x";
				else if(ans == "-y") ans = "-x";
			}
		}

		cout<<ans<<'\n';

	}
}