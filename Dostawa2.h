#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dostawa2
	/// </summary>
	public ref class Dostawa2 : public System::Windows::Forms::Form
	{
	public:
		Dostawa2(CheckedListBox^ checkedlist, IEnumerator^ checked)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			Checkedlist = checkedlist;
			Checked = checked;
			//
		}
	CheckedListBox^ Checkedlist;
	IEnumerator^ Checked;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dostawa2()
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
	private: System::Windows::Forms::Label^  label2;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(82, 231);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 19);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Anuluj";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Dostawa2::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 231);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(67, 19);
			this->button1->TabIndex = 15;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// checkedListBox2
			// 
			this->checkedListBox2->FormattingEnabled = true;
			this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Rega� 1", L"Rega� 2", L"Rega� 3" });
			this->checkedListBox2->Location = System::Drawing::Point(11, 29);
			this->checkedListBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkedListBox2->Name = L"checkedListBox2";
			this->checkedListBox2->Size = System::Drawing::Size(236, 184);
			this->checkedListBox2->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 14);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Rega�y";
			// 
			// Dostawa2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(275, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkedListBox2);
			this->Controls->Add(this->label2);
			this->Name = L"Dostawa2";
			this->Text = L"Dostawa2";
			this->Load += gcnew System::EventHandler(this, &Dostawa2::Dostawa2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Dostawa2_Load(System::Object^  sender, System::EventArgs^  e) {


	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//ANULUJ

	Checked->Reset();
	Checked->MoveNext();


	IEnumerator^ myEnum2 = Checkedlist->CheckedItems->GetEnumerator();
	while (myEnum2->MoveNext())
	{
		Object^ itemChecked = safe_cast<Object^>(myEnum2->Current);

		// Use the IndexOf method to get the index of an item.
		MessageBox::Show(String::Concat("Item with title: \"", itemChecked, "\", is checked. Checked state is: ", Checkedlist->GetItemCheckState(Checkedlist->Items->IndexOf(itemChecked)), "."));
	}

}
};
}