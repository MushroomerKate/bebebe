#include <iostream>
#include <string>
#include "Company.h"
#include <fstream>
#include "Function.h"
#include <msclr\marshal_cppstd.h>

using namespace System::Data;
using namespace MySql::Data::MySqlClient;

using namespace std;

    Company& Company::getInstance()
    {
        static Company  C;
        return C;
    }
    void Company::add_Tariff(string n, double r, double d) {
        for (int i = 0; i < 5; i++) {
            if (tariffs[i].name == "") {
                tariffs[i].name = n;
                tariffs[i].rate = r;
                tariffs[i].discount = d;
                return;
            }
        }
        cout << "No more tariffs allowed\n";
    }

    void Company::LoadData() {
        ifstream file("Data.txt");
        string str;
        for (int i = 0; getline(file, str); i++) {
            tariffs[i].name = lineName(str);
            tariffs[i].rate = lineRate(str);
            tariffs[i].discount = lineDiscount(str);
        }
        file.close();
    }

    void Company::LoadData_base(void) {
        MySqlConnection^ dbConn = gcnew MySqlConnection("Server=localhost; Database=new_schema; Uid=root; Pwd=Choochmeck112!;");
        MySqlCommand^ dbCmd = gcnew MySqlCommand("SELECT * FROM new_schema.new_table;", dbConn);
        MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(dbCmd);
        DataSet^ dataSet = gcnew DataSet();
        MySqlDataReader^ reader;
        dbConn->Open();
        reader = dbCmd->ExecuteReader();
        for (int i = 0; reader->Read(); i++) {
            tariffs[i].name = msclr::interop::marshal_as<std::string>(reader->GetString(0));
            tariffs[i].rate = (reader->GetDouble(1));
            tariffs[i].discount = (reader->GetDouble(2)/100);
        }
        dbConn->Close();
    }

    int Company::cheapest_Tariff() {
        double min = tariffs[0].rate * (1 - tariffs[0].discount);
        int k = 0;
        for (int i = 0; i < 4; i++) {
            if (tariffs[i].rate != 0) {
                if (min > tariffs[i].rate * (1 - tariffs[i].discount)) {
                    min = tariffs[i].rate * (1 - tariffs[i].discount);
                    k = i;
                }
            }
        }
        cout << "\nCheapest tariff: \n" << k + 1 << ". " << tariffs[k].name << endl;
        cout << "Rate: " << tariffs[k].rate << endl;
        cout << "Discount: " << tariffs[k].discount * 100 << "%" << endl << endl;
        return (k);
    }
    void Company::output_tariffs() {
        for (int i = 0; i < 5; i++) {
            if (tariffs[i].name != "")
                cout << i + 1 << ". " << tariffs[i].name << endl;
        }
    }

    Company::~Company()
    { }
    Company& Company::operator=(Company const&)
    {
        return(getInstance());
    }
