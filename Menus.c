#include "game.h"

extern struct user_rank a[10],z;

void main_menu (void)
{
    int s;
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");

    printf("\033[1;33m\t\t\t\t\t\t\t1.Resume Game\n\t\t\t\t\t\t\t2.New Game\n\t\t\t\t\t\t\t3.Load Game\n\t\t\t\t\t\t\t4.Top 10\n\t\t\t\t\t\t\t5.Exit\n\n");
    printf("Enter The Number Corresponding To Your Choice: ");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                if((grid_s==5 && (p1.moves+p2.moves!=12)) ||(grid_s==11 && (p1.moves+p2.moves!=60)))  draw_grid();
                else printf("No Game Initiated!!\nPlease Enter Another Choice: \033[0m");
                break;
            case 2:
                difficulty_select();
                break;
            case 3:
                load_menu();
                break;
            case 4:
                top_10();
                break;
                case 5:
                exit(0);
                break;
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();

        }
    }
}

void difficulty_select (void)
{
    save=false;
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");


    int s;
    printf("\033[1;33m\t\t\t\t\t\t\t1.Beginner 2x2\n\t\t\t\t\t\t\t2.Expert 5x5\n\t\t\t\t\t\t\t3.Back To Main Menu\n");
    printf("Enter The Number Corresponding To Your Choice: \033[0");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                grid_s=5;
                player_mode_menu();
                break;
            case 2:
                grid_s=11;
                player_mode_menu();
                break;
            case 3:
                main_menu();
                break;
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();

        }
    }

}


void player_mode_menu (void)
{
    turn=1;
    clear_player_data ();
    clear_game_data();
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");


    int s;
    printf("\033[1;33m\t\t\t\t\t\t\t1.Player VS AI\n\t\t\t\t\t\t\t2.Player VS Player\n\t\t\t\t\t\t\t3.Back To Main Menu\n");
    printf("Enter The Number Corresponding To Your Choice: \033[0");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                vsai=1;
                draw_grid();
                break;
            case 2:
                vsai=0;
                draw_grid();
                break;
            case 3:
                main_menu();
                break;
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();
                break;

        }
    }
}


void invalid_input (void)
{
    printf("\033[1;31m\n\t\t\t\t\tPlease Enter A Valid Input:\033[0m");
}




