#include "Parameter.h"

/* パラメータをセット */

void Parameter::set(std::string key, int val)
{
	_map[key] = val;
}

/* パラメータを取得 */

int Parameter::get(std::string key) const
{
	auto it = _map.find(key);
	if (_map.end() == it) {
		return -1;
	}
	else {
		return it->second; //int valに入ってるので
	}
}