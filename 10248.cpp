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
int knightx[] = {-2,-2,-1,-1,1,1,2,2};
int knighty[] = {1,-1,2,-2,2,-2,1,-1};


void queen(int i, int j, char** board){
	REP(k, 8) FOR(l, 1, 8){
		if(i + l*dirx[k] >= 0 and j + l*diry[k] >= 0 and i + l*dirx[k] <= 7 and j + l*diry[k] <= 7){
			if(board[i + l*dirx[k]][j + l*diry[k]] == 'p') break;
			board[i + l*dirx[k]][j + l*diry[k]] = 'c';
		}
	}
}
void rook(int i, int j, char** board){
	REP(k,4) FOR(l, 1,8){
		if(i + l*dirx[k] >= 0 and j + l*diry[k] >= 0 and i + l*dirx[k] <= 7 and j + l*diry[k] <= 7){
			if(board[i + l*dirx[k]][j + l*diry[k]] == 'p') break;
			board[i + l*dirx[k]][j + l*diry[k]] = 'c';
		}
	}
}
void knight(int i, int j, char** board){
	REP(k, 8){
		if(i + knightx[k] >= 0 and j + knighty[k] >= 0 and i + knightx[k] <= 7 and j + knighty[k] <= 7 ){
			if(board[i + knightx[k]][j + knighty[k]] != 'p') board[i + knightx[k]][j + knighty[k]] = 'c';
		}
	}
}
void bishop(int i, int j, char** board){
	FOR(k,4,8) FOR(l, 1,8){
		if(i + l*dirx[k] >= 0 and j + l*diry[k] >= 0 and i + l*dirx[k] <= 7 and j + l*diry[k] <= 7){
			if(board[i + l*dirx[k]][j + l*diry[k]] == 'p') break;
			board[i + l*dirx[k]][j + l*diry[k]] = 'c';
		}
	}
}
void pawn(int i, int j, char** board){
	if(j < 7 and board[i+1][j+1] != 'p') board[i+1][j+1] = 'c';
	if(j > 0 and board[i+1][j-1] != 'p')board[i+1][j-1] = 'c';
}
void Pawn(int i, int j, char** board){
	
	if(j < 7 and board[i-1][j+1] != 'p') board[i-1][j+1] = 'c';
	if(j > 0 and board[i-1][j-1] != 'p') board[i-1][j-1] = 'c';
}


void king(int i, int j, char** board){
	REP(k, 8) if(i + dirx[k] >= 0 and j + diry[k] >= 0 and i + dirx[k] <= 7 and j + diry[k] <= 7){
		if(board[i + dirx[k]][j + diry[k]] != 'p') board[i + dirx[k]][j + diry[k]] = 'c';
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	

	while(1){
		vector<string> FEN(8);
		REP(i,7) getline(cin, FEN[i], '/');
		getline(cin, FEN[7], '\n');

		
		if(FEN[0].length() == 0) break;
		

		char** board = new char*[8];
		REP(i, 8) board[i] = new char[8];

		REP(i,8) REP(j,8) board[i][j] = '_';

		REP(i, 8){
			int space = 0;
			for(char ch : FEN[i]){
				if(ch >= '1' and ch <= '8'){
					space += ch - '0';
				}
				else board[i][space++] = 'p'; 
			}
		}
		
		REP(i, 8){
			int space = 0;
			for(char ch : FEN[i]){
				switch (ch)
				{
				case 'k':
					king(i, space, board);
					space++;
					break;
				case 'K':
					king(i, space, board);
					space++;
					break;
				case 'q':
					queen(i, space, board);
					space++;
					break;
				case 'Q':
					queen(i, space, board);
					space++;
					break;
				case 'b':
					bishop(i, space, board);
					space++;
					break;
				case 'B':
					bishop(i, space, board);
					space++;
					break;
				case 'n':
					knight(i, space, board);
					space++;
					break;
				case 'N':
					knight(i, space, board);
					space++;
					break;
				case 'p':
					pawn(i, space, board);
					space++;
					break;
				case 'P':
					Pawn(i, space, board);
					space++;
					break;
				case 'r':
					rook(i, space, board);
					space++;
					break;
				case 'R':
					rook(i, space, board);
					space++;
					break;
				
				default:
					space += ch - '0';
					break;
				}
			}
		}

		int count = 0;
		REP(i, 8) REP(j, 8) if(board[i][j] == '_')
			count++;

		cout<<count<<"\n";
	}
	
	
	
}