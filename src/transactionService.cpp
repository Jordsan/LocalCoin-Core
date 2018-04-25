#include "../include/transactionService.hpp"

#include <iostream>
using namespace std;

TransactionService::TransactionService() {
    
}

WalletService& TransactionService::getWalletService() {
    return walletService;
}

bool TransactionService::validateTransaction(Transaction t, Chain &c) {
    // TODO: add in validation of chain?

    if (walletService.getDB().count(t.getFrom()) == 0 || walletService.getDB().count(t.getTo()) == 0) {
        return false;
    }

    Wallet to = walletService.getDB().at(t.getTo());
    Wallet from = walletService.getDB().at(t.getFrom());

    if (from.getBalance() >= t.getAmount()) { 
        return true;
    } 
    return false;
}

void TransactionService::sendTransaction(Transaction t, Chain &c) {
    Wallet to = walletService.findWallet(t.getTo());
    Wallet from = walletService.findWallet(t.getFrom());

    walletService.doTransaction(walletService.findWallet(t.getTo()), walletService.findWallet(t.getFrom()), t.getAmount());

    Block b(chainService.getChainObj().getChain().size(), "now", from.getPublicKey() + ":" + to.getPublicKey() + ":" + std::to_string(t.getAmount()));
    c.addBlock(b);
}