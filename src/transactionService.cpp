#include "../include/transactionService.hpp"

TransactionService::TransactionService() {
    map<string, Wallet> mockDB;

    Wallet w1("test1", 100);
    Wallet w2("test2", 100);

    mockDB[w1.getPublicKey()] = w1;
    mockDB[w2.getPublicKey()] = w2;


    walletService.setData(mockDB);
}

bool TransactionService::validateTransaction(Transaction t, Chain &c) {
    // TODO: add in validation of chain?

    if (walletService.getDB().count(t.getFrom()) == 0 || walletService.getDB().count(t.getTo()) == 0) {
        return false;
    }

    Wallet to = walletService.findWallet(t.getTo());
    Wallet from = walletService.findWallet(t.getFrom());

    if (from.getBalance() >= t.getAmount()) { 
        return true;
    } 
    return false;
}

void TransactionService::sendTransaction(Transaction t, Chain &c) {
    Wallet to = walletService.findWallet(t.getTo());
    Wallet from = walletService.findWallet(t.getFrom());

    walletService.doTransaction(walletService.findWallet(t.getTo()), walletService.findWallet(t.getFrom()), t.getAmount());

    // walletService.findWallet(t.getFrom()).send(t.getAmount());
    // walletService.findWallet(t.getTo()).receive(t.getAmount());

    Block b(chainService.getChainObj().getChain().size(), "now", from.getPublicKey() + ":" + to.getPublicKey() + ":" + std::to_string(t.getAmount()));
    c.addBlock(b);
}