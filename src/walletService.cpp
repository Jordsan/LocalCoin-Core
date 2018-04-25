#include "../include/walletService.hpp"

#include <iostream>
using namespace std;

WalletService::WalletService() {
    map<string, Wallet> mockDB;

    Wallet w1("test1", 100);
    Wallet w2("test2", 100);

    // mockDB[w1.getPublicKey()] = w1;
    // mockDB[w2.getPublicKey()] = w2;

    mockDB.insert(pair<string, Wallet>(w1.getPublicKey(), w1));
    mockDB.insert(pair<string, Wallet>(w2.getPublicKey(), w2));

    setData(mockDB);
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