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
g++ main.cpp -o MovieTicketBookingSystem
.\MovieTicketBookingSystem.exe

Functional & Non-Functional Requirements
Functional Requirements (FR)
FR1: The system shall display all movies currently playing in the cinema.

FR2: The system shall display the available shows, including screen and start time, for a selected movie.

FR3: The system shall display the seat layout of a selected show, with each seat marked as AVAILABLE or BOOKED.

FR4: The system shall allow the customer to book one or more available seats and reject any seat that is already booked.

FR5: The system shall calculate the total booking amount according to the seat type:

Seat Type	Price
SILVER	₹150
GOLD	₹250
PLATINUM	₹400
FR6: The system shall accept payment through UPI, Card, or Cash and shall not confirm the booking if the payment fails.

FR7: The system shall print a ticket containing the booking ID, customer details, movie name, screen, show time, seat numbers, payment method, and total amount.

FR8: The system shall allow a customer to cancel a confirmed booking and make the previously booked seats AVAILABLE again.

Non-Functional Requirements (NFR)
Modularity: Each class shall have a separate file and a single clear responsibility.

Extensibility: The system shall allow new payment methods, such as NetBanking, to be added without modifying the existing payment classes or core booking logic.

Input Validation: The system shall validate menu choices, seat numbers, and booking inputs and display clear error messages without crashing the program.

Maintainability: Functions shall perform a single clear task, use meaningful names, avoid unnecessary code repetition, and remain reasonably short and easy to understand.

Reliability: The system shall maintain correct seat availability and shall not mark seats as booked when the corresponding payment fails.

Usability: The system shall provide a simple menu-driven interface so that customers can easily view movies, select shows, check seats, make bookings, and cancel bookings.

What This Project Does
The system provides a cinema ticket booking counter through a simple menu-driven interface. A customer can:

List Movies — View all currently playing movies with their language and duration.
List Shows — Select a movie and view its available shows, including screen and show time.
View Seats — View the seat layout for a selected show, including seat number, seat type, and availability status.
Book Seats — Select one or more available seats, choose a payment method, and receive a printed ticket.
Cancel Booking — Cancel a confirmed booking and make the previously booked seats available again.
