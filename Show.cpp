#include <string>
#include <vector>
using namespace std;

// Aggregation: Show uses an existing Movie and Screen.
// Composition: Show creates and owns its ShowSeat objects.
class Show {
private:
    const Movie* movie;
    const Screen* screen;
    string startTime;
    vector<ShowSeat> showSeats;

public:
    Show(const Movie* movie, const Screen* screen, string startTime)
        : movie(movie), screen(screen), startTime(startTime) {
        for (const Seat& seat : screen->getSeats())
            showSeats.emplace_back(&seat);
    }

    const Movie* getMovie() const { return movie; }
    const Screen* getScreen() const { return screen; }
    const string& getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }

    ShowSeat* findSeat(int number) {
        for (auto& ss : showSeats)
            if (ss.getSeatNumber() == number) return &ss;
        return nullptr;
    }

    void displaySeats() const {
        cout << "\n--- Seat Layout ---\n";
        for (const auto& ss : showSeats) {
            cout << "Seat " << ss.getSeatNumber()
                 << " [" << ss.getSeat()->getTypeName() << "] : "
                 << (ss.isAvailable() ? "AVAILABLE" : "BOOKED") << "\n";
        }
    }
};
