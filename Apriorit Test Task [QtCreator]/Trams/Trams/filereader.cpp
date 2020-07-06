#include "filereader.h"

FileReader::FileReader(std::string filename):
    File(filename)
{

}

FileReader::~FileReader()
{

}

void FileReader::OpenFile()
{
    if(!(file.is_open()))
    {
        file.open(filename, std::ios_base::in);
    }
}

void FileReader::check_nm(int& num)
{
    if(num < 1)
    {
        num = 1;
    }

    if(num > 1000000000)
    {
        num = 1000000000;
    }
}

void FileReader::check_k(int& num)
{
    if(num < 0)
    {
        num = 0;
    }

    if(num > 1000)
    {
        num = 1000;
    }
}

void FileReader::check_rc(int& rc, int& num)
{
    if(rc < 1)
    {
        rc = 1;
    }

    if(rc > num)
    {
        rc = num;
    }
}

int FileReader::getInt(std::fstream& file)
{
    std::string num;
    char s;
    while(file >> std::noskipws >> s)
    {
        if(s == ' ' || s == '\n')
        {
            return std::stoi(num);
        }
        else if(s < 48 || s > 57)
        {
            continue;
        }
        else
        {
            num += s;
        }
    }

    return std::stoi(num);
}

int FileReader::ParseFile()
{
    int m, n, k, r, c1, c2;
    std::vector<std::vector<bool>> arr;
    int count{0};

    if(!(file.is_open()))
    {
        return -1;
    }

    //file >> n >> m >> k;

    // Apriorit files has special(unshown) symbols.
    // So we should read symbol by symbol and check all of them
    n = getInt(std::ref(file));
    m = getInt(std::ref(file));
    k = getInt(std::ref(file));

    check_nm(std::ref(n));
    check_nm(std::ref(m));
    check_k(std::ref(k));

    std::cout << n << ' ' << m << ' ' << k << std::endl;

    for(int i{0}; i < m; ++i)
    {
        std::vector<bool> vect;
        for(int j{0}; j < n; ++j)
        {
            vect.push_back(true);
        }
        arr.push_back(vect);
    }

    for(int i{0}; i < k; ++i)
    {
        //file >> r >> c1 >> c2;
        r = getInt(std::ref(file));
        c1 = getInt(std::ref(file));
        c2 = getInt(std::ref(file));

        check_rc(std::ref(r), std::ref(n));
        check_rc(std::ref(c1), std::ref(m));
        check_rc(std::ref(c2), std::ref(m));

        std::cout << r << ' ' << c1 << ' ' << c2 << std::endl;

        for(; c1 <= c2; ++c1)
        {
            arr.at(c1 - 1).at(r - 1) = false;
        }
    }

    for(int i{0}; i < m; ++i)
    {
        for(int j{0}; j < n; ++j)
        {
            if(arr.at(i).at(j))
            {
                count++;
            }
        }
    }

    return count;
}
