#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
#include <conio.h>
#include<windows.h>
#include <stdbool.h>
//Card Game

// Define card struct
typedef struct {
    char *suit;
    char *rank;
} Card;

int count=52;

// Define player struct
typedef struct {
    Card hand[11]; // Maximum of 11 cards per hand in Blackjack
    int num_cards;
    int score;
} Player;

// Function prototypes
void initialize_deck(Card *deck);
void shuffle_deck(Card *deck);
void deal_card(Card *deck, Player *player);
int calculate_score(Player *player);
void print_hand(Player *player);
void card_game();

//casino
int rules();
int round1();
void casino();

//Sudoku

#define SIZE 9
#define EMPTY 0
bool isSafe(int puzzle[SIZE][SIZE], int row, int column, int num);
bool EmptyLocation(int puzzle[SIZE][SIZE], int *row, int *column);
bool solveSudoku(int puzzle[SIZE][SIZE]);
void generateSudoku(int puzzle[SIZE][SIZE], int difficulty);
void printSudoku(int puzzle[SIZE][SIZE]);
bool isAvailable(int puzzle[SIZE][SIZE], int row, int column, int num);
void sudoku();


//QUIZ
void start();
void SciTech();
void History();

struct Board
{
    int score;
    char name[50];
    char *subject;
};
struct Board s; //declaration
void quiz();


//TICTACTOE
// making an array of characters i.e a string
char grid[10] = {'0','1','2','3','4','5','6','7','8','9'};

 //Defining 2 functions;
int findwinner();
void squareboard();
void tictactoe();

int main(){
    int choice;
    printf("\t\t\t WELCOME TO THE CLASSIC GAMING ARCADE \t\t\t\n\n");
    printf("MEMBERS OF PROJECT 10 Wish you an exiting gaming experience :) \n\n");

    printf("Press 1 to Play TIC TAC TOE - the game which filled Last pages of Your School notebooks\n");

    printf("Press 2 to Play QUIZ        - Brainstorm about exciting Science and History Questions\n");

    printf("Press 3 to Play Sudoku      - Play at your preferred Difficulty Level\n");

    printf("Press 4 to Play Casino      - Wanna Try your Luck or want to Earn something big? \n");

    printf("Press 5 to Play BlackJack   - Your Beloved Card game...Time to beat the dealer ;) \n");
    printf("Your choice(^v^) ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
        tictactoe();
        break;
        case 2:
        quiz();
        break;
        case 3:
        sudoku();
        break;
        case 4:
        casino();
        break;
        case 5:
        card_game();
        break;
        default:
        printf("Wrong Choice Buddy :( ");
        break;
    }
}

//TIC TAC TOE

