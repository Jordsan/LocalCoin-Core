#include "../include/transactionController.hpp"


void display_json(json::value const & json, utility::string_t const & prefix) {
    cout << prefix << json.serialize() << endl;
}

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
    // listener.support(methods::PUT, bind(&TransactionController::handlePut, this, placeholders::_1));
    listener.support(methods::POST, bind(&TransactionController::handlePost, this, placeholders::_1));
    // listener.support(methods::DEL, bind(&TransactionController::handleDelete, this, placeholders::_1));
    // listener.support(methods::PATCH, bind(&TransactionController::handlePatch, this, placeholders::_1));
}

void TransactionController::setEndpoint(const string& value) {
        // uri endpointURI(value);
        // uri_builder endpointBuilder;

        // endpointBuilder.set_scheme(endpointURI.scheme());
        // // if (endpointURI.host() == "host_auto_ip4") {
        // //     endpointBuilder.set_host(NetworkUtils::hostIP4());        
        // // }
        // // else if (endpointURI.host() == "host_auto_ip6") {
        // //     endpointBuilder.set_host(NetworkUtils::hostIP6());
        // // }
        // endpointBuilder.set_port(endpointURI.port());
        // endpointBuilder.set_path(endpointURI.path());

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

    for(auto iter = json.as_object().cbegin(); iter != json.as_object().cend(); ++iter) {
        const utility::string_t &str = iter->first;
        const json::value &v = iter->second;

        std::cout << "\""<< utility::conversions::to_utf8string(str) << "\" : " << v.serialize() << endl;
    }

    auto path = requestPath(request);
    if (!path.empty()) {
        if (path[0] == "api" && path[1] == "chain") {
            auto response = json::value::object();
            response["chain"] = json::value::string("post a transaction here");
            request.reply(status_codes::OK, response);
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
