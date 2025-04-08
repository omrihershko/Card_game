//
// Created by omri_hershkovich on 2/10/24.
//
#include <iostream>
using namespace std;
#ifndef EX_2_CARD_H
#define EX_2_CARD_H



class Card {

public:
/**
     * @brief Enum representing the four suits of a standard deck of cards.
     */
    enum Suit { DIAMONDS,HEARTS,SPADES,CLUBS };
    /**
     * @brief Constructor for the Card class.
     * @param r The rank of the card.
     * @param s The suit of the card.
     */
    Card(char r, char s);
    // Setter methods
    void set_suit();

    void setValue();
    // Getter methods
    char get_rank() const;

    char get_sign() const;

    int get_value() const;

    Suit get_Suit() const ;

    // Comparison operators
    bool operator==(const Card &other) const;

    bool operator!=(const Card &other) const;

    bool operator<(const Card &other) const;

    bool operator<=(const Card &other) const;

    bool operator>(const Card &other) const;

    bool operator>=(const Card &other) const;

    // Assignment operator
    Card &operator=(const Card &other);
/**
     * @brief Overloaded output stream operator to print card information.
     * @param os Output stream.
     * @param card The card to be printed.
     * @return Reference to the output stream.
     */
    friend ostream &operator<<(ostream &os, const Card &card);


private:
    char rank;          /**< The rank of the card (e.g., '2', 'K', 'A'). */
    char sign;          /**< The sign of the card (e.g., '♦', '♥', '♠', '♣'). */
    int value;          /**< The numerical value of the card (e.g., 2-10, 11 for Jack, 12 for Queen, 13 for King, 1 for Ace). */
    Suit sign_value;    /**< The suit of the card (diamonds, hearts, spades, clubs). */
};




#endif //EX_2_CARD_H

