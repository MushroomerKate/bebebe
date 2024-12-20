#include "HomeWindow.h"

using namespace Lab4;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Lab4::HomeWindow window;
	Application::Run(% window);
}