#ifndef PCH_H
#define PCH_H

// Windows 헤더
#include "framework.h"

// DirectX 9
#include <d3d9.h>
#include <d3dx9.h>

#include <process.h>


// STL
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>

// ImGui 헤더
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif

#endif

// CBase 포함 (모든 클래스가 상속)
#include "CBase.h"


// Engine 기본 타입만 (자주 변경 안 됨)
#include "Engine_Define.h"

extern HINSTANCE g_hInst;
extern HWND g_hWnd;

using namespace std;
using namespace Engine;  // WINCX, WINCY 등 Engine 매크로 사용

#endif //PCH_H