void draw_grid (void)
{
    calc_score();
    if(p1.moves+p2.moves==0) T_start=time(NULL);
    T_now_secs=time(NULL)-T_start;
    T_now_mins=T_now_secs/60;
    T_now_secs=T_now_secs%60;
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n");

    int rem_lines;
    if (grid_s==5) rem_lines=12-p1.moves-p2.moves;
    else if (grid_s==11) rem_lines=60-p1.moves-p2.moves;
    if(rem_lines>=1)
    {printf("\033[1;36m\t\t\tEnter 'U' For Undo, 'R' For Redo, 'S' For Save, And 'E' To Go To Main Menu\n\n");}
    if (vsai==0){
        if (turn==1){
            printf("\033[1;32m\t\t\t\t\tTime: %d : %d     Remaining Lines:%d \033[1;31m Turn: %s    \n\n",T_now_mins,T_now_secs,rem_lines,p1.name);
            }
        else{
            printf("\033[1;32m\t\t\t\t\tTime: %d : %d     Remaining Lines:%d \033[1;34m Turn: %s    \n\n",T_now_mins,T_now_secs,rem_lines,p2.name);
            }
            printf("\033[1;31m\t\t\t\t\tPlayer1: %s       \033[1;34m    Player2: %s\n",p1.name,p2.name);
            }

    else if(vsai==1){
        if (turn==1){
            printf("\033[1;32m\t\t\t\t\tTime: %d : %d      Remaining Lines:%d \033[1;31m Turn: %s    \n\n",T_now_mins,T_now_secs,rem_lines,p1.name);
            }
        else{
            printf("\033[1;32m\t\t\t\t\tTime: %d : %d      Remaining Lines:%d \033[1;34m Turn: AI    \n\n",T_now_mins,T_now_secs,rem_lines);
            }
            printf("\033[1;31m\t\t\t\t\tPlayer1: %s       \033[1;34m    Player2: AI\n",p1.name);
            }

    printf("\033[1;31m\t\t\t\t\tMoves: %d         \033[1;34m      Moves: %d\n",p1.moves,p2.moves);
    printf("\033[1;31m\t\t\t\t\tScore: %d         \033[1;34m      Score: %d\n\n\033[0m",p1.score,p2.score);


    printf("\t\t\t\t\t0   ");
    for (int i=1;i<grid_s+1;i++) {
            if (i<9) printf("%d  ",i);
            else printf("%d ",i);}
    printf("\n\t\t\t\t\t");

    int j;
    for (int i=0;i<grid_s;i++){

        if(i<9)printf("%d   ",i+1);
        else printf("%d  ",i+1);

        for (j=0;j<grid_s;j++){
            if ((i%2)==0){
                if(j%2==0){draw_dot();}
                else if(lines[i][j]==1){
                    if (player[i][j]==1) redh();
                    else blueh();
                }
                else eh();
            }
            else{
                if (j%2==0){
                    if(lines[i][j]==1){
                        if(player[i][j]==1) redv();
                        else bluev();
                    }
                    else ev();
                }
                else{
                    if(player[i][j]==0) boxe();
                    else if (player[i][j]==1) boxp1();
                    else if (player[i][j]==2) boxp2();
                }

            }
        }
        if(i==grid_s-1){ printf("\n");}
        else {printf("\n\t\t\t\t\t");}
    }


    if(grid_s==5){
        if (p1.moves+p2.moves==12)
            game_over();

    }
    else if(grid_s==11){
        if (p1.moves+p2.moves==60)
            game_over();
    }
    if(turn==0 && vsai==1){
        ai_input();
    }
    else take_input();
}



void draw_dot (void)
{
    printf("\033[1;33m%c\033[0m",254);
}


void redh (void)
{
    printf("\033[0;31m%c%c%c%c%c\033[0m",196,196,196,196,196,196);
}

void redv (void)
{
    printf("\033[0;31m%c\033[0m",179);
}

void blueh (void)
{
    printf("\033[0;34m%c%c%c%c%c\033[0m",196,196,196,196,196,196);
}

void bluev (void)
{
    printf("\033[0;34m%c\033[0m",179);
}

void ev (void)
{
    printf(" ");
}

void eh (void)
{
    printf("     ");
}

void boxp1 (void)
{
    printf("\033[1;31m P 1 \033[0m");

}

void boxp2 (void)
{
    printf("\033[1;34m P 2 \033[0m");

}

void boxe (void)
{
 printf("     ");
}




void clear_game_data(void)
{
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++){
            lines[i][j]=0;
            player[i][j]=0;
            vsai=0;
            total_moves=0;
        }
    }
}

void clear_player_data (void)
{
p1.moves=0;
p2.moves=0;
p1.score=0;
p2.score=0;
total_moves=0;
}



void game_over (void)
{
    load_top10();
    calc_score();
    bool found=false;
    char buf [256]={0};
    printf("\033[1;33m\n\t\t\t\t\t\t\tGAME OVER\n");
    if(p1.score>p2.score) {
        printf("\t\t\t\t\t\t\tP 1 WINS!!\n\t\t\t\t\t\t\tScore: %d\n\n",p1.score);
        printf("\t\t\t\t\t\t\tEnter Your Name: ");
        scanf("%s",buf);
        for (int i=0;i<10;i++){
            if(strcasecmp(a[i].name,buf)==0){
                found=true;
                if(p1.score>a[i].score){
                    a[i].score=p1.score;
                    break;
                }
            }
        }
        if (p1.score>=a[9].score&& !found){
            a[9].score=p1.score;
            strcpy(a[9].name,buf);}
        save_top10();
        top_10();
        }

    else if(p2.score>p1.score){
        if(vsai==1){
        printf("\t\t\t\t\t\t\tAI WINS!!\n");
        }
        else if (vsai==0) {
            printf("\t\t\t\t\t\t\tP 2 WINS!!\n\t\t\t\t\t\t\tScore: %d\n\n",p2.score);
            printf("\t\t\t\t\t\t\tEnter Your Name: ");
            scanf("%s",buf);
            for (int i=0;i<10;i++){
                if(strcasecmp(a[i].name,buf)==0){
                    found=true;
                    if(p2.score>a[i].score){
                    a[i].score=p2.score;
                    break;
                }
            }
        }
        if (p2.score>=a[9].score && !found){
            a[9].score=p2.score;
            strcpy(a[9].name,buf);
            }
        save_top10();
        top_10();
                }
            }


    else printf("\t\t\t\t\t\t\tDRAW!!\n");
         printf("\t\t\t\t\tEnter 1 To Go Back To Main Menu:\n \033[0m");

    int s;
    while (1){
        s=0;
        scanf("%d",&s);
        switch (s){
            case 1:
                main_menu();
                break;

            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();
                break;
        }
    }
}



