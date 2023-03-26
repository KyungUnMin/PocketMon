#pragma once

// Ό³Έν :
class WhiteBox
{
public:
	// constrcuter destructer
	WhiteBox();
	~WhiteBox();

	// delete Function
	WhiteBox(const WhiteBox& _Other) = delete;
	WhiteBox(WhiteBox&& _Other) noexcept = delete;
	WhiteBox& operator=(const WhiteBox& _Other) = delete;
	WhiteBox& operator=(WhiteBox&& _Other) noexcept = delete;

protected:

private:

};