void tictactoe(){
    int chance=1;
    int check;
    int choose;
    char mark;
    int choice;
    int next;
    char a[30];
    char b[30];

    printf("Hello, This game is called Tic-Tac-Toe");
    printf("\nTo see the rules Press 1");
    printf("\nTo play the game press 2 ");
    printf("\nEnter: ");
    scanf("%d", &choice);

    if(choice==1){
        system("cls");
        printf("The game is played on a grid that's 3 squares by 3 squares.");
        printf("\nThis is a 2 player game. Players take turns putting their marks in empty squares.");
        printf("\nThe first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.");
        printf("\nWhen all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.");
        printf("\n");
        printf("\nTo Play Press 1:");
        printf("\nTo Exit The Game Press 2: ");
        printf("\nEnter: ");
        printf("\a");
        scanf("%d", &next);
    }

    if(choice==2||next==1)
    {
        printf("Enter your name, Player 1: ");
        scanf("%s",a);
        printf("Enter your name, Player 2: ");
        scanf("%s",b);
        printf("\n%s has the symbol X", a);
        printf("\n%s has the symbol O", b);
        printf("\n");
        printf("\a");
        //This statement asks the user to press enter before moving forward
        system("pause -p 'Press Enter to continue.....'var");
        do
        {
            squareboard(a,b);
            //This is known as the ternery operator
            chance = (chance % 2==1) ? 1 : 2;

            if(chance==1)
            {
                printf("%s, Enter the digit where you want to put your symbol:  ", a);
                printf("\a");
            }
            else
            {
                printf("%s, Enter the digit where you want to put your symbol:  ", b);
                printf("\a");
            }
            scanf("%d", &choose);

            mark=(chance==1) ? 'X' : 'O';

            if (choose==1)
            {
                grid[1]=mark;
            }
            else if (choose==2)
            {
                grid[2]=mark;
            }
            else if (choose==3){
                grid[3]=mark;
            }
            else if (choose==4){
                grid[4]=mark;
            }
            else if (choose==5)
            {
                grid[5]=mark;
            }
            else if (choose==6)
            {
                grid[6]=mark;
            }
            else if (choose==7)
                grid[7]=mark;
                
            else if (choose==8)
            {
                grid[8]=mark;
            }
            else if (choose==9)
            {
                grid[9]=mark;
            }
            else
            {
                printf("\aInvalid move by the player");
                chance--;
                getch();
            }
            check=findwinner();
            chance++;
        }
        while (check==-1);
        squareboard(a,b);
        
        if (check==1)
        {
            if(chance%2==0){
                // \a makes a beep sound on printing the statement!
                printf("%s has won the game. Congratulations!", a);
            }
            else{
                printf("%s has won the game. Congratulations!", b);
            }
        }
        else
        {
            printf("\a\a\aGame draw! Better luck next time!");
        }
        getch();
    }
    else{
        printf("\a\a\aThanks for visiting!");
    }
}

int findwinner()
{                                                                                                       
    if (grid[1]==grid[2] && grid[2]==grid[3])
    {
        return 1;
    }   
    else if (grid[4]==grid[5] && grid[5]==grid[6])
    {
        return 1;
    }   
    else if (grid[7]==grid[8] && grid[8]==grid[9])
    {
        return 1;
    }
    else if (grid[1]==grid[4] && grid[4]==grid[7])
    {
        return 1;
    }
    else if (grid[2]==grid[5] && grid[5]==grid[8])
    {
        return 1;
    }
    else if (grid[3]==grid[6] && grid[6]==grid[9])
    {
        return 1;
    }
    else if (grid[1]==grid[5] && grid[5]==grid[9])
    {
        return 1;
    }   
    else if (grid[3]==grid[5] && grid[5]==grid[7])
    {
        return 1;
    }
    else if (grid[1]!='1' && grid[2]!='2' && grid[3]!='3' && grid[4]!='4' && grid[5]!='5' && grid[6]!='6' && grid[7]!='7' && grid[8]!='8' && grid[9]!='9')
    {
        return 0;
    }
    else
    {
        return  - 1;
    }
}


/******************************************************************
THE BELOW FUNCTION ALLOWS US TO DRAW THE GAME BOARD OF TIC-TAC-TOE
******************************************************************/


void squareboard(char a[], char b[])
{
    //Deletes the previous lines of output
    system("cls");
    printf("\n\t\tMULTIPLAYER TIC-TAC-TOE\n\n\n");
    printf("\t%s (X)  -  %s (O)\n\n", a,b);
    printf(" ---------------------\n");
    printf("|      |      |      |\n");
    printf("|   %c  |   %c  |   %c  |\n", grid[1], grid[2], grid[3]);
    printf(" ---------------------\n");
    printf("|      |      |      |\n");
    printf("|   %c  |   %c  |   %c  |\n", grid[4], grid[5], grid[6]);
    printf(" ---------------------\n");
    printf("|      |      |      |\n");
    printf("|   %c  |   %c  |   %c  |\n", grid[7], grid[8], grid[9]);
    printf(" ---------------------\n");
}

//QUIZ

