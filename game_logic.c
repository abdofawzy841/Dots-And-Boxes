#include "game.h"


void take_input(void)
{
    char buf [256]={0};
    if(save) printf("\t\t\t\t\t\t\t\tSaved!!\n");
    save=false;
    printf("\t\tEnter Two Numbers First for Rows and Second for Columns Separated by a Space: ");
    if(scanf("%d %d",&n,&m)!=2 || buf[4]>1){
            fgets(buf,256,stdin);
            if((buf[0]=='U'|| buf[0]=='u')&& buf[1]=='\n') {undomove=false; undo();}
            else if ((buf[0]=='R'|| buf[0]=='r') && buf[1]=='\n') {if(undone) {redo();}
                                                                   else{take_input();}}
            else if ((buf[0]=='S'|| buf[0]=='s') && buf[1]=='\n') {save_menu();}
            else if ((buf[0]=='E' || buf[0]=='e') && buf[1]=='\n') main_menu();
            else take_input();
    }

    if ((n%2==0 && m%2==1 && n>0 && m>0)||(n%2==1 && m%2==0 && n>0 &&m>0)){
        fgets(buf,256,stdin);
        undone=false;
        if (n<=grid_s && m<=grid_s){
            n-=1;
            m-=1;
            if(lines[n][m]==0)proccess_input();
        }
        else{
            take_input();}
            }
    else{
        take_input();}
    fgets(buf,256,stdin);
    take_input();
}

void proccess_input(void)
{
    if(lines[n][m]==1) take_input();
    else {
    total_moves++;
    lines[n][m]=1;
    if (turn==1) {
        player[n][m]=1;
        p1.moves++;
    }
    else {
        player[n][m]=2;
        p2.moves++;
    }
    save_move();
    check_box();
    }
}

void box_complete (void)
{
    if (box==1){
        printf("\a");
        if(turn==1){
            player[b1][b2]=t;
        }
        else {
            player[b1][b2]=t;
        }
        moves[total_moves-1][3]=1;

        box_count=1;
    }
    else {
        player[b1][b2]=0;
        }
    box=0;

}


void check_box (void)
{
    t=2;
    box=0;
    if(turn==1) t=1;
    if (n%2==0){
        if(n==0){
            check_down();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }
        }
        else if (n==grid_s-1){
            check_up();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }

        }
        else {
            check_up();
            box_complete();
            check_down();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }

        }
    }
    else{
        if(m==0){
            check_right();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }
        }
       else if(m==grid_s-1){
            check_left();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }
        }
        else{
            check_right();
            box_complete();
            check_left();
            box_complete();
            if(box_count==1){
                if(turn==1){turn=0;}
                else{turn=1;}
            }
        }
    }

     box_count=0;
     if(turn==1){turn=0;}
        else{turn=1;}

    if (undomove && vsai==1 &&turn==0){
        ai_undo();
    }
    else {
        draw_grid();}



}


void check_down (void)
{
    if(lines[n+1][m-1]==1 &&lines[n+1][m+1]==1 &&lines[n+2][m]==1 &&lines[n][m]==1){
        box=1;
        player[n+1][m-1]=t;
        player[n+1][m+1]=t;
        player[n+2][m]=t;

    }
    b1=n+1;
    b2=m;
}

void check_up (void)
{
    if(lines[n-1][m+1]==1 &&lines[n-1][m-1]==1 &&lines[n-2][m]==1 && lines[n][m]==1){
        box=1;
        player[n-1][m+1]=t;
        player[n-1][m-1]=t;
        player[n-2][m]=t;

    }
    b1=n-1;
    b2=m;
}

void check_right (void)
{
    if(lines[n+1][m+1]==1 &&lines[n-1][m+1]==1 &&lines[n][m+2]==1&& lines[n][m]==1){
        box=1;
        player[n+1][m+1]=t;
        player[n-1][m+1]=t;
        player[n][m+2]=t;

    }
    b1=n;
    b2=m+1;
}

void check_left (void)
{
    if(lines[n-1][m-1]==1 &&lines[n+1][m-1]==1 &&lines[n][m-2]==1&& lines[n][m]==1){
        box=1;
        player[n-1][m-1]=t;
        player[n+1][m-1]=t;
        player[n][m-2]=t;

    }
    b1=n;
    b2=m-1;
}


void ai_input (void)
{
    for (int i=0;i<grid_s;i++){
        for (int j=0;j<grid_s;j++){
            if((i%2==0 && j%2==1)||(i%2==1 && j%2==0)){
                if(lines[i][j]==0){
                    n=i;
                    m=j;
                    proccess_input();
                }
            }

        }

    }
}

void save_move (void)
{

    moves[total_moves-1][0]=n;
    moves[total_moves-1][1]=m;
    if (turn==1) moves[total_moves-1][2]=1;
    else moves[total_moves-1][2]=2;
}

void undo (void)
{
    if(total_moves>0){
    undone=true;
    undomove=true;
    total_moves--;
    if(turn==1 && total_moves>=0){
        lines[moves[total_moves][0]][moves[total_moves][1]]=0;
        p2.moves--;
    }
    else if(turn==0 && total_moves>=0){
        lines[moves[total_moves][0]][moves[total_moves][1]]=0;
        p1.moves--;
    }
    n=moves[total_moves][0];
    m=moves[total_moves][1];

    if(moves[total_moves][3]==1)
    {undomove=false;
        if(turn==1){turn=0;}
        else{turn=1;}

        if(turn==1){
            p1.moves++;
            p2.moves--;
        }
        else {
            p1.moves--;
            p2.moves++;
        }
    }
    check_box();
    }

    else take_input();
}
void calc_score (void)
{
    p1.score=0;
    p2.score=0;
    for(int i=1;i<grid_s;i=i+2){
        for (int j=1;j<grid_s;j=j+2){
            if ((i%2==1)&&(j%2==1)){
            if (player[i][j]==1) p1.score++;
            else if (player[i][j]==2) p2.score++;
        }

        }
    }
}


void ai_undo (void)
{
if(total_moves>0){
    undone=true;
    total_moves--;
    if(turn==1 && total_moves>=0){
        lines[moves[total_moves][0]][moves[total_moves][1]]=0;
        p2.moves--;
    }
    else if(turn==0 && total_moves>=0){
        lines[moves[total_moves][0]][moves[total_moves][1]]=0;
        p1.moves--;
    }
    n=moves[total_moves][0];
    m=moves[total_moves][1];

    if(moves[total_moves][3]==1)
    {
         if(turn==1){turn=0;}
        else{turn=1;}

        if(turn==1){
            p1.moves++;
            p2.moves--;
        }
        else {
            p1.moves--;
            p2.moves++;
        }
    }

    undomove=false;
    check_box();
    }

}


void redo (void)
{
    lines[n][m]=1;
    if(turn==1){
        p1.moves++;
        total_moves++;
    }
    else {
        p2.moves++;
        total_moves++;
    }
    undone=false;
    check_box();
}

