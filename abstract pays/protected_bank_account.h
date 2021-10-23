#pragma once
#include "bank_account.h"
class protected_bank_account :
    public bank_account
{
protected:
	int pin_code = 0;
	protected_bank_account(const protected_bank_account& prot) :
		bank_account(prot) {
		this->pin_code = prot.pin_code;
	}
public:

	protected_bank_account() = default;
	protected_bank_account(bank_account* account);
	protected_bank_account(const int _pin, const int _num_balance, const double _balanse, const string _name) :
		bank_account(_num_balance, _balanse, _name) {
		pin_code = _pin;
	}
	void enter_info_account()override;
	void transfer(bank_account *account,const double _trans_money)override;
	double withdraw_cash(const double draw_money)override;
	void view_data()override;
	virtual void replacement_pin();
	const int get_pin()override;
};

