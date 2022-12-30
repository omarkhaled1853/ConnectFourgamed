#include <stdio.h>
#include <string.h >
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "color.h"
#include "score.h"
#include "printArrays.h"
#include "undo_redo.h"
#include "highscore.h"
#include "xml.h"
#include "save_load.h"
#include "select column.h"

//global variables
int start, end, time_s = 0  ;


//player  function
void player (int row, int column, char display[row][column], int found, int arr[row*column*2], int score_arr[row*column])
{
    score_arr[x] = sop1 ;
    score_arr[y] = sop2 ;

    struct info pl_one = {move1, sop1, 'X', "Green"} ;

    struct info pl_two = {move2, sop2, 'O', "Red"} ;

    green();
    printf("number of moves of player 1 is '%d'\t", pl_one.moves) ;
    reset();

    red();
    printf("number of moves of player 2 is '%d'\n", pl_two.moves) ;
    reset();

    green();
    printf("the score of player 1 is '%d'\t\t", pl_one.player_score) ;
    reset();

    red();
    printf("the score of player 2 is '%d'\n",pl_two.player_score) ;
    reset() ;

    green() ;
    printf("the deck of player 1 is '%c'\t\t", pl_one.deck) ;
    reset() ;

    red() ;
    printf("the deck of player 2 is '%c'\n", pl_two.deck) ;
    reset() ;

    green() ;
    printf("the color of player 1 is '%s'  \t", pl_one.color) ;
    reset() ;

    red() ;
    printf("the color of player 2 is '%s'\n", pl_two.color) ;
    reset() ;

    printf("it's player %d turn\n", found) ;

    char type[1000] ;

    blue() ;
    printf("type 'c' to select column\n") ;
    reset() ;

    yellow() ;
    printf("type 'u' for undo\n") ;
    reset() ;

    cyan() ;
    printf("type 'r' for redo\n") ;
    reset() ;

    purple() ;
    printf("type 's' for save\n") ;
    reset() ;

    red() ;
    printf("type 'e' for exit\n") ;
    reset() ;

    printf("select type:") ;
    gets(type) ;

    if(check_alphabet(type) == 0)
    {
        if(strlen(type) > 1)
        {
            printing_board(row, column, display) ;
            yellow() ;
            printf("\nNot exist type! Try Again!\n") ;
            reset() ;
            player(row, column, display, found, arr, score_arr) ;
        }
        else
        {
            switch(*type)
            {
                case 'c' :
                    printing_board(row, column, display) ;
                    select_column(row, column, display, found, arr, score_arr) ;
                    break ;
                case 'u' :
                    undo(row, column, display, found, arr, score_arr) ;
                    break ;
                case 'r' :
                    redo(row, column, display, found, arr, score_arr) ;
                    break ;
                case 's' :
                    saving(found, display, arr) ;
                    _Exit(0) ;
                    break ;
                case 'e':
                    _Exit(0) ;
                    break ;
                default:
                    printing_board(row, column, display) ;
                    yellow() ;
                    printf("\nNot exist type! Try Again!\n") ;
                    reset() ;
                    player(row, column, display, found, arr, score_arr) ;
            }
        }
    }
    else
    {
        printing_board(row, column, display) ;

        yellow() ;
        printf("please select alphabet\n") ;
        reset() ;

        player(row, column, display, found, arr, score_arr) ;
    }

}


