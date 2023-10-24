#include <iostream>
#include <vector>

// Function to display the Tic-Tac-Toe board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (i < 2) {
            std::cout << "---------\n";
        }
    }
}

// Function to check if the current player has won
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; // There is an empty space, game is not a draw
            }
        }
    }
    return true; // All spaces are filled, game is a draw
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    bool gameOver = false;

    while (!gameOver) {
        // Display the board
        displayBoard(board);

        // Player input
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "It's a draw!\n";
            gameOver = true;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Ask if the players want to play again
    char playAgain;
    std::cout << "Play again? (y/n): ";
    std::cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board for a new game
        board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
        currentPlayer = 'X';
        gameOver = false;
    } else {
        std::cout << "Thanks for playing!\n";
    }

    return 0;
}
