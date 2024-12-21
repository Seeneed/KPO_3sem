#pragma once
class Deserializer
{
public:
	void Deserialize(char* valueChar, char* literalChar);
private:
	const char* FILENAME = "../Serialization/bin.bin";
};
