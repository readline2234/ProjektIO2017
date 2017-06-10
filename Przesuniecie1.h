#pragma once
#include "DataBaseConnector.h"
#include <msclr\marshal_cppstd.h>
#include "Przesuniecie2.h"
#include "Przesuniecie1Zmiana.h"
#include <iostream>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Przesuniecie1
	/// </summary>
	public ref class Przesuniecie1 : public System::Windows::Forms::Form
	{
	public:
		Przesuniecie1(void)
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
		~Przesuniecie1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(6) {
				L"#REG41",
					L"Laptopy", L"Lenovo", L"B50-70, i5-3220, 4GB, 500GB", L"20", L"5"
			}, -1));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(6) {
				L"#REG41",
					L"Klawiatury", L"HP", L"K45, membranowa, 216 klawiszy, czarna", L"24", L"15"
			}, -1));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->AllowColumnReorder = true;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1, this->columnHeader3,
					this->columnHeader4, this->columnHeader5, this->columnHeader6, this->columnHeader7
			});
			this->listView1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			listViewItem1->StateImageIndex = 0;
			listViewItem2->StateImageIndex = 0;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(2) { listViewItem1, listViewItem2 });
			this->listView1->Location = System::Drawing::Point(11, 73);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(524, 191);
			this->listView1->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->listView1->TabIndex = 16;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Przesuniecie1::listView1_MouseDoubleClick);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Rega³";
			this->columnHeader1->Width = 71;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Kategoria";
			this->columnHeader3->Width = 69;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Nazwa";
			this->columnHeader4->Width = 57;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Cechy";
			this->columnHeader5->Width = 209;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Dostepnoœæ";
			this->columnHeader6->Width = 71;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Iloœæ";
			this->columnHeader7->Width = 40;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(80, 268);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Anuluj";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 268);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 19);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Dalej";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Przesuniecie1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 58);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Zasoby";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 9);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Strefa Ÿród³owa";
			// 
			// comboBox1
			// 
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Strefa A", L"Strefa B" });
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(13, 26);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(176, 21);
			this->comboBox1->TabIndex = 11;
			// 
			// Przesuniecie1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 298);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Przesuniecie1";
			this->Text = L"Przesuniecie1";
			this->Load += gcnew System::EventHandler(this, &Przesuniecie1::Przesuniecie1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Przesuniecie1_Load(System::Object^  sender, System::EventArgs^  e) {

#pragma region //comboBox1 - wypelnianie strefami
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
#pragma endregion

#pragma region //zerowanie wszystkich wartosci "ilosc"
		for (int i = 0; i < listView1->Items->Count; i++)
		{
			listView1->Items[i]->SubItems[5]->Text = "0";
		}
#pragma endregion
	}

private: System::Void listView1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	
	Point mousepoint=e->Location;
	ListViewHitTestInfo ^ info = listView1->HitTest(mousepoint);//->HitTest(e.X, e.Y);
	ListViewItem ^ item = info->Item;//Item;

	//int columnindex = info.Item.SubItems.IndexOf(hit.SubItem);
	int columnindex = info->Item->SubItems->IndexOf(info->SubItem);

	String ^ number;

	if (columnindex == 5)
	{
		Przesuniecie1Zmiana ^ przesuniecie1zmiana = gcnew Przesuniecie1Zmiana();
		przesuniecie1zmiana->ShowDialog();

		number = przesuniecie1zmiana->GetNumber();

		info->Item->SubItems[5]->Text = number;
	}

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//OK

	Przesuniecie2 ^ przesuniecie2 = gcnew Przesuniecie2();
	przesuniecie2->ShowDialog();
}
};
}
