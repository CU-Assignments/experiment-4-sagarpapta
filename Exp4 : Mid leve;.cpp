/**
Create a program to collect and store all the cards to assist the users in finding all the cards in a given symbol using Collection interface.
*/

import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;

class Card {
    private String symbol;
    private String value;

    public Card(String symbol, String value) {
        this.symbol = symbol;
        this.value = value;
    }

    public String getSymbol() {
        return symbol;
    }

    public String getValue() {
        return value;
    }

    @Override
    public String toString() {
        return value + " of " + symbol;
    }
}

public class CardCollection {
    private Collection<Card> cards;

    public CardCollection() {
        cards = new ArrayList<>();
    }

    public void addCard(Card card) {
        cards.add(card);
    }

    public Collection<Card> findCardsBySymbol(String symbol) {
        Collection<Card> result = new ArrayList<>();
        for (Card card : cards) {
            if (card.getSymbol().equalsIgnoreCase(symbol)) {
                result.add(card);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        CardCollection cardCollection = new CardCollection();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the number of cards to add:");
        int numberOfCards = scanner.nextInt();
        scanner.nextLine();  // Consume newline

        for (int i = 0; i < numberOfCards; i++) {
            System.out.println("Enter card " + (i + 1) + " symbol:");
            String symbol = scanner.nextLine();
            System.out.println("Enter card " + (i + 1) + " value:");
            String value = scanner.nextLine();
            cardCollection.addCard(new Card(symbol, value));
        }

        System.out.println("Enter the symbol to search for:");
        String searchSymbol = scanner.nextLine();

        Collection<Card> foundCards = cardCollection.findCardsBySymbol(searchSymbol);

        if (foundCards.isEmpty()) {
            System.out.println("No cards found with the symbol: " + searchSymbol);
        } else {
            System.out.println("Cards with the symbol " + searchSymbol + ":");
            for (Card card : foundCards) {
                System.out.println(card);
            }
        }

        scanner.close();
    }
}
