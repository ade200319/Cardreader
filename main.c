#include <stdio.h> 
#include <stdbool.h>
#include <windows.h> 
#include "safeinput.h"
#include "functions.h"

//-------------------------------------------------------
int option;          //val i add/remove access funktionen
//---------------------------------------------------------

int main_menu(){
    while(true){
printf("Admin menu\n");
printf("1. Remote open door\n");
printf("2. List all cards in system\n");
printf("3. Add/remove access\n");
printf("4. Exit\n");
printf("9. FAKE TEST SCAN CARD\n");
    }

int main_option;

GetInputInt("Choose option:", &main_option);
if(main_option == 4){
return 0;
}
else if(main_option == 1){
    remote_open();     //------------- remote open door funktion
}

 else if(main_option == 2){
   listcards(); //lista alla kort funktion
    }
else if(main_option == 3){
     card_menu();           //---------- meny för att skapa nya kort/ radera 
 
}
else if(main_option == 9){
   test_scan(); // test scan funktion
}

   
}