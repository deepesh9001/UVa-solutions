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
		string str;
		getline(cin, str);

		if(str == "") break;

		list<char> ans;

		char ptrAt = 'n';
		auto it = ans.begin();

		for(auto ch: str){
			if(ch == '['){
				it = ans.begin();
			}
			else if(ch == ']') {
				it = ans.end();
			}
			else{
				ans.insert(it,ch);
			}
		}

		for(auto x: ans)  std::cout<<x;
		std::cout<<'\n';
	}
}