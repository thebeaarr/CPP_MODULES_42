#include "Serializer.hpp"


int main()
{
    Data* data = new Data();
    data->info = "Hello, Serializer!";
    
    uintptr_t raw = Serializer::serialize(data);
    Data* deserializedData = Serializer::deserialize(raw);
    if (deserializedData)
        std::cout << "Deserialized info: " << deserializedData->info << std::endl;
    
    delete data;
    return 0;
}