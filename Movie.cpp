#include <string>
using namespace std;

// Encapsulation: movie data is private and accessed through public methods.
class Movie {
private:
    string title, language;
    int duration;

public:
    Movie(string title, string language, int duration)
        : title(title), language(language), duration(duration) {}

    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDuration() const { return duration; }
};
