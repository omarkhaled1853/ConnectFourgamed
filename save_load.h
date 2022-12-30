#ifndef SAVE_LOAD
#define SAVE_LOAD

int move1 = 0, move2 = 0;
//saving function
void saving(int found , char array[row][column] ,int arr[row*column*2])
{
    char type_of_s[1000] ;
    int number_choice ;
    printf("please choose number of file you want to save\n") ;
    printf("select number:") ;
    gets(type_of_s) ;
    if (check_alphabet(type_of_s) == 1)
    {
        number_choice = atoi(type_of_s) ;
        if(number_choice==1){

            FILE *file1;
            file1=fopen("savegame1.bin","wb");
            fn_save(found , array , file1,arr);
        }
        else if(number_choice==2){

            FILE *file2;
            file2=fopen("savegame2.bin","wb");
            fn_save(found ,array , file2 ,arr);
        }
        else if(number_choice==3){

            FILE *file3;
            file3=fopen("savegame3.bin","wb");
            fn_save(found , array , file3 ,arr);
        }
        else
        {
            yellow() ;
            printf("Not existing number! Try Again!\n") ;
            reset() ;
            saving(found, array, arr) ;
        }
    }
    else
    {
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        saving(found, array, arr) ;
    }
}

void fn_save(int found,char array[row][column],FILE *file, int arr[row*column*2])
{
    int i;
    fwrite(&comp,sizeof(comp),1,file);
    fwrite(&sop1,sizeof(sop1),1,file);
    fwrite(&sop2,sizeof(sop2),1,file);
    fwrite(&move1,sizeof(move1),1,file);
    fwrite(&move2,sizeof(move2),1,file);
    fwrite(&row,sizeof(row),1,file);
    fwrite(&column,sizeof(column),1,file);

    for(i=0;i<row;i++)
    {
        fwrite(array[i],sizeof(array[i]),1,file);
    }
    fwrite(&found,sizeof(found),1,file);
    fwrite(arr,sizeof(arr),1,file);
    fclose(file);
}
//end of function


//loading function
void loading()
{
    char type_of_l[1000] ;
    int number_choice ;
    printf("please choose number of file you want to load\n") ;
    printf("select number:") ;
    gets(type_of_l) ;
    if (check_alphabet(type_of_l) == 1)
    {
        number_choice = atoi(type_of_l) ;
        if(number_choice==1)
        {
            FILE *file1;
            if((file1=fopen("savegame1.bin","rb"))==NULL)
            {
                printf("can not open the file!!\n");
                menu() ;
            }
            else
            {
                fn_load(file1);
            }

        }
        else if(number_choice==2)
        {
            FILE *file2;
            if((file2=fopen("savegame2.bin","rb"))==NULL)
            {
                printf("can not open the file!!\n");
                menu() ;
            }
            else
            {
                fn_load(file2);
            }
        }
          else if(number_choice==3)
        {
            FILE *file3;
            if((file3=fopen("savegame3.bin","rb"))==NULL)
            {
                printf("can not open the file!!\n");
                menu() ;
            }
            else
            {
                fn_load(file3);
            }
        }
        else
        {
            yellow() ;
            printf("Not existing number! Try Again!\n") ;
            reset() ;
            loading() ;
        }
    }
    else
    {
        yellow() ;
        printf("\nplease select number\n") ;
        reset() ;
        loading() ;
    }
}

void fn_load(FILE *file)
{
    int i,found;
    fread(&comp,sizeof(comp),1,file);
    fread(&sop1,sizeof(sop1),1,file);
    fread(&sop2,sizeof(sop2),1,file);
    fread(&move1,sizeof(move1),1,file);
    fread(&move2,sizeof(move2),1,file);
    fread(&row,sizeof(row),1,file);
    fread(&column,sizeof(column),1,file);
    int arr[row*column*2];
    char array[row][column];

    for(i=0;i<row;i++)
    {
        fread(array[i],sizeof(array[i]),1,file);
    }
    fread(&found,sizeof(found),1,file);
    fread(arr,sizeof(arr),1,file);

    fclose(file);
    printing_board(row, column, array) ;
    game_flow ( row, column, array , found , arr);
}
//end of function

#endif // SAVE_LOAD
