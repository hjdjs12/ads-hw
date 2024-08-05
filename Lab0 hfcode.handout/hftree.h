#ifndef HFTREE_H
#define HFTREE_H

#include <string>
#include <map>

class hfTree
{

private:
    // TODO: Your code here
public:
    enum class Option
    {
        SingleChar,
        MultiChar
    };
    hfTree(const std::string &text, const Option op);
    std::map<std::string, std::string> getCodingTable();
};

#endif