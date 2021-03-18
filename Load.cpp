#include "Load.h"


StartLoad::StartLoad(){
	_frame = LoadGraph("Resource/img/ui/frame.png");
	printfDx("StartLoad: frameLoaded.\n");
}

const int StartLoad::Get(Loads data)
{
	switch (data)
	{
	case(Frame):
		return _frame;
	}
    return 0;
}


St1Load::St1Load() {
	addSingle("Resource/img/bg/1.jpg");
	printfDx("StartLoad: Loaded.\n");
}

const int St1Load::Get(Loads data)
{
	switch (data)
	{
	case(bg):
		return _imgs[0];
	}
	return 0;
}


/*!
@brief ¡‚Ü‚Åƒ[ƒh‚µ‚½‰æ‘œ‚ğ‰ğ•ú‚·‚é
*/
void St1Load::release()
{
    const int size = _imgs.size();
    for (int i = 0; i < size; i++) {
        DeleteGraph(_imgs[i]);
    }
    _imgs.clear();
}

void St1Load::addSingle(const char* fileName)
{
	int ret = LoadGraph(fileName);
	_imgs.push_back(ret);

	return;
}


void St1Load::addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf)
{
	int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
	for (int i = 0; i < n; i++) {
		_imgs.push_back(buf[i]);
	}
	return;
}
