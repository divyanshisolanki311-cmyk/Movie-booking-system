#include <string>
#include <vector>
using namespace std;

// Composition: Cinema owns its Screen objects.
class Cinema {
private:
    string name;
    vector<Screen> screens;

public:
    Cinema(string name) : name(name) {}
    void addScreen(const Screen& screen) { screens.push_back(screen); }

    const string& getName() const { return name; }
    const vector<Screen>& getScreens() const { return screens; }
};
