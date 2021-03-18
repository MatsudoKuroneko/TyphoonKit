#include "StartLoad.h"
#include <DxLib.h>

StartLoad::StartLoad(){
	_frame = LoadGraph("Resource/img/ui/frame.png");
	printfDx("StartLoad: frameLoaded.\n");
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
