#ifndef HIGHSCORE_H_HIGHSCORE

//Top Players Struct
typedef struct{
    int score;
    char name[100];
    int rank;
}Top;
void make_upper(char *s){
    int len=strlen(s);

    for(int i=0;i<len;i++){

        s[i]=toupper(s[i]);
    }
}
void top(int highscore)
{
    int i = 0 , len = 0 ,sorted ;
    Top top , temp ;
    FILE *fptr;
    Top array[2000];
    if((fptr = fopen("highscore.txt","rb"))==NULL)    //if the game runs for the 1st time or the file was deleted.
    {
        fptr = fopen("highscore.txt","wb");
        fclose(fptr);
        fptr = fopen("highscore.txt","rb");
    }
    while((fread(&top,sizeof(top),1,fptr)))           // reading the file.
    {
       array[i].score=top.score;
       strcpy(array[i].name,top.name);
       array[i].rank=top.rank;
       len++;
       i++;
   }
    do                                               // Sort the top highscore list.
    {
        sorted=1;
        for(i=0;i<len-1;i++)
        {
            if(array[i].score<array[i+1].score)
            {
                temp = array[i] ;
                array[i] = array[i+1];
                array[i+1] = temp ;
                sorted=0;
            }
        }

    }while(sorted==0);

    fclose(fptr);

    int small_l = (highscore < len) ? highscore : len ;

    printf("NAME\t\t\t\t\tSCORE\t\t\t\t\tRANK\n") ;
     for(i=0;i<small_l;i++)
        printf("%s\t\t\t\t\t%d\t\t\t\t\t%d\n",array[i].name,array[i].score,i+1);
}
//end of function


//function to compare the name and with other names and save it.
void high_score_list(int score , char name[100])
{
    int len = 0 , flag = 1 , i = 0;
    FILE *fptr;
    Top array[2000];
    make_upper(name);
    Top top;

    if((fptr = fopen("highscore.txt","rb"))==NULL){    //if the game runs for the 1st time or the file was deleted.

        fptr = fopen("highscore.txt","wb");
        fclose(fptr);
        fptr = fopen("highscore.txt","rb");

    }
    while(fread(&top,sizeof(top),1,fptr)){           // reading the file.
       array[i].score=top.score;
       strcpy(array[i].name,top.name);
  //     array[i].rank=top.rank;
       len++;
       i++;

    }
    for(i=0;i<len;i++)
    {
        if((strcmp(name,array[i].name))==0){                //Check if the name already exists.

            if(score>array[i].score){                       //Check if new score larger than the old one.
                array[i].score = score;
            }
           // array[i].rank+=1;
            flag = 0 ;
        }
    }
    if(flag==1){
        strcpy(array[i].name,name);                        //save the name if not exist.
        array[i].score = score;
      //  array[i].rank = 1;
        len+=1;
    }

    fclose(fptr);

    if((fptr=fopen("highscore.txt","wb"))==NULL){         //save the name and his score in the file .
        printf("can not open the file");
    }
    for(i=0;i<len;i++){

        strcpy(top.name,array[i].name);
        top.score=array[i].score;
        //top.rank=array[i].rank;

        fwrite(&top,sizeof(top),1,fptr);
    }
    Rank_player(name,array,len);

    fclose(fptr);



}
//end of function

//Function To Print Your Rank After Sort The Array
void Rank_player(char name [100] , Top array[2000] , int len)
{
    Top temp;
    int sorted , i;
     do                                               // Sort the top highscore list.
    {
        sorted=1;
        for(i=0;i<len-1;i++)
        {
            if(array[i].score<array[i+1].score)
            {
                temp = array[i] ;
                array[i] = array[i+1];
                array[i+1] = temp ;
                sorted=0;
            }
        }

    }while(sorted==0);


    for(i=0;i<len ;i++)
    {
        if(strcmp(name,array[i].name)==0)
        {
            printf("Your Rank is %d",i+1);         //Print Your Score
        }
    }
}

#define HIGHSCORE_H_HIGHSCORE
#endif // HIGHSCORE_H_HIGHSCRE
