#ifndef BLOCK_H_ 
#define BLOCK_H_

#include <string>

class Block {
    private:
        int index;
        std::string timestamp;
        std::string data;
        std::string hash;
        std::string prevHash;

    public:
        Block();
        Block(int index, std::string timestamp, std::string data);

        int getIndex();
        std::string getHash();
        void setHash(std::string h);
        std::string getPrevHash();
        void setPrevHash(std::string h);

        std::string getTimestamp();
        std::string getData();

        std::string calculateHash(std::string ts, std::string d, std::string ph);


};

#endif