#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<cstdio>
using namespace std;
int main()
{
	int m;
	while(scanf("%d",&m) == 1){
		vector<vector<int> > IPAddr(m,vector<int>(4));
		//读取ip地址 
		for(int x = 0; x < m; ++x){
			string s;
			for(int i = 0; i < 3; ++i){
				getline(cin,s,'.');
				IPAddr[x][i] = stoi(s);
			}
			getline(cin,s);
			IPAddr[x][3] = stoi(s);
		}
		//得出第一个不同的十进制值 
		int j;
		bool flag = true;
		for(j = 0; j < 4; ++j){
			int t = IPAddr[0][j];
			for(int i = 0; i < m; ++i){
				if(t != IPAddr[i][j]){
					flag = false;
					break;
				}
			}
			if(!flag)
				break;
		}
		
		if(j == 4){	//所有IP均相同 
			cout << IPAddr[0][0] << "." << IPAddr[0][1] << "."
				<< IPAddr[0][2] << "." << IPAddr[0][3] << endl;
			cout << "255.255.255.255" << endl;
		}
		else{
			set<int> ipset;
			int mask = 255;
			while(mask = (mask << 1)&255){
				ipset.clear();	
				for(int i = 0; i < m; ++i){
					ipset.insert(IPAddr[i][j]&mask);
				} 
				if(ipset.size()==1)
					break;
			}
			string netaddr = "";
			string submask = "";
			for(int i = 0; i < j; ++i){
				netaddr += to_string(IPAddr[0][i]);
				netaddr += ".";
				submask += "255";
				submask += ".";
			}
			netaddr += to_string(*ipset.begin());
			submask += to_string(mask);
			if(j < 3){
				netaddr += ".";
				submask += ".";
			}
			++j;
			for(; j < 4; ++j){
				netaddr += "0";
				submask += "0";
				if(j < 3){
					netaddr += ".";
					submask += ".";
				}
			}
			cout << netaddr << endl;
			cout << submask << endl;
		}
	}
	return 0;
}
