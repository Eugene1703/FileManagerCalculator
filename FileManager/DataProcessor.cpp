#include "DataProcessor.h"

template<typename T>
void DataProcessor<T>::checkDataIsNotEmpty() const
{
    if (data->empty())
    {
        throw std::runtime_error("Data is empty");
    }
}
template<typename T>
T DataProcessor<T>::getAverage() const 
{
    return std::accumulate(data->begin(), data->end(), T(0)) / static_cast<T>(data->size());
}
template<typename T>
T DataProcessor<T>::getMin() const
{
    return *std::min_element(data->begin(), data->end());
}
template<typename T>
T DataProcessor<T>::getMax() const
{
    return *std::max_element(data->begin(), data->end());
}
template<typename T>
DataProcessor<T> DataProcessor<T>::operator+(DataProcessor<T> other) 
{
    auto newData = std::make_shared<std::vector<T>>(*data); 
    newData->insert(newData->end(), other.data->begin(), other.data->end());
    return DataProcessor(newData);
}
// Explicit template instantiation 
template class DataProcessor<int>;
template class DataProcessor<double>;
