# Image-Processing-ToolBox-using-winform(CPP)

## To run the Project
### Downlaod Visual Studio
[visual studio community free download](https://visualstudio.microsoft.com/downloads/)
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

### To access the GUI head towards MyForm.h[Design]
![mainScreen](/documentation/images/guiDescription/mainScreen.png)

## After Running the Project
### Main Tab
![mainTab](/documentation/images/guiDescription/mainTab.png)

## Buttons Explanation
## Main Tab
### - Select image: Opens a dialog for the user to browse to get the required image.
![selectImg](/documentation/images/guiDescription/selectImg.png)

### - image Details: Shows the image Properties
![imgDetails](/documentation/images/guiDescription/imgDetails.png)

### - Convert Gray Scale: Converts from RGB to gray Scale
![cnrtGrayScale](/documentation/images/guiDescription/cnrtGrayScale.png)

### - Reset: Removes all the changes that were made to the image
![Reset](/documentation/images/guiDescription/Reset.png)

### - Save: Opens a dialog to enables the user to select the location of the saved image
![save](/documentation/images/guiDescription/save.png)


The Second Tab is Edit (for the image transformation operations)
## Edit Tab
![editTab](/documentation/images/guiDescription/editTab.png)

### - Adjust Position (image translation): moves the image along the x axis or the y axis
![adjustPosition](/documentation/images/guiDescription/adjustPosition.png)

### - Mirror (flipping): flips the image along the x axis or y axis or both
![mirror](/documentation/images/guiDescription/mirror.png)

### - Rotate: rotates the image
![rotate](/documentation/images/guiDescription/rotate.png)

### - Skewing: skew the image in any direction
![skewing](/documentation/images/guiDescription/skewing.png)

### - Zoom (Scaling): zooming in or zooming out
![zoom](/documentation/images/guiDescription/zoom.png)

### - Crop: Crops the image
![crop](/documentation/images/guiDescription/crop.png)

The Third Tab is Advanced Edit (for the Point Processing operations)
## Advanced Edit
![advancedEdit](/documentation/images/guiDescription/advancedEdit.png)

### - Show Graphical Representation (Histogram): Shows the histogram
![histogram](/documentation/images/guiDescription/histogram.png)

### - Adjust Contrast (Histogram Equalization): perform contrast stretching (Histogram Equalization)
![adjustContrast](/documentation/images/guiDescription/adjustContrast.png)

### - Negative: flips all the pixels values
![negative](/documentation/images/guiDescription/negative.png)

### - Water Mark (Blinding): Blinds two images together
![blinding](/documentation/images/guiDescription/blinding.png)
![blinding2](/documentation/images/guiDescription/blinding2.png)

### - Adjust Brightness (Power Transformation (Gamma Correction)): Used to map a narrow range of dark input values into a wider range of output values or vice versa depending on γ value
![gamaCorrection](/documentation/images/guiDescription/gammaCorrection.png)

### - Brighten Dark Images (Log Transformation): Used to map a narrow range of dark input values into a wider range of output values
![logTransformation](/documentation/images/guiDescription/logTransformation.png)

### - Image Slicing Levels (Bit Plane Slicing): Converting a gray level image to a binary image.
![bitPlane](/documentation/images/guiDescription/bitPlane.png)
![bitPlane2](/documentation/images/guiDescription/bitPlane2.png)

### - Choose Certain Details (Thresholding): used to create binary images.
![thresholding](/documentation/images/guiDescription/thresholding.png)

### - Highlight Gray range (Gray Level Slicing): It’s a way to highlight gray range of interest to a viewer by one of two ways
#### Highlight only
![graySlicing](/documentation/images/guiDescription/graySlicing.png)
#### Highlight and dim others
![graySlicing2](/documentation/images/guiDescription/graySlicing2.png)

The Fourth Tab is Filters (for the Neighborhood Processing operations)

## Filters
![filters](/documentation/images/guiDescription/filters.png)

### - Box Filter (Traditional Filter): Smoothing filter
The trackbar controls the size of the filter’s Matrix

![boxFilter](/documentation/images/guiDescription/boxFilter.png)

### - Pyramidal Blurring (Pyramidal Filter): Smoothing filter
The trackbar controls the size of the filter’s Matrix

![pyramidalFilter](/documentation/images/guiDescription/pyramidalFilter.png)

### - Remove High Noise (Circular Filter): remove High noise
The trackbar controls the size of the filter’s Matrix

![circularFilter](/documentation/images/guiDescription/circularFilter.png)

### - Cone Blurring (Cone Filter): Smoothing filter
The trackbar controls the size of the filter’s Matrix

![coneFilter](/documentation/images/guiDescription/coneFilter.png)

### - Fixing Extremely Dark or Bright Values (Median Filter): remove salt and pepper noise
The trackbar controls the size of the filter’s Matrix

![medianFilter](/documentation/images/guiDescription/medianFilter.png)
![medianFilter2](/documentation/images/guiDescription/medianFilter2.png)

### - Reducing high noises and blurring (Gaussian Filter): remove High noise
The trackbar controls the size of the filter’s Matrix

![gaussianFilter](/documentation/images/guiDescription/gaussianFilter.png)

### - Thick Sharpening (Sobel Filter)
First Click Apply filter

![sobelFilter](/documentation/images/guiDescription/sobelFilter.png)

Then Click Save changes to sharpen the original image

![sobelFilter2](/documentation/images/guiDescription/sobelFilter2.png)

### - Thin Sharpening (Laplacian Filter)
First Choose the filter size and Click Apply filter

![laplacianFilter](/documentation/images/guiDescription/laplacianFilter.png)

Then Click Save changes to sharpen the original image

![laplacianFilter2](/documentation/images/guiDescription/laplacianFilter2.png)

The Fifth Tab is Locate objects and boundaries (for the Segmentation operations)
## Locate Objects and Boundaries
![locateObjectsBoundaries](/documentation/images/guiDescription/locateObjectsBoundaries.png)

### - Detecting Thin Edges (Laplacian Segmentation)
Track bar is for matrix size 

![laplacianSegmentation](/documentation/images/guiDescription/laplacianSegmentation.png)

### - Detecting Certain Edges Of The Images (Thresholding Segmentation)
Track bar is for Thresholding value

![thresholdingSegmantation](/documentation/images/guiDescription/thresholdingSegmentation.png)

### - Detecting all Edge’s Direction (Sobel Segmentation)
![sobelSegmantation](/documentation/images/guiDescription/sobelSegmantation.png)

### - Detecting the main object (DFT Low Pass Filter)
Track bar is for the smoothing value 

![DftLowPassFilter](/documentation/images/guiDescription/DftLowPassFilter.png)

### - Denying the main object (DFT High Pass Filter)
Track bar is for the high frequency’s selection 

![DftHighPassFilter](/documentation/images/guiDescription/DftHighPassFilter.png)

### - Mathematical Shapes Detector (Shapes Recognition): Recognize the graphical shapes
![ShapesRecognition](/documentation/images/guiDescription/ShapesRecognition.png)

The sixth Tab is Noise (to add noise to the image)
## Noise
![noise](/documentation/images/guiDescription/noise.png)

### - Salt and pepper Noise: adds Salt and pepper noise to the image
![saltAndPepper](/documentation/images/guiDescription/saltAndPepper.png)

### - Gaussian Noise: adds Gaussian Noise to the image
![gaussianNoise](/documentation/images/guiDescription/gaussianNoise.png)

## Themes Selection
There is three themes to Choose From

### - Gray Theme
![grayTheme](/documentation/images/guiDescription/grayTheme.png)

### - Dark Theme
![darkTheme](/documentation/images/guiDescription/darkTheme.png)

### - White Theme (Default)
![whiteTheme](/documentation/images/guiDescription/whiteTheme.png)
