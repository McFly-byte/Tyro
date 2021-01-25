#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool isEql(string a , string aa )
{
	int alen = a.length(), aalen = aa.length();
	int i = alen - 1;
	for( ; a[i] == ' ' || a[i] == '\t' ; i-- ) a[i] = '\0';
	for( i = 0; a[i] == ' ' || a[i] == '\t' ; i++ ) ;
	int j = aalen - 1;
	for( ; aa[j] == ' ' || aa[j] == '\t' ; j-- ) aa[j] = '\0';
	for( j = 0; aa[j] == ' ' || aa[j] == '\t' ; j++ ) ;
	//cout << &a[i] << endl;
	//cout << &aa[j] << endl;
	if( strcmp( &a[i] , &aa[j] ) == 0 ) return true;
	return false; 
}

bool cmpfile( const char * file1 ,const char * file2 )
{
	ifstream srcFile( file1  );
	if( !srcFile.is_open() ){
		cout << "file1 failed.\n";
		return false;
	}
	ifstream destFile( file2 );
	if( !destFile.is_open() ){
		cout << "file2failed.\n";
		return false;
	} 
	//vector<char> s,d;
	bool ans = true;
	//char ch1 , ch2;// 定义字符数组用来接受读取一行的数据
	string a , b;
    //int i = 0 , j = 0;
    while(getline(srcFile,a)){
    	getline(destFile,b);
		if( !isEql( a , b  ) ){
			ans = false;
			break;
		} 
	}
	
	destFile.close();
	srcFile.close();
	return ans;
}



int main()
{
	string txt1 , txt2;
	cout << "文件1：" << endl;
	getline( cin , txt1 );
	cout << "文件2：" << endl;
	getline( cin , txt2 );
	char file1[100] = "D:\\4M-C plus plus\\cpp_homework\\Compfile(6)\\txts\\1.txt",
 		 file2[100] = "D:\\4M-C plus plus\\cpp_homework\\Compfile(6)\\txts\\2.txt";
	ofstream f1( file1 , ios::out );
	ofstream f2( file2 , ios::out );
	f1 << txt1;
	f2 << txt2;
	f1.close();//妈的忘关了看了一晚上 
	f2.close();
	
	if( cmpfile( file1 , file2 ) ) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
