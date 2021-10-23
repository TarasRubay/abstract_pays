#include "colection_acoount.h"
#include<iomanip>
int main() {
	vector<bank_account*> colection;
	int menu = 100, max_menu = 2;
	int switch_on = menu;
	do
	{
		switch (switch_on)
		{
		case 100:
			do
			{
				cout << "\n1 - Bank employee\n";
				cout << "2 - Bank client\n";
				cout << "0 - exit\n";
				cin >> switch_on;
				system("cls");
			} while (switch_on < 0 || switch_on > max_menu);
			cin.get();

			break;
		case 1:
			bank_employee(colection);
			switch_on = menu;
			break;
		case 2:
			if (colection.empty())cout << "no bank account";
			else bank_client(colection);
			switch_on = menu;
			break;
		default:
			break;
		}

	} while (switch_on != 0);
	return 0;
}

////#include "credit_protec_bank_account.h"
////#include <vector>
////int main() {
////	vector<bank_account*> colect;
////	credit_protec_bank_account a(-250.0, 1234, 32424, 100.23, "Mikhaiel"), c(-50.0, 2222, 324, 50, "Miki");
////	protected_bank_account b(2222, 323, 200, "Jonh");
////	bank_account* p_protect, * p_credit;
////	p_protect = &b;
////	p_credit = &a;
////	//c->enter_info_account();
////	double res = p_credit->balans_check();
////	p_credit->replenish_balans(20.23);
////	p_protect->transfer(p_credit, 20);
////	p_credit->transfer(p_protect, 100);
////	res = p_credit->balans_check();
////	double res2 = p_protect->balans_check();
////	res = p_credit->withdraw_cash(240);
////	credit_protec_bank_account* tmp;
////	tmp = dynamic_cast<credit_protec_bank_account*>(p_credit);
////	//tmp->replacement_pin();
////	//a.replacement_pin();
////	//b.replacement_pin();
////	colect.push_back(&a);
////	colect.push_back(&b);
////	colect.push_back(&c);
////	for (int i = 0; i < colect.size(); i++)
////	{
////		colect.at(i)->view_data();
////	}
////	return 0;
////}
////
