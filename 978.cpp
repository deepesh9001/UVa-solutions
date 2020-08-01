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

	int tests;
	cin>>tests;
	while(tests-->0){
		int n, ng, nb;
		cin>>n>>ng>>nb;

		multiset<int> g;
		multiset<int> b;

		REP(i, ng){
			int a;
			cin>>a;
			g.insert(a);
		}

		REP(i, nb){
			int a;
			cin>>a;
			b.insert(a);
		}

		vector<int> battles(n);

		while(b.size() > 0 and g.size() > 0){
			REP(i, n){
				int g1 = 0, b1 = 0;
				
				if(g.size() > 0){ 
					auto itg = g.end();
					itg--;
					g1 = *itg; 
					g.erase(itg);
				}
				if(b.size() > 0) {
					auto itb = b.end();
					itb--;
					b1 = *itb; 
					b.erase(itb);
				}

				int a = g1 - b1;
				if(a > 0) g.insert(a);
				else if(a < 0) b.insert(-1*a);
			}
		}

		if(b.size() > 0) {
			cout<<"blue wins\n";
			auto it = b.end();
			while(1){
				it--;
				cout<<*it<<'\n';
				if(it == b.begin()) break;
			}
		}
		else if(g.size() > 0) {
			cout<<"green wins\n";
			auto it = g.end();
			while(1){
				it--;
				cout<<*it<<'\n';
				if(it == g.begin()) break;
			}
		}
		else {
			cout<<"green and blue died\n";
		}
		cout<<'\n';
	}
}