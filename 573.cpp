#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define si(x) scanf("%d", &x)

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);

	while(1){
		int h, d, f;
		double u;
		cin>>h>>u>>d>>f;

		if(h == 0) break;

		int days = 0;
		bool flag;

		double height = 0, climb = u;

		while(1){
			height += climb;
			days++;

			if(height > h) {
				flag = true;
				break;
			}

			height -= d;

			if(height < 0) {
				flag = false;
				break;
			}

			climb -= u*f/100.;
			
		}

		if(flag) cout<<"sucess on day ";
		else cout<<"failure on day ";
		cout<<days<<'\n';
		
	}
}