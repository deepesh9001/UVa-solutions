#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = b-1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1,0,-1,0,1,1,-1,-1};
int diry[] = {0,1,0,-1,1,-1,-1,1};

class UnionFind
{
	// OOP style
private:
	int p[100100], rank[100100], n;
	// remember: vi is vector<int>
public:
	UnionFind(int N)
	{
		n = N;
		for (int i = 0; i < 100100; i++)
			p[i] = i, rank[i] = 0;
	}
	int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			// if from different set
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			// rank keeps the tree short
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int sizeOfSet(int i)
	{
		int count = 0;
		for(int j = 0; j <= n; j++)
			if(isSameSet(i, j) and i != j) count++;
		
		return count;
	}
	int numDisjointSet(){
		int count = 0;
		bool* UF_vis = new bool[n+1];
		for(int i = 0; i < n; i++){
			if(!UF_vis[i]){
				count++;
				for(int j = 0; j <= n; j++)
					if(!UF_vis[j] and isSameSet(i, j) and i != j) UF_vis[j] = true;
			}
		}
		return count;
	}
};

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int cases;
	cin >> cases;
	while(cases-->0){
		int n;
		cin>>n;
		cin.ignore();

		map<string, int> net;
		UnionFind uf(n);
		int id = 1;

		string name1, name2;
		REP(i, n){
			getline(cin, name1);
			stringstream ss;
			ss << name1;
			ss >> name1 >> name2;

			if(net.count(name1) == 0) net[name1] = id++;
			if(net.count(name2) == 0) net[name2] = id++;

			uf.unionSet(net[name1], net[name2]);
			cout<<uf.sizeOfSet(net[name1])+1<<'\n';
			
		}
	}
}