#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>
#include<thread>
#include <chrono>

using namespace std;

int randint(int a, int b)
{
	uniform_int_distribution<unsigned> u(a,b);
	this_thread::sleep_for(1s);
	default_random_engine e(time(0));
	return u(e);
}
int main()
{
	freopen("Test658.in","w",stdout);
	int T = 66;
	char ch[4] = "0+-";
	while(T--){
		int n = randint(1,20);
		int m = randint(1,100);
		cout << n << " " << m << endl;
		for(int i = 0; i < m; ++i){
			cout << randint(1,10) << " ";
			for(int j = 0; j < n; ++j)
				cout << ch[randint(0,2)];
			cout << " ";
			for(int j = 0; j < n; ++j)
				cout << ch[randint(0,2)];
			cout << endl;
		}
	}
	return 0;
}