void quiz(){
    int n;
printf("\n\t\t\tWELCOME!!\t\t\t\n\n");
printf("\n\tTHIS IS A QUIZ GAME MADE BY GROUP 10 !!!\t\t\t\n\n");
printf("MENU\n\n");
printf("Start the Quiz:\t\t Press 1\n");
printf("Check Scoreboard:\t Press 2\n\n");
printf("ENTER: ");
scanf("%d",&n);
printf("\n**\n\n");
switch(n)
    {
        case 1: printf("\t\t\tINSTRUCTIONS FOR PLAYING!\n\n");
        printf(" - After you enter your name,you will be asked to choose from any 1 of the given 2 topics\n");
        printf(" - Choose the subject that interests you the most\n");
        printf(" - Each subject will have 10 questions\n");
        printf(" - You will be given 2 options to choose from\n");
        printf(" - For every correct answer you will score +10 points\n");
        printf(" - There will be no negative marking\n");
        printf("\n Press 1 to Continue\n");
        printf(" Press 2 to Exit\n");
        int n1;
        printf("\n ENTER: ");
        scanf("%d" ,&n1);
        printf("\n**\n\n");
        getchar();
        switch(n1)
            {
                case 1: system("cls");
                        printf("\n LETS BEGIN!!\n");
                        printf(" Enter your name:");
                        gets(s.name);
                        start();
                        break;

                case 2: system("cls");
                        printf("\n You have successfully exited the game!\n\n");
                        break;
                default: printf("ERROR: Enter a correct option!!!");
            }
        break;

    case 2: printf("NAME\t\t\tSUBJECT\t\t\t\tSCORE\n");
            FILE *fp;
            char d;
            int count=0;
            fp=fopen("Scoreboard.txt", "r");

            if(fp==NULL)
            {
                printf("ERROR: Could not find file!");
            }
            d=fgetc(fp);
            while (d != EOF)
            {
                printf("%c", d);
                d=fgetc(fp);
                if(d=='\n')
                {
                    count++;
                }
            }
            printf("\n\nTotal Number of times quiz was played = %d\n\n" ,count);
            fclose(fp);
            getch();
            break;
     default: printf("ERROR: Enter a correct option!!!");
    }

}

void start()
{
    int n;
    printf("\n*CHOOSE A SUBJECT*\n");
    printf(" 1. Science and Technology\n");
    printf(" 2. History\n");
    printf("\n ENTER: ");
    scanf("%d" ,&n);
    printf("\n**\n");
    switch(n)
    {
        case 1: system("cls");
                SciTech();
                break;

        case 2: system("cls");
                History();
                break;

        default: printf("ERROR: Enter a correct option!");
    }
}

