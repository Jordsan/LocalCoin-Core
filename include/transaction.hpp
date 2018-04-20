#ifndef TRANSACTION_H_ 
#define TRANSACTION_H_

#include <string>

class Transaction {
    private:
        std::string toAddress;
        std::string fromAddress;
        double amount;

    public:
        Transaction();
        Transaction(std::string to, std::string from, double amnt);

        std::string getTo();
        std::string getFrom();
        double getAmount();
};

#endif