void save_menu (void)
{
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");


    int s;
    printf("\033[1;33m\t\t\t\t\t\t\t1.Save To File 1\n\t\t\t\t\t\t\t2.Save To File 2\n\t\t\t\t\t\t\t3.Save To File 3\n\t\t\t\t\t\t\t4.Back To Game\n");
    printf("Enter The Number Corresponding To Your Choice: \033[0");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                file1=fopen("save_game1.txt","w");
                save_game();
                break;
            case 2:
                file1=fopen("save_game2.txt","w");
                save_game();
                break;
            case 3:
                file1=fopen("save_game3.txt","w");
                save_game();
                break;
            case 4:
                draw_grid();
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();

        }
    }

}


void load_menu (void)
{
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");


    int s;
    printf("\033[1;33m\t\t\t\t\t\t\t1.Load File 1\n\t\t\t\t\t\t\t2.Load File 2\n\t\t\t\t\t\t\t3.Load File 3\n\t\t\t\t\t\t\t4.Back To Main Menu\n");
    printf("Enter The Number Corresponding To Your Choice: \033[0");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                file1=fopen("save_game1.txt","r");
                T_start=time(NULL);
                load_game();
                break;
            case 2:
                file1=fopen("save_game2.txt","r");
                T_start=time(NULL);
                load_game();
                break;
            case 3:
                file1=fopen("save_game3.txt","r");
                T_start=time(NULL);
                load_game();
                break;
            case 4:
                main_menu();
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();

        }
    }
}

void top_10 (void)
{
    char buf [256]={0};
    system("cls");
    printf("\033[1;31m########   #######  ########  ######\033[1;36m      ###    ##    ## ######## \033[1;34m  ########   #######  ##     ## ########  ######\n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ##\033[1;36m    ## ##   ###   ## ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##      \033[1;36m   ##   ##  ####  ## ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##       ## \n");
    printf("\033[1;31m##     ## ##     ##    ##     ######  \033[1;36m ##     ## ## ## ## ##     ##\033[1;34m  ########  ##     ##    ###    ######    ###### \n");
    printf("\033[1;31m##     ## ##     ##    ##          ## \033[1;36m ######### ##  #### ##     ##\033[1;34m  ##     ## ##     ##   ## ##   ##             ## \n");
    printf("\033[1;31m##     ## ##     ##    ##    ##    ## \033[1;36m ##     ## ##   ### ##     ##\033[1;34m  ##     ## ##     ##  ##   ##  ##       ##    ## \n");
    printf("\033[1;31m########   #######     ##     ######  \033[1;36m ##     ## ##    ## ########\033[1;34m   ########   #######  ##     ## ########  ######\033[0m\n\n\n\n\n\n");

    load_top10();
    print_top10();
    save_top10();
    int s;

    printf("\033[1;33m\t\t\t\t\t\t\tEnter 1 To Go To Main Menu ");
    while (1){
        s=0;
        scanf("%d",&s);

        switch (s){
            case 1:
                main_menu();
                break;
            case 0:
                fgets(buf,256,stdin);
            default:
                invalid_input();

        }
    }

}