//one player mode (computer vs human)
void computer (int row, int column, char display[row][column], int found , int arr[row*column*2], int score_arr[row*column])
{
    score_arr[x] = sop1 ;
    score_arr[y] = sop2 ;

    int number_of_column ;
    if(found == 1)
    {
        struct info pl_one = {move1, sop1, 'X', "Green"} ;

        struct info pl_two = {move2, sop2, 'O', "Red"} ;

        green();
        printf("number of moves of you is '%d'\t", pl_one.moves) ;
        reset();

        red();
        printf("number of moves of AI is '%d'\n", pl_two.moves) ;
        reset();

        green();
        printf("the score of you is '%d'\t\t", pl_one.player_score) ;
        reset();

        red();
        printf("the score of AI is '%d'\n",pl_two.player_score) ;
        reset() ;

        green() ;
        printf("the deck of you is '%c'\t\t", pl_one.deck) ;
        reset() ;

        red() ;
        printf("the deck of AI is '%c'\n", pl_two.deck) ;
        reset() ;

        green() ;
        printf("the color of you is '%s'  \t", pl_one.color) ;
        reset() ;

        red() ;
        printf("the color of AI is '%s'\n", pl_two.color) ;
        reset() ;

        printf("it's your turn\n") ;
    }

    if(found == 2)
    {
        int i ;
        do{
        srand(time(NULL));
        number_of_column=(rand()%(column+1));
        }while(number_of_column > column || number_of_column < 1);
        n_undo_redo = 0 ;
        for (i = row -1 ; i >= 0; i--)
        {
            if (display[i][number_of_column - 1] == ' ')
            {
                move2++ ;
                display[i][number_of_column - 1] = 'O' ;
                score(i,number_of_column - 1, display, 'O',0) ;
                arr[x] = i ;
                x += 2 ;
                arr[y] = number_of_column - 1 ;
                y += 2;
                break ;
            }
        }
        while(i < 0)
        {
            do{
                srand(time(NULL));
                number_of_column=(rand()%(column+1));
            }while(number_of_column > column || number_of_column < 1 );
            for (i = row -1 ; i >= 0; i--)
            {
                if (display[i][number_of_column - 1] == ' ')
                {
                    move2++ ;
                    display[i][number_of_column - 1] = 'O' ;
                    score(i,number_of_column - 1, display, 'O',0) ;
                    arr[x] = i ;
                    x += 2 ;
                    arr[y] = number_of_column - 1 ;
                    y += 2;
                    break ;
                }
            }
        }
    }
    else
    {
        char type[1000] ;

        blue() ;
        printf("type 'c' to select column\n") ;
        reset() ;

        yellow() ;
        printf("type 'u' for undo\n") ;
        reset() ;

        cyan() ;
        printf("type 'r' for redo\n") ;
        reset() ;

        purple() ;
        printf("type 's' for save\n") ;
        reset() ;

        red() ;
        printf("type 'e' for exit\n") ;
        reset() ;

        printf("select type:") ;
        gets(type) ;
        if(check_alphabet(type) == 0)
        {
            if(strlen(type) > 1)
            {
                printing_board(row, column, display) ;
                yellow() ;
                printf("\nNot exist type! Try Again!\n") ;
                reset() ;
                computer(row, column, display, found, arr, score_arr) ;
            }
            else
            {
                switch(*type)
                {
                case 'c' :
                    printing_board(row, column, display) ;
                    select_column_comp(row, column, display, found, arr, score_arr) ;
                    break ;
                case 'u' :
                    undo(row, column, display, found, arr, score_arr) ;
                    break ;
                case 'r' :
                    redo(row, column, display, found, arr, score_arr) ;
                    break ;
                case 's' :
                    saving(found, display,arr) ;
                    _Exit(0) ;
                    break ;
                case 'e':
                    _Exit(0) ;
                    break ;
                default:
                    printing_board(row, column, display) ;
                    yellow() ;
                    printf("\nNot exist type! Try Again!\n") ;
                    reset() ;
                    computer(row, column, display, found, arr, score_arr) ;
                }
            }
        }
        else
        {
            printing_board(row, column, display) ;

            yellow() ;
            printf("please select alphabet\n") ;
            reset() ;

            computer(row, column, display, found, arr, score_arr) ;
        }
    }
}

//common in end game
void common_end_game ()
{
    char type[1000] ;

    purple() ;
    printf("\ntype 'b' to go back menu") ;
    reset() ;

    red() ;
    printf("\ntype 'e' to exit\n") ;
    reset() ;

    printf("select type:") ;
    gets(type) ;
    if(check_alphabet(type) == 0)
    {
        if(strlen(type) > 1)
        {
            yellow() ;
            printf("\nNot exist type! Try Again!\n") ;
            reset() ;
            common_end_game() ;
        }
        else
        {
            switch(*type)
            {
                case 'b':
                    menu() ;
                break ;
                case 'e':
                    _Exit(0) ;
                break ;
                default:
                    yellow() ;
                    printf("\nNot exist type! Try Again!\n") ;
                    reset() ;
                    common_end_game() ;
                break ;
            }
        }
    }
    else
    {
        yellow() ;
        printf("please select alphabet\n") ;
        reset() ;
        common_end_game() ;
    }
}



