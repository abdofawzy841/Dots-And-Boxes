#include "game.h"


int grid_s;
int lines[11][11];
int player[11][11];
int n,m,b1,b2,t;
int turn=1;
int box=0,box_count;
struct player_data p1={0,"P 1",0};
struct player_data p2={0,"P 2",0};
time_t T_start,T_now_mins,T_now_secs;
int vsai=0;
int moves[60][4];
bool undomove,undone;
int total_moves;
bool save=false;
FILE *file1;
struct user_rank a[10],z;


FILE *file2;







int main()
{
    clear_game_data();
    clear_player_data();
    main_menu();
    return 0;
}
