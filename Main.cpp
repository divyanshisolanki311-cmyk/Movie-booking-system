#include <iostream>
#include <string>
#include <vector>
using namespace std;

// No header files are used, as required by the assignment.
// Each class is kept in its own .cpp file and included here.
#include "Movie.cpp"
#include "Seat.cpp"
#include "Screen.cpp"
#include "Cinema.cpp"
#include "ShowSeat.cpp"
#include "Show.cpp"
#include "Customer.cpp"
#include "Booking.cpp"
#include "Payment.cpp"
#include "UpiPayment.cpp"
#include "CardPayment.cpp"
#include "CashPayment.cpp"
#include "PriceCalculator.cpp"
#include "TicketPrinter.cpp"
#include "BookingService.cpp"

int main() {
    Cinema cinema("PVR Cinema");

    Screen screen1(1);
    Screen screen2(2);
    cinema.addScreen(screen1);
    cinema.addScreen(screen2);

    Movie movie1("Avengers: Endgame", "English", 181);
    Movie movie2("3 Idiots", "Hindi", 170);

    Show show1(&movie1, &cinema.getScreens()[0], "11:00 AM");
    Show show2(&movie1, &cinema.getScreens()[0], "03:00 PM");
    Show show3(&movie2, &cinema.getScreens()[1], "07:00 PM");

    Customer customer("Rahul", "9876543210");
    BookingService service;

    Booking* lastBooking = nullptr;

    while (true) {
        cout << "\n===== MOVIE TICKET BOOKING =====\n";
        cout << "1. List Movies\n";
        cout << "2. List Shows\n";
        cout << "3. Display Seat Layout\n";
        cout << "4. Book Seat\n";
        cout << "5. Make Payment\n";
        cout << "6. Print Ticket\n";
        cout << "7. Cancel Booking\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            cout << "\n--- Movies Currently Playing ---\n";
            cout << "1. " << movie1.getTitle() << " | " << movie1.getLanguage()
                 << " | " << movie1.getDuration() << " min\n";
            cout << "2. " << movie2.getTitle() << " | " << movie2.getLanguage()
                 << " | " << movie2.getDuration() << " min\n";
        }
        else if (choice == 2) {
            cout << "\n--- Shows ---\n";
            cout << "1. " << movie1.getTitle() << " | Screen 1 | 11:00 AM\n";
            cout << "2. " << movie1.getTitle() << " | Screen 1 | 03:00 PM\n";
            cout << "3. " << movie2.getTitle() << " | Screen 2 | 07:00 PM\n";
        }
        else if (choice == 3) {
            cout << "Select show (1-3): ";
            int s; cin >> s;
            if (s == 1) show1.displaySeats();
            else if (s == 2) show2.displaySeats();
            else if (s == 3) show3.displaySeats();
            else cout << "Invalid show choice.\n";
        }
        else if (choice == 4) {
            cout << "Select show (1-3): ";
            int s; cin >> s;
            Show* selectedShow = nullptr;

            if (s == 1) selectedShow = &show1;
            else if (s == 2) selectedShow = &show2;
            else if (s == 3) selectedShow = &show3;
            else {
                cout << "Invalid show choice.\n";
                continue;
            }

            selectedShow->displaySeats();
            cout << "Enter seat number: ";
            int seat; cin >> seat;

            lastBooking = service.createBooking(selectedShow, &customer, seat);
            if (lastBooking)
                cout << "Seat reserved temporarily. Please make payment.\n";
        }
        else if (choice == 5) {
            if (!lastBooking) {
                cout << "No booking available for payment.\n";
                continue;
            }

            cout << "1. UPI\n2. Card\n3. Cash\nEnter payment method: ";
            int p; cin >> p;
            Payment* payment = nullptr;

            if (p == 1) payment = new UpiPayment();
            else if (p == 2) payment = new CardPayment();
            else if (p == 3) payment = new CashPayment();
            else {
                cout << "Invalid payment choice.\n";
                continue;
            }

            service.makePayment(lastBooking, payment);
            delete payment;
        }
        else if (choice == 6) {
            service.printTicket(lastBooking);
        }
        else if (choice == 7) {
            service.cancelBooking(lastBooking);
        }
        else if (choice == 8) {
            cout << "Thank you!\n";
            break;
        }
        else {
            cout << "Invalid menu choice.\n";
        }
    }

    return
