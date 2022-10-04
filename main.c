#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct player_data
{
    char name[50];
    int score;
    char input;
} pd;
char ai_input()
{
    char inp;
    int rand_input_index;
    char input_set[3] = {'R', 'P', 'S'};
    srand(time(NULL));
    rand_input_index = rand() % 3;
    inp = input_set[rand_input_index];
    return inp;
}
char player_input(char name[50])
{
    char inp;
    printf("It is your turn %s \n", name);
    fflush(stdin);
    scanf("%c", &inp);
    return inp;
}
void move_check(char inp1, char inp2, int *sc1, int *sc2, char name1[50], char name2[50])
{
    if (inp1 == 'R' && inp2 == 'R' || inp1 == 'P' && inp2 == 'P' || inp1 == 'S' && inp2 == 'S')
    {
        printf("Both the choises are same ,it's a draw.\n");
        printf("\n");
    }
    else if (inp1 == 'R' && inp2 == 'S' || inp1 == 'P' && inp2 == 'R' || inp1 == 'S' && inp2 == 'P')
    {
        printf("%s wins this round\n", name1);
        printf("\n");

        (*sc1)++;
    }
    else if (inp1 == 'R' && inp2 == 'P' || inp1 == 'P' && inp2 == 'S' || inp1 == 'S' && inp2 == 'R')
    {
        printf("%s wins this round\n", name2);
        printf("\n");

        (*sc2)++;
    }
    else
    {
        printf("Invalid input\n");
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    FILE * ptr;
    ptr=fopen("records.txt","a");
    printf("INSTRUCTIONS:-\nEnter 'R' for rock , 'P' for paper and 'S' for scissors.\n");
    printf("********************************************************\n");
    struct player_data d1, d2;
    char restart = 'y';
    char p1_main_input;
    char p2_main_input;
    d1.score = 0;
    d2.score = 0;
    while (restart != 'N')
    {
        int player_count;
        printf("Enter the number of players playing this game:-\n 1 or 2:-\n");
        scanf("%d", &player_count);
        if (player_count == 1)
        {
            printf("Enter your name.\n");
            scanf("%s", &d1.name);
            printf("Enter the name for your virtual opponent\n");
            scanf("%s", &d2.name);
            printf("Each player will have 9 chances ,the one with the higher score wins.\n");
            for (int i = 0; i < 9; i++)
            {
                printf("Round %d\n", i + 1);
                p1_main_input = player_input(d1.name);
                p2_main_input = ai_input();
                printf("%s's choise is %c.\n", d2.name, p2_main_input);
                move_check(p1_main_input, p2_main_input, &d1.score, &d2.score, d1.name, d2.name);
            }
            if (d1.score > d2.score)
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("%s wins the game.\n", d1.name);
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"%s wins the game.\n", d1.name);
                fprintf(ptr,"********************************************************\n");
            }
            else if (d1.score < d2.score)
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("%s wins the game.\n", d2.name);
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"%s wins the game.\n", d2.name);
                fprintf(ptr,"********************************************************\n");
            }
            else
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("The game was called a draw.\n");
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"The game was called a draw.\n");
                fprintf(ptr,"********************************************************\n");
            }
        }
        else if (player_count == 2)
        {
            printf("Enter your name (player 1).\n");
            scanf("%s", &d1.name);
            printf("Enter your name (player 2).\n");
            scanf("%s", &d2.name);
             printf("Each player will have 9 chances ,the one with the higher score wins.\n");
            for (int i = 0; i < 9; i++)
            {
                printf("Round %d\n", i + 1);
                p1_main_input = player_input(d1.name);
                p2_main_input = player_input(d2.name);
                printf("%s's choise is %c.\n", d2.name, p2_main_input);
                move_check(p1_main_input, p2_main_input, &d1.score, &d2.score, d1.name, d2.name);
            }
            if (d1.score > d2.score)
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("%s wins the game.\n", d1.name);
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"%s wins the game.\n", d1.name);
                fprintf(ptr,"********************************************************\n");
            }
            else if (d1.score < d2.score)
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("%s wins the game.\n", d2.name);
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"%s wins the game.\n", d2.name);
                fprintf(ptr,"********************************************************\n");
            }
            else
            {
                printf("%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                printf("The game was called a draw.\n");
                fprintf(ptr,"%s scored %d points and %s scored %d points.\n", d1.name, d1.score, d2.name, d2.score);
                fprintf(ptr,"The game was called a draw.\n");
                fprintf(ptr,"********************************************************\n");
            }
        }
        else
        {
            printf("INALID OUTPUT!\n");
            break;
        }
        fflush(stdin);
        printf("Do you want to play again?(Y/N)\n");
        scanf("%c", &restart);
    }

    printf("Game over.....");

    return 0;
}
