#pragma once

#include "file.h"

class FileWriter : public File
{
public:
    FileWriter(std::string filename);
    ~FileWriter();

    void OpenFile();
    void WriteToFile(int n);
};
