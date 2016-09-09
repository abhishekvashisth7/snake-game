////Fixing bugs...

#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<windows.h>

char arr[200][200];
int i,j;
int x=30,y=10;
char ch;

using namespace std;
/*void gotoxy(int x,int y)
{

}*/
void createSnake(){

	i=y;
	arr[i][x-1]=' ';
	for(j=x;j<x+4;j++){
	arr[i][j]='@';
	}
} 
void disp(){
	system("cls");
	for(i=0;i<20;i++){
		for(j=0;j<80;j++){
			cout<<arr[i][j];
			
		}cout<<endl;
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
		
			cout<<arr[i][j];
			
		}cout<<endl;
	}
}
void move0(){
	x++;
	createSnake();
	disp();
}
int main()
{
system("cls");

 cout<<"START";
 cout<<endl;
 make();
 createSnake();
 disp();
 while(1){ 
 move0();
}
getch();
return 0;
}
