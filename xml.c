#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLACK "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[1;0m"
struct configuration{

    int hight;
    int wedth;
    int top;

};
int x = 0,y = 1 ;

time_t begin;
time_t end;

void reset(){

    system("");
    printf(RESET);

}
void yellow(){

    system("");
    printf(YELLOW);

}
void red(){

    system("");
    printf(RED);
}
void green(){

    system("");
    printf(GREEN);
}
void black(){

    system("");
    printf(BLACK);
}

//printing board function
void printing_board (int row, int column, char display[row][column])
{
    int i, j, k ;
    for (k = 0; k  < column; k++)
        printf("   %d", k+1) ;
    printf("\n") ;
    for(k = 0; k <= column; k++)
        printf("----") ;
    printf("\n") ;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf(" | ") ;
            if(display[i][j]=='X'){

                green();
                printf("%c", display[i][j]) ;
                reset();
                continue;
            }
            if(display[i][j]=='O'){

                red();
                printf("%c", display[i][j]) ;
                reset();
                continue;
            }
            printf("%c", display[i][j]) ;
        }

        printf(" |") ;
        printf("\n") ;
    for(k = 0; k <= column; k++)
        printf("----") ;
    printf("\n") ;
    }
}


//printing empty board in the beginning of each new game
void empty_board(int row, int column, char display[row][column])
{
    int i, j ;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
            display[i][j] = ' ' ;
    }
    printing_board(row, column, display) ;
}

//checking of full board
int check_board (int row, int column, char display[row][column])
{
    int i ;
    for(i = 0; i < column; i++)
    {
        if (display[0][i] == ' ')
            break ;
    }
    if (i == column && display[0][column-1] != ' ')
        return 1 ;      //board is full
    else
        return 0 ;      //board isn't full
}

//score of each player
int sop1=0,sop2=0,rows,cols;

int score(int x,int y, char arr[rows][cols], char ch,int dir){
    //printf("____inside score %d_____",dir);
    int n=0,s=0,e=0,w=0,nw=0,se=0,ne=0,sw=0;
    int scoree=0;
    if((arr[x][y]!=ch)||(x>=rows)||(y>=cols)){
        return 0;
    }
    if((x<0)||(y<0)){
        return 0;
    }
    if((dir==1)||(dir==0))n=score(x,y+1,arr,ch, 1);
    if((dir==5)||(dir==0))s=score(x,y-1,arr,ch,5);
    if((dir==7)||(dir==0))w=score(x-1,y,arr,ch,7);
    if((dir==3)||(dir==0))e=score(x+1,y,arr,ch,3);
    if((dir==2)||(dir==0))ne=score(x+1,y+1,arr,ch,2);
    if((dir==6)||(dir==0))sw=score(x-1,y-1,arr,ch,6);
    if((dir==8)||(dir==0))nw=score(x-1,y+1,arr,ch,8);
    if((dir==4)||(dir==0))se=score(x+1,y-1,arr,ch,4);


    if(dir==0){
        //printf("%d_%d_%d_%d_%d_%d_%d_%d\n",n,s,e,w,nw,se,ne,sw);
        if((n+s+1)>=4){
            scoree+=1;
            if(n+s>=4)
                scoree+=(n>s) ? s : n;
    }


        if((e+w+1)>=4){
            scoree+=1;
            if(e+w>=4)
                scoree+=(e>w) ? w : e;
        }

        if((ne+sw+1)>=4){
            scoree+=1;
            if(ne+sw>=4)
                scoree+=(ne>sw) ? sw : ne;
        }

        if((nw+se+1)>=4){
            scoree+=1;
            if(nw+se>=4)
                scoree+=(nw>se) ? se : nw;
        }
        //printf("%d\n",scoree);
        if(ch=='X'){
            sop1+=scoree;
        }
        else{
            sop2+=scoree;
        }
        return scoree;
    }
    else
    {
        if(dir==1)return n+1;
        if(dir==5)return s+1;
        if(dir==3)return e+1;
        if(dir==7)return w+1;
        if(dir==2)return ne+1;
        if(dir==6)return sw+1;
        if(dir==8)return nw+1;
        if(dir==4)return se+1;
    }
}

