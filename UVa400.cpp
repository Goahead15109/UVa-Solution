#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	while(scanf("%d",&N) == 1){
		vector<string> strvec;	//文件名数组 
		string fn;
		int maxsize;	//输入文件名最大长度
		//输入 
		for(int i = 0; i < N; ++i){
			cin >> fn;
			if(i == 0)
				maxsize = fn.size();
			if(maxsize < fn.size())
				maxsize = fn.size();
			strvec.push_back(fn);
		}
		sort(strvec.begin(),strvec.end());
		//计算行列数
		int fsize = strvec.size();	//文件名数量 
		int col = (60-maxsize)/(maxsize+2)+1; 
		int row = (fsize - 1)/col + 1;
		/*
		int row = fsize/col;
		if(fsize%col != 0)
			++row;
		*/
		//输出 
		cout << string(60,'-') << endl;
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				int n = j * row + i;
				if(n < fsize){
					string ts = strvec[n];
					ts += string(maxsize-ts.size(),' ');
					if(j != col-1)
						ts += string(2,' ');
					cout << ts;
				} 
			}
			cout << endl;
		}
	}
	return 0;
}
