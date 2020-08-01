#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

bool flag1 = false, flag2 = false;
int caseNo = 1;


int main(){
	freopen("in.txt", "r", stdin);

	int k, m;
	while(scanf("%d%d", &k, &m) == 2){
		unordered_map<string, int> courses;

		REP(i,k) {
			string s;
			cin>>s;

			courses[s] = 2;
		}

		flag1 = false;
		REP(i, m){
			int n, r, req = 0;
			cin>>n>>r;			

			REP(j, n){
				string s;
				cin>>s;
				

				if(courses[s] == 2){
					req++;
				}
			}

			if(req < r) flag1 = true;

		}

		if(!flag1) cout<<"yes\n";
		else cout<<"no\n";

		caseNo++;
	}

}