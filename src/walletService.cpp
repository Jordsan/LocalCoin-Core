#include "../include/walletService.hpp"

WalletService::WalletService() {
}

void WalletService::setData(map<string, Wallet> db) {
    mockDB = db;
}

Wallet WalletService::findWallet(string s) {
    return mockDB.at(s);
}