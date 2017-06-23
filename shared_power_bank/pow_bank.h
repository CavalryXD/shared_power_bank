#pragma once
class PowBank
{
private:
	int _pow_bank_idf;
	int _battery;
public:
	PowBank() {}
	PowBank(int pow_bank_idf, int battery):_pow_bank_idf(pow_bank_idf),_battery(battery){}
	int Consume(); // 消耗电量
	bool Charge(); // 充电
};