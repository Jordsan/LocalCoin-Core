#ifndef WALLETSERVICE_H_ 
#define WALLETSERVICE_H_

#include <string>
#include "wallet.hpp"

#include <map>

using namespace std;

class WalletService {
    private:
        // temporarily using a map to store fake wallets
         map<string, Wallet> mockDB;
    public:
        WalletService();
        
        Wallet findWallet(string s);
        void setData(map<string, Wallet> db);
};

#endif