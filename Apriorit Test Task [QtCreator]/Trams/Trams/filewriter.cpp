#include "filewriter.h"

FileWriter::FileWriter(std::string filename):
    File(filename)
{

}

FileWriter::~FileWriter()
{

}

void FileWriter::OpenFile()
{
    if(!(file.is_open()))
    {
        file.open(filename, std::ios_base::out);
    }
}

void FileWriter::WriteToFile(int n)
{
    if(file.is_open())
    {
        file << n;
    }
}
