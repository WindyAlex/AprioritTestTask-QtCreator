#include "file.h"

File::File(std::string filename):
    filename(filename)
{

}

File::~File()
{

}

void File::CloseFile()
{
    if(file.is_open())
    {
        file.close();
    }
}
