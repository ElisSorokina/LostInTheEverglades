#include <iostream>
#include <random>
#include <cstdlib>

const int DIMENSIONS = 5;
const int MOB_NUMBER = 10;

void printRules();

void startGame();

void populateMobMatrix(char mobMatrix[][DIMENSIONS]);

void initGameMatrix(char matrix[][DIMENSIONS]);

void updateGameMatrix(char matrix[][DIMENSIONS], int currentX, int currentY, int nextX, int nextY);

void printMatrix(char matrix[][DIMENSIONS]);

bool encounterDanger(int &gongs);

void checkEndGame(int currentX, int currentY, int gongs);

bool isFightWon();

void restartGame();

using namespace std;
const int ASCII_ZERO_CODE = 48;

int main() {
    char number;

    cout << "Lost in the Everglades..." << endl;
    while (true) {
        cout << "Please select a number(1-3)" << endl;
        cout << "1. See Rules." << endl;
        cout << "2. Play Game." << endl;
        cout << "3. Exit." << endl;


        cin >> number;


        switch (number) {
            case '1':
                printRules();
                break;
            case '2':
                startGame();
                break;
            case '3':
                //exit
                exit(0);

            default:
                cout << "Unknown option. Try again..." << endl;


        }

    }

}

void printRules() {
    cout << "GAME RULES..." << endl;
    cout << "Lost in the Everglades in an RPG (Role-Playing-Game) between a player and the computer.\n"
            "\n"
            "A group of tourists has been lost in the Everglades and a ranger must rescue them before time runs out.\n"
            "\n"
            "The Everglades are represented by a 5x5 matrix. The ranger (R) starts the rescue at the upper-left corner of the park, the group of tourists (T) are lost at the lower-right corner. The ranger has 12 gongs of time to find and rescue the tourists before they perish.\n"
            "\n"
            "During the journey, the ranger might find dangers (hungry alligator, swarm of giant mosquitoes, venomous spider, or python).\n"
            "\n"
            "When the ranger finds a danger, they can choose to isFightWon them, or hide and wait for them to leave.\n"
            "\n"
            "If the Ranger waits\n"
            "Moves to the desired cell\n"
            "Loses 5 gongs of time\n"
            "If the Ranger fights and wins\n"
            "Moves to the desired cell\n"
            "Loses 2 gongs of time\n"
            "If the Ranger fights and loses\n"
            "Goes back to the initial cell\n"
            "Loses 3 gongs of time\n"
            "The danger remains in the cell\n"
            "Notes\n"
            "If the Ranger move to a cell with no dangers\n"
            "Loses 1 gong of time\n"
            "The game ends when either:\n"
            "The ranger rescues the group of tourists.\n"
            "The time expires and the fate of the tourists is forever unknown.\n"
            "---------------------------------------\n";//implement rules
}

void startGame() {
    char matrix[DIMENSIONS][DIMENSIONS];
    char mobMatrix[DIMENSIONS][DIMENSIONS] = {0};
    memset (mobMatrix, 0, sizeof(mobMatrix) );
    int gongs = 12;
    initGameMatrix(matrix);

    printMatrix(matrix);
    populateMobMatrix(mobMatrix);

    int currentX = 0;
    int currentY = 0;
    int nextX;
    int nextY;
    char nextInput[2];
    while (true) {
        cout << "Gongs left: " << gongs << endl;
        cout << "Enter next cell (row & column): " << endl;
        cin >> nextInput[0] >> nextInput[1];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        nextX = (nextInput[0]) - ASCII_ZERO_CODE;
        nextY = (nextInput[1]) - ASCII_ZERO_CODE;
        if (nextX == currentX && nextY == currentY) {
            cout << "Wake up! You have to move on..." << endl;
            continue;
        }
        if (nextX - currentX > 1 || nextY - currentY > 1 ||
            currentX - nextX > 1 || currentY - nextY > 1) {
            cout << "Nice try! You can move to adjacent cells only." << endl;

            continue;
        }
        bool advance = true;
        if (mobMatrix[nextX][nextY] == 'D') {
            advance = encounterDanger(gongs);

        }
        if (advance) {
            updateGameMatrix(matrix, currentX, currentY, nextX, nextY);

            currentX = nextX;
            currentY = nextY;
            mobMatrix[currentX][currentY] = 0;

            gongs = gongs - 1;

        }
        checkEndGame(currentX, currentY, gongs);
        printMatrix(matrix);
    }

}

