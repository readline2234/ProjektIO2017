#pragma once
#include "Dostawa1.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuDostawa
	/// </summary>
	public ref class MenuDostawa : public System::Windows::Forms::Form
	{
	public:
		MenuDostawa(void)
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
		~MenuDostawa()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  butt_dodaj_D_do_SK;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->butt_dodaj_D_do_SK = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// butt_dodaj_D_do_SK
			// 
			this->butt_dodaj_D_do_SK->Location = System::Drawing::Point(12, 12);
			this->butt_dodaj_D_do_SK->Name = L"butt_dodaj_D_do_SK";
			this->butt_dodaj_D_do_SK->Size = System::Drawing::Size(198, 23);
			this->butt_dodaj_D_do_SK->TabIndex = 0;
			this->butt_dodaj_D_do_SK->Text = L"Dodaj dostaw� do strefy sk�adowania";
			this->butt_dodaj_D_do_SK->UseVisualStyleBackColor = true;
			this->butt_dodaj_D_do_SK->Click += gcnew System::EventHandler(this, &MenuDostawa::butt_dodaj_D_do_SK_Click);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(198, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Dodaj dostaw�";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(12, 70);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(198, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Edytujj dostaw�";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(12, 99);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(198, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Usu� dostaw�";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// MenuDostawa
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(233, 143);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->butt_dodaj_D_do_SK);
			this->Name = L"MenuDostawa";
			this->Text = L"Dostawa";
			this->Load += gcnew System::EventHandler(this, &MenuDostawa::MenuDostawa_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuDostawa_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void butt_dodaj_D_do_SK_Click(System::Object^  sender, System::EventArgs^  e) {

		Dostawa1 ^ dostawa1 = gcnew Dostawa1();
		dostawa1->ShowDialog();
	}
};
}
