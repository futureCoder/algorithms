#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
    void reverse(string &s,int start,int end){
        for(int i = start,j = end;i<j;++i,--j)
            swap(s[i],s[j]);
        return;
    }
    void reverseWords(string &s) {
        if(s.size()<2) return ;
        int len = s.size(),i=0;
        reverse(s,0,len-1);
        for(int start = 0,end=0;end<len;start = end){
            while(s[start]==' ') ++start;
            end = start;
            while(s[end]!=' '&&end<len) ++end;
            reverse(s,start,end-1);
        }
        return ;
    }
int main(){
	string s("                           ");
	reverseWords(s);
	cout<<s<<"-"<<endl;
}