void SciTech()
{
    s.subject="Science and Technology";
    printf("\n WELCOME TO SCIENCE AND TECHNOLOGY QUIZ\n\n");
    printf("\nQuestion 1:What is the chemical symbol for the element potassium?\n");
    printf("\n a. Ag \t\t\t b. K \n\n c. Mg \t\t\t d. Au\n\n");
    char a1;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a1);
    if(a1=='b'||a1=='B')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10; 
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is b.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 2: What is the process by which plants make their own food called?\n");
    printf("\n a. Osmosis \t\t b. Photosynthesis \n c. Germination \t\t d. Seeding\n\n");
    char a2;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a2);
    if(a2=='b'||a2=='B')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is b.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nWho is credited with the discovery of penicillin?\n");
    printf("\n a.Alexander Fleming \t\t b. Florence Nightingale \n c. Dr. Jonas Salk  \t\t d. Dr. Elizabeth Blackwell\n\n");
    char a3;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a3);
    if(a3=='a'||a3=='A')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is a.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 4: What is the smallest unit of matter?\n");
    printf("\n a. Complex \t\t b.Molecule \n c. Atom \t\t d. Particle\n\n");
    char a4;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a4);
    if(a4=='c'||a4=='C')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is c.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 5: What is the Earth's outermost layer called?\n");
    printf("\n a. Inner Core \t\t b. Outer Core \n\n c. Mantle \t\t d. Crust\n\n");
    char a5;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a5);
    if(a5=='d'||a5=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 6: Which gas makes up the majority of the Earth's atmosphere?\n");
    printf("\n a. Neon \t\t b. Oxygen \n\n c. Carbon \t\t d. Nitrogen\n\n");
    char a6;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a6);
    if(a6=='d'||a6=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 7: What is the name of the closest star to Earth?\n");
    printf("\n a. Sun \t\t b. Proxima Centauri \n\n c. Alpha Centauri \t\t d. Sirius\n\n");
    char a7;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a7);
    if(a7=='a'||a7=='A')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is a.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 8: The process by which a cell divides into two identical daughter cells is called \n");
    printf("\n a. Meiosis \t b. Mitosis \n\n c. Transcription \t\t d.Translation\n\n");
    char a8;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a8);
    if(a8=='b'||a8=='B')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is b.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 9: What is the process by which a cell converts glucose into ATP (adenosine triphosphate) called? \n");
    printf("\n a. Legs \t\t b. Anaerobic Respiration \n\n c. Aerobic Respiration \t\t d. Cellular respiration\n\n");
    char a9;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a9);
    if(a9=='d'||a9=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 10: Which of the following is an example of an endothermic reaction?\n");
    printf("\n a. Combustion of gasoline \t\t\t b. Rusting of iron\n\n c. Formation of ice from water \t\t d. Rusting of Copper\n\n");
    char a10;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",a10);
    if(a10=='c'||a10=='C')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is c.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nYou scored: %d\n",s.score);
    if(s.score==100)
    {
        printf("\n\nCONGRATULATIONS!!!!\nYOU HAVE ANSWERED ALL QUESTIONS CORRECTLY!!!!\n\n");
    }
    else if (s.score>=70 && s.score<=90)
    {
        printf("\n\nGREAT JOB!!!\n\n");
    }
    else if (s.score>=30 && s.score<=60)
    {
        printf("\n\nBETTER LUCK NEXT TIME!\n\n");
    }
    else
    {
        printf("\n\nYOU CAN DO BETTER!\n");
    }

    FILE *fp;
    fp=fopen("Scoreboard.txt", "a");
    if(fp==NULL) //to check whether the file we're opening exists or doesn't exist
    {
        printf("ERROR: Could not find file!");
    }
    fprintf(fp,"%s\t\t\t%s\t\t%d\n",s.name,s.subject,s.score);
    fclose(fp);
}

