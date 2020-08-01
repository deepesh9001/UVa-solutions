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

	int k, q, m;
	while (scanf("%d%d%d", &k,&q, &m) == 3)
	{
		
		int board[8][8];
		clr(board);

		board[k/8][k%8] = 1;
		if(board[q/8][q%8] == 1){
			cout<<"Illegal state\n";
			continue;
		}
		board[q/8][q%8] = 1;

		if(k/8 > 0) board[k/8 -1][k%8] = 2;
		if(k/8 < 7) board[k/8 +1][k%8] = 2;
		if(k%8 > 0) board[k/8][k%8 -1] = 2;
		if(k%8 < 7) board[k/8][k%8 +1] = 2;

		int x = q/8;
		int fill = 3;
		while(++x < 8){
			if(board[x][q%8] == 1)  fill = 1;
			if(board[x][q%8] == 0) board[x][q%8] = fill;
			if(fill == 1) board[x][q%8] = fill;
		}

		x = q/8;
		fill = 3;
		while(--x >= 0){
			if(board[x][q%8] == 1)	fill = 1;
			if(board[x][q%8] == 0 ) board[x][q%8] = fill;
			if(fill == 1) board[x][q%8] = fill;
		}

		x = q%8;
		fill = 3;
		while(++x < 8){
			if(board[q/8][x] == 1) fill = 1;
			if(board[q/8][x] == 0) board[q/8][x] = fill;
			if(fill == 1) board[q/8][x] = fill;
		}

		x = q%8;
		fill = 3;
		while(--x >= 0){
			if(board[q/8][x-1] == 1)  fill = 1;
			if(board[q/8][x] == 0) board[q/8][x] = fill;
			if(fill == 1) board[q/8][x] = fill;
		}

		if(board[m/8][m%8] == 1 || board[m/8][m%8] == 0){
			cout<<"Illegal move\n";
			continue;
		}

		if(board[m/8][m%8] == 2){
			cout<<"Move not allowed\n";
			continue;
		}
		

		x = m/8;
		fill = 3;
		while(++x < 8){
			if(board[x][m%8] == 2) board[x][m%8] = fill;
		}

		x = m/8;
		fill = 3;
		while(--x >= 0){
			if(board[x][m%8] == 2) board[x][m%8] = fill;
		}

		x = m%8;
		fill = 3;
		while(++x < 8){
			if(board[m/8][x] == 2) board[m/8][x] = fill;
		}

		x = m%8;
		fill = 3;
		while(--x >= 0){
			if(board[m/8][x] == 2) board[m/8][x] = fill;
		}

		flag2 = false;
		if(k/8 > 0) if(board[k/8 -1][k%8] == 2 || board[k/8 -1][k%8] == 1) flag2 = true;
		if(k/8 < 7) if(board[k/8 +1][k%8] == 2 || board[k/8 +1][k%8] == 1) flag2 = true;
		if(k%8 > 0) if(board[k/8][k%8 -1] == 2 || board[k/8][k%8 -1] == 1) flag2 = true;
		if(k%8 < 7) if(board[k/8][k%8 +1] == 2 || board[k/8][k%8 +1] == 1) flag2 = true;


		if(flag2) cout<<"Continue\n";
		else cout<<"Stop\n";
	}
	
	
}