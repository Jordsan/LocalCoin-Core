#ifndef TRANSACTIONSERVICE_H_ 
#define TRANSACTIONSERVICE_H_

#include "transaction.hpp"
#include "wallet.hpp"
#include "block.hpp"
#include "chain.hpp"

class TransactionService {
    private:
        
    public:
        TransactionService();
        
        Transaction createTransaction(Wallet to, Wallet from, double amnt);
        bool validateTransaction(Transaction t, Chain &c);
        void sendTransaction(Transaction t, Chain &c);
};

#endif