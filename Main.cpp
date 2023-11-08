/*
Braeden Olney
CS 361
Assignment # 7
Main.cpp
Prints out the same output as assignment 6 but adds the
functionality of getting the hand value
*/

#include "Deck.h"
#include "Hand.h"
#include "Card.h"

using namespace std;
//using namespace cardDeck;

// initialize the method
bool goodDiscards(vector<int>);

int main() {

    // error status 
    int errorStatus = 0;

    // make a deck and hand
    std::unique_ptr<Deck> deck = std::make_unique<Deck>();
    std::unique_ptr<Hand> hand = std::make_unique<Hand>();

    // constant for the size of hand
    const int sizeOfHand = 5;


    
    // add cards to hand from deck
    for (int handSize = 0; handSize < sizeOfHand; handSize++) {
        hand->addCardToHand(deck->dealCard());
    }
    
    /*
    // for testing
    hand->addCardToHand(Card{ cardDeck::values::Ace, cardDeck::suits::Club });
    hand->addCardToHand(Card{ cardDeck::values::King, cardDeck::suits::Club });
    hand->addCardToHand(Card{ cardDeck::values::Queen, cardDeck::suits::Club });
    hand->addCardToHand(Card{ cardDeck::values::Jack, cardDeck::suits::Club });
    hand->addCardToHand(Card{ cardDeck::values::Ten, cardDeck::suits::Club });
    */
    // print out hand size, hand, and deck size
    cout << "There are " << hand->handSize() << " cards in the hand" << endl;
    cout << "These cards are in the hand: ";
    hand->printHand();
    cout << endl << endl;
    cout << hand->getHandValue() << endl;
    cout << "There are " << deck->deckSize() << " cards remaining in the deck" << endl << endl;
    cout << "You may replace three cards in your hand, four if you have an ace" << endl;
    cout << "Please enter the number of card(s) you wish to discard, followed by <ctrl>z: ";

    // how many cards the user can replace with current hand based on if an ace is in the hand
    int numAbleRemove = 3;
    if (hand->Ace()) {
        numAbleRemove = 4;
    }


    // initialize a vector for user input
    std::vector<int> removeIndexes{};

    // user input to put into the vector for index values to remove
    int nextIndex;

    // get all user input until ctrl z
    while (cin >> nextIndex) {
        removeIndexes.push_back(nextIndex - 1);

        // stop after maximum remove is reached
        if (numAbleRemove <= removeIndexes.size()) {
            break;
        }
    }

    // if the values in the vector are not duplicates and are from 0-4
    if (goodDiscards(removeIndexes)) {
        // change the cards for all the index
        for (int currIndexRemove : removeIndexes) {
            hand->discard(currIndexRemove, deck->dealCard());
        }

        //reprint the hand
        // print out hand size, hand, and deck size
        cout << "There are " << hand->handSize() << " cards in the hand" << endl;
        cout << "These cards are in the hand: ";
        hand->printHand();
    }
    else { // if invalid 
        cerr << "invalid discard";
        errorStatus = 1;
    }

    // return status
    return errorStatus;
}

// checks discard indexes for valid indexes and duplicates 
bool goodDiscards(vector<int> indexesVector) {

    // Array for duplicate check, if a number is 1 the index is in the vector
    int duplicateCheck[5] = { 0,0,0,0,0 };

    //return value
    bool toReturn = true;

    // loop through the vector
    for (int currIndex : indexesVector) {

        // if the index value is out of the hand indexing return false because the card cannot be indexed
        if (currIndex < 0 && currIndex > 4) {
            toReturn = false;
            break;
        }// if the current index is not zero then the index is already in the vector thus its a duplicate return false
        if (duplicateCheck[currIndex] != 0) {
            toReturn = false;
            break;
        }
        else { // else the index isnt in the vector thus mark that it is in the array check
            duplicateCheck[currIndex] = 1;
        }
    }

    // if all conditions passed return true
    return true;

}