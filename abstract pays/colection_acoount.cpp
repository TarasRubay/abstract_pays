#include "colection_acoount.h"
void bank_employee(vector<bank_account*>& _colection)
{
	
	vector<bank_account*>::iterator it;
	int menu = 100, max_menu = 4,ind = 0;
	int switch_on = menu;
	bool check = false;
	do
	{
		switch (switch_on)
		{
		case 100:
			do
			{
				check = false;
				cout << "\n1 - view list bank account\n";
				cout << "2 - add acoount\n";
				cout << "3 - add credit acoount\n";
				cout << "4 - delete bank account\n";
				cout << "0 - exit\n";

				cin >> switch_on;
				system("cls");
			} while (switch_on < 0 || switch_on > max_menu);
			cin.get();
			break;
		case 1:
			if (_colection.empty())cout << "no client bank account";
			else {
				for (int i = 0; i < _colection.size(); i++)
				{
					_colection.at(i)->view_data();
					cout << endl;
				}
			}
			switch_on = menu;
			break;
		case 2:
			add_protect(_colection);
			switch_on = menu;
			break;
		case 3:
			add_credit(_colection);
			switch_on = menu;
			break;
		case 4:
			if (_colection.empty())cout << "no client bank account";
			else {
				for (int i = 0; i < _colection.size(); i++)_colection.at(i)->view_data();
				cout << "\n\nEntet ID to delete: ";
				cin >> switch_on;
				cin.get();
				for (int i = 0; i < _colection.size(); i++)
				{
					if (switch_on == _colection.at(i)->get_id()) {
						check = true;
						ind = i;
						break;
					}
				}
				if (check) {
					if (!_colection[ind]->balans_check()) {
						it = _colection.begin() + ind;
						_colection.erase(it);
						cout << "\ndelete is completed...";
					}
					else cout << "\nIt is impossible to delete en acoount with a non-zero balance!!!";
				}
				else cout << "\nNo found ID to delete!!!";
			}
			switch_on = menu;
			break;
		default:
			break;
		}

	} while (switch_on != 0);
}

void add_credit(vector<bank_account*>& _colection)
{
	credit_protec_bank_account* tmp = new credit_protec_bank_account();
	tmp->enter_info_account();
	bool check = false;
	int ind;
	if (_colection.empty()) {
		_colection.push_back(tmp);
	}
	else {
		for (int i = 0; i < _colection.size(); i++)
		{
			if (tmp->get_id() == _colection[i]->get_id()) {
				check = true;
				ind = i;
				break;
			}
		}

		if (check)cout << "To change en existing acoount - " << _colection.at(ind)->get_id();
		else _colection.push_back(tmp);
	}
}

void add_protect(vector<bank_account*>& _colection)
{
		protected_bank_account* tmp = new protected_bank_account();
		tmp->enter_info_account();
		//tmp->replenish_balans(20);
		bool check = false;
		int ind;
	if (_colection.empty()) {
		_colection.push_back(tmp);
	}
	else {
	for (int i = 0; i < _colection.size(); i++)
	{ 
		if (tmp->get_id() == _colection[i]->get_id()) {
			check = true;
			ind = i;
			break;
		}
	}

	if (check)cout << "To change en existing acoount - " << _colection.at(ind)->get_id();
	else _colection.push_back(tmp);
	}


}

void bank_client(vector<bank_account*>& _colection)
{
	bool check = false;
	int ind,i_tranfer;
	cout << "Hi client enter your acoount ID: ";
	int id, id_tansfer;
	double money;
	cin >> id;
	cin.get();
	for (int i = 0; i < _colection.size(); i++)
	{
		if (id == _colection[i]->get_id()) {
			check = true;
			ind = i;
			break;
		}
	}

	if (check)
	{
		int pin_code;
		cout << "Enter pin for acoount(min 1000 max 9999): "<< id << endl;
			cin >> pin_code;
		cin.get();

		if (pin_code == _colection[ind]->get_pin()) {
			
			int menu = 100, max_menu = 4;
			int switch_on = menu;
			do
			{
				switch (switch_on)
				{
				case 100:
					do
					{
						check = false;
						cout << "\n\nHello user: " << _colection[ind]->get_name() << endl;
						cout << "\n1 - transfer money to othen acoount\n";
						cout << "2 - refill this acoount\n";
						cout << "3 - withdraw money\n";
						cout << "4 - view data about this acoount\n";
						cout << "0 - exit\n";

						cin >> switch_on;
						system("cls");
					} while (switch_on < 0 || switch_on > max_menu);
					cin.get();

					break;
				case 1:
					cout << "\n1 - transfer money to othen acoount\n";
					cout << "Enter tranfer acoount ID: ";
					cin >> id_tansfer;
					cin.get();
					for (int i = 0; i < _colection.size(); i++)
					{
						if (id_tansfer == _colection[i]->get_id()) {
							check = true;
							i_tranfer = i;
							break;
						}
					}
					if (check) {
						cout << "Enter count money: ";
						cin >> money;
						cin.get();
						_colection[ind]->transfer(_colection[i_tranfer],money);
						cout << "Transfer completed...";
					}
					else
					{
						cerr << "Not found ID";
					}
					switch_on = menu;
					break;
				case 2:
					cout << "2 - refill this acoount\n";
					cout << "Enter count money: ";
					cin >> money;
					cin.get();
					_colection[ind]->replenish_balans(money);
					cout << "Your balans: " << _colection[ind]->balans_check();
					switch_on = menu;
					break;
				case 3:
					cout << "3 - withdraw money\n";
					cout << "Enter count money: ";
					cin >> money;
					cin.get();
					_colection[ind]->withdraw_cash(money);
					cout << "3 - withdraw completed...\n";
					cout << "Your balans: " << _colection[ind]->balans_check();
					switch_on = menu;
					break;
				case 4:
					cout << "4 - view data about this acoount\n";
					_colection[ind]->view_data();
					switch_on = menu;
					break;
				default:
					break;
				}

			} while (switch_on != 0);
		}
		else {
			cerr << "wrong pin";
		}
	}
	else {
			cerr << "wrong ID";
	}
}

