//
// Created by omri_hershkovich on 2/11/24.
//
#ifndef EX_2_DECK_H
#define EX_2_DECK_H

/**
 * @class Deck
 * @brief Represents a deck of playing cards.
 */
#include "Card.h"

class Deck {
private:
    int length_package;                 /**< The current length of the deck. */
    Card **package_array_pointer;       /**< Pointer to an array of pointers to Card objects representing the deck. */
public:
    /**
     * @brief Default constructor for the Deck class.
     */
    Deck():package_array_pointer(nullptr),length_package(0){};
    /**
        * @brief Destructor for the Deck class.
    */
    ~Deck();

    int get_length() const;
    /**
   * @brief Getter method for retrieving the length of the deck.
   * @return The current length of the deck.
   */
    Card **get_package_array_pointer();
    /**
        * @brief Getter method for retrieving the pointer to the array of cards.
        * @return Pointer to an array of pointers to Card objects representing the deck.
    */
    bool add_package(Card *other);
    /**
     * @brief Adds a card to the deck.
     * @param other Pointer to the card to be added.
     * @return True if the addition was successful, false otherwise.
     */
    void peak_to_first_n_cards(int how_mach_to_see);

    /**
     * @brief Shows the first n cards of the deck without removing them.
     * @param how_much_to_see The number of cards to be shown.
     */

    Deck &operator-=(int how_mach_to_throw);
    /**
     * @brief Overloaded compound subtraction assignment operator to remove cards from the deck.
     * @param how_much_to_throw The number of cards to be removed.
     * @return Reference to the modified deck.
     */
    Card& operator[](int index);
    /**
     * @brief Overloaded output stream operator to print the deck.
     * @param os Output stream.
     * @param Deck The deck to be printed.
     * @return Reference to the output stream.
     */
    friend ostream &operator<<(ostream &os, const Deck &Deck);
    /**
     * @brief Overloaded compound addition assignment operator to add a single card to the deck.
     * @param cards Pointer to the card to be added.
     * @return Reference to the modified deck.
     */
    Deck& operator+=(Card* cards);
    /**
     * @brief Overloaded compound addition assignment operator to add all cards from another deck to this deck.
     * @param dk The deck whose cards are to be added to this deck.
     * @return Reference to the modified deck.
     */
    Deck& operator+=(Deck &dk);
    /**
     * @brief Frees the memory occupied by the deck.
     */
    void free();

    Card* pop_top();

    Deck& remove_element(Card& card_to_remove);

    Card * get_top_card();




    };













#endif //EX_2_DECK_H
