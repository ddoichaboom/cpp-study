#include "pch.h"
#include "CLogo.h"
#include "CBackGround.h"
#include "CProtoMgr.h"
#include "CStage.h"
#include "CManagement.h"

CLogo::CLogo(LPDIRECT3DDEVICE9 pGraphicDev)
    :   CScene(pGraphicDev), m_pLoading(nullptr)
{

}

CLogo::~CLogo()
{

}

HRESULT	CLogo::Ready_Scene()
{
    if (FAILED(Ready_Prototype()))
        return E_FAIL;

    if (FAILED(Ready_Environment_Layer(L"Environment_Layer")))
        return E_FAIL;

    // 로딩 스레드 생성 및 시작
    m_pLoading = CLoading::Create(m_pGraphicDev, CLoading::LOADING_STAGE);

    return S_OK;
}

_int	CLogo::Update_Scene(const _float& fTimeDelta)
{
    _int    iExit = Engine::CScene::Update_Scene(fTimeDelta);

    if (true == m_pLoading->Get_Finish())
    {
        if (GetAsyncKeyState(VK_RETURN))
        {
            Engine::CScene* pStage = CStage::Create(m_pGraphicDev);

            if (nullptr == pStage)
                return -1;

            if (FAILED(CManagement::GetInstance()->Set_Scene(pStage)))
            {
                MSG_BOX("Stage Scene Failed");
                return -1;
            }
        }
    }

    return iExit;
}

void	CLogo::LateUpdate_Scene(const _float& fTimeDelta)
{
    Engine::CScene::LateUpdate_Scene(fTimeDelta);
}

void	CLogo::Render_Scene()
{
}

HRESULT CLogo::Ready_Environment_Layer(const _tchar* pLayerTag)
{
    CLayer* pLayer = CLayer::Create();
    if (nullptr == pLayer)
        return E_FAIL;

    CGameObject* pGameObject = nullptr;

    // BackGround
    pGameObject = CBackGround::Create(m_pGraphicDev);

    if (FAILED(pLayer->Add_GameObject(L"BackGround", pGameObject)))
        return E_FAIL;

    m_mapLayer.insert({ pLayerTag, pLayer });

    return S_OK;
}

HRESULT CLogo::Ready_Prototype()
{
    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_RcTex", Engine::CRcTex::Create(m_pGraphicDev))))
        return E_FAIL;

    if (FAILED(CProtoMgr::GetInstance()->Ready_Prototype(L"Proto_LogoTexture", Engine::CTexture::Create(m_pGraphicDev, TEX_NORMAL, L"../Bin/Resource/Texture/Logo/jang.jpg", 1))))
        return E_FAIL;

    return S_OK;
}

CLogo* CLogo::Create(LPDIRECT3DDEVICE9 pGraphicDev)
{
    CLogo* pLogo = new CLogo(pGraphicDev);

    if (FAILED(pLogo->Ready_Scene()))
    {
        Safe_Release(pLogo);
        MSG_BOX("pLogo Create Failed");
        return nullptr;
    }

    return pLogo;
}

void CLogo::Free()
{
    Safe_Release(m_pLoading);

    CScene::Free();
}