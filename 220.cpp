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

int main(){
	freopen("in.txt", "r", stdin);
	
	cin>>caseNo;

	while(caseNo-->0){
		char board[8][8];

		REP(i,8) REP(j,8) cin>>board[i][j];

		char toMove;
		cin>>toMove;

		
		while(1){
			char command;
			cin>>command;

			if(command == 'L'){
				vector<pair<int,int>> ans;
				REP(i, 8) REP(j, 8) REP(k, 8) if(i + dirx[k] < 8 and j + diry[k] < 8 and i + dirx[k] >= 0 and j + diry[k] >= 0 and board[i][j] == '-')
					if(board[i+dirx[k]][j+diry[k]] == (toMove!='W'?'W':'B')){
						flag2 = false;
						FOR(l, 1, 8){
							if(i + l*dirx[k] < 8 and j + l*diry[k] < 8 and i + l*dirx[k] >= 0 and j + l*diry[k] >= 0){
								if(board[i + l*dirx[k]][j + l*diry[k]] == toMove) flag2 = true;
							}
						}
						if(flag2) ans.push_back({i+1,j+1});
					}

				if(ans.size() > 0) REP(i, ans.size()) cout<<"("<<ans[i].first<<","<<ans[i].second<<") ";
				else {cout<<"No legal moves.";toMove = toMove!='W'?'W':'B';}
				cout<<'\n';
						
			}
			
			
			else if(command == 'M'){
				char a, b;
				cin>>a>>b;

				REP(i, 8){
					if(board[a-'1' + dirx[i]][b-'1' + diry[i]] == toMove!='W'?'W':'B'){
						FOR(l, 2, 8){
							if(a-'1' + l*dirx[i] < 8 and b-'1' + l*diry[i] < 8 and a-'1' + l*dirx[i] >= 0 and b-'1' + l*diry[i] >= 0){
								if(board[a-'1' + l*dirx[i]][b-'1' + l*diry[i]] == '-') break;
								if(board[a-'1' + l*dirx[i]][b-'1' + l*diry[i]] == toMove){
									REP(rev, l){
										board[a-'1' + (l-rev)*dirx[i]][b-'1' + (l - rev)*diry[i]] = toMove;
									}
									break;
								} 
								
							}
						}
					}
				}

				board[a-'1'][b-'1'] = toMove;
				toMove = toMove!='W'?'W':'B';

				int white = 0, black = 0;
				REP(i,8) REP(j,8){
					if(board[i][j] == 'W') white++;
					else if(board[i][j] == 'B') black++;
				}

				cout<<"Black - "<<black<<" White - "<<white<<'\n';
			}
			else if(command == 'Q'){
				REP(i,8){
					REP(j,8){
						cout<<board[i][j];
					}
					cout<<'\n';
				}
				cout<<'\n';
				break;
			}
			else{
				cout<<"Invalid command! Check the command and try again.\n";
				break;
			}
		}

	}
	
	
	
}