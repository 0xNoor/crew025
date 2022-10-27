#include<stdio.h>
void show(void);
void reset(void);
void replay(void);
void check(void);
void diag(void);
void hori(void);
void vert(void);
int i,j,flag=0,win=0,temp=0;
char matrix[3][3],dummy;
int main(void){
	printf("Hello ! This is a simple tic-tak-toe.\n");
	printf("This game is played by 2 players one by one.\nEnter the respective place where you want to place your move.\nEnter row positon,then by pressing tab,Enter column position :-\n	ex->1	1\n");
	reset();
	do{
		show();							//input
		printf("Player A enter your turn :- ");
		scanf("%d	%d",&i,&j);
		printf("\n");
		matrix[i][j] ='X';
		temp++;
		diag();
		hori();
		vert();
		check();
		if(win==1 || temp>7)
			break;
		show();
		printf("Player B enter your turn :- ");
		scanf("%d	%d",&i,&j);
		printf("\n");
		matrix[i][j]='O';
		temp++;
		diag();
		hori();
		vert();
		check();
		if(win==1 || temp>7)
			break;
	}while(flag!=1);
	return 0;
}
void show(void){							//print
	printf("		0	1	2\n\n");
	for(i=0;i<=2;i++){
		printf("	%d",i);
		for(j=0;j<=2;j++){
			printf("	%c",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void reset(void){							//in case of restart reset matrix
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			matrix[i][j]= '\0';
		}
	}
	temp=0;
}
void replay(void){
	printf("Want to play again ? TYPE [Y/y] or [N/n] : ");
	scanf(" %c",&dummy);
	if(dummy=='Y' || dummy=='y'){
		reset();
		flag=0;
		win=0;
	}
}
void check(void){								//check if someone wins
	if(win==1){
		if(temp%2!=0)
			printf("\nPlayer A wins !!\n\n");
		else
			printf("\nPlayer B wins !!\n\n");
		flag=1;
		show();
		replay();
	}
	else if(temp>7){
		printf("	Sed\n	Game Draws\n");
		replay();
	}
}
void diag(void){							//if win is diagonal
	if( matrix[1][1]!='\0' && (((matrix[0][0]==matrix[1][1]) && (matrix[0][0]==matrix[2][2])) || ((matrix[0][2]==matrix[1][1]) && (matrix[2][0]==matrix[1][1])))){
		win=1;
		printf("\nDiagonal win.\n");
	}
}
void hori(void){							//if win is horizontal
	for(i=0;i<=2;i++){
		if(matrix[i][0]!='\0' && (matrix[i][0]==matrix[i][1]) && (matrix[i][0]==matrix[i][2])){
			win=1;
			printf("\nHorizontal win.\n");
		}
	}
}
void vert(void){							//if win is vertical
	for(i=0;i<=2;i++){
		if(matrix[0][i]!='\0' && (matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i]) ){
			win=1;
			printf("\nVertical win.\n");
		}
	}
}
