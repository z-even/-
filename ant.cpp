#include <iostream>
using namespace std;
int m=60,n=188,t=20000;//�������棬����Ķ���С 
char room[60][188];  //�趨����ߺͿ� 
int before[2]={94,30};//�趨��ʼλ�� 
int now[2]={94,31};	  //���ʼ���� 

void change0()//ת�亯��0 
{
	room[now[1]][now[0]]='B';
	before[0]=now[0];
 	before[1]=now[1];
}

void change1()//ת�亯��1 
{
	room[now[1]][now[0]]=' ';
	before[0]=now[0];
 	before[1]=now[1];
}

void move()//�����ƶ�һ����� 
{

 	if(before[0]>now[0]&&before[1]==now[1])//���� 
 	{
 		if(room[now[1]][now[0]]==' ')//�հ� ��ת 
 		{
 			change0();
 			now[1]++;
		 }
		 else if(room[now[1]][now[0]]=='B')//��ɫ ��ת 
 		{
 			change1();
 			now[1]--;
		 }
	 }
	else if(before[0]<now[0]&&before[1]==now[1])//����
	 {
	 	if(room[now[1]][now[0]]==' ')//�հ� ��ת 
 		{
 			change0();
 			now[1]--;
		 }
		else if(room[now[1]][now[0]]=='B')//��ɫ ��ת 
 		{
 			change1();
 			now[1]++;
		 }
	  }
	else if(before[0]==now[0]&&before[1]<now[1])//���� 
 	{
 		if(room[now[1]][now[0]]==' ')//�հ� ��ת 
 		{
 			change0();
 			now[0]++;
		 }
		else if(room[now[1]][now[0]]=='B')//��ɫ ��ת 
 		{
 			change1();
 			now[0]--;
		 }
	 }
 	else if(before[0]==now[0]&&before[1]>now[1])//���� 
 	{
 		if(room[now[1]][now[0]]==' ')//�հ� ��ת 
 		{
 			change0();
 			now[0]--;
		 }
		else if(room[now[1]][now[0]]=='B')//��ɫ ��ת 
 		{
 			change1();
 			now[0]++;
		 }
	 }
 }

int main()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		room[i][j]=' ';//�趨�հ����� 
	}
	
	//�������ܣ��趨��ʼ��ͼ
	cout<<"���һЩ�ڿ飬����Ҫ�ӵĸ�����" <<endl;
	int e;
	cin>>e;
	if(e!=0)
	for(int c=0;c<=e-1;c++)//ѭ�� d �� 
	{
		cout<<"��ʽΪ ������ӿո��������"<<endl;
		int a,b;
		cin>>a>>b;
		if(a<=n&&b<=m)
		{
			room[b][a]='B';
		} 
	}
	
	//room[30][90]='B';//???ֱ�ӻ��˸����� 
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<room[i][j];
		cout<<endl;
	}//����Ϊ��ʼ����������հ�����
	cout<<endl;//���У��������һ�� 
	for(int k=1;k<=t;k++)//�����ж� t �� 
	{
		move();
	}
	for(int i=1;i<=m;i++)//����Ϊ����˶���� 
	{
		for(int j=1;j<=n;j++)
		{
			cout<<room[i][j];
		}
		cout<<endl;
	}
	return 0; 
}
