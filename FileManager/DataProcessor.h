#pragma once
#include <numeric>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>
template<typename T>
class DataProcessor
{
public: explicit DataProcessor(std::shared_ptr<std::vector<T>> data) : data(std::move(data)) 
{
	checkDataIsNotEmpty();
}
	T getAverage() const;
	T getMin() const;
	T getMax() const;
	void checkDataIsNotEmpty() const;
	DataProcessor operator+(DataProcessor other);
private:
	std::shared_ptr<std::vector<T>> data;
};

