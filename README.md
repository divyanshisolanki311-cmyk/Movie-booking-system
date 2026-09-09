# Movie Ticket Booking System

A console-based **Movie Ticket Booking System** built in C++ demonstrating core **Object-Oriented Programming (OOP)** concepts and basic **System Design principles** — similar to how PVR or INOX works, but for a single cinema.

---

## How to Run

### Requirements

- Any C++ compiler that supports **C++17**
- g++ recommended

### Step 1 — Go to the project folder

Open PowerShell and navigate to the project folder:

```bash
cd C:\Users\DELL\Downloads\MovieTicket
```

### Step 2 — Compile

Compile the C++ program using:

```bash
g++ main.cpp -o MovieTicketBookingSystem
```

### Step 3 — Run

Run the generated executable:

```bash
.\MovieTicketBookingSystem.exe
```
# Functional & Non-Functional Requirements

## Functional Requirements (FR)

- **FR1:** The system shall display all movies currently playing in the cinema.

- **FR2:** The system shall display the available shows, including screen and start time, for a selected movie.

- **FR3:** The system shall display the seat layout of a selected show, with each seat marked as **AVAILABLE** or **BOOKED**.

- **FR4:** The system shall allow the customer to book one or more available seats and reject any seat that is already booked.

- **FR5:** The system shall calculate the total booking amount according to the seat type:

| Seat Type | Price |
|-----------|-------|
| SILVER | ₹150 |
| GOLD | ₹250 |
| PLATINUM | ₹400 |

- **FR6:** The system shall accept payment through **UPI, Card, or Cash** and shall not confirm the booking if the payment fails.

- **FR7:** The system shall print a ticket containing the booking ID, customer details, movie name, screen, show time, seat numbers, payment method, and total amount.

- **FR8:** The system shall allow a customer to cancel a confirmed booking and make the previously booked seats **AVAILABLE** again.

## Non-Functional Requirements (NFR)

1. **Modularity:** Each class shall have a separate file and a single clear responsibility.

2. **Extensibility:** The system shall allow new payment methods, such as NetBanking, to be added without modifying the existing payment classes or core booking logic.

3. **Input Validation:** The system shall validate menu choices, seat numbers, and booking inputs and display clear error messages without crashing the program.

4. **Maintainability:** Functions shall perform a single clear task, use meaningful names, avoid unnecessary code repetition, and remain reasonably short and easy to understand.

5. **Reliability:** The system shall maintain correct seat availability and shall not mark seats as booked when the corresponding payment fails.

6. **Usability:** The system shall provide a simple menu-driven interface so that customers can easily view movies, select shows, check seats, make bookings, and cancel bookings.

---

# What This Project Does

The system provides a **cinema ticket booking counter** through a simple menu-driven interface. A customer can:

- **List Movies** — View all currently playing movies with their language and duration.
- **List Shows** — Select a movie and view its available shows, including screen and show time.
- **View Seats** — View the seat layout for a selected show, including seat number, seat type, and availability status.
- **Book Seats** — Select one or more available seats, choose a payment method, and receive a printed ticket.
- **Cancel Booking** — Cancel a confirmed booking and make the previously booked seats available again.

---

# Noun-Verb Analysis
| Noun Found | Keep as a Class? | Reason |
|------------|------------------|--------|
| Cinema | Yes | Represents the cinema and maintains references to its screens. |
| Movie | Yes | Has its own data such as title, language, and duration. |
| Screen | Yes | Represents an auditorium and maintains its physical seats. |
| Show | Yes | Represents a particular screening of a movie on a screen at a specific time and maintains show-specific seats. |
| Seat | Yes | Represents the physical seat with a seat number and seat type. |
| ShowSeat | Yes | Represents the availability status of a physical seat for a particular show. |
| Customer | Yes | Represents the customer who makes a booking. |
| Booking | Yes | Represents a customer's confirmed ticket booking. |
| Payment | Yes | Represents the payment made for a booking. |
| Ticket | Yes | Represents the ticket generated after successful booking. |## Noun-Verb Analysis

| Noun Found | Keep as a Class? | Reason |
|---|---|---|
| Cinema | Yes | Represents the cinema and maintains references to its screens. |
| Movie | Yes | Has its own data such as title, language, and duration. |
| Screen | Yes | Represents an auditorium and maintains its physical seats. |
| Show | Yes | Represents a particular screening of a movie on a screen at a specific time. |
| Seat | Yes | Represents one physical seat with a seat number and seat type. |
| ShowSeat | Yes | Represents the availability status of a physical seat for a particular show. |
| Customer | Yes | Represents a customer and stores information such as name and phone number. |
| Booking | Yes | Represents a reservation and stores booking details, selected seats, payment, total amount, and status. |
| Payment | Yes | Abstract class that defines the common payment contract. |
| UPI | Yes | Represents UPI payment implementation. |
| Card | Yes | Represents card payment implementation. |
| Cash | Yes | Represents cash payment implementation. |
| PriceCalculator | Yes | Calculates seat prices and total booking amount. |
| TicketPrinter | Yes | Formats and prints booking tickets. |
| BookingService | Yes | Coordinates booking, seat selection, price calculation, payment and cancellation. |
| MainMenu | Yes | Provides the user interface and handles menu operations. |
| Ticket | No | Ticket generation is handled by TicketPrinter. |
| Seat Layout | No | It is only a display/view of seats, not an independent entity. |
| Booking ID | No | It is a data member of Booking, not a separate entity. |
| Show ID | No | It is an attribute of Show. |
| Price | No | Price is calculated by PriceCalculator. |
| Payment Method | No | Represented through Payment and its subclasses. |
| Status | No | Represented using enums such as SeatStatus and BookingStatus. |

