#include "StartLoad.h"
#include <DxLib.h>

StartLoad::StartLoad(){
	_frame = LoadGraph("Resource/ui/frame.png");
}

const int StartLoad::Get(StartLoads data)
{
	switch (data)
	{
	case(Frame):
		return _frame;
	}
    return 0;
}
