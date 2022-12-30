#ifndef  SCORE_H_INCLUDED
#define  SCORE_H_INCLUDED
//score of each player
int sop1=0,sop2=0,rows,cols;

int score(int x,int y, char arr[rows][cols], char ch,int dir){
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

        if((n+s+1)>=4){
            if((n!=2)||(s!=2))
                scoree+=1;
                    if(n+s>=4)
                        scoree+=(n>s) ? s : n;
    }


        if((e+w+1)>=4){
                if((e!=2)||(w!=2))
                    scoree+=1;
                        if(e+w>=4)
                                scoree+=(e>w) ? w : e;
        }

        if((ne+sw+1)>=4){
            if((ne!=2)||(sw!=2))
                scoree+=1;
                    if(ne+sw>=4)
                        scoree+=(ne>sw) ? sw : ne;
        }

        if((nw+se+1)>=4){
          if((nw!=2)||(se!=2))
            scoree+=1;
                if(nw+se>=4)
                    scoree+=(nw>se) ? se : nw;
        }
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

#endif // SCORE_H_INCLUDED




