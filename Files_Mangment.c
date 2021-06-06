#include "game.h"


void save_game(void){
save=true;
printf("\t\t\tSaved\n");

for(int i=0;i<11;i++){
    for(int j=0;j<11;j++){
        fprintf(file1,"%d ",lines[i][j]);
    }}


for(int i=0;i<11;i++){
    for(int j=0;j<11;j++){
        fprintf(file1,"%d ",player[i][j]);
    }}
for (int i=0;i<60;i++){
    for (int j=0;j<4;j++){
        fprintf(file1,"%d ",moves[i][j]);
    }
}
    fprintf(file1,"%d %d %d %d %d %d %d %d %d",grid_s,turn,box,vsai,p1.moves,p2.moves,n,m,total_moves);
    fclose(file1);



    draw_grid();
}




void load_game(void){
    undone=false;
for(int i=0;i<11;i++){
    for(int j=0;j<11;j++){
        fscanf(file1,"%d",&lines[i][j]);
    }}


for(int i=0;i<11;i++){
    for(int j=0;j<11;j++){
        fscanf(file1,"%d",&player[i][j]);
    }}
    for (int i=0;i<60;i++){
    for (int j=0;j<4;j++){
        fscanf(file1,"%d",&moves[i][j]);
    }
}
    fscanf(file1,"%d %d %d %d %d %d %d %d %d",&grid_s,&turn,&box,&vsai,&p1.moves,&p2.moves,&n,&m,&total_moves);
    fclose(file1);
    T_start=time(NULL);
    save=false;

draw_grid();
}



struct user_rank a[10],z;

void load_top10 (void)
{
    file2=fopen("Top10.txt","r");
    for(int i=0;i<10;i++){
        fscanf(file2,"%s %d\n",a[i].name,&a[i].score);
    }
    sort_top10();
    fclose(file2);

}

void save_top10 (void)
{
    sort_top10();
    file2=fopen("Top10.txt","w");
    for(int i=0;i<10;i++){
        fprintf(file2,"%s %d\n",a[i].name,a[i].score);
    }
    fclose(file2);

}

void sort_top10 (void)
{
    for(int i=1;i<10;i++){
        for (int j=0;j<10;j++){
            if(a[j].score<a[j+1].score){
            z=a[j];
            a[j]=a[j+1];
            a[j+1]=z;
            }
        }
    }
}

void print_top10 (void)
{
    sort_top10();
    for(int i=0;i<9;i++){
        printf("\033[1;33m\t\t\t\t\t%d.    %s      %d\n\033[0m",i+1,a[i].name,a[i].score);
    }
    printf("\033[1;33m\t\t\t\t\t10.   %s      %d\n\033[0m\n\n\n",a[9].name,a[9].score);

}


