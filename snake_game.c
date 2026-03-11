#include"snake.h"

/*modern day many operating systems dont run conio.h as its not a part of strandard c library but we will use it
as the getch() function can take value from user without the need of hitting enter every time...*/

int fruit_row=12,fruit_coloumn=12;
int gameover=0;
int fruit_row, fruit_coloumn;
int head_x=7,head_y=7; // initial position of head of snake
char boundary[width+1][length+1];//2D array

int game_score=0;

/*we need tod=randomize starting position of snake and also give it controls on how by pressing certain buttons
its position will move and with a moderate speed speed(use library time.h and stdlib for it)*/

int snake_length=3; //initial snake length


segment Snake[snakemaxlen]; // now we can accesss a part of snake'Body by simply typing Snake[].x or Snake[].y

//Snake[].x represents the x coordinate if the segment of the snake //

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void High_score(){
    FILE*filepointer=fopen("Score.txt","w");// use w to create a new file...
    fprintf(filepointer," %d\n ",game_score);
    fclose(filepointer);
}
int Load_High(){
    FILE*filepointer = fopen("Score.txt", "r"); // Open file if already exist....
    int high_score = 0;
    if (filepointer != NULL) {
        fscanf(filepointer, "%d", &high_score); // Read score from file
        fclose(filepointer);
    } else {
        printf("No high score file found. Starting fresh.\n");
    }
    return high_score;
}

void area()//first creatre the boundary (we can make an array(char) which has 21*21 for in this workspace th snake shall move
{
    for(int i=0;i< width+1;i++)
    {
        for(int j=0;j<length+1;j++)
        {
             if(i==0 || i==width || j==0 || j==length)
            {boundary[i][j]='|';}
            else
            {boundary[i][j]=' ';}
        }
    }
}
void printboundary() 
{   
    //to clear the previous output as its in a loop
    //system("cls") ; // present in <stdlib.h>


    for(int i=0;i<length+1;i++)   // this is what we took first for printing it also is used as same as {putch()} syntax..
    { for(int j=0;j<width+1;j++)
        {
            printf("%c",boundary[i][j]);
        }
        printf("\n");
    } 
}

void erase_position(int x,int y){
    // use gotoxy to mive to the prev positionof the TAIL .....
    gotoxy(x,y);
    printf(" ");
    // go to position of tail and erase it by movbing the cursot to that location.....
}

void draw_snake() {
    // Update the boundary array with the snake's head and body
    // Head
    gotoxy(Snake[0].x, Snake[0].y);
    printf("\033[0;32mO\033[0m\n");
    for (int i = 1; i < snake_length; i++) {
     gotoxy(Snake[i].x, Snake[i].y);
     printf("\033[0;32mo\033[0m\n");
        // Body
    }
}

char key;

void move_snake(int delX,int delY)
{   
    segment tail=Snake[snake_length-1];
    // shifting each tail segment to its succesors prev position.
    for(int i=snake_length-1;i>0;i--)
    {
        Snake[i]=Snake[i-1];
    }

    // use a loop in which we can terminate loop by khbit (a funtion which gives one till a button is pressed).
    
        head_x+=delX;        // update snakes head's value
        head_y+=delY;

    Snake[0].x=head_x; // updating its position aagin acc. to prev update of head.
    Snake[0].y=head_y;

    // Erase the tail.
    erase_position(tail.x,tail.y);


    if(head_x==width||head_y==length||head_x==-1||head_y==-1) // if snake hits walls its gameover.
    {
        gameover=1;
        
    }
    
}
char direction;
void input_direction()
{
    if(kbhit()){ // returns 0 if no key pressed so the loop is not processed again to take input and return 1 to run loop if button pressed so the value of key changes....
    
    key= getch(); // from <conio.h>
    
    switch(key){
        case('w'):if(direction!='D'){direction='U';} break;
        case('s'):if(direction!='U'){direction='D';}  break;
        case('a'):if(direction!='R'){direction='L';}  break;
        case('d'):if(direction!='L'){direction='R';}break;
        case('x'):direction='N';break;
    }
    } // if this loop does not work then the  value of the key remains sme hence the snake position in three next function will be updated in the same position..
}

void move_key()
{

    switch(direction){
        case('U'):move_snake(-1,0); break;
        case('D'):move_snake(1,0) ; break;
        case('L'):move_snake(0,-1); break;
        case('R'):move_snake(0,1) ; break;
        case('N'):gameover=1;break;
    }

}
// apple represented by @ and snake body like (Oooooooooo) O being its head and 'o' representing body.

// fruit shall be given a new position again when the snake catches until then its position will remain same.

void draw_fruit() {
    gotoxy(fruit_row, fruit_coloumn);
    printf("\033[0;31m@\033[0m\n");
}

void fruit() //for drawing a fruit...
{
     srand(time(0));// Initialize the random number generator

    if(fruit_row==Snake[0].x && fruit_coloumn==Snake[0].y){
     do {
        fruit_row = (rand() % (width-1)) + 1;
        fruit_coloumn = (rand() % (length-1)) + 1;
        } while (fruit_row == head_x && fruit_coloumn == head_y);  

        snake_length++;
        game_score+=10;
    }     

        boundary[fruit_row][fruit_coloumn] = '@';// initially set at 12,12 then if prev loop run its position will change else not.
        draw_fruit();

}




 //game rules.... if snake hits its own body gameover;
 void game_rules(){

        for(int i=0;i<snake_length-2;i++)
        {
            for(int j=i+1;j<snake_length-1;j++){
                if(Snake[i].x == Snake[j].x && Snake[i].y==Snake[j].y)
                {gameover=1;}
            }
        }
}

int main(){// initial length of snake ==3

    system("cls");
    printf("GAME RULES:\n");
    printf("Snake CANNOT move immediately in opposite dirn ");
    printf("\nEach apple is of 10 points\n");
    printf("\nENTER-W,S,A,D-to move up,down,left,right\n");
    printf("Snake is not allowed to hit the walls \n Snake is not allowed to hit itself\n ALL THE BEST!\n");


    // Load high score
        int high_score = Load_High()
        ;
        printf("High Score: %d\n", high_score);

    printf("PRESS ENTER TO PLAY:");
    getch();
    printf("\n");
    system("cls");

    for(int i=0;i<3;i++){
     Snake[i].x=head_x;       // initializing head position at beggining of game so not taken snake length as it will be updated
     Snake[i].y=head_y-i;
    }
    
    area();
    printboundary();

    while(!gameover){
    input_direction() ; // uses khbit ans getch yo take input from user
    move_key(); // defines movement according to the button given by user
    fruit();
    draw_snake();
    game_rules(); // will update later/...
    Sleep(150);
    }
    system("cls");

    if (game_score > high_score) {
        printf("New High Score! %d\n", game_score);
        High_score(game_score); // Save high score
    }
    
    if(gameover==1)
    {
        printf("\nGAME-OVER");
        printf("\nFinal score=%d",game_score);
        
    }
    
    return 0;
}