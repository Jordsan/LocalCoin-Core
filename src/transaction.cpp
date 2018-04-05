#include "../include/transaction.hpp"

Transaction::Transaction() {
    
}

Transaction::Transaction(Wallet to, Wallet from, double amnt) {
    toAddress = to;
    fromAddress = from;
    amount = amnt;
}

Wallet Transaction::getTo() {
    return toAddress;
}

Wallet Transaction::getFrom() {
    return fromAddress;
}

double Transaction::getAmount() {
    return amount;
}