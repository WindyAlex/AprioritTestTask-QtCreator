#pragma once

#include <iostream>
#include <functional>
#include <vector>

#include "file.h"

class FileReader : public File
{
private:
    void check_nm(int& num);
    void check_k(int& num);
    void check_rc(int& rc, int& num);
    int getInt(std::fstream& file);

public:
    FileReader(std::string filename);
    ~FileReader();

    void OpenFile();
    int ParseFile();
};
