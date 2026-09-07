#include <vector>
using namespace std;

// Composition: Screen owns its Seat objects.
class Screen {
private:
    int screenNumber;
    vector<Seat> seats;

public:
    Screen(int screenNumber) : screenNumber(screenNumber) {
        // 10 seats: 1-4 Silver, 5-7 Gold, 8-10 Platinum
        for (int i = 1; i <= 10; ++i) {
            Seat::Type type = (i <= 4) ? Seat::SILVER :
                               (i <= 7) ? Seat::GOLD : Seat::PLATINUM;
            seats.emplace_back(i, type);
        }
    }

    int getScreenNumber() const { return screenNumber; }
    const vector<Seat>& getSeats() const { return seats; }
};
