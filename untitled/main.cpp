#include "iostream"
#include "sstream"
std::string calculateNmeaChecksum(const std::string& sentence) {

    size_t start = sentence.find('$');
    size_t end = sentence.find('*');
    std::string data = sentence.substr(start + 1, end - start - 1);
    int checksum = 0;
    for (size_t i = 0; i < data.length(); ++i){
        checksum ^= static_cast<int>(data[i]);
    }
    std::stringstream stream;
    stream << std::uppercase << std::hex << checksum;

    return stream.str();
}
int main(){
    std::string nmeaSentence ="$PFEC,GPint,RMC05*";
    std::string checksum = calculateNmeaChecksum(nmeaSentence);
    std::cout << "Checksum: " << checksum << std::endl;
    return 0;
}