#include<iostream>
#include <ctime>
using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while (running) {
        playerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)) {
            running = false;
            break;
        }
    }
}

void drawBoard(char *spaces)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;
}

void playerMove(char *spaces, char player)
{
    int number;
    do {
        cout << "Enter a spot to place a marker (1-9): ";
        cin >> number;
        number--;
        if (number >= 0 && number < 9 && spaces[number] == ' ') {
            spaces[number] = player;
            break;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    } while (true);
}

void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer; // Fixed assignment operator
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    if ((spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]) ||
        (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]) ||
        (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]) ||
        (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]) ||
        (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]) ||
        (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]) ||
        (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]) ||
        (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
        if (spaces[0] == player || spaces[3] == player || spaces[6] == player) {
            cout << "You win!" << endl;
        } else {
            cout << "You lose!" << endl;
        }
        return true;
    }
    return false;
}

bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    cout << "It's a tie!" << endl;
    return true;
}
