//
//  Scanner.h
//  Testing2
//
//  Created by AnthonyFPP on 24/05/2019.
//  Copyright © 2019 AnthonyFPP. All rights reserved.
//

#ifndef Scanner_h
#define Scanner_h

#include <string>

class Scanner {
public:
                    Scanner();
                   ~Scanner();
    void            setInput(std::string str);
    void            setInput(std::istream& infile);
    std::string     nextToken();
    std::string     getBuffer();
    void            saveToken(std::string token);
    bool            hasMoreTokens();
    
    enum            spaceOption {PreserveSpaces, IgnoreSpaces};
private:
    int             scanToEndOfIdentifier();
    void            skipSpaces();
    std::string     m_buffer; //contains the tokens
    unsigned long   m_len;    // buffer length
    int             m_cp;     // current index in the buffer
    spaceOption     m_spaceOption;
};

#endif /* Scanner_h */
