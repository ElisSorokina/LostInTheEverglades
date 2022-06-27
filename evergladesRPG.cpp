#include <iostream>

void printRules();

using namespace std;

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
                //implement game
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