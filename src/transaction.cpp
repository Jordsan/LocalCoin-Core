#include "../include/transaction.hpp"


Transaction::Transaction() {
    
}

Transaction::Transaction(std::string to, std::string from, double amnt) {
    toAddress = to;
    fromAddress = from;
    amount = amnt;
}

std::string Transaction::getTo() {
    return toAddress;
}

std::string Transaction::getFrom() {
    return fromAddress;
}

double Transaction::getAmount() {
    return amount;
}