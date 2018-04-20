#include "include/chain.hpp"
#include "include/block.hpp"
#include "include/transaction.hpp"
#include "include/transactionService.hpp"
#include "include/wallet.hpp"
#include "include/transactionController.hpp"
#include "include/interruptHandler.hpp"


#include <iostream>

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

int main() {
    cout << "Starting Server" << endl;

    InterruptHandler::hookSIGINT();

    TransactionController server;
    server.setEndpoint("http://0.0.0.0:4200/api");
    server.initHandlers();

    try {
        server.openServer().wait();
        cout << "Server listening at: " << server.getEndpoint() << endl;

        InterruptHandler::waitForUserInterrupt();

        server.closeServer().wait();
        cout << endl << "Shutting Down Server" << endl;
    }
    catch(exception &e) {
        cout << "--- ERROR DETECTED ---" << endl;
        cout << e.what() << endl;
    }    

    return 0;
}
