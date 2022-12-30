#ifndef UNDOREDO_H_UNDOREDO
#define UNDOREDO_H_UNDOREDO
int x=0 , y=1  , n_undo_redo = 0 , comp =0;
// undo function
void undo( int row, int column, char display[row][column], int found, int arr[row*column*2], int score_arr[row*column])
{
    if (x <= 0 && y <= 1)
    {
        printing_board(row, column, display) ;
        yellow() ;
        printf("You can't do undo!\n") ;
        reset() ;
        if (comp == 1)
        {
            computer(row, column, display, found, arr, score_arr) ;
        }
        else
        {
            player(row, column, display, found, arr, score_arr) ;
        }
    }
    else
    {
        if (found = 2)
        {
            sop1 = score_arr[x-2] ;
        }
        else
        {
            sop2 = score_arr[y-2] ;
        }
        n_undo_redo++ ;
        display[arr[x-2]][arr[y-2]]=' ';
        x -= 2 ;
        y -= 2 ;
    }
}


//redo function
void redo(int row , int column , char display[row][column] , int found, int arr[row*column*2], int score_arr[row*column])
{
    if (n_undo_redo > 0)
    {
        n_undo_redo-- ;
        if(found == 2)
        {
            display[arr[x]][arr[y]]='O';
            score(arr[x], arr[y], display, 'O', 0) ;
            x += 2;
            y += 2;
        }
        else if (found == 1)
        {
            display[arr[x]][arr[y]]='X';
            score(arr[x], arr[y], display, 'X', 0) ;
            x += 2;
            y += 2;
        }
    }
    else if (n_undo_redo == 0)
    {
        printing_board(row, column, display) ;
        yellow() ;
        printf("You can't do redo!\n") ;
        reset() ;
        if (comp == 1)
        {
            computer(row, column, display, found, arr, score_arr) ;
        }
        else
        {
            player(row, column, display, found, arr, score_arr) ;
        }
    }
}
#endif
