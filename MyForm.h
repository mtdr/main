/*!
	\file
	\brief Здесь собраны все функции для визуальной части
	\author Осмоловский Павел
	\version 1.0
	\date Декабрь 2015 года
	
*/

#pragma once
#include "BT.cpp"

namespace kr {

	using namespace BT1;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}



	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::PaintEventArgs^ e;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;





	protected: 

	private:
		 BT1::binTree b;
		 
		 
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->Location = System::Drawing::Point(221, 29);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1400, 750);
			this->panel1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(16, 98);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(173, 26);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 58);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Введите элемент";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(16, 152);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(173, 153);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Вставить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1912, 944);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel1);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Binary Tree ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		
#pragma endregion

		inline void displayBT (binTree b, int theX, int theY,int n, int theX1, int theY1)
	{	// n - уровень узла
		
		Graphics ^panelGraphics = panel1->CreateGraphics();
		
		if (b!=NULL) 
		{
			Label^ label = gcnew Label();
			label->Font = gcnew System::Drawing::Font("verdana",11);
			label->Width = 60;
			
			label->BackColor = Color::Gold;
			
			label->Location = Point(theX1, theY1);
			label->Text = Convert::ToString((int)RootBT(b));
			panel1->Controls->Add(label);
			
			if(theX !=theX1 && theY !=theY1){
			 // Draw line to screen.
				panelGraphics->DrawLine( gcnew Pen(Color::Violet, 2), Point(theX+40,theY+20), Point(theX1+40,theY1+20));}
			n++;
			if(!isNull(Right1(b))) 
			{
				displayBT (Right1(b),theX1,theY1,n,theX1+200/n,theY1+50);
			}
			
 			if(!isNull(Left1(b))) 
			{
				displayBT (Left1(b),theX1,theY1,n,theX1-200/n,theY1+50);
			}
		}

	}
		

		

		
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			
				int k;
				if (Int32::TryParse(textBox2->Text,k))
				{
					panel1->Controls->Clear();
					panel1->Invalidate();
					b = insert(b,k);
					displayBT(b,400,20,0,400,20);
					textBox2->Clear();
				}
				else 
				{
					MessageBox::Show("Можно вводить только целые числа");
					textBox2->Clear();
				}
		 }
		 
};
}

