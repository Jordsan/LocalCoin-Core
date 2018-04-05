#include "../include/transactionService.hpp"

TransactionService::TransactionService() {
    
}

Transaction TransactionService::createTransaction(Wallet to, Wallet from, double amnt) {
    return Transaction(to, from, amnt);
}

bool TransactionService::validateTransaction(Transaction t, Chain &c) {
    // add in validation

    if (t.getAmount() > t.getFrom().getBalance()){
        return true;
    } 
    return false;
}

void TransactionService::sendTransaction(Transaction t, Chain &c) {
    if (validateTransaction(t, c)) {
        t.getFrom().send(t.getAmount());
        t.getTo().receive(t.getAmount());

        Block b(0, "now", t.getFrom().getPublicKey() + ":" + t.getTo().getPublicKey() + ":" + std::to_string(t.getAmount()));
        c.addBlock(b);
    }
}