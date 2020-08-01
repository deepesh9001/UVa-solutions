#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int main(){
	freopen("in.txt", "r", stdin);
	
	int n;
	while(cin>>n){
		if(n == -1) break;

		string str1, str2;
		cin>>str1>>str2;

		bool charr1[26], charr2[26];
		clr(charr1), clr(charr2);
		
		for(auto x : str1){
			charr1[x - 'a'] = true;
		}
		
		for(auto x : str2){
			charr2[x-'a'] = true;
		}

		int count = 0;
		flag2 = false;
		REP(i, 26){
			if(charr2[i] and !charr1[i]) count++;
			else if(charr1[i] and !charr2[i]) flag2 = true;
		}

		cout<<"Round "<<n<<'\n';
		if(flag2){
			if(count >= 7){
				cout<<"You lose.\n";
			}
			else cout<<"You chickened out.\n";
		}
		else cout<<"You win.\n";
	}
	
	
	
}