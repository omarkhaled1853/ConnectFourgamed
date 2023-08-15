#ifndef PRINTARRAYS_H_INCLUDED
#define PRINTARRAYS_H_INCLUDED

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
//check if alphabet or not
int check_alphabet (char *ch)
{
   if( *ch == 0)              // empty string - wrong
         return 0;

    for( ; *ch != 0; ch++) // scan the string till its end (a zero byte (char)0)
        if (!isdigit(*ch))     // test for a digit
            return 0;              // not a digit - return

    return 1;                      // all characters are digits
}

#endif // PRINTARRAYS_H_INCLUDED
