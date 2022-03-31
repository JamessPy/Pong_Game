#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#define RACKETLEN 50
#define RACKETWIDTH 5
using namespace std;

static int score1 = 0;
static int score2 = 0;
static int racket1_x = 1;
static int racket1_y = 5;
static int racket2_x = 38;
static int racket2_y = 5;
static int ball_x= 20, ball_y = 5;



int dirY = 0;int dirX = 0;
const int width = 40;
const int height = 10;

void ClearScreen()
{   
    // Function which cleans the screen without flickering
    COORD cursorPosition;   cursorPosition.X = 0;   cursorPosition.Y = 0;   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void move_racket(int *x, int *y, int dir)
{
   // drawRackets(0);
	if (dir == 1 && racket2_y  != 9 && racket1_y  != 9)  	/* LEFT */
		*y = *y - 10;
	else if (dir == 0 && racket2_y !=1  && racket1_y  != 1)		/* RIGHT */
		*y = *y + 10;
	//drawRackets(RacketColor);
}

void Draw() // Drawing playing field, rackets and ball
{
    ClearScreen();

    // Draws top border
    for (int i = 0; i < width + 2; i++)
        cout << '-';
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {   
            // Left border
            if (k == 0)
                cout << '|';
            // Racket1
            if (i == racket1_y && k == racket1_x){
                cout << '|';
            }
            // Racket2
            else if (i == racket2_y && k == racket2_x)
                cout << '|';
            // Ball
            else if (i == ball_y && k == ball_x)
                cout << '*';

            else
            {   
                
                // Draws blank space if there is nothing to display
                cout << ' ';
            }
			
            
            // Right border
            if (k == width -1 )
                cout << '|';
            //printf("%d",k);
        }
        cout << endl;
    }

    // Draws bottom border
    for (int i = 0; i < width + 2; i++)
        cout << '-';
    cout << endl;

    // Displays player's score
    cout << endl;
    cout << "Score:  Player1:  " << score1;
    cout << "    ---   Player2:  " ;
	cout << score2;
}

void move_ball()
{
	//drawBall(ball_x,ball_y,ballSize,BallGNDColor);
	if(ball_x>=39){
		score1 += 1;
		Sleep(1000);
		
    	ball_x = 20;
    	ball_y = 5;
    	dirX = 1;

	}
	if(ball_x <=0){
		score2 += 1;
		Sleep(1000);
		
    	ball_x = 20;
    	ball_y = 5;
    	dirX = 0;
	}
    
    if(ball_y>=10)
        dirY = 0;
    if(ball_y<=0)
        dirY = 1;
  

    if(ball_x == racket2_x && (ball_y >= racket2_y-1 && racket2_y+1 >= ball_y))
    	dirX = 1;
    if(ball_x == racket1_x && (ball_y >= racket1_y-1 && racket1_y+1 >= ball_y))
    	dirX = 0;


    ball_x++;
    
    if(dirY == 1)
        ball_y++;
    else
        ball_y--;
        
    if(dirX == 0)
        ball_x++;
    else
        ball_x--;
	ball_x--;
	

}
gameOver(){
	

	cout << endl;
	if(score1>score2)
		cout << "Winner: Player1"<<endl;
	else if(score1==score2)
		cout << "Draw!!" <<endl;
	else
		cout << "Winner: Player2"<<endl;
    
    system("Pause");
}
void playGame()
{
	
    char c;

	if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
        	{
        	racket1_y--;
            break;
			}
        case 72:
        	{
        	racket2_y--;
            break;
			}
        case 's':
        	{
        		
        	racket1_y++;
            break;	
			}

        case 80:
        	{
        	racket2_y++;
            break;
			}
                
        case 27:
        	{
        	gameOver();
            break;
			}
            
        }

    }
}



int main(int argc, char** argv) {
	while(true)
	{
		Draw();
		playGame();
		move_ball();
		Sleep(80);
	}
	
}
