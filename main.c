#include <stdio.h> 
#include <stdbool.h>
#include <windows.h> 
#include "safeinput.h"
#include "functions.h"

//-------------------------------------------------------
int option;          //val i add/remove access funktionen
//---------------------------------------------------------

int main_menu(){
    int main_option;

    while (true) {
        printf("Admin menu\n");
        printf("1. Remote open door\n");
        printf("2. List all cards in system\n");
        printf("3. Add/remove access\n");
        printf("4. Exit\n");
        printf("9. FAKE TEST SCAN CARD\n");

        GetInputInt("Choose option:", &main_option);

        if (main_option == 4) {
            return 0;
        } else if (main_option == 1) {
            remote_open();
        } else if (main_option == 2) {
            listcards();
        } else if (main_option == 3) {
            card_menu();
        } else if (main_option == 9) {
            test_scan();
        } else {
            printf("Invalid option.\n");
        }
    }
}
int main(void) {
    main_menu();
    return 0;
}
