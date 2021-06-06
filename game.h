#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>>


extern int lines[11][11];
extern int player[11][11];
extern int grid_s;
extern int turn;
extern int box,box_count;
extern int n,m,b1,b2,t;
struct player_data{
    int score;
    char name [50];
    int moves;
};
extern struct player_data p1;
extern struct player_data p2;
extern time_t T_start,T_now_mins,T_now_secs;
extern int vsai;
extern int moves [60][4];
extern bool undomove,undone;
extern int total_moves;
extern bool save;
extern FILE *file1;
struct user_rank{
char name [150];
int score;
};
extern FILE *file2;









void mainmeu (void);
void difficulty_select (void);
void player_mode_menu (void);
void invalid_input (void);
void draw_grid (void);
void draw_dot (void);
void redh (void);
void redv (void);
void blueh (void);
void bluev (void);
void eh (void);
void ev (void);
void boxp1 (void);
void boxp2 (void);
void boxe (void);
void take_input(void);
void proccess_input(void);
void check_box (void);
void check_down (void);
void check_up (void);
void check_right (void);
void check_left (void);
void clear_player_data (void);
void game_over (void);
void clear_game_data(void);
void ai_input (void);
void save_move (void);
void calc_score (void);
void ai_undo(void);
void redo (void);
void save_game(void);
void load_game(void);
void load_menu (void);
void save_menu (void);
void top_10 (void);
void sort_top10 (void);
void load_top10 (void);
void save_top10 (void);
void print_top10 (void);





#endif // GAME_H_INCLUDED
