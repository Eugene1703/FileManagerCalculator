
#include <iostream>
#include "FileManagerClass.h"
#include "DataProcessor.h"


template<typename T>
DataProcessor<T> createDataProcessorFromFile(const std::string& filePath) 
{
	auto fileManager = std::make_unique<FileManagerClass>(filePath);
	auto data = fileManager->loadData<T>();
	return DataProcessor<T>(data);
}
int main()
{
	try
	{
		auto processor1 = createDataProcessorFromFile<double>("C:/Users/Eugene/Desktop/Numbers.txt");
		auto processor2 = createDataProcessorFromFile<double>("C:/Users/Eugene/Desktop/Numbers(2).txt");
		auto combinedProcessor = processor1 + processor2;
		std::cout << "Results:" << std::endl;
		std::cout << "Average: " << combinedProcessor.getAverage() << std::endl;
		std::cout << "Min: " << combinedProcessor.getMin() << std::endl;
		std::cout << "Max: " << combinedProcessor.getMax() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

