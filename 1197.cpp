#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = b - 1; i >= a; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define si(x) scanf("%d", &x)
#define clr(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

bool flag1 = false, flag2 = false;
int caseNo = 1;

int dirx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int diry[] = {0, 1, 0, -1, 1, -1, -1, 1};

vi adj[30010];
bool vis[30010];

class UnionFind
{
	// OOP style
private:
	vi p, rank;
	// remember: vi is vector<int>
public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
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
		for(int j = 0; j <= p.size(); j++)
			if(isSameSet(i, j) and i != j) count++;
		
		return count;
	}
	int numDisjointSet(){
		int count = 0;
		bool* UF_vis = new bool[p.size()+1];
		for(int i = 0; i < p.size(); i++){
			if(!UF_vis[i]){
				count++;
				for(int j = 0; j <= p.size(); j++)
					if(!UF_vis[j] and isSameSet(i, j) and i != j) UF_vis[j] = true;
			}
		}
		return count;
	}
};

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (1)
	{
		int n, m;
		cin >> n >> m;
		if (n == 0 and m == 0) break;

		UnionFind* u = new UnionFind(n);

		REP(i, m)
		{
			int n0;
			cin >> n0;

			int t;
			cin>>t;

			REP(j, n0 -1)
			{
				int a;
				cin >> a;

				u->unionSet(t, a);
			}
		}

		cout<<u->sizeOfSet(0)<<' '<<u->numDisjointSet()<<'\n';

	}
}