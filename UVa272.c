#include<stdio.h>

int main()
{
	char ch;
	int q = 1;
	while((ch = getchar())!=EOF){
		if(ch == '"'){
			printf("%s",q?"``":"''");
			q = !q;
		}
		else
			printf("%c",ch);
	}
	return 0;
}
