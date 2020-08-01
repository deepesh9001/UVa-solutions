#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	int k = n;
	while(n-->0){
		vector<int> salary(3);
		for(int i =0; i < 3; i++){
			cin>>salary[i];
		}
		sort(salary.begin(), salary.end());
		cout<<"Case "<<k-n<<": "<<salary[1]<<'\n';
	}
}