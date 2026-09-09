#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};


// Display the board
void displayBoard() {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n";
    cout << "\n";
}

// Check whether a player has won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check whether the board is full
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

// Make a move
bool makeMove(int position, char player) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (position < 1 || position > 9)
        return false;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = player;
    return true;
}

int main() {
    int position;
    char player = 'X';

    cout << "============================\n";
    cout << "       TIC TAC TOE\n";
    cout << "============================\n";

    cout << "Player 1: X\n";
    cout << "Player 2: O\n";

    while (true) {
        displayBoard();

        cout << "Player " << player << ", enter position (1-9): ";
        cin >> position;

        if (!makeMove(position, player)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Check winner
        if (checkWin(player)) {
            displayBoard();
            cout << "Congratulations! Player " << player << " wins!\n";
            break;
        }

        // Check draw
        if (checkDraw()) {
            displayBoard();
            cout << "Game Draw!\n";
            break;
        }

        // Change player
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    return 0;
}