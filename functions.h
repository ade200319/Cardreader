#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <safeinput.h>

//------------------------------------------------------
// struct för card 
typedef struct {           
    int card_nr;
    char card_name[20];
    char created_date[20];
} card;

typedef struct {
    card *cards;
    int count;
} CardDB;
//------------------------------------------------------

//------------------------------------------------------
// Funktionsdeklarationer
bool creatnewcard(CardDB *db, card *newcard);
bool removecard(CardDB *db);
int remote_open(CardDB *db);
void listcards(CardDB *db);
int card_menu(CardDB *db);
bool test_scan(CardDB *db);

#endif
