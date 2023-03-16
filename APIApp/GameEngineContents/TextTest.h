#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "LetterRenderObject.h"

class TextTest : public GameEngineActor
{
public:
	// construtor destructor
	TextTest();
	~TextTest();

	// delete Function
	TextTest(const TextTest& _Other) = delete;
	TextTest(TextTest&& _Other) noexcept = delete;
	TextTest& operator=(const TextTest& _Other) = delete;
	TextTest& operator=(TextTest&& _Other) noexcept = delete;

protected:


private:
	


};

