#pragma once
#include "Przesuniecie1.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuTowar
	/// </summary>
	public ref class MenuTowar : public System::Windows::Forms::Form
	{
	public:
		MenuTowar(void)
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
		~MenuTowar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button3;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  butt_dodaj_D_do_SK;
	private: System::Windows::Forms::Button^  button4;

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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->butt_dodaj_D_do_SK = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 128);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(198, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Przesuniecie";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuTowar::button3_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(12, 70);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(198, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Usuñ towar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(198, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Edytuj towar";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// butt_dodaj_D_do_SK
			// 
			this->butt_dodaj_D_do_SK->Enabled = false;
			this->butt_dodaj_D_do_SK->Location = System::Drawing::Point(12, 12);
			this->butt_dodaj_D_do_SK->Name = L"butt_dodaj_D_do_SK";
			this->butt_dodaj_D_do_SK->Size = System::Drawing::Size(198, 23);
			this->butt_dodaj_D_do_SK->TabIndex = 4;
			this->butt_dodaj_D_do_SK->Text = L"Dodaj towar";
			this->butt_dodaj_D_do_SK->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(12, 99);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(198, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Inwentaryzacja";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// MenuTowar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(233, 164);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->butt_dodaj_D_do_SK);
			this->Name = L"MenuTowar";
			this->Text = L"Towar";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//przesuniecie
		Przesuniecie1 ^ przesuniecie1 = gcnew Przesuniecie1();
		przesuniecie1->ShowDialog();
	}
};
}
