#include<iostream>
#include<stdio.h>	//getchar
using namespace std;

int main()
{
    string word;
    string sent;
    cin>>word;
    getchar();  //不加getchar()不执行下面输入
    getline(cin,sent);  //输入允许包含空格
    
    //统一转小写
    for(int i=0;i<word.length();i++){
        word[i]=tolower(word[i]);
    }
    for(int i=0;i<sent.length();i++){
        sent[i]=tolower(sent[i]);
    }

    //搜索时利用单词前后有空格
    word.insert(0," "); word.push_back(' ');
    sent.insert(0," "); sent.push_back(' ');

    //find()函数找不到便返回-1，找得到则返回第一个的下标
    if(sent.find(word)==-1){
        cout<<-1;
        return 0;
    }
    else{
        int countn=0,n=0;
        while(sent.find(word,n)!=-1){
            ++countn;
            n=sent.find(word,n)+1;  //从已查找到的地方的下一个位置查找
        }
        cout<<countn<<" "<<sent.find(word);
    }
}

