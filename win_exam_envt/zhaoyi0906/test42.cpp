#include <iostream>
#include <vector>

enum class FlashState {
    Normal,
    ReadProtected
};

class Flash {
private:
    std::vector<uint8_t> data;
    uint32_t pageSize;
    FlashState state;

public:
    Flash(uint32_t size, uint32_t pageSize) : data(size, 0xFF), pageSize(pageSize), state(FlashState::Normal) {}

    void erasePage(uint32_t pageAddress) {
        if (isReadProtected()) return;

        uint32_t startIndex = pageAddress * pageSize;
        uint32_t endIndex = startIndex + pageSize;

        if (endIndex > data.size()) {
            endIndex = data.size();
        }

        std::fill(data.begin() + startIndex, data.begin() + endIndex, 0xFF);
    }

    void writeData16(uint32_t address, uint16_t value) {
        if (isReadProtected()) return;
    
        uint8_t lowByte = value & 0xFF;
        uint8_t highByte = (value >> 8) & 0xFF;

        data[address] = highByte;
        data[address + 1] = lowByte;
    }

    void writeData32(uint32_t address, uint32_t value) {
        if (isReadProtected()) return;
    
        uint16_t lowWord = value & 0xFFFF;
        uint16_t highWord = (value >> 16) & 0xFFFF;

        writeData16(address, highWord);
        writeData16(address + 2, lowWord);
    }

    uint8_t readData(uint32_t address) const {
        return data[address];
    }

    void enableReadProtection() {
        if (isReadProtected()) return;
        state = FlashState::ReadProtected;
    }

    void disableReadProtection() {
        if (!isReadProtected()) return;
        state = FlashState::Normal;
    }

    bool isReadProtected() const {
        return state == FlashState::ReadProtected;
    }
};

int main() {
    uint32_t flashSize = 8192; // Flash总大小
    uint32_t pageSize = 1024; // 页大小
    
    Flash flash(flashSize, pageSize);

    flash.writeData(0, 0x55); // 写入数据 0x55

    flash.enableReadProtection(); // 开启读保护

    flash.writeData(1, 0xAA); // 无法写入数据

    flash.disableReadProtection(); // 解除读保护

    flash.writeData(1, 0xAA); // 再次写入数据

    return 0;
}