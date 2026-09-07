#include <iostream>
#include <vector>
using namespace std;

// Association with Customer; orchestrates Booking, pricing, payment and ticket printing.
class BookingService {
private:
    PriceCalculator calculator;
    TicketPrinter printer;
    vector<Booking*> bookings;

public:
    Booking* createBooking(Show* show, Customer* customer, int seatNumber) {
        ShowSeat* ss = show->findSeat(seatNumber);
        if (ss == nullptr) {
            cout << "Invalid seat number.\n";
            return nullptr;
        }
        if (!ss->isAvailable()) {
            cout << "Seat is already BOOKED. Booking rejected.\n";
            return nullptr;
        }

        ss->bookSeat();
        vector<ShowSeat*> selected{ss};
        double total = calculator.calculate(selected);

        Booking* booking = new Booking(show, customer, selected, total);
        bookings.push_back(booking);
        return booking;
    }

    bool makePayment(Booking* booking, Payment* payment) {
        if (booking == nullptr) return false;

        // Runtime polymorphism: Payment* can point to UPI/Card/Cash.
        bool paid = payment->pay(booking->getTotalAmount());

        if (paid) {
            booking->confirm();
            return true;
        }

        booking->fail();
        for (auto* ss : booking->getSeats()) ss->cancelSeat();
        return false;
    }

    void cancelBooking(Booking* booking) {
        if (booking == nullptr || booking->getStatus() != Booking::CONFIRMED) {
            cout << "Booking cannot be cancelled.\n";
            return;
        }

        for (auto* ss : booking->getSeats()) ss->cancelSeat();
        booking->cancel();
        cout << "Booking cancelled. Seats are AVAILABLE again.\n";
    }

    void printTicket(Booking* booking) {
        if (booking && booking->getStatus() == Booking::CONFIRMED)
            printer.print(*booking);
        else
            cout << "Ticket cannot be printed. Booking is not confirmed.\n";
    }
};
