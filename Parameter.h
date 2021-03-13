#pragma once

#include <map>
#include <string>

class Parameter
{
public:
	
	Parameter() = default;
	virtual ~Parameter() = default;

	void set(std::string key, int val); // パラメータセット
	int get(std::string key) const; // パラメータ取得(int)

private:
	std::map<std::string, int> _map;
};

