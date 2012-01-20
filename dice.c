// dice.c: Rolls a dice, input in the manner of 1d6
// Abritrary dice and sides can be entered
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void roll(int dice, int sides); 
int main (int argc, char *argv[])
{
    int dice, sides;
    // Simple error checking on arguments
    if ( argc != 2 )
    {
        fprintf(stderr, "You must enter one argument. ex:\n");
        fprintf(stderr, "\tdice 1d6\n");
        return 1;
    }

    srand((unsigned)time(NULL));  // Init seed for random numbers

    // Parse input
    dice = strtol(strtok(argv[1], "d"), NULL, 10);
    sides = strtol(strtok(NULL, "\n"), NULL, 10);
    
    // Roll dem fucking dice.
    roll(dice, sides);
    return 0;
}

void roll(int dice, int sides)
{
    int i, result, total = 0;
    for ( i=0; i < dice; i++)
    {
        result = 1 + rand() % sides;    // Would be between 0 and 5 without + 1
        printf("Die %d: %d\n", i + 1, result);
        total += result;
    }
    printf("Total: %d\n", total);
    return;
}

