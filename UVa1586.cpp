#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<cctype>

using namespace std;

const double mc = 12.01;
const double mh = 1.008;
const double mo = 16.00;
const double mn = 14.01;

int main()
{
	int T;
	scanf("%d",&T);
	for(int i = 0; i < T; ++i){
		map<char,int> mol{{'C',0},{'H',0},{'O',0},{'N',0}};
		string s;
		cin >> s;
		int k = 0;
		while(k < s.size()){
			if(k+1>= s.size() || isalpha(s[k+1])){
				++mol[s[k]];
				++k;
			}
			else{
				if(k+2>= s.size() || isalpha(s[k+2])){
					mol[s[k]] += (s[k+1] - '0');
					k += 2;
				}
				else{
					mol[s[k]] += (s[k+1] - '0')*10+(s[k+2]-'0');
					k += 3;
				}
			}
		}
		double ret = mol['C']*mc+mol['H']*mh+mol['O']*mo+mol['N']*mn;
		printf("%.3f\n",ret);
	}
	return 0;
}

