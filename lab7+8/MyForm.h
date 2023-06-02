#pragma once
#include"funcs.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

namespace Lab7 {

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
	private: System::Windows::Forms::TextBox^ month1;
	private: System::Windows::Forms::TextBox^ year1;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::TextBox^ day1;
	private: System::Windows::Forms::TextBox^ day2;
	private: System::Windows::Forms::TextBox^ year2;



	private: System::Windows::Forms::TextBox^ month2;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ date_generation;
	private: System::Windows::Forms::Button^ find_new_date;


	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ result;
	private: System::Windows::Forms::Label^ label6;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->month1 = (gcnew System::Windows::Forms::TextBox());
			this->year1 = (gcnew System::Windows::Forms::TextBox());
			this->day1 = (gcnew System::Windows::Forms::TextBox());
			this->day2 = (gcnew System::Windows::Forms::TextBox());
			this->year2 = (gcnew System::Windows::Forms::TextBox());
			this->month2 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->date_generation = (gcnew System::Windows::Forms::Button());
			this->find_new_date = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->result = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// month1
			// 
			this->month1->Location = System::Drawing::Point(125, 54);
			this->month1->Name = L"month1";
			this->month1->Size = System::Drawing::Size(43, 22);
			this->month1->TabIndex = 0;
			// 
			// year1
			// 
			this->year1->Location = System::Drawing::Point(174, 54);
			this->year1->Name = L"year1";
			this->year1->Size = System::Drawing::Size(68, 22);
			this->year1->TabIndex = 1;
			// 
			// day1
			// 
			this->day1->Location = System::Drawing::Point(76, 54);
			this->day1->Name = L"day1";
			this->day1->Size = System::Drawing::Size(43, 22);
			this->day1->TabIndex = 2;
			// 
			// day2
			// 
			this->day2->Location = System::Drawing::Point(76, 166);
			this->day2->Name = L"day2";
			this->day2->Size = System::Drawing::Size(43, 22);
			this->day2->TabIndex = 5;
			// 
			// year2
			// 
			this->year2->Location = System::Drawing::Point(174, 166);
			this->year2->Name = L"year2";
			this->year2->Size = System::Drawing::Size(68, 22);
			this->year2->TabIndex = 4;
			// 
			// month2
			// 
			this->month2->Location = System::Drawing::Point(125, 166);
			this->month2->Name = L"month2";
			this->month2->Size = System::Drawing::Size(43, 22);
			this->month2->TabIndex = 3;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-2, 82);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(137, 131);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(49, 16);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Дата 2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(137, 19);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 16);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Дата1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(109, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(101, 16);
			this->label3->TabIndex = 9;
			this->label3->Text = L"(DD-MM-YYYY)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(109, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 16);
			this->label4->TabIndex = 10;
			this->label4->Text = L"(DD-MM-YYYY)";
			// 
			// date_generation
			// 
			this->date_generation->Location = System::Drawing::Point(379, 21);
			this->date_generation->Name = L"date_generation";
			this->date_generation->Size = System::Drawing::Size(91, 68);
			this->date_generation->TabIndex = 11;
			this->date_generation->Text = L"генерація дати";
			this->date_generation->UseVisualStyleBackColor = true;
			this->date_generation->Click += gcnew System::EventHandler(this, &MyForm::date_generation_Click);
			// 
			// find_new_date
			// 
			this->find_new_date->Location = System::Drawing::Point(268, 21);
			this->find_new_date->Name = L"find_new_date";
			this->find_new_date->Size = System::Drawing::Size(91, 68);
			this->find_new_date->TabIndex = 12;
			this->find_new_date->Text = L"Знайти пізнішу дату";
			this->find_new_date->UseVisualStyleBackColor = true;
			this->find_new_date->Click += gcnew System::EventHandler(this, &MyForm::find_new_date_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->result);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Location = System::Drawing::Point(268, 110);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 100);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(51, 56);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(0, 16);
			this->result->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(62, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(77, 16);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Результат";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(70, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Результат";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(483, 222);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->find_new_date);
			this->Controls->Add(this->date_generation);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->day2);
			this->Controls->Add(this->year2);
			this->Controls->Add(this->month2);
			this->Controls->Add(this->day1);
			this->Controls->Add(this->year1);
			this->Controls->Add(this->month1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void MyForm::IsEmptyInterface();
	private: void MyForm::SetWhiteBackColor();
	private: void MyForm::IsCellIsNumber();
	private: void MyForm::IsInterfaceDateExist();
	private: System::Void date_generation_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void find_new_date_Click(System::Object^ sender, System::EventArgs^ e);
};
}
