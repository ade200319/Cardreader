#include "functions.h"
#include <stdlib.h>
#include <time.h>

// Skapa nytt kort
bool creatnewcard(CardDB *db, card *newcard) {
    printf("Enter new card number / 0 to exit:\n");
    GetInputInt("%d", &newcard->card_nr);
    if (newcard->card_nr == 0) return false;

    GetInput("Enter card registration name:\n", newcard->card_name, sizeof(newcard->card_name));

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(newcard->created_date, sizeof(newcard->created_date), "%Y-%m-%d", t);

    db->count++;
    card* temp = realloc(db->cards, db->count * sizeof(card));
    if (temp == NULL) {
        printf("Memory error!\n");
        return false;
    }
    db->cards = temp;

    db->cards[db->count - 1] = *newcard;

    printf("Card added!\n");
    return true;
}

// Ta bort kort
bool removecard(CardDB *db) {
    int id;
    printf("Enter card number to remove:\n");
    GetInputInt("%d", &id);

    for (int x = 0; x < db->count; x++) {
        if (db->cards[x].card_nr == id) {

            for (int y = x; y < db->count - 1; y++)
                db->cards[y] = db->cards[y + 1];

            db->count--;

            if (db->count == 0) {
                free(db->cards);
                db->cards = NULL;
            } else {
                card* temp = realloc(db->cards, db->count * sizeof(card));
                if (temp == NULL) {
                    printf("Memory error!\n");
                    return false;
                }
                db->cards = temp;
            }

            printf("Card access removed\n");
            return true;
        }
    }

    printf("Card not found\n");
    return false;
}

// Dörröppning
int remote_open(CardDB *db) {
    (void)db; // används ej men krävs för headern

    printf("Door unlocked, closing in:\n");
    for (int timer = 10; timer >= 0; timer--) {
        printf("%d\n", timer);
        fflush(stdout);
        Sleep(1000);
    }
    return 0;
}

// Lista alla kort
void listcards(CardDB *db) {
    if (db->count == 0) {
        printf("No cards in system.\n");
        return;
    }

    printf("Cards currently in system:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Card %d: Number = %d, Name = %s, Date = %s\n",
            i + 1, db->cards[i].card_nr,
            db->cards[i].card_name,
            db->cards[i].created_date);
    }
}

// Test-scanna kort
bool test_scan(CardDB *db) {
    int id;
    printf("Enter card number to test scan (0 to cancel):\n");
    GetInputInt("%d", &id);

    if (id == 0) {
        printf("Scan cancelled.\n");
        return false;
    }

    for (int i = 0; i < db->count; i++) {
        if (db->cards[i].card_nr == id) {
            printf("Access granted. Card found: %s\n", db->cards[i].card_name);
            return true;
        }
    }

    printf("Access denied. Card not found.\n");
    return false;
}

// Kortmeny
int card_menu(CardDB *db) {
    int option;

    while (true) {
        printf("1. Create new card user\n");
        printf("2. Remove card access\n");
        printf("3. Exit\n");
        GetInputInt("%d", &option);

        if (option == 1) {
            card newcard;
            creatnewcard(db, &newcard);
        } else if (option == 2) {
            removecard(db);
        } else if (option == 3) {
            break;
        }
    }

    return 0;
}
