#ifndef TRANSACTION_CONTROLLER_H_
#define TRANSACTION_CONTROLLER_H_

#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

#include "../include/transactionService.hpp"
#include "../include/chainService.hpp"

//#include "networkUtils.hpp"

using namespace web;
using namespace http;
using namespace http::experimental::listener;
using namespace std;
using namespace pplx;

class TransactionController {
    private:
        TransactionService transactionService;
        ChainService chainService;
    protected:
        http_listener listener;
    public:
        TransactionController();
        ~TransactionController() {};
        void handleGet(http_request request);
        void handlePut(http_request request);
        void handlePost(http_request request);
        void handlePatch(http_request request);
        void handleDelete(http_request request);

        void initHandlers();

        void setEndpoint(const std::string & value);
        std::string getEndpoint() const;

        pplx::task<void> openServer();
        pplx::task<void> closeServer();

        vector<utility::string_t> requestPath(const http_request & request);
};

#endif
