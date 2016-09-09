#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>

using namespace std;

struct snake{
	int X,Y;
};
struct snake head;
struct snake tail;
char arr[200][200];
int r,i,j,presco;
int score=0;
int posX,posY;
char ch,prech;
int foodeat=1;
char sn='@';
void Gotoxy(int x,int y)
{
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
	

}
void createSnake(){
	Gotoxy(tail.X,tail.Y);
	i=tail.Y;
	for(j=tail.X;j<=head.X;j++){
	arr[i][j]='@';
	cout<<sn;
	}
	Gotoxy(81,0);
}
void createSnakeY()
{
	Gotoxy(tail.X,tail.Y);
	i=tail.X;
	for(j=tail.Y;j<=head.Y;j++){
	arr[i][j]='@';
	Gotoxy(i,j);
	cout<<sn;
	}
	Gotoxy(81,0);
	
	
	
}
void food(){

	foodeat=0;
	r=(int) ch;
     GEN:
	 posX=(int)r%71;
 	 posY=(int)r%17;
 	 if(posX==0||posX==79||posY==0||posY==19){
 	 	r+=2;
 	 	goto GEN;
	  } 	 
	  
	 Gotoxy(posX,posY);
	 arr[posX][posY]='#';
	 cout<<"#";
	 Gotoxy(81,0);   	
	
}
void del(){

	Gotoxy(tail.X,tail.Y);
	
	for(i=tail.Y-1;i<=head.Y+2;i++){
	
		for(j=tail.X-1;j<=head.X+2;j++){
	
		arr[j][i]=' ';
		Gotoxy(j,i);
		cout<<" ";
		}
	}Gotoxy(81,0); 
	
}
 
void disp(){
	system("cls");
	for(i=0;i<20;i++){
		for(j=0;j<80;j++){
			
			cout<<arr[i][j];			
			
		}
		cout<<endl;
	
	}
}
void make()
{
	for(i=0;i<20;i++){
		for(j=0;j<80;j++){
			arr[i][j]=' ';
		
			if(i==0||i==19||j==0||j==79)
			{
				arr[i][j]='^';
			}
		
			
		}
	}
}
void moveR(){
	if(prech!=ch)
	{
		del();
		tail.Y=head.Y;
		tail.X=tail.X-2;
		head.X=tail.X+2;
		createSnake();
	}
	else{
	Gotoxy(tail.X,tail.Y);
	arr[tail.X][tail.Y]=' ';
	cout<<' ';
	tail.X++;
	head.X++;
	}
	
	if(head.X==79)
	{
		tail.X=0;
		head.X=tail.X+4;
	}
	createSnake();
	Gotoxy(81,0);
}
void moveL(){
	if(prech!=ch)
	{
		
		del();
		tail.Y=head.Y;
		tail.X=tail.X-2;
		head.X=tail.X+2;
		createSnake();
	}
	else{
	Gotoxy(head.X,head.Y);
	arr[head.X][head.Y]=' ';
	cout<<' ';
	tail.X--;
	head.X--;
	}
	if(tail.X==0)
	{
		head.X=79;
		tail.X=head.X-4;
	}
	createSnake();
	Gotoxy(81,0);
}
void moveU(){
	if(prech!=ch)
	{
	
	del();
	tail.X=head.X;
	tail.Y=tail.Y-2;
	head.Y=tail.Y+2;
	createSnakeY();
	}
	else{
	Gotoxy(head.X,head.Y);
	cout<<" ";
	Gotoxy(81,0);
	
	head.Y--;
	tail.Y--;
	createSnakeY();
	}
	if(tail.Y==0)
	{
		head.Y=20;
		tail.Y=16;
		createSnakeY();
	}
}
void moveD(){
	if(prech!=ch)
	{
	
	del();
	tail.X=head.X;
	tail.Y=head.Y-2;
	head.Y=tail.Y+2;
	createSnakeY();
	}
	else{
	Gotoxy(tail.X,tail.Y);
	cout<<" ";
	Gotoxy(81,0);
	
	head.Y++;
	tail.Y++;
	createSnakeY();
	}
	if(head.Y==20)
	{
		head.Y=4;
		tail.Y=0;
		createSnakeY();
	}
}
int main()
{
 

	tail.X=30;
	tail.Y=10;
	head.X=34;
	head.Y=10;

	system("cls");

 cout<<"SNAKE GAME"<<endl<<"PRESS ENTER TO START";
 cout<<endl;
 cout<<"ENTER W,S,A,D TO MOVE SNAKE:"<<endl<<"PRESS X TO EXIT";
 ch=getche();
 system("cls"); 
 make();
 
 disp();
 food(); 
 createSnake();
 ch=getche();
	while(ch!='x')
	{
  
				if(ch=='d'||ch=='D'){
 						 moveR();
				}
	
				if(ch=='a'||ch=='A'){
 					 moveL();
				}
				if(ch=='w'||ch=='W'){
 					 moveU();
				}
			
				if(ch=='s'||ch=='S'){
 					 moveD();
				}
			
			
				if(((head.X==posX)&&(head.Y==posY))||((tail.X==posX)&&(tail.Y==posY)))
				{
				foodeat=1;
				presco=score;
				score++;
				food();
				
				}	
		prech=ch;
		ch=getche();
		if(prech!=ch){
			del();
		}
		if(presco==score&&arr[posX][posY]!='#')
		{food();
		}
		Gotoxy(40,21);
		cout<<"SNAKE GAME ";
		Gotoxy(81,21);
		cout<<"SCORE : "<<score;
		Gotoxy(81,0);
	}
	

getch();
return 0;
}
