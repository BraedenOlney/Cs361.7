/*
Braeden Olney
CS 361
Assignment # 7
Deck.cpp
Class for Deck setting the methods to use in main for the objects
*/
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include <iostream>

Deck::Deck() {

    // Deck Default Constructor 
    for (cardDeck::suits suit : cardDeck::suitArray) {

        for (cardDeck::values value : cardDeck::valuesArray) {

            Card currentCard{ value, suit };
            deck.push_back(currentCard);

        }

    }


}

Card Deck::dealCard() {
    // initialize the random seed
    srand(time(0));
    // random number from 0-number of cards in deck
    int randNum = rand() % Deck::deckSize();

    // store random card to return
    Card cardToReturn = deck.at(randNum);

    // delete card from deck
    deck.erase(deck.begin() + randNum);

    return cardToReturn;
}

// return deck size 
int Deck::deckSize() {
    return deck.size();
}
