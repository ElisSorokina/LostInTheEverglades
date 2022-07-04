#include <iostream>
#include <stdlib.h>
void printRules();
void startGame();

void initGameMatrix(char matrix[][5]);
void updateGameMatrix(char matrix[][5], int currentX, int currentY, int nextX, int nextY);
void printMatrix(char matrix[][5]);

using namespace std;
const int ASCII_ZERO_CODE=48;
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
    return 0;
}
void printRules(){
    cout<<"GAME RULES..."<<endl;
    cout<<"Lost in the Everglades in an RPG (Role-Playing-Game) between a player and the computer.\n"
          "\n"
          "A group of tourists has been lost in the Everglades and a ranger must rescue them before time runs out.\n"
          "\n"
          "The Everglades are represented by a 5x5 matrix. The ranger (R) starts the rescue at the upper-left corner of the park, the group of tourists (T) are lost at the lower-right corner. The ranger has 12 gongs of time to find and rescue the tourists before they perish.\n"
          "\n"
          "During the journey, the ranger might find dangers (hungry alligator, swarm of giant mosquitoes, venomous spider, or python).\n"
          "\n"
          "When the ranger finds a danger, they can choose to fight them, or hide and wait for them to leave.\n"
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
void startGame(){
    char matrix[5][5];

    initGameMatrix(matrix);

    printMatrix(matrix);
    cout<< "Gongs left: 12"<<endl;
    int currentX = 0;
    int currentY = 0;
    int nextX = 0;
    int nextY = 0;
    char nextInput[2];
    while(true){
        cout<<"Enter next cell (row & column): "<< endl;
        cin>> nextInput[0]>>nextInput[1];
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        nextX = (nextInput[0])-ASCII_ZERO_CODE;
        nextY = (nextInput[1])-ASCII_ZERO_CODE;
        if(nextX-currentX>1|| nextY-currentY>1){
            cout<<"Nice try! You can move to adjacent cells only."<<endl;

            continue;
        }
        updateGameMatrix(matrix, currentX, currentY, nextX, nextY);
        printMatrix(matrix);
        currentX = nextX;
        currentY = nextY;


    }

}

void printMatrix(char matrix[][5]) {
    cout<< "   0  1  2  3  4  "<<endl;
    for (int i = 0; i < 5; i++) {
        cout<<i<<"  ";
        for (int j = 0; j < 5; j++) {

            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

void initGameMatrix(char matrix[][5]) {
    for (int i = 0; i < 5 ; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = '*';
    matrix[0][0]='R';
    matrix[4][4]='T';
}
void updateGameMatrix(char matrix[][5], int currentX, int currentY, int nextX, int nextY){
    matrix[currentX][currentY] = ' ';
    matrix[nextX][nextY] = 'R';
}
