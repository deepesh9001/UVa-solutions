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

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

bool isPal(string s){
	int n = s.length();
	if(n == 0) return false;

	if(n%2 == 0){
		REP(i, n/2) if(s[ n/2 -1 - i] != s[n/2 + i]) return false;
	}
	else{
		FOR(i, 0, n/2 +1) if(s[n/2  - i] != s[n/2 + i]) return false;
	}
	return true;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	string str;
	while(getline(cin, str, '\n') and str.length() > 0){
		unordered_set<string> s;
		unordered_set<string> ans;
		
		REP(i, str.length() ){
			REP(j, str.length()+1 - i){ 
				string sub = str.substr(i, j);

				if(s.find(sub) == s.end()){
					s.insert(sub);
					if(isPal(sub)){
						if(ans.find(sub) == ans.end())ans.insert(sub);
					}
				}
			}
		}
		
		cout<<"The string \'"<<str<<"\' contains "<<ans.size()<<" palindromes.\n";
	}
}