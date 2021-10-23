#include "protected_bank_account.h"


protected_bank_account::protected_bank_account(bank_account* account)
{
	*this = account;
}

void protected_bank_account::enter_info_account()
{
	cout << "\nEnter number account: ";
	do
	{
		cin >> this->num_balans;
		if (this->num_balans < 1)cerr << "min 1!!!  ";
	} while (this->num_balans < 1);
	cin.get();
	cout << "Enter name owner account:";
	getline(cin, this->name);
	cout << "Enter pin: ";
	do
	{
		cin >> this->pin_code;
		if (this->pin_code < 1000 || this->pin_code > 9999)cerr << "min 1000 max 9999!!!  ";
	} while (this->pin_code < 1000 || this->pin_code > 9999);
	cin.get();
	this->balans = 0.0;
}

void protected_bank_account::transfer(bank_account* account,const double _trans_money)
{
		account->replenish_balans(this->withdraw_cash(_trans_money));
}

double protected_bank_account::withdraw_cash(const double draw_money)
{
	if (this->balans < draw_money) {
		cerr << "Not enough money\n";
		return 0.0;
	}
	else
	{
		this->balans -= draw_money;
		return draw_money;
	}
}

void protected_bank_account::view_data()
{
	cout << "\n<<Protected account>>\n";
	cout << "Name: " << this->name;
	cout << "\nID: " << this->num_balans;
	cout << "\nBalans: " << this->balans;
}

void protected_bank_account::replacement_pin()
{
	cout << "Enter pin code to account - " << this->name<<"\n 0 - exit\n";
	int replace_pin;
	do
	{
		cin >> replace_pin;
		if (replace_pin == 0)break;
		if (replace_pin != this->pin_code)cerr << "min 1000 max 9999!!! ";
	} while (replace_pin != this->pin_code);
	cin.get();
	if (replace_pin == 0)return;
	else {
		cout << "Enter new pin code to account - " << this->name << endl;
		do
		{
			cin >> this->pin_code;
			if (this->pin_code < 1000 || this->pin_code > 9999)cerr << "min 1000 max 9999!!!  ";
		} while (this->pin_code < 1000 || this->pin_code > 9999);
		cin.get();
	}
}

const int protected_bank_account::get_pin()
{
	return this->pin_code;
}
