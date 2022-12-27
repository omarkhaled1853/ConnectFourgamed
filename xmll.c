#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct{

    int hight;
    int width;
    int top;

}configuration;

int row,column,highscore;
int main(){
configuration config;

    xml();
config.hight=row;
config.width=column;
config.top=highscore;
    printf("%d\n",config.hight);
    printf("%d\n",config.width);
    printf("%d",config.top);

}

void xml(){

    char config_start[]="<Configurations>",config_end[]="</Configurations>",Hight_start[]="<Height>",Hight_end[]="</Height>";
    char Width_start[]="<Width>",Width_end[]="</Width>",highscore_start[]="<Highscores>",highscore_end[]="</Highscores>",arr[2000],ch;
    int start_conf,end_conf,start_high,end_high,start_width,end_width,start_highscore,end_highscore;
    int i=0,len=0;
    FILE *fptr;

    if((fptr=fopen("configuration.xml","r"))==NULL){                                 //read the file
        printf("can not open the file please enter the path");
        return;
    }
    while((ch=getc(fptr))!=EOF){

        if(!isspace(ch)){
            arr[i++]=ch;
            len++;
        }
    }


    start_conf=check_name(config_start,arr);

    end_conf=check_name(config_end,arr);

    if((start_conf==-1)||(end_conf==-1))
    {
        printf("can not open the file please enter the path");                      //check if configuration not exist
        return;
    }
    int length = end_conf-start_conf+1;
    char array[length];                                                             //element between configuration

    for(i=0;i<length;i++){

        array[i]=arr[start_conf+i];

    }
    start_high=check_name(Hight_start,array);
    end_high=check_name(Hight_end,array);
    if((start_high==-1)||(end_high==-1))                                              //check if hight not exist
    {
        printf("there is error in height please enter the path");
        return;
    }
    else
    {
    int size_hight=(end_high-start_high-8);
    char w[size_hight];

    for(i=0;i<size_hight;i++)
    {
        w[i]=array[start_high+8+i];
    }

    int check_x;
    for(i=0;i<size_hight;i++)                                                          //check if between <Height></Height> not a number
    {
        check_x=(isdigit(w[i]));
    }
    if (check_x)
    {
        if((atoi(w))<=0)                                                               //check if the number is less than or equal zero
        {
        printf("there is error in height please enter the path");
        return;
        }
        row=atoi(w);
    }
    else{
        printf("there is error in height please enter the path");
        return;
    }
    }


    start_width=check_name(Width_start,array);
    end_width=check_name(Width_end,array);
    if((start_width==-1)||(end_width==-1))                                              //check if width not exist
    {
        printf("there is error in width please enter the path");
        return;
    }
    int size_width=(end_width-start_width-7);
    char c[size_width];

    for(i=0;i<size_width;i++)
    {
        c[i]=array[start_width+7+i];
    }

    int check_y;
    for(i=0;i<size_width;i++)                                                          //check if between <Width></Width> not a number
    {
        check_y=(isdigit(c[i]));
    }
    if (check_y)
    {
        if((atoi(c))<=0)                                                               //check if the number is less than or equal zero
        {
        printf("there is error in width please enter the path");
        return;
        }
        column=atoi(c);
    }
    else{
        printf("there is error in width please enter the path");
        return;
    }


    start_highscore=check_name(highscore_start,array);
    end_highscore=check_name(highscore_end,array);
    if((start_highscore==-1)||(end_highscore==-1))                                              //check if highscors not exist
    {
        printf("there is error in highscore please enter the path");
        return;
    }
    int size_highscore=(end_highscore-start_highscore-12);
    char h[size_highscore];

    for(i=0;i<size_highscore;i++)
    {
        h[i]=array[start_highscore+12+i];
    }

    int check_z;
    for(i=0;i<size_highscore;i++)                                                          //check if between <Highscores></Highscores> not a number
    {
        check_z=(isdigit(h[i]));
    }
    if (check_z)
    {
        if((atoi(h))<=0)                                                               //check if the number is less than or equal zero
        {
        printf("there is error in highscore please enter the path");
        return;
        }
        highscore=atoi(h);
    }
    else{
        printf("there is error in highscore please enter the path");
        return;
    }

}
//function check whether the name is exist or not.
//return -1 if not / return index if exist
int check_name(char name[] , char array[]){
    int check=-1,i,j,ln,larr;
    ln=strlen(name);
    larr=strlen(array);
    for(i=0;i<larr;i++){
        for(j=0;j<ln;j++){
            if(name[j]!=array[i+j]){
                break;

            }
        }
        if(j==ln){
            check=i;
        }
    }
    return check;

}
