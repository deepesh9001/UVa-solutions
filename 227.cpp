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
	freopen("out.txt", "w", stdout);
	
	
	while(1){
		vector<string> grid(5);

		REP(i, 5){
			getline(cin,grid[i],'\n');
		}
		
		if(grid[0].length() < 4) break;

		int ai, aj;
		REP(i,5) if(grid[i].length() == 4) grid[i].push_back(' ');
		REP(i, 5){
			aj = grid[i].find(' ');
			if(aj > -1){
				ai = i;
				break;
			}
		}

		flag2 = false;
		while(1){
			string str;
			getline(cin, str, '\n');

			for(char ch : str){
				switch (ch){
				case 'A':
					if(ai > 0){
						grid[ai][aj] = grid[ai-1][aj];
						ai--;
						grid[ai][aj] = ' ';
					}
					else flag2 = true;
					break;
				case 'B':
					if(ai < 4){
						grid[ai][aj] = grid[ai+1][aj];
						ai++;
						grid[ai][aj] = ' ';
					}
					else flag2 = true;
					break;
				case 'R':
					if(aj < 4){
						grid[ai][aj] = grid[ai][aj+1];
						aj++;
						grid[ai][aj] = ' ';
					}
					else flag2 = true;
					break;
				case 'L':
					if(aj > 0){
						grid[ai][aj] = grid[ai][aj-1];
						aj--;
						grid[ai][aj] = ' ';
					}
					else flag2 = true;
					break;
				default:
					break;
				}
			}
			if(str[str.length() -1] == '0') break;
		}

		std::cout<<"Puzzle #"<<caseNo++<<":\n";

		if(flag2) std::cout<<"This puzzle has no final configuration.\n";
		else REP(i, 5) std::cout<<grid[i]<<'\n';

		std::cout<<'\n';

	}
	
}