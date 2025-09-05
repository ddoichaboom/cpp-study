#pragma once
#include "CObj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	~CPlayer();

public:
	int		Get_MaxEx() override { return m_iMaxEx; }
	int		Get_CurEx() override { return m_iCurEx; }


public:
	void	Set_CurEx(int iEx) override;
	void	Set_MaxEx(int iMaxEx) override;
	void	Set_Hp(int iMaxHp) override;
	void	Level_Up(int iDrpEx) override;
	void	Select_Job() override;
	void	Render()	override;

private:
	int		m_iMaxEx;
	int		m_iCurEx;

};