// undo redo continue  exit option function
void options (int row , int column , char display[row][column] , int found, int arr[row*column*2], int xo)
{
    int type ;
    printf("type 1 to undo\ntype 2 to redo\ntype 3 to continue\ntype 4 to exit\n") ;
    printf("type: ") ;
    scanf("%d", &type) ;
    switch(type)
    {
        case 1: undo(row , column , display , found, arr, xo);//undo
        player (row, column, display, found, arr) ;
        printing_board(row, column, display) ;
        break;
        case 2: redo(row , column , display , found , arr, xo) ; //redo
        player (row, column, display, found, arr) ;
        printing_board(row, column, display) ;
        break;
        case 3: printing_board(row, column, display) ; //continue
        break;
        //case 4: exit()
        //break ;
        default:printf("You have not selected a correct value! Try Again!\n");
        printing_board(row, column, display) ;
        options(row, column, display, found, arr, xo) ;
        break;
    }
}

// checking x or o in board after undo or redo
/*int check_xo (int xo)
{
    if(xo % 2 == 0)
    {
        return 1 ;
    }
    else if (xo % 2 != 0)
    {
        return 2 ;
    }
}*/
// undo function

void undo( int row, int column, char display[row][column], int found, int arr[row*column*2], int xo, int temp)
{
    if (x <= 0 && y <= 1)
    {
        printing_board(row, column, display) ;
        printf("you can't do undo\n") ;
        options(row, column, display, found, arr, xo) ;
    }
    else
    {
        temp++ ;
        display[arr[x-2]][arr[y-2]]=' ';
        x -= 2 ;
        y -= 2 ;
        printing_board(row, column, display) ;
        if ((xo % 2 )== 0)
        {
            xo = 1 ;
        }
        else if ((xo % 2) != 0)
        {
            xo = 2 ;
        }
        options(row, column, display, found, arr, xo) ;
    }
}


//redo function
void redo(int row , int column , char display[row][column] , int found, int arr[row*column*2], int xo)
{

    if(xo == 2)
    {
        display[arr[x]][arr[y]]='X';
        x += 2;
        y += 2;
        printing_board(row, column, display) ;
        xo = 1 ;
        options(row, column, display, found, arr, xo) ;

    }
    else if (xo == 1)
    {
        display[arr[x]][arr[y]]='O';
        x += 2;
        y += 2;
        printing_board(row, column, display) ;
        xo = 2;
        options(row, column, display, found, arr, xo) ;
    }
}

//player  function
void player (int row, int column, char display[row][column], int found, int arr[row*column*2])
{
    green();
    printf("the score of player 1 is %d\n",sop1) ;
    reset();
    //score(row, column, display, 'X',0) ;
    red();
    printf("the score of player 2 is %d\n",sop2) ;
    reset();
    //score(row, column, display, 'O',0) ;
    printf("it's player %d turn\n", found) ;
    int number_of_column, i ;
    printf("choose number of column:") ;
    time_t begin = time(NULL);
    scanf("%d", &number_of_column) ;
    if (number_of_column > column || number_of_column < 1)
    {
        printf("please try again and choose column from 1 to %d\n", column) ;
        printing_board(row, column, display) ;
        player(row, column, display, found, arr) ;
    }
    else
    {
        for (i = row -1 ; i >= 0; i--)
        {
            if (display[i][number_of_column - 1] == ' ')
            {
                if(found == 1)
                {
                    display[i][number_of_column - 1] = 'X' ;
                    score(i,number_of_column - 1, display, 'X',0) ;
                    arr[x]=i;
                    x += 2;
                    arr[y]=number_of_column-1;
                    y += 2;

                }
                else if(found == 2)
                {
                    display[i][number_of_column - 1] = 'O' ;
                    score(i,number_of_column - 1, display, 'O',0) ;
                    arr[x]=i;
                    x += 2;
                    arr[y]=number_of_column-1;
                    y += 2;
                }
                break ;
            }
        }
        if(i < 0)
        {
            printing_board(row, column, display) ;
            printf("#warning: the column number '%d' is full please select another column \n", number_of_column) ;
            player (row, column, display, found, arr) ;
        }
    }
}
// function player vs computer
void computer (int row, int column, char display[row][column], int found , int arr[row*column*2])
{

    green();
    printf("your score is %d\n",sop1) ;
    reset();

    red();
    printf("the score of AI is %d\n",sop2) ;
    reset();

    int number_of_column, i ;

    if(found==1){
    printf("it's your turn to play\n") ;
    printf("choose number of column:\n") ;
    }
    if(found==2){
        do{
        srand(time(NULL));
        number_of_column=(rand()%(column+1));
        }while(number_of_column > column || number_of_column < 1 || i < 0);
    }
    else
    scanf("%d", &number_of_column) ;
    if (number_of_column > column || number_of_column < 1){
        if(found==1){
        printf("please try again and choose column from 1 to %d\n", column) ;
        computer(row,column,display,found,arr);

        }
        else
              computer(row,column,display,found,arr);
    }
    else
    {
        for (i = row -1 ; i >= 0; i--)
        {
            if (display[i][number_of_column - 1] == ' ')
            {
                if(found == 1)
                {
                    display[i][number_of_column - 1] = 'X' ;
                    score(i,number_of_column - 1, display, 'X',0) ;

                }
                else if(found == 2)
                {
                    display[i][number_of_column - 1] = 'O' ;
                    score(i,number_of_column - 1, display, 'O',0) ;
                }
                break ;
            }
        }
        if(i < 0)               //check if the column is full
        {
            if(found==1){
            printing_board(row, column, display) ;
            printf("#warning: the column number '%d' is full please select another column \n", number_of_column) ;
            computer (row, column, display, found,arr) ;
            }
            else if(found==2)
            computer (row, column, display, found,arr) ;
            }

        }

    }



