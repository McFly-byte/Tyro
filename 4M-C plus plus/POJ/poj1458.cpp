#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[1001];
char s2[1001];
int maxlen[1000][1000];

int main()
{
	while(cin>>s1>>s2){
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for(int i=0;i<=len1;i++)
			for(int j=0;j<len2;j++)
				maxlen[i][j] = 0;
		for(int i=0;i<len1;i++)
			maxlen[i][0] = 0;
		for(int j=0;j<len2;j++)
			maxlen[0][j] = 0;
		for(int i=1;i<=len1;i++)
			for(int j=1;j<=len2;j++)
			{
				if(s1[i-1]==s2[j-1])
					maxlen[i][j] = maxlen[i-1][j-1] + 1;
				else
					maxlen[i][j] = max(maxlen[i-1][j],maxlen[i][j-1]); 
			}
		cout<<maxlen[len1][len2]<<endl;
	}	
	return 0;
}
