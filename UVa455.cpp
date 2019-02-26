#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	while(N--){
		string str;
		cin >> str;
		int len = str.size();
		bool flag = 0;
		for(int sz = 1;sz <= len/2;++sz){	//sz表示子字符串长度 
			flag = 0;
			if(len%sz==0){
				flag = 1;
				int k = 0;
				int j = sz;
				while(j < len){
					if(str[k] == str[j]){
						++k;
						++j;
					}
					else{
						flag = 0;
						break;
					}
				}
			}
			if(flag){
				printf("%d\n",sz);
				break;
			}
		}
		if(!flag)
			printf("%d\n",len);
		
		if(N)	//最后一个输出不需要第二次换行 
			printf("\n");
	}
	return 0;
}
