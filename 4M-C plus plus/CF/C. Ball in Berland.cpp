#include <bits/stdc++.h>
using namespace std;

struct node {
	int boy , girl;
};

const int maxn = 200001;
long long f1[maxn];
long long f2[maxn]; 

int main()
{
	long long t , a ,b , k;
	cin >> t;
	while ( t-- ){
		cin >> a >> b >> k;
		node n[k];
		for ( int i = 0; i < k; i++ ) {
			cin >> n[i].boy;
			f1[n[i].boy] ++;
		}
		for ( int j = 0; j < k; j++ ) {
			cin >> n[j].girl;
			f2[n[j].girl] ++;
		}
		long long sum = 0;
		for ( int i = 0; i < k; i++ ){
			if( f1[n[i].boy] > 0 ){
				sum = sum + (long long)( f1[n[i].boy] * (f1[n[i].boy]-1) ) / 2;
				f1[n[i].boy] = 0; //ÿ�ֱ�ŵ�boy/girlֻͳ��һ�� 
			}
			if( f2[n[i].girl] > 0 ){
				sum = sum + (long long)( f2[n[i].girl] * (f2[n[i].girl]-1) ) / 2;
				f2[n[i].girl] = 0; 
			}
		}
		cout << (long long)(k * (k - 1) / 2)  - sum << endl;
		
//		int count = 0;
//		for ( int i = 0; i < k-1; i++ ){
//			for ( int j = i+1; j < k; j++ ){
//				if( n[j].boy != n[i].boy && n[j].girl != n[i].girl ) count++;
//			}
//		}
//		cout << count << endl;
		
	}
}

/* ��� 
#include <bits/stdc++.h>
using namespace std;
long long freq1[200001];		//ȫ��Ĭ��Ϊ0 
long long freq2[200001];
int main()
{
#ifndef ONLINE_JUDGE
	//FOR GETTING INPUT FROM INPUT.TEXT
	freopen("input", "r", stdin);
	//for getting output to output.txt
	freopen("output", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long b, g, k; 			//b,g����ûʲô�� 
		cin >> b >> g >> k;
		int arr[k];
		int brr[k];
		for (int j = 0; j < k; j++)
		{
			cin >> arr[j];
		}
		for (int j = 0; j < k; j++)
		{
			cin >> brr[j];
		}
		for (int j = 0; j < k; j++)
		{
			freq1[arr[j]]++;
		}
		for (int j = 0; j < k; j++)
		{
			freq2[brr[j]]++;
		}
		long long sum = 0;
		for (int j = 0; j < k; j++)		//��Ҫ˼·���ܵļ�ȥboy�ظ������
										//��girl�ظ������ 
		{								//��Ϊ������һ���ģ�boy��girl����� 
			if (freq1[arr[j]] > 0)		//��boy�ظ��������girl�ظ�������޽��� 
			{
				sum = sum + (long long)(freq1[arr[j]] * (freq1[arr[j]] - 1) / 2);
				freq1[arr[j]] = 0;
			}
			if (freq2[brr[j]] > 0)
			{
				sum  = sum + (long long)(freq2[brr[j]] * (freq2[brr[j]] - 1) / 2);
				freq2[brr[j]] = 0;
			}
		}
		cout << (long long)(k * (k - 1) / 2)  - sum << endl;
 
	}
	return 0;
}
*/ 