bool encounterDanger(int &gongs) {
    int mobType = rand() % 4;
    string dangerName[] = {"Hungry Alligator", "Swarm of Giant Mosquitos", "Venomous Spider", "Python"};

    const string &currentDanger = dangerName[mobType];
    cout << "Watch out! There is a " << currentDanger << " ahead." << endl;
    cout << "Choose your next move." << endl;
    cout << "1. Fight" << endl;
    cout << "2. Wait" << endl;

    char userChoice;
    while (true) {
        cin >> userChoice;

        switch (userChoice) {
            case '1':
                if (isFightWon()) {
                    cout << "You fight the " << currentDanger << " And win.. You advance." << endl;
                    gongs -= 1;
                    return true;
                } else {
                    cout << "You fight the " << currentDanger << " And lose...Retreat." << endl;
                    gongs -= 3;
                    return false;
                }

            case '2':
                cout << currentDanger << " Is gone... You advance." << endl;
                gongs -= 4;

                return true;
            default:
                cout << "Invalid input." << endl;
        }
    }


}

bool isFightWon() {

    return rand() % 2 > 0;
}

void checkEndGame(int currentX, int currentY, int gongs) {
    if (currentX == DIMENSIONS - 1 && currentY == DIMENSIONS - 1) {
        cout << "You win!" << endl;
        cout<<" Play again? (y/n)"<<endl;
        restartGame();


    }
    if (gongs <= 0) {
        cout << "You are out of time!"<<endl;
         cout<< "You lose! Try again? (y/n)" << endl;
        restartGame();
    }
}

void restartGame() {
    char input;
    while (true) {
        cin >> input;
        switch (input) {
            case 'y':
                startGame();
                break;
            case 'n':
                exit(0);

            default :
                cout << "Incorrect input..." << endl;
                break;

        }
    }
}

void printMatrix(char matrix[][DIMENSIONS]) {
    cout << "   0  1  2  3  4  " << endl;
    for (int i = 0; i < DIMENSIONS; i++) {
        cout << i << "  ";
        for (int j = 0; j < DIMENSIONS; j++) {

            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void initGameMatrix(char matrix[][DIMENSIONS]) {
    for (int i = 0; i < DIMENSIONS; i++)
        for (int j = 0; j < DIMENSIONS; j++)
            matrix[i][j] = '*';
    matrix[0][0] = 'R';
    matrix[4][4] = 'T';
}

void updateGameMatrix(char matrix[][DIMENSIONS], int currentX, int currentY, int nextX, int nextY) {
    matrix[currentX][currentY] = ' ';
    matrix[nextX][nextY] = 'R';
}

void populateMobMatrix(char mobMatrix[][DIMENSIONS]) {

    int randomNumbers[23];
    //create array with numbers from 1 to 23
    for (int i = 0; i < 23; i++) {
        randomNumbers[i] = i + 1;
    }

    // get time-based seed
    unsigned seed = std::chrono::system_clock::now()
            .time_since_epoch()
            .count();
    //randomize elements of randomNumbers
    shuffle(&randomNumbers[0], &randomNumbers[22], default_random_engine(seed));
    //take first 10 random numbers and turn them into matrix indexes
    for (int i = 0; i < MOB_NUMBER; i++) {
        mobMatrix[randomNumbers[i] / DIMENSIONS][randomNumbers[i] % DIMENSIONS] = 'D';
    }

}