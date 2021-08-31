//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>

// if you want to set a pointer to a literal, always make sure you use the const keyword

int main() {
    char cards[] = "JQK";
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] =  cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(cards);
    return 0;
}
