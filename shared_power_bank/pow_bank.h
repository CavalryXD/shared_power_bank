#pragma once
class PowBank
{
private:
	int _pow_bank_idf;
	int _battery;
public:
	PowBank() = default;
	PowBank(int pow_bank_idf, int battery);
	int Consume(); // 消耗电量
	bool Charge(); // 充电
};