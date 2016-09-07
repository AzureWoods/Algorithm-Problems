#include <iostream>
#include <string>
#define MOD 1000003
using namespace std;
class User
{
public:
	string name;
	int number;
	User();
};
User::User():name(""),number(0){}
int main()
{
	User Register[200000];
	string ch;
	int n;
	int hashValue;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch;
		hashValue=0;
		for(int j=0;j<ch.length();j++)
			hashValue+=ch[j]*j;
		hashValue%=MOD;
		while(Register[hashValue].name!="" && Register[hashValue].name!=ch)
			hashValue=(hashValue+1)%MOD;
		if(Register[hashValue%MOD].name=="")
		{
			cout<<"OK"<<endl;
			Register[hashValue].name=ch;
		}
		else
		{
			Register[hashValue].number++;
			cout<<ch<<Register[hashValue].number<<endl;
		}
	}
	return 0;
}
