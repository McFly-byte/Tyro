#include <cstdio>
using namespace std;

int main()
{
	int N,num,id=1,pay;
	long long int fee,cost;
	scanf( "%d",&N );
	while( N-- ){
		scanf( "%d%I64d%d",&num,&fee,&pay );
		//��Ҫ�¼����������ӱ������Ϻ����Ϻ��������ĵ��κ������
		//�Լ��ڱ���ͣ��һ��Ĺ��� 
		long long int thisday=0, lastday=0, remaindays=1;
		scanf("%I64d",&lastday);
		cost = 0;//�ܷ��� 
		for( int i = 1 ; i < num ; i++ ){	//printf("%d\n",cost);
			scanf( "%I64d",&thisday );
			if( ( thisday - lastday  ) * pay > fee * 2 ){
				cost += ( remaindays*pay + fee*2 );	//printf("%d\n",remaindays);
				remaindays = 1;
			}
			else
				remaindays += ( thisday - lastday );
			lastday = thisday;
		}//printf("%I64d\n",remaindays);
		cost += ( remaindays*pay + fee*2 );//���һ��ȥBJû�б����� 
		printf( "Case #%d: %I64d\n",id++,cost );
	}
} 
