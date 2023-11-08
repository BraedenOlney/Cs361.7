/*
Braeden Olney
CS 361
Assignment # 7
Hand.cpp
Class for Hand setting the methods to use in main for the objects
*/
#include "Hand.h"
#include "Card.h"
#include <iostream>;

// defalut constructor do nothing
Hand::Hand() {

}

// Hand constructor with parameter put card into hand
void Hand::addCardToHand(Card cardToHand) {

    hand.push_back(cardToHand);

}

// print the hand
void Hand::printHand() {
    // print each card in hand
    std::cout << "These cards are in the hand: ";
    //for the current card number
    int cardCounter = 1;
    for (Card cardItt : hand) {
        std::cout << std::endl << "Card " << cardCounter << " ";
        cardCounter++;
        cardItt.printCard();
        std::cout << " ";

    }
}

// return hand size
int Hand::handSize() {

    return hand.size();

}

// change the card in the index with the passed card
void Hand::discard(int index, Card newCard) {

    Hand::hand[index] = newCard;

    
}

std::vector<int> Hand::getHandValues() {

    //indexes: Two = 0, ... , Ace = 12
    std::vector<int> returnVector = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };

    // for all the
    for (Card currCard : Hand::hand) {
        switch (currCard.getValue()) {
        case cardDeck::values::Ace:
            returnVector[12]++;
            break;
        case cardDeck::values::Two:
            returnVector[0]++;
            break;
        case cardDeck::values::Three:
            returnVector[1]++;
            break;
        case cardDeck::values::Four:
            returnVector[2]++;
            break;
        case cardDeck::values::Five:
            returnVector[3]++;
            break;
        case cardDeck::values::Six:
            returnVector[4]++;
            break;
        case cardDeck::values::Seven:
            returnVector[5]++;
            break;
        case cardDeck::values::Eight:
            returnVector[6]++;
            break;
        case cardDeck::values::Nine:
            returnVector[7]++;
            break;
        case cardDeck::values::Ten:
            returnVector[8]++;
            break;
        case cardDeck::values::Jack:
            returnVector[9]++;
            break;
        case cardDeck::values::Queen:
            returnVector[10]++;
            break;
        case cardDeck::values::King:
            returnVector[11]++;
            break;
        }
    }

    // return filled vector
    return returnVector;
}

// list all suits present in a vector
std::vector<int> Hand::getHandSuits() {

    // indexes : 0 = clubs, 1 = diamonds, 2 = hearts, 3 = spades
    std::vector<int> returnVector = { 0,0,0,0 };

    // for all the cards in the hand increment if the suit is the current card
    for (Card currCard : Hand::hand) {
        switch (currCard.getSuit()) {
        case cardDeck::suits::Club:
            returnVector[0]++;
            break;
        case cardDeck::suits::Diamond:
            returnVector[1]++;
            break;
        case cardDeck::suits::Heart:
            returnVector[2]++;
            break;
        case cardDeck::suits::Spade:
            returnVector[3]++;
            break;
        }
    }

    // return filled vector
    return returnVector;

}