## Class Design

| Class | Attributes / Data Members | Responsibility | Must NOT Do |
|---|---|---|---|
| Movie | title, language, duration | Stores basic movie information | Handle booking, seat management or payment |
| Seat | seatNumber, seatType | Represents one physical seat and its category | Manage show-specific booking status |
| Screen | screenNumber, seats | Represents an auditorium and maintains physical seats | Handle booking, payment or price calculation |
| Cinema | name, screens | Represents the cinema and maintains its screens | Calculate prices, process payments or manage bookings |
| Show | showId, movie, screen, startTime, showSeats | Represents one movie screening and maintains show-specific seats | Process payments or create bookings |
| ShowSeat | seat, status | Maintains availability of a seat for a particular show | Create or delete physical seats |
| Customer | name, phone | Stores customer information | Manage payment or seat availability |
| Booking | bookingId, customer, show, seats, payment, totalAmount, status | Stores booking details and manages booking state | Implement payment methods or print tickets |
| Payment (Abstract) | — | Defines the common interface for payment methods | Implement specific UPI, card or cash logic |
| UpiPayment | upiId | Processes UPI payment | Manage bookings, seats or print tickets |
| CardPayment | cardNumber | Processes card payment | Manage bookings, seats or print tickets |
| CashPayment | — | Processes cash payment | Manage bookings or print tickets |
| PriceCalculator | — | Calculates total booking price based on seat category | Process payment or print tickets |
| TicketPrinter | — | Formats and displays/prints booking tickets | Calculate price or change booking |
| BookingService | — | Coordinates the complete booking workflow | Directly implement low-level payment logic |
| MainMenu | — | Provides the user interface and handles menu operations | Handle low-level booking logic |

## Relationships

| Pair | Relationship | Justification |
|---|---|---|
| Cinema — Screen | Aggregation | Cinema stores references to existing Screen objects. Screens can exist independently. |
| Screen — Seat | Association | Screen maintains references to physical Seat objects. |
| Show — Movie | Association | Show refers to an existing Movie. |
| Show — Screen | Association | Show uses a Screen for a particular screening. |
| Show — ShowSeat | Composition | Show creates and manages ShowSeat objects whose lifetime depends on the Show. |
| ShowSeat — Seat | Association | ShowSeat refers to an existing physical Seat. |
| Booking — Customer | Association | Booking refers to the customer making the reservation. |
| Booking — Show | Association | Booking refers to the selected Show. |
| Booking — Payment | Association | Booking uses a Payment object to process payment. |
| Payment — UpiPayment | Inheritance | UpiPayment implements the Payment interface/abstract class. |
| Payment — CardPayment | Inheritance | CardPayment implements the Payment interface/abstract class. |
| Payment — CashPayment | Inheritance | CashPayment implements the Payment interface/abstract class. |
| BookingService — Booking | Association | BookingService coordinates the booking process. |
| BookingService — PriceCalculator | Association | BookingService uses PriceCalculator to calculate the total price. |
| BookingService — TicketPrinter | Association | BookingService uses TicketPrinter to generate the ticket. |

## Project Structure

```text
MovieTicketBookingSystem/
│
├── docs/
│   ├── Class Diagram.png
│   ├── noun_verb.png
│   ├── Sequence Diagrams.png
│   └── SOLID PRINCIPLES.png
│
├── app.exe
├── Booking.cpp
├── BookingService.cpp
├── CardPayment.cpp
├── CashPayment.cpp
├── Cinema.cpp
├── Customer.cpp
├── Implementation.cpp
├── MainMenu.cpp
├── Movie.cpp
├── Payment.cpp
├── PriceCalculator.cpp
├── Screen.cpp
├── Seat.cpp
├── Show.cpp
├── ShowSeat.cpp
├── TicketPrinter.cpp
├── UpiPayment.cpp
├── main.cpp
└── README.md
```
##sqmple booking 
========================================
        MOVIE TICKET BOOKING SYSTEM
========================================

1. List Movies
2. List Shows for a Movie
3. Display Seats for a Show
4. Book Seats
5. Cancel Booking
6. Exit

Enter choice: 4

Enter Show ID: 1

Selected Movie: Avengers: Endgame
Show Time: 10:00 AM

Seat A1 [PLATINUM] - AVAILABLE
Seat A2 [PLATINUM] - AVAILABLE
Seat B1 [GOLD] - AVAILABLE
Seat B2 [GOLD] - AVAILABLE
Seat C1 [SILVER] - AVAILABLE
Seat C2 [SILVER] - AVAILABLE

Enter number of seats to book: 1
Enter seat number 1: A1

Enter customer name: Divyanshi 
Enter phone number: 9812345600

========================================
             PAYMENT METHOD
========================================

1. UPI
2. Card
3. Cash

Enter choice: 1
Enter UPI ID: Divyanshi@upi

Sending Rs. 400 via UPI
UPI payment successful.

========================================
                 TICKET
========================================

Booking ID : 1001
Customer   : Divyanshi 
Phone      : 9812345600
Movie      : Avengers: Endgame
Screen     : 1
Show Time  : 10:00 AM
Seats      : A1
Paid via   : UPI
Total      : Rs.400.00
Status     : CONFIRMED

========================================
