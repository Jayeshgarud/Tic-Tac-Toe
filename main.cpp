#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j != 2)
                cout << " | ";
        }
        cout << endl;
        if (i != 2)
            cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool placeMove(int pos, char symbol) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = symbol;
        return true;
    }

    return false;
}

bool checkWin(char symbol) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol &&
            board[i][1] == symbol &&
            board[i][2] == symbol)
            return true;
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol &&
            board[1][i] == symbol &&
            board[2][i] == symbol)
            return true;
    }

    if (board[0][0] == symbol &&
        board[1][1] == symbol &&
        board[2][2] == symbol)
        return true;

    if (board[0][2] == symbol &&
        board[1][1] == symbol &&
        board[2][0] == symbol)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main() {

    char replay;

    do {

        initializeBoard();

        char currentPlayer = 'X';

        while (true) {

            displayBoard();

            int move;

            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";
            cin >> move;

            if (move < 1 || move > 9) {
                cout << "Invalid position!\n";
                continue;
            }

            if (!placeMove(move, currentPlayer)) {
                cout << "Position already taken!\n";
                continue;
            }

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " Wins!\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "Game Draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThanks for Playing!\n";

    return 0;
}
