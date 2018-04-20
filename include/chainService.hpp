#ifndef CHAINSERVICE_H_ 
#define CHAINSERVICE_H_

#include "chain.hpp"


using namespace std;

class ChainService {
    private:
        Chain chainObj;
    public:
        ChainService();

        Chain& getChainObj();

};

#endif