void History()
{
    s.subject="History";
    s.score=0;
 	printf("\n WELCOME TO HISTORY QUIZ\n\n");
 	printf("\nQuestion 1: Which of the following events marked the end of the Middle Ages and the beginning of the Renaissance?\n");
    printf("\n a. The fall of Constantinople \t\t\t b. The Black Death \n\n c.  The invention of the printing press \t\t d. The discovery of America\n\n");
    char a1;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a1);
    if(a1=='a'||a1=='A')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is a. Vasantrao Naik");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 2:The Treaty of Versailles, signed in 1919, formally ended which conflict?\n");
    printf("\n a.  World War II \t\t\t b. The Crimean War \n\n c. The Cold War \t\t d. World War I\n\n");
    char a2;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a2);
    if(a2=='d'||a2=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 3:The Opium Wars, fought between China and which other country, led to the colonization of Hong Kong?\n");
    printf("\n a. Portugal \t\t b. France \n\n c. Japan \t\t d. Britain\n\n");
    char a3;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a3);
    if(a3=='d'||a3=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 4:Who was the first President of the United States?\n");
    printf("\n a.  Thomas Jefferson \t b.  Abraham Lincoln \n\n c. George Washington\t\t d.  John Adams\n\n");
    char a4;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a4);
    if(a4=='c'||a4=='C')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is c.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 5: Who won the Battle of Dewair 1582  ?\n");
    printf("\n a. Afzal Khan \t\t b. Chattrapati Shivaji Maharaj \n\n c. Maharana Pratap \t\t d. Akbar\n\n");
    char a5;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a5);
    if(a5=='c'||a5=='C')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is c.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nThe Magna Carta, signed in 1215, was a significant document in the history of which country?\n");
    printf("\n a.France \t\t b. England \n\n c.  Spain \t\t d. Italy\n\n");
    char a6;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a6);
    if(a6=='b'||a6=='B')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is b.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 7: The French Revolution began in which year?\n");
    printf("\n a. 1939 \t\t b. 1776 \n\n c. 1945 \t\t d. 1789\n\n");
    char a7;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a7);
    if(a7=='d'||a7=='D')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Correct Answer is d.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 8: Who is the son of founder of Maratha Empire ?\n");
    printf("\n a. Chhatrapati Sambhaji Maharaj \t b. Chhatrapati Rajaram Maharaj \n\n c. Chhatrapati Shahu Maharaj \t\t d. Chhatrapati Shivaji Maharaj\n\n");
    char a8;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a8);
    if(a8=='a'||a8=='A')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Answer is a.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 9: What Is the biggest Empire Documented In Indian History\n");
    printf("\n a. Maratha Empire \t\t b. Mughal Empire \n\n c. Maurayn Empire \t\t d. Sikh Empire\n\n");
    char a9;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a9);
    if(a9=='c'||a9=='C')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Answer is c.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nQuestion 10:Who ruled Major Parts of Indian Subcontinent before British?\n");
    printf("\n a. Maratha \t\t b.Mughals \n\n c. Sikhs \t\t d. Rajputs\n\n");
    char a10;
    getchar();
    printf("\nEnter your ans: ");
    scanf("%c",&a10);
    if(a10=='a'||a10=='A')
    {
        printf("\nCORRECT ANSWER!");
        s.score+=10;
        printf("\nYour score= %d\n\n",s.score);
    }
    else
    {
        printf("\nINCORRECT\nThe Answer is a.");
        printf("\nYour score= %d\n\n",s.score);
    }
    system("pause -p 'Press Enter to continue...' var");
    system("cls");
    printf("\nYou scored: %d\n",s.score);
    if(s.score==100)
    {
        printf("\n\nCONGRATULATIONS!!!!\nYOU HAVE ANSWERED ALL QUESTIONS CORRECTLY!!!!\n\n");
    }
    else if (s.score>=70 && s.score<=90)
    {
        printf("\n\nGREAT JOB!!!\n\n");
    }
    else if (s.score>=30 && s.score<=60)
    {
        printf("\n\nBETTER LUCK NEXT TIME!\n\n");
    }
    else
    {
        printf("\n\nYOU CAN DO BETTER!\n");
    }

    FILE *fp;
    fp=fopen("Scoreboard.txt", "a");
    if(fp==NULL)
    {
        printf("ERROR: Could not find file!");
    }
    fprintf(fp,"%s\t\t%s\t\t\t%d\n",s.name,s.subject,s.score);
}

//Sudoku

void sudoku(){
    // Allows the user to choose between generating a random Sudoku puzzle or entering their own.
    printf("To generate a random sudoku puzzle Enter '1' or if you want to enter your Sudoku puzzle Enter '2'.\n\n");
    int n;
    printf("Enter your command : ");
    scanf("%d", &n);
    //creates random sudoku puzzle 
    if (n == 1){
        int puzzle[SIZE][SIZE];
        srand(time(NULL));// Seed the random number generator
        printf("Enter Difficulty of Sudoku Puzzle on Scale 40-65 : ");
        int dificulty; scanf("%d", &dificulty);
        generateSudoku(puzzle, dificulty);// Generate the Sudoku puzzle
        printf("Generated Sudoku Puzzle:\n\n");
        printSudoku(puzzle);//Print the Sudoku puzzle
        printf("\n");
        printf("To print the solved puzzle please enter Y or if you want to exit enter N : ");
         // Ask the user if they want to print the solved puzzle
        char c;     scanf("%c", &c); scanf("%c", &c);

        if (c == 'Y' || c == 'y'){
            printf("\nSolved Sudoku Puzzle:\n\n");

            if (solveSudoku(puzzle))   printSudoku(puzzle);
            else    printf("\n\nNO SOLUTION\n\n");
        }
        else if (c == 'N' || c == 'n')  printf("Enjoy solving the Sudoku Puzzle.");
    //Enter your own puzzle
    } else if(n==2){
         // Prompt the user to enter their Sudoku puzzle
        int puzzle[SIZE][SIZE];
        printf("Enter your Numberes \n");
        for(int i=0;i<SIZE;i++)
            for(int j=0;j<SIZE;j++)     scanf("%d",&puzzle[i][j]);
        // Solve the user's Sudoku puzzle
        if(solveSudoku(puzzle))    printSudoku(puzzle);// solves the puzzle 
        else printf("\n\nNO SOLUTION\n\n");
    }

}



