#include<iostream>
using namespace std;
#include<conio.h>
#include<bits/stdc++.h>
void upmove(int a[4][4]){
		for(int c=0;c<4;++c){
			int x=0;
			for(int r=1;r<4;++r){
				if(a[r][c]!=0){
				if(a[r-1][c]==0||a[r-1][c]==a[r][c]){
					if(a[x][c]==a[r][c]){
						a[x][c]*=2;
						a[r][c]=0;
					}
					else{
						if(a[x][c]==0)
						a[x][c]=a[r][c];
						else
						a[++x][c]=a[r][c];
						a[r][c]=0;
					}
				}
				else{
					x++;
				}
			}
		}
	}
}
void downmove(int a[4][4]){
	for(int c=0;c<4;++c){
		int x=3;
		for(int r=2;r>=0;--r){
			if(a[r][c]!=0){
				if(a[r+1][c]==a[r][c]||a[r+1][c]==0){
					if(a[x][c]==a[r][c]){
						a[x][c]*=2;
						a[r][c]=0;
					}
					else{
						if(a[x][c]==0){
							a[x][c]=a[r][c];
						}
						else{
							a[--x][c]=a[r][c];
						}
						a[r][c]=0;
					}
				}
				else{
					--x;
				}
			}
		}
	}
}
void leftmove(int a[4][4]){
	for(int r=0;r<4;++r){
		int y=0;
		for(int c=1;c<4;++c){
			if(a[r][c]!=0){
				if(a[r][c-1]==0||a[r][c-1]==a[r][c]){
					if(a[r][y]==a[r][c]){
						a[r][y]*=2;
						a[r][c]=0;
					}
					else{
						if(a[r][y]==0){
							a[r][y]=a[r][c];
						}
						else
						a[r][++y]=a[r][c];
						a[r][c]=0;
					}
				}
				else
				++y;
			}
		}
	}
}
void rightmove(int a[4][4]){
	for(int r=0;r<4;++r){
		int y=3;
		for(int c=2;c>=0;--c){
			if(a[r][c]!=0){
				if(a[r][c+1]==a[r][c]||a[r][c+1]==0){
					if(a[r][c]==a[r][y]){
						a[r][y]*=2;
						a[r][c]=0;
					}
					else{
						if(a[r][y]==0){
							a[r][y]=a[r][c];
						}
						else{
							a[r][--y]=a[r][c];
						}
						a[r][c]=0;
					}
				}
				else
				--y;
			}
		}
	}
}
void display(int a[4][4])
{
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}
int check(int temp[4][4],int a[4][4]){
	for(int r=0;r<4;++r){
		for(int c=0;c<4;++c){
			if(temp[r][c]!=a[r][c])
			return 0;
			}
		}
		return 1;
}
void addblock(int a[4][4]){
	int x1=0,y1=0;
	srand(time(0));
	while(1){
		x1=rand()%4;
		y1=rand()%4;
		if(a[x1][y1]==0){
		a[x1][y1]=2*(x1%2+1);
		break;	
		}
	}
}
bool checkover(int a[4][4]){
	bool empty=false,adj=false;
	for(int r=0;r<4;++r){
		for(int c=0;c<4;++c){
			if(a[r][c]==0){
				empty=true;
				break;
			}
			}
		}
	for(int r=0;r<3;++r){
		for(int c=0;c<3;++c){
			if(a[r][c]==a[r+1][c]||a[r][c]==a[r][c+1]){
				adj=true;
				break;
			}
		}
	}
	return empty||adj;
}
int main(){
	int a[4][4]={0},temp[4][4]={0};
	cout<<"\n\n\n\n\t\t\t2048 GAME \n\n\t\t\tpress any key to start the game\n\n";
	getch();
	system("cls");
	int x1=0,y1=0,x2=0,y2=0,input=0;
	srand(time(0));
	x1=rand()%4;
	y1=rand()%4;
	while(1){
	x2=rand()%4;
	y2=rand()%4;
	if(x1!=x2 || y1!=y2){
		break;
	}	
	}
	a[x1][y1]=2;
	a[x2][y2]=4;
	display(a);
	int m=0;
	while(1){	
	input=getch();
	if(input==72) upmove(a);
	else if(input==75) leftmove(a);
	else if(input==77) rightmove(a);
	else if(input==80) downmove(a);
	else if(input==27) break;
	if(!check(a,temp)){
		addblock(a);
	}
		for(int r=0;r<4;++r){
		for(int c=0;c<4;++c){
			temp[r][c]=a[r][c];
			m=max(m,a[r][c]);
		}
	}
	system("cls");
	display(a);
	cout<<"\n\n\t\t  SCORE : "<<m<<endl;
	if(!checkover(a)){
		cout<<"\n\n\n \t\t\t GAME OVER";
		break;
	}
	}
	
	return 0;
}
