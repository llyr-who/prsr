#include "core/scanner.h"

#include <cctype>
#include <iostream>

using PRSR::core::scanner

scanner::scanner()
    : m_buffer(""), m_spaceOption(IgnoreSpaces), m_cp(-1) {}

scanner::~scanner() {}

void scanner::setInput(std::string str) {
    m_buffer = str;
    m_cp = 0;
}

void scanner::setInput(std::istream& infile) {
    std::getline(infile, m_buffer);
    m_cp = 0;
}

std::string scanner::nextToken() {
    if (m_spaceOption == IgnoreSpaces) skipSpaces();
    int s = m_cp;
    if (s >= m_buffer.length()) return "";
    if (isalnum(m_buffer[m_cp])) {
        int f = scanToEndOfIdentifier();
        return m_buffer.substr(s, f - s + 1);
    }
    m_cp++;
    return m_buffer.substr(s, 1);
}

std::string scanner::getBuffer() { return m_buffer; }

int scanner::getCurrentIndex() { return m_cp; }

void scanner::saveToken(std::string token) {
    m_cp--;
    // m_buffer.insert(0, token); - optimisation
}

bool scanner::hasMoreTokens() { return m_cp == m_buffer.length() - 1; }

int scanner::scanToEndOfIdentifier() {
    while (m_cp < m_buffer.length() && isalnum(m_buffer[m_cp])) {
        m_cp++;
    }
    return m_cp - 1;
}

void scanner::skipSpaces() {
    while (m_cp < m_buffer.length() && isspace(m_buffer[m_cp])) {
        m_cp++;
    }
}
