#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> p1;
vector<int> p2;
vector<int> p3;

int n, m;
int M[3][55];
int num[3];
int b[2] = {0, 0};
int tm = 0;

void input(vector<int> p, int M[]){ //传入数组可能太占空间 
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		p.push_back(a);
		M[a]++;
	}
}

void deal(int a, int M[], int vmin, int wmin){
	for(int i = vmin + 1; i <= m; i++){
		if(M[i] >= wmin){
			num[a]-= wmin;
			M[i]-= wmin;
			b[0] = i;
			b[1] = wmin;
			tm = 0;
			return;
		}
	}
	for(int i = 1; i <= m; i++){
		if(M[i] > wmin){
			num[a] -= wmin + 1;
			M[i]-= wmin + 1;
			b[0] = i;
			b[1] = wmin + 1; 
			tm =0;
			return;			
		}
	}
	tm++;
	if(tm == 3){
		b[0] = 0;
		b[1] = 0;
	}
}

int main (){
	cin >> n >> m;
	num[0] = n;
	num[1] = n;
	num[2] = n;
	memset(M, 0, sizeof(M));
	
	input(p1, M[0]);
	input(p2, M[1]);
	input(p3, M[2]);
	
	/*for(int i = 0; i <= 2; i++){
		for(int j = 1; j <= m; j++){
			cout <<M[i][j] << " ";
		}
		cout << endl;
	} */
		
			
	
	int vmin = 0, wmin = 1;
	
	int i = 0 ;
	
	while(i < 3){
		//cout <<	vmin <<" "<< wmin << endl;
		deal(i, M[i], vmin, wmin);	//出牌
		//cout << "每人剩余排数" << num[0] << " " <<num[1] << " " << num[2] <<endl;
		 
		//cout << "输出函数返回值：" << i << " " << b[0] <<" "<< b[1]<< endl;
		if(b[0] != 0){
			vmin = b[0];
			wmin = b[1];
			
			if(i == 2)
	 			i = 0;
			else
				i++;			
		}
		else{
			vmin = 0;
			wmin = 1;
		}
		//cout << "输出上一轮出的牌："<<vmin <<" "<< wmin << endl;
		//cout << "剩余的牌" <<endl; 
		/*for(int i = 0; i <= 2; i++){
		for(int j = 1; j <= m; j++){
			cout <<M[i][j] << " ";
		}
		cout << endl;
	} */
		if(num[i] == 0){
			cout << i+1;
			break;
		}
		//j++;
	}
	return 0;
}