//the start of flow
void game_flow (int row, int column, char display[row][column], int found, int arr[row*column*2], int xo)
{
    if (check_board(row, column, display) == 1)
    {
       time_t end = time(NULL);
       printf("-the board is full\n-end game\n") ;
       printf("The elapsed time is %d hours : %d minuets : %d seconds", ((end - begin)/(60*60)),(((end - begin)%3600)/60),((end - begin)%60));
    }
    else if(found == 1)         // player 1 turn
    {
        xo = found ;
        computer (row, column, display, found, arr) ;
        printing_board(row, column, display) ;
        options(row, column, display, found, arr, xo) ;
        found = 2 ;
        game_flow(row, column, display, found, arr, xo) ;
    }
    else if (found == 2)        //player 2 turn
    {
        xo = found ;
        computer (row, column, display, found, arr) ;
        printing_board(row, column, display) ;
        options(row, column, display, found, arr, xo) ;
        found = 1 ;
        game_flow(row, column, display, found, arr, xo) ;
    }

}
//function to read hight and wedth and number of top player from XML file
struct configuration xml(){

struct configuration a;
char ch;
char x[200];
int i=0,len=0,i1,i2,i3;
FILE *fptr;

if( (fptr = fopen("configuration.xml","r"))==NULL){

    printf("can not open the file");
    exit(1);
}
    while((ch=getc(fptr))!=EOF){

        if(!isspace(ch)){
            x[i++]=ch;
            len++;
        }
    }
if (3 == sscanf(x,
                "%*[^0123456789]%d%*[^0123456789]%d%*[^0123456789]%d",
                &i1,
                &i2,
                &i3))               //search from youtube
{
    a.hight=i1;
    a.wedth=i2;
    a.top=i3;
}
    fclose(fptr);
    return a;
}

int main()
{

    int row ,top ,column , found = 1 , xo ;
    struct configuration a;
    // welcome entry with some notes
    printf("-welcome in game\n") ;
    printf("-notes:\n    *you should input the size that you want to play\n    *player1 is '%c'\n    *player2 is '%c'\n-enjoy playing\n", 'X', 'O') ;

    a=xml();
    row=a.hight;
    column=a.wedth;
    top=a.top;
    rows=row;
    cols=column;
/*    //input row
   printf("\ninput number of rows:") ;
    scanf("%d", &row) ;
    rows=row;
    //input column
    printf("input number of columns:") ;
    scanf("%d", &column) ;
    cols=column;*/
    printf("the size you select is %d rows %d columns\n", row, column) ;

    //printing empty board in beginning of the game
    printf("\n#hint!!:now you can select any column from 1 -> %d\n\n", column) ;
    char display[row][column] ;
    empty_board(row, column, display) ;
    int arr[row*column*2];

    //game flow
    game_flow(row, column, display, found, arr, xo) ;
}
