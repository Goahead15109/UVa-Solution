#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> Pii;	//first-曲子数 second-时间 
const int maxn = 50 + 5;
const int maxt = 180 * maxn + 678 + 2;
Pii dp[maxn][maxt];

int main()
{
	freopen("uva12568.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int n,t;
	int tm[maxn];
	for(int ca = 1; ca <= T; ++ca){
		scanf("%d%d",&n,&t);
		for(int i = 1; i <= n; ++i)
			scanf("%d",&tm[i]);
		
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j <= t; ++j){
				dp[i][j] = dp[i-1][j];
				if(j > tm[i]){
					Pii& p = dp[i-1][j-tm[i]];
					dp[i][j] = max(dp[i-1][j],Pii(p.first+1,p.second+tm[i]));
				}
			}
		}
		printf("Case %d: %d %d\n",ca,dp[n][t].first+1,dp[n][t].second+678);
	}
	return 0;
}
