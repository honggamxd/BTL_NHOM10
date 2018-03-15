#include<bits/stdc++.h>
#define Nmax 99999
using namespace std;
list<string> a[Nmax];
int FunHash(string s){
long sum=0;
	for(int i=0;i<s.length();i++)
		sum+=(s[i]-'a')*(i+1)+1;
		
	return sum%Nmax;
		
}

bool Check(string s){
list<string>:: iterator x= a[FunHash(s)].begin();
list<string>:: iterator y= a[FunHash(s)].end();
	for(;x!=y;x++)
		if(*x==s) return(true);
	return(false);
}
void InPut(){
string s;
ifstream cin1("dictionary.txt");
	while(!cin1.eof()){
		cin1>>s;
		if(s.length()>=4)
		a[FunHash(s)].push_back(s);
	}
cout<<Check("mites");
}

main(){
InPut();
}