bool isSafe(int puzzle[SIZE][SIZE], int row, int column, int num){
    // Check if 'num' already exists in the same row.
    for(int i = 0; i < SIZE; i++) if(puzzle[row][i] == num)  return false;
    // Check if 'num' already exists in the same column.
    for(int i = 0; i < SIZE; i++) if(puzzle[i][column] == num)  return false;

    int startRow = row - row % 3;
    int startCol = column - column % 3;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) if(puzzle[i + startRow][j + startCol] == num)  return false;
     // If 'num' is not found in the same row, column, or 3x3 subgrid, it's safe to place it.
    return true;
}
bool EmptyLocation(int puzzle[SIZE][SIZE], int *row, int *column){
    for (*row = 0; *row < SIZE; (*row)++)
        for (*column = 0; *column < SIZE; (*column)++)   if (puzzle[*row][*column] == EMPTY)    return true;

    return false;
}
bool solveSudoku(int puzzle[SIZE][SIZE]){
    int row, column;

    if (!EmptyLocation(puzzle, &row, &column)){
        // If there is no empty location , then our sudoku would be solved
        return true;
    }

    // To generate a random permutation of numbers from 1  to 9
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++){
        int j = rand() % 9;
        int p = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = p;
    }

    
    for (int i = 0; i < 9; i++){
        int num = numbers[i];
        if (isSafe(puzzle, row, column, num)){
            // Assigning the no if its safe 
            puzzle[row][column] = num;

            // Recursively solving the remaining part of the sudoku
            if (solveSudoku(puzzle))    return true;
            // If the assigned no doesn't leads to a solution, try a different number
            puzzle[row][column] = EMPTY;
        }
    }

    // No solution found
    return false;
}
void generateSudoku(int puzzle[SIZE][SIZE], int difficulty){
    // 
    //puzzle
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++)      puzzle[i][j] = EMPTY;
    }

    // Generate a random Sudoku puzzle
    solveSudoku(puzzle);

    // eliminates numbers for creating a playable game 
    int numToRemove = difficulty; // adjusting values to control the difficulty of the game 

    while (numToRemove > 0){
        int row = rand() % SIZE;
        int column = rand() % SIZE;

        if (puzzle[row][column] != EMPTY){
            // Backup the number
            int backup = puzzle[row][column];
            puzzle[row][column] = EMPTY;

            // Check if there is unique solution
            int p[SIZE][SIZE];
            for (int i = 0; i < SIZE; i++){
                for (int j = 0; j < SIZE; j++)    p[i][j] = puzzle[i][j];
                
            }

            if (!solveSudoku(p)){
                // If removing the number leads to a non-unique solution,
                // restore the number and try removing a different number
                puzzle[row][column] = backup;
            }
            else    numToRemove--;
        }
    }
}
bool isAvailable(int puzzle[SIZE][SIZE], int row, int column, int num)
{
    int rowStart = (row / 3) * 3;
    int colStart = (column / 3) * 3;
    int i, j;
// Check if 'num' already exists in the same row, column, or 3x3 subgrid.
    for (i = 0; i < SIZE; ++i)
    {
        if (puzzle[row][i] == num)  return false;
        if (puzzle[i][column] == num)  return false;
        if (puzzle[rowStart + (i % 3)][colStart + (i / 3)] == num)  return false;
    }
      // If 'num' is not found in the same row, column, or 3x3 subgrid, it's available to be placed.
    return true;
}
void printSudoku(int puzzle[SIZE][SIZE])
{
      // Prints the Sudoku puzzle with horizontal and vertical separators.
    printf("+------+-------+------+\n");
    for (int i = 1; i < 10; ++i){
        for (int j = 1; j < 10; ++j){
            printf("|%d", puzzle[i - 1][j - 1]);
            if (j % 3 == 0 && j != 9) printf("| ");
        }
        printf("|\n");
        if (i % 3 == 0) printf("+------+-------+------+\n");
    }
}


