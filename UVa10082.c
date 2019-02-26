#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char ch;
	while((ch = getchar())!=EOF){
		if(ch == ' ' || ch == '\n'){
			putchar(ch);
			continue;
		}
		for(int i = 1; i < strlen(s);++i){
			if(ch == s[i])
				printf("%c",s[i-1]);
		}
	}
	return 0;
}
