#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char grid[3][3];
const char PLAYER_MARK = 'X';
const char AI_MARK = 'O';

void initializeGrid();
void displayGrid();
int countEmptyCells();
void playerTurn();
void aiTurn();
char determineWinner();
void announceWinner(char);
int minimax(int isMaximizing);
int getBestMove();

int main()
{
    char winner;
    char playAgain;

    do
    {
        winner = ' ';
        playAgain = ' ';
        initializeGrid();

        while (winner == ' ' && countEmptyCells() > 0)
        {
            displayGrid();

            playerTurn();
            winner = determineWinner();
            if (winner != ' ' || countEmptyCells() == 0)
                break;

            aiTurn();
            winner = determineWinner();
            if (winner != ' ' || countEmptyCells() == 0)
                break;
        }

        displayGrid();
        announceWinner(winner);

        printf("\nPlay again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);

    } while (playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

// Initialize the grid
void initializeGrid()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = ' ';
}

// Display the current grid
void displayGrid()
{
    printf(" %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);
}

// Count remaining empty cells
int countEmptyCells()
{
    int emptyCells = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == ' ')
                emptyCells++;

    return emptyCells;
}

// Player's move
void playerTurn()
{
    int row, col;

    do
    {
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        row--;
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        col--;

        if (grid[row][col] != ' ')
            printf("Invalid move! Try again.\n");
        else
        {
            grid[row][col] = PLAYER_MARK;
            break;
        }
    } while (1);
}

// AI's move using Minimax
void aiTurn()
{
    int moveIndex = getBestMove();
    int row = moveIndex / 3;
    int col = moveIndex % 3;
    grid[row][col] = AI_MARK;
}

// Determine if there's a winner
char determineWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != ' ')
            return grid[i][0];
        if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i] && grid[0][i] != ' ')
            return grid[0][i];
    }

    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != ' ')
        return grid[0][0];
    if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != ' ')
        return grid[0][2];

    return ' ';
}

// Announce the game result
void announceWinner(char winner)
{
    if (winner == PLAYER_MARK)
        printf("YOU WIN!\n");
    else if (winner == AI_MARK)
        printf("YOU LOSE!\n");
    else
        printf("IT'S A TIE!\n");
}

// Minimax algorithm for AI
int minimax(int isMaximizing)
{
    char result = determineWinner();
    if (result == AI_MARK) return 10;
    if (result == PLAYER_MARK) return -10;
    if (countEmptyCells() == 0) return 0;

    int bestScore = isMaximizing ? -1000 : 1000;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == ' ')
            {
                grid[i][j] = isMaximizing ? AI_MARK : PLAYER_MARK;
                int score = minimax(!isMaximizing);
                grid[i][j] = ' ';

                if (isMaximizing)
                    bestScore = (score > bestScore) ? score : bestScore;
                else
                    bestScore = (score < bestScore) ? score : bestScore;
            }
        }
    }
    return bestScore;
}

// Get the best move for AI
int getBestMove()
{
    int bestScore = -1000;
    int bestMove = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] == ' ')
            {
                grid[i][j] = AI_MARK;
                int score = minimax(0);
                grid[i][j] = ' ';

                if (score > bestScore)
                {
                    bestScore = score;
                    bestMove = i * 3 + j;
                }
            }
        }
    }
    return bestMove;
}
