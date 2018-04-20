#ifndef WALLET_H_
#define WALLET_H_

#include <string>

class Wallet {
    private:
        std::string publicKey;
        double balance;
    public:
        Wallet();
        Wallet(std::string s, double amnt);

        std::string getPublicKey();

        double getBalance();

        void send(double amount);
        void receive(double amount);
};

#endif