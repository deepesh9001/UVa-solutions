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

int rook(int m, int n){
	return min(m,n);
}

int king(int m, int n){
	return (m+1)*(n+1)/4;
}

int queen(int m, int n){
	if(m <=2 and n <= 2) return 1;
	if(m <= 3 and n <= 3) return 2;

	return min(m,n);
}

int knight(int m, int n){
	if(m == 1 || n == 1){
		return max(m, n);
	}

	if(m == 2 || n == 2){
		int c = (max(m,n)/4)*4;

		if(max(m,n)%4 == 1) c += 2;
		else if(max(m,n)%4 > 1) c += 4;

		return c;
	}
	else return (m*n + 1) / 2;
}


int main(){
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int no;
	si(no);

	while(no-->0){
		char piece;
		int n,m;
		cin>>piece>>n>>m; 

		switch (piece)
		{
		case 'r':
			cout<<rook(m,n);
			break;
		case 'k':
			cout<<knight(m,n);
			break;
		case 'Q':
			cout<<queen(m,n);
			break;
		case 'K':
			cout<<king(m,n);
			break;
		default:
			break;
		}
		cout<<'\n';
	}
	
	
	
}