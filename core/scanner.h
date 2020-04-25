#ifndef Scanner_h
#define Scanner_h

#include <string>
namespace PRSR {
namespace core {
class scanner {
public:
    scanner();
    ~scanner();
    void setInput(std::string str);
    void setInput(std::istream& infile);
    std::string nextToken();
    std::string getBuffer();
    void saveToken(std::string token);
    bool hasMoreTokens();
    int getCurrentIndex();
    enum spaceOption { PreserveSpaces, IgnoreSpaces };

private:
    int scanToEndOfIdentifier();
    void skipSpaces();
    std::string m_buffer;  // contains the tokens
    int m_cp;              // current index in the buffer
    spaceOption m_spaceOption;
};
}  // namespace core
}  // namespace PRSR
#endif
