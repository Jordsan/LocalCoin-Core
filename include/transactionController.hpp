#ifndef TRANSACTION_CONTROLLER_H_
#define TRANSACTION_CONTROLLER_H_

#include <string>
#include <cpprest/http_listener.h>
#include <pplx/pplxtasks.h>
#include <cpprest/http_msg.h>

#include "networkUtils.hpp"

using namespace web;
using namespace http;
using namespace http::experimental::listener;
using namespace std;
using namespace pplx;

class TransactionController {
    protected:
        http_listener listener;
    public:
        TransactionController() {};
        ~TransactionController() {};
        void handleGet(http_request request);
        void handlePut(http_request request);
        void handlePost(http_request request);
        void handlePatch(http_request request);
        void handleDelete(http_request request);
        void initRestOpHandlers();

        void setEndpoint(const std::string & value);
        string endpoint() const;
        task<void> accept();
        task<void> shutdown();

        vector<utility::string_t> requestPath(const http_request & request);
};

#endif
