#include "functions.h"
#include <stdlib.h> // för realloc, free
#include <time.h>

//------------------------------------------------------
card *cards = NULL;
int count = 0;
//------------------------------------------------------

// Skapa nytt kort--------------------------------------------------------------------
bool creatnewcard(card *newcard) {
    printf("Enter new card number / 0 to exit:\n");
    GetInputInt("%d", &newcard->card_nr);
    if (newcard->card_nr == 0) return false;

    GetInput("Enter card registration name:\n", newcard->card_name, sizeof(newcard->card_name));
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(newcard->created_date, sizeof(newcard->created_date), "%Y-%m-%d", t); //för att få med datum kort skapades


    count++;
    card* temp = realloc(cards, count * sizeof(card));
if (temp == NULL) {
    printf("Memory error!\n");
    return false;
}
cards = temp;

    cards[count - 1] = *newcard;

    printf("Card added!\n");
    return true;
}
//------------------------------------------------------------------------------------
// Ta bort kort
bool removecard(void) {
    int id;
    printf("Enter card number to remove:\n");
    GetInputInt("%d", &id);
    for (int x = 0; x < count; x++) {
        if (cards[x].card_nr == id) {
            for (int y = x; y < count - 1; y++) {
                cards[y] = cards[y + 1];
            }
            count--;
            if (count == 0) {
                free(cards);
                cards = NULL;
            } else {
               card* temp = realloc(cards, count * sizeof(card));
            if (temp == NULL) {
              printf("Memory error!\n");
              return false;
            }
            cards = temp;

            }
            printf("Card access removed\n");
            return true;
        }
    }
         printf("Card not found\n");
         return false;
}

// Dörröppning
int remote_open(void) {
    printf("Door unlocked, closing in:\n");
    for (int timer = 10; timer >= 0; timer--) {
        printf("%d\n", timer);
        fflush(stdout);
        Sleep(1000);
    }
    return 0;
}

// Lista alla kort
void listcards(void) {
    if (count == 0) {
        printf("No cards in system.\n");
        return;
    }

    printf("Cards currently in system:\n");
    for (int i = 0; i < count; i++) {
        printf("Card %d: Number = %d, Name = %s, Date = %s\n",
       i + 1, cards[i].card_nr, cards[i].card_name, cards[i].created_date);

    }
}

// Test-scanna kort
bool test_scan(void) {
    int id;
    printf("Enter card number to test scan (0 to cancel):\n");
    GetInputInt("%d", &id);

    if (id == 0) {
        printf("Scan cancelled.\n");
        return false;
    }

    for (int i = 0; i < count; i++) {
        if (cards[i].card_nr == id) {
            printf("Access granted. Card found: %s\n", cards[i].card_name);
            return true;
        }
    }

    printf("Access denied. Card not found.\n");
    return false;
}

// Kortmeny
int card_menu(void) {
    int option;
    while (true) {
        printf("1. Create new card user\n");
        printf("2. Remove card access\n");
        printf("3. Exit\n");
        GetInputInt("%d", &option);

        if (option == 1) {
            card newcard;
            creatnewcard(&newcard);
        } else if (option == 2) {
            removecard();
        } else if (option == 3) {
            break;
        }
    }
    return 0;
}