//end game function
void end_game ()
{
    if(sop1 > sop2)
    {
        green() ;
        printf("player 1 is winner\n") ;
        reset() ;

        yellow() ;
        printf("please enter your name:") ;
        reset() ;

        gets(pl_own.name) ;
        high_score_list(sop1,pl_own.name);

        common_end_game() ;

    }
    else if (sop2 > sop1)
    {
        red() ;
        printf("player 2 is winner\n") ;
        reset() ;

        yellow() ;
        printf("please enter your name:") ;
        reset() ;
        gets(pl_two.name) ;
        high_score_list(sop2,pl_two.name);

        common_end_game() ;
    }
    else
    {
        yellow() ;
        printf("same score! No winner in game\n") ;
        reset() ;
        common_end_game() ;
    }
}


//the start of flow
void game_flow (int row, int column, char display[row][column], int found, int arr[row*column*2], int score_arr[row*column])
{
    if (check_board(row, column, display) == 1)
    {
        if (comp == 1)
        {
            printing_board(row, column, display) ;

            struct info pl_one = {move1, sop1, 'X', "Green"} ;

            struct info pl_two = {move2, sop2, 'O', "Red"} ;

            green();
            printf("number of moves of you is '%d'\t", pl_one.moves) ;
            reset();

            red();
            printf("number of moves of AI is '%d'\n", pl_two.moves) ;
            reset();

            green();
            printf("the score of you is '%d'\t\t", pl_one.player_score) ;
            reset();

            red();
            printf("the score of AI is '%d'\n",pl_two.player_score) ;
            reset() ;

            green() ;
            printf("the deck of you is '%c'\t\t", pl_one.deck) ;
            reset() ;

            red() ;
            printf("the deck of AI is '%c'\n", pl_two.deck) ;
            reset() ;

            green() ;
            printf("the color of you is '%s'  \t", pl_one.color) ;
            reset() ;

            red() ;
            printf("the color of AI is '%s'\n", pl_two.color) ;
            reset() ;

        }
        else
        {
            struct info pl_one = {move1, sop1, 'X', "Green"} ;

            struct info pl_two = {move2, sop2, 'O', "Red"} ;

            green();
            printf("number of moves of player 1 is '%d'\t", pl_one.moves) ;
            reset();

            red();
            printf("number of moves of player 2 is '%d'\n", pl_two.moves) ;
            reset();

            green();
            printf("the score of player 1 is '%d'\t\t", pl_one.player_score) ;
            reset();

            red();
            printf("the score of player 2 is '%d'\n",pl_two.player_score) ;
            reset() ;

            green() ;
            printf("the deck of player 1 is '%c'\t\t", pl_one.deck) ;
            reset() ;

            red() ;
            printf("the deck of player 2 is '%c'\n", pl_two.deck) ;
            reset() ;

            green() ;
            printf("the color of player 1 is '%s'  \t", pl_one.color) ;
            reset() ;

            red() ;
            printf("the color of player 2 is '%s'\n", pl_two.color) ;
            reset() ;
        }
        yellow() ;
        printf("-end game\n") ;
        reset() ;
        int i, j ;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
                display[i][j] = ' ' ;
        }
        x = 0,y = 1, n_undo_redo = 0, comp = 0, move1 = 0, move2 = 0, start = 0, end = 0, time_s = 0  ;
        end_game() ;

    }
    else if(found == 1)         // player 1 turn
    {
        if (comp == 1)
        {

            printf("Time elapsed: ") ;
            yellow() ;
            printf("%d M:%d S\n", time_s / 60, time_s % 60) ;
            reset() ;
            start = clock() ;
            computer(row, column, display, found, arr, score_arr) ;
            end = clock() ;
            time_s += (end - start)/1000 ;
        }
        else
        {
            printf("Time elapsed: ") ;
            yellow() ;
            printf("%d M:%d S\n", time_s / 60, time_s % 60) ;
            reset() ;
            start = clock() ;
            player (row, column, display, found, arr, score_arr) ;
            end = clock() ;
            time_s += (end - start)/1000 ;
            printing_board(row, column, display) ;
        }

        found = 2 ;
        game_flow(row, column, display, found, arr, score_arr) ;
    }
    else if (found == 2)        //player 2 turn
    {
        if (comp == 1)
        {
            start = clock() ;
            computer(row, column, display, found, arr, score_arr) ;
            end = clock() ;
            time_s += (end - start)/1000 ;
        }
        else
        {
            printf("Time elapsed: ") ;
            yellow() ;
            printf("%d M:%d S\n", time_s / 60, time_s % 60) ;
            reset() ;
            start = clock() ;
            player (row, column, display, found, arr, score_arr) ;
            end = clock() ;
            time_s += (end - start)/1000 ;
        }
        printing_board(row, column, display) ;
        found = 1 ;
        game_flow(row, column, display, found, arr, score_arr) ;
    }

}
//end of function

