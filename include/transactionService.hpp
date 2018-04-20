#ifndef TRANSACTIONSERVICE_H_ 
#define TRANSACTIONSERVICE_H_

#include "transaction.hpp"
#include "wallet.hpp"
#include "block.hpp"
#include "chain.hpp"

#include "../include/walletService.hpp"
#include "../include/chainService.hpp"


class TransactionService {
    private:
        WalletService walletService;
        ChainService chainService;
    public:
        TransactionService();
        
        bool validateTransaction(Transaction t, Chain &c);
        void sendTransaction(Transaction t, Chain &c);

};

#endif