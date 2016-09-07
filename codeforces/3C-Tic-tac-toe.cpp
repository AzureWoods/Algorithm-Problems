#include <iostream>
using namespace std;
char board[4][4];
int isWin(char ch)
{
	int flag=0;
	if(board[0][0]==ch && board[0][1]==ch && board[0][2]==ch)
		flag++;
	if(board[1][0]==ch && board[1][1]==ch && board[1][2]==ch)
		flag++;
	if(board[2][0]==ch && board[2][1]==ch && board[2][2]==ch)
		flag++;
	if(board[0][0]==ch && board[1][0]==ch && board[2][0]==ch)
		flag++;
	if(board[0][1]==ch && board[1][1]==ch && board[2][1]==ch)
		flag++;
	if(board[0][2]==ch && board[1][2]==ch && board[2][2]==ch)
		flag++;
	if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch)
		flag++;
	if(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch)
		flag++;
	return flag;	
}
int main()
{
	int num_x,num_0;
	int is_x,is_0;
	num_x=num_0=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			cin>>board[i][j];
			if(board[i][j]=='X')
				num_x++;
			else if(board[i][j]=='0')
				num_0++;
		}
	is_x=isWin('X');
	is_0=isWin('0');
	if((is_x==1 && is_0==1) || !(num_x==num_0 || num_x==num_0+1) || (num_x==num_0+1 && is_0>0) || (num_x==num_0 && is_x>0))
	{
		cout<<"illegal";
	}
	else {
		if(is_x)
			cout<<"the first player won";
		else if(is_0)
			cout<<"the second player won";
		else {
			if(num_x+num_0==9)
				cout<<"draw";
			else {
				if(num_x==num_0)
					cout<<"first";
				else cout<<"second";
			}
		}
	}
	return 0;
}