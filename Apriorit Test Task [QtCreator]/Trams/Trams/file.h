#pragma once

#include <fstream>

class File
{
protected:
    std::string filename;
    std::fstream file;

public:
    File(std::string filename);
    virtual ~File();

    virtual void OpenFile() = 0;
    void CloseFile();
};
