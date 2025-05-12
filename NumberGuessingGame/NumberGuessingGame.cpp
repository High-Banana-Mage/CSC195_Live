#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int max) {
    srand(time(0));
    return rand() % max + 1;
}

void game(int max) {
    int answer = random(max);
    bool won = false;
    for (int i = 0; i < 5; i++) {
        cout << "Guess ";
        cout << (i + 1) << endl;
        int guess;
        cin >> guess;
        if (guess > answer) {
            cout << "You guessed too high!" << endl;
        }
        else if (guess < answer) {
            cout << "You guessed too low!" << endl;
        }
        else {
            cout << "You guessed correctly!" << endl;
            won = true;
            break;
        }

    }
    if (!won) {
        cout << "You couldn't guess the number! You lose!" << endl;
    }
}

int main()
{
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have 5 tries!" << endl;
    cout << "Choose the max range of the game!" << endl;
    int range;
    while (true) {
        cout << "Range :";
        cin >> range;
        game(range);

        cout << "" << endl;
        cout << "Do you want to play again?[y/n]: ";
        char choice;
        cin >> choice;
        switch (choice) {
        case 'y':
            continue;
        case 'n':
            return 0;
        default:
            cout << "Invalid input, quiting game.";
            break;
        }
    }
    cout << "Goodbye!" << endl;
}
