class TicketPrinter {
public:
    void print(const Booking& booking) const {
        cout << "\n=============== TICKET ===============\n";
        cout << "Booking ID : " << booking.getBookingId() << "\n";
        cout << "Customer   : " << booking.getCustomer()->getName() << "\n";
        cout << "Movie      : " << booking.getShow()->getMovie()->getTitle() << "\n";
        cout << "Screen     : " << booking.getShow()->getScreen()->getScreenNumber() << "\n";
        cout << "Time       : " << booking.getShow()->getStartTime() << "\n";
        cout << "Seats      : ";
        for (const auto* ss : booking.getSeats())
            cout << ss->getSeatNumber() << " ";
        cout << "\nTotal      : Rs." << booking.getTotalAmount() << "\n";
        cout << "Status     : CONFIRMED\n";
        cout << "======================================\n";
    }
};
