/**
Develop a ticket booking system with synchronized threads to ensure no double booking of seats. Use thread priorities to simulate VIP bookings being processed first.
*/

import java.util.*;

class TicketBookingSystem {
    private static final int TOTAL_SEATS = 10;
    private static boolean[] seats = new boolean[TOTAL_SEATS];
    private static final Object lock = new Object();

    public static void bookSeat(int seatNumber, String customerName) {
        synchronized (lock) {
            if (seatNumber < 0 || seatNumber >= TOTAL_SEATS) {
                System.out.println(customerName + " - Invalid seat number!");
                return;
            }
            if (!seats[seatNumber]) {
                seats[seatNumber] = true;
                System.out.println(customerName + " successfully booked seat " + seatNumber);
            } else {
                System.out.println(customerName + " - Seat " + seatNumber + " is already booked!");
            }
        }
    }
}

class BookingThread extends Thread {
    private int seatNumber;
    private String customerName;
    
    public BookingThread(String customerName, int seatNumber, int priority) {
        this.customerName = customerName;
        this.seatNumber = seatNumber;
        setPriority(priority);
    }

    @Override
    public void run() {
        TicketBookingSystem.bookSeat(seatNumber, customerName);
    }
}

public class TicketBookingApp {
    public static void main(String[] args) {
        List<Thread> threads = new ArrayList<>();
        threads.add(new BookingThread("VIP_Alice", 2, Thread.MAX_PRIORITY));
        threads.add(new BookingThread("VIP_Bob", 2, Thread.MAX_PRIORITY));
        threads.add(new BookingThread("Regular_Charlie", 2, Thread.MIN_PRIORITY));
        threads.add(new BookingThread("Regular_David", 3, Thread.NORM_PRIORITY));
        threads.add(new BookingThread("VIP_Eve", 3, Thread.MAX_PRIORITY));
        
        for (Thread t : threads) {
            t.start();
        }
        
        for (Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
