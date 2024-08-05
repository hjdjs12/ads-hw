#ifndef UTILS_H
#define UTILS_H

#include <cstring>

namespace utils
{
    std::string getFileName(const std::string &fileName, const std::string &suffix)
    {
        size_t final_pos = fileName.find_last_of("/\\");
        size_t suffix_pos = fileName.find_last_of('.');
        return final_pos == std::string::npos ? "./output/" + fileName.substr(0, suffix_pos) + suffix : "./output/" + fileName.substr(final_pos + 1, suffix_pos - final_pos - 1) + suffix;
    }

    std::string parseText(const std::string &input)
    {
        std::string content;
        // TODO: Your code here
        return content;
    }

    void output(const std::string &output, const std::string &data)
    {
        // TODO: Your code here
    }

    std::string codingTable2String(const std::map<std::string, std::string> &codingTable)
    {
        std::string result = "";
        // TODO: Your code here
        return result;
    }

    void loadCodingTable(const std::string &input, std::map<std::string, std::string> &codingTable)
    {
        // TODO: Your code here
    }

    std::string compress(const std::map<std::string, std::string> &codingTable, const std::string &text)
    {
        std::string result;
        // TODO: Your code here
        return result;
    }
};

#endif