#include "include/chain.hpp"
#include "include/block.hpp"
#include "include/transaction.hpp"
#include "include/transactionService.hpp"
#include "include/wallet.hpp"
#include "include/transactionController.hpp"


#include <iostream>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int main() {
    cout << "Starting Server" << endl;

    TransactionController server;
    server.setEndpoint("http://0.0.0.0:4200/api");
    server.initHandlers();

    try {
        server.openServer().wait();
        cout << "Server listening at: " << server.getEndpoint() << endl;

        // figure out how to keep server running without this?
        while (true);
    }
    catch(exception &e) {
        cout << "--- ERROR DETECTED ---" << endl;
        cout << e.what() << endl;
    }

    
    // this doesn't get reached bc of the while(true)
    server.closeServer().wait();

    return 0;
}
