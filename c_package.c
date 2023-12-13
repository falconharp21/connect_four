#include <stdio.h>

#define ROWS 6
#define COLS 7

// Function to initialize the game board
void initializeBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the game board
void displayBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        for (int j = 0; j < COLS; j++) {
            printf("----");
        }
        printf("\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("  %d ", j + 1);
    }
    printf("\n\n");
}

// Function to check if a player has won
int checkWin(char board[ROWS][COLS], char player) {
    // Check horizontally
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player) {
                return 1; // Win
            }
        }
    }

    // Check vertically
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player) {
                return 1; // Win
            }
        }
    }

    // Check diagonally (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player &&
                board[i - 3][j + 3] == player) {
                return 1; // Win
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player &&
                board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player) {
                return 1; // Win
            }
        }
    }

    return 0; // No win
}

// Function to check if the board is full
int isBoardFull(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

int main() {
    char board[ROWS][COLS];
    int currentPlayer = 1; // Player 1 starts
    int column;

    initializeBoard(board);

    printf("Welcome to Connect Four!\n");

    do {
        displayBoard(board);

        printf("Choose 1st and 2nd Players among yourselves \n\n ");
        printf("Lets Start to Play and have fun \n\n");
        // Get the current player's move
        printf("Player %d, enter your move (1-%d): ", currentPlayer, COLS);
        scanf("%d", &column);

        // Validate the move
        if (column < 1 || column > COLS || board[0][column - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Drop the disc in the selected column
        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][column - 1] == ' ') {
                board[i][column - 1] = (currentPlayer == 1) ? 'X' : 'O';
                break;
            }
        }

        // Check for a win
        if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O')) {
            displayBoard(board);
            printf("Player %d wins!\n", currentPlayer);
            break;
        }

        // Check for a tie
        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a tie!\n");
            break;
        }

        // Switch to the other player
        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }

    } while (1);

    return 0;
}
