class CardPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Card payment of Rs." << amount << " successful.\n";
        return true;
    }
};
