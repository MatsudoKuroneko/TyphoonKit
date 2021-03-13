#include "Parameter.h"

/* �p�����[�^���Z�b�g */

void Parameter::set(std::string key, int val)
{
	_map[key] = val;
}

/* �p�����[�^���擾 */

int Parameter::get(std::string key) const
{
	auto it = _map.find(key);
	if (_map.end() == it) {
		return -1;
	}
	else {
		return it->second; //int val�ɓ����Ă�̂�
	}
}