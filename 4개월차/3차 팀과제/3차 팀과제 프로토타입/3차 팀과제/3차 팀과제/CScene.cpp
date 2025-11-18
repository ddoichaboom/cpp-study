#include "pch.h"
#include "CScene.h"
#include "CObjMgr.h"

CScene::CScene()
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Release()
{
	CObjMgr::Destroy_Instance();
}
