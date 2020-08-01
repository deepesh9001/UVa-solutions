#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;


int main(){
	freopen("in.txt", "r", stdin);

	while(1){
		int l;
		cin>>l;
		
		if(l <= 0) break;

		string str;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, str, '\n');

		int min = 1e9;
		int idx = -1;
		int i = 0;
		char last = '$';

		for(auto x : str){
			if(x == 'Z') min = 0;
			else if(x == 'R'){
				if(last == 'D' and min > i - idx){
					min = i - idx;
				}
				last = x;
				idx = i;
			}
			else if(x == 'D'){
				if(last == 'R' and min > i - idx) {
					min = i - idx;
				}
				last = x;
				idx = i;
			}
			i++;
		}

		cout<<min<<'\n';

	}

}