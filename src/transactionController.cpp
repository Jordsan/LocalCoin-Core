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
    auto relativePath = uri::decode(request.relative_uri().path());
    return uri::split_path(relativePath);
}

void TransactionController::handleGet(http_request request) {
    // auto path = requestPath(request);
    // if (!path.empty()) {
    //     if (path[0] == "service" && path[1] == "test") {
    //         auto response = json::value::object();
    //         response["version"] = json::value::string("0.1.1");
    //         response["status"] = json::value::string("ready !");
    //         request.reply(status_codes::OK, response);
    //     }
    // }
    // request.reply(status_codes::NotFound);
    
    cout << ("received GET request") << endl;

    auto response = json::value::object();
    response["test"] = json::value::string("test response!");

    request.reply(status_codes::OK, response);

}

void TransactionController::handlePost(http_request request) {
    cout << ("received POST request") << endl;
}
