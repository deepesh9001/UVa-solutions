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

bool myComp(const vector<string> &v1, const vector<string> &v2){
	if(v1[1] != v2[1]) return v1[0] > v2[0];
	else return v1[1] > v2[1];
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    vector<vector<string>> books;

	string str;
	int i = 0;
	while(getline(cin, str, '\n') and str != "END"){
		vector<string> book(2);
		int bIdx = str.find('\"', 1);
		book[0] = str.substr(0, bIdx+1);
		int aIdx = str.find("by", bIdx);
		book[1] = str.substr(aIdx+3, str.length() - aIdx-3);
		books.push_back(book);
	}

	REP(i, books.size()) cout<<books[i][0]<<" "<<books[i][1]<<'\n';

	vector<vector<string>> rbooks;
	vector<vector<string>> bbooks;
	

	while(getline(cin, str, '\n') and str != "END"){
		
		string what_command = str.substr(0,6);
		if(what_command == "SHELVE"){
			sort(rbooks.begin(), rbooks.end(), myComp);
			if(!books.empty()){
				string later = books[books.size()-1][0];
				REP(i, rbooks.size()){
					cout<<"Put "<<rbooks[i][0]<<" after "<<later<<'\n';
					later = rbooks[i][0];
				}
			}
			else{
				string later = rbooks[0][0];
				cout<<"Put "<<later<<" first\n";
				FOR(i, 1, rbooks.size()){
					cout<<"Put "<<rbooks[i][0]<<" after "<<later<<'\n';
					later = rbooks[i][0];
				}
			}
			REP(i, rbooks.size()){
				books.push_back(rbooks[i]);
			}
			cout<<"END\n";
			continue;
		}
		string which_book = str.substr(7, str.length() - 7);
		if(what_command == "BORROW"){
			REP(i, books.size()){
				if(books[i][0] == which_book){
					bbooks.push_back(books[i]);
					FOR(j,i,books.size()-1){
						books[j] = books[j+1];
					}
					books.pop_back();
				}
			}
		}

		else if(what_command == "RETURN"){
			for(auto it = bbooks.begin(); it != bbooks.end(); it++){
				if((*it)[0] == which_book){
					rbooks.push_back(*it);
					for(; it != bbooks.end() -1; it++){
						(*it)[0] = (*(it+1))[0];
						(*it)[1] = (*(it+1))[1];
					}
					bbooks.pop_back();
					break;
				}
			}
		}
		
	}

	
}