#include "FileManagerClass.h"


FileManagerClass::FileManagerClass(const std::string& filePath) 
{
    file.open(filePath);
    if (!file.is_open()) 
    {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
}

FileManagerClass::~FileManagerClass()
{
    if (file.is_open()) 
    {
        file.close();
    }
}

template<typename T>
std::shared_ptr<std::vector<T>> FileManagerClass::loadData()
{
    auto data = std::make_shared<std::vector<T>>(); 
    T value;
    while (file >> value) 
    {
        data->push_back(value);
    }
    return data; 
}

using SPvecInt = std::shared_ptr<std::vector<int>>;
using SPvecDouble = std::shared_ptr<std::vector<double>>;

template SPvecInt FileManagerClass::loadData<int>();
template SPvecDouble FileManagerClass::loadData<double>();