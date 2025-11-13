#include <stdio.h> 
#include <stdbool.h>
#include <windows.h>
#include <safeinput.h>
#include "functions.h"


bool test_scan(void) { //test scan funktion
    int id;
    printf("Enter card number to test scan (0 to cancel):\n");
    GetInputInt("%d", &id);
    if (id == 0) {
        printf("Scan cancelled.\n");
        return false;
    }

    if (count == 0) {
        printf("No cards in system.\n");
        return false;
    }

    for (int index = 0; index < count; index++) {
        if (cards[index].card_nr == id) {
            printf("Access approved. Card found: Number = %d, Name = %s\n",
                   cards[index].card_nr, cards[index].card_name);
            return true;
        }
    }

    printf("Access denied. Card not found.\n");
    return false;
}