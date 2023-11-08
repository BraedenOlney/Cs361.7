/*
Braeden Olney
CS 361
Assignment # 7
Hand.h
header file of the outline for the class hand
*/
#pragma once
#include "Card.h"
#include <vector>;

class Hand {

public:

    // constructor
    Hand();

    // other members
    void addCardToHand(Card cardToHand);
    void printHand();
    int handSize();
    void discard(int index, Card newCard);
    bool Ace();
    int getHandValue();

private:

    // private property

    std::vector<Card> hand{};
    std::vector<int> getHandSuits();
    std::vector<int> getHandValues();
    bool hasKing();
    int getHighCard(std::vector<int> handValues);
    bool isFlush(std::vector<int> handSuits);
    bool isStraight(std::vector<int> handValues);
    bool isFourOfKind(std::vector<int> handValues);
    bool isThreeOfKind(std::vector<int> handValues);
    bool isTwoPair(std::vector<int> handValues);
    bool isPair(std::vector<int> handValues);
};