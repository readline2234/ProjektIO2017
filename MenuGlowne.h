#pragma once
#include <msclr\marshal_cppstd.h>
#include "MenuDostawa.h"
#include "MenuTowar.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuGlowne
	/// </summary>
	public ref class MenuGlowne : public System::Windows::Forms::Form
	{
	public:
		MenuGlowne(void)
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
		~MenuGlowne()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  butt_zaloguj;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;

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
			this->butt_zaloguj = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// butt_zaloguj
			// 
			this->butt_zaloguj->Location = System::Drawing::Point(53, 105);
			this->butt_zaloguj->Margin = System::Windows::Forms::Padding(2);
			this->butt_zaloguj->Name = L"butt_zaloguj";
			this->butt_zaloguj->Size = System::Drawing::Size(56, 19);
			this->butt_zaloguj->TabIndex = 35;
			this->butt_zaloguj->Text = L"Zaloguj";
			this->butt_zaloguj->UseVisualStyleBackColor = true;
			this->butt_zaloguj->Click += gcnew System::EventHandler(this, &MenuGlowne::butt_zaloguj_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 77);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 13);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Has³o";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 55);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Login";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(53, 75);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(137, 20);
			this->textBox2->TabIndex = 32;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(53, 52);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 20);
			this->textBox1->TabIndex = 31;
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(255, 11);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(124, 19);
			this->button5->TabIndex = 30;
			this->button5->Text = L"Przywracanie danych";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(195, 11);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 19);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Towar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuGlowne::button4_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(11, 11);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(65, 19);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Dostawa";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuGlowne::button3_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(80, 11);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 19);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Przegl¹daj dane";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MenuGlowne
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(390, 197);
			this->Controls->Add(this->butt_zaloguj);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Name = L"MenuGlowne";
			this->Text = L"MenuGlowne";
			this->Load += gcnew System::EventHandler(this, &MenuGlowne::MenuGlowne_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MenuGlowne_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void butt_zaloguj_Click(System::Object^  sender, System::EventArgs^  e) {

	System::String^ managedString = textBox1->Text;
	msclr::interop::marshal_context context;

	std::string login = context.marshal_as<std::string>(managedString);
	managedString = textBox2->Text;
	std::string haslo = context.marshal_as<std::string>(managedString);


	if (login == "bob")
	{
		if (haslo == "1234")
		{
			textBox1->Enabled = false;
			textBox2->Enabled = false;
			butt_zaloguj->Enabled = false;

			button3->Enabled = true;
			button4->Enabled = true;
		}
	}
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//dostawa
	MenuDostawa ^ menudostawa = gcnew MenuDostawa();
	menudostawa->ShowDialog();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//towar
	MenuTowar ^ menutowar = gcnew MenuTowar();
	menutowar->ShowDialog();
}
};
}
