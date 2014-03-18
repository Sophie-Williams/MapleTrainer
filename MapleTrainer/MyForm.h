#pragma once
#include <windows.h>

namespace MyDllApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	protected: 
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  MOUSEX_VAL;
	private: System::Windows::Forms::Label^  MOUSEY_VAL;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  HP_VAL;
	private: System::Windows::Forms::Label^  MOBCOUNT_VAL;
	private: System::Windows::Forms::Label^  MAPID_VAL;
	private: System::Windows::Forms::Label^  WORLDID_VAL;
	private: System::Windows::Forms::Label^  CHANNEL_VAL;
	private: System::Windows::Forms::Label^  PEOPLECOUNT_VAL;
	private: System::Windows::Forms::Label^  ITEMCOUNT_VAL;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  CHARY_VAL;
	private: System::Windows::Forms::Label^  CHARX_VAL;
	private: System::Windows::Forms::Label^  ATTACKCOUNT_VAL;
	private: System::Windows::Forms::Label^  BREATH_VAL;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  MP_VAL;
	private: System::Windows::Forms::Label^  MP_LABEL;
	private: System::Windows::Forms::Label^  HP_LABEL;
	private: System::Windows::Forms::CheckBox^  MOUSE_TELE;
	private: System::Windows::Forms::Label^  MOUSEANIM_VAL;
	private: System::Windows::Forms::CheckBox^  KAMI_TOGGLE;
	private: System::Windows::Forms::Label^  TEST_LABEL;




















































	private: System::Windows::Forms::Button^  button1;

	private:
         void onButton1Click(System::Object^  sender, System::EventArgs^  e);
		 void onTimer1 (System::Object^  sender, System::EventArgs^  e);
		 void mouseTeleChangedCheck(System::Object^  sender, System::EventArgs^  e);
		 void kamiChanged(System::Object^  sender, System::EventArgs^  e);

	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->MOUSEX_VAL = (gcnew System::Windows::Forms::Label());
			this->MOUSEY_VAL = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->HP_VAL = (gcnew System::Windows::Forms::Label());
			this->MOBCOUNT_VAL = (gcnew System::Windows::Forms::Label());
			this->MAPID_VAL = (gcnew System::Windows::Forms::Label());
			this->WORLDID_VAL = (gcnew System::Windows::Forms::Label());
			this->CHANNEL_VAL = (gcnew System::Windows::Forms::Label());
			this->PEOPLECOUNT_VAL = (gcnew System::Windows::Forms::Label());
			this->ITEMCOUNT_VAL = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->CHARY_VAL = (gcnew System::Windows::Forms::Label());
			this->CHARX_VAL = (gcnew System::Windows::Forms::Label());
			this->ATTACKCOUNT_VAL = (gcnew System::Windows::Forms::Label());
			this->BREATH_VAL = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MP_VAL = (gcnew System::Windows::Forms::Label());
			this->MP_LABEL = (gcnew System::Windows::Forms::Label());
			this->HP_LABEL = (gcnew System::Windows::Forms::Label());
			this->MOUSE_TELE = (gcnew System::Windows::Forms::CheckBox());
			this->MOUSEANIM_VAL = (gcnew System::Windows::Forms::Label());
			this->KAMI_TOGGLE = (gcnew System::Windows::Forms::CheckBox());
			this->TEST_LABEL = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(57, 587);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Kill Process";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::onButton1Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::onTimer1);
			// 
			// MOUSEX_VAL
			// 
			this->MOUSEX_VAL->AutoSize = true;
			this->MOUSEX_VAL->Location = System::Drawing::Point(132, 106);
			this->MOUSEX_VAL->Name = L"MOUSEX_VAL";
			this->MOUSEX_VAL->Size = System::Drawing::Size(10, 13);
			this->MOUSEX_VAL->TabIndex = 68;
			this->MOUSEX_VAL->Text = L"-";
			// 
			// MOUSEY_VAL
			// 
			this->MOUSEY_VAL->AutoSize = true;
			this->MOUSEY_VAL->Location = System::Drawing::Point(132, 119);
			this->MOUSEY_VAL->Name = L"MOUSEY_VAL";
			this->MOUSEY_VAL->Size = System::Drawing::Size(10, 13);
			this->MOUSEY_VAL->TabIndex = 67;
			this->MOUSEY_VAL->Text = L"-";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(26, 106);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(52, 13);
			this->label14->TabIndex = 66;
			this->label14->Text = L"Mouse X:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(26, 119);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(52, 13);
			this->label13->TabIndex = 65;
			this->label13->Text = L"Mouse Y:";
			// 
			// HP_VAL
			// 
			this->HP_VAL->AutoSize = true;
			this->HP_VAL->Location = System::Drawing::Point(132, 28);
			this->HP_VAL->Name = L"HP_VAL";
			this->HP_VAL->Size = System::Drawing::Size(10, 13);
			this->HP_VAL->TabIndex = 64;
			this->HP_VAL->Text = L"-";
			// 
			// MOBCOUNT_VAL
			// 
			this->MOBCOUNT_VAL->AutoSize = true;
			this->MOBCOUNT_VAL->Location = System::Drawing::Point(132, 163);
			this->MOBCOUNT_VAL->Name = L"MOBCOUNT_VAL";
			this->MOBCOUNT_VAL->Size = System::Drawing::Size(10, 13);
			this->MOBCOUNT_VAL->TabIndex = 63;
			this->MOBCOUNT_VAL->Text = L"-";
			// 
			// MAPID_VAL
			// 
			this->MAPID_VAL->AutoSize = true;
			this->MAPID_VAL->Location = System::Drawing::Point(132, 176);
			this->MAPID_VAL->Name = L"MAPID_VAL";
			this->MAPID_VAL->Size = System::Drawing::Size(10, 13);
			this->MAPID_VAL->TabIndex = 62;
			this->MAPID_VAL->Text = L"-";
			// 
			// WORLDID_VAL
			// 
			this->WORLDID_VAL->AutoSize = true;
			this->WORLDID_VAL->Location = System::Drawing::Point(132, 189);
			this->WORLDID_VAL->Name = L"WORLDID_VAL";
			this->WORLDID_VAL->Size = System::Drawing::Size(10, 13);
			this->WORLDID_VAL->TabIndex = 61;
			this->WORLDID_VAL->Text = L"-";
			// 
			// CHANNEL_VAL
			// 
			this->CHANNEL_VAL->AutoSize = true;
			this->CHANNEL_VAL->Location = System::Drawing::Point(132, 202);
			this->CHANNEL_VAL->Name = L"CHANNEL_VAL";
			this->CHANNEL_VAL->Size = System::Drawing::Size(10, 13);
			this->CHANNEL_VAL->TabIndex = 60;
			this->CHANNEL_VAL->Text = L"-";
			// 
			// PEOPLECOUNT_VAL
			// 
			this->PEOPLECOUNT_VAL->AutoSize = true;
			this->PEOPLECOUNT_VAL->Location = System::Drawing::Point(132, 215);
			this->PEOPLECOUNT_VAL->Name = L"PEOPLECOUNT_VAL";
			this->PEOPLECOUNT_VAL->Size = System::Drawing::Size(10, 13);
			this->PEOPLECOUNT_VAL->TabIndex = 59;
			this->PEOPLECOUNT_VAL->Text = L"-";
			// 
			// ITEMCOUNT_VAL
			// 
			this->ITEMCOUNT_VAL->AutoSize = true;
			this->ITEMCOUNT_VAL->Location = System::Drawing::Point(132, 228);
			this->ITEMCOUNT_VAL->Name = L"ITEMCOUNT_VAL";
			this->ITEMCOUNT_VAL->Size = System::Drawing::Size(10, 13);
			this->ITEMCOUNT_VAL->TabIndex = 58;
			this->ITEMCOUNT_VAL->Text = L"-";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(26, 163);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(62, 13);
			this->label12->TabIndex = 57;
			this->label12->Text = L"Mob Count:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(26, 176);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(45, 13);
			this->label11->TabIndex = 56;
			this->label11->Text = L"Map ID:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(26, 189);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 13);
			this->label10->TabIndex = 55;
			this->label10->Text = L"World ID:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(26, 202);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 54;
			this->label9->Text = L"Channel:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(26, 215);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 13);
			this->label8->TabIndex = 53;
			this->label8->Text = L"People Count:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(26, 228);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 52;
			this->label7->Text = L"Item Count:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 141);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 51;
			this->label4->Text = L"~Map Info~";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(54, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(88, 13);
			this->label6->TabIndex = 50;
			this->label6->Text = L"~Character Info~";
			// 
			// CHARY_VAL
			// 
			this->CHARY_VAL->AutoSize = true;
			this->CHARY_VAL->Location = System::Drawing::Point(132, 67);
			this->CHARY_VAL->Name = L"CHARY_VAL";
			this->CHARY_VAL->Size = System::Drawing::Size(10, 13);
			this->CHARY_VAL->TabIndex = 49;
			this->CHARY_VAL->Text = L"-";
			// 
			// CHARX_VAL
			// 
			this->CHARX_VAL->AutoSize = true;
			this->CHARX_VAL->Location = System::Drawing::Point(132, 54);
			this->CHARX_VAL->Name = L"CHARX_VAL";
			this->CHARX_VAL->Size = System::Drawing::Size(10, 13);
			this->CHARX_VAL->TabIndex = 48;
			this->CHARX_VAL->Text = L"-";
			// 
			// ATTACKCOUNT_VAL
			// 
			this->ATTACKCOUNT_VAL->AutoSize = true;
			this->ATTACKCOUNT_VAL->Location = System::Drawing::Point(132, 80);
			this->ATTACKCOUNT_VAL->Name = L"ATTACKCOUNT_VAL";
			this->ATTACKCOUNT_VAL->Size = System::Drawing::Size(10, 13);
			this->ATTACKCOUNT_VAL->TabIndex = 47;
			this->ATTACKCOUNT_VAL->Text = L"-";
			// 
			// BREATH_VAL
			// 
			this->BREATH_VAL->AutoSize = true;
			this->BREATH_VAL->Location = System::Drawing::Point(132, 93);
			this->BREATH_VAL->Name = L"BREATH_VAL";
			this->BREATH_VAL->Size = System::Drawing::Size(10, 13);
			this->BREATH_VAL->TabIndex = 46;
			this->BREATH_VAL->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 93);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 13);
			this->label5->TabIndex = 45;
			this->label5->Text = L"Breath:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 13);
			this->label3->TabIndex = 44;
			this->label3->Text = L"Attack Count:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 43;
			this->label2->Text = L"Char X:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 42;
			this->label1->Text = L"Char Y:";
			// 
			// MP_VAL
			// 
			this->MP_VAL->AutoSize = true;
			this->MP_VAL->Location = System::Drawing::Point(132, 41);
			this->MP_VAL->Name = L"MP_VAL";
			this->MP_VAL->Size = System::Drawing::Size(10, 13);
			this->MP_VAL->TabIndex = 41;
			this->MP_VAL->Text = L"-";
			// 
			// MP_LABEL
			// 
			this->MP_LABEL->AutoSize = true;
			this->MP_LABEL->Location = System::Drawing::Point(26, 40);
			this->MP_LABEL->Name = L"MP_LABEL";
			this->MP_LABEL->Size = System::Drawing::Size(26, 13);
			this->MP_LABEL->TabIndex = 40;
			this->MP_LABEL->Text = L"MP:";
			// 
			// HP_LABEL
			// 
			this->HP_LABEL->AutoSize = true;
			this->HP_LABEL->Location = System::Drawing::Point(26, 27);
			this->HP_LABEL->Name = L"HP_LABEL";
			this->HP_LABEL->Size = System::Drawing::Size(25, 13);
			this->HP_LABEL->TabIndex = 39;
			this->HP_LABEL->Text = L"HP:";
			// 
			// MOUSE_TELE
			// 
			this->MOUSE_TELE->AutoSize = true;
			this->MOUSE_TELE->Location = System::Drawing::Point(29, 284);
			this->MOUSE_TELE->Name = L"MOUSE_TELE";
			this->MOUSE_TELE->Size = System::Drawing::Size(73, 17);
			this->MOUSE_TELE->TabIndex = 69;
			this->MOUSE_TELE->Text = L"Click Tele";
			this->MOUSE_TELE->UseVisualStyleBackColor = true;
			this->MOUSE_TELE->CheckedChanged += gcnew System::EventHandler(this, &MyForm::mouseTeleChangedCheck);
			// 
			// MOUSEANIM_VAL
			// 
			this->MOUSEANIM_VAL->AutoSize = true;
			this->MOUSEANIM_VAL->Location = System::Drawing::Point(132, 284);
			this->MOUSEANIM_VAL->Name = L"MOUSEANIM_VAL";
			this->MOUSEANIM_VAL->Size = System::Drawing::Size(10, 13);
			this->MOUSEANIM_VAL->TabIndex = 70;
			this->MOUSEANIM_VAL->Text = L"-";
			// 
			// KAMI_TOGGLE
			// 
			this->KAMI_TOGGLE->AutoSize = true;
			this->KAMI_TOGGLE->Location = System::Drawing::Point(29, 307);
			this->KAMI_TOGGLE->Name = L"KAMI_TOGGLE";
			this->KAMI_TOGGLE->Size = System::Drawing::Size(49, 17);
			this->KAMI_TOGGLE->TabIndex = 71;
			this->KAMI_TOGGLE->Text = L"Kami";
			this->KAMI_TOGGLE->UseVisualStyleBackColor = true;
			this->KAMI_TOGGLE->CheckedChanged += gcnew System::EventHandler(this, &MyForm::kamiChanged);
			// 
			// TEST_LABEL
			// 
			this->TEST_LABEL->AutoSize = true;
			this->TEST_LABEL->Location = System::Drawing::Point(54, 571);
			this->TEST_LABEL->Name = L"TEST_LABEL";
			this->TEST_LABEL->Size = System::Drawing::Size(28, 13);
			this->TEST_LABEL->TabIndex = 72;
			this->TEST_LABEL->Text = L"Test";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(211, 613);
			this->Controls->Add(this->TEST_LABEL);
			this->Controls->Add(this->KAMI_TOGGLE);
			this->Controls->Add(this->MOUSEANIM_VAL);
			this->Controls->Add(this->MOUSE_TELE);
			this->Controls->Add(this->MOUSEX_VAL);
			this->Controls->Add(this->MOUSEY_VAL);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->HP_VAL);
			this->Controls->Add(this->MOBCOUNT_VAL);
			this->Controls->Add(this->MAPID_VAL);
			this->Controls->Add(this->WORLDID_VAL);
			this->Controls->Add(this->CHANNEL_VAL);
			this->Controls->Add(this->PEOPLECOUNT_VAL);
			this->Controls->Add(this->ITEMCOUNT_VAL);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->CHARY_VAL);
			this->Controls->Add(this->CHARX_VAL);
			this->Controls->Add(this->ATTACKCOUNT_VAL);
			this->Controls->Add(this->BREATH_VAL);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MP_VAL);
			this->Controls->Add(this->MP_LABEL);
			this->Controls->Add(this->HP_LABEL);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MyForm";
			this->Text = L"Maple v138";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void MP_LABEL_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
