#include "../include/wallet.hpp"

Wallet::Wallet() {
    // generate public key here
    balance = 0;
    publicKey = "asdf123";
}

Wallet::Wallet(std::string s, double amnt) {
    publicKey = s;
    balance = amnt;
}

std::string Wallet::getPublicKey() {
    return publicKey;
}

double Wallet::getBalance() {
    return balance;
}

void Wallet::send(double amount) {
    balance -= amount;
}

void Wallet::receive(double amount) {
    balance += amount;
}