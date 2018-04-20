#include "../include/transactionController.hpp"


pplx::task<void> TransactionController::openServer() {
    return listener.open();
}

pplx::task<void> TransactionController::closeServer() {
    return listener.close();
}

std::string TransactionController::getEndpoint() const{
    return listener.uri().to_string();
}


void TransactionController::initHandlers() {
    listener.support(methods::GET, bind(&TransactionController::handleGet, this, std::placeholders::_1));
    listener.support(methods::POST, bind(&TransactionController::handlePost, this, placeholders::_1));
}

void TransactionController::setEndpoint(const string& value) {
    listener = http_listener(value);
}

vector<utility::string_t> TransactionController::requestPath(const http_request &request) {
    return uri::split_path(request.request_uri().path());
}

void TransactionController::handleGet(http_request request) {
    cout << ("received GET request") << endl;

    auto path = requestPath(request);
    if (!path.empty()) {
        if (path[0] == "api" && path[1] == "chain") {
            auto response = json::value::object();
            response["chain"] = json::value::string("insert chain here");
            request.reply(status_codes::OK, response);
        }
        else if (path[0] == "api" && path[1] == "transaction") {
            auto response = json::value::object();
            response["transaction"] = json::value::string("insert transaction with inputted id here");
            request.reply(status_codes::OK, response);
        }
        else {
            request.reply(status_codes::NotFound);
        }   
    }
    else {
        request.reply(status_codes::NotFound);
    }
}

void TransactionController::handlePost(http_request request) {
    cout << ("received POST request") << endl;

    web::json::value json = request.extract_json().get();

    auto path = requestPath(request);
    if (!path.empty()) {
        if (path[0] == "api" && path[1] == "chain") {
            string to;
            string from;
            double amount;
            auto response = json::value::object();

            try {
                to = json.at(U("to")).as_string();
                from = json.at(U("from")).as_string();
                amount = json.at(U("amount")).as_double();
            }
            catch (exception &e) {
                cout << "invalid obj" << endl;
                request.reply(status_codes::UnprocessableEntity);
                return;
            }

            Transaction t(to, from, amount);

            if (transactionService.validateTransaction(t, chainService.getChainObj())) {
                transactionService.sendTransaction(t, chainService.getChainObj());
                response["status"] = json::value::string("transaction created");
                request.reply(status_codes::OK, response);
            }
            else {
                request.reply(status_codes::UnprocessableEntity);
            }
        }
        else {
            request.reply(status_codes::NotFound);
        }   
    }
    else {
        request.reply(status_codes::NotFound);
    }

    request.reply(status_codes::NotFound);
}
