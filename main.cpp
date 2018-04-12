#include "include/chain.hpp"
#include "include/block.hpp"
#include "include/transaction.hpp"
#include "include/transactionService.hpp"
#include "include/wallet.hpp"
#include "include/transactionController.hpp"


#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    cout << "Starting Server" << endl;

    TransactionController server;
    server.setEndpoint("http://host_auto_ip4:4200/api");

}
