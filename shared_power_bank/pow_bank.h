#pragma once
class PowBank
{
private:
	int pow_bank_idf;
	int battery;
public:
	PowBank() = default;
	PowBank(int pow_bank_idf, int battery);
	int Consume(); // ���ĵ���
	bool Charge(); // ���
};