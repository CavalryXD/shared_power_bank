#pragma once
class PowBank
{
private:
	int _pow_bank_idf;
	int _battery;
public:
	PowBank() = default;
	PowBank(int pow_bank_idf, int battery);
	int Consume(); // ���ĵ���
	bool Charge(); // ���
};