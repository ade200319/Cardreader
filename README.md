KortSystem

Ett enkelt administrativt program för att hantera kortåtkomst. Programmet är skrivet i C och fungerar på Windows.

Funktioner

Skapa nya kort och registrera kortnummer och namn.

Ta bort kortåtkomst.

Lista alla registrerade kort.

Fjärröppna dörr med timer.

Testa kortläsare med simulerad "fake scan".

Filstruktur

main.c – Programmet startar här och visar huvudmenyn.

functions.c – Innehåller funktioner för korthantering och dörrkontroll.

functions.h – Headerfil för funktionerna och kortstrukturen.

safeinput.h – Bibliotek för säker inmatning (GetInputInt/GetInputChar).

makefile – Kompilationsinstruktioner för programmet.

Kompilering

Programmet kompileras med GCC (MinGW) på Windows:

cc -o main.exe -Wall -Werror -g -I. main.c functions.c


Eller med make:

mingw32-make

Användning

Starta programmet (main.exe).

Välj alternativ från huvudmenyn:

1 – Fjärröppna dörr

2 – Lista alla kort

3 – Lägg till / ta bort kort

4 – Avsluta

9 – Testa kortläsning

Följ instruktionerna för respektive menyval.

Noteringar

Programmet sparar inte kortdata mellan körningar.

Antal kort som kan registreras begränsas endast av tillgängligt minne.

Kortnamn är begränsade till 20 tecken.

Förbättringsförslag

Spara kortdata till fil för persistens mellan körningar.

Låta användarnamn vara dynamiskt längdbegränsat.

Implementera bättre felhantering vid minnesbrist.
