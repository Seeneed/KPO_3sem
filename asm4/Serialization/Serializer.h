#pragma once
class Serializer
{
public:
	void Serialize(char valueChar, char literalChar);
private:
	const char* FILENAME = "bin.bin";
};
