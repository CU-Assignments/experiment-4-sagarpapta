/**
Develop a ticket booking system with synchronized threads to ensure no double booking of seats. Use thread priorities to simulate VIP bookings being processed first.
*/


class TicketBookingSystem {
    private int availableSeats = 10;

    public synchronized boolean bookSeat(String user) {
        if (availableSeats > 0) {
            System.out.println(user + " booked a seat. Seats left: " + (--availableSeats));
            return true;
        } else {
            System.out.println(user + " could not book a seat. No seats left.");
            return false;
        }
    }
}

class BookingThread extends Thread {
    private TicketBookingSystem bookingSystem;
    private String user;

    public BookingThread(TicketBookingSystem bookingSystem, String user, int priority) {
        this.bookingSystem = bookingSystem;
        this.user = user;
        setPriority(priority);
    }

    @Override
    public void run() {
        bookingSystem.bookSeat(user);
    }
}

public class Main {
    public static void main(String[] args) {
        TicketBookingSystem bookingSystem = new TicketBookingSystem();

        // Creating VIP booking threads with higher priority
        BookingThread vip1 = new BookingThread(bookingSystem, "VIP1", Thread.MAX_PRIORITY);
        BookingThread vip2 = new BookingThread(bookingSystem, "VIP2", Thread.MAX_PRIORITY);

        // Creating regular booking threads with normal priority
        BookingThread user1 = new BookingThread(bookingSystem, "User1", Thread.NORM_PRIORITY);
        BookingThread user2 = new BookingThread(bookingSystem, "User2", Thread.NORM_PRIORITY);
        BookingThread user3 = new BookingThread(bookingSystem, "User3", Thread.NORM_PRIORITY);

        // Starting the threads
        vip1.start();
        vip2.start();
        user1.start();
        user2.start();
        user3.start();

        // Waiting for all threads to finish
        try {
            vip1.join();
            vip2.join();
            user1.join();
            user2.join();
            user3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Booking process completed.");
    }
}
