#include "../include/wallet.hpp"

Wallet::Wallet() {
    // generate public key here
    balance = 0;
    publicKey = "asdf123";
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