#include<bits/stdc++.h>
#define Nmax 99999
using namespace std;

list<string> a[Nmax];
fstream rgrid("grid.txt");
fstream word("word.txt");

int FunHash(string s)
{
    long sum=0;
        for(int i=0;i<s.length();i++)
            sum+=(s[i]-'a')*(i+1)+1;

        return sum%Nmax;
}

bool Check(string s)
{
    list<string>:: iterator x= a[FunHash(s)].begin();
    list<string>:: iterator y= a[FunHash(s)].end();
	for(;x!=y;x++)
		if(*x==s) return(true);
	return(false);
}

void Inputdic()
{
    string s;
    ifstream cin1("dictionary.txt");
	while(!cin1.eof())
	{
		cin1>>s;
		if(s.length()>=4)
		a[FunHash(s)].push_back(s);
	}
}

void Inputgrid( char **A, int n, int m)
{
	int i,j;
	for( i =1; i <= n; i++)
	{
		for( j = 1; j <= m; j++)
			rgrid >> A[i][j];
	}
}

string strrev( string s )
{
    int i;
    string str;
    for( i = s.length() - 1 ; i >= 0; --i)
        str.push_back(s[i]);
    return str;
}

void gridSearch(char **A, int i, int j, int n, int m)
{
	int h = i ,k = j;
	string S1,S2,S3,S4;
	while( k <= m){
		S1.push_back( A[h][k] );
		string S = strrev(S1);
		if( Check(S1))
			word << S1 << " ( " << i << " , " << j << " )" << endl;
        if( Check(S) )
            word << S << " ( " << h << " , " << k << " )" << endl;
        k++;
    }
	k = j;
	while( h <= n){
		S2.push_back( A[h][k] );
		string S = strrev(S2);
		if( Check(S2))
			word << S2 << " ( " << i << " , " << j << " )" << endl;
        if( Check(S) )
            word << S << " ( " << h << " , " << k << " )" << endl;
        h++;
	}
	h = i;
	while( k <= m && h <= n){
		S3.push_back( A[h][k] );
		string S = strrev(S3);
		if( Check(S3))
			word << S3 << " ( " << i << " , " << j << " )" << endl;
        if( Check(S) )
            word << S << " ( " << h << " , " << k << " )" << endl;
        k++;
		h++;
    }
	h = i,k = j;
	while( h <= n && k >= 1){
		S4.push_back( A[h][k] );
		string S = strrev(S4);
		if( Check(S4))
			word << S4 << " ( " << i << " , " << j << " )" << endl;
        if( Check(S) )
            word << S << " ( " << h << " , " << k << " )" << endl;
        h++;
		k--;
	}
}

void Output( char **A, int n, int m)
{
	int i,j;
	cout << n << " " << m << endl;
	for( i = 1; i <= n; i++)
	{
		for( j = 1; j <= m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
    cout << endl;
}


main()
{
	int N,M,i,j;
	rgrid >> N >> M;
	char **A = new char*[N];
	for( i = 1; i <= N; i++)
		A[i] = new char[M];

	Inputgrid(A,N,M);
	Inputdic();
	for( i = 1; i <= N; i++)
	{
		for( j = 1; j <= M; j ++)
			gridSearch(A,i,j,N,M);
	}
	Output(A,N,M);
	rgrid.close();
	word.close();

	for(i = 1; i <= N; i++)
        delete []A[i];
    delete []A;
}
