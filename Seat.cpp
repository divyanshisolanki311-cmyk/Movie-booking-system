#include <string>
using namespace std;

// Encapsulation: seat details are private.
class Seat {
public:
    enum Type { SILVER, GOLD, PLATINUM };

private:
    int number;
    Type type;

public:
    Seat(int number, Type type) : number(number), type(type) {}

    int getNumber() const { return number; }
    Type getType() const { return type; }

    double getPrice() const {
        if (type == SILVER) return 150.0;
        if (type == GOLD) return 250.0;
        return 400.0;
    }

    string getTypeName() const {
        if (type == SILVER) return "SILVER";
        if (type == GOLD) return "GOLD";
        return "PLATINUM";
    }
};