//CASINO
void casino(){
    rules();
	printf("\n\n");
	round1();
}

int round1()
{
	char name[50];
	printf("Enter your name : \n");
	scanf("%s",name);
	printf("\n\n");
	int deposit;
	printf("enter the amount of money to be deposited for the game : \n");
	scanf("%d",&deposit);
	printf("\n\n");
	printf("Your current balance is :$%d\n",deposit);
	printf("\n\n");
	int bet1;
	printf("%s,Enter the amount of money to bet : $\n",name);
	scanf("%d",&bet1);
	printf("\n\n");
	if(bet1>deposit)
	{
		printf("Money exceeds!\n");
		printf("enter again :$\n");
		scanf("%d",&bet1);
	}
	printf("\n\n");
	int computer1;
	computer1=rand()%10;
	int guess1;
	printf("Guess a number from 1 to 10:\n");
	scanf("%d",&guess1);
	printf("\n\n");
	if(guess1>10)
	{
		printf("Number exceeds!\n");
		printf("Enter again : \n");
		scanf("%d",&guess1);
	}
	printf("\n\n");
	if(guess1==computer1)
	{
		printf("You have won :$%d\n",bet1);
		printf("\n\n");
		int bet2;
		bet2=bet1*10;
		int new_won;
		if(bet1==deposit)
		{
			new_won=bet2+0;
		}
		else
		{
			new_won=bet2+deposit;
		}
		printf("You have won $%d as total\n",new_won);
	}
	else if(guess1!=computer1)
	{
		printf("You have lost $%d",bet1);
		printf("\n\n");
		printf("The correct number is : %d\n",computer1);
		printf("\n\n");
		int new_lost;
		new_lost=deposit-bet1;
		printf("You have %d as balance\n",new_lost);
		printf("\n\n");
		if(new_lost==0)
		{
			printf("Sir you have $0 as balance\n");
			printf("You have no more money to play\n");
			printf("Have a nice day!\n");
		}
		else
		{
			int decision;
			printf("Press 1 for Yes\n");
			printf("Press 2 for No\n");
			printf("Do you want to continue(yes/no)?\n");
			scanf("%d",&decision);
			printf("\n\n");
			if(decision==1)
			{
				rules();
				printf("\n\n");
				printf("Now you have $%d as balance\n",new_lost);
				printf("\n\n");
				int bet3;
				printf("%s,Enter the amount of money to bet :\n",name);
				scanf("%d",&bet3);
				printf("\n\n");
				if(bet3>new_lost)
				{
					printf("Money exceeds!\n");
					printf("Enter again :$\n");
					scanf("%d",&bet3);
				}
				int guess2;
				printf("Enter a number from 1 to 10\n");
				scanf("%d",&guess2);
				printf("\n\n");
				int computer2;
				computer2=9;
				if(guess2>10)
				{
					printf("Number exceeds!\n");
					printf("Enter again :\n");
					scanf("%d",&guess2);
					printf("\n\n");
				}
				if(guess2==computer2)
				{
					printf("You have won $%d\n",bet3);
					printf("\n\n");
					int b;
					b=bet3*10;
					int b1;
					if(bet3==new_lost)
					{
						b1=b+0;
					}
					else
					{
						b1=b+new_lost;
					}
					printf("You have won $%d as a total\n",b1);
				}
				else if(guess2!=computer2)
				{
					printf("You have lost $%d\n",bet3);
					printf("\n\n");
					int b2;
					b2=new_lost-bet3;
					printf("You have $%d as a total\n",b2);
					printf("\n\n");
					if(b2==0)
					{
						printf("Sir you have $0 balance\n");
						printf("You have no more money to play\n");
						printf("Have a nice day");
					}
				}
			}
			if(decision==2)
			{
				printf("Have a nic day sir!\n");
			}
		}
	}
}
int rules()
{
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("RULES:-\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("1.Choose your number between 1 to 10\n");
	printf("2.If you win , you will win 10 times the money you bet\n");
	printf("3.If you bet on wrong , you will lose your betting amount\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
}

//Card Game

void card_game(){
   // Initialize deck
    Card deck[52];
    initialize_deck(deck);
    shuffle_deck(deck);

    // Initialize player
    Player player;
    player.num_cards = 0;
    player.score = 0;

    // Deal initial cards
    deal_card(deck, &player);
    deal_card(deck, &player);

    // Main game loop
    char choice;
    do {
        // Display player's hand and score
        printf("\nYour hand:\n");
        print_hand(&player);
        printf("Score: %d\n", calculate_score(&player));

        // Ask player to hit or stand
        printf("Do you want to (h)it or (s)tand? ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            // Deal another card to player
            deal_card(deck, &player);
            // Check for bust
            if (calculate_score(&player) > 21) {
                printf("\nBust! You lose.\n");
            }
        }
    } while (choice != 's');

    // Dealer's turn
    printf("\nDealer's turn:\n");
    Player dealer;
    dealer.num_cards = 0;
    dealer.score = 0;
    deal_card(deck, &dealer);
    deal_card(deck, &dealer);
    while (calculate_score(&dealer) < 17)
    {
        deal_card(deck, &dealer);
    }

    // Display dealer's hand and score
    printf("\nDealer's hand:\n");
    print_hand(&dealer);
    printf("Score: %d\n", calculate_score(&dealer));

    // Determine winner
    int player_score = calculate_score(&player);
    int dealer_score = calculate_score(&dealer);
    if (dealer_score > 21 || (player_score <= 21 && player_score > dealer_score))
    {
        printf("\nYou win!\n");
    }
    else if(player_score==dealer_score)
    {
        printf("It is a tie!");
    }
    else
    {
        printf("\nDealer wins.\n");
    }
}

// Initialize deck of cards
void initialize_deck(Card *deck) {
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    int i, j, count = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 13; j++)
        {
            deck[count].suit = suits[i];
            deck[count].rank = ranks[j];
            count++;
        }
    }
}
// Shuffle deck of cards
void shuffle_deck(Card *deck)
{
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal a card from deck to player
void deal_card(Card deck[], Player *p)
{
    p->hand[p->num_cards++] = deck[0];
    
    for (int c = 0; c < count-1; c++ )
    {
        deck[c]= deck[c+1];
    } 
    count--;
}
// Calculate score of player's hand
int calculate_score(Player *player)
{
    int score = 0;
    int num_aces = 0;
    for (int i = 0; i < player->num_cards; i++)
    {
        if (player->hand[i].rank == "Jack" || player->hand[i].rank == "Queen" || player->hand[i].rank == "King") 
        {
            score += 10;
        } else if (player->hand[i].rank == "Ace")
        {
            score += 11;
            num_aces++;
        } else 
        {
            score += atoi(player->hand[i].rank);
        }
    }
    // Adjust score for aces
    while (score > 21 && num_aces > 0)
    {
        score -= 10;
        num_aces--;
    }
    return score;
}
// Print player's hand
void print_hand(Player *player) {
    for (int i = 0; i < player->num_cards; i++)
    {
        printf("%s of %s\n", player->hand[i].rank, player->hand[i].suit);
    }
}