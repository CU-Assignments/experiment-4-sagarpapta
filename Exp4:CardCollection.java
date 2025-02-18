/**
Create a program to collect and store all the cards to assist the users in finding all the cards in a given symbol using Collection interface.
*/
import java.util.*;

class Card {
    private String symbol;
    private String name;

    public Card(String symbol, String name) {
        this.symbol = symbol;
        this.name = name;
    }

    public String getSymbol() {
        return symbol;
    }

    @Override
    public String toString() {
        return "Card{Name='" + name + "', Symbol='" + symbol + "'}";
    }
}

public class CardCollection {
    private static Collection<Card> cards = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void addCard() {
        System.out.print("Enter card symbol: ");
        String symbol = scanner.nextLine();
        System.out.print("Enter card name: ");
        String name = scanner.nextLine();
        
        cards.add(new Card(symbol, name));
        System.out.println("Card added successfully!");
    }

    public static void searchBySymbol() {
        System.out.print("Enter symbol to search: ");
        String symbol = scanner.nextLine();
        
        boolean found = false;
        for (Card card : cards) {
            if (card.getSymbol().equalsIgnoreCase(symbol)) {
                System.out.println(card);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No cards found with symbol: " + symbol);
        }
    }

    public static void displayAllCards() {
        if (cards.isEmpty()) {
            System.out.println("No cards available.");
        } else {
            for (Card card : cards) {
                System.out.println(card);
            }
        }
    }

    public static void main(String[] args) {
        while (true) {
            System.out.println("\nCard Collection System");
            System.out.println("1. Add Card");
            System.out.println("2. Search Card by Symbol");
            System.out.println("3. Display All Cards");
            System.out.println("4. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1: addCard(); break;
                case 2: searchBySymbol(); break;
                case 3: displayAllCards(); break;
                case 4: System.out.println("Exiting..."); return;
                default: System.out.println("Invalid choice! Try again.");
            }
        }
    }
}

