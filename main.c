#include <stdio.h> 
#include <stdbool.h>
#include <windows.h> 
#include "safeinput.h"
#include "functions.h"

//-------------------------------------------------------
// Endast lokala variabler – ingen global database!
//-------------------------------------------------------

int main_menu(CardDB *db) {
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
            remote_open(db);
        } else if (main_option == 2) {
            listcards(db);
        } else if (main_option == 3) {
            card_menu(db);
        } else if (main_option == 9) {
            test_scan(db);
        } else {
            printf("Invalid option.\n");
        }
    }
}

int main(void) {
    CardDB db = { NULL, 0 };   // Initiera lokal databas
    main_menu(&db);
    free(db.cards);            // Städa minne innan program avslutas
    return 0;
}
