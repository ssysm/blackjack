#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "dict.h"
#include "Card.h"
#include "util.h"

using namespace std;


int main() {
    srand(time(nullptr));

    vector<Card> deck;

    vector<Card> playerHand;
    vector<Card> dealerHand;

    bool playagain = true;
    char again;
    char decision;

    //init all vector
    initialize(deck,playerHand,dealerHand);

    while (playagain) {
        //Prepare the game
        prepareTable(playerHand, dealerHand, deck);
        do {
            //Give dealer a card
            dealerHand.push_back(dealfrom(deck));
            //Print out pre game info
            cout << "You have" << endl;
            printCard(playerHand);
            cout << "Dealer Have" << endl;
            printPreDealerCard(dealerHand);

            //If the player hand is not over 21
            if (getCardSum(playerHand) < 21) {
                cout << "Do you want to Stand of Hit? [s/h]";
                cin >> decision;
                if (decision == 'h') {
                    playerHand.push_back(dealfrom(deck));
                }
                //if s, pass
            }

            //Display Result
            cout << "You have" << endl;
            printCard(playerHand);
            cout << "Dealer have" << endl;
            printCard(dealerHand);

        } while (getCardSum(playerHand) < 21 && getCardSum(dealerHand) < 21);//If both of their hand don't get over 21

        //Print out game result
        cout << compareResult(getCardSum(playerHand), getCardSum(dealerHand));

        //Do they want to go again
        cout << "Do you want to play another hand? (y/n)";
        cin >> again;
        if (again != 'y') {
            playagain = false;//quit
        } else if (again == 'y') {
            //Re-Init all deck
            initialize(deck,playerHand,dealerHand);
        }
    }

}