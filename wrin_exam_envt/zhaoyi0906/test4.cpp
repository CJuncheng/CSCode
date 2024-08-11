#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

class Flash{
private:
    std::vector<uint8_t> data;
    uint32_t startAddress;
    uint32_t pageSize;
    Flash(int flashSize) : startAddress(0x80000000), pageSize(1024), data(flashSize, 0xFF){}
    Flash(const Flash&);
    Flash& operator=(const Flash&);
    ~Flash(){}

public:
    static Flash& getInstance(){
        static Flash instance;
        return instance;
    };

    void erasePage(uint32_t pageAddress){
        uint32_t startIdx = pageAddress * pageSize;
        uint32_t endIdx = startIdx + pageSize;

        if(endIdx > data.size()) endIdx = data.size();
        fill(data.begin()+startIdx, data.begin()+endIdx, 0XFF);

    }

    void writeData(uint32_t address, uint32_t data){
        cout << std::hex << address << endl;
    }

    void readData(uint32_t address){
        cout << hex << address << endl;
    }
};