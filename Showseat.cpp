// Composition with Show, while referring to an existing Seat.
class ShowSeat {
public:
    enum Status { AVAILABLE, BOOKED };

private:
    const Seat* seat;
    Status status;

public:
    ShowSeat(const Seat* seat) : seat(seat), status(AVAILABLE) {}

    int getSeatNumber() const { return seat->getNumber(); }
    const Seat* getSeat() const { return seat; }

    bool isAvailable() const { return status == AVAILABLE; }
    Status getStatus() const { return status; }

    bool bookSeat() {
        if (!isAvailable()) return false;
        status = BOOKED;
        return true;
    }

    void cancelSeat() { status = AVAILABLE; }
};
