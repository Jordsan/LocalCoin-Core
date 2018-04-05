#ifndef CHAIN_H_ 
#define CHAIN_H_

#include "block.hpp"
#include <list>
#include <iterator> 

class Chain {
    private:
        Block genesisBlock;
        std::list<Block> chain;
    public:
        Chain();
        Chain(Block b);

        Block getLatest();
        void addBlock(Block &b);
        bool validateChain();
};

#endif