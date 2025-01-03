#include "../include/Serializer.hpp"

int main() {
    // Create a Data object
    Data data = {42, "Test Data"};

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Ensure the deserialized pointer is equal to the original pointer
    assert(deserializedData == &data);

    // Validate the contents of the deserialized object
    std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;

    return 0;
}
