#include<string.h>
#include<iostream.h>
int main()
{ 	
	char s[50];
	cin.getline(s,50);
	cout<<s<<endl;
	cout.write(s,strlen(s)); 
	return 0;
}
