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


	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;

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
			System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2) {
				L"#REG41",
					L"20/100"
			}, -1));
			System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(2) {
				L"#REG42",
					L"50/100"
			}, -1));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
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
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnHeader1, this->columnHeader3 });
			this->listView1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->listView1->FullRowSelect = true;
			listViewItem1->StateImageIndex = 0;
			listViewItem2->StateImageIndex = 0;
			this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(2) { listViewItem1, listViewItem2 });
			this->listView1->Location = System::Drawing::Point(11, 73);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->MultiSelect = false;
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(524, 191);
			this->listView1->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->listView1->TabIndex = 25;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Rega³";
			this->columnHeader1->Width = 375;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Pojemnosc";
			this->columnHeader3->Width = 131;
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
			// Przesuniecie2
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
			this->Name = L"Przesuniecie2";
			this->Text = L"Przesuniecie2";
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
};
}
