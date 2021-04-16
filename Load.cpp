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

GameLoad::GameLoad() {
	//addSingle("Resource/img/bg/1.jpg");
	addSingle("Resource/img/ui/sample.png");
	addGroup("Resource/img/spdot/player_reimu.png", 6, 2, 3, 48, 48, _IMAGES);
	addGroup("Resource/img/spdot/compass.png", 3, 3, 1, 300, 300, _COMPASSIMAGES);
	printfDx("StartLoad: Loaded.\n");
}

const int GameLoad::Get(Loads data)
{
	switch (data)
	{
	case(bg):
		return _imgs[0];
	case(PlayerImg):
		if (Score::Instance()->GetScore(Gametime) % 4 == 0) {
			if (pallanime <= panime) {
				panime = 0;
			}
			else {
				panime++;
			}
		}
		return _imgs[1+panime];
	case(Compass_RED):
		return _imgs[7];
	case(Compass_GREEN):
		return _imgs[8];
	case(Compass_BLUE):
		return _imgs[9];
	}
	return 0;
}

/*!
@brief 今までロードした画像を解放する
*/
void GameLoad::release()
{
	const int size = _imgs.size();
	for (int i = 0; i < size; i++) {
		DeleteGraph(_imgs[i]);
	}
	_imgs.clear();
}

void GameLoad::addSingle(const char* fileName)
{
	int ret = LoadGraph(fileName);
	_imgs.push_back(ret);

	return;
}


void GameLoad::addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf)
{
	int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
	for (int i = 0; i < n; i++) {
		_imgs.push_back(buf[i]);
	}
	return;
}

GameLoadSE::GameLoadSE() {
	addSingle("Resource/se/dmg01.wav");
	addSingle("Resource/se/charge00.ogg");
	addSingle("Resource/se/charge01.ogg");
	addSingle("Resource/se/missing.ogg");
	addSingle("Resource/se/pshot.ogg");
	addSingle("Resource/se/shot1.ogg");
	printfDx("GameLoadSE: Loaded.\n");
}

const int GameLoadSE::Get(LoadSEs data)
{
	return _ses[data];
}

/*!
@brief 今までロードした画像を解放する
*/
void GameLoadSE::release()
{
	const int size = _ses.size();
	for (int i = 0; i < size; i++) {
		DeleteSoundMem(_ses[i]);
	}
	_ses.clear();
}

void GameLoadSE::addSingle(const char* fileName)
{
	int ret = LoadSoundMem(fileName);
	_ses.push_back(ret);

	return;
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
@brief 今までロードした画像を解放する
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
