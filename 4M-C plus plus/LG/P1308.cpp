#include<iostream>
#include<stdio.h>	//getchar
using namespace std;

int main()
{
    string word;
    string sent;
    cin>>word;
    getchar();  //����getchar()��ִ����������
    getline(cin,sent);  //������������ո�
    
    //ͳһתСд
    for(int i=0;i<word.length();i++){
        word[i]=tolower(word[i]);
    }
    for(int i=0;i<sent.length();i++){
        sent[i]=tolower(sent[i]);
    }

    //����ʱ���õ���ǰ���пո�
    word.insert(0," "); word.push_back(' ');
    sent.insert(0," "); sent.push_back(' ');

    //find()�����Ҳ����㷵��-1���ҵõ��򷵻ص�һ�����±�
    if(sent.find(word)==-1){
        cout<<-1;
        return 0;
    }
    else{
        int countn=0,n=0;
        while(sent.find(word,n)!=-1){
            ++countn;
            n=sent.find(word,n)+1;  //���Ѳ��ҵ��ĵط�����һ��λ�ò���
        }
        cout<<countn<<" "<<sent.find(word);
    }
}

