#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <memory>

class FileManagerClass
{
public: FileManagerClass(const std::string& filePath);
      template<typename T>
      std::shared_ptr<std::vector<T>> loadData();
      ~FileManagerClass();
private:
    std::ifstream file;
};

