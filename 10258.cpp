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

bool myComp(const vector<int> &v1, const vector<int> &v2){
	if(v1[1] != v2[1]) return v1[1] > v2[1];
	else return v1[2] < v2[2];
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int n;
	si(n);
	cin.ignore();
	cin.ignore();
	while(n-->0){

		vector<vector<int>> score(101, vector<int>(11));
		
		int c, p, t;
		char L;
		char str[20];
		while(fgets(str, sizeof str, stdin) and str[0] != '\n'){
			sscanf(str, "%d %d %d %c\n", &c,&p,&t,&L);
			
			if(L == 'I') score[c][10] += 20;
			else if(L == 'C' and score[c][p] == 0) score[c][p] += t;			
		}

		vector<vector<int>> list;
		REP(i, 101){
			p = 0, t = 0;
			REP(j, 11){
				if(j != 10 and score[i][j] > 0) p++;
				t += score[i][j];
			}
			if(t > 0){
				vector<int> temp = {i,p,t};
				list.push_back(temp);
			}
		}

		sort(list.begin(), list.end(), myComp);

		REP(i, list.size()){
			REP(j, 3) cout<<list[i][j]<<' ';
			cout<<'\n';
		}
		cout<<'\n';
	}
}