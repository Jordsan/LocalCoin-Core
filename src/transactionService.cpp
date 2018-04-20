#include "../include/transactionService.hpp"

#include <iostream>

TransactionService::TransactionService() {
    map<string, Wallet> mockDB;

    Wallet w1("test1", 100);
    Wallet w2("test2", 100);

    mockDB[w1.getPublicKey()] = w1;
    mockDB[w2.getPublicKey()] = w2;


    walletService.setData(mockDB);
}

bool TransactionService::validateTransaction(Transaction t, Chain &c) {
    // add in validation
    Wallet to = walletService.findWallet(t.getTo());
    Wallet from = walletService.findWallet(t.getFrom());

    if (from.getBalance() > t.getAmount()) { 
        return true;
    } 
    return false;
}

void TransactionService::sendTransaction(Transaction t, Chain &c) {
    Wallet to = walletService.findWallet(t.getTo());
    Wallet from = walletService.findWallet(t.getFrom());

    from.send(t.getAmount());
    to.receive(t.getAmount());

    Block b(0, "now", from.getPublicKey() + ":" + to.getPublicKey() + ":" + std::to_string(t.getAmount()));
    c.addBlock(b);
}