#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dostawa1
	/// </summary>
	public ref class Dostawa1 : public System::Windows::Forms::Form
	{
	public:
		Dostawa1(void)
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
		~Dostawa1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox2;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

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
			this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(82, 223);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Anuluj";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 223);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 19);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Dalej";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// checkedListBox2
			// 
			this->checkedListBox2->FormattingEnabled = true;
			this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Strefa A", L"Strefa B" });
			this->checkedListBox2->Location = System::Drawing::Point(208, 24);
			this->checkedListBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkedListBox2->Name = L"checkedListBox2";
			this->checkedListBox2->Size = System::Drawing::Size(166, 184);
			this->checkedListBox2->TabIndex = 10;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->DisplayMember = L"Name";
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"#A45B - 8:00 - 20.05.2017", L"#A45C - 9:15 - 24.05.2017",
					L"#A45D - 14:35 - 20..06.2017"
			});
			this->checkedListBox1->Location = System::Drawing::Point(11, 24);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(163, 184);
			this->checkedListBox1->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(242, 8);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Strefy sk³adowania";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 8);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Dostawy";
			// 
			// Dostawa1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(398, 253);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox2);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Dostawa1";
			this->Text = L"Dostawa1";
			this->Load += gcnew System::EventHandler(this, &Dostawa1::Dostawa1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Dostawa1_Load(System::Object^  sender, System::EventArgs^  e) {

		checkedListBox1->Items->Add(String::Format("Item {0}", 50));
	}
};
}
