
//#include "stdafx.h"		//Sometimes this include file is needed
#include "MyForm.h"		//Use name of form here

using namespace Program2;
[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm());	//Use form name here
	return 0;
}


