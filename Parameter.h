#pragma once

#include <map>
#include <string>

class Parameter
{
public:
	
	Parameter() = default;
	virtual ~Parameter() = default;

	void set(std::string key, int val); // �p�����[�^�Z�b�g
	int get(std::string key) const; // �p�����[�^�擾(int)

private:
	std::map<std::string, int> _map;
};

