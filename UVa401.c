#include<stdio.h>
#include<string.h>
#include<ctype.h>

const char Rev[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *Res[] = {"not a palindrome","a regular palindrome",
					"a mirrored string","a mirrored palindrome"};
char Mirror(char ch)
{
	if(isalpha(ch))
		return Rev[ch-'A'];
	else
		return Rev[ch-'0'+25];
}
int main()
{
	char s[30];
	while(scanf("%s",s)!=EOF){
		int isp = 1;
		int ism = 1;
		for(int i = 0, j = strlen(s)-1; i <= j; ++i,--j){
			if(s[i] != s[j])
				isp = 0;
			if(s[i] != Mirror(s[j]))
				ism = 0;
		}
		printf("%s -- is %s.\n\n",s,Res[ism*2+isp]);
	}
	return 0;
}