// return true if an ace is in the hand
bool Hand::Ace() {

    // return value
    bool toReturn = false;

    // for all the cards in the hand
    for (Card currCard : hand) {

        // if current card is an ace set return
        if (currCard.getValue() == cardDeck::values::Ace) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// returns true if hand has a king
bool Hand::hasKing() {

    // return value
    bool toReturn = false;

    // for all the cards in teh hand
    for (Card currCard : hand) {

        // if the current cards value is a king set  true
        if (currCard.getValue() == cardDeck::values::King) {

            toReturn = true;
            break;

        }

    }

    // return status
    return toReturn;
}

// gets the high card of a given vector
int Hand::getHighCard(std::vector<int> handValues) {

    // return the highest cards value
    int toReturn = 0;

    // position in vector
    int vectorPos = 0;

    // for all the values in the vector
    for (int currValue : handValues) {

        // if the current vaule is higher than the current highest set new highest
        if (currValue > 0 && cardDeck::numValuesArray[vectorPos] > toReturn) {
            toReturn = cardDeck::numValuesArray[vectorPos];
        }

        // increment counter
        vectorPos++;
    }
    
    // return highest card
    return toReturn;
}

// check for flush
bool Hand::isFlush(std::vector<int> handSuits) {
    // return value
    bool toReturn = false;

    // loop through the suits vector
    for (int currSuit : handSuits) { 
        // if suits vector has a 5 all cards are same suit thus the hand is a flush
        if (currSuit == 5) {

            // return true
            toReturn = true;
        }
    }

    // return status
    return toReturn;
}

// checks for straight
bool Hand::isStraight(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // if hand has ace and  not king 
    // make vector with just the wheel straight to check for the wheel straight
    if (Ace() && !hasKing()) {
        // indexes: A = 0, 2 = 1, ... , 5 = 4 
        handValues = { 0,0,0,0,0 };
        for (Card currCard : Hand::hand) {
            switch (currCard.getValue()) {
            case cardDeck::values::Ace:
                handValues.at(0)++;
            case cardDeck::values::Two:
                handValues.at(1)++;
            case cardDeck::values::Three:
                handValues.at(2)++;
            case cardDeck::values::Four:
                handValues.at(3)++;
            case cardDeck::values::Five:
                handValues.at(4)++;
            }
        }
    }

    // consecitive counter 
    int consecitive = 0;

    // for all the values in the vector
    for (int currCard : handValues) {

        // if there is a consecitive line going and the current value is a zero break and return false because hand is not a straight
        if (consecitive > 0 && currCard == 0) {
            break;
        }// if the currCard value is greater than 1 there are two card in the hand thus not a straight return false
        else if (currCard > 1) {
            break;
        } // if 1 increment the consecitive counter
        else if (currCard == 1) {
            consecitive++;
        }
    }

    // after the loop if the counter is equal to 5 set return to true
    if (consecitive == 5) {
        toReturn = true;
    }

    // reutrn status
    return toReturn;
}

// checks if its a four of a kind
bool Hand::isFourOfKind(std::vector<int> handValues) {

    // return value
    bool toReturn = false;
    
    // for all the values in the hand
    for (int currCard : handValues) {

        // if four 
        if (currCard == 4) {

            // set true
            toReturn = true;
            break;
        }
    }
    
    // return status
    return toReturn;
}

// checks if its a 3 of a kind
bool Hand::isThreeOfKind(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // for all the values in the vector
    for (int currCard : handValues) {
        // if three
        if (currCard == 3) {

            // set true
            toReturn = true;
            break;
        }
    }
    // return status
    return toReturn;
}

// checks if hand is a pair
bool Hand::isPair(std::vector<int> handValues) {

    // return value
    bool toReturn = false;

    // for all the values in the vector
    for (int currCard : handValues) {

        // if pair
        if (currCard == 2) {

            // set status to true
            toReturn = true;
            break;
        }
    }

    // return status
    return toReturn;
}

// checks if its two pair
bool Hand::isTwoPair(std::vector<int> handValues) {
    // return value
    bool toReturn = false;

    // number of pairs in hand
    int numPairs = 0;

    //for all the values in the vector
    for (int currCard : handValues) {

        // if pair add to the number of pairs
        if (currCard == 2) {
            numPairs++;
        }

        // if num pairs is 2 then the hand has two pairs
        if (numPairs == 2) {

            // set return value to true
            toReturn = true;
            break;
        }
    }

    // return status
    return toReturn;
}

// gets value of the hand from 1,000,000 to 100,000
int Hand::getHandValue() {

    // int to return
    int returnValue = 0;

    // Royal Flush
    if (Hand::isFlush(getHandValues()) && Hand::isStraight(getHandValues()) && Hand::Ace() && Hand::hasKing()) {
        // value for royal flush
        returnValue = 1'000'000;
    }// straight flush
    else if (Hand::isFlush(getHandSuits()) && Hand::isStraight(getHandValues())) {

        //base value for straight flush
        returnValue = 900'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // if the straight is not a broadway straight
        if (Ace() && !hasKing()) {
            // get rid of ace
            currVector.at(12) = 0;
        }

        // add high card value ot the value to return
        returnValue += getHighCard(currVector);

    }// Four of a Kind
    else if (isFourOfKind(getHandValues())) {

        // base return value
        returnValue = 800'000;

        // current positon in vector
        int cardPosition = 0;
        for (int vectorValue : getHandValues()) {
            
            // if four of a kind multiply card value by primary multiply
            if (vectorValue == 4) {
                
                returnValue += (cardDeck::highCardMultiples[0] * cardDeck::numValuesArray[cardPosition]);

            } //if single card add value to returnValue
            else if (vectorValue == 1) {

                returnValue += cardDeck::numValuesArray[cardPosition];

            }

            // increment counter
            cardPosition++;
        }
    }// Full House
    else if (isThreeOfKind(getHandValues()) && isPair(getHandValues())) {

        // base value to return
        returnValue = 700'000;

        // card position in vector
        int cardPosition = 0;

        // loop for each value in the vector
        for (int vectorValue : getHandValues()) {

            // if three of a kind
            if (vectorValue == 3) {

                // priority value
                returnValue += cardDeck::highCardMultiples[0] * cardDeck::numValuesArray[cardPosition];

            }
            else if (vectorValue == 2) {

                // secondary value
                returnValue += cardDeck::highCardMultiples[1] * cardDeck::numValuesArray[cardPosition];
            }
            // increment position
            cardPosition++;
        }
    }// Flush
    else if (isFlush(getHandSuits())) {

        // base value
        returnValue = 600'000;

        // current high card value
        int currHighCard = 0;

        // number of cards looped through
        int numHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[numHighCard] * currHighCard;

            //increment high card counter
            numHighCard++;

            /*
                        if (currHighCard == 14) {
                            currHighCard = 1;
                        }
                        */

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;




        }

        
    }// Straight
    else if (isStraight(getHandValues())) {

        // base straight value
        returnValue = 500'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // if the straight is not a broadway straight
        if (Ace() && !hasKing()) {
            currVector.at(13) = 0;
        }

        returnValue += getHighCard(currVector);

        /*
        // loop for all values in the hand because all card will be examined
        for (Card currCard : Hand::hand) {
            int currHighCard = getHighCard(currVector);
            returnValue += (preHighCard + currHighCard);
            preHighCard -= 50;
            if (currHighCard == 14) {
                currHighCard = 1;
            }
            currVector.at(currHighCard - 1) = 0;
        }
        */

        
    }// Three of a kind
    else if (isThreeOfKind(getHandValues())) {

        // Base value
        returnValue = 400'000;
 
        // position in the vector
        int cardPosition = 0;

        // num single high cards
        int numSingle = 0;

        // current multiply value for hand Value for after pairs
        int currMulti = 0;

        // current high card
        int currHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // for each value in the values vector
        for (int vectorValue : getHandValues()) {

            // if three of a kind
            if (vectorValue == 3) {

                //
                returnValue += (cardDeck::numValuesArray[cardPosition+2] * cardDeck::highCardMultiples[currMulti]);
                currMulti++;
                currVector.at(cardPosition) = 0;

            }
            cardPosition++;
        }

        // for the rest of the cards values
        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[currMulti] * currHighCard;

            //increment high card counter multiplier
            currMulti++;

            /*
                        if (currHighCard == 14) {
                            currHighCard = 1;
                        }
                        */

                        //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }


    } // Two pair
    else if (isTwoPair(getHandValues())) {

        //base value
        returnValue = 300'000;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // card position in vector
        int cardPosition = 0;

        // current multiply value for hand Value for after pairs
        int currMulti = 2;

        // current high card
        int currHighCard = 0;

        // loop for all the card values
        for (int currIndex : getHandValues()) {

            // if the current vector index is a pair
            if (currIndex == 2) {

                // if the first pair is found multiply by first multi value because the pair is higher
                if (returnValue > 300'000) {
                    returnValue += (currIndex + 2) * cardDeck::highCardMultiples[0];
                }
                else { // else the pair is the smaller pair in the hand thus multiply by the second multi value
                    returnValue += (currIndex + 2) * cardDeck::highCardMultiples[1];
                }

                // set the pairs vectors location to 0;
                currVector.at(cardPosition) = 0;

            }

            // increment the card position
            cardPosition++;

        }

        // for the rest of the cards values
        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[currMulti] * currHighCard;

            //increment high card counter multiplier
            currMulti++;

            /*
                        if (currHighCard == 14) {
                            currHighCard = 1;
                        }
                        */

                        //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }


    }// Pair
    else if (isPair(getHandValues())) {
        // base value for pair
        returnValue = 200'000;

        // current multiply value for hand Value
        int currMulti = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // number of times looped
        int cardPosition = 0;

        // current high card for the values of the rest of the cards
        int currHighCard = 0;

        // loop through the vector
        for (int currIndex : getHandValues()) {

            // for the pair multiple the multi coefficent by the current cards value
            if (currIndex == 2) {
                returnValue += (cardPosition + 2) * cardDeck::highCardMultiples[currMulti];
                currVector.at(cardPosition) = 0;
                currMulti++;
                break;
            }
            // increment the card position
            cardPosition++;
        }

        // for the rest of the cards values
        // for the size of the hand
        for (Card handItt : Hand::hand) {

            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[currMulti] * currHighCard;

            //increment high card counter multiplier
            currMulti++;

            /*
                        if (currHighCard == 14) {
                            currHighCard = 1;
                        }
                        */

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;

        }




    } // High Card
    else {

        // base value for High Card
        returnValue = 100'000;

        // current high card value
        int currHighCard = 0;

        // number of cards looped through
        int numHighCard = 0;

        // get current vector to modify as high cards are taken out
        std::vector<int> currVector = getHandValues();

        // for the size of the hand
        for (Card handItt : Hand::hand) {
            
            // get the high card of the current vector
            currHighCard = getHighCard(currVector);

            // for each case
            returnValue += cardDeck::highCardMultiples[numHighCard] * currHighCard;

            //increment high card counter
            numHighCard++;

/*
            if (currHighCard == 14) {
                currHighCard = 1;
            }
            */

            //set the high cards value in the vector to zero
            currVector.at(currHighCard - 2) = 0;



            
        }

    }
    return returnValue;
}