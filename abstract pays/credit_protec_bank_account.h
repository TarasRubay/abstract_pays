#pragma once
#include "protected_bank_account.h"
class credit_protec_bank_account :
    public protected_bank_account
{
protected:
    double down_limit_credit = 0.0;
	credit_protec_bank_account(const credit_protec_bank_account& cred) :
		protected_bank_account(cred) {
		this->pin_code = cred.pin_code;
	}
public:
	credit_protec_bank_account() = default;
	credit_protec_bank_account(const double _down_limit, const int _pin, const int _num_balance, const double _balanse, const string _name) :
		protected_bank_account(_pin, _num_balance, _balanse, _name) {
		down_limit_credit = _down_limit;
	}
	void enter_info_account()override;
	void transfer(bank_account* account,const double _trans_money)override;
	double withdraw_cash(const double draw_money)override;
	void view_data()override;
	void replacement_pin()override;
	const int get_pin()override;
};

