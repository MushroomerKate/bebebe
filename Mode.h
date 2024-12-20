#pragma once
#include <fstream>
#include <string>
#include"Function.h"
#include "Company.h"
#include <msclr\marshal_cppstd.h>
#include "CargoType.h"
#include "wDiscount.h"
#include "woDiscount.h"

using namespace std;

namespace Lab4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;


	/// <summary>
	/// Summary for UserMode
	/// </summary>
	public ref class Mode : public System::Windows::Forms::Form
	{
			Company& comp = Company::getInstance();
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ menu_item4;
	private: System::Windows::Forms::Button^ menu_item5;
		   int t = 0;
	public:
		Mode(void)
		{
			InitializeComponent();
		}
		Mode(int u)
		{
			InitializeComponent();
			UserMode(); 
			init();
			LoadDataF_base();
			comp.LoadData_base();
		}
		Mode(int a, int p)
		{
			InitializeComponent();
			AdminMode();
			LoadDataF_base();
			comp.LoadData_base();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Mode()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ModeLabel;
	protected:

	protected:


	private: System::Windows::Forms::FlowLayoutPanel^ menuCargoTypes;

	private: System::Windows::Forms::Button^ menu_header;

	private: System::Windows::Forms::Button^ menu_item1;

	private: System::Windows::Forms::Button^ menu_item2;

	private: System::Windows::Forms::Button^ menu_item3;
	private: System::Windows::Forms::Label^ label1;







	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ enterButton;

	private: System::Windows::Forms::Label^ outputLabel;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ModeLabel = (gcnew System::Windows::Forms::Label());
			this->menuCargoTypes = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menu_header = (gcnew System::Windows::Forms::Button());
			this->menu_item1 = (gcnew System::Windows::Forms::Button());
			this->menu_item2 = (gcnew System::Windows::Forms::Button());
			this->menu_item3 = (gcnew System::Windows::Forms::Button());
			this->menu_item4 = (gcnew System::Windows::Forms::Button());
			this->menu_item5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->enterButton = (gcnew System::Windows::Forms::Button());
			this->outputLabel = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->menuCargoTypes->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ModeLabel
			// 
			this->ModeLabel->AutoSize = true;
			this->ModeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ModeLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ModeLabel->Location = System::Drawing::Point(60, 25);
			this->ModeLabel->Name = L"ModeLabel";
			this->ModeLabel->Size = System::Drawing::Size(146, 31);
			this->ModeLabel->TabIndex = 0;
			this->ModeLabel->Text = L"User Mode";
			// 
			// menuCargoTypes
			// 
			this->menuCargoTypes->Controls->Add(this->menu_header);
			this->menuCargoTypes->Controls->Add(this->menu_item1);
			this->menuCargoTypes->Controls->Add(this->menu_item2);
			this->menuCargoTypes->Controls->Add(this->menu_item3);
			this->menuCargoTypes->Controls->Add(this->menu_item4);
			this->menuCargoTypes->Controls->Add(this->menu_item5);
			this->menuCargoTypes->Location = System::Drawing::Point(50, 75);
			this->menuCargoTypes->MaximumSize = System::Drawing::Size(315, 285);
			this->menuCargoTypes->MinimumSize = System::Drawing::Size(315, 50);
			this->menuCargoTypes->Name = L"menuCargoTypes";
			this->menuCargoTypes->Size = System::Drawing::Size(315, 50);
			this->menuCargoTypes->TabIndex = 2;
			// 
			// menu_header
			// 
			this->menu_header->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_header->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_header->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_header->Location = System::Drawing::Point(3, 3);
			this->menu_header->Name = L"menu_header";
			this->menu_header->Size = System::Drawing::Size(309, 41);
			this->menu_header->TabIndex = 0;
			this->menu_header->Text = L"Choose cargo type";
			this->menu_header->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_header->UseVisualStyleBackColor = true;
			this->menu_header->Click += gcnew System::EventHandler(this, &Mode::button1_Click);
			// 
			// menu_item1
			// 
			this->menu_item1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_item1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_item1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_item1->Location = System::Drawing::Point(3, 50);
			this->menu_item1->Name = L"menu_item1";
			this->menu_item1->Size = System::Drawing::Size(309, 41);
			this->menu_item1->TabIndex = 1;
			this->menu_item1->Text = L"Choose cargo type";
			this->menu_item1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_item1->UseVisualStyleBackColor = true;
			this->menu_item1->Click += gcnew System::EventHandler(this, &Mode::menu_item1_Click);
			// 
			// menu_item2
			// 
			this->menu_item2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_item2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_item2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_item2->Location = System::Drawing::Point(3, 97);
			this->menu_item2->Name = L"menu_item2";
			this->menu_item2->Size = System::Drawing::Size(309, 41);
			this->menu_item2->TabIndex = 2;
			this->menu_item2->Text = L"Choose cargo type";
			this->menu_item2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_item2->UseVisualStyleBackColor = true;
			this->menu_item2->Click += gcnew System::EventHandler(this, &Mode::menu_item2_Click);
			// 
			// menu_item3
			// 
			this->menu_item3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_item3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_item3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_item3->Location = System::Drawing::Point(3, 144);
			this->menu_item3->Name = L"menu_item3";
			this->menu_item3->Size = System::Drawing::Size(309, 41);
			this->menu_item3->TabIndex = 3;
			this->menu_item3->Text = L"Choose cargo type";
			this->menu_item3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_item3->UseVisualStyleBackColor = true;
			this->menu_item3->Click += gcnew System::EventHandler(this, &Mode::menu_item3_Click);
			// 
			// menu_item4
			// 
			this->menu_item4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_item4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_item4->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_item4->Location = System::Drawing::Point(3, 191);
			this->menu_item4->Name = L"menu_item4";
			this->menu_item4->Size = System::Drawing::Size(309, 41);
			this->menu_item4->TabIndex = 4;
			this->menu_item4->Text = L"Choose cargo type";
			this->menu_item4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_item4->UseVisualStyleBackColor = true;
			this->menu_item4->Click += gcnew System::EventHandler(this, &Mode::menu_item4_Click);
			// 
			// menu_item5
			// 
			this->menu_item5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->menu_item5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menu_item5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->menu_item5->Location = System::Drawing::Point(3, 238);
			this->menu_item5->Name = L"menu_item5";
			this->menu_item5->Size = System::Drawing::Size(309, 41);
			this->menu_item5->TabIndex = 5;
			this->menu_item5->Text = L"Choose cargo type";
			this->menu_item5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->menu_item5->UseVisualStyleBackColor = true;
			this->menu_item5->Click += gcnew System::EventHandler(this, &Mode::menu_item5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->label1->Location = System::Drawing::Point(60, 391);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(301, 31);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter cargo mass (kg)";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(50, 438);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(317, 38);
			this->textBox1->TabIndex = 4;
			// 
			// enterButton
			// 
			this->enterButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->enterButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->enterButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->enterButton->FlatAppearance->BorderSize = 0;
			this->enterButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkGray;
			this->enterButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Silver;
			this->enterButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->enterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->enterButton->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->enterButton->Location = System::Drawing::Point(765, 467);
			this->enterButton->Name = L"enterButton";
			this->enterButton->Size = System::Drawing::Size(324, 66);
			this->enterButton->TabIndex = 5;
			this->enterButton->Text = L"Calculate cost";
			this->enterButton->UseVisualStyleBackColor = false;
			this->enterButton->Click += gcnew System::EventHandler(this, &Mode::button5_Click);
			// 
			// outputLabel
			// 
			this->outputLabel->AutoSize = true;
			this->outputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->outputLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->outputLabel->Location = System::Drawing::Point(3, 0);
			this->outputLabel->Name = L"outputLabel";
			this->outputLabel->Size = System::Drawing::Size(0, 31);
			this->outputLabel->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(50, 549);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(317, 38);
			this->textBox2->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->label2->Location = System::Drawing::Point(60, 502);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(255, 31);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Enter discount (%)";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox3->Location = System::Drawing::Point(442, 278);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(317, 38);
			this->textBox3->TabIndex = 10;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Mode::textBox3_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->label3->Location = System::Drawing::Point(452, 231);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(231, 31);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Enter tariff name";
			this->label3->Click += gcnew System::EventHandler(this, &Mode::label3_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->outputLabel);
			this->flowLayoutPanel1->Location = System::Drawing::Point(744, 25);
			this->flowLayoutPanel1->MaximumSize = System::Drawing::Size(715, 351);
			this->flowLayoutPanel1->MinimumSize = System::Drawing::Size(339, 351);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(339, 351);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// Mode
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1194, 611);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->enterButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuCargoTypes);
			this->Controls->Add(this->ModeLabel);
			this->Name = L"Mode";
			this->Text = L"UserMode";
			this->Load += gcnew System::EventHandler(this, &Mode::Mode_Load);
			this->menuCargoTypes->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void  UserMode() {
			this->outputLabel->Size = this->outputLabel->MaximumSize;
			this->ModeLabel->Text = "User Mode";
			this->menuCargoTypes->Show();
			this->label1->Text = L"Enter cargo mass (kg)";
			this->enterButton->Text = L"Calculate cost";

			this->label2->Hide();
			this->label3->Hide();
			this->textBox2->Hide();
			this->textBox3->Hide();
		}

		void  AdminMode() {
			this->outputLabel->Size = this->outputLabel->MinimumSize;
			this->ModeLabel->Text = "Admin Mode";
			this->menuCargoTypes->Hide();
			this->label1->Text = L"Enter tariff rate ($)";
			this->enterButton->Text = L"Add this tariff";

			this->label2->Show();
			this->label3->Show();
			this->textBox2->Show();
			this->textBox3->Show();

		}

		void init() {
			this->menu_item1->Hide();
			this->menu_item2->Hide();
			this->menu_item3->Hide();
			this->menu_item4->Hide();
			this->menu_item5->Hide();
		}

		void LoadDataF() {
			ifstream file("Data.txt");
			string str, n;
			if (getline(file, str) && (lineName(str) != "")) {
				this->menu_item1->Show();
				n = lineName(str);
				String^ s = gcnew String(n.data());
				this->menu_item1->Text = s;
				if (getline(file, str) && (lineName(str) != "")) {
					this->menu_item2->Show();
					n = lineName(str);
					s = gcnew String(n.data());
					this->menu_item2->Text = s;
					if (getline(file, str) && (lineName(str) != "")) {
						this->menu_item3->Show();
						n = lineName(str);
						s = gcnew String(n.data());
						this->menu_item3->Text = s;
						if (getline(file, str) && (lineName(str) != "")) {
							this->menu_item4->Show();
							n = lineName(str);
							s = gcnew String(n.data());
							this->menu_item4->Text = s;
							if (getline(file, str) && (lineName(str) != "")) {
								this->menu_item5->Show();
								n = lineName(str);
								s = gcnew String(n.data());
								this->menu_item5->Text = s;
							}
							else
								file.close();
						}
						else
							file.close();
					}
				}
				else
					file.close();
			}
			else
				file.close();
		}

		void UploadData() {
			ofstream file("Data.txt", ios::app);
			string n = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
			double r = Double::Parse(this->textBox1->Text), d = Double::Parse(this->textBox2->Text);
			file <<endl << n << " " << r << " " << d/100;
			file.close();
		}
		
		void LoadDataF_base() {
			MySqlConnection^ dbConn = gcnew MySqlConnection("Server=localhost; Database=new_schema; Uid=root; Pwd=Choochmeck112!;");
			MySqlCommand^ dbCmd = gcnew MySqlCommand("SELECT * FROM new_schema.new_table;", dbConn);
			MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(dbCmd);
			DataSet^ dataSet = gcnew DataSet();		
			MySqlDataReader^ reader;

			try {
			dbConn->Open();
			dataAdapter->Fill(dataSet);
			reader = dbCmd->ExecuteReader();
			/*while (reader->Read()) {
				this->outputLabel->Text += (reader->GetString(0));
			}*/

			if (reader->Read()) {
				this->menu_item1->Show();
				this->menu_item1->Text = (reader->GetString(0));
				if (reader->Read()) {
					this->menu_item2->Show();
					this->menu_item2->Text = (reader->GetString(0));
					if (reader->Read()) {
						this->menu_item3->Show();
						this->menu_item3->Text = (reader->GetString(0));
						if (reader->Read()) {
							this->menu_item4->Show();
							this->menu_item4->Text = (reader->GetString(0));
							if (reader->Read()) {
								this->menu_item5->Show();
								this->menu_item5->Text = (reader->GetString(0));
							}
							else
								dbConn->Close();
						}
						else
							dbConn->Close();
					}
				}
				else
					dbConn->Close();
			}
			else
				dbConn->Close();

			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

		void UploadData_base() {
			MySqlConnection^ dbConn = gcnew MySqlConnection("Server=localhost; Database=new_schema; Uid=root; Pwd=Choochmeck112!;");
			MySqlCommand^ dbCmd = gcnew MySqlCommand("insert into new_schema.new_table (TariffName,Rate,Discount) values('" + this->textBox3->Text + "','"+ this->textBox1->Text +"','"+ this->textBox2->Text +"');", dbConn);
			MySqlDataAdapter^ dataAdapter = gcnew MySqlDataAdapter(dbCmd);
			DataSet^ dataSet = gcnew DataSet();
			MySqlDataReader^ reader;

			try {
				dbConn->Open();
				dataAdapter->Fill(dataSet);
				reader = dbCmd->ExecuteReader();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}

#pragma endregion
	private: System::Void Mode_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void menuCargoTypes_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//
//	if (flowLayoutPanel1->Size == flowLayoutPanel1->MaximumSize)
//		flowLayoutPanel1->Size = flowLayoutPanel1->MinimumSize;
//	else
//		flowLayoutPanel1->Size = flowLayoutPanel1->MaximumSize;
//}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
		if (this->menuCargoTypes->Size == this->menuCargoTypes->MaximumSize)
			this->menuCargoTypes->Size = this->menuCargoTypes->MinimumSize;
		else
			this->menuCargoTypes->Size = this->menuCargoTypes->MaximumSize;

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->ModeLabel->Text == "Admin Mode") {
	string n = msclr::interop::marshal_as<std::string>(this->textBox3->Text);
	double r = Double::Parse(this->textBox1->Text), d = Double::Parse(this->textBox2->Text);
	if (d > 100) {
		this->outputLabel->Text = "Discount cannot exceed 100%";
	}
	else {
	String^ t = gcnew String (("Tariff set to " + n + " " + to_string(r) + " " + to_string(d) + " discount").data());
	this->outputLabel->Text = t;
	UploadData_base();
	}
	}
	if (this->ModeLabel->Text == "User Mode") {
		double mass = Double::Parse(this->textBox1->Text);
		string tx="";
		CargoType type(make_unique<woDiscount>());
		//"\nCost without discount: ";
		tx += "Cost without discount: " + to_string(type.calculate_cost(mass, t, comp));
		tx += "Discount: " + to_string(comp.tariffs[t].discount * 100) + "%";
		//"Cost with discount: ";
		type.set_strategy(make_unique<wDiscount>());
		tx += "Cost with discount: " + to_string(type.calculate_cost(mass, t, comp));
		String^ txt = gcnew String((tx).data());
		this->outputLabel->Text = txt;
	}
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void menu_item1_Click(System::Object^ sender, System::EventArgs^ e) {
	t = 0;
	String^ txt = gcnew String(("Tariff set to 1. "+comp.tariffs[0].name).data());
	this->outputLabel->Text = txt;
}
private: System::Void menu_item2_Click(System::Object^ sender, System::EventArgs^ e) {
	t = 1;
	String^ txt = gcnew String(("Tariff set to 2. " + comp.tariffs[1].name).data());
	this->outputLabel->Text = txt;
}
private: System::Void menu_item3_Click(System::Object^ sender, System::EventArgs^ e) {
	t = 2;
	String^ txt = gcnew String(("Tariff set to 3. " + comp.tariffs[2].name).data());
	this->outputLabel->Text = txt;
}
private: System::Void menu_item4_Click(System::Object^ sender, System::EventArgs^ e) {
	t = 3;
	String^ txt = gcnew String(("Tariff set to 4. " + comp.tariffs[3].name).data());
	this->outputLabel->Text = txt;
}
private: System::Void menu_item5_Click(System::Object^ sender, System::EventArgs^ e) {
	t = 4;
	String^ txt = gcnew String(("Tariff set to 5. " + comp.tariffs[4].name).data());
	this->outputLabel->Text = txt;
}
};
}
