#include "../include/chain.hpp"

Chain::Chain() {
    Block b(0, "beginning of time", "genesis Block");

    genesisBlock = b;
    chain = std::list<Block>();
    chain.push_front(genesisBlock);
}


Block Chain::getLatest() {
    return chain.back();
}

std::list<Block> Chain::getChain() {
    return chain;
}

void Chain::addBlock(Block &b) {
    b.setPrevHash(getLatest().getHash());
    b.setHash(b.calculateHash(b.getTimestamp(), b.getData(), b.getPrevHash()));
    chain.push_back(b);
}

bool Chain::validateChain() {
    for(std::list<Block>::iterator itr = chain.begin(); itr!=chain.end(); ++itr){
        if(itr->getHash() != itr->calculateHash(itr->getTimestamp(), itr->getData(), itr->getPrevHash())){
            return false;
        }
        if(itr->getHash() != std::prev(itr)->getPrevHash()){
            return false;
        }
    }
    return true;
}