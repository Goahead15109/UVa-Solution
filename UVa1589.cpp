#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Pos{
	int x;
	int y;
	bool operator<(const Pos& pt)const{
		if(this->x != pt.x)
			return this->x < pt.x;
		else
			return this->y < pt.y;
	}
	bool operator==(const Pos& pt)const{
		if(this->x == pt.x && this->y == pt.y)
			return true;
		else
			return false;
	}
};
int check[12][12];	//棋盘位置是否有棋子 
void CheckClear()
{
	for(int i = 0; i < 12; ++i)
		for(int j = 0; j < 12; ++j)
			check[i][j] = 0;
}

//俩位置之间的棋子数 
int PiecesCt(Pos& Ori, Pos& Des)
{
	int ct = 0;
	if(Ori.x == Des.x){
		int from = min(Ori.y,Des.y);
		int to = max(Ori.y,Des.y);
		for(int i = from+1; i <to;++i)
			ct += check[Ori.x][i];
	} 
	if(Ori.y == Des.y){
		int from = min(Ori.x,Des.x);
		int to = max(Ori.x,Des.x);
		for(int i = from+1; i < to; ++i)
			ct += check[i][Ori.y];
	}
	return ct;
}
//位置Ori的红棋子type是否可攻击位置Des 
bool IsHit(char type, Pos& Ori, Pos& Des) 
{
	if(type == 'G'){	//红将 
		if(Ori.y == Des.y && PiecesCt(Ori,Des)==0)
			return true;
		else
			return false;
	}
	else if(type == 'R'){	//红车 
		if((Ori.y == Des.y ^ Ori.x == Des.x) && PiecesCt(Ori,Des)==0)
			return true;
		else
			return false;		
	}
	else if(type == 'C'){	//红炮 
		if((Ori.y == Des.y ^ Ori.x == Des.x) && PiecesCt(Ori,Des)==1)
			return true;
		else
			return false;				
	}
	else if(type == 'H'){	//红马 
		int dx = Ori.x - Des.x;
		int dy = Ori.y - Des.y;
		if(dx == 1 && dy == 2 && check[Ori.x][Ori.y-1]==0)
			return true;
		else if(dx == 2 && dy == 1 && check[Ori.x-1][Ori.y]==0)
			return true;
		else if(dx == 2 && dy == -1 && check[Ori.x-1][Ori.y]==0)
			return true;
		else if(dx == 1 && dy == -2 && check[Ori.x][Ori.y+1]==0)
			return true;
		else if(dx == -1 && dy == -2 && check[Ori.x][Ori.y+1]==0)
			return true;
		else if(dx == -2 && dy == -1 && check[Ori.x+1][Ori.y]==0)
			return true;
		else if(dx == -2 && dy == 1 && check[Ori.x+1][Ori.y]==0)
			return true;
		else if(dx == -1 && dy == 2 && check[Ori.x][Ori.y-1]==0)
			return true;
		else
			return false;
	}
	
}
bool Hitable(Pos& pt,multimap<char,Pos>& redps)
{
	bool flag = false;
	for(multimap<char,Pos>::iterator it = redps.begin(); it != redps.end(); ++it){
		if(pt == it->second)
			continue;
		if(IsHit(it->first,it->second,pt)){
			flag = true;
		}
	}
	return flag;
}

int readchar(){
	for(;;){
		int ch = getchar();
		if(ch != '\n' && ch != '\r' && ch != ' ')
			return ch;
	}
} 
int main()
{
//	freopen("output.txt","w",stdout);
	//初始化黑将的初始位置 v 下一个可能位置的映射 
	map<Pos,vector<Pos>> genexts{{{1,4},{{1,5},{2,4}}},
								 {{1,5},{{1,4},{1,6},{2,5}}},
								 {{1,6},{{1,5},{2,6}}},
								 {{2,4},{{1,4},{2,5},{3,4}}},
								 {{2,5},{{1,5},{2,4},{2,6},{3,5}}},
								 {{2,6},{{1,6},{2,5},{3,6}}},
								 {{3,4},{{2,4},{3,5}}},
								 {{3,5},{{2,5},{3,4},{3,6}}},
								 {{3,6},{{2,6},{3,5}}}
								};
	
	int N;
	Pos genp;
	scanf("%d%d%d",&N,&genp.x,&genp.y);		
	while(N || genp.x || genp.y){
		CheckClear();
		//输入N个红子位置
		multimap<char,Pos> redps;
		while(N--){
			char c;
			c = readchar();
			Pos pt;
			scanf("%d%d",&pt.x,&pt.y);		
			redps.insert({c,pt});
			check[pt.x][pt.y] = 1;
		}

		bool flag = false;	//flag表示不能checkmate
		if(IsHit('G',redps.find('G')->second,genp)) {
			flag = true;
		}
		else{	
			vector<Pos> genext = genexts[genp];//黑将下一次可能的位置 
			for(int i = 0; i < genext.size(); ++i){
				if(!Hitable(genext[i],redps)){	//如果该位置不可攻击 
					flag = true;
					break;
				}
			} 
		}
		
		printf("%s\n",flag?"NO":"YES");
		
		scanf("%d%d%d",&N,&genp.x,&genp.y);
	}
	return 0;
} 
