#ifndef SELECT_H_INCLUDED
#define SELECT_H_INCLUDED

//info of player
struct info
{
    int moves ;
    int player_score ;
    char deck ;
    char *color ;
    char name[100] ;
}pl_own, pl_two ;

// select column function in case 'c' (1 to 1)
void select_column(int row, int column, char display[row][column], int found, int arr[row*column*2], int score_arr[row*column])
{
    int number_of_column, i ;
    char number_of_col[1000] ;

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

    if (found == 1)
    {
        green() ;
        printf("it's player %d turn\n", found) ;
        reset() ;
    }
    else
    {
        red() ;
        printf("it's player %d turn\n", found) ;
        reset() ;
    }

    printf("select column:") ;
    gets(number_of_col) ;
    if (check_alphabet(number_of_col) == 1)
    {
        number_of_column = atoi(number_of_col) ;
        if (number_of_column > column || number_of_column < 1)
        {
            printing_board(row, column, display) ;
            yellow() ;
            printf("Not existing column!\n") ;
            reset() ;
            printf("please try again and choose column from 1 to %d\n", column) ;
            select_column(row, column, display, found, arr, score_arr) ;
        }
        else
        {
            n_undo_redo = 0 ;
            for (i = row -1 ; i >= 0; i--)
            {
                if (display[i][number_of_column - 1] == ' ')
                {
                    if(found == 1)
                    {
                        move1++ ;
                        pl_one.moves = move1 ;
                        display[i][number_of_column - 1] = 'X' ;
                        score(i,number_of_column - 1, display, 'X',0) ;
                        arr[x] = i ;
                        x += 2 ;
                        arr[y] = number_of_column - 1 ;
                        y += 2 ;
                    }
                    else if(found == 2)
                    {
                        move2++ ;
                        pl_two.moves = move2 ;
                        display[i][number_of_column - 1] = 'O' ;
                        score(i,number_of_column - 1, display, 'O',0) ;
                        arr[x] = i ;
                        x += 2 ;
                        arr[y] = number_of_column - 1 ;
                        y += 2;
                    }
                    break ;
                }
            }
            if(i < 0)
            {
                printing_board(row, column, display) ;
                yellow() ;
                printf("the column number '%d' is full!\n", number_of_column) ;
                reset() ;
                printf("please select another column \n") ;
                select_column(row, column, display, found, arr, score_arr) ;
            }
        }
    }
    else
    {
        printing_board(row, column, display) ;
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        select_column(row, column, display, found, arr, score_arr) ;
    }
}
//end of function

//select column function in case 'c' 1 player
void select_column_comp(int row, int column, char display[row][column], int found, int arr[row*column*2], int score_arr[row*column])
{
    int number_of_column, i ;
    char number_of_col[1000] ;

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

    green() ;
    printf("it's your turn\n") ;
    reset() ;

    printf("select column:") ;
    gets(number_of_col) ;


    if (check_alphabet(number_of_col) == 1)
    {
        number_of_column = atoi(number_of_col) ;
        if (number_of_column > column || number_of_column < 1)
        {
            printing_board(row, column, display) ;
            yellow() ;
            printf("Not existing column!\n") ;
            reset() ;
            printf("please try again and choose column from 1 to %d\n", column) ;
            select_column_comp(row, column, display, found, arr, score_arr) ;
        }
        else
        {
            n_undo_redo = 0 ;
            for (i = row -1 ; i >= 0; i--)
            {
                if (display[i][number_of_column - 1] == ' ')
                {
                    move1++ ;
                    display[i][number_of_column - 1] = 'X' ;
                    score(i,number_of_column - 1, display, 'X',0) ;
                    arr[x] = i ;
                    x += 2 ;
                    arr[y] = number_of_column - 1 ;
                    y += 2 ;
                    break ;
                }
            }
            if(i < 0)
            {
                printing_board(row, column, display) ;

                yellow() ;
                printf("the column number '%d' is full!\n", number_of_column) ;
                reset() ;

                printf("please select another column \n") ;
                select_column_comp(row, column, display, found, arr, score_arr) ;
            }
        }
    }
    else
    {
        printing_board(row, column, display) ;
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        select_column_comp(row, column, display, found, arr, score_arr) ;
    }
}
//end of function
#endif // SELECT_H_INCLUDED
