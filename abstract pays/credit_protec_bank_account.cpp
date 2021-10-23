#include "credit_protec_bank_account.h"

void credit_protec_bank_account::enter_info_account()
{
	protected_bank_account::enter_info_account();
	cout << "\nEnter down credit limit max 0: ";
	do
	{
		cin >> this->down_limit_credit;
		if (this->down_limit_credit > 0)cerr << "max 0!!!  ";
	} while (this->down_limit_credit > 0);
	cin.get();

}

void credit_protec_bank_account::transfer(bank_account* account,const double _trans_money)
{
	protected_bank_account::transfer(account,_trans_money);
}

double credit_protec_bank_account::withdraw_cash(const double draw_money)
{ 
	if (this->down_limit_credit > this->balans - draw_money) {
		cerr << "Exceeding the credit limit\n";
		return 0.0;
	}
	else
	{
		this->balans -= draw_money;
		return draw_money;
	}
}

void credit_protec_bank_account::view_data()
{
	cout << "\n<<Credit protected account>>\n";
	cout << "Name: " << this->name;
	cout << "\nID: " << this->num_balans;
	cout << "\nBalans: " << this->balans;
	cout << "\nDown limit: " << this->down_limit_credit;
}

void credit_protec_bank_account::replacement_pin()
{
	protected_bank_account::replacement_pin();
}

const int credit_protec_bank_account::get_pin()
{
	return protected_bank_account::get_pin();
}
