#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string>
#include<functional>
using namespace std;
struct Node{
	int cost;
	int id;
	bool operator>(const Node& n)const{
		return this->cost > n.cost;
	}
}; 

int GetNext(int id,string prev,string post)
{
	int mask = 1;
	for(auto iter = prev.rbegin(); iter!=prev.rend(); ++iter){
		if(*iter == '-' && !(id & mask))	//被WA了无数次 
			return -1;
		if(*iter == '+' && (id & mask))		//位操作的惨痛教训 
			return -1;
		mask <<= 1;
	}
	
	mask = 1;
	for(auto iter = post.rbegin(); iter!=post.rend(); ++iter){
		if(*iter == '-'){
			id = id|mask;
		}
		if(*iter == '+'){
			id = id&(~mask);
		}
		mask <<= 1;
	}
	return id;
}

int main()
{
	int n,m;	//n-bugs数  m-patches数 
	int pid = 0;	//产品编号 
	while(scanf("%d%d",&n,&m)==2 && n){
		++pid;
		vector<int> tm(m);
		vector<string> prev(m);
		vector<string> post(m);
		//将m组patch输入
		for(int i = 0; i < m; ++i){
			cin >> tm[i] >> prev[i] >> post[i];
		}

		//dijkstra算法 
		vector<bool> visited(1<<n,0);
		int aim = (1<<n)-1;
		priority_queue<Node,vector<Node>,greater<Node> > pq;
		pq.push(Node{0,0});
		bool flag = false;
		while(!pq.empty()){
			Node tn = pq.top();	pq.pop();
			if(visited[tn.id])
				continue;
			visited[tn.id] = true;
			if(tn.id == aim){
				printf("Product %d\n",pid);
				printf("Fastest sequence takes %d seconds.\n\n",tn.cost);
				flag = true;
				break;
			}
			for(int i = 0; i < m; ++i){
				int nextid = GetNext(tn.id,prev[i],post[i]);
				if(nextid != -1 && !visited[nextid]){
					pq.push(Node{tm[i]+tn.cost,nextid});
				}
			}
		} 
		if(!flag){
			printf("Product %d\n",pid);
			printf("Bugs cannot be fixed.\n\n");
		}
	}
	return 0;
}
