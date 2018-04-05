#ifndef TRANSACTION_H_ 
#define TRANSACTION_H_

#include "wallet.hpp"

class Transaction {
    private:
        Wallet toAddress;
        Wallet fromAddress;
        double amount;

    public:
        Transaction();
        Transaction(Wallet to, Wallet from, double amnt);

        Wallet getTo();
        Wallet getFrom();
        double getAmount();
};

#endif