//common with one and two player
void common ()
{
    // store size in configuration struct
    configuration config;

    //xml();
    config.hight=row;
    config.width=column;
    config.top=highscore;
    int row ,top ,column , found = 1 ;

    // welcome entry
    purple() ;
    printf("-welcome in game\n") ;
    reset() ;

    //scan size from xml file
    row = config.hight;
    column = config.width;
    top = config.top;

    //for check score
    rows=row;
    cols=column;

    yellow() ;
    printf("\n#hint!!:now you can select any column from 1 -> %d\n\n", column) ;
    reset() ;

    //printing empty board in beginning of the game
    char display[row][column] ;
    empty_board(row, column, display) ;
    int arr[row*column*2];
    int score_arr[row*column] ;
    //game flow
    game_flow(row, column, display, found, arr, score_arr) ;
}

//one player
void one_player()
{
    common() ;
}

//two player mode
void two_player ()
{
    common() ;
}

//mode selection for one player or two
void mode_selection()
{
    purple() ;
    printf("\n1-one player\n") ;
    reset() ;

    blue() ;
    printf("2-two player\n") ;
    reset() ;

    cyan() ;
    printf("3-Go back\n");
    reset() ;

    printf("select type:") ;
    char select_m[1000] ;
    int select_mode ;
    gets(select_m) ;
    if (check_alphabet(select_m) == 1)
    {
        select_mode = atoi(select_m) ;
        switch(select_mode)
        {
            case 1:
                comp = 1 ;
                one_player() ;                 //one player mode (player vs computer)
                break ;
            case 2:
                two_player() ; //two player mode (human vs human)
                break ;
            case 3:
                printf("\n") ;
                menu() ; //main menu
                break ;
            default:
                yellow() ;
                printf("\nNot exist type! Try Again!") ;
                reset() ;
                mode_selection() ;
                break ;
        }
    }
    else
    {
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        mode_selection() ;
    }
}

//main menu selection
void menu()
{
    configuration config;
    config.top=highscore;
    blue() ;
    printf("<< Main Menu >>\n") ;
    reset() ;

    yellow() ;
    printf("1-Start a new game\n") ;
    reset() ;

    cyan() ;
    printf("2-Load a game\n") ;
    reset() ;

    purple() ;
    printf("3-Top players\n") ;
    reset() ;

    red() ;
    printf("4-Quit\n") ;
    reset() ;

    printf("select type:") ;
    int select_number ;
    char select_menu[1000] ;
    gets(select_menu) ;
    if(check_alphabet(select_menu) == 1)
    {
        select_number = atoi(select_menu) ;
        switch(select_number)
        {
            case 1:
                mode_selection() ;
            break ;
            case 2:
                loading() ;
            break ;
            case 3:
                top(config.top) ;
                menu() ;
            break ;
            case 4:
                _Exit(0) ;
            break ;
            default:
                yellow() ;
                printf("\nNot exist type! Try Again!\n") ;
                reset() ;
                menu() ;
            break ;
        }
    }
    else
    {
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        menu() ;
    }
}
//end of function

int main()
{
    int j = 0;

    check_path(j) ;

    configuration config;
    config.top=highscore;

    top(config.top) ;
    menu() ;
    return 0 ;
}
