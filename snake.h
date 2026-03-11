#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define width 31
#define length 31
#define snakemaxlen 256


extern int fruit_row, fruit_coloumn;
extern int gameover;
extern int head_x, head_y;
extern char boundary[width + 1][length + 1];
extern int game_score;
extern int snake_length;
extern char direction;
extern char key;


typedef struct {
    int x;
    int y;
} segment;
 segment Snake[snakemaxlen];


void gotoxy(int x, int y);
void High_score();
int Load_High();
void area();
void printboundary();
void erase_position(int x, int y);
void draw_snake();
void move_snake(int delX, int delY);
void input_direction();
void move_key();
void draw_fruit();
void fruit();
void game_rules();

#endif // SNAKE_GAME_H
