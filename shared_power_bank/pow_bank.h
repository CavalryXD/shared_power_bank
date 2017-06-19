#pragma once
class PowBank
{
private:
	int pow_bank_idf;
	int battery;
public:
	PowBank(int pow_bank_idf, int battery);
	int Consume();
	bool Charge();
};