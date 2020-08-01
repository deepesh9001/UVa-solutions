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
	
	int n, m;
	while(cin>>n>>m){
		if(n == 0 and m == 0) break;

		char land[n+1][m+1];

		REP(i,n) REP(j,m){
			cin>>land[i][j];
		}
		
		int a[] = {1, 0, -1, 0, 1, 1, -1, -1};
		int b[] = {0, 1, 0, -1, 1, -1, -1, 1};
		REP(i,n){ 
			REP(j,m){
				int count = 0;
				if(land[i][j] == '.'){
					
					REP(k, 8){
						if(i >= 0 and j >= 0 and i < n and j < m){
							if(land[i+a[k]][j+b[k]] == '*') count++;
						}
					}
					
					land[i][j] = '0' + count;
				}
			}
		}

		cout<<"Field #"<<caseNo++<<":\n";
		REP(i,n){ 
			REP(j,m){
				cout<<land[i][j];
			}
			cout<<'\n';
		}
		cout<<'\n';
		
	}
	
	
	
}