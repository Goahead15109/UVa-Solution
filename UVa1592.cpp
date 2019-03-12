#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

map<string,int> IDCache;
vector<string> strCache;
int GetID(string str)
{
	if(IDCache.count(str) != 0)
		return IDCache[str];
	strCache.push_back(str);
	return IDCache[str] = strCache.size() - 1; 
}
int main()
{
//	freopen("output.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){ 
		getchar();	//丢弃'\n' 
		//输入保存表，并直接预处理为id表 
		IDCache.clear();
		strCache.clear();
		vector<vector<int> > DTable(n,vector<int>(m));
		for(int i = 0; i < n; ++i){
			string str;
			for(int j = 0; j < m-1; ++j){
				getline(cin,str,',');
				DTable[i][j] = GetID(str);
			}
			getline(cin,str);
			DTable[i][m-1] = GetID(str);
		} 
//		cout << DTable[0][0] << " " << DTable[1][2] << endl;
		//对列对枚举，并与行号形成键值对入map
		map<pair<int,int>,int> rmap;
		bool flag = true;
		for(int i = 0; i < m && flag; ++i){	//i列 
			for(int j = i+1; j < m && flag; ++j){	//j列
				rmap.clear();
				for(int r = 0; r < n && flag; ++r){	//r行 
					if(rmap.count(pair<int,int>(DTable[r][i],DTable[r][j])) != 0){
						flag = false;
						cout << "NO" << endl;
						cout << rmap[pair<int,int>(DTable[r][i],DTable[r][j])] + 1<< " " << r + 1<< endl;
						cout << i + 1 << " " << j + 1 << endl;
					} else{
						rmap[pair<int,int>(DTable[r][i],DTable[r][j])] = r;
					}
				} 
			}
		}
		if(flag)
			cout << "YES" << endl;
	}
	return 0;
}
