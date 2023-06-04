#include"MyForm.h"


[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab7::MyForm form;
	Application::Run(% form);
}
