class CashPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "Cash payment of Rs." << amount << " successful.\n";
        return true;
    }
};
