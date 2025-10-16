#pragma once
#include "CScene.h"
class CStage1 :
    public CScene
{
public:
    CStage1();
    virtual ~CStage1();

public:
    void Initialize() override;
    void Update() override;
    void Late_Update() override;
    void Render(HDC hDC) override;
    void Release() override;


#pragma region 호준 - 신규 추가 
// DeltaTime 사용하기 위한 기본 변수 추가

public:

    ULONGLONG		m_currTime;			// Update 호출 시 시각 체크
    ULONGLONG		m_prevTime;			// 해당 프레임 생성시 시각 체크 
    float			m_deltaTime;		// 시간 차이 담는 변수

#pragma endregion

};

