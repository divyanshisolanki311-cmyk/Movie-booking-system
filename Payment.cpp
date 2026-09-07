// Abstraction: Payment defines a common contract.
class Payment {
public:
    virtual bool pay(double amount) = 0;
    virtual ~Payment() = default;
};
