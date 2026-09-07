class UpiPayment : public Payment {
public:
    bool pay(double amount) override {
        cout << "UPI payment of Rs." << amount << " successful.\n";
        return true;
    }
};
