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

//------------------------------------------------------
// Globala variabler (endast deklaration, ej definition)
extern card *cards;
extern int count;

//------------------------------------------------------
// Funktionsdeklarationer
bool creatnewcard(card *newcard);
bool removecard(void);
int remote_open(void);
void listcards(void);
int card_menu(void);
bool test_scan(void);

#endif
