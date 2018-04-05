#ifndef WALLET_H_
#define WALLET_H_

#include <string>

class Wallet {
    private:
        std::string publicKey;
        double balance;
    public:
        Wallet();

        std::string getPublicKey();

        double getBalance();
        void send(double amount);
        void receive(double amount);
};

#endif