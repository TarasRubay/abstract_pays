#include "bank_account.h"

bank_account::bank_account(int num_b, double bal, string _name)
{
	num_balans = num_b;
	balans = bal;
	name = _name;
}

const double bank_account::balans_check()
{
	return balans;
}

const int bank_account::get_id()
{
	return num_balans;
}

const string bank_account::get_name()
{
	return this->name;
}

void bank_account::replenish_balans(const double money)
{
	balans += money;
}
