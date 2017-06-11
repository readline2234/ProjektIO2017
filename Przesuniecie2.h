#pragma once
#include <msclr\marshal_cppstd.h>
#include "DataBaseConnector.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Przesuniecie2
	/// </summary>
	public ref class Przesuniecie2 : public System::Windows::Forms::Form
	{
	public:

		std::vector <int> * X;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	public:
		std::vector <std::string> * Y;

		Przesuniecie2(std::vector <int> * x, std::vector <std::string> * y)
		{
			InitializeComponent();
			X = x;
			Y = y;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Przesuniecie2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:






	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(72, 268);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 24;
			this->button2->Text = L"Anuluj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Przesuniecie2::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 268);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 19);
			this->button1->TabIndex = 23;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Przesuniecie2::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 58);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Rega³y";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 9);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 13);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Strefa docelowa";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Strefa A", L"Strefa B" });
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(10, 26);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(176, 21);
			this->comboBox1->TabIndex = 20;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(207, 28);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(68, 19);
			this->button3->TabIndex = 26;
			this->button3->Text = L"Wyœwietl";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Przesuniecie2::button3_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 86);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(510, 154);
			this->checkedListBox1->TabIndex = 27;
			// 
			// Przesuniecie2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 298);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Przesuniecie2";
			this->Text = L"Przesuniecie - etap II";
			this->Load += gcnew System::EventHandler(this, &Przesuniecie2::Przesuniecie2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Przesuniecie2_Load(System::Object^  sender, System::EventArgs^  e) {

		//comboBox1->Items->Add(String::Format("Item {0}", 50));	//test
		std::vector<StrefaSkladowania*> vec;
		DataBaseConnector* db = DataBaseConnector::GetInstance();
		db->GetStrefySkladowania(&vec);

		for (int i = 0; i < vec.size(); i++)
		{
			std::string bufor = vec[i]->GetKod();
			String^ result;
			result = marshal_as<String^>(bufor);

			comboBox1->Items->Add(String::Format(result, 10));	//SK
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//WYSWIETL

		checkedListBox1->Items->Clear();
		DataBaseConnector* db = DataBaseConnector::GetInstance();

		String^ strefa = comboBox1->Text;
		msclr::interop::marshal_context context;
		std::string sstrefa = context.marshal_as<std::string>(strefa);

		std::vector<Regal*> vec;
		db->GetRegalyFromStrefaSkladowania(&vec, sstrefa);	//poprawka

		for (int i = 0; i < vec.size(); i++)
		{
			std::string bufor = vec[i]->GetKod();
			String^ result;
			result = marshal_as<String^>(bufor);

			checkedListBox1->Items->Add(String::Format(result, 10));	//SK
		}
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		IEnumerator ^ Checked = checkedListBox1->CheckedItems->GetEnumerator();
		Checked = checkedListBox1->CheckedItems->GetEnumerator();

		int tickcount = 0;
		while (Checked->MoveNext())
		{
			tickcount++;
		}

		if (tickcount >= 2)
		{
			MessageBox::Show("Wybrales wiecej niz 1 rega³.", "B³¹d");
		}
		else
		{
			if (checkedListBox1->Items->Count == 0)
			{
				MessageBox::Show("Brak wybranych rega³ów.", "B³¹d");
			}
			else
			{
				Checked->Reset();
				Checked->MoveNext();

				String ^  kod;
				kod = Checked->Current->ToString();
				msclr::interop::marshal_context context;
				std::string Regal = context.marshal_as<std::string>(kod);

				DataBaseConnector* db = DataBaseConnector::GetInstance();

				for (int i = 0; i < X->size(); i++)
				{
					int ilosc = std::stoi(Y->at(i));

					db->PrzesunZasobNaRegal(X->at(i), Regal, ilosc);
				}
			Przesuniecie2:Close();
			}
		}

	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//ANULUJ
	Przesuniecie2::Close();

}
};
	}