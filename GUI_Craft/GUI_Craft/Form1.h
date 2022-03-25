#pragma once

#include "pch.h"
#include <list>

namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		Table <3, 3>* crafting;
		Table <3, 9>* inventory;
		libitem* lib;
		void updateInventory(libitem li);
		void tokenize(string const& str, const char delim, std::vector<string>& out);
		void RefreshGUI();
		bool checkSlotInventory(int i, int j);
		bool checkSlotCrafting(int i, int j);
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
	private: System::Windows::Forms::Button^ Carft;


		   RecipeList* rList;
	public:
		Form1(void)
		{
			lib = new libitem();
			rList = new RecipeList();
			*lib << "../../config/item.txt";
			*rList << "../../config/Recipe";
			crafting = new Table<3, 3>();
			inventory = new Table<3, 9>();
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
			delete lib;
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ Inventory1;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::Panel^ panel15;
	private: System::Windows::Forms::Panel^ panel16;
	private: System::Windows::Forms::Panel^ panel17;
	private: System::Windows::Forms::Panel^ panel18;
	private: System::Windows::Forms::Panel^ panel19;
	private: System::Windows::Forms::Panel^ panel20;
	private: System::Windows::Forms::Panel^ panel21;
	private: System::Windows::Forms::Panel^ panel22;
	private: System::Windows::Forms::Panel^ panel23;
	private: System::Windows::Forms::Panel^ panel24;
	private: System::Windows::Forms::Panel^ panel25;
	private: System::Windows::Forms::Panel^ panel26;
	private: System::Windows::Forms::Label^ I0;
	private: System::Windows::Forms::Label^ I17;



	private: System::Windows::Forms::Label^ I16;


	private: System::Windows::Forms::Label^ I15;

	private: System::Windows::Forms::Label^ I14;

	private: System::Windows::Forms::Label^ I13;

	private: System::Windows::Forms::Label^ I12;


	private: System::Windows::Forms::Label^ I11;


	private: System::Windows::Forms::Label^ I10;

	private: System::Windows::Forms::Label^ I9;
	private: System::Windows::Forms::Label^ I26;



	private: System::Windows::Forms::Label^ I25;

	private: System::Windows::Forms::Label^ I24;


	private: System::Windows::Forms::Label^ I23;

	private: System::Windows::Forms::Label^ I22;

	private: System::Windows::Forms::Label^ I21;

	private: System::Windows::Forms::Label^ I20;

	private: System::Windows::Forms::Label^ I19;

	private: System::Windows::Forms::Label^ I18;

	private: System::Windows::Forms::Panel^ panel27;
	private: System::Windows::Forms::Label^ C8;


	private: System::Windows::Forms::Panel^ panel28;
	private: System::Windows::Forms::Label^ C7;

	private: System::Windows::Forms::Panel^ panel29;
	private: System::Windows::Forms::Label^ C5;


	private: System::Windows::Forms::Panel^ panel30;
private: System::Windows::Forms::Label^ C6;


	private: System::Windows::Forms::Panel^ panel31;
private: System::Windows::Forms::Label^ C4;

	private: System::Windows::Forms::Panel^ panel32;
private: System::Windows::Forms::Label^ C3;


	private: System::Windows::Forms::Panel^ panel33;
private: System::Windows::Forms::Label^ C2;


	private: System::Windows::Forms::Panel^ panel34;
private: System::Windows::Forms::Label^ C1;

	private: System::Windows::Forms::Panel^ panel35;
private: System::Windows::Forms::Label^ C0;

	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ I8;


	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ I7;


	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ I6;


	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ I5;


	private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::Label^ I4;


	private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Label^ I3;


	private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Label^ I2;


	private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Label^ I1;


	private: System::Windows::Forms::Button^ button1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Inventory1 = (gcnew System::Windows::Forms::Panel());
			this->I0 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->I17 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->I16 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->I15 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->I14 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->I13 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->I12 = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->I11 = (gcnew System::Windows::Forms::Label());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->I10 = (gcnew System::Windows::Forms::Label());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->I9 = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->I26 = (gcnew System::Windows::Forms::Label());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->I25 = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->I24 = (gcnew System::Windows::Forms::Label());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->I23 = (gcnew System::Windows::Forms::Label());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->I22 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->I21 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->I20 = (gcnew System::Windows::Forms::Label());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->I19 = (gcnew System::Windows::Forms::Label());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->I18 = (gcnew System::Windows::Forms::Label());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->C8 = (gcnew System::Windows::Forms::Label());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->C7 = (gcnew System::Windows::Forms::Label());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->C5 = (gcnew System::Windows::Forms::Label());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->C6 = (gcnew System::Windows::Forms::Label());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->C4 = (gcnew System::Windows::Forms::Label());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->C3 = (gcnew System::Windows::Forms::Label());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->C2 = (gcnew System::Windows::Forms::Label());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->C1 = (gcnew System::Windows::Forms::Label());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->C0 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->I8 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->I7 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->I6 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->I5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->I4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->I3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->I2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->I1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Carft = (gcnew System::Windows::Forms::Button());
			this->Inventory1->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel31->SuspendLayout();
			this->panel32->SuspendLayout();
			this->panel33->SuspendLayout();
			this->panel34->SuspendLayout();
			this->panel35->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1108, 394);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(448, 20);
			this->textBox1->TabIndex = 0;
			// 
			// Inventory1
			// 
			this->Inventory1->Controls->Add(this->I0);
			this->Inventory1->Location = System::Drawing::Point(36, 394);
			this->Inventory1->Name = L"Inventory1";
			this->Inventory1->Size = System::Drawing::Size(100, 100);
			this->Inventory1->TabIndex = 1;
			// 
			// I0
			// 
			this->I0->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I0->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I0->Location = System::Drawing::Point(0, 0);
			this->I0->Name = L"I0";
			this->I0->Size = System::Drawing::Size(100, 100);
			this->I0->TabIndex = 0;
			this->I0->Text = L"I0";
			this->I0->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->I17);
			this->panel9->Location = System::Drawing::Point(884, 500);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(100, 100);
			this->panel9->TabIndex = 12;
			// 
			// I17
			// 
			this->I17->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I17->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I17->Location = System::Drawing::Point(0, 0);
			this->I17->Name = L"I17";
			this->I17->Size = System::Drawing::Size(100, 100);
			this->I17->TabIndex = 2;
			this->I17->Text = L"I17";
			this->I17->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->I16);
			this->panel10->Location = System::Drawing::Point(778, 500);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(100, 100);
			this->panel10->TabIndex = 5;
			// 
			// I16
			// 
			this->I16->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I16->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I16->Location = System::Drawing::Point(0, 0);
			this->I16->Name = L"I16";
			this->I16->Size = System::Drawing::Size(100, 100);
			this->I16->TabIndex = 2;
			this->I16->Text = L"I16";
			this->I16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->I15);
			this->panel11->Location = System::Drawing::Point(672, 500);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(100, 100);
			this->panel11->TabIndex = 6;
			// 
			// I15
			// 
			this->I15->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I15->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I15->Location = System::Drawing::Point(0, 0);
			this->I15->Name = L"I15";
			this->I15->Size = System::Drawing::Size(100, 100);
			this->I15->TabIndex = 2;
			this->I15->Text = L"I15";
			this->I15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->I14);
			this->panel12->Location = System::Drawing::Point(566, 500);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(100, 100);
			this->panel12->TabIndex = 7;
			// 
			// I14
			// 
			this->I14->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I14->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I14->Location = System::Drawing::Point(0, 0);
			this->I14->Name = L"I14";
			this->I14->Size = System::Drawing::Size(100, 100);
			this->I14->TabIndex = 2;
			this->I14->Text = L"I14";
			this->I14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->I13);
			this->panel13->Location = System::Drawing::Point(460, 500);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(100, 100);
			this->panel13->TabIndex = 8;
			// 
			// I13
			// 
			this->I13->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I13->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I13->Location = System::Drawing::Point(0, 0);
			this->I13->Name = L"I13";
			this->I13->Size = System::Drawing::Size(100, 100);
			this->I13->TabIndex = 2;
			this->I13->Text = L"I13";
			this->I13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->I12);
			this->panel14->Location = System::Drawing::Point(354, 500);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(100, 100);
			this->panel14->TabIndex = 9;
			// 
			// I12
			// 
			this->I12->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I12->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I12->Location = System::Drawing::Point(0, 0);
			this->I12->Name = L"I12";
			this->I12->Size = System::Drawing::Size(100, 100);
			this->I12->TabIndex = 2;
			this->I12->Text = L"I12";
			this->I12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel15
			// 
			this->panel15->Controls->Add(this->I11);
			this->panel15->Location = System::Drawing::Point(248, 500);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(100, 100);
			this->panel15->TabIndex = 10;
			// 
			// I11
			// 
			this->I11->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I11->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I11->Location = System::Drawing::Point(0, 0);
			this->I11->Name = L"I11";
			this->I11->Size = System::Drawing::Size(100, 100);
			this->I11->TabIndex = 2;
			this->I11->Text = L"I11";
			this->I11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->I10);
			this->panel16->Location = System::Drawing::Point(142, 500);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(100, 100);
			this->panel16->TabIndex = 11;
			// 
			// I10
			// 
			this->I10->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I10->Location = System::Drawing::Point(0, 0);
			this->I10->Name = L"I10";
			this->I10->Size = System::Drawing::Size(100, 100);
			this->I10->TabIndex = 1;
			this->I10->Text = L"I10";
			this->I10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel17
			// 
			this->panel17->Controls->Add(this->I9);
			this->panel17->Location = System::Drawing::Point(36, 500);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(100, 100);
			this->panel17->TabIndex = 4;
			// 
			// I9
			// 
			this->I9->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I9->Location = System::Drawing::Point(0, 0);
			this->I9->Name = L"I9";
			this->I9->Size = System::Drawing::Size(100, 100);
			this->I9->TabIndex = 2;
			this->I9->Text = L"I9";
			this->I9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel18
			// 
			this->panel18->Controls->Add(this->I26);
			this->panel18->Location = System::Drawing::Point(884, 606);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(100, 100);
			this->panel18->TabIndex = 12;
			// 
			// I26
			// 
			this->I26->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I26->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I26->Location = System::Drawing::Point(0, 0);
			this->I26->Name = L"I26";
			this->I26->Size = System::Drawing::Size(100, 100);
			this->I26->TabIndex = 3;
			this->I26->Text = L"I26";
			this->I26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel19
			// 
			this->panel19->Controls->Add(this->I25);
			this->panel19->Location = System::Drawing::Point(778, 606);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(100, 100);
			this->panel19->TabIndex = 5;
			// 
			// I25
			// 
			this->I25->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I25->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I25->Location = System::Drawing::Point(0, 0);
			this->I25->Name = L"I25";
			this->I25->Size = System::Drawing::Size(100, 100);
			this->I25->TabIndex = 3;
			this->I25->Text = L"I25";
			this->I25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel20
			// 
			this->panel20->Controls->Add(this->I24);
			this->panel20->Location = System::Drawing::Point(672, 606);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(100, 100);
			this->panel20->TabIndex = 6;
			// 
			// I24
			// 
			this->I24->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I24->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I24->Location = System::Drawing::Point(0, 0);
			this->I24->Name = L"I24";
			this->I24->Size = System::Drawing::Size(100, 100);
			this->I24->TabIndex = 3;
			this->I24->Text = L"I24";
			this->I24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel21
			// 
			this->panel21->Controls->Add(this->I23);
			this->panel21->Location = System::Drawing::Point(566, 606);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(100, 100);
			this->panel21->TabIndex = 7;
			// 
			// I23
			// 
			this->I23->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I23->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I23->Location = System::Drawing::Point(0, 0);
			this->I23->Name = L"I23";
			this->I23->Size = System::Drawing::Size(100, 100);
			this->I23->TabIndex = 3;
			this->I23->Text = L"I23";
			this->I23->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel22
			// 
			this->panel22->Controls->Add(this->I22);
			this->panel22->Location = System::Drawing::Point(460, 606);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(100, 100);
			this->panel22->TabIndex = 8;
			// 
			// I22
			// 
			this->I22->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I22->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I22->Location = System::Drawing::Point(0, 0);
			this->I22->Name = L"I22";
			this->I22->Size = System::Drawing::Size(100, 100);
			this->I22->TabIndex = 3;
			this->I22->Text = L"I22";
			this->I22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel23
			// 
			this->panel23->Controls->Add(this->I21);
			this->panel23->Location = System::Drawing::Point(354, 606);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(100, 100);
			this->panel23->TabIndex = 9;
			// 
			// I21
			// 
			this->I21->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I21->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I21->Location = System::Drawing::Point(0, 0);
			this->I21->Name = L"I21";
			this->I21->Size = System::Drawing::Size(100, 100);
			this->I21->TabIndex = 3;
			this->I21->Text = L"I21";
			this->I21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel24
			// 
			this->panel24->Controls->Add(this->I20);
			this->panel24->Location = System::Drawing::Point(248, 606);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(100, 100);
			this->panel24->TabIndex = 10;
			// 
			// I20
			// 
			this->I20->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I20->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I20->Location = System::Drawing::Point(0, 0);
			this->I20->Name = L"I20";
			this->I20->Size = System::Drawing::Size(100, 100);
			this->I20->TabIndex = 3;
			this->I20->Text = L"I20";
			this->I20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel25
			// 
			this->panel25->Controls->Add(this->I19);
			this->panel25->Location = System::Drawing::Point(142, 606);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(100, 100);
			this->panel25->TabIndex = 11;
			// 
			// I19
			// 
			this->I19->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I19->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I19->Location = System::Drawing::Point(0, 0);
			this->I19->Name = L"I19";
			this->I19->Size = System::Drawing::Size(100, 100);
			this->I19->TabIndex = 3;
			this->I19->Text = L"I19";
			this->I19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel26
			// 
			this->panel26->Controls->Add(this->I18);
			this->panel26->Location = System::Drawing::Point(36, 606);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(100, 100);
			this->panel26->TabIndex = 4;
			// 
			// I18
			// 
			this->I18->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I18->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I18->Location = System::Drawing::Point(0, 0);
			this->I18->Name = L"I18";
			this->I18->Size = System::Drawing::Size(100, 100);
			this->I18->TabIndex = 3;
			this->I18->Text = L"I18";
			this->I18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel27
			// 
			this->panel27->Controls->Add(this->C8);
			this->panel27->Location = System::Drawing::Point(566, 269);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(100, 100);
			this->panel27->TabIndex = 17;
			// 
			// C8
			// 
			this->C8->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C8->Location = System::Drawing::Point(0, 0);
			this->C8->Name = L"C8";
			this->C8->Size = System::Drawing::Size(100, 100);
			this->C8->TabIndex = 1;
			this->C8->Text = L"C8";
			this->C8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel28
			// 
			this->panel28->Controls->Add(this->C7);
			this->panel28->Location = System::Drawing::Point(460, 269);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(100, 100);
			this->panel28->TabIndex = 19;
			// 
			// C7
			// 
			this->C7->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C7->Location = System::Drawing::Point(0, 0);
			this->C7->Name = L"C7";
			this->C7->Size = System::Drawing::Size(100, 100);
			this->C7->TabIndex = 1;
			this->C7->Text = L"C7";
			this->C7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel29
			// 
			this->panel29->Controls->Add(this->C5);
			this->panel29->Location = System::Drawing::Point(566, 163);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(100, 100);
			this->panel29->TabIndex = 18;
			// 
			// C5
			// 
			this->C5->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C5->Location = System::Drawing::Point(0, 0);
			this->C5->Name = L"C5";
			this->C5->Size = System::Drawing::Size(100, 100);
			this->C5->TabIndex = 1;
			this->C5->Text = L"C5";
			this->C5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel30
			// 
			this->panel30->Controls->Add(this->C6);
			this->panel30->Location = System::Drawing::Point(354, 269);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(100, 100);
			this->panel30->TabIndex = 15;
			// 
			// C6
			// 
			this->C6->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C6->Location = System::Drawing::Point(0, 0);
			this->C6->Name = L"C6";
			this->C6->Size = System::Drawing::Size(100, 100);
			this->C6->TabIndex = 1;
			this->C6->Text = L"C6";
			this->C6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel31
			// 
			this->panel31->Controls->Add(this->C4);
			this->panel31->Location = System::Drawing::Point(460, 163);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(100, 100);
			this->panel31->TabIndex = 20;
			// 
			// C4
			// 
			this->C4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C4->Location = System::Drawing::Point(0, 0);
			this->C4->Name = L"C4";
			this->C4->Size = System::Drawing::Size(100, 100);
			this->C4->TabIndex = 1;
			this->C4->Text = L"C4";
			this->C4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel32
			// 
			this->panel32->Controls->Add(this->C3);
			this->panel32->Location = System::Drawing::Point(354, 163);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(100, 100);
			this->panel32->TabIndex = 16;
			// 
			// C3
			// 
			this->C3->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C3->Location = System::Drawing::Point(0, 0);
			this->C3->Name = L"C3";
			this->C3->Size = System::Drawing::Size(100, 100);
			this->C3->TabIndex = 1;
			this->C3->Text = L"C3";
			this->C3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel33
			// 
			this->panel33->Controls->Add(this->C2);
			this->panel33->Location = System::Drawing::Point(566, 57);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(100, 100);
			this->panel33->TabIndex = 13;
			// 
			// C2
			// 
			this->C2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C2->Location = System::Drawing::Point(0, 0);
			this->C2->Name = L"C2";
			this->C2->Size = System::Drawing::Size(100, 100);
			this->C2->TabIndex = 1;
			this->C2->Text = L"C2";
			this->C2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel34
			// 
			this->panel34->Controls->Add(this->C1);
			this->panel34->Location = System::Drawing::Point(460, 57);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(100, 100);
			this->panel34->TabIndex = 14;
			// 
			// C1
			// 
			this->C1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C1->Location = System::Drawing::Point(0, 0);
			this->C1->Name = L"C1";
			this->C1->Size = System::Drawing::Size(100, 100);
			this->C1->TabIndex = 1;
			this->C1->Text = L"C1";
			this->C1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel35
			// 
			this->panel35->Controls->Add(this->C0);
			this->panel35->Location = System::Drawing::Point(354, 57);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(100, 100);
			this->panel35->TabIndex = 12;
			// 
			// C0
			// 
			this->C0->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->C0->Dock = System::Windows::Forms::DockStyle::Fill;
			this->C0->Location = System::Drawing::Point(0, 0);
			this->C0->Name = L"C0";
			this->C0->Size = System::Drawing::Size(100, 100);
			this->C0->TabIndex = 1;
			this->C0->Text = L"C0";
			this->C0->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->I8);
			this->panel8->Location = System::Drawing::Point(884, 394);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(100, 100);
			this->panel8->TabIndex = 3;
			// 
			// I8
			// 
			this->I8->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I8->Location = System::Drawing::Point(0, 0);
			this->I8->Name = L"I8";
			this->I8->Size = System::Drawing::Size(100, 100);
			this->I8->TabIndex = 1;
			this->I8->Text = L"I8";
			this->I8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->I7);
			this->panel7->Location = System::Drawing::Point(778, 394);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(100, 100);
			this->panel7->TabIndex = 2;
			// 
			// I7
			// 
			this->I7->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I7->Location = System::Drawing::Point(0, 0);
			this->I7->Name = L"I7";
			this->I7->Size = System::Drawing::Size(100, 100);
			this->I7->TabIndex = 1;
			this->I7->Text = L"I7";
			this->I7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->I6);
			this->panel6->Location = System::Drawing::Point(672, 394);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(100, 100);
			this->panel6->TabIndex = 2;
			// 
			// I6
			// 
			this->I6->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I6->Location = System::Drawing::Point(0, 0);
			this->I6->Name = L"I6";
			this->I6->Size = System::Drawing::Size(100, 100);
			this->I6->TabIndex = 1;
			this->I6->Text = L"I6";
			this->I6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->I5);
			this->panel5->Location = System::Drawing::Point(566, 394);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(100, 100);
			this->panel5->TabIndex = 2;
			// 
			// I5
			// 
			this->I5->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I5->Location = System::Drawing::Point(0, 0);
			this->I5->Name = L"I5";
			this->I5->Size = System::Drawing::Size(100, 100);
			this->I5->TabIndex = 1;
			this->I5->Text = L"I5";
			this->I5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->I4);
			this->panel4->Location = System::Drawing::Point(460, 394);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(100, 100);
			this->panel4->TabIndex = 2;
			// 
			// I4
			// 
			this->I4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I4->Location = System::Drawing::Point(0, 0);
			this->I4->Name = L"I4";
			this->I4->Size = System::Drawing::Size(100, 100);
			this->I4->TabIndex = 1;
			this->I4->Text = L"I4";
			this->I4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->I3);
			this->panel3->Location = System::Drawing::Point(354, 394);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(100, 100);
			this->panel3->TabIndex = 2;
			// 
			// I3
			// 
			this->I3->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I3->Location = System::Drawing::Point(0, 0);
			this->I3->Name = L"I3";
			this->I3->Size = System::Drawing::Size(100, 100);
			this->I3->TabIndex = 1;
			this->I3->Text = L"I3";
			this->I3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->I2);
			this->panel2->Location = System::Drawing::Point(248, 394);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(100, 100);
			this->panel2->TabIndex = 2;
			// 
			// I2
			// 
			this->I2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I2->Location = System::Drawing::Point(0, 0);
			this->I2->Name = L"I2";
			this->I2->Size = System::Drawing::Size(100, 100);
			this->I2->TabIndex = 1;
			this->I2->Text = L"I2";
			this->I2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->I1);
			this->panel1->Location = System::Drawing::Point(142, 394);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(100, 100);
			this->panel1->TabIndex = 2;
			// 
			// I1
			// 
			this->I1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->I1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->I1->Location = System::Drawing::Point(0, 0);
			this->I1->Name = L"I1";
			this->I1->Size = System::Drawing::Size(100, 100);
			this->I1->TabIndex = 1;
			this->I1->Text = L"I1";
			this->I1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1572, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Carft
			// 
			this->Carft->Location = System::Drawing::Point(781, 202);
			this->Carft->Name = L"Carft";
			this->Carft->Size = System::Drawing::Size(75, 23);
			this->Carft->TabIndex = 22;
			this->Carft->Text = L"Carft";
			this->Carft->UseVisualStyleBackColor = true;
			this->Carft->Click += gcnew System::EventHandler(this, &Form1::Carft_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1709, 783);
			this->Controls->Add(this->Carft);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel27);
			this->Controls->Add(this->panel18);
			this->Controls->Add(this->panel28);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel29);
			this->Controls->Add(this->panel19);
			this->Controls->Add(this->panel30);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel31);
			this->Controls->Add(this->panel20);
			this->Controls->Add(this->panel32);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel33);
			this->Controls->Add(this->panel21);
			this->Controls->Add(this->panel34);
			this->Controls->Add(this->panel35);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel22);
			this->Controls->Add(this->panel13);
			this->Controls->Add(this->panel23);
			this->Controls->Add(this->panel14);
			this->Controls->Add(this->panel24);
			this->Controls->Add(this->panel25);
			this->Controls->Add(this->panel15);
			this->Controls->Add(this->panel26);
			this->Controls->Add(this->panel16);
			this->Controls->Add(this->panel17);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Inventory1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Inventory1->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->panel13->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->panel16->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel22->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel24->ResumeLayout(false);
			this->panel25->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel27->ResumeLayout(false);
			this->panel28->ResumeLayout(false);
			this->panel29->ResumeLayout(false);
			this->panel30->ResumeLayout(false);
			this->panel31->ResumeLayout(false);
			this->panel32->ResumeLayout(false);
			this->panel33->ResumeLayout(false);
			this->panel34->ResumeLayout(false);
			this->panel35->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string input;
		MarshalString(this->textBox1->Text, input);

		vector<string> tokenized_input;
		tokenize(input, ' ', tokenized_input);
		if (tokenized_input.front() == "GIVE") {
			vector<string>::iterator i = tokenized_input.begin() + 1;
			string itemName = *i;

			i = tokenized_input.begin() + 2;
			int itemQty = stoi(*i);
			Give give(itemName, itemQty);
			give.Execute(inventory, *lib);
		}
		else if (tokenized_input.front() == "DISCARD") {
			vector<string>::iterator i = tokenized_input.begin() + 1;
			string InvID = *i;

			i = tokenized_input.begin() + 2;
			int itemQty = stoi(*i);
			Discard discard(InvID, itemQty);
			discard.Execute(inventory);
		}
		else if (tokenized_input.front() == "MOVE") {
			vector<string> dest;
			vector<string>::iterator i = tokenized_input.begin() + 1;
			string src = *i;

			i = tokenized_input.begin() + 2;
			int N = stoi(*i);

			for (int j = 3; j < N + 3; j++) {
				i = tokenized_input.begin() + j;
				dest.push_back(*i);
			}
			class::Move move(src, N, dest);
			move.Execute(inventory, crafting);
		}
		else if (tokenized_input.front() == "USE") {
			vector<string> dest;
			vector<string>::iterator i = tokenized_input.begin() + 1;
			string InvID = *i;
			Use use(InvID);
			use.Execute(inventory);
		}
		else if (tokenized_input.front() == "EXPORT") {
			vector<string> dest;
			vector<string>::iterator i = tokenized_input.begin() + 1;
			string fileName = *i;
			Export exp(fileName);
			exp.Execute(inventory);
		}
		
		RefreshGUI();
	}
	private: System::Void Carft_Click(System::Object^ sender, System::EventArgs^ e) {
		Craft craft;
		craft.Execute(crafting, inventory, *rList, *lib);

		RefreshGUI();
	}
};
}
