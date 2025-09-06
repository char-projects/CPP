#include "Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->value = 42;
    data->name = "Málaga";
    Data *data2 = new Data;
    data2->value = '*'; // ASCII value of '*' is 42
    data2->name = "Madrid";

    uintptr_t raw = Serializer::serialize(data);
    Data *deserialized = Serializer::deserialize(raw);
    uintptr_t raw2 = Serializer::serialize(data2);
    Data *deserialized2 = Serializer::deserialize(raw2);

    std::cout << "Original Data: " << data->value << " " << data->name << std::endl;
    std::cout << "Deserialized Data: " << deserialized->value << " " << deserialized->name << std::endl;
    std::cout << "Original Data2: " << data2->value << " " << data2->name << std::endl;
    std::cout << "Deserialized Data2: " << deserialized2->value << " " << deserialized2->name << std::endl;

    delete data;
    delete data2;
}
