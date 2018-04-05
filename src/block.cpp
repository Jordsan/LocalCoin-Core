#include "../include/block.hpp"
#include "../lib/hash.hpp"

Block::Block() {
    
}

Block::Block(int index, std::string timestamp, std::string data) {
    this->index = index;
    this->timestamp = timestamp;
    this->data = data;
    this->prevHash = "";
    this->hash = this->calculateHash(timestamp, data, this->prevHash);
    
}

std::string Block::getHash() {
    return this->hash;
}

void Block::setHash(std::string h){
    this->hash = h;
}

std::string Block::getPrevHash() {
    return this->prevHash;
}

void Block::setPrevHash(std::string h){
    this->prevHash = h;
}

std::string Block::getTimestamp() {
    return this->timestamp;
}

std::string Block::getData() {
    return this->data;
}

std::string Block::calculateHash(std::string ts, std::string d, std::string ph) {
    return SHA256(ts + d + ph);
}
