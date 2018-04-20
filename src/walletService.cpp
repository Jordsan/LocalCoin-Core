#include "../include/walletService.hpp"

WalletService::WalletService() {
}

void WalletService::setData(map<string, Wallet> &db) {
    mockDB = db;
}

Wallet& WalletService::findWallet(string s) {
    return mockDB.at(s);
}

map<string, Wallet>& WalletService::getDB() {
    return mockDB;
}

void WalletService::doTransaction(Wallet &to, Wallet &from, double amnt) {
    to.receive(amnt);
    from.send(amnt);
}