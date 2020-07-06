#include <iostream>

#include "filereader.h"
#include "filewriter.h"

int main()
{
    int n = 0;

    FileReader reader("/home/ad/Desktop/test2-in.txt");
    reader.OpenFile();
    n = reader.ParseFile();
    reader.CloseFile();

    FileWriter writer("/home/ad/Desktop/test2-out.txt");
    writer.OpenFile();
    writer.WriteToFile(n);
    writer.CloseFile();

    std::cout << "Number of lights: " << n << std::endl;

    return 0;
}
