# Image-Processing-ToolBox-using-winform(CPP)

## To run the Project
### Downlaod Visual Studio
[visual studio 2019 community free download](https://visualstudio.microsoft.com/downloads/)
### Install C++/CLI from individual components (14.29 is used)

![cli](/documentation/images/cli.png)

### Download and Extract openCV
### Download Links: [OpenCV 4.3.0](https://sourceforge.net/projects/opencvlibrary/files/4.3.0/opencv-4.3.0-vc14_vc15.exe/download)

## Project Creation
![ProjectCreation1](/documentation/images/ProjectCreation1.png)
![ProjectCreation2](/documentation/images/ProjectCreation2.png)

## Configuring Project Properties

### Set Configuration to All Configurations
![projectProperties](/documentation/images/projectProperties.png)
![projectProperties1](/documentation/images/projectProperties1.png)
## Linking OpenCV to the Project

### Set Configuration to All Configurations
![c++General](/documentation/images/c++General.png)
![VC++](/documentation/images/VC++.png)
![linkerGeneral](/documentation/images/linkerGeneral.png)

### Set Configuration to Debug
![LinkerInputDepug](/documentation/images/LinkerInputDepug.png)

### Set Configuration to Release
![LinkerInputRelease](/documentation/images/LinkerInputRelease.png)

## Linking the .cpp and .h files
### Create cpp file and import the following Code
```
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ToolBox::MyForm);
}

```
![linkingCPPandhFiles](/documentation/images/linkingCPPandhFiles.png)

### Now just copy MyForm.h file in this repo and paste it in your own project
### it will be found in your project files
### Run the Project through visual studio