#include <vector>
using namespace std;

class PriceCalculator {
public:
    double calculate(const vector<ShowSeat*>& seats) const {
        double total = 0;
        for (const auto* ss : seats)
            total += ss->getSeat()->getPrice();
        return total;
    }

    // Compile-time polymorphism: overloaded method.
    double calculate(const ShowSeat& seat) const {
        return seat.getSeat()->getPrice();
    }
};
