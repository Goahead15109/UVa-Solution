#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<set>

using namespace std;

int n,m;	//n-结点数  m-边数
const int MAXN = 102;
const int MAXM = 5000;
int a[MAXM],b[MAXM],w[MAXM],r[MAXM];
bool cmp(const int& a, const int& b){return w[a]<w[b];}	//间接比较函数 
int p[MAXN];	//并查集
int FindRoot(int i){return p[i]==i ? i : p[i]=FindRoot(p[i]);}

//从排序后第k条边开始使用kruskal算法
//返回最大最小边之差，若无生成树返回-1 
int Kruskal(int k)
{
	//初始化并查集
	for(int i = 0; i <= n; ++i)
		p[i] = i; 
	
	int det = 0;
	int min = w[r[k]];
	for(int i = k; i < m; ++i){
		int t = r[i];
		int x = FindRoot(a[t]);
		int y = FindRoot(b[t]);
		if(x != y){
			p[y] = x;
			det = w[t] - min;
		}
	}	 
	
	set<int> roots;
	for(int i = 1; i <= n; ++i){
		p[i] = FindRoot(i);
		roots.insert(p[i]);
	}
	
	return roots.size()==1 ? det : -1;
}
int main()
{
	while(scanf("%d%d",&n,&m)==2 && n){
		//输入a,b,w
		for(int i = 0; i < m; ++i){
			scanf("%d%d%d",&a[i],&b[i],&w[i]);
		}
		//初始化间接比较数组r
		for(int i = 0; i < m; ++i)
			r[i] = i; 
		//间接排序 
		sort(r,r+m,cmp);
		 
		priority_queue<int,vector<int>,greater<int> > pq;  
		for(int i = 0; i <= m-n+1; ++i){
			int k = Kruskal(i);
			if(k != -1)
				pq.push(k);
		} 
		if(pq.empty())
			cout << -1 << endl;
		else
			cout << pq.top() << endl;
	}
	return 0;
}
