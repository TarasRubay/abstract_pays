#pragma once
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class bank_account
{
protected:
	int num_balans = 0;
	double balans = 0.0;
	string name;
	bank_account(const bank_account*& ac) {
		this->num_balans = ac->num_balans;
		this->balans = ac->balans;
		this->name = ac->name;
	}
public:
	
	bank_account() = default; //конструктор
	bank_account(const int num_b, const double bal, const string _name); //конструктор з параметрами
	virtual void enter_info_account()=0; 
	virtual void transfer(bank_account* account,const double _trans_money)=0; // переведення коштів на інший рахунок
	virtual double withdraw_cash(const double draw_money)=0; // метод зняття коштів
	virtual void view_data()=0;
	const double balans_check();
	virtual const int get_pin() = 0;
	const int get_id();
	const string get_name();
	void replenish_balans(const double money);
};

