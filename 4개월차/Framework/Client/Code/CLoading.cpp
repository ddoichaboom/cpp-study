#include "pch.h"
#include "CLoading.h"
#include "CProtoMgr.h"

CLoading::CLoading(LPDIRECT3DDEVICE9 pGraphicDev)
    : m_pGraphicDev(pGraphicDev), m_bFinish(false), m_eLoading(LOADING_END)
{
    m_pGraphicDev->AddRef();
}

CLoading::~CLoading()
{
}

HRESULT CLoading::Ready_Loading(LOADINGID eID)
{
    // 임계 영역 초기화
    InitializeCriticalSection(&m_Crt);

    m_eLoading = eID;

    int iNumber = 10;

    m_hThread = (HANDLE)_beginthreadex(NULL,                // 보안속성(핸들의 상속 여부, null인 경우 상속에서 제외)
                                        0,                  // 디폴트 스택 사이즈(1 바이트)
                                        Thread_Main,        // 쓰레드 함수
                                        this,               // 쓰레드 함수를 이용하여 가공할 데이터 주소    
                                        0,                  // 쓰레드 생성 및 실행을 조정하기 옵션(flag)
                                        NULL);              // 쓰레드 id

    return S_OK;
}

_uint CLoading::Loading_ForStage()
{
    // Proto_TriCol
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_TriCol", Engine::CTriCol::Create(m_pGraphicDev))))
        return E_FAIL;

    // Proto_RcCol
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_RcCol", Engine::CRcCol::Create(m_pGraphicDev))))
        return E_FAIL;

    // Proto_TerrainTex
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_TerrainTex", Engine::CTerrainTex::Create(m_pGraphicDev, VTXCNTX, VTXCNTZ, VTXITV))))
        return E_FAIL;

    // Proto_Transform
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_Transform", Engine::CTransform::Create(m_pGraphicDev))))
        return E_FAIL;

    // Proto_PlayerTexture
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_PlayerTexture", Engine::CTexture::Create(m_pGraphicDev, TEX_NORMAL, L"../Bin/Resource/Texture/Player0.png", 1))))
        return E_FAIL;

    // Proto_TerrainTexture
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_TerrainTexture", Engine::CTexture::Create(m_pGraphicDev, TEX_NORMAL, L"../Bin/Resource/Texture/Terrain/Terrain0.png", 1))))
        return E_FAIL;

    // 로딩 완료 
    m_bFinish = true;

    return 0;
}

unsigned int CLoading::Thread_Main(void* pArg)
{
    // void* -> CLoading* 타입 변환
    CLoading* pLoading = reinterpret_cast<CLoading*>(pArg);

    _uint iFlag(0);

    // 임계 영역 진입 (Lock)
    EnterCriticalSection(pLoading->Get_Crt());

    switch (pLoading->Get_Loading())
    {
    case LOADING_STAGE:
        iFlag = pLoading->Loading_ForStage();
        break;

    case LOADING_BOSS:
        break;
    }

    // 임계 영역 탈출 (Unlock)
    LeaveCriticalSection(pLoading->Get_Crt());

    // 자동 종료 ( 주석 처리 )
    // _endthreadex(0);

    return iFlag;
}

CLoading* CLoading::Create(LPDIRECT3DDEVICE9 pGraphicDev, LOADINGID eID)
{
    CLoading* pLoading = new CLoading(pGraphicDev);

    if (FAILED(pLoading->Ready_Loading(eID)))
    {
        Safe_Release(pLoading);
        MSG_BOX("Loading Create Failed");
        return nullptr;
    }

    return pLoading;
}

void CLoading::Free()
{
    WaitForSingleObject(m_hThread, INFINITE);

    CloseHandle(m_hThread);

    DeleteCriticalSection(&m_Crt);

    Safe_Release(m_pGraphicDev);
}