#include <vector>
#include <string>
using namespace std;

// Encapsulation: booking amount/status are private.
class Booking {
public:
    enum Status { PENDING, CONFIRMED, CANCELLED, FAILED };

private:
    static int nextBookingId;
    int bookingId;
    Show* show;
    Customer* customer;
    vector<ShowSeat*> seats;
    double totalAmount;
    Status status;

public:
    Booking(Show* show, Customer* customer, const vector<ShowSeat*>& seats,
            double totalAmount)
        : bookingId(nextBookingId++), show(show), customer(customer),
          seats(seats), totalAmount(totalAmount), status(PENDING) {}

    int getBookingId() const { return bookingId; }
    Show* getShow() const { return show; }
    Customer* getCustomer() const { return customer; }
    const vector<ShowSeat*>& getSeats() const { return seats; }
    double getTotalAmount() const { return totalAmount; }
    Status getStatus() const { return status; }

    void confirm() { status = CONFIRMED; }
    void fail() { status = FAILED; }
    void cancel() { status = CANCELLED; }
};

int Booking::nextBookingId = 1001; // Static member for unique booking IDs.

