#pragma once
#include "FieldDialog.h"

class BuyLevelDialog : public FieldDialog
{
public:
	// construtor destructor
	BuyLevelDialog();
	~BuyLevelDialog();

	// delete Function
	BuyLevelDialog(const BuyLevelDialog& _Other) = delete;
	BuyLevelDialog(BuyLevelDialog&& _Other) noexcept = delete;
	BuyLevelDialog& operator=(const BuyLevelDialog& _Other) = delete;
	BuyLevelDialog& operator=(BuyLevelDialog&& _Other) noexcept = delete;

	//void Off() override;

	static BuyLevelDialog* GetBuyLevelDialog()
	{
		return AcBuyLevelDialog;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static BuyLevelDialog* AcBuyLevelDialog;
	float4 ActorPos = {480, 544};

	GameEngineRender* DialogBack = nullptr;
	float4 DialogBackScale = {960, 192};
	
};

