//omar hany mohamed hussien
//image processing techniques
//customized tool box


#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<Windows.h>
#include<iostream>
#include<sstream>
#include<string>
#include<array>
#include<vector>
#include<set>
#include<tchar.h>
#include<math.h>


namespace ToolBox {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;
	using namespace cv;

    Mat src;
	Mat blind;
	string x, x1, op;
	bool histVisualize = false;

    //region of interest
        //Mat image;
        //cv::Point origin;
        //Rect selection;
        //bool selectObject = false;
        //bool objectCropped = false;
        System::Drawing::Rectangle Rect;
        System::Drawing::Rectangle Rect1;
        cv::Rect rect1;
        System::Drawing::Point LocationXY;			 //starting point
        System::Drawing::Point Locationx1y1;			//ending point
        bool isMouseDown = false;		//mouse down event

    //shape Recogination
	    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	//dft filter
	//Mat FI;
	    int d0 = 100;



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

		//variable to containe the picture path


	public:System::String^ path;
	public:System::String^ path1;





	public:





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabPage^ ImageSegmentation;
	private: System::Windows::Forms::TabPage^ NeighborhoodOperations;
	private: System::Windows::Forms::TabPage^ PointProcessing;




	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TabPage^ imageOperations;
	private: System::Windows::Forms::Button^ ZoomOut;
	private: System::Windows::Forms::Button^ ZoomIn;
	private: System::Windows::Forms::Button^ SkewDownLeft;
	private: System::Windows::Forms::Button^ SkewDownRight;
	private: System::Windows::Forms::Button^ SkewUpLeft;
	private: System::Windows::Forms::Button^ SkewUpRight;
	private: System::Windows::Forms::Button^ CustomRotation;
	private: System::Windows::Forms::TextBox^ RotationVar;
	private: System::Windows::Forms::TextBox^ TransY;
	private: System::Windows::Forms::TextBox^ TransX;
	private: System::Windows::Forms::Label^ RotateLabel;
	private: System::Windows::Forms::Label^ RotationLabel;
	private: System::Windows::Forms::Button^ RotateLeft;
	private: System::Windows::Forms::Button^ RotateRight;
	private: System::Windows::Forms::Button^ xmirror;
	private: System::Windows::Forms::Button^ xymirror;
	private: System::Windows::Forms::Button^ ymirror;
	private: System::Windows::Forms::Button^ CustomTranslation;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ DownRight;
	private: System::Windows::Forms::Button^ DownLeft;
	private: System::Windows::Forms::Button^ UpRight;
	private: System::Windows::Forms::Button^ UpLeft;
	private: System::Windows::Forms::Button^ btnDown;
	private: System::Windows::Forms::Button^ Right;
	private: System::Windows::Forms::Button^ Left;
	private: System::Windows::Forms::Button^ btnUp;
	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ Zoom;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ Translation;
	private: System::Windows::Forms::TabPage^ index;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ SaveImg;
	private: System::Windows::Forms::Button^ ResetImg;
	private: System::Windows::Forms::Button^ RGB2Gray;
	private: System::Windows::Forms::Button^ ImageProberties;
	private: System::Windows::Forms::Button^ LoadImg;
	private: System::Windows::Forms::TabControl^ mainTabC;
	private: System::Windows::Forms::Button^ Save2;

	private: System::Windows::Forms::Button^ Reset2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ ConfCrop;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ powerTransformation;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ cnfrmBlind;

	private: System::Windows::Forms::Button^ Blind;

	private: System::Windows::Forms::Button^ selectImg;
	private: System::Windows::Forms::OpenFileDialog^ ofd2;
	private: System::Windows::Forms::TrackBar^ powerTrans;
	private: System::Windows::Forms::Button^ cnfrmPowerTrans;
	private: System::Windows::Forms::Label^ bightLabel;
	private: System::Windows::Forms::Button^ logTrans;
	private: System::Windows::Forms::Button^ cnfrmChanges;

	private: System::Windows::Forms::TrackBar^ logTransf;
	private: System::Windows::Forms::Label^ logLabel;
	private: System::Windows::Forms::Button^ cnfrmChangess;

	private: System::Windows::Forms::TrackBar^ foureirFilter;
	private: System::Windows::Forms::Panel^ panel4;



	private: System::Windows::Forms::Button^ MedianFilter;

	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Label^ dftLabel;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ cnfrmTraditional;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::TrackBar^ circularS;
	private: System::Windows::Forms::Button^ cnfrmCircular;
	private: System::Windows::Forms::Button^ cnfrmCone;

	private: System::Windows::Forms::Button^ coneFilter;
	private: System::Windows::Forms::TrackBar^ MedianScroll;
	private: System::Windows::Forms::Button^ cnfrmMedian;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ComboBox^ BitPlaneBox;

	private: System::Windows::Forms::Label^ SelectedBitLabel;
	private: System::Windows::Forms::Label^ ChoosenPlane;
	private: System::Windows::Forms::Label^ PlaneLabel;
	private: System::Windows::Forms::Button^ SavePlane;
	private: System::Windows::Forms::Button^ cnfrmBitPlaneSelection;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ ThreshLabel;
	private: System::Windows::Forms::Button^ threshHoldingCnfrm;

	private: System::Windows::Forms::TrackBar^ threshHoldingS;
	private: System::Windows::Forms::Button^ saveGrayRange;
	private: System::Windows::Forms::Button^ secHighlightGray;
	private: System::Windows::Forms::Label^ labelMin;
	private: System::Windows::Forms::Label^ labelMax;
	private: System::Windows::Forms::Button^ HighlightGray;
	private: System::Windows::Forms::TrackBar^ MaxVlaue;
	private: System::Windows::Forms::TrackBar^ MinValue;
	private: System::Windows::Forms::Button^ grayLevelSlicing;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::TrackBar^ gaussianFilterS;
	private: System::Windows::Forms::Button^ cnfrmGaussSave;


	private: System::Windows::Forms::Button^ gaussianFilter;
	private: System::Windows::Forms::Button^ SobelFilter;
	private: System::Windows::Forms::PictureBox^ Vbox;

	private: System::Windows::Forms::PictureBox^ Hbox;

	private: System::Windows::Forms::Label^ Vlabel;
	private: System::Windows::Forms::Label^ Dlabel;
	private: System::Windows::Forms::Label^ Hlabel;
	private: System::Windows::Forms::Button^ cnfrmSobel;
	private: System::Windows::Forms::Button^ applyingSobel;
	private: System::Windows::Forms::PictureBox^ Dbox;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::ComboBox^ laplacianFilters;
	private: System::Windows::Forms::Label^ fLabel;
	private: System::Windows::Forms::Label^ selectLabel;
	private: System::Windows::Forms::Label^ SelectedLabel;
	private: System::Windows::Forms::Button^ cnfrmLaplacian;

	private: System::Windows::Forms::Button^ applyingLaplacian;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ LaplacianDetection;
	private: System::Windows::Forms::Label^ laplaceLabel;

	private: System::Windows::Forms::Button^ saveEdges;

	private: System::Windows::Forms::TrackBar^ laplacianScroll;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Label^ ThreshhHold;
	private: System::Windows::Forms::Button^ cnfrmThresholding;
	private: System::Windows::Forms::TrackBar^ threshS;
	private: System::Windows::Forms::PictureBox^ BoxD;
	private: System::Windows::Forms::PictureBox^ BoxV;
	private: System::Windows::Forms::PictureBox^ BoxH;
	private: System::Windows::Forms::Label^ labelV;
	private: System::Windows::Forms::Label^ labelD;
	private: System::Windows::Forms::Label^ labelH;
	private: System::Windows::Forms::Button^ SaveSobel;
	private: System::Windows::Forms::Button^ Sobel;
	private: System::Windows::Forms::Button^ SobelEdges;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::PictureBox^ Recog;
	private: System::Windows::Forms::Button^ Fourier;
	private: System::Windows::Forms::Button^ Fourier2;
	private: System::Windows::Forms::TrackBar^ FourierFilter;
	private: System::Windows::Forms::Button^ lowPass;

	private: System::Windows::Forms::Label^ LPF;
	private: System::Windows::Forms::Button^ saveFFS;
	private: System::Windows::Forms::TrackBar^ ffs;
	private: System::Windows::Forms::TextBox^ maxRange;
	private: System::Windows::Forms::TextBox^ minRange;
	private: System::Windows::Forms::TextBox^ powerBox;
	private: System::Windows::Forms::TextBox^ logBox;
	private: System::Windows::Forms::TextBox^ threshBox;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Button^ GaussianNoise;

	private: System::Windows::Forms::Button^ saltAndPepper;
	private: System::Windows::Forms::Button^ Save3;
	private: System::Windows::Forms::Button^ Reset3;
	private: System::Windows::Forms::Button^ pointProcessingGuide;
	private: System::Windows::Forms::Button^ FiltersGuide;
	private: System::Windows::Forms::Button^ segmentationGuide;
	private: System::Windows::Forms::Button^ RGB2Gray2;
	private: System::Windows::Forms::Button^ darkTheme;
	private: System::Windows::Forms::Button^ greyTheme;
	private: System::Windows::Forms::Button^ lightTheme;








































	private: System::Windows::Forms::SaveFileDialog^ sfd;





	public:
		//bit map to save the pixels values

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





	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ ofd;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sfd = (gcnew System::Windows::Forms::SaveFileDialog());
			this->ImageSegmentation = (gcnew System::Windows::Forms::TabPage());
			this->segmentationGuide = (gcnew System::Windows::Forms::Button());
			this->saveFFS = (gcnew System::Windows::Forms::Button());
			this->ffs = (gcnew System::Windows::Forms::TrackBar());
			this->lowPass = (gcnew System::Windows::Forms::Button());
			this->LPF = (gcnew System::Windows::Forms::Label());
			this->FourierFilter = (gcnew System::Windows::Forms::TrackBar());
			this->Recog = (gcnew System::Windows::Forms::PictureBox());
			this->BoxD = (gcnew System::Windows::Forms::PictureBox());
			this->BoxV = (gcnew System::Windows::Forms::PictureBox());
			this->BoxH = (gcnew System::Windows::Forms::PictureBox());
			this->labelV = (gcnew System::Windows::Forms::Label());
			this->labelD = (gcnew System::Windows::Forms::Label());
			this->labelH = (gcnew System::Windows::Forms::Label());
			this->SaveSobel = (gcnew System::Windows::Forms::Button());
			this->Sobel = (gcnew System::Windows::Forms::Button());
			this->ThreshhHold = (gcnew System::Windows::Forms::Label());
			this->cnfrmThresholding = (gcnew System::Windows::Forms::Button());
			this->threshS = (gcnew System::Windows::Forms::TrackBar());
			this->laplaceLabel = (gcnew System::Windows::Forms::Label());
			this->saveEdges = (gcnew System::Windows::Forms::Button());
			this->laplacianScroll = (gcnew System::Windows::Forms::TrackBar());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->Fourier2 = (gcnew System::Windows::Forms::Button());
			this->Fourier = (gcnew System::Windows::Forms::Button());
			this->SobelEdges = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->LaplacianDetection = (gcnew System::Windows::Forms::Button());
			this->NeighborhoodOperations = (gcnew System::Windows::Forms::TabPage());
			this->FiltersGuide = (gcnew System::Windows::Forms::Button());
			this->cnfrmLaplacian = (gcnew System::Windows::Forms::Button());
			this->applyingLaplacian = (gcnew System::Windows::Forms::Button());
			this->SelectedLabel = (gcnew System::Windows::Forms::Label());
			this->Dbox = (gcnew System::Windows::Forms::PictureBox());
			this->selectLabel = (gcnew System::Windows::Forms::Label());
			this->Vbox = (gcnew System::Windows::Forms::PictureBox());
			this->fLabel = (gcnew System::Windows::Forms::Label());
			this->Hbox = (gcnew System::Windows::Forms::PictureBox());
			this->laplacianFilters = (gcnew System::Windows::Forms::ComboBox());
			this->Vlabel = (gcnew System::Windows::Forms::Label());
			this->Dlabel = (gcnew System::Windows::Forms::Label());
			this->Hlabel = (gcnew System::Windows::Forms::Label());
			this->cnfrmSobel = (gcnew System::Windows::Forms::Button());
			this->applyingSobel = (gcnew System::Windows::Forms::Button());
			this->gaussianFilterS = (gcnew System::Windows::Forms::TrackBar());
			this->cnfrmGaussSave = (gcnew System::Windows::Forms::Button());
			this->MedianScroll = (gcnew System::Windows::Forms::TrackBar());
			this->cnfrmMedian = (gcnew System::Windows::Forms::Button());
			this->cnfrmCone = (gcnew System::Windows::Forms::Button());
			this->coneFilter = (gcnew System::Windows::Forms::Button());
			this->circularS = (gcnew System::Windows::Forms::TrackBar());
			this->cnfrmCircular = (gcnew System::Windows::Forms::Button());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->cnfrmTraditional = (gcnew System::Windows::Forms::Button());
			this->dftLabel = (gcnew System::Windows::Forms::Label());
			this->cnfrmChangess = (gcnew System::Windows::Forms::Button());
			this->foureirFilter = (gcnew System::Windows::Forms::TrackBar());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SobelFilter = (gcnew System::Windows::Forms::Button());
			this->gaussianFilter = (gcnew System::Windows::Forms::Button());
			this->MedianFilter = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->PointProcessing = (gcnew System::Windows::Forms::TabPage());
			this->pointProcessingGuide = (gcnew System::Windows::Forms::Button());
			this->threshBox = (gcnew System::Windows::Forms::TextBox());
			this->logBox = (gcnew System::Windows::Forms::TextBox());
			this->powerBox = (gcnew System::Windows::Forms::TextBox());
			this->maxRange = (gcnew System::Windows::Forms::TextBox());
			this->minRange = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->saveGrayRange = (gcnew System::Windows::Forms::Button());
			this->secHighlightGray = (gcnew System::Windows::Forms::Button());
			this->MinValue = (gcnew System::Windows::Forms::TrackBar());
			this->labelMin = (gcnew System::Windows::Forms::Label());
			this->labelMax = (gcnew System::Windows::Forms::Label());
			this->HighlightGray = (gcnew System::Windows::Forms::Button());
			this->MaxVlaue = (gcnew System::Windows::Forms::TrackBar());
			this->ThreshLabel = (gcnew System::Windows::Forms::Label());
			this->threshHoldingCnfrm = (gcnew System::Windows::Forms::Button());
			this->threshHoldingS = (gcnew System::Windows::Forms::TrackBar());
			this->SavePlane = (gcnew System::Windows::Forms::Button());
			this->cnfrmBitPlaneSelection = (gcnew System::Windows::Forms::Button());
			this->ChoosenPlane = (gcnew System::Windows::Forms::Label());
			this->PlaneLabel = (gcnew System::Windows::Forms::Label());
			this->SelectedBitLabel = (gcnew System::Windows::Forms::Label());
			this->logLabel = (gcnew System::Windows::Forms::Label());
			this->BitPlaneBox = (gcnew System::Windows::Forms::ComboBox());
			this->cnfrmChanges = (gcnew System::Windows::Forms::Button());
			this->logTransf = (gcnew System::Windows::Forms::TrackBar());
			this->bightLabel = (gcnew System::Windows::Forms::Label());
			this->cnfrmPowerTrans = (gcnew System::Windows::Forms::Button());
			this->powerTrans = (gcnew System::Windows::Forms::TrackBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->cnfrmBlind = (gcnew System::Windows::Forms::Button());
			this->Blind = (gcnew System::Windows::Forms::Button());
			this->selectImg = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->grayLevelSlicing = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->logTrans = (gcnew System::Windows::Forms::Button());
			this->powerTransformation = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->imageOperations = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->ConfCrop = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->ZoomOut = (gcnew System::Windows::Forms::Button());
			this->ZoomIn = (gcnew System::Windows::Forms::Button());
			this->SkewDownLeft = (gcnew System::Windows::Forms::Button());
			this->SkewDownRight = (gcnew System::Windows::Forms::Button());
			this->SkewUpLeft = (gcnew System::Windows::Forms::Button());
			this->SkewUpRight = (gcnew System::Windows::Forms::Button());
			this->CustomRotation = (gcnew System::Windows::Forms::Button());
			this->RotationVar = (gcnew System::Windows::Forms::TextBox());
			this->TransY = (gcnew System::Windows::Forms::TextBox());
			this->TransX = (gcnew System::Windows::Forms::TextBox());
			this->RotateLabel = (gcnew System::Windows::Forms::Label());
			this->RotationLabel = (gcnew System::Windows::Forms::Label());
			this->RotateLeft = (gcnew System::Windows::Forms::Button());
			this->RotateRight = (gcnew System::Windows::Forms::Button());
			this->xmirror = (gcnew System::Windows::Forms::Button());
			this->xymirror = (gcnew System::Windows::Forms::Button());
			this->ymirror = (gcnew System::Windows::Forms::Button());
			this->CustomTranslation = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->DownRight = (gcnew System::Windows::Forms::Button());
			this->DownLeft = (gcnew System::Windows::Forms::Button());
			this->UpRight = (gcnew System::Windows::Forms::Button());
			this->UpLeft = (gcnew System::Windows::Forms::Button());
			this->btnDown = (gcnew System::Windows::Forms::Button());
			this->Right = (gcnew System::Windows::Forms::Button());
			this->Left = (gcnew System::Windows::Forms::Button());
			this->btnUp = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Save2 = (gcnew System::Windows::Forms::Button());
			this->Reset2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Zoom = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->Translation = (gcnew System::Windows::Forms::Button());
			this->index = (gcnew System::Windows::Forms::TabPage());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SaveImg = (gcnew System::Windows::Forms::Button());
			this->ResetImg = (gcnew System::Windows::Forms::Button());
			this->RGB2Gray = (gcnew System::Windows::Forms::Button());
			this->ImageProberties = (gcnew System::Windows::Forms::Button());
			this->LoadImg = (gcnew System::Windows::Forms::Button());
			this->mainTabC = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->GaussianNoise = (gcnew System::Windows::Forms::Button());
			this->saltAndPepper = (gcnew System::Windows::Forms::Button());
			this->ofd2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Save3 = (gcnew System::Windows::Forms::Button());
			this->Reset3 = (gcnew System::Windows::Forms::Button());
			this->RGB2Gray2 = (gcnew System::Windows::Forms::Button());
			this->darkTheme = (gcnew System::Windows::Forms::Button());
			this->greyTheme = (gcnew System::Windows::Forms::Button());
			this->lightTheme = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->ImageSegmentation->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ffs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FourierFilter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recog))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxV))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->laplacianScroll))->BeginInit();
			this->panel5->SuspendLayout();
			this->NeighborhoodOperations->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dbox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vbox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Hbox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gaussianFilterS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MedianScroll))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->circularS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->foureirFilter))->BeginInit();
			this->panel4->SuspendLayout();
			this->PointProcessing->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinValue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxVlaue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshHoldingS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logTransf))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->powerTrans))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->imageOperations->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			this->index->SuspendLayout();
			this->panel1->SuspendLayout();
			this->mainTabC->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(824, 91);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(519, 407);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// ofd
			// 
			this->ofd->FilterIndex = 2;
			this->ofd->RestoreDirectory = true;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->label2->Location = System::Drawing::Point(951, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(269, 45);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Omar\'s ToolBox";
			// 
			// ImageSegmentation
			// 
			this->ImageSegmentation->BackColor = System::Drawing::Color::White;
			this->ImageSegmentation->Controls->Add(this->segmentationGuide);
			this->ImageSegmentation->Controls->Add(this->saveFFS);
			this->ImageSegmentation->Controls->Add(this->ffs);
			this->ImageSegmentation->Controls->Add(this->lowPass);
			this->ImageSegmentation->Controls->Add(this->LPF);
			this->ImageSegmentation->Controls->Add(this->FourierFilter);
			this->ImageSegmentation->Controls->Add(this->Recog);
			this->ImageSegmentation->Controls->Add(this->BoxD);
			this->ImageSegmentation->Controls->Add(this->BoxV);
			this->ImageSegmentation->Controls->Add(this->BoxH);
			this->ImageSegmentation->Controls->Add(this->labelV);
			this->ImageSegmentation->Controls->Add(this->labelD);
			this->ImageSegmentation->Controls->Add(this->labelH);
			this->ImageSegmentation->Controls->Add(this->SaveSobel);
			this->ImageSegmentation->Controls->Add(this->Sobel);
			this->ImageSegmentation->Controls->Add(this->ThreshhHold);
			this->ImageSegmentation->Controls->Add(this->cnfrmThresholding);
			this->ImageSegmentation->Controls->Add(this->threshS);
			this->ImageSegmentation->Controls->Add(this->laplaceLabel);
			this->ImageSegmentation->Controls->Add(this->saveEdges);
			this->ImageSegmentation->Controls->Add(this->laplacianScroll);
			this->ImageSegmentation->Controls->Add(this->panel5);
			this->ImageSegmentation->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ImageSegmentation->Location = System::Drawing::Point(4, 29);
			this->ImageSegmentation->Name = L"ImageSegmentation";
			this->ImageSegmentation->Padding = System::Windows::Forms::Padding(3);
			this->ImageSegmentation->Size = System::Drawing::Size(810, 582);
			this->ImageSegmentation->TabIndex = 4;
			this->ImageSegmentation->Text = L"LocateObjects&Boundaries";
			// 
			// segmentationGuide
			// 
			this->segmentationGuide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"segmentationGuide.Image")));
			this->segmentationGuide->Location = System::Drawing::Point(784, 6);
			this->segmentationGuide->Name = L"segmentationGuide";
			this->segmentationGuide->Size = System::Drawing::Size(20, 23);
			this->segmentationGuide->TabIndex = 84;
			this->segmentationGuide->UseVisualStyleBackColor = true;
			this->segmentationGuide->Click += gcnew System::EventHandler(this, &MyForm::segmentationGuide_Click);
			// 
			// saveFFS
			// 
			this->saveFFS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->saveFFS->FlatAppearance->BorderSize = 0;
			this->saveFFS->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveFFS->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->saveFFS->ForeColor = System::Drawing::Color::Gainsboro;
			this->saveFFS->Location = System::Drawing::Point(422, 248);
			this->saveFFS->Name = L"saveFFS";
			this->saveFFS->Size = System::Drawing::Size(172, 95);
			this->saveFFS->TabIndex = 83;
			this->saveFFS->Text = L"Apply Filter";
			this->saveFFS->UseVisualStyleBackColor = false;
			this->saveFFS->Visible = false;
			this->saveFFS->Click += gcnew System::EventHandler(this, &MyForm::saveFFS_Click);
			// 
			// ffs
			// 
			this->ffs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->ffs->Location = System::Drawing::Point(265, 122);
			this->ffs->Maximum = 200;
			this->ffs->Minimum = 1;
			this->ffs->Name = L"ffs";
			this->ffs->Size = System::Drawing::Size(531, 45);
			this->ffs->TabIndex = 82;
			this->ffs->Value = 200;
			this->ffs->Visible = false;
			this->ffs->Scroll += gcnew System::EventHandler(this, &MyForm::ffs_Scroll);
			// 
			// lowPass
			// 
			this->lowPass->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->lowPass->FlatAppearance->BorderSize = 0;
			this->lowPass->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lowPass->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lowPass->ForeColor = System::Drawing::Color::Gainsboro;
			this->lowPass->Location = System::Drawing::Point(422, 248);
			this->lowPass->Name = L"lowPass";
			this->lowPass->Size = System::Drawing::Size(172, 95);
			this->lowPass->TabIndex = 81;
			this->lowPass->Text = L"Apply Filter";
			this->lowPass->UseVisualStyleBackColor = false;
			this->lowPass->Visible = false;
			this->lowPass->Click += gcnew System::EventHandler(this, &MyForm::lowPass_Click);
			// 
			// LPF
			// 
			this->LPF->AutoSize = true;
			this->LPF->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LPF->Location = System::Drawing::Point(263, 90);
			this->LPF->Name = L"LPF";
			this->LPF->Size = System::Drawing::Size(539, 23);
			this->LPF->TabIndex = 80;
			this->LPF->Text = L"Minimum Filter Radius                           Maximum Filter Radius";
			this->LPF->Visible = false;
			// 
			// FourierFilter
			// 
			this->FourierFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->FourierFilter->Location = System::Drawing::Point(265, 122);
			this->FourierFilter->Maximum = 200;
			this->FourierFilter->Minimum = 1;
			this->FourierFilter->Name = L"FourierFilter";
			this->FourierFilter->Size = System::Drawing::Size(531, 45);
			this->FourierFilter->TabIndex = 79;
			this->FourierFilter->Value = 1;
			this->FourierFilter->Visible = false;
			this->FourierFilter->Scroll += gcnew System::EventHandler(this, &MyForm::FourierFilter_Scroll);
			// 
			// Recog
			// 
			this->Recog->Location = System::Drawing::Point(263, 43);
			this->Recog->Name = L"Recog";
			this->Recog->Size = System::Drawing::Size(533, 471);
			this->Recog->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Recog->TabIndex = 78;
			this->Recog->TabStop = false;
			this->Recog->Visible = false;
			// 
			// BoxD
			// 
			this->BoxD->Location = System::Drawing::Point(390, 363);
			this->BoxD->Name = L"BoxD";
			this->BoxD->Size = System::Drawing::Size(259, 211);
			this->BoxD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->BoxD->TabIndex = 77;
			this->BoxD->TabStop = false;
			this->BoxD->Visible = false;
			// 
			// BoxV
			// 
			this->BoxV->Location = System::Drawing::Point(538, 122);
			this->BoxV->Name = L"BoxV";
			this->BoxV->Size = System::Drawing::Size(259, 211);
			this->BoxV->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->BoxV->TabIndex = 76;
			this->BoxV->TabStop = false;
			this->BoxV->Visible = false;
			// 
			// BoxH
			// 
			this->BoxH->Location = System::Drawing::Point(263, 122);
			this->BoxH->Name = L"BoxH";
			this->BoxH->Size = System::Drawing::Size(259, 211);
			this->BoxH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->BoxH->TabIndex = 75;
			this->BoxH->TabStop = false;
			this->BoxH->Visible = false;
			// 
			// labelV
			// 
			this->labelV->AutoSize = true;
			this->labelV->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelV->Location = System::Drawing::Point(629, 90);
			this->labelV->Name = L"labelV";
			this->labelV->Size = System::Drawing::Size(113, 23);
			this->labelV->TabIndex = 74;
			this->labelV->Text = L"Vertical View";
			this->labelV->Visible = false;
			// 
			// labelD
			// 
			this->labelD->AutoSize = true;
			this->labelD->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelD->Location = System::Drawing::Point(461, 338);
			this->labelD->Name = L"labelD";
			this->labelD->Size = System::Drawing::Size(115, 23);
			this->labelD->TabIndex = 73;
			this->labelD->Text = L"Diagonal View";
			this->labelD->Visible = false;
			// 
			// labelH
			// 
			this->labelH->AutoSize = true;
			this->labelH->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelH->Location = System::Drawing::Point(311, 90);
			this->labelH->Name = L"labelH";
			this->labelH->Size = System::Drawing::Size(130, 23);
			this->labelH->TabIndex = 72;
			this->labelH->Text = L"Horizontal View";
			this->labelH->Visible = false;
			// 
			// SaveSobel
			// 
			this->SaveSobel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->SaveSobel->FlatAppearance->BorderSize = 0;
			this->SaveSobel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveSobel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SaveSobel->ForeColor = System::Drawing::Color::Gainsboro;
			this->SaveSobel->Location = System::Drawing::Point(605, 7);
			this->SaveSobel->Name = L"SaveSobel";
			this->SaveSobel->Size = System::Drawing::Size(137, 70);
			this->SaveSobel->TabIndex = 71;
			this->SaveSobel->Text = L"Save Changes";
			this->SaveSobel->UseVisualStyleBackColor = false;
			this->SaveSobel->Visible = false;
			this->SaveSobel->Click += gcnew System::EventHandler(this, &MyForm::SaveSobel_Click);
			// 
			// Sobel
			// 
			this->Sobel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->Sobel->FlatAppearance->BorderSize = 0;
			this->Sobel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Sobel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Sobel->ForeColor = System::Drawing::Color::Gainsboro;
			this->Sobel->Location = System::Drawing::Point(265, 6);
			this->Sobel->Name = L"Sobel";
			this->Sobel->Size = System::Drawing::Size(137, 70);
			this->Sobel->TabIndex = 70;
			this->Sobel->Text = L"Apply Filter";
			this->Sobel->UseVisualStyleBackColor = false;
			this->Sobel->Visible = false;
			this->Sobel->Click += gcnew System::EventHandler(this, &MyForm::Sobel_Click);
			// 
			// ThreshhHold
			// 
			this->ThreshhHold->AutoSize = true;
			this->ThreshhHold->Location = System::Drawing::Point(259, 123);
			this->ThreshhHold->Name = L"ThreshhHold";
			this->ThreshhHold->Size = System::Drawing::Size(537, 19);
			this->ThreshhHold->TabIndex = 40;
			this->ThreshhHold->Text = L"Min Kernel Size                                                      Max Kernel S"
				L"ize\r\n";
			this->ThreshhHold->Visible = false;
			// 
			// cnfrmThresholding
			// 
			this->cnfrmThresholding->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->cnfrmThresholding->FlatAppearance->BorderSize = 0;
			this->cnfrmThresholding->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmThresholding->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmThresholding->ForeColor = System::Drawing::Color::Black;
			this->cnfrmThresholding->Location = System::Drawing::Point(405, 280);
			this->cnfrmThresholding->Name = L"cnfrmThresholding";
			this->cnfrmThresholding->Size = System::Drawing::Size(206, 80);
			this->cnfrmThresholding->TabIndex = 39;
			this->cnfrmThresholding->Text = L"Save Changes";
			this->cnfrmThresholding->UseVisualStyleBackColor = false;
			this->cnfrmThresholding->Visible = false;
			this->cnfrmThresholding->Click += gcnew System::EventHandler(this, &MyForm::cnfrmThresholding_Click);
			// 
			// threshS
			// 
			this->threshS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->threshS->LargeChange = 2;
			this->threshS->Location = System::Drawing::Point(263, 145);
			this->threshS->Maximum = 15;
			this->threshS->Minimum = 1;
			this->threshS->Name = L"threshS";
			this->threshS->Size = System::Drawing::Size(534, 45);
			this->threshS->TabIndex = 38;
			this->threshS->Value = 1;
			this->threshS->Visible = false;
			this->threshS->Scroll += gcnew System::EventHandler(this, &MyForm::threshS_Scroll);
			// 
			// laplaceLabel
			// 
			this->laplaceLabel->AutoSize = true;
			this->laplaceLabel->Location = System::Drawing::Point(259, 123);
			this->laplaceLabel->Name = L"laplaceLabel";
			this->laplaceLabel->Size = System::Drawing::Size(537, 19);
			this->laplaceLabel->TabIndex = 37;
			this->laplaceLabel->Text = L"Min Kernel Size                                                      Max Kernel S"
				L"ize\r\n";
			this->laplaceLabel->Visible = false;
			// 
			// saveEdges
			// 
			this->saveEdges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->saveEdges->FlatAppearance->BorderSize = 0;
			this->saveEdges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveEdges->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->saveEdges->ForeColor = System::Drawing::Color::Black;
			this->saveEdges->Location = System::Drawing::Point(405, 280);
			this->saveEdges->Name = L"saveEdges";
			this->saveEdges->Size = System::Drawing::Size(206, 80);
			this->saveEdges->TabIndex = 36;
			this->saveEdges->Text = L"Save Changes";
			this->saveEdges->UseVisualStyleBackColor = false;
			this->saveEdges->Visible = false;
			this->saveEdges->Click += gcnew System::EventHandler(this, &MyForm::saveEdges_Click);
			// 
			// laplacianScroll
			// 
			this->laplacianScroll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->laplacianScroll->LargeChange = 2;
			this->laplacianScroll->Location = System::Drawing::Point(263, 145);
			this->laplacianScroll->Maximum = 15;
			this->laplacianScroll->Minimum = 1;
			this->laplacianScroll->Name = L"laplacianScroll";
			this->laplacianScroll->Size = System::Drawing::Size(534, 45);
			this->laplacianScroll->TabIndex = 10;
			this->laplacianScroll->Value = 1;
			this->laplacianScroll->Visible = false;
			this->laplacianScroll->Scroll += gcnew System::EventHandler(this, &MyForm::laplacianScroll_Scroll);
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel5->Controls->Add(this->button18);
			this->panel5->Controls->Add(this->Fourier2);
			this->panel5->Controls->Add(this->Fourier);
			this->panel5->Controls->Add(this->SobelEdges);
			this->panel5->Controls->Add(this->button15);
			this->panel5->Controls->Add(this->LaplacianDetection);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel5->Location = System::Drawing::Point(3, 3);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(254, 576);
			this->panel5->TabIndex = 9;
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button18->Dock = System::Windows::Forms::DockStyle::Top;
			this->button18->FlatAppearance->BorderSize = 0;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button18->ForeColor = System::Drawing::Color::Gainsboro;
			this->button18->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button18->Location = System::Drawing::Point(0, 325);
			this->button18->Name = L"button18";
			this->button18->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button18->Size = System::Drawing::Size(254, 65);
			this->button18->TabIndex = 5;
			this->button18->Text = L"  Mathematical Shapes \r\n        Detector";
			this->button18->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button18->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::ShapeDetection_Click);
			// 
			// Fourier2
			// 
			this->Fourier2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Fourier2->Dock = System::Windows::Forms::DockStyle::Top;
			this->Fourier2->FlatAppearance->BorderSize = 0;
			this->Fourier2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Fourier2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Fourier2->ForeColor = System::Drawing::Color::Gainsboro;
			this->Fourier2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Fourier2->Location = System::Drawing::Point(0, 260);
			this->Fourier2->Name = L"Fourier2";
			this->Fourier2->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->Fourier2->Size = System::Drawing::Size(254, 65);
			this->Fourier2->TabIndex = 7;
			this->Fourier2->Text = L"Denying the Main Object";
			this->Fourier2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Fourier2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Fourier2->UseVisualStyleBackColor = false;
			this->Fourier2->Click += gcnew System::EventHandler(this, &MyForm::Fourier2_Click);
			// 
			// Fourier
			// 
			this->Fourier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Fourier->Dock = System::Windows::Forms::DockStyle::Top;
			this->Fourier->FlatAppearance->BorderSize = 0;
			this->Fourier->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Fourier->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Fourier->ForeColor = System::Drawing::Color::Gainsboro;
			this->Fourier->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Fourier->Location = System::Drawing::Point(0, 195);
			this->Fourier->Name = L"Fourier";
			this->Fourier->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->Fourier->Size = System::Drawing::Size(254, 65);
			this->Fourier->TabIndex = 6;
			this->Fourier->Text = L"Detecting the Main Object";
			this->Fourier->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Fourier->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Fourier->UseVisualStyleBackColor = false;
			this->Fourier->Click += gcnew System::EventHandler(this, &MyForm::Fourier_Click);
			// 
			// SobelEdges
			// 
			this->SobelEdges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SobelEdges->Dock = System::Windows::Forms::DockStyle::Top;
			this->SobelEdges->FlatAppearance->BorderSize = 0;
			this->SobelEdges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SobelEdges->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SobelEdges->ForeColor = System::Drawing::Color::Gainsboro;
			this->SobelEdges->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SobelEdges->Location = System::Drawing::Point(0, 130);
			this->SobelEdges->Name = L"SobelEdges";
			this->SobelEdges->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->SobelEdges->Size = System::Drawing::Size(254, 65);
			this->SobelEdges->TabIndex = 4;
			this->SobelEdges->Text = L"Detecting all Edges\'s Directions";
			this->SobelEdges->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SobelEdges->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->SobelEdges->UseVisualStyleBackColor = false;
			this->SobelEdges->Click += gcnew System::EventHandler(this, &MyForm::SobelEdges_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button15->Dock = System::Windows::Forms::DockStyle::Top;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Gainsboro;
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(0, 65);
			this->button15->Name = L"button15";
			this->button15->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button15->Size = System::Drawing::Size(254, 65);
			this->button15->TabIndex = 3;
			this->button15->Text = L"Detecting Certain Edges of the Images";
			this->button15->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::ThreshEdge_Click);
			// 
			// LaplacianDetection
			// 
			this->LaplacianDetection->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->LaplacianDetection->Dock = System::Windows::Forms::DockStyle::Top;
			this->LaplacianDetection->FlatAppearance->BorderSize = 0;
			this->LaplacianDetection->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LaplacianDetection->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LaplacianDetection->ForeColor = System::Drawing::Color::Gainsboro;
			this->LaplacianDetection->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->LaplacianDetection->Location = System::Drawing::Point(0, 0);
			this->LaplacianDetection->Name = L"LaplacianDetection";
			this->LaplacianDetection->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->LaplacianDetection->Size = System::Drawing::Size(254, 65);
			this->LaplacianDetection->TabIndex = 2;
			this->LaplacianDetection->Text = L" Detecting Thin Edges";
			this->LaplacianDetection->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->LaplacianDetection->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->LaplacianDetection->UseVisualStyleBackColor = false;
			this->LaplacianDetection->Click += gcnew System::EventHandler(this, &MyForm::LaplacianDetection_Click);
			// 
			// NeighborhoodOperations
			// 
			this->NeighborhoodOperations->BackColor = System::Drawing::Color::White;
			this->NeighborhoodOperations->Controls->Add(this->FiltersGuide);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmLaplacian);
			this->NeighborhoodOperations->Controls->Add(this->applyingLaplacian);
			this->NeighborhoodOperations->Controls->Add(this->SelectedLabel);
			this->NeighborhoodOperations->Controls->Add(this->Dbox);
			this->NeighborhoodOperations->Controls->Add(this->selectLabel);
			this->NeighborhoodOperations->Controls->Add(this->Vbox);
			this->NeighborhoodOperations->Controls->Add(this->fLabel);
			this->NeighborhoodOperations->Controls->Add(this->Hbox);
			this->NeighborhoodOperations->Controls->Add(this->laplacianFilters);
			this->NeighborhoodOperations->Controls->Add(this->Vlabel);
			this->NeighborhoodOperations->Controls->Add(this->Dlabel);
			this->NeighborhoodOperations->Controls->Add(this->Hlabel);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmSobel);
			this->NeighborhoodOperations->Controls->Add(this->applyingSobel);
			this->NeighborhoodOperations->Controls->Add(this->gaussianFilterS);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmGaussSave);
			this->NeighborhoodOperations->Controls->Add(this->MedianScroll);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmMedian);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmCone);
			this->NeighborhoodOperations->Controls->Add(this->coneFilter);
			this->NeighborhoodOperations->Controls->Add(this->circularS);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmCircular);
			this->NeighborhoodOperations->Controls->Add(this->trackBar2);
			this->NeighborhoodOperations->Controls->Add(this->button16);
			this->NeighborhoodOperations->Controls->Add(this->trackBar1);
			this->NeighborhoodOperations->Controls->Add(this->label16);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmTraditional);
			this->NeighborhoodOperations->Controls->Add(this->dftLabel);
			this->NeighborhoodOperations->Controls->Add(this->cnfrmChangess);
			this->NeighborhoodOperations->Controls->Add(this->foureirFilter);
			this->NeighborhoodOperations->Controls->Add(this->panel4);
			this->NeighborhoodOperations->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->NeighborhoodOperations->Location = System::Drawing::Point(4, 29);
			this->NeighborhoodOperations->Name = L"NeighborhoodOperations";
			this->NeighborhoodOperations->Padding = System::Windows::Forms::Padding(3);
			this->NeighborhoodOperations->Size = System::Drawing::Size(810, 582);
			this->NeighborhoodOperations->TabIndex = 3;
			this->NeighborhoodOperations->Text = L"Filters";
			// 
			// FiltersGuide
			// 
			this->FiltersGuide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FiltersGuide.Image")));
			this->FiltersGuide->Location = System::Drawing::Point(784, 6);
			this->FiltersGuide->Name = L"FiltersGuide";
			this->FiltersGuide->Size = System::Drawing::Size(20, 23);
			this->FiltersGuide->TabIndex = 76;
			this->FiltersGuide->UseVisualStyleBackColor = true;
			this->FiltersGuide->Click += gcnew System::EventHandler(this, &MyForm::FiltersGuide_Click);
			// 
			// cnfrmLaplacian
			// 
			this->cnfrmLaplacian->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->cnfrmLaplacian->FlatAppearance->BorderSize = 0;
			this->cnfrmLaplacian->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmLaplacian->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmLaplacian->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmLaplacian->Location = System::Drawing::Point(580, 288);
			this->cnfrmLaplacian->Name = L"cnfrmLaplacian";
			this->cnfrmLaplacian->Size = System::Drawing::Size(176, 100);
			this->cnfrmLaplacian->TabIndex = 75;
			this->cnfrmLaplacian->Text = L"Save Changes";
			this->cnfrmLaplacian->UseVisualStyleBackColor = false;
			this->cnfrmLaplacian->Visible = false;
			this->cnfrmLaplacian->Click += gcnew System::EventHandler(this, &MyForm::cnfrmLaplacian_Click);
			// 
			// applyingLaplacian
			// 
			this->applyingLaplacian->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->applyingLaplacian->FlatAppearance->BorderSize = 0;
			this->applyingLaplacian->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->applyingLaplacian->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->applyingLaplacian->ForeColor = System::Drawing::Color::Gainsboro;
			this->applyingLaplacian->Location = System::Drawing::Point(263, 288);
			this->applyingLaplacian->Name = L"applyingLaplacian";
			this->applyingLaplacian->Size = System::Drawing::Size(176, 100);
			this->applyingLaplacian->TabIndex = 74;
			this->applyingLaplacian->Text = L"Apply Filter";
			this->applyingLaplacian->UseVisualStyleBackColor = false;
			this->applyingLaplacian->Visible = false;
			this->applyingLaplacian->Click += gcnew System::EventHandler(this, &MyForm::applyingLaplacian_Click);
			// 
			// SelectedLabel
			// 
			this->SelectedLabel->AutoSize = true;
			this->SelectedLabel->Location = System::Drawing::Point(455, 204);
			this->SelectedLabel->Name = L"SelectedLabel";
			this->SelectedLabel->Size = System::Drawing::Size(16, 19);
			this->SelectedLabel->TabIndex = 73;
			this->SelectedLabel->Text = L"\?";
			this->SelectedLabel->Visible = false;
			// 
			// Dbox
			// 
			this->Dbox->Location = System::Drawing::Point(374, 363);
			this->Dbox->Name = L"Dbox";
			this->Dbox->Size = System::Drawing::Size(259, 211);
			this->Dbox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Dbox->TabIndex = 69;
			this->Dbox->TabStop = false;
			this->Dbox->Visible = false;
			// 
			// selectLabel
			// 
			this->selectLabel->AutoSize = true;
			this->selectLabel->Location = System::Drawing::Point(338, 204);
			this->selectLabel->Name = L"selectLabel";
			this->selectLabel->Size = System::Drawing::Size(111, 19);
			this->selectLabel->TabIndex = 72;
			this->selectLabel->Text = L"Selected Filter:";
			this->selectLabel->Visible = false;
			// 
			// Vbox
			// 
			this->Vbox->Location = System::Drawing::Point(529, 122);
			this->Vbox->Name = L"Vbox";
			this->Vbox->Size = System::Drawing::Size(259, 211);
			this->Vbox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Vbox->TabIndex = 68;
			this->Vbox->TabStop = false;
			this->Vbox->Visible = false;
			// 
			// fLabel
			// 
			this->fLabel->AutoSize = true;
			this->fLabel->Location = System::Drawing::Point(381, 161);
			this->fLabel->Name = L"fLabel";
			this->fLabel->Size = System::Drawing::Size(62, 19);
			this->fLabel->TabIndex = 71;
			this->fLabel->Text = L"Filters :";
			this->fLabel->Visible = false;
			// 
			// Hbox
			// 
			this->Hbox->Location = System::Drawing::Point(234, 121);
			this->Hbox->Name = L"Hbox";
			this->Hbox->Size = System::Drawing::Size(259, 211);
			this->Hbox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Hbox->TabIndex = 67;
			this->Hbox->TabStop = false;
			this->Hbox->Visible = false;
			// 
			// laplacianFilters
			// 
			this->laplacianFilters->FormattingEnabled = true;
			this->laplacianFilters->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Type 4 filter", L"Type 8 filter", L"Type -4 filter",
					L"Type -8 filter"
			});
			this->laplacianFilters->Location = System::Drawing::Point(449, 158);
			this->laplacianFilters->Name = L"laplacianFilters";
			this->laplacianFilters->Size = System::Drawing::Size(121, 27);
			this->laplacianFilters->TabIndex = 70;
			this->laplacianFilters->Visible = false;
			this->laplacianFilters->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::laplacianFilters_SelectedIndexChanged);
			// 
			// Vlabel
			// 
			this->Vlabel->AutoSize = true;
			this->Vlabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Vlabel->Location = System::Drawing::Point(613, 90);
			this->Vlabel->Name = L"Vlabel";
			this->Vlabel->Size = System::Drawing::Size(113, 23);
			this->Vlabel->TabIndex = 66;
			this->Vlabel->Text = L"Vertical View";
			this->Vlabel->Visible = false;
			// 
			// Dlabel
			// 
			this->Dlabel->AutoSize = true;
			this->Dlabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Dlabel->Location = System::Drawing::Point(445, 338);
			this->Dlabel->Name = L"Dlabel";
			this->Dlabel->Size = System::Drawing::Size(115, 23);
			this->Dlabel->TabIndex = 65;
			this->Dlabel->Text = L"Diagonal View";
			this->Dlabel->Visible = false;
			// 
			// Hlabel
			// 
			this->Hlabel->AutoSize = true;
			this->Hlabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Hlabel->Location = System::Drawing::Point(295, 90);
			this->Hlabel->Name = L"Hlabel";
			this->Hlabel->Size = System::Drawing::Size(130, 23);
			this->Hlabel->TabIndex = 64;
			this->Hlabel->Text = L"Horizontal View";
			this->Hlabel->Visible = false;
			// 
			// cnfrmSobel
			// 
			this->cnfrmSobel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->cnfrmSobel->FlatAppearance->BorderSize = 0;
			this->cnfrmSobel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmSobel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmSobel->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmSobel->Location = System::Drawing::Point(589, 7);
			this->cnfrmSobel->Name = L"cnfrmSobel";
			this->cnfrmSobel->Size = System::Drawing::Size(137, 70);
			this->cnfrmSobel->TabIndex = 63;
			this->cnfrmSobel->Text = L"Save Changes";
			this->cnfrmSobel->UseVisualStyleBackColor = false;
			this->cnfrmSobel->Visible = false;
			this->cnfrmSobel->Click += gcnew System::EventHandler(this, &MyForm::cnfrmSobel_Click);
			// 
			// applyingSobel
			// 
			this->applyingSobel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->applyingSobel->FlatAppearance->BorderSize = 0;
			this->applyingSobel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->applyingSobel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->applyingSobel->ForeColor = System::Drawing::Color::Gainsboro;
			this->applyingSobel->Location = System::Drawing::Point(249, 6);
			this->applyingSobel->Name = L"applyingSobel";
			this->applyingSobel->Size = System::Drawing::Size(137, 70);
			this->applyingSobel->TabIndex = 62;
			this->applyingSobel->Text = L"Apply Filter";
			this->applyingSobel->UseVisualStyleBackColor = false;
			this->applyingSobel->Visible = false;
			this->applyingSobel->Click += gcnew System::EventHandler(this, &MyForm::applyingSobel_Click);
			// 
			// gaussianFilterS
			// 
			this->gaussianFilterS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->gaussianFilterS->LargeChange = 2;
			this->gaussianFilterS->Location = System::Drawing::Point(230, 140);
			this->gaussianFilterS->Maximum = 15;
			this->gaussianFilterS->Minimum = 3;
			this->gaussianFilterS->Name = L"gaussianFilterS";
			this->gaussianFilterS->Size = System::Drawing::Size(567, 45);
			this->gaussianFilterS->TabIndex = 61;
			this->gaussianFilterS->Value = 3;
			this->gaussianFilterS->Visible = false;
			this->gaussianFilterS->Scroll += gcnew System::EventHandler(this, &MyForm::gaussianFilterS_Scroll);
			// 
			// cnfrmGaussSave
			// 
			this->cnfrmGaussSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(56)));
			this->cnfrmGaussSave->FlatAppearance->BorderSize = 0;
			this->cnfrmGaussSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmGaussSave->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmGaussSave->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmGaussSave->Location = System::Drawing::Point(414, 265);
			this->cnfrmGaussSave->Name = L"cnfrmGaussSave";
			this->cnfrmGaussSave->Size = System::Drawing::Size(176, 100);
			this->cnfrmGaussSave->TabIndex = 60;
			this->cnfrmGaussSave->Text = L"Confirm Changes";
			this->cnfrmGaussSave->UseVisualStyleBackColor = false;
			this->cnfrmGaussSave->Visible = false;
			this->cnfrmGaussSave->Click += gcnew System::EventHandler(this, &MyForm::cnfrmGaussSave_Click);
			// 
			// MedianScroll
			// 
			this->MedianScroll->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->MedianScroll->LargeChange = 2;
			this->MedianScroll->Location = System::Drawing::Point(230, 140);
			this->MedianScroll->Maximum = 15;
			this->MedianScroll->Minimum = 3;
			this->MedianScroll->Name = L"MedianScroll";
			this->MedianScroll->Size = System::Drawing::Size(567, 45);
			this->MedianScroll->TabIndex = 59;
			this->MedianScroll->Value = 3;
			this->MedianScroll->Visible = false;
			this->MedianScroll->Scroll += gcnew System::EventHandler(this, &MyForm::MedianScroll_Scroll);
			// 
			// cnfrmMedian
			// 
			this->cnfrmMedian->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
				static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->cnfrmMedian->FlatAppearance->BorderSize = 0;
			this->cnfrmMedian->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmMedian->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmMedian->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmMedian->Location = System::Drawing::Point(414, 265);
			this->cnfrmMedian->Name = L"cnfrmMedian";
			this->cnfrmMedian->Size = System::Drawing::Size(176, 100);
			this->cnfrmMedian->TabIndex = 58;
			this->cnfrmMedian->Text = L"Confirm Changes";
			this->cnfrmMedian->UseVisualStyleBackColor = false;
			this->cnfrmMedian->Visible = false;
			this->cnfrmMedian->Click += gcnew System::EventHandler(this, &MyForm::cnfrmMedian_Click);
			// 
			// cnfrmCone
			// 
			this->cnfrmCone->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->cnfrmCone->FlatAppearance->BorderSize = 0;
			this->cnfrmCone->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmCone->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmCone->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmCone->Location = System::Drawing::Point(529, 235);
			this->cnfrmCone->Name = L"cnfrmCone";
			this->cnfrmCone->Size = System::Drawing::Size(176, 100);
			this->cnfrmCone->TabIndex = 57;
			this->cnfrmCone->Text = L"Save Changes";
			this->cnfrmCone->UseVisualStyleBackColor = false;
			this->cnfrmCone->Visible = false;
			this->cnfrmCone->Click += gcnew System::EventHandler(this, &MyForm::cnfrmCone_Click);
			// 
			// coneFilter
			// 
			this->coneFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->coneFilter->FlatAppearance->BorderSize = 0;
			this->coneFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->coneFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->coneFilter->ForeColor = System::Drawing::Color::Gainsboro;
			this->coneFilter->Location = System::Drawing::Point(249, 235);
			this->coneFilter->Name = L"coneFilter";
			this->coneFilter->Size = System::Drawing::Size(176, 100);
			this->coneFilter->TabIndex = 56;
			this->coneFilter->Text = L"Apply Filter";
			this->coneFilter->UseVisualStyleBackColor = false;
			this->coneFilter->Visible = false;
			this->coneFilter->Click += gcnew System::EventHandler(this, &MyForm::coneFilter_Click);
			// 
			// circularS
			// 
			this->circularS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->circularS->LargeChange = 2;
			this->circularS->Location = System::Drawing::Point(230, 140);
			this->circularS->Maximum = 15;
			this->circularS->Minimum = 3;
			this->circularS->Name = L"circularS";
			this->circularS->Size = System::Drawing::Size(567, 45);
			this->circularS->TabIndex = 55;
			this->circularS->Value = 3;
			this->circularS->Visible = false;
			this->circularS->Scroll += gcnew System::EventHandler(this, &MyForm::circularS_Scroll);
			// 
			// cnfrmCircular
			// 
			this->cnfrmCircular->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->cnfrmCircular->FlatAppearance->BorderSize = 0;
			this->cnfrmCircular->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmCircular->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmCircular->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmCircular->Location = System::Drawing::Point(414, 265);
			this->cnfrmCircular->Name = L"cnfrmCircular";
			this->cnfrmCircular->Size = System::Drawing::Size(176, 100);
			this->cnfrmCircular->TabIndex = 54;
			this->cnfrmCircular->Text = L"Confirm Changes";
			this->cnfrmCircular->UseVisualStyleBackColor = false;
			this->cnfrmCircular->Visible = false;
			this->cnfrmCircular->Click += gcnew System::EventHandler(this, &MyForm::cnfrmCircular_Click);
			// 
			// trackBar2
			// 
			this->trackBar2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->trackBar2->LargeChange = 2;
			this->trackBar2->Location = System::Drawing::Point(230, 140);
			this->trackBar2->Maximum = 15;
			this->trackBar2->Minimum = 3;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(567, 45);
			this->trackBar2->TabIndex = 53;
			this->trackBar2->Value = 3;
			this->trackBar2->Visible = false;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::pyramidal_Scroll);
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->button16->FlatAppearance->BorderSize = 0;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::Color::Gainsboro;
			this->button16->Location = System::Drawing::Point(414, 265);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(176, 100);
			this->button16->TabIndex = 52;
			this->button16->Text = L"Confirm Changes";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Visible = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::cnfrmpyramidal_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->trackBar1->LargeChange = 2;
			this->trackBar1->Location = System::Drawing::Point(235, 140);
			this->trackBar1->Maximum = 15;
			this->trackBar1->Minimum = 3;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(562, 45);
			this->trackBar1->TabIndex = 51;
			this->trackBar1->Value = 3;
			this->trackBar1->Visible = false;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::traditionalFilter_Scroll);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(231, 110);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(566, 23);
			this->label16->TabIndex = 50;
			this->label16->Text = L"Minimum Blurring                                          Maximum Blurring";
			this->label16->Visible = false;
			// 
			// cnfrmTraditional
			// 
			this->cnfrmTraditional->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cnfrmTraditional->FlatAppearance->BorderSize = 0;
			this->cnfrmTraditional->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmTraditional->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmTraditional->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmTraditional->Location = System::Drawing::Point(414, 265);
			this->cnfrmTraditional->Name = L"cnfrmTraditional";
			this->cnfrmTraditional->Size = System::Drawing::Size(176, 100);
			this->cnfrmTraditional->TabIndex = 49;
			this->cnfrmTraditional->Text = L"Confirm Changes";
			this->cnfrmTraditional->UseVisualStyleBackColor = false;
			this->cnfrmTraditional->Visible = false;
			this->cnfrmTraditional->Click += gcnew System::EventHandler(this, &MyForm::cnfrmTraditional_Click);
			// 
			// dftLabel
			// 
			this->dftLabel->AutoSize = true;
			this->dftLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dftLabel->Location = System::Drawing::Point(230, 109);
			this->dftLabel->Name = L"dftLabel";
			this->dftLabel->Size = System::Drawing::Size(567, 23);
			this->dftLabel->TabIndex = 47;
			this->dftLabel->Text = L"Minimum Enhancement                               Maximum Enhancement\r\n";
			this->dftLabel->Visible = false;
			// 
			// cnfrmChangess
			// 
			this->cnfrmChangess->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->cnfrmChangess->FlatAppearance->BorderSize = 0;
			this->cnfrmChangess->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmChangess->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmChangess->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmChangess->Location = System::Drawing::Point(414, 265);
			this->cnfrmChangess->Name = L"cnfrmChangess";
			this->cnfrmChangess->Size = System::Drawing::Size(176, 100);
			this->cnfrmChangess->TabIndex = 46;
			this->cnfrmChangess->Text = L"Confirm Changes";
			this->cnfrmChangess->UseVisualStyleBackColor = false;
			this->cnfrmChangess->Visible = false;
			// 
			// foureirFilter
			// 
			this->foureirFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->foureirFilter->LargeChange = 25;
			this->foureirFilter->Location = System::Drawing::Point(230, 140);
			this->foureirFilter->Maximum = 200;
			this->foureirFilter->Minimum = 1;
			this->foureirFilter->Name = L"foureirFilter";
			this->foureirFilter->Size = System::Drawing::Size(567, 45);
			this->foureirFilter->SmallChange = 10;
			this->foureirFilter->TabIndex = 9;
			this->foureirFilter->Value = 1;
			this->foureirFilter->Visible = false;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel4->Controls->Add(this->button6);
			this->panel4->Controls->Add(this->SobelFilter);
			this->panel4->Controls->Add(this->gaussianFilter);
			this->panel4->Controls->Add(this->MedianFilter);
			this->panel4->Controls->Add(this->button11);
			this->panel4->Controls->Add(this->button12);
			this->panel4->Controls->Add(this->button13);
			this->panel4->Controls->Add(this->button14);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(221, 576);
			this->panel4->TabIndex = 8;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button6->Dock = System::Windows::Forms::DockStyle::Top;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Gainsboro;
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(0, 413);
			this->button6->Name = L"button6";
			this->button6->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button6->Size = System::Drawing::Size(221, 55);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Thin Sharpening";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::laplac_Click);
			// 
			// SobelFilter
			// 
			this->SobelFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SobelFilter->Dock = System::Windows::Forms::DockStyle::Top;
			this->SobelFilter->FlatAppearance->BorderSize = 0;
			this->SobelFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SobelFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SobelFilter->ForeColor = System::Drawing::Color::Gainsboro;
			this->SobelFilter->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SobelFilter->Location = System::Drawing::Point(0, 346);
			this->SobelFilter->Name = L"SobelFilter";
			this->SobelFilter->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->SobelFilter->Size = System::Drawing::Size(221, 67);
			this->SobelFilter->TabIndex = 8;
			this->SobelFilter->Text = L"Thick Sharpening";
			this->SobelFilter->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SobelFilter->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->SobelFilter->UseVisualStyleBackColor = false;
			this->SobelFilter->Click += gcnew System::EventHandler(this, &MyForm::SobelFilter_Click);
			// 
			// gaussianFilter
			// 
			this->gaussianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->gaussianFilter->Dock = System::Windows::Forms::DockStyle::Top;
			this->gaussianFilter->FlatAppearance->BorderSize = 0;
			this->gaussianFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->gaussianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->gaussianFilter->ForeColor = System::Drawing::Color::Gainsboro;
			this->gaussianFilter->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->gaussianFilter->Location = System::Drawing::Point(0, 282);
			this->gaussianFilter->Name = L"gaussianFilter";
			this->gaussianFilter->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->gaussianFilter->Size = System::Drawing::Size(221, 64);
			this->gaussianFilter->TabIndex = 6;
			this->gaussianFilter->Text = L"Reducing High Noises and Blurring";
			this->gaussianFilter->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->gaussianFilter->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->gaussianFilter->UseVisualStyleBackColor = false;
			this->gaussianFilter->Click += gcnew System::EventHandler(this, &MyForm::gaussianFilter_Click);
			// 
			// MedianFilter
			// 
			this->MedianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->MedianFilter->Dock = System::Windows::Forms::DockStyle::Top;
			this->MedianFilter->FlatAppearance->BorderSize = 0;
			this->MedianFilter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->MedianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MedianFilter->ForeColor = System::Drawing::Color::Gainsboro;
			this->MedianFilter->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->MedianFilter->Location = System::Drawing::Point(0, 220);
			this->MedianFilter->Name = L"MedianFilter";
			this->MedianFilter->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->MedianFilter->Size = System::Drawing::Size(221, 62);
			this->MedianFilter->TabIndex = 4;
			this->MedianFilter->Text = L"Fixing Extremely Dark or Bright Values";
			this->MedianFilter->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->MedianFilter->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->MedianFilter->UseVisualStyleBackColor = false;
			this->MedianFilter->Click += gcnew System::EventHandler(this, &MyForm::MedianFilter_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button11->Dock = System::Windows::Forms::DockStyle::Top;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::Gainsboro;
			this->button11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->Location = System::Drawing::Point(0, 165);
			this->button11->Name = L"button11";
			this->button11->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button11->Size = System::Drawing::Size(221, 55);
			this->button11->TabIndex = 3;
			this->button11->Text = L"Cone Blurring";
			this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::coneFilteR_Click);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button12->Dock = System::Windows::Forms::DockStyle::Top;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Gainsboro;
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(0, 110);
			this->button12->Name = L"button12";
			this->button12->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button12->Size = System::Drawing::Size(221, 55);
			this->button12->TabIndex = 0;
			this->button12->Text = L"Remove High Noise";
			this->button12->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::CircularFilter_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button13->Dock = System::Windows::Forms::DockStyle::Top;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Gainsboro;
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(0, 55);
			this->button13->Name = L"button13";
			this->button13->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button13->Size = System::Drawing::Size(221, 55);
			this->button13->TabIndex = 1;
			this->button13->Text = L"Pyramidal Blurring";
			this->button13->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::pyramidalFilter_Click);
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button14->Dock = System::Windows::Forms::DockStyle::Top;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Gainsboro;
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(0, 0);
			this->button14->Name = L"button14";
			this->button14->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button14->Size = System::Drawing::Size(221, 55);
			this->button14->TabIndex = 2;
			this->button14->Text = L"     Box Filter";
			this->button14->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::traditionalFilter_Click);
			// 
			// PointProcessing
			// 
			this->PointProcessing->BackColor = System::Drawing::Color::White;
			this->PointProcessing->Controls->Add(this->pointProcessingGuide);
			this->PointProcessing->Controls->Add(this->threshBox);
			this->PointProcessing->Controls->Add(this->logBox);
			this->PointProcessing->Controls->Add(this->powerBox);
			this->PointProcessing->Controls->Add(this->maxRange);
			this->PointProcessing->Controls->Add(this->minRange);
			this->PointProcessing->Controls->Add(this->label18);
			this->PointProcessing->Controls->Add(this->label17);
			this->PointProcessing->Controls->Add(this->saveGrayRange);
			this->PointProcessing->Controls->Add(this->secHighlightGray);
			this->PointProcessing->Controls->Add(this->MinValue);
			this->PointProcessing->Controls->Add(this->labelMin);
			this->PointProcessing->Controls->Add(this->labelMax);
			this->PointProcessing->Controls->Add(this->HighlightGray);
			this->PointProcessing->Controls->Add(this->MaxVlaue);
			this->PointProcessing->Controls->Add(this->ThreshLabel);
			this->PointProcessing->Controls->Add(this->threshHoldingCnfrm);
			this->PointProcessing->Controls->Add(this->threshHoldingS);
			this->PointProcessing->Controls->Add(this->SavePlane);
			this->PointProcessing->Controls->Add(this->cnfrmBitPlaneSelection);
			this->PointProcessing->Controls->Add(this->ChoosenPlane);
			this->PointProcessing->Controls->Add(this->PlaneLabel);
			this->PointProcessing->Controls->Add(this->SelectedBitLabel);
			this->PointProcessing->Controls->Add(this->logLabel);
			this->PointProcessing->Controls->Add(this->BitPlaneBox);
			this->PointProcessing->Controls->Add(this->cnfrmChanges);
			this->PointProcessing->Controls->Add(this->logTransf);
			this->PointProcessing->Controls->Add(this->bightLabel);
			this->PointProcessing->Controls->Add(this->cnfrmPowerTrans);
			this->PointProcessing->Controls->Add(this->powerTrans);
			this->PointProcessing->Controls->Add(this->label15);
			this->PointProcessing->Controls->Add(this->textBox9);
			this->PointProcessing->Controls->Add(this->cnfrmBlind);
			this->PointProcessing->Controls->Add(this->Blind);
			this->PointProcessing->Controls->Add(this->selectImg);
			this->PointProcessing->Controls->Add(this->panel3);
			this->PointProcessing->Controls->Add(this->pictureBox3);
			this->PointProcessing->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->PointProcessing->Location = System::Drawing::Point(4, 29);
			this->PointProcessing->Name = L"PointProcessing";
			this->PointProcessing->Padding = System::Windows::Forms::Padding(3);
			this->PointProcessing->Size = System::Drawing::Size(810, 582);
			this->PointProcessing->TabIndex = 2;
			this->PointProcessing->Text = L"AdvancedEdit";
			// 
			// pointProcessingGuide
			// 
			this->pointProcessingGuide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pointProcessingGuide.Image")));
			this->pointProcessingGuide->Location = System::Drawing::Point(782, 7);
			this->pointProcessingGuide->Name = L"pointProcessingGuide";
			this->pointProcessingGuide->Size = System::Drawing::Size(20, 23);
			this->pointProcessingGuide->TabIndex = 69;
			this->pointProcessingGuide->UseVisualStyleBackColor = true;
			this->pointProcessingGuide->Click += gcnew System::EventHandler(this, &MyForm::pointProcessingGuide_Click);
			// 
			// threshBox
			// 
			this->threshBox->Enabled = false;
			this->threshBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->threshBox->ForeColor = System::Drawing::Color::Black;
			this->threshBox->Location = System::Drawing::Point(762, 197);
			this->threshBox->Name = L"threshBox";
			this->threshBox->Size = System::Drawing::Size(45, 34);
			this->threshBox->TabIndex = 68;
			this->threshBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->threshBox->Visible = false;
			// 
			// logBox
			// 
			this->logBox->Enabled = false;
			this->logBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logBox->ForeColor = System::Drawing::Color::Black;
			this->logBox->Location = System::Drawing::Point(466, 269);
			this->logBox->Name = L"logBox";
			this->logBox->Size = System::Drawing::Size(83, 34);
			this->logBox->TabIndex = 67;
			this->logBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->logBox->Visible = false;
			// 
			// powerBox
			// 
			this->powerBox->Enabled = false;
			this->powerBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->powerBox->ForeColor = System::Drawing::Color::Black;
			this->powerBox->Location = System::Drawing::Point(466, 269);
			this->powerBox->Name = L"powerBox";
			this->powerBox->Size = System::Drawing::Size(83, 34);
			this->powerBox->TabIndex = 66;
			this->powerBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->powerBox->Visible = false;
			// 
			// maxRange
			// 
			this->maxRange->Enabled = false;
			this->maxRange->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->maxRange->ForeColor = System::Drawing::Color::Black;
			this->maxRange->Location = System::Drawing::Point(762, 99);
			this->maxRange->Name = L"maxRange";
			this->maxRange->Size = System::Drawing::Size(45, 34);
			this->maxRange->TabIndex = 65;
			this->maxRange->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->maxRange->Visible = false;
			// 
			// minRange
			// 
			this->minRange->Enabled = false;
			this->minRange->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->minRange->ForeColor = System::Drawing::Color::Black;
			this->minRange->Location = System::Drawing::Point(762, 218);
			this->minRange->Name = L"minRange";
			this->minRange->Size = System::Drawing::Size(45, 34);
			this->minRange->TabIndex = 64;
			this->minRange->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->minRange->Visible = false;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(240, 34);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(165, 23);
			this->label18->TabIndex = 63;
			this->label18->Text = L"Set Maximum Range";
			this->label18->Visible = false;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(234, 159);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(159, 23);
			this->label17->TabIndex = 62;
			this->label17->Text = L"Set Minimum Range";
			this->label17->Visible = false;
			// 
			// saveGrayRange
			// 
			this->saveGrayRange->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->saveGrayRange->FlatAppearance->BorderSize = 0;
			this->saveGrayRange->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveGrayRange->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->saveGrayRange->ForeColor = System::Drawing::Color::Gainsboro;
			this->saveGrayRange->Location = System::Drawing::Point(410, 408);
			this->saveGrayRange->Name = L"saveGrayRange";
			this->saveGrayRange->Size = System::Drawing::Size(176, 100);
			this->saveGrayRange->TabIndex = 61;
			this->saveGrayRange->Text = L"Save Changes";
			this->saveGrayRange->UseVisualStyleBackColor = false;
			this->saveGrayRange->Visible = false;
			this->saveGrayRange->Click += gcnew System::EventHandler(this, &MyForm::saveGrayRange_Click);
			// 
			// secHighlightGray
			// 
			this->secHighlightGray->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)),
				static_cast<System::Int32>(static_cast<System::Byte>(134)), static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->secHighlightGray->FlatAppearance->BorderSize = 0;
			this->secHighlightGray->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->secHighlightGray->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->secHighlightGray->ForeColor = System::Drawing::Color::Gainsboro;
			this->secHighlightGray->Location = System::Drawing::Point(539, 289);
			this->secHighlightGray->Name = L"secHighlightGray";
			this->secHighlightGray->Size = System::Drawing::Size(176, 100);
			this->secHighlightGray->TabIndex = 60;
			this->secHighlightGray->Text = L"Highlight and Dim Others";
			this->secHighlightGray->UseVisualStyleBackColor = false;
			this->secHighlightGray->Visible = false;
			this->secHighlightGray->Click += gcnew System::EventHandler(this, &MyForm::secHighlightGray_Click);
			// 
			// MinValue
			// 
			this->MinValue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->MinValue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MinValue->LargeChange = 25;
			this->MinValue->Location = System::Drawing::Point(236, 208);
			this->MinValue->Name = L"MinValue";
			this->MinValue->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->MinValue->Size = System::Drawing::Size(524, 45);
			this->MinValue->TabIndex = 55;
			this->MinValue->Visible = false;
			this->MinValue->Scroll += gcnew System::EventHandler(this, &MyForm::MinValue_Scroll);
			// 
			// labelMin
			// 
			this->labelMin->AutoSize = true;
			this->labelMin->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMin->Location = System::Drawing::Point(234, 182);
			this->labelMin->Name = L"labelMin";
			this->labelMin->Size = System::Drawing::Size(530, 23);
			this->labelMin->TabIndex = 59;
			this->labelMin->Text = L"Minimum Value                                          Maximum Value\r\n";
			this->labelMin->Visible = false;
			// 
			// labelMax
			// 
			this->labelMax->AutoSize = true;
			this->labelMax->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelMax->Location = System::Drawing::Point(236, 62);
			this->labelMax->Name = L"labelMax";
			this->labelMax->Size = System::Drawing::Size(530, 23);
			this->labelMax->TabIndex = 58;
			this->labelMax->Text = L"Minimum Value                                          Maximum Value\r\n";
			this->labelMax->Visible = false;
			// 
			// HighlightGray
			// 
			this->HighlightGray->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->HighlightGray->FlatAppearance->BorderSize = 0;
			this->HighlightGray->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->HighlightGray->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->HighlightGray->ForeColor = System::Drawing::Color::Gainsboro;
			this->HighlightGray->Location = System::Drawing::Point(260, 289);
			this->HighlightGray->Name = L"HighlightGray";
			this->HighlightGray->Size = System::Drawing::Size(176, 100);
			this->HighlightGray->TabIndex = 57;
			this->HighlightGray->Text = L"Highlight Only";
			this->HighlightGray->UseVisualStyleBackColor = false;
			this->HighlightGray->Visible = false;
			this->HighlightGray->Click += gcnew System::EventHandler(this, &MyForm::HighlightGray_Click);
			// 
			// MaxVlaue
			// 
			this->MaxVlaue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->MaxVlaue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MaxVlaue->LargeChange = 25;
			this->MaxVlaue->Location = System::Drawing::Point(240, 88);
			this->MaxVlaue->Maximum = 255;
			this->MaxVlaue->Name = L"MaxVlaue";
			this->MaxVlaue->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->MaxVlaue->Size = System::Drawing::Size(520, 45);
			this->MaxVlaue->TabIndex = 56;
			this->MaxVlaue->Value = 255;
			this->MaxVlaue->Visible = false;
			this->MaxVlaue->Scroll += gcnew System::EventHandler(this, &MyForm::MaxVlaue_Scroll);
			// 
			// ThreshLabel
			// 
			this->ThreshLabel->AutoSize = true;
			this->ThreshLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ThreshLabel->Location = System::Drawing::Point(236, 160);
			this->ThreshLabel->Name = L"ThreshLabel";
			this->ThreshLabel->Size = System::Drawing::Size(532, 23);
			this->ThreshLabel->TabIndex = 54;
			this->ThreshLabel->Text = L"Minimum Enhancement                          Maximum Enhancement\r\n";
			this->ThreshLabel->Visible = false;
			// 
			// threshHoldingCnfrm
			// 
			this->threshHoldingCnfrm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)),
				static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->threshHoldingCnfrm->FlatAppearance->BorderSize = 0;
			this->threshHoldingCnfrm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->threshHoldingCnfrm->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->threshHoldingCnfrm->ForeColor = System::Drawing::Color::Gainsboro;
			this->threshHoldingCnfrm->Location = System::Drawing::Point(410, 289);
			this->threshHoldingCnfrm->Name = L"threshHoldingCnfrm";
			this->threshHoldingCnfrm->Size = System::Drawing::Size(176, 100);
			this->threshHoldingCnfrm->TabIndex = 53;
			this->threshHoldingCnfrm->Text = L"Confirm Changes";
			this->threshHoldingCnfrm->UseVisualStyleBackColor = false;
			this->threshHoldingCnfrm->Visible = false;
			this->threshHoldingCnfrm->Click += gcnew System::EventHandler(this, &MyForm::threshHoldingCnfrm_Click);
			// 
			// threshHoldingS
			// 
			this->threshHoldingS->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->threshHoldingS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->threshHoldingS->LargeChange = 25;
			this->threshHoldingS->Location = System::Drawing::Point(236, 186);
			this->threshHoldingS->Maximum = 255;
			this->threshHoldingS->Minimum = 1;
			this->threshHoldingS->Name = L"threshHoldingS";
			this->threshHoldingS->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->threshHoldingS->Size = System::Drawing::Size(524, 45);
			this->threshHoldingS->TabIndex = 52;
			this->threshHoldingS->Value = 1;
			this->threshHoldingS->Visible = false;
			this->threshHoldingS->Scroll += gcnew System::EventHandler(this, &MyForm::threshHoldingS_Scroll);
			// 
			// SavePlane
			// 
			this->SavePlane->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->SavePlane->FlatAppearance->BorderSize = 0;
			this->SavePlane->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SavePlane->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SavePlane->ForeColor = System::Drawing::Color::Gainsboro;
			this->SavePlane->Location = System::Drawing::Point(539, 289);
			this->SavePlane->Name = L"SavePlane";
			this->SavePlane->Size = System::Drawing::Size(176, 100);
			this->SavePlane->TabIndex = 51;
			this->SavePlane->Text = L"Save Changes";
			this->SavePlane->UseVisualStyleBackColor = false;
			this->SavePlane->Visible = false;
			this->SavePlane->Click += gcnew System::EventHandler(this, &MyForm::SavePlane_Click);
			// 
			// cnfrmBitPlaneSelection
			// 
			this->cnfrmBitPlaneSelection->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(47)));
			this->cnfrmBitPlaneSelection->FlatAppearance->BorderSize = 0;
			this->cnfrmBitPlaneSelection->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmBitPlaneSelection->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmBitPlaneSelection->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmBitPlaneSelection->Location = System::Drawing::Point(260, 289);
			this->cnfrmBitPlaneSelection->Name = L"cnfrmBitPlaneSelection";
			this->cnfrmBitPlaneSelection->Size = System::Drawing::Size(176, 100);
			this->cnfrmBitPlaneSelection->TabIndex = 50;
			this->cnfrmBitPlaneSelection->Text = L"Confirm Choice";
			this->cnfrmBitPlaneSelection->UseVisualStyleBackColor = false;
			this->cnfrmBitPlaneSelection->Visible = false;
			this->cnfrmBitPlaneSelection->Click += gcnew System::EventHandler(this, &MyForm::cnfrmBitPlaneSelection_Click);
			// 
			// ChoosenPlane
			// 
			this->ChoosenPlane->AutoSize = true;
			this->ChoosenPlane->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ChoosenPlane->Location = System::Drawing::Point(462, 216);
			this->ChoosenPlane->Name = L"ChoosenPlane";
			this->ChoosenPlane->Size = System::Drawing::Size(19, 23);
			this->ChoosenPlane->TabIndex = 48;
			this->ChoosenPlane->Text = L"\?";
			this->ChoosenPlane->Visible = false;
			// 
			// PlaneLabel
			// 
			this->PlaneLabel->AutoSize = true;
			this->PlaneLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->PlaneLabel->Location = System::Drawing::Point(365, 168);
			this->PlaneLabel->Name = L"PlaneLabel";
			this->PlaneLabel->Size = System::Drawing::Size(71, 23);
			this->PlaneLabel->TabIndex = 49;
			this->PlaneLabel->Text = L"Planes :";
			this->PlaneLabel->Visible = false;
			// 
			// SelectedBitLabel
			// 
			this->SelectedBitLabel->AutoSize = true;
			this->SelectedBitLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SelectedBitLabel->Location = System::Drawing::Point(365, 214);
			this->SelectedBitLabel->Name = L"SelectedBitLabel";
			this->SelectedBitLabel->Size = System::Drawing::Size(91, 23);
			this->SelectedBitLabel->TabIndex = 47;
			this->SelectedBitLabel->Text = L"Selected :\r\n";
			this->SelectedBitLabel->Visible = false;
			// 
			// logLabel
			// 
			this->logLabel->AutoSize = true;
			this->logLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->logLabel->Location = System::Drawing::Point(278, 191);
			this->logLabel->Name = L"logLabel";
			this->logLabel->Size = System::Drawing::Size(469, 23);
			this->logLabel->TabIndex = 46;
			this->logLabel->Text = L"Maximum Enhancement                 Minimum Enhancement\r\n";
			this->logLabel->Visible = false;
			// 
			// BitPlaneBox
			// 
			this->BitPlaneBox->FormattingEnabled = true;
			this->BitPlaneBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"First Plane", L"Second Plane", L"Third Plane",
					L"Fourth Plane", L"Fifth Plane", L"Sixth Plane", L"Seventh Plane", L"Eighth Plane"
			});
			this->BitPlaneBox->Location = System::Drawing::Point(438, 167);
			this->BitPlaneBox->Name = L"BitPlaneBox";
			this->BitPlaneBox->Size = System::Drawing::Size(211, 27);
			this->BitPlaneBox->TabIndex = 9;
			this->BitPlaneBox->Visible = false;
			this->BitPlaneBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::BitPlaneBox_SelectedIndexChanged);
			// 
			// cnfrmChanges
			// 
			this->cnfrmChanges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)));
			this->cnfrmChanges->FlatAppearance->BorderSize = 0;
			this->cnfrmChanges->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmChanges->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmChanges->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmChanges->Location = System::Drawing::Point(410, 321);
			this->cnfrmChanges->Name = L"cnfrmChanges";
			this->cnfrmChanges->Size = System::Drawing::Size(176, 100);
			this->cnfrmChanges->TabIndex = 45;
			this->cnfrmChanges->Text = L"Confirm Changes";
			this->cnfrmChanges->UseVisualStyleBackColor = false;
			this->cnfrmChanges->Visible = false;
			this->cnfrmChanges->Click += gcnew System::EventHandler(this, &MyForm::cnfrmChanges_Click);
			// 
			// logTransf
			// 
			this->logTransf->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(137)));
			this->logTransf->Cursor = System::Windows::Forms::Cursors::Hand;
			this->logTransf->LargeChange = 3;
			this->logTransf->Location = System::Drawing::Point(282, 218);
			this->logTransf->Maximum = 32;
			this->logTransf->Minimum = 1;
			this->logTransf->Name = L"logTransf";
			this->logTransf->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->logTransf->Size = System::Drawing::Size(465, 45);
			this->logTransf->SmallChange = 8;
			this->logTransf->TabIndex = 44;
			this->logTransf->Value = 32;
			this->logTransf->Visible = false;
			this->logTransf->Scroll += gcnew System::EventHandler(this, &MyForm::logTransf_Scroll);
			// 
			// bightLabel
			// 
			this->bightLabel->AutoSize = true;
			this->bightLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bightLabel->Location = System::Drawing::Point(315, 191);
			this->bightLabel->Name = L"bightLabel";
			this->bightLabel->Size = System::Drawing::Size(400, 23);
			this->bightLabel->TabIndex = 43;
			this->bightLabel->Text = L"Increase              Normal              Decrease";
			this->bightLabel->Visible = false;
			// 
			// cnfrmPowerTrans
			// 
			this->cnfrmPowerTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->cnfrmPowerTrans->FlatAppearance->BorderSize = 0;
			this->cnfrmPowerTrans->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmPowerTrans->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmPowerTrans->ForeColor = System::Drawing::Color::Gainsboro;
			this->cnfrmPowerTrans->Location = System::Drawing::Point(410, 321);
			this->cnfrmPowerTrans->Name = L"cnfrmPowerTrans";
			this->cnfrmPowerTrans->Size = System::Drawing::Size(176, 100);
			this->cnfrmPowerTrans->TabIndex = 42;
			this->cnfrmPowerTrans->Text = L"Confirm Changes";
			this->cnfrmPowerTrans->UseVisualStyleBackColor = false;
			this->cnfrmPowerTrans->Visible = false;
			this->cnfrmPowerTrans->Click += gcnew System::EventHandler(this, &MyForm::cnfrmPowerTrans_Click);
			// 
			// powerTrans
			// 
			this->powerTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->powerTrans->Cursor = System::Windows::Forms::Cursors::Hand;
			this->powerTrans->LargeChange = 2;
			this->powerTrans->Location = System::Drawing::Point(319, 218);
			this->powerTrans->Maximum = 20;
			this->powerTrans->Minimum = 1;
			this->powerTrans->Name = L"powerTrans";
			this->powerTrans->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->powerTrans->Size = System::Drawing::Size(396, 45);
			this->powerTrans->TabIndex = 41;
			this->powerTrans->Value = 10;
			this->powerTrans->Visible = false;
			this->powerTrans->Scroll += gcnew System::EventHandler(this, &MyForm::powerTrans_Scroll);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(253, 239);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(494, 23);
			this->label15->TabIndex = 40;
			this->label15->Text = L"For Custom Blinding Ratio Choose a value between 0 to 100 %";
			this->label15->Visible = false;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(317, 289);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(97, 26);
			this->textBox9->TabIndex = 39;
			this->textBox9->Visible = false;
			// 
			// cnfrmBlind
			// 
			this->cnfrmBlind->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(197)));
			this->cnfrmBlind->FlatAppearance->BorderSize = 0;
			this->cnfrmBlind->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cnfrmBlind->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cnfrmBlind->ForeColor = System::Drawing::Color::Black;
			this->cnfrmBlind->Location = System::Drawing::Point(509, 280);
			this->cnfrmBlind->Name = L"cnfrmBlind";
			this->cnfrmBlind->Size = System::Drawing::Size(206, 41);
			this->cnfrmBlind->TabIndex = 38;
			this->cnfrmBlind->Text = L"Confirm Ratio";
			this->cnfrmBlind->UseVisualStyleBackColor = false;
			this->cnfrmBlind->Visible = false;
			this->cnfrmBlind->Click += gcnew System::EventHandler(this, &MyForm::cnfrmBlind_Click);
			// 
			// Blind
			// 
			this->Blind->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(197)));
			this->Blind->FlatAppearance->BorderSize = 0;
			this->Blind->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Blind->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Blind->ForeColor = System::Drawing::Color::Black;
			this->Blind->Location = System::Drawing::Point(509, 19);
			this->Blind->Name = L"Blind";
			this->Blind->Size = System::Drawing::Size(206, 142);
			this->Blind->TabIndex = 37;
			this->Blind->Text = L"Insert the Water Mark";
			this->Blind->UseVisualStyleBackColor = false;
			this->Blind->Visible = false;
			this->Blind->Click += gcnew System::EventHandler(this, &MyForm::Blind_Click);
			// 
			// selectImg
			// 
			this->selectImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(197)));
			this->selectImg->FlatAppearance->BorderSize = 0;
			this->selectImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->selectImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->selectImg->ForeColor = System::Drawing::Color::Black;
			this->selectImg->Location = System::Drawing::Point(257, 19);
			this->selectImg->Name = L"selectImg";
			this->selectImg->Size = System::Drawing::Size(206, 142);
			this->selectImg->TabIndex = 36;
			this->selectImg->Text = L"Select the Marking Image";
			this->selectImg->UseVisualStyleBackColor = false;
			this->selectImg->Visible = false;
			this->selectImg->Click += gcnew System::EventHandler(this, &MyForm::selectImg_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel3->Controls->Add(this->grayLevelSlicing);
			this->panel3->Controls->Add(this->button17);
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->logTrans);
			this->panel3->Controls->Add(this->powerTransformation);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button10);
			this->panel3->Controls->Add(this->button9);
			this->panel3->Controls->Add(this->button8);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(231, 576);
			this->panel3->TabIndex = 7;
			// 
			// grayLevelSlicing
			// 
			this->grayLevelSlicing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->grayLevelSlicing->Dock = System::Windows::Forms::DockStyle::Top;
			this->grayLevelSlicing->FlatAppearance->BorderSize = 0;
			this->grayLevelSlicing->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->grayLevelSlicing->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->grayLevelSlicing->ForeColor = System::Drawing::Color::Gainsboro;
			this->grayLevelSlicing->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->grayLevelSlicing->Location = System::Drawing::Point(0, 470);
			this->grayLevelSlicing->Name = L"grayLevelSlicing";
			this->grayLevelSlicing->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->grayLevelSlicing->Size = System::Drawing::Size(231, 55);
			this->grayLevelSlicing->TabIndex = 8;
			this->grayLevelSlicing->Text = L"Highlight Gray Range\r\n";
			this->grayLevelSlicing->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->grayLevelSlicing->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->grayLevelSlicing->UseVisualStyleBackColor = false;
			this->grayLevelSlicing->Click += gcnew System::EventHandler(this, &MyForm::grayLevelSlicing_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button17->Dock = System::Windows::Forms::DockStyle::Top;
			this->button17->FlatAppearance->BorderSize = 0;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::Color::Gainsboro;
			this->button17->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button17->Location = System::Drawing::Point(0, 415);
			this->button17->Name = L"button17";
			this->button17->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button17->Size = System::Drawing::Size(231, 55);
			this->button17->TabIndex = 7;
			this->button17->Text = L"Choose Certain Details";
			this->button17->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button17->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button17->UseVisualStyleBackColor = false;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::threshHolding_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button7->Dock = System::Windows::Forms::DockStyle::Top;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Gainsboro;
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(0, 360);
			this->button7->Name = L"button7";
			this->button7->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button7->Size = System::Drawing::Size(231, 55);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Image Slicing Levels";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::BitPlane_Click);
			// 
			// logTrans
			// 
			this->logTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->logTrans->Dock = System::Windows::Forms::DockStyle::Top;
			this->logTrans->FlatAppearance->BorderSize = 0;
			this->logTrans->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->logTrans->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->logTrans->ForeColor = System::Drawing::Color::Gainsboro;
			this->logTrans->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->logTrans->Location = System::Drawing::Point(0, 305);
			this->logTrans->Name = L"logTrans";
			this->logTrans->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->logTrans->Size = System::Drawing::Size(231, 55);
			this->logTrans->TabIndex = 5;
			this->logTrans->Text = L"Brighten Dark Images";
			this->logTrans->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->logTrans->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->logTrans->UseVisualStyleBackColor = false;
			this->logTrans->Click += gcnew System::EventHandler(this, &MyForm::logTrans_Click);
			// 
			// powerTransformation
			// 
			this->powerTransformation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->powerTransformation->Dock = System::Windows::Forms::DockStyle::Top;
			this->powerTransformation->FlatAppearance->BorderSize = 0;
			this->powerTransformation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->powerTransformation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->powerTransformation->ForeColor = System::Drawing::Color::Gainsboro;
			this->powerTransformation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"powerTransformation.Image")));
			this->powerTransformation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->powerTransformation->Location = System::Drawing::Point(0, 250);
			this->powerTransformation->Name = L"powerTransformation";
			this->powerTransformation->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->powerTransformation->Size = System::Drawing::Size(231, 55);
			this->powerTransformation->TabIndex = 4;
			this->powerTransformation->Text = L"Adjust Brightness";
			this->powerTransformation->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->powerTransformation->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->powerTransformation->UseVisualStyleBackColor = false;
			this->powerTransformation->Click += gcnew System::EventHandler(this, &MyForm::powerTransformation_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gainsboro;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(0, 195);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(231, 55);
			this->button2->TabIndex = 3;
			this->button2->Text = L"  Water Mark";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::waterMark_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button10->Dock = System::Windows::Forms::DockStyle::Top;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::Gainsboro;
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(0, 140);
			this->button10->Name = L"button10";
			this->button10->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button10->Size = System::Drawing::Size(231, 55);
			this->button10->TabIndex = 0;
			this->button10->Text = L"         Negative";
			this->button10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::Negative_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button9->Dock = System::Windows::Forms::DockStyle::Top;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Gainsboro;
			this->button9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.Image")));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->Location = System::Drawing::Point(0, 85);
			this->button9->Name = L"button9";
			this->button9->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button9->Size = System::Drawing::Size(231, 55);
			this->button9->TabIndex = 1;
			this->button9->Text = L"Adjust Contrast";
			this->button9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button9->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::HistEqualize_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button8->Dock = System::Windows::Forms::DockStyle::Top;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::Gainsboro;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(0, 0);
			this->button8->Name = L"button8";
			this->button8->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->button8->Size = System::Drawing::Size(231, 85);
			this->button8->TabIndex = 2;
			this->button8->Text = L"Show Graphical Representation\r\n  (Histogram)";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::ShowHist_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(236, 368);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(567, 194);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// imageOperations
			// 
			this->imageOperations->BackColor = System::Drawing::Color::White;
			this->imageOperations->Controls->Add(this->label14);
			this->imageOperations->Controls->Add(this->ConfCrop);
			this->imageOperations->Controls->Add(this->pictureBox2);
			this->imageOperations->Controls->Add(this->ZoomOut);
			this->imageOperations->Controls->Add(this->ZoomIn);
			this->imageOperations->Controls->Add(this->SkewDownLeft);
			this->imageOperations->Controls->Add(this->SkewDownRight);
			this->imageOperations->Controls->Add(this->SkewUpLeft);
			this->imageOperations->Controls->Add(this->SkewUpRight);
			this->imageOperations->Controls->Add(this->CustomRotation);
			this->imageOperations->Controls->Add(this->RotationVar);
			this->imageOperations->Controls->Add(this->TransY);
			this->imageOperations->Controls->Add(this->TransX);
			this->imageOperations->Controls->Add(this->RotateLabel);
			this->imageOperations->Controls->Add(this->RotationLabel);
			this->imageOperations->Controls->Add(this->RotateLeft);
			this->imageOperations->Controls->Add(this->RotateRight);
			this->imageOperations->Controls->Add(this->xmirror);
			this->imageOperations->Controls->Add(this->xymirror);
			this->imageOperations->Controls->Add(this->ymirror);
			this->imageOperations->Controls->Add(this->CustomTranslation);
			this->imageOperations->Controls->Add(this->label13);
			this->imageOperations->Controls->Add(this->label12);
			this->imageOperations->Controls->Add(this->label11);
			this->imageOperations->Controls->Add(this->label10);
			this->imageOperations->Controls->Add(this->DownRight);
			this->imageOperations->Controls->Add(this->DownLeft);
			this->imageOperations->Controls->Add(this->UpRight);
			this->imageOperations->Controls->Add(this->UpLeft);
			this->imageOperations->Controls->Add(this->btnDown);
			this->imageOperations->Controls->Add(this->Right);
			this->imageOperations->Controls->Add(this->Left);
			this->imageOperations->Controls->Add(this->btnUp);
			this->imageOperations->Controls->Add(this->panel2);
			this->imageOperations->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->imageOperations->Location = System::Drawing::Point(4, 29);
			this->imageOperations->Name = L"imageOperations";
			this->imageOperations->Padding = System::Windows::Forms::Padding(3);
			this->imageOperations->Size = System::Drawing::Size(810, 582);
			this->imageOperations->TabIndex = 1;
			this->imageOperations->Text = L"Edit";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(293, 10);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(368, 18);
			this->label14->TabIndex = 36;
			this->label14->Text = L"Note: Add - Drag using the mouse to select the wanted area";
			this->label14->Visible = false;
			// 
			// ConfCrop
			// 
			this->ConfCrop->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->ConfCrop->FlatAppearance->BorderSize = 0;
			this->ConfCrop->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ConfCrop->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ConfCrop->ForeColor = System::Drawing::Color::Black;
			this->ConfCrop->Location = System::Drawing::Point(398, 481);
			this->ConfCrop->Name = L"ConfCrop";
			this->ConfCrop->Size = System::Drawing::Size(206, 80);
			this->ConfCrop->TabIndex = 35;
			this->ConfCrop->Text = L"Crop Selected";
			this->ConfCrop->UseVisualStyleBackColor = false;
			this->ConfCrop->Visible = false;
			this->ConfCrop->Click += gcnew System::EventHandler(this, &MyForm::ConfCrop_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(214, 34);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(583, 444);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 34;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox2_Paint);
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseDown);
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseMove);
			this->pictureBox2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox2_MouseUp);
			// 
			// ZoomOut
			// 
			this->ZoomOut->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->ZoomOut->FlatAppearance->BorderSize = 0;
			this->ZoomOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ZoomOut->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ZoomOut->ForeColor = System::Drawing::Color::Black;
			this->ZoomOut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ZoomOut.Image")));
			this->ZoomOut->Location = System::Drawing::Point(522, 143);
			this->ZoomOut->Name = L"ZoomOut";
			this->ZoomOut->Size = System::Drawing::Size(193, 195);
			this->ZoomOut->TabIndex = 33;
			this->ZoomOut->Text = L"Zoom Out";
			this->ZoomOut->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->ZoomOut->UseVisualStyleBackColor = false;
			this->ZoomOut->Visible = false;
			this->ZoomOut->Click += gcnew System::EventHandler(this, &MyForm::ZoomOut_Click);
			// 
			// ZoomIn
			// 
			this->ZoomIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->ZoomIn->FlatAppearance->BorderSize = 0;
			this->ZoomIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ZoomIn->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ZoomIn->ForeColor = System::Drawing::Color::Black;
			this->ZoomIn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ZoomIn.Image")));
			this->ZoomIn->Location = System::Drawing::Point(283, 143);
			this->ZoomIn->Name = L"ZoomIn";
			this->ZoomIn->Size = System::Drawing::Size(193, 195);
			this->ZoomIn->TabIndex = 32;
			this->ZoomIn->Text = L"Zoom In";
			this->ZoomIn->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->ZoomIn->UseVisualStyleBackColor = false;
			this->ZoomIn->Visible = false;
			this->ZoomIn->Click += gcnew System::EventHandler(this, &MyForm::ZoomIn_Click);
			// 
			// SkewDownLeft
			// 
			this->SkewDownLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->SkewDownLeft->FlatAppearance->BorderSize = 0;
			this->SkewDownLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SkewDownLeft->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SkewDownLeft->ForeColor = System::Drawing::Color::Black;
			this->SkewDownLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SkewDownLeft.Image")));
			this->SkewDownLeft->Location = System::Drawing::Point(536, 224);
			this->SkewDownLeft->Name = L"SkewDownLeft";
			this->SkewDownLeft->Size = System::Drawing::Size(160, 160);
			this->SkewDownLeft->TabIndex = 31;
			this->SkewDownLeft->Text = L"Skew Lower Part to the Left";
			this->SkewDownLeft->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->SkewDownLeft->UseVisualStyleBackColor = false;
			this->SkewDownLeft->Visible = false;
			this->SkewDownLeft->Click += gcnew System::EventHandler(this, &MyForm::SkewDownLeft_Click);
			// 
			// SkewDownRight
			// 
			this->SkewDownRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->SkewDownRight->FlatAppearance->BorderSize = 0;
			this->SkewDownRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SkewDownRight->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SkewDownRight->ForeColor = System::Drawing::Color::Black;
			this->SkewDownRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SkewDownRight.Image")));
			this->SkewDownRight->Location = System::Drawing::Point(283, 224);
			this->SkewDownRight->Name = L"SkewDownRight";
			this->SkewDownRight->Size = System::Drawing::Size(160, 160);
			this->SkewDownRight->TabIndex = 30;
			this->SkewDownRight->Text = L"Skew Lower Part to the Right";
			this->SkewDownRight->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->SkewDownRight->UseVisualStyleBackColor = false;
			this->SkewDownRight->Visible = false;
			this->SkewDownRight->Click += gcnew System::EventHandler(this, &MyForm::SkewDownRight_Click);
			// 
			// SkewUpLeft
			// 
			this->SkewUpLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->SkewUpLeft->FlatAppearance->BorderSize = 0;
			this->SkewUpLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SkewUpLeft->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SkewUpLeft->ForeColor = System::Drawing::Color::Black;
			this->SkewUpLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SkewUpLeft.Image")));
			this->SkewUpLeft->Location = System::Drawing::Point(536, 31);
			this->SkewUpLeft->Name = L"SkewUpLeft";
			this->SkewUpLeft->Size = System::Drawing::Size(160, 160);
			this->SkewUpLeft->TabIndex = 29;
			this->SkewUpLeft->Text = L"Skew Upper Part to the Left";
			this->SkewUpLeft->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->SkewUpLeft->UseVisualStyleBackColor = false;
			this->SkewUpLeft->Visible = false;
			this->SkewUpLeft->Click += gcnew System::EventHandler(this, &MyForm::SkewUpLeft_Click);
			// 
			// SkewUpRight
			// 
			this->SkewUpRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
				static_cast<System::Int32>(static_cast<System::Byte>(97)));
			this->SkewUpRight->FlatAppearance->BorderSize = 0;
			this->SkewUpRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SkewUpRight->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SkewUpRight->ForeColor = System::Drawing::Color::Black;
			this->SkewUpRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SkewUpRight.Image")));
			this->SkewUpRight->Location = System::Drawing::Point(283, 31);
			this->SkewUpRight->Name = L"SkewUpRight";
			this->SkewUpRight->Size = System::Drawing::Size(160, 160);
			this->SkewUpRight->TabIndex = 28;
			this->SkewUpRight->Text = L"Skew Upper Part to the Right";
			this->SkewUpRight->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->SkewUpRight->UseVisualStyleBackColor = false;
			this->SkewUpRight->Visible = false;
			this->SkewUpRight->Click += gcnew System::EventHandler(this, &MyForm::SkewUpRight_Click);
			// 
			// CustomRotation
			// 
			this->CustomRotation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->CustomRotation->FlatAppearance->BorderSize = 0;
			this->CustomRotation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CustomRotation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CustomRotation->ForeColor = System::Drawing::Color::Black;
			this->CustomRotation->Location = System::Drawing::Point(510, 435);
			this->CustomRotation->Name = L"CustomRotation";
			this->CustomRotation->Size = System::Drawing::Size(87, 26);
			this->CustomRotation->TabIndex = 27;
			this->CustomRotation->Text = L"Rotate ";
			this->CustomRotation->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->CustomRotation->UseVisualStyleBackColor = false;
			this->CustomRotation->Visible = false;
			this->CustomRotation->Click += gcnew System::EventHandler(this, &MyForm::CustomRotation_Click);
			// 
			// RotationVar
			// 
			this->RotationVar->Location = System::Drawing::Point(389, 435);
			this->RotationVar->Name = L"RotationVar";
			this->RotationVar->Size = System::Drawing::Size(87, 26);
			this->RotationVar->TabIndex = 26;
			this->RotationVar->Visible = false;
			// 
			// TransY
			// 
			this->TransY->Location = System::Drawing::Point(469, 438);
			this->TransY->Name = L"TransY";
			this->TransY->Size = System::Drawing::Size(100, 26);
			this->TransY->TabIndex = 13;
			this->TransY->Visible = false;
			// 
			// TransX
			// 
			this->TransX->Location = System::Drawing::Point(283, 438);
			this->TransX->Name = L"TransX";
			this->TransX->Size = System::Drawing::Size(100, 26);
			this->TransX->TabIndex = 12;
			this->TransX->Visible = false;
			// 
			// RotateLabel
			// 
			this->RotateLabel->AutoSize = true;
			this->RotateLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RotateLabel->Location = System::Drawing::Point(300, 481);
			this->RotateLabel->Name = L"RotateLabel";
			this->RotateLabel->Size = System::Drawing::Size(421, 18);
			this->RotateLabel->TabIndex = 25;
			this->RotateLabel->Text = L"Note: Add - Before The Numbers To Move It in The Other Direction";
			this->RotateLabel->Visible = false;
			// 
			// RotationLabel
			// 
			this->RotationLabel->AutoSize = true;
			this->RotationLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RotationLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->RotationLabel->Location = System::Drawing::Point(375, 387);
			this->RotationLabel->Name = L"RotationLabel";
			this->RotationLabel->Size = System::Drawing::Size(229, 23);
			this->RotationLabel->TabIndex = 24;
			this->RotationLabel->Text = L"For Custom Image  Rotation";
			this->RotationLabel->Visible = false;
			// 
			// RotateLeft
			// 
			this->RotateLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->RotateLeft->FlatAppearance->BorderSize = 0;
			this->RotateLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RotateLeft->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RotateLeft->ForeColor = System::Drawing::Color::Black;
			this->RotateLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RotateLeft.Image")));
			this->RotateLeft->Location = System::Drawing::Point(522, 117);
			this->RotateLeft->Name = L"RotateLeft";
			this->RotateLeft->Size = System::Drawing::Size(160, 160);
			this->RotateLeft->TabIndex = 23;
			this->RotateLeft->Text = L"Rotate Left";
			this->RotateLeft->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->RotateLeft->UseVisualStyleBackColor = false;
			this->RotateLeft->Visible = false;
			this->RotateLeft->Click += gcnew System::EventHandler(this, &MyForm::RotateLeft_Click);
			// 
			// RotateRight
			// 
			this->RotateRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->RotateRight->FlatAppearance->BorderSize = 0;
			this->RotateRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RotateRight->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RotateRight->ForeColor = System::Drawing::Color::Black;
			this->RotateRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RotateRight.Image")));
			this->RotateRight->Location = System::Drawing::Point(296, 117);
			this->RotateRight->Name = L"RotateRight";
			this->RotateRight->Size = System::Drawing::Size(160, 160);
			this->RotateRight->TabIndex = 22;
			this->RotateRight->Text = L"Rotate Right";
			this->RotateRight->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->RotateRight->UseVisualStyleBackColor = false;
			this->RotateRight->Visible = false;
			this->RotateRight->Click += gcnew System::EventHandler(this, &MyForm::RotateRight_Click);
			// 
			// xmirror
			// 
			this->xmirror->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->xmirror->FlatAppearance->BorderSize = 0;
			this->xmirror->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->xmirror->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->xmirror->ForeColor = System::Drawing::Color::Black;
			this->xmirror->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"xmirror.Image")));
			this->xmirror->Location = System::Drawing::Point(522, 98);
			this->xmirror->Name = L"xmirror";
			this->xmirror->Size = System::Drawing::Size(160, 160);
			this->xmirror->TabIndex = 21;
			this->xmirror->Text = L"Vertical \r\nMirroring";
			this->xmirror->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->xmirror->UseVisualStyleBackColor = false;
			this->xmirror->Visible = false;
			this->xmirror->Click += gcnew System::EventHandler(this, &MyForm::ymirror_Click);
			// 
			// xymirror
			// 
			this->xymirror->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->xymirror->FlatAppearance->BorderSize = 0;
			this->xymirror->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->xymirror->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->xymirror->ForeColor = System::Drawing::Color::Black;
			this->xymirror->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"xymirror.Image")));
			this->xymirror->Location = System::Drawing::Point(389, 318);
			this->xymirror->Name = L"xymirror";
			this->xymirror->Size = System::Drawing::Size(208, 160);
			this->xymirror->TabIndex = 20;
			this->xymirror->Text = L"Vertical and Horizontal \r\nMirroring";
			this->xymirror->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->xymirror->UseVisualStyleBackColor = false;
			this->xymirror->Visible = false;
			this->xymirror->Click += gcnew System::EventHandler(this, &MyForm::xymirror_Click);
			// 
			// ymirror
			// 
			this->ymirror->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
				static_cast<System::Int32>(static_cast<System::Byte>(233)));
			this->ymirror->FlatAppearance->BorderSize = 0;
			this->ymirror->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ymirror->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ymirror->ForeColor = System::Drawing::Color::Black;
			this->ymirror->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ymirror.Image")));
			this->ymirror->Location = System::Drawing::Point(296, 98);
			this->ymirror->Name = L"ymirror";
			this->ymirror->Size = System::Drawing::Size(160, 160);
			this->ymirror->TabIndex = 19;
			this->ymirror->Text = L"Horizontal Mirroring";
			this->ymirror->TextImageRelation = System::Windows::Forms::TextImageRelation::TextAboveImage;
			this->ymirror->UseVisualStyleBackColor = false;
			this->ymirror->Visible = false;
			this->ymirror->Click += gcnew System::EventHandler(this, &MyForm::xmirror_Click);
			// 
			// CustomTranslation
			// 
			this->CustomTranslation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->CustomTranslation->FlatAppearance->BorderSize = 0;
			this->CustomTranslation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CustomTranslation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CustomTranslation->Location = System::Drawing::Point(611, 438);
			this->CustomTranslation->Name = L"CustomTranslation";
			this->CustomTranslation->Size = System::Drawing::Size(110, 26);
			this->CustomTranslation->TabIndex = 18;
			this->CustomTranslation->Text = L"Move";
			this->CustomTranslation->UseVisualStyleBackColor = false;
			this->CustomTranslation->Visible = false;
			this->CustomTranslation->Click += gcnew System::EventHandler(this, &MyForm::CustomTranslation_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(241, 502);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(421, 18);
			this->label13->TabIndex = 17;
			this->label13->Text = L"Note: Add - Before The Numbers To Move It in The Other Direction";
			this->label13->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(436, 438);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 23);
			this->label12->TabIndex = 16;
			this->label12->Text = L"Y";
			this->label12->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(246, 438);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(22, 23);
			this->label11->TabIndex = 15;
			this->label11->Text = L"X";
			this->label11->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(375, 387);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(210, 23);
			this->label10->TabIndex = 14;
			this->label10->Text = L"For Custom Image Moving";
			this->label10->Visible = false;
			// 
			// DownRight
			// 
			this->DownRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->DownRight->FlatAppearance->BorderSize = 0;
			this->DownRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DownRight->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DownRight->ForeColor = System::Drawing::Color::Black;
			this->DownRight->Location = System::Drawing::Point(564, 240);
			this->DownRight->Name = L"DownRight";
			this->DownRight->Size = System::Drawing::Size(80, 80);
			this->DownRight->TabIndex = 11;
			this->DownRight->Text = L"Down Right";
			this->DownRight->UseVisualStyleBackColor = false;
			this->DownRight->Visible = false;
			this->DownRight->Click += gcnew System::EventHandler(this, &MyForm::DownRight_Click);
			// 
			// DownLeft
			// 
			this->DownLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->DownLeft->FlatAppearance->BorderSize = 0;
			this->DownLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DownLeft->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->DownLeft->ForeColor = System::Drawing::Color::Black;
			this->DownLeft->Location = System::Drawing::Point(332, 240);
			this->DownLeft->Name = L"DownLeft";
			this->DownLeft->Size = System::Drawing::Size(80, 80);
			this->DownLeft->TabIndex = 10;
			this->DownLeft->Text = L"Down Left";
			this->DownLeft->UseVisualStyleBackColor = false;
			this->DownLeft->Visible = false;
			this->DownLeft->Click += gcnew System::EventHandler(this, &MyForm::DownLeft_Click);
			// 
			// UpRight
			// 
			this->UpRight->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->UpRight->FlatAppearance->BorderSize = 0;
			this->UpRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UpRight->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->UpRight->ForeColor = System::Drawing::Color::Black;
			this->UpRight->Location = System::Drawing::Point(563, 31);
			this->UpRight->Name = L"UpRight";
			this->UpRight->Size = System::Drawing::Size(80, 80);
			this->UpRight->TabIndex = 9;
			this->UpRight->Text = L"Upper Right";
			this->UpRight->UseVisualStyleBackColor = false;
			this->UpRight->Visible = false;
			this->UpRight->Click += gcnew System::EventHandler(this, &MyForm::UpRight_Click);
			// 
			// UpLeft
			// 
			this->UpLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->UpLeft->FlatAppearance->BorderSize = 0;
			this->UpLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->UpLeft->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->UpLeft->ForeColor = System::Drawing::Color::Black;
			this->UpLeft->Location = System::Drawing::Point(332, 31);
			this->UpLeft->Name = L"UpLeft";
			this->UpLeft->Size = System::Drawing::Size(80, 80);
			this->UpLeft->TabIndex = 8;
			this->UpLeft->Text = L"Upper Left";
			this->UpLeft->UseVisualStyleBackColor = false;
			this->UpLeft->Visible = false;
			this->UpLeft->Click += gcnew System::EventHandler(this, &MyForm::UpLeft_Click);
			// 
			// btnDown
			// 
			this->btnDown->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnDown->FlatAppearance->BorderSize = 0;
			this->btnDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDown->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDown->ForeColor = System::Drawing::Color::Black;
			this->btnDown->Location = System::Drawing::Point(450, 240);
			this->btnDown->Name = L"btnDown";
			this->btnDown->Size = System::Drawing::Size(80, 80);
			this->btnDown->TabIndex = 7;
			this->btnDown->Text = L"Down";
			this->btnDown->UseVisualStyleBackColor = false;
			this->btnDown->Visible = false;
			this->btnDown->Click += gcnew System::EventHandler(this, &MyForm::btnDown_Click);
			// 
			// Right
			// 
			this->Right->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->Right->FlatAppearance->BorderSize = 0;
			this->Right->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Right->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Right->ForeColor = System::Drawing::Color::Black;
			this->Right->Location = System::Drawing::Point(564, 133);
			this->Right->Name = L"Right";
			this->Right->Size = System::Drawing::Size(80, 80);
			this->Right->TabIndex = 6;
			this->Right->Text = L"Right";
			this->Right->UseVisualStyleBackColor = false;
			this->Right->Visible = false;
			this->Right->Click += gcnew System::EventHandler(this, &MyForm::Right_Click);
			// 
			// Left
			// 
			this->Left->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->Left->FlatAppearance->BorderSize = 0;
			this->Left->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Left->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Left->ForeColor = System::Drawing::Color::Black;
			this->Left->Location = System::Drawing::Point(332, 133);
			this->Left->Name = L"Left";
			this->Left->Size = System::Drawing::Size(80, 80);
			this->Left->TabIndex = 5;
			this->Left->Text = L"Left";
			this->Left->UseVisualStyleBackColor = false;
			this->Left->Visible = false;
			this->Left->Click += gcnew System::EventHandler(this, &MyForm::Left_Click);
			// 
			// btnUp
			// 
			this->btnUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btnUp->FlatAppearance->BorderSize = 0;
			this->btnUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUp->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnUp->ForeColor = System::Drawing::Color::Black;
			this->btnUp->Location = System::Drawing::Point(450, 31);
			this->btnUp->Name = L"btnUp";
			this->btnUp->Size = System::Drawing::Size(80, 80);
			this->btnUp->TabIndex = 4;
			this->btnUp->Text = L"UP";
			this->btnUp->UseVisualStyleBackColor = false;
			this->btnUp->Visible = false;
			this->btnUp->Click += gcnew System::EventHandler(this, &MyForm::btnUp_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel2->Controls->Add(this->Save2);
			this->panel2->Controls->Add(this->Reset2);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->Zoom);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->Translation);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(3, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(205, 576);
			this->panel2->TabIndex = 3;
			// 
			// Save2
			// 
			this->Save2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Save2->Dock = System::Windows::Forms::DockStyle::Top;
			this->Save2->FlatAppearance->BorderSize = 0;
			this->Save2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save2->ForeColor = System::Drawing::Color::Gainsboro;
			this->Save2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save2.Image")));
			this->Save2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Save2->Location = System::Drawing::Point(0, 490);
			this->Save2->Name = L"Save2";
			this->Save2->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Save2->Size = System::Drawing::Size(205, 70);
			this->Save2->TabIndex = 7;
			this->Save2->Text = L"   Save";
			this->Save2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Save2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Save2->UseVisualStyleBackColor = false;
			this->Save2->Visible = false;
			this->Save2->Click += gcnew System::EventHandler(this, &MyForm::Save2_Click);
			// 
			// Reset2
			// 
			this->Reset2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Reset2->Dock = System::Windows::Forms::DockStyle::Top;
			this->Reset2->FlatAppearance->BorderSize = 0;
			this->Reset2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Reset2->ForeColor = System::Drawing::Color::Gainsboro;
			this->Reset2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Reset2.Image")));
			this->Reset2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Reset2->Location = System::Drawing::Point(0, 420);
			this->Reset2->Name = L"Reset2";
			this->Reset2->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Reset2->Size = System::Drawing::Size(205, 70);
			this->Reset2->TabIndex = 6;
			this->Reset2->Text = L"   Reset";
			this->Reset2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Reset2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Reset2->UseVisualStyleBackColor = false;
			this->Reset2->Click += gcnew System::EventHandler(this, &MyForm::Reset2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gainsboro;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(0, 350);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->button3->Size = System::Drawing::Size(205, 70);
			this->button3->TabIndex = 5;
			this->button3->Text = L"   Crop";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::Crop_Click);
			// 
			// Zoom
			// 
			this->Zoom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Zoom->Dock = System::Windows::Forms::DockStyle::Top;
			this->Zoom->FlatAppearance->BorderSize = 0;
			this->Zoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Zoom->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Zoom->ForeColor = System::Drawing::Color::Gainsboro;
			this->Zoom->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Zoom.Image")));
			this->Zoom->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Zoom->Location = System::Drawing::Point(0, 280);
			this->Zoom->Name = L"Zoom";
			this->Zoom->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Zoom->Size = System::Drawing::Size(205, 70);
			this->Zoom->TabIndex = 4;
			this->Zoom->Text = L"    Zoom";
			this->Zoom->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Zoom->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Zoom->UseVisualStyleBackColor = false;
			this->Zoom->Click += gcnew System::EventHandler(this, &MyForm::Zoom_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gainsboro;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(0, 210);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->button1->Size = System::Drawing::Size(205, 70);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Skewing";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Skewing_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button4->Dock = System::Windows::Forms::DockStyle::Top;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Gainsboro;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(0, 140);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->button4->Size = System::Drawing::Size(205, 70);
			this->button4->TabIndex = 2;
			this->button4->Text = L"    Rotate";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::Rotation);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button5->Dock = System::Windows::Forms::DockStyle::Top;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Gainsboro;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(0, 70);
			this->button5->Name = L"button5";
			this->button5->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->button5->Size = System::Drawing::Size(205, 70);
			this->button5->TabIndex = 1;
			this->button5->Text = L"    Mirror";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::Mirror_Click);
			// 
			// Translation
			// 
			this->Translation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Translation->Dock = System::Windows::Forms::DockStyle::Top;
			this->Translation->FlatAppearance->BorderSize = 0;
			this->Translation->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Translation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Translation->ForeColor = System::Drawing::Color::Gainsboro;
			this->Translation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Translation.Image")));
			this->Translation->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Translation->Location = System::Drawing::Point(0, 0);
			this->Translation->Name = L"Translation";
			this->Translation->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Translation->Size = System::Drawing::Size(205, 70);
			this->Translation->TabIndex = 0;
			this->Translation->Text = L"Adjust Position";
			this->Translation->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Translation->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Translation->UseVisualStyleBackColor = false;
			this->Translation->Click += gcnew System::EventHandler(this, &MyForm::Translation_Click);
			// 
			// index
			// 
			this->index->BackColor = System::Drawing::Color::White;
			this->index->Controls->Add(this->label9);
			this->index->Controls->Add(this->textBox8);
			this->index->Controls->Add(this->textBox7);
			this->index->Controls->Add(this->textBox6);
			this->index->Controls->Add(this->textBox5);
			this->index->Controls->Add(this->textBox4);
			this->index->Controls->Add(this->textBox3);
			this->index->Controls->Add(this->textBox2);
			this->index->Controls->Add(this->textBox1);
			this->index->Controls->Add(this->label8);
			this->index->Controls->Add(this->label7);
			this->index->Controls->Add(this->label6);
			this->index->Controls->Add(this->label5);
			this->index->Controls->Add(this->label4);
			this->index->Controls->Add(this->label3);
			this->index->Controls->Add(this->label1);
			this->index->Controls->Add(this->panel1);
			this->index->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->index->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->index->Location = System::Drawing::Point(4, 29);
			this->index->Name = L"index";
			this->index->Padding = System::Windows::Forms::Padding(3);
			this->index->Size = System::Drawing::Size(810, 582);
			this->index->TabIndex = 0;
			this->index->Text = L"Main";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(556, 373);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(99, 23);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Pixel Depth";
			this->label9->Visible = false;
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->ForeColor = System::Drawing::Color::Black;
			this->textBox8->Location = System::Drawing::Point(555, 399);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 34);
			this->textBox8->TabIndex = 17;
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox8->Visible = false;
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->ForeColor = System::Drawing::Color::Black;
			this->textBox7->Location = System::Drawing::Point(277, 399);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 34);
			this->textBox7->TabIndex = 15;
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox7->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->ForeColor = System::Drawing::Color::Black;
			this->textBox6->Location = System::Drawing::Point(555, 279);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 34);
			this->textBox6->TabIndex = 13;
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox6->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->ForeColor = System::Drawing::Color::Black;
			this->textBox5->Location = System::Drawing::Point(555, 179);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 34);
			this->textBox5->TabIndex = 11;
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox5->Visible = false;
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->ForeColor = System::Drawing::Color::Black;
			this->textBox4->Location = System::Drawing::Point(555, 68);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 34);
			this->textBox4->TabIndex = 9;
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::Black;
			this->textBox3->Location = System::Drawing::Point(277, 68);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 34);
			this->textBox3->TabIndex = 7;
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Black;
			this->textBox2->Location = System::Drawing::Point(277, 179);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 34);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(277, 279);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 34);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(262, 373);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(130, 23);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Image Channels";
			this->label8->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(510, 252);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(195, 23);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Total Number Of Pixels";
			this->label7->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(510, 109);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(182, 46);
			this->label6->TabIndex = 12;
			this->label6->Text = L"         Width\r\n(Total Image Columns)";
			this->label6->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(520, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(161, 46);
			this->label5->TabIndex = 10;
			this->label5->Text = L"        Height\r\n(Total Image Rows)";
			this->label5->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(238, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(196, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Minimum Pixel Amplitude";
			this->label4->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(232, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(202, 23);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Maximum Pixel Amplitude";
			this->label3->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(236, 252);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Average Pixel Amplitude";
			this->label1->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->panel1->Controls->Add(this->SaveImg);
			this->panel1->Controls->Add(this->ResetImg);
			this->panel1->Controls->Add(this->RGB2Gray);
			this->panel1->Controls->Add(this->ImageProberties);
			this->panel1->Controls->Add(this->LoadImg);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(205, 576);
			this->panel1->TabIndex = 2;
			// 
			// SaveImg
			// 
			this->SaveImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SaveImg->Dock = System::Windows::Forms::DockStyle::Top;
			this->SaveImg->FlatAppearance->BorderSize = 0;
			this->SaveImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SaveImg->ForeColor = System::Drawing::Color::Gainsboro;
			this->SaveImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SaveImg.Image")));
			this->SaveImg->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SaveImg->Location = System::Drawing::Point(0, 280);
			this->SaveImg->Name = L"SaveImg";
			this->SaveImg->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->SaveImg->Size = System::Drawing::Size(205, 70);
			this->SaveImg->TabIndex = 4;
			this->SaveImg->Text = L"   Save";
			this->SaveImg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->SaveImg->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->SaveImg->UseVisualStyleBackColor = false;
			this->SaveImg->Visible = false;
			this->SaveImg->Click += gcnew System::EventHandler(this, &MyForm::Save_Click);
			// 
			// ResetImg
			// 
			this->ResetImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ResetImg->Dock = System::Windows::Forms::DockStyle::Top;
			this->ResetImg->FlatAppearance->BorderSize = 0;
			this->ResetImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ResetImg->ForeColor = System::Drawing::Color::Gainsboro;
			this->ResetImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ResetImg.Image")));
			this->ResetImg->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ResetImg->Location = System::Drawing::Point(0, 210);
			this->ResetImg->Name = L"ResetImg";
			this->ResetImg->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->ResetImg->Size = System::Drawing::Size(205, 70);
			this->ResetImg->TabIndex = 3;
			this->ResetImg->Text = L"   Reset";
			this->ResetImg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ResetImg->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->ResetImg->UseVisualStyleBackColor = false;
			this->ResetImg->Click += gcnew System::EventHandler(this, &MyForm::Reset_Click);
			// 
			// RGB2Gray
			// 
			this->RGB2Gray->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->RGB2Gray->Dock = System::Windows::Forms::DockStyle::Top;
			this->RGB2Gray->FlatAppearance->BorderSize = 0;
			this->RGB2Gray->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RGB2Gray->ForeColor = System::Drawing::Color::Gainsboro;
			this->RGB2Gray->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->RGB2Gray->Location = System::Drawing::Point(0, 140);
			this->RGB2Gray->Name = L"RGB2Gray";
			this->RGB2Gray->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->RGB2Gray->Size = System::Drawing::Size(205, 70);
			this->RGB2Gray->TabIndex = 2;
			this->RGB2Gray->Text = L"Convert Gray Scale";
			this->RGB2Gray->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->RGB2Gray->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->RGB2Gray->UseVisualStyleBackColor = false;
			this->RGB2Gray->Click += gcnew System::EventHandler(this, &MyForm::convertRgb2Gray_Click);
			// 
			// ImageProberties
			// 
			this->ImageProberties->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ImageProberties->Dock = System::Windows::Forms::DockStyle::Top;
			this->ImageProberties->FlatAppearance->BorderSize = 0;
			this->ImageProberties->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ImageProberties->ForeColor = System::Drawing::Color::Gainsboro;
			this->ImageProberties->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ImageProberties.Image")));
			this->ImageProberties->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ImageProberties->Location = System::Drawing::Point(0, 70);
			this->ImageProberties->Name = L"ImageProberties";
			this->ImageProberties->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->ImageProberties->Size = System::Drawing::Size(205, 70);
			this->ImageProberties->TabIndex = 1;
			this->ImageProberties->Text = L"Image Details";
			this->ImageProberties->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ImageProberties->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->ImageProberties->UseVisualStyleBackColor = false;
			this->ImageProberties->Click += gcnew System::EventHandler(this, &MyForm::ImageProberties_Click);
			// 
			// LoadImg
			// 
			this->LoadImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->LoadImg->Dock = System::Windows::Forms::DockStyle::Top;
			this->LoadImg->FlatAppearance->BorderSize = 0;
			this->LoadImg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoadImg->ForeColor = System::Drawing::Color::Gainsboro;
			this->LoadImg->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoadImg.Image")));
			this->LoadImg->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->LoadImg->Location = System::Drawing::Point(0, 0);
			this->LoadImg->Name = L"LoadImg";
			this->LoadImg->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->LoadImg->Size = System::Drawing::Size(205, 70);
			this->LoadImg->TabIndex = 0;
			this->LoadImg->Text = L"Select Image";
			this->LoadImg->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->LoadImg->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->LoadImg->UseVisualStyleBackColor = false;
			this->LoadImg->Click += gcnew System::EventHandler(this, &MyForm::LoadImg_Click);
			// 
			// mainTabC
			// 
			this->mainTabC->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->mainTabC->Controls->Add(this->index);
			this->mainTabC->Controls->Add(this->imageOperations);
			this->mainTabC->Controls->Add(this->PointProcessing);
			this->mainTabC->Controls->Add(this->NeighborhoodOperations);
			this->mainTabC->Controls->Add(this->ImageSegmentation);
			this->mainTabC->Controls->Add(this->tabPage1);
			this->mainTabC->Dock = System::Windows::Forms::DockStyle::Left;
			this->mainTabC->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->mainTabC->ItemSize = System::Drawing::Size(66, 25);
			this->mainTabC->Location = System::Drawing::Point(0, 0);
			this->mainTabC->Name = L"mainTabC";
			this->mainTabC->SelectedIndex = 0;
			this->mainTabC->Size = System::Drawing::Size(818, 615);
			this->mainTabC->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->mainTabC->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->GaussianNoise);
			this->tabPage1->Controls->Add(this->saltAndPepper);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(810, 582);
			this->tabPage1->TabIndex = 5;
			this->tabPage1->Text = L"Noise";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// GaussianNoise
			// 
			this->GaussianNoise->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->GaussianNoise->FlatAppearance->BorderSize = 0;
			this->GaussianNoise->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GaussianNoise->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GaussianNoise->ForeColor = System::Drawing::Color::Gainsboro;
			this->GaussianNoise->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->GaussianNoise->Location = System::Drawing::Point(281, 274);
			this->GaussianNoise->Name = L"GaussianNoise";
			this->GaussianNoise->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->GaussianNoise->Size = System::Drawing::Size(256, 65);
			this->GaussianNoise->TabIndex = 4;
			this->GaussianNoise->Text = L"       Gaussian Noise";
			this->GaussianNoise->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->GaussianNoise->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->GaussianNoise->UseVisualStyleBackColor = false;
			this->GaussianNoise->Click += gcnew System::EventHandler(this, &MyForm::GaussianNoise_Click);
			// 
			// saltAndPepper
			// 
			this->saltAndPepper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->saltAndPepper->FlatAppearance->BorderSize = 0;
			this->saltAndPepper->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saltAndPepper->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->saltAndPepper->ForeColor = System::Drawing::Color::Gainsboro;
			this->saltAndPepper->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->saltAndPepper->Location = System::Drawing::Point(281, 116);
			this->saltAndPepper->Name = L"saltAndPepper";
			this->saltAndPepper->Padding = System::Windows::Forms::Padding(14, 0, 0, 0);
			this->saltAndPepper->Size = System::Drawing::Size(256, 65);
			this->saltAndPepper->TabIndex = 3;
			this->saltAndPepper->Text = L"  Salt And Pepper Noise";
			this->saltAndPepper->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->saltAndPepper->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->saltAndPepper->UseVisualStyleBackColor = false;
			this->saltAndPepper->Click += gcnew System::EventHandler(this, &MyForm::saltAndPepper_Click);
			// 
			// ofd2
			// 
			this->ofd2->FileName = L"openFileDialog1";
			// 
			// Save3
			// 
			this->Save3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Save3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Save3->FlatAppearance->BorderSize = 0;
			this->Save3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save3->ForeColor = System::Drawing::Color::Gainsboro;
			this->Save3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Save3->Location = System::Drawing::Point(1217, 515);
			this->Save3->Name = L"Save3";
			this->Save3->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Save3->Size = System::Drawing::Size(115, 35);
			this->Save3->TabIndex = 5;
			this->Save3->Text = L"   Save";
			this->Save3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Save3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Save3->UseVisualStyleBackColor = false;
			this->Save3->Visible = false;
			this->Save3->Click += gcnew System::EventHandler(this, &MyForm::Save3_Click);
			// 
			// Reset3
			// 
			this->Reset3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Reset3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Reset3->FlatAppearance->BorderSize = 0;
			this->Reset3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Reset3->ForeColor = System::Drawing::Color::Gainsboro;
			this->Reset3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Reset3->Location = System::Drawing::Point(833, 515);
			this->Reset3->Name = L"Reset3";
			this->Reset3->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->Reset3->Size = System::Drawing::Size(115, 35);
			this->Reset3->TabIndex = 5;
			this->Reset3->Text = L"   Reset";
			this->Reset3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Reset3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Reset3->UseVisualStyleBackColor = false;
			this->Reset3->Click += gcnew System::EventHandler(this, &MyForm::Reset3_Click);
			// 
			// RGB2Gray2
			// 
			this->RGB2Gray2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->RGB2Gray2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->RGB2Gray2->FlatAppearance->BorderSize = 0;
			this->RGB2Gray2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RGB2Gray2->ForeColor = System::Drawing::Color::Gainsboro;
			this->RGB2Gray2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->RGB2Gray2->Location = System::Drawing::Point(971, 515);
			this->RGB2Gray2->Name = L"RGB2Gray2";
			this->RGB2Gray2->Padding = System::Windows::Forms::Padding(12, 0, 0, 0);
			this->RGB2Gray2->Size = System::Drawing::Size(216, 35);
			this->RGB2Gray2->TabIndex = 9;
			this->RGB2Gray2->Text = L"Convert to Gray Scale";
			this->RGB2Gray2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->RGB2Gray2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->RGB2Gray2->UseVisualStyleBackColor = false;
			this->RGB2Gray2->Click += gcnew System::EventHandler(this, &MyForm::RGB2Gray2_Click);
			// 
			// darkTheme
			// 
			this->darkTheme->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->darkTheme->BackColor = System::Drawing::Color::Transparent;
			this->darkTheme->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"darkTheme.BackgroundImage")));
			this->darkTheme->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->darkTheme->FlatAppearance->BorderSize = 0;
			this->darkTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->darkTheme->Location = System::Drawing::Point(1301, 12);
			this->darkTheme->Name = L"darkTheme";
			this->darkTheme->Size = System::Drawing::Size(31, 27);
			this->darkTheme->TabIndex = 10;
			this->darkTheme->UseVisualStyleBackColor = false;
			this->darkTheme->Click += gcnew System::EventHandler(this, &MyForm::darkTheme_Click);
			// 
			// greyTheme
			// 
			this->greyTheme->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->greyTheme->BackColor = System::Drawing::Color::Transparent;
			this->greyTheme->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"greyTheme.BackgroundImage")));
			this->greyTheme->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->greyTheme->FlatAppearance->BorderSize = 0;
			this->greyTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->greyTheme->Location = System::Drawing::Point(1264, 12);
			this->greyTheme->Name = L"greyTheme";
			this->greyTheme->Size = System::Drawing::Size(31, 27);
			this->greyTheme->TabIndex = 11;
			this->greyTheme->UseVisualStyleBackColor = false;
			this->greyTheme->Click += gcnew System::EventHandler(this, &MyForm::greyTheme_Click);
			// 
			// lightTheme
			// 
			this->lightTheme->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lightTheme->BackColor = System::Drawing::Color::Transparent;
			this->lightTheme->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"lightTheme.BackgroundImage")));
			this->lightTheme->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->lightTheme->FlatAppearance->BorderSize = 0;
			this->lightTheme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lightTheme->Location = System::Drawing::Point(1227, 12);
			this->lightTheme->Name = L"lightTheme";
			this->lightTheme->Size = System::Drawing::Size(31, 27);
			this->lightTheme->TabIndex = 12;
			this->lightTheme->UseVisualStyleBackColor = false;
			this->lightTheme->Click += gcnew System::EventHandler(this, &MyForm::lightTheme_Click);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1344, 615);
			this->Controls->Add(this->lightTheme);
			this->Controls->Add(this->greyTheme);
			this->Controls->Add(this->darkTheme);
			this->Controls->Add(this->RGB2Gray2);
			this->Controls->Add(this->Reset3);
			this->Controls->Add(this->Save3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->mainTabC);
			this->Controls->Add(this->pictureBox1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(1360, 654);
			this->Name = L"MyForm";
			this->Text = L"Omar\'sToolBox";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ImageSegmentation->ResumeLayout(false);
			this->ImageSegmentation->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ffs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FourierFilter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recog))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxV))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BoxH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->laplacianScroll))->EndInit();
			this->panel5->ResumeLayout(false);
			this->NeighborhoodOperations->ResumeLayout(false);
			this->NeighborhoodOperations->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Dbox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vbox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Hbox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gaussianFilterS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MedianScroll))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->circularS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->foureirFilter))->EndInit();
			this->panel4->ResumeLayout(false);
			this->PointProcessing->ResumeLayout(false);
			this->PointProcessing->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MinValue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MaxVlaue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threshHoldingS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logTransf))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->powerTrans))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->imageOperations->ResumeLayout(false);
			this->imageOperations->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->index->ResumeLayout(false);
			this->index->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->mainTabC->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//Color Management Customized Function
		void hideButtonColor() {
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));;
			this->LoadImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->LoadImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LoadImg->ForeColor = System::Drawing::Color::Gainsboro;

			this->ImageProberties->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ImageProberties->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ImageProberties->ForeColor = System::Drawing::Color::Gainsboro;

			this->RGB2Gray->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->RGB2Gray->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RGB2Gray->ForeColor = System::Drawing::Color::Gainsboro;

			this->ResetImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->ResetImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ResetImg->ForeColor = System::Drawing::Color::Gainsboro;

			this->SaveImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SaveImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SaveImg->ForeColor = System::Drawing::Color::Gainsboro;

			this->Translation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Translation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Translation->ForeColor = System::Drawing::Color::Gainsboro;

			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Gainsboro;

			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Gainsboro;

			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Gainsboro;

			this->Zoom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Zoom->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Zoom->ForeColor = System::Drawing::Color::Gainsboro;

			this->Reset2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Reset2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Reset2->ForeColor = System::Drawing::Color::Gainsboro;

			this->Save2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Save2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Save2->ForeColor = System::Drawing::Color::Gainsboro;
			this->pictureBox2->Visible = false;

			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Gainsboro;

			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button8->ForeColor = System::Drawing::Color::Gainsboro;

			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Gainsboro;

			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button10->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::Color::Gainsboro;

			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Gainsboro;

			this->powerTransformation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->powerTransformation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->powerTransformation->ForeColor = System::Drawing::Color::Gainsboro;

			this->logTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->logTrans->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->logTrans->ForeColor = System::Drawing::Color::Gainsboro;

			this->logTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->logTrans->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->logTrans->ForeColor = System::Drawing::Color::Gainsboro;

			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Gainsboro;

			this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button17->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button17->ForeColor = System::Drawing::Color::Gainsboro;

			this->grayLevelSlicing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->grayLevelSlicing->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->grayLevelSlicing->ForeColor = System::Drawing::Color::Gainsboro;

			this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::Color::Gainsboro;

			this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button13->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::Color::Gainsboro;

			this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button12->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::Color::Gainsboro;

			this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button11->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::Color::Gainsboro;

			this->MedianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->MedianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->MedianFilter->ForeColor = System::Drawing::Color::Gainsboro;

			this->gaussianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->gaussianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->gaussianFilter->ForeColor = System::Drawing::Color::Gainsboro;

			this->SobelFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SobelFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SobelFilter->ForeColor = System::Drawing::Color::Gainsboro;

			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Gainsboro;

			this->LaplacianDetection->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->LaplacianDetection->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->LaplacianDetection->ForeColor = System::Drawing::Color::Gainsboro;

			this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::Color::Gainsboro;

			this->SobelEdges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->SobelEdges->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SobelEdges->ForeColor = System::Drawing::Color::Gainsboro;

			this->Fourier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Fourier->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Fourier->ForeColor = System::Drawing::Color::Gainsboro;

			this->Fourier2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Fourier2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Fourier2->ForeColor = System::Drawing::Color::Gainsboro;

			this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->button18->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button18->ForeColor = System::Drawing::Color::Gainsboro;

			this->Reset3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Reset3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Reset3->ForeColor = System::Drawing::Color::Gainsboro;

			this->Save3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->Save3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Save3->ForeColor = System::Drawing::Color::Gainsboro;

			this->saltAndPepper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->saltAndPepper->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->saltAndPepper->ForeColor = System::Drawing::Color::Gainsboro;

			this->GaussianNoise->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->GaussianNoise->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->GaussianNoise->ForeColor = System::Drawing::Color::Gainsboro;

			this->RGB2Gray2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(76)));
			this->RGB2Gray2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RGB2Gray2->ForeColor = System::Drawing::Color::Gainsboro;


		}

    //Save Function
    void Savee() {
        sfd->Filter = "Bitmap Image (.bmp)|*.bmp|Gif Image (.gif)|*.gif |JPEG Image (.jpeg)|*.jpeg |Png Image (.png)|*.png |Tiff Image (.tiff)|*.tiff |Wmf Image (.wmf)|*.wmf";
        sfd->InitialDirectory = "C:\\";
        sfd->FileName = "deafult";
        sfd->RestoreDirectory = true;
        if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            pictureBox1->Image->Save(sfd->FileName, System::Drawing::Imaging::ImageFormat::Jpeg);
        }
    }
    //Hide & Show Save Button Functions
            void hideSave() {
                this->Save2->Visible = false;
                this->SaveImg->Visible = false;
                this->Save3->Visible = false;
            }
            void showSave() {
                this->Save2->Visible = true;
                this->SaveImg->Visible = true;
                this->Save3->Visible = true;
            }
    
    		//Hide Unwanted Details Function
		void hideUnwanted() {
			this->ZoomIn->Visible = false;
			this->ZoomOut->Visible = false;
			this->SkewUpRight->Visible = false;
			this->SkewUpLeft->Visible = false;
			this->SkewDownRight->Visible = false;
			this->SkewDownLeft->Visible = false;
			this->RotateRight->Visible = false;
			this->RotateLeft->Visible = false;
			this->CustomRotation->Visible = false;
			this->RotationVar->Visible = false;
			this->RotationLabel->Visible = false;
			this->RotateLabel->Visible = false;
			this->btnUp->Visible = false;
			this->UpRight->Visible = false;
			this->Right->Visible = false;
			this->DownRight->Visible = false;
			this->btnDown->Visible = false;
			this->DownLeft->Visible = false;
			this->Left->Visible = false;
			this->UpLeft->Visible = false;
			this->label10->Visible = false;
			this->label11->Visible = false;
			this->TransX->Visible = false;
			this->label12->Visible = false;
			this->TransY->Visible = false;
			this->CustomTranslation->Visible = false;
			this->label13->Visible = false;
			this->xmirror->Visible = false;
			this->ymirror->Visible = false;
			this->xymirror->Visible = false;
			this->textBox1->Visible = false;
			this->textBox2->Visible = false;
			this->textBox3->Visible = false;
			this->textBox4->Visible = false;
			this->textBox5->Visible = false;
			this->textBox6->Visible = false;
			this->textBox7->Visible = false;
			this->textBox8->Visible = false;
			this->label1->Visible = false;
			this->label9->Visible = false;
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->label8->Visible = false;
			this->pictureBox2->Visible = false;
			this->ConfCrop->Visible = false;
			this->label14->Visible = false;
			this->pictureBox3->Visible = false;
			this->selectImg->Visible = false;
			this->Blind->Visible = false;
			this->label15->Visible = false;
			this->textBox9->Visible = false;
			this->cnfrmBlind->Visible = false;
			this->powerTrans->Visible = false;
			this->cnfrmPowerTrans->Visible = false;
			this->bightLabel->Visible = false;
			this->cnfrmChanges->Visible = false;
			this->logTransf->Visible = false;
			this->logLabel->Visible = false;
			this->cnfrmChangess->Visible = false;
			this->foureirFilter->Visible = false;
			this->dftLabel->Visible = false;
			this->label16->Visible = false;
			this->trackBar1->Visible = false;
			this->cnfrmTraditional->Visible = false;
			this->trackBar2->Visible = false;
			this->button16->Visible = false;
			this->circularS->Visible = false;
			this->cnfrmCircular->Visible = false;
			this->coneFilter->Visible = false;
			this->cnfrmCone->Visible = false;
			this->MedianScroll->Visible = false;
			this->cnfrmMedian->Visible = false;
			this->PlaneLabel->Visible = false;
			this->BitPlaneBox->Visible = false;
			this->SelectedBitLabel->Visible = false;
			this->ChoosenPlane->Visible = false;
			this->cnfrmBitPlaneSelection->Visible = false;
			this->SavePlane->Visible = false;
			this->threshHoldingCnfrm->Visible = false;
			this->threshHoldingS->Visible = false;
			this->ThreshLabel->Visible = false;
			this->labelMin->Visible = false;
			this->labelMax->Visible = false;
			this->MinValue->Visible = false;
			this->MaxVlaue->Visible = false;
			this->HighlightGray->Visible = false;
			this->secHighlightGray->Visible = false;
			this->saveGrayRange->Visible = false;
			this->label18->Visible = false;
			this->label17->Visible = false;
			this->gaussianFilterS->Visible = false;
			this->cnfrmGaussSave->Visible = false;
			this->applyingSobel->Visible = false;
			this->cnfrmSobel->Visible = false;
			this->Hlabel->Visible = false;
			this->Vlabel->Visible = false;
			this->Dlabel->Visible = false;
			this->Dbox->Visible = false;
			this->Vbox->Visible = false;
			this->Hbox->Visible = false;
			this->fLabel->Visible = false;
			this->laplacianFilters->Visible = false;
			this->selectLabel->Visible = false;
			this->SelectedLabel->Visible = false;
			this->applyingLaplacian->Visible = false;
			this->cnfrmLaplacian->Visible = false;
			this->laplaceLabel->Visible = false;
			this->laplacianScroll->Visible = false;
			this->saveEdges->Visible = false;
			this->ThreshhHold->Visible = false;
			this->threshS->Visible = false;
			this->cnfrmThresholding->Visible = false;
			this->SaveSobel->Visible = false;
			this->labelH->Visible = false;
			this->labelV->Visible = false;
			this->labelD->Visible = false;
			this->BoxD->Visible = false;
			this->BoxV->Visible = false;
			this->BoxH->Visible = false;
			this->Sobel->Visible = false;
			this->Recog->Visible = false;
			this->FourierFilter->Visible = false;
			this->LPF->Visible = false;
			this->lowPass->Visible = false;
			this->minRange->Visible = false;
			this->maxRange->Visible = false;
			this->powerBox->Visible = false;
			this->logBox->Visible = false;
			this->threshBox->Visible = false;
			this->saveFFS->Visible = false;
			this->ffs->Visible = false;
			this->LPF->Visible = false;

		}


        //String matching 
    void MarshalString(System::String^ s, std::string& os) {
        //set system string and std string to be the same string
        using namespace Runtime::InteropServices;
        const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
        os = chars;
        Marshal::FreeHGlobal(IntPtr((void*)chars));
    }

    		//region of interest 

		System::Drawing::Rectangle GetRect() {

			Rect = System::Drawing::Rectangle(); //creating new Rectangle object

			Rect.X = min(LocationXY.X, Locationx1y1.X);//value of x must be between starting point and current point

			Rect.Y = min(LocationXY.Y, Locationx1y1.Y);//value of y must be between starting point and current point

			Rect.Width = (LocationXY.X - Locationx1y1.X);

			Rect.Height = (LocationXY.Y - Locationx1y1.Y);

			return Rect;


		}

		//roi
		/*static void onMouse(int event, int x, int y, int flags, void*)
		{
			if (selectObject)
			{
				selection.x = min(x, origin.x);
				selection.y = min(y, origin.y);
				selection.width = abs(x - origin.x);
				selection.height = abs(y - origin.y);

				selection &= Rect(0, 0, src.cols, src.rows);
			}
			switch (event)
			{
			case EVENT_LBUTTONDOWN:
				origin = cv::Point(x, y);
				selection = Rect(x, y, 0, 0);
				selectObject = true;
				break;

			case EVENT_LBUTTONUP:
				selectObject = false;
				if (selection.width > 0 && selection.height > 0)
				{
					objectCropped = true;
				}


			default:
				break;
			}

			src.copyTo(image);
			rectangle(image, selection, Scalar(255, 0, 0), 3, 8, 0);
			imshow("image", image);


		}*/

        		//adding noises
		void Add_salt_pepper_Noise(Mat& srcArr, float pa, float pb)

		{
			RNG rng;
			int amount1 = srcArr.rows * srcArr.cols * pa;
			int amount2 = srcArr.rows * srcArr.cols * pb;
			for (int counter = 0; counter < amount1; ++counter)
			{
				srcArr.at<uchar>(rng.uniform(0, srcArr.rows), rng.uniform(0, srcArr.cols)) = 0;

			}
			for (int counter = 0; counter < amount2; ++counter)
			{
				srcArr.at<uchar>(rng.uniform(0, srcArr.rows), rng.uniform(0, srcArr.cols)) = 255;
			}
		}
		void Add_gaussian_Noise(Mat& srcArr, double mean, double sigma)
		{
			Mat NoiseArr = srcArr.clone();
			RNG rng;
			rng.fill(NoiseArr, RNG::NORMAL, mean, sigma);

			add(srcArr, NoiseArr, srcArr);
		}

        		//Get Contour Custoom Function
		void getContours(Mat imgDil, Mat src) {

			vector<vector<cv::Point>> contours;
			vector<Vec4i> hierarchy;

			findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
			//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

			vector<vector<cv::Point>> conPoly(contours.size());
			vector<cv::Rect> boundRect(contours.size());

			for (int i = 0; i < contours.size(); i++)
			{
				int area = contourArea(contours[i]);
				cout << area << endl;
				string objectType;

				if (area > 1000)
				{
					float peri = arcLength(contours[i], true);
					approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
					cout << conPoly[i].size() << endl;
					boundRect[i] = boundingRect(conPoly[i]);

					int objCor = (int)conPoly[i].size();

					if (objCor == 3) { objectType = "Tri"; }
					else if (objCor == 4)
					{
						float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
						cout << aspRatio << endl;
						if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
						else { objectType = "Rect"; }
					}
					else if (objCor > 4) { objectType = "Circle"; }

					drawContours(src, conPoly, i, Scalar(255, 0, 255), 2);
					rectangle(src, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
					putText(src, objectType, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 2);
				}
			}
		}
    
#pragma endregion
    	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   //Button That Loads the Image
	private: System::Void LoadImg_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->LoadImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;
		this->LoadImg->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->LoadImg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;

		//btn to Select the image that will be opened in the picture box
		hideUnwanted();
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			path = ofd->FileName;
			MarshalString(path, x);
			src = imread(x);
			if (src.empty())
			{
				MessageBox::Show("Please enter an image");
			}
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			ofd->RestoreDirectory = true;
		}
	}
    		   //Button That Shows the Image Details
	private: System::Void ImageProberties_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->ImageProberties->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
			static_cast<System::Int32>(static_cast<System::Byte>(159)));;
		this->ImageProberties->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->ImageProberties->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(47)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
			static_cast<System::Int32>(static_cast<System::Byte>(159)));;
		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			this->textBox1->Visible = true;
			this->textBox2->Visible = true;
			this->textBox3->Visible = true;
			this->textBox4->Visible = true;
			this->textBox5->Visible = true;
			this->textBox6->Visible = true;
			this->textBox7->Visible = true;
			this->textBox8->Visible = true;
			this->label1->Visible = true;
			this->label9->Visible = true;
			this->label3->Visible = true;
			this->label4->Visible = true;
			this->label5->Visible = true;
			this->label6->Visible = true;
			this->label7->Visible = true;
			this->label8->Visible = true;

			int max = 0;
			for (int i = 0; i < src.rows; i++)
			{
				for (int j = 0; j < src.cols; j++)
				{
					if (src.at<uchar>(i, j) > max)
					{
						max = src.at<uchar>(i, j);
					}
				}
			}
			int min = 255;
			for (int i = 0; i < src.rows; i++)
				for (int j = 0; j < src.cols; j++)
					if (src.at<uchar>(i, j) < min)
						min = src.at<uchar>(i, j);

			int sum = 0;
			for (int i = 0; i < src.rows; i++)
				for (int j = 0; j < src.cols; j++)
					sum = sum + src.at<uchar>(i, j);
			int avg = sum / src.total();


			//Showing Values on TextBoxes
			textBox1->Text = System::Convert::ToString(avg);
			textBox2->Text = System::Convert::ToString(max);
			textBox3->Text = System::Convert::ToString(min);
			textBox4->Text = System::Convert::ToString(src.rows);
			textBox5->Text = System::Convert::ToString(src.cols);
			textBox6->Text = System::Convert::ToString(src.total());
			textBox7->Text = System::Convert::ToString(src.channels());
			textBox8->Text = System::Convert::ToString(src.depth()); //return a number from 0 to 6 

			//imwrite("x.jpg", src);
			//pictureBox1->ImageLocation = "x.jpg";
			//ofd->FileName = pictureBox1->ImageLocation;
		}
	}

    		   //Changes from rgb to gray scale
	private: System::Void convertRgb2Gray_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->RGB2Gray->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
			static_cast<System::Int32>(static_cast<System::Byte>(117)));;
		this->RGB2Gray->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->RGB2Gray->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
			static_cast<System::Int32>(static_cast<System::Byte>(117)));;

		hideUnwanted();
		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() == 1)
		{
			MessageBox::Show("Picture is already Gray");
		}
		else
		{
			cvtColor(src, src, COLOR_BGR2GRAY);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			showSave();
		}
	}
    		   //resets the image to the original image
	private: System::Void Reset_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->ResetImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;
		this->ResetImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->ResetImg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			src = imread(x);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			hideSave();
		}
		int n = 0;
		textBox1->Text = System::Convert::ToString(n);
		textBox2->Text = System::Convert::ToString(n);
		textBox3->Text = System::Convert::ToString(n);
		textBox4->Text = System::Convert::ToString(n);
		textBox5->Text = System::Convert::ToString(n);
		textBox6->Text = System::Convert::ToString(n);
		textBox7->Text = System::Convert::ToString(n);
		textBox8->Text = System::Convert::ToString(n);
	}
    		   //Saves the image in the Desired location
	private: System::Void Save_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->SaveImg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;
		this->SaveImg->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->SaveImg->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else {
			hideUnwanted();
			Savee();
		}
	}

    		   //Image Translation Section
	private: System::Void Translation_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Translation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
			static_cast<System::Int32>(static_cast<System::Byte>(215)));;
		this->Translation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Translation->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(162)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
			static_cast<System::Int32>(static_cast<System::Byte>(215)));;


		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			this->btnUp->Visible = true;
			this->UpRight->Visible = true;
			this->Right->Visible = true;
			this->DownRight->Visible = true;
			this->btnDown->Visible = true;
			this->DownLeft->Visible = true;
			this->Left->Visible = true;
			this->UpLeft->Visible = true;
			this->label10->Visible = true;
			this->label11->Visible = true;
			this->TransX->Visible = true;
			this->label12->Visible = true;
			this->TransY->Visible = true;
			this->CustomTranslation->Visible = true;
			this->label13->Visible = true;
		}
	}
	private: System::Void btnUp_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, 0, 0, 1, -10);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void UpRight_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, 5, 0, 1, -5);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void Right_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, 10, 0, 1, 0);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void DownRight_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, 5, 0, 1, 5);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void btnDown_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, 0, 0, 1, 10);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void DownLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, -5, 0, 1, 5);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void Left_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, -10, 0, 1, 0);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void UpLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		Mat TM = (Mat_<float>(2, 3) << 1, 0, -5, 0, 1, -5);
		warpAffine(src, src, TM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void CustomTranslation_Click(System::Object^ sender, System::EventArgs^ e) {
		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			double tx = 0;
			tx = System::Convert::ToDouble(TransX->Text);
			double ty = 0;
			ty = System::Convert::ToDouble(TransY->Text);

			Mat TM = (Mat_<float>(2, 3) << 1, 0, tx, 0, 1, -ty);
			warpAffine(src, src, TM, src.size());
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			if (tx != 0 || ty != 0)
			{
				showSave();
			}
		}
	}

    		   //Image Flip Section
	private: System::Void Mirror_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
			static_cast<System::Int32>(static_cast<System::Byte>(233)));;
		this->button5->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(222)),
			static_cast<System::Int32>(static_cast<System::Byte>(233)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			this->xmirror->Visible = true;
			this->ymirror->Visible = true;
			this->xymirror->Visible = true;
		}
	}
	private: System::Void xmirror_Click(System::Object^ sender, System::EventArgs^ e) {
		flip(src, src, 1);
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void ymirror_Click(System::Object^ sender, System::EventArgs^ e) {
		flip(src, src, 0);
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void xymirror_Click(System::Object^ sender, System::EventArgs^ e) {
		flip(src, src, -1);
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}

    		   //Image Rotation Section
	private: System::Void RotateRight_Click(System::Object^ sender, System::EventArgs^ e) {
		//Mat R = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), -90, 1);
		//warpAffine(src, src, R, src.size());
		//imwrite("x.jpg", src);
		//pictureBox1->ImageLocation = "x.jpg";
		//ofd->FileName = pictureBox1->ImageLocation;
		pictureBox1->Image->RotateFlip(RotateFlipType::Rotate90FlipNone);
		pictureBox1->Refresh();
		showSave();
	}
	private: System::Void RotateLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		//Mat R = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), 90, 1);
		//warpAffine(src, src, R, src.size());
		//imwrite("x.jpg", src);
		//pictureBox1->ImageLocation = "x.jpg";
		//ofd->FileName = pictureBox1->ImageLocation;
		pictureBox1->Image->RotateFlip(RotateFlipType::Rotate270FlipNone);
		pictureBox1->Refresh();
		showSave();
	}
	private: System::Void CustomRotation_Click(System::Object^ sender, System::EventArgs^ e) {
		double a = 0;
		a = System::Convert::ToDouble(RotationVar->Text);
		Mat R = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), -a, 1);
		warpAffine(src, src, R, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		if (a != 0)
		{
			showSave();
		}
	}
	private: System::Void Rotation(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;
		this->button4->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			this->RotateRight->Visible = true;
			this->RotateLeft->Visible = true;
			this->CustomRotation->Visible = true;
			this->RotationVar->Visible = true;
			this->RotationLabel->Visible = true;
			this->RotateLabel->Visible = true;
		}
	}

    		   //Image Skewing Section
	private: System::Void Skewing_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
			static_cast<System::Int32>(static_cast<System::Byte>(97)));;
		this->button1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
			static_cast<System::Int32>(static_cast<System::Byte>(97)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			this->SkewUpRight->Visible = true;
			this->SkewUpLeft->Visible = true;
			this->SkewDownRight->Visible = true;
			this->SkewDownLeft->Visible = true;
		}
	}
	private: System::Void SkewUpRight_Click(System::Object^ sender, System::EventArgs^ e) {
		Point2f ori[3], dest[3];
		ori[0] = Point2f(0, src.rows - 1);
		ori[1] = Point2f(src.rows - 1, src.cols - 1);
		ori[2] = Point2f(src.cols - 6, 0);
		dest[0] = Point2f(0, src.rows - 1);
		dest[1] = Point2f(src.rows - 1, src.cols - 1);
		dest[2] = Point2f(src.cols - 1, 0);
		Mat SM = getAffineTransform(ori, dest);
		warpAffine(src, src, SM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void SkewUpLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		Point2f ori[3], dest[3];
		ori[0] = Point2f(0, src.rows - 1);
		ori[1] = Point2f(src.rows - 1, src.cols - 1);
		ori[2] = Point2f(5, 0);
		dest[0] = Point2f(0, src.rows - 1);
		dest[1] = Point2f(src.rows - 1, src.cols - 1);
		dest[2] = Point2f(0, 0);
		Mat SM = getAffineTransform(ori, dest);
		warpAffine(src, src, SM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void SkewDownRight_Click(System::Object^ sender, System::EventArgs^ e) {
		Point2f ori[3], dest[3];
		ori[0] = Point2f(0, 0);
		ori[1] = Point2f(src.cols - 1, 0);
		ori[2] = Point2f(src.cols - 6, src.rows - 1);
		dest[0] = Point2f(0, 0);
		dest[1] = Point2f(src.cols - 1, 0);
		dest[2] = Point2f(src.cols - 1, src.rows - 1);
		Mat SM = getAffineTransform(ori, dest);
		warpAffine(src, src, SM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void SkewDownLeft_Click(System::Object^ sender, System::EventArgs^ e) {
		Point2f ori[3], dest[3];
		ori[0] = Point2f(0, 0);
		ori[1] = Point2f(src.cols - 1, 0);
		ori[2] = Point2f(5, src.rows - 1);
		dest[0] = Point2f(0, 0);
		dest[1] = Point2f(src.cols - 1, 0);
		dest[2] = Point2f(0, src.rows - 1);
		Mat SM = getAffineTransform(ori, dest);
		warpAffine(src, src, SM, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}

    		   //Image Zooming Section
	private: System::Void Zoom_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Zoom->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
			static_cast<System::Int32>(static_cast<System::Byte>(204)));;
		this->Zoom->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Zoom->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(196)),
			static_cast<System::Int32>(static_cast<System::Byte>(204)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			this->ZoomIn->Visible = false;
			this->ZoomOut->Visible = false;
			this->ZoomIn->Visible = true;
			this->ZoomOut->Visible = true;
		}
	}
	private: System::Void ZoomIn_Click(System::Object^ sender, System::EventArgs^ e) {
		/*
		* Mat Z = src(Rect(0,0,src.cols/2,src.rows/2));
		* resize(src,src,cv::Size(),2,2,0);
		*/
		/*Mat Z = getRotationMatrix2D(Point2f(src.cols / 2, src.rows / 2), 0, 1.2);
		warpAffine(src, src, Z, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;*/
		int zoomlevel = 50;
		pictureBox1->Top -= zoomlevel / 2;
		pictureBox1->Left -= zoomlevel / 2;
		pictureBox1->Width += zoomlevel;
		pictureBox1->Height += zoomlevel;
		showSave();
	}
	private: System::Void ZoomOut_Click(System::Object^ sender, System::EventArgs^ e) {
		/*Mat Z = getRotationMatrix2D(Point2f(src.cols/2,src.rows/2),0,0.8);
		warpAffine(src, src, Z, src.size());
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;*/
		int zoomlevel = 50;
		pictureBox1->Top += zoomlevel / 2;
		pictureBox1->Left += zoomlevel / 2;
		pictureBox1->Width -= zoomlevel;
		pictureBox1->Height -= zoomlevel;
		showSave();
	}

    private: System::Void Crop_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;
		this->button3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			////crop main code
			//namedWindow("image", 0);
			//setMouseCallback("image",onMouse);
			//imshow("image", src);
			//Mat crop;
			//int d = 1;
			//while (d == 1)
			//{
			//	if (objectCropped)
			//	{
			//		crop = src(selection);

			//		d = 0;
			//	}
			//	waitKey(10);
			//}
			//crop.copyTo(src);

			hideUnwanted();
			this->pictureBox2->Visible = true;
			this->ConfCrop->Visible = true;
			this->label14->Visible = true;
			pictureBox2->ImageLocation = "x.jpg";

		}
	}

		   //Region of interest (Detecting mouse selection area) for croping function

	private: System::Void pictureBox2_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		isMouseDown = true;  //in event occurance this var is true
		LocationXY = e->Location; //getting the starting point of x and y
	}
	private: System::Void pictureBox2_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown == true)    //this block will be excuted only when mouse down event is occuring
		{
			Locationx1y1 = e->Location; // Get the current point of x & y
			Refresh();
		}
	}
	private: System::Void pictureBox2_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isMouseDown == true)    //this block will be excuted only when mouse down event is occuring
		{
			Locationx1y1 = e->Location; // Get the ending point of x & y

			isMouseDown = false;
		}
	}
	private: System::Void pictureBox2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Create pen.
		Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);


		// Draw rectangle to screen.
		e->Graphics->DrawRectangle(bluePen, GetRect());//GetRect() is a function
	}

	private: System::Void ConfCrop_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox2->ImageLocation = "x.jpg";

		rect1.x = 0;
		rect1.y = 0;
		rect1.width = 0;
		rect1.height = 0;

		rect1.x = min(LocationXY.X, Locationx1y1.X);
		rect1.y = min(LocationXY.Y, Locationx1y1.Y);
		rect1.width = abs(LocationXY.X - Locationx1y1.X);
		rect1.height = abs(LocationXY.Y - Locationx1y1.Y);
		rect1 &= cv::Rect(0, 0, src.cols, src.rows);
		//rect1 = cv::Rect(e->Location.X, e->Location.Y, 0, 0);

		Mat crop = src(rect1);
		src = crop;

		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();

	}

    		   //Second TAB Reset And Save
	private: System::Void Reset2_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Reset2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;
		this->Reset2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Reset2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideSave();
			hideUnwanted();
			src = imread(x);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;

		}
	}
	private: System::Void Save2_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Save2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;
		this->Save2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Save2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else {
			hideUnwanted();
			Savee();
		}
	}

    		   //Negative Buttons
	private: System::Void Negative_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;
		this->button10->Font = (gcnew System::Drawing::Font(L"Tahoma", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
			static_cast<System::Int32>(static_cast<System::Byte>(65)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			showSave();
			hideUnwanted();
			for (int i = 0; i < src.rows; i++)
			{
				for (int j = 0; j < src.cols; j++)
				{
					src.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);
				}
			}
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			showSave();
		}
	}

    		   //Histogram Equalization Buttons
	private: System::Void HistEqualize_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;
		this->button9->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			showSave();
			hideUnwanted();
			equalizeHist(src, src);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			showSave();
		}
	}

    		   //Histogram Visualization Buttons
	private: System::Void ShowHist_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;
		this->button8->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;


		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			this->pictureBox3->Visible = true;
			histVisualize = true;
			float hist[256] = { 0 };
			int max = 0;
			for (int g = 0; g < 256; g++)
			{
				for (int r = 0; r < src.rows; r++)
					for (int c = 0; c < src.cols; c++)
					{
						if (src.at<uchar>(r, c) == g)
						{
							hist[g] = hist[g] + 1;
						}
						if (hist[g] > max)
						{
							max = hist[g];
						}
					}
			}
			////////////////visualizing histogram//////////////////////////
			Mat hist_img(max, 510, CV_8UC1, Scalar(0));
			for (int s = 0; s < 256; s++)
			{
				float bin_val = hist[s];
				line(hist_img, cv::Point(s * 2 + 2, max), cv::Point(s * 2 + 2, max - bin_val), Scalar(255), 1);
			}
			imwrite("j.jpg", hist_img);
			pictureBox3->ImageLocation = "j.jpg";
		}
	}

    		   //Two Images Blinding Buttons
	private: System::Void waterMark_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
			static_cast<System::Int32>(static_cast<System::Byte>(197)));;
		this->button2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
			static_cast<System::Int32>(static_cast<System::Byte>(197)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->selectImg->Visible = true;
			this->Blind->Visible = true;
			this->label15->Visible = true;
			this->textBox9->Visible = true;
			this->cnfrmBlind->Visible = true;

		}
	}
	private: System::Void selectImg_Click(System::Object^ sender, System::EventArgs^ e) {

		if (ofd2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			path1 = ofd2->FileName;
			MarshalString(path1, x1);
			blind = imread(x1, 0);
		}
	}
	private: System::Void Blind_Click(System::Object^ sender, System::EventArgs^ e) {
		resize(blind, blind, src.size());
		for (int i = 0; i < src.rows; i++)
		{
			for (int j = 0; j < src.cols; j++)
			{
				src.at<uchar>(i, j) = src.at<uchar>(i, j) * 0.9 + blind.at<uchar>(i, j) * 0.1;
			}
		}
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		showSave();
	}
	private: System::Void cnfrmBlind_Click(System::Object^ sender, System::EventArgs^ e) {
		if (blind.empty())
		{
			MessageBox::Show("Please Select an Image");
		}
		else
		{
			double a = System::Convert::ToDouble(textBox9->Text);
			if (a < 0)
			{
				MessageBox::Show("Please enter a Valid Number");
			}
			else
			{
				a = a / 100;
				double b = 1 - a;
				resize(blind, blind, src.size());
				for (int i = 0; i < src.rows; i++)
				{
					for (int j = 0; j < src.cols; j++)
					{
						src.at<uchar>(i, j) = src.at<uchar>(i, j) * b + blind.at<uchar>(i, j) * a;
					}
				}
				imwrite("x.jpg", src);
				pictureBox1->ImageLocation = "x.jpg";
				ofd->FileName = pictureBox1->ImageLocation;
				showSave();
			}
		}
	}

    		   //Gamma Correction Buttons
	private: System::Void powerTransformation_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->powerTransformation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(36)));;
		this->powerTransformation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->powerTransformation->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(233)), static_cast<System::Int32>(static_cast<System::Byte>(233)),
			static_cast<System::Int32>(static_cast<System::Byte>(233)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(36)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->powerBox->Visible = true;
			this->powerTrans->Visible = true;
			this->cnfrmPowerTrans->Visible = true;
			this->bightLabel->Visible = true;
		}
	}

    	private: System::Void powerTrans_Scroll(System::Object^ sender, System::EventArgs^ e) {

		powerTrans->Minimum = 1;
		powerTrans->Maximum = 20;
		powerBox->Text = System::Convert::ToString(powerTrans->Value);

		Mat dst(src.size(), CV_32FC1);
		for (int i = 0; i < dst.rows; i++)
		{
			for (int j = 0; j < dst.cols; j++)
			{
				dst.at<float>(i, j) = powf(src.at<uchar>(i, j), powerTrans->Value * 0.1);
			}
		}
		normalize(dst, dst, 0, 255, NORM_MINMAX);
		convertScaleAbs(dst, dst);
		imwrite("x.jpg", dst);
		pictureBox1->ImageLocation = "x.jpg";
		blind = dst;
	}
	private: System::Void cnfrmPowerTrans_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		powerTrans->Value = 10;
		powerBox->Text = System::Convert::ToString(0);
	}

    		   //LogTransformation Buttons
	private: System::Void logTrans_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->logTrans->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
			static_cast<System::Int32>(static_cast<System::Byte>(137)));;
		this->logTrans->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->logTrans->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(112)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
			static_cast<System::Int32>(static_cast<System::Byte>(137)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->logBox->Visible = true;
			this->cnfrmChanges->Visible = true;
			this->logTransf->Visible = true;
			this->logLabel->Visible = true;
		}
	}
	private: System::Void logTransf_Scroll(System::Object^ sender, System::EventArgs^ e) {
		logTransf->Minimum = 1;
		logTransf->Maximum = 32;
		logBox->Text = System::Convert::ToString(logTransf->Value);

		Mat dst(src.size(), CV_32FC1);
		for (int i = 0; i < dst.rows; i++)
		{
			for (int j = 0; j < dst.cols; j++)
			{
				dst.at<float>(i, j) = log(src.at<uchar>(i, j) + logTransf->Value);
			}
		}
		normalize(dst, dst, 0, 255, NORM_MINMAX);
		convertScaleAbs(dst, dst);
		imwrite("x.jpg", dst);
		pictureBox1->ImageLocation = "x.jpg";
		blind = dst;
	}
	private: System::Void cnfrmChanges_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		logTransf->Value = 32;
		logBox->Text = System::Convert::ToString(0);
	}

    		   //Bit Plane Slicing
	private: System::Void BitPlane_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
			static_cast<System::Int32>(static_cast<System::Byte>(47)));;
		this->button7->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(118)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
			static_cast<System::Int32>(static_cast<System::Byte>(47)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->PlaneLabel->Visible = true;
			this->BitPlaneBox->Visible = true;
			this->SelectedBitLabel->Visible = true;
			this->ChoosenPlane->Visible = true;
			this->cnfrmBitPlaneSelection->Visible = true;
			this->SavePlane->Visible = true;
		}
	}
	private: System::Void BitPlaneBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		ChoosenPlane->Text = BitPlaneBox->Text;
	}
	private: System::Void cnfrmBitPlaneSelection_Click(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		if (BitPlaneBox->Text == "First Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 1)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Second Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 2)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Third Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 4)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Fourth Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 8)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Fifth Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < src.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 16)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Sixth Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 32)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else if (BitPlaneBox->Text == "Seventh Plane")
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 64)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < blind.rows; i++)
			{
				for (int j = 0; j < blind.cols; j++)
				{
					if (blind.at<uchar>(i, j) & 128)
					{
						blind.at<uchar>(i, j) = 255;
					}
					else
					{
						blind.at<uchar>(i, j) = 0;
					}
				}
			}
		}
		imwrite("plane.jpg", blind);
		pictureBox1->ImageLocation = "plane.jpg";
	}
	private: System::Void SavePlane_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
	}

    		   //Thresholding
	private: System::Void threshHolding_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
			static_cast<System::Int32>(static_cast<System::Byte>(229)));;
		this->button17->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(3)), static_cast<System::Int32>(static_cast<System::Byte>(3)),
			static_cast<System::Int32>(static_cast<System::Byte>(3)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(146)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
			static_cast<System::Int32>(static_cast<System::Byte>(229)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->threshBox->Visible = true;
			this->threshHoldingCnfrm->Visible = true;
			this->threshHoldingS->Visible = true;
			this->ThreshLabel->Visible = true;
		}
	}
	private: System::Void threshHoldingS_Scroll(System::Object^ sender, System::EventArgs^ e) {
		threshHoldingS->Minimum = 1;
		threshHoldingS->Maximum = 255;
		threshBox->Text = System::Convert::ToString(threshHoldingS->Value);

		blind = src.clone();
		threshold(src, blind, threshHoldingS->Value, 255, THRESH_BINARY);
		imwrite("plane.jpg", blind);
		pictureBox1->ImageLocation = "plane.jpg";
	}
	private: System::Void threshHoldingCnfrm_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
		threshBox->Text = System::Convert::ToString(0);
		threshHoldingS->Value = 1;
	}

    		   //Gray Level Slicing
	private: System::Void grayLevelSlicing_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->grayLevelSlicing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
			static_cast<System::Int32>(static_cast<System::Byte>(37)));;
		this->grayLevelSlicing->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->grayLevelSlicing->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(134)),
			static_cast<System::Int32>(static_cast<System::Byte>(37)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->minRange->Visible = true;
			this->maxRange->Visible = true;
			this->labelMin->Visible = true;
			this->labelMax->Visible = true;
			this->MinValue->Visible = true;
			this->MaxVlaue->Visible = true;
			this->HighlightGray->Visible = true;
			this->secHighlightGray->Visible = true;
			this->saveGrayRange->Visible = true;
			this->label18->Visible = true;
			this->label17->Visible = true;
		}

	}
	private: System::Void MinValue_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MinValue->Minimum = 0;
		MinValue->Maximum = MaxVlaue->Value;
		minRange->Text = System::Convert::ToString(MinValue->Value);
	}
	private: System::Void MaxVlaue_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MaxVlaue->Minimum = MinValue->Value;
		MaxVlaue->Maximum = 255;
		maxRange->Text = System::Convert::ToString(MaxVlaue->Value);
	}
	private: System::Void HighlightGray_Click(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		for (int i = 0; i < src.rows; i++)
		{
			for (int j = 0; j < src.cols; j++)
			{
				if (blind.at<uchar>(i, j) > MinValue->Value && blind.at<uchar>(i, j) < MaxVlaue->Value)
				{
					blind.at<uchar>(i, j) = 255;
				}
				else
				{
					blind.at<uchar>(i, j) = blind.at<uchar>(i, j);
				}
			}
		}
		imwrite("plane.jpg", blind);
		pictureBox1->ImageLocation = "plane.jpg";
	}
	private: System::Void secHighlightGray_Click(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		for (int i = 0; i < src.rows; i++)
		{
			for (int j = 0; j < src.cols; j++)
			{
				if (blind.at<uchar>(i, j) > MinValue->Value && blind.at<uchar>(i, j) < MaxVlaue->Value)
				{
					blind.at<uchar>(i, j) = 255;
				}
				else
				{
					blind.at<uchar>(i, j) = 0;
				}
			}
		}
		imwrite("plane.jpg", blind);
		pictureBox1->ImageLocation = "plane.jpg";
	}
	private: System::Void saveGrayRange_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
		MaxVlaue->Value = 255;
		MinValue->Value = 0;
	}

    		   //Traditional Filter
	private: System::Void traditionalFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));;
		this->button14->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(84)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
			static_cast<System::Int32>(static_cast<System::Byte>(192)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->label16->Visible = true;
			this->trackBar1->Visible = true;
			this->cnfrmTraditional->Visible = true;
		}
	}
	private: System::Void traditionalFilter_Scroll(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		trackBar1->Maximum = 15;
		trackBar1->Minimum = 3;

		Mat  filter;
		int count = 0;

		Mat Kernel = (Mat_<float>(trackBar1->Value, trackBar1->Value));
		for (int i = 0; i < trackBar1->Value; i++) {
			for (int j = 0; j < trackBar1->Value; j++) {
				count++;
				Kernel.at<float>(i, j) = 1;
			}
		}
		Kernel /= count;
		filter2D(src, filter, CV_8UC1, Kernel);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";
		blind = filter;
	}
	private: System::Void cnfrmTraditional_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		trackBar1->Value = 3;
	}

    		   //Pyramidal Filter
	private: System::Void pyramidalFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
			static_cast<System::Int32>(static_cast<System::Byte>(226)));;
		this->button13->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
			static_cast<System::Int32>(static_cast<System::Byte>(226)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->label16->Visible = true;
			this->trackBar2->Visible = true;
			this->button16->Visible = true;
		}
	}
	private: System::Void pyramidal_Scroll(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();

		trackBar2->Maximum = 15;
		trackBar2->Minimum = 3;

		Mat  filter;
		int count = 0;

		Mat Kernel = (Mat_<float>(trackBar2->Value, trackBar2->Value));
		// 1, 2, 3, 2, 1, 2, 4, 6, 4, 2, 3, 6, 9, 6, 3, 2, 4, 6, 4, 2, 1, 2, 3, 2, 1
		for (int i = 0; i < trackBar2->Value; i++) {
			for (int j = 0; j < trackBar2->Value; j++) {
				if ((i <= (trackBar2->Value - 1) / 2) && ((j <= (trackBar2->Value - 1) / 2))) {
					if (i == 0 || j == 0) {
						Kernel.at<float>(i, j) = i + j + 1;
						count += Kernel.at<float>(i, j);
					}
					else {
						Kernel.at<float>(i, j) = Kernel.at<float>(i, 0) + Kernel.at<float>(i, j - 1);
						count += Kernel.at<float>(i, j);
					}
				}
				else if (i <= (trackBar2->Value - 1) / 2) {
					Kernel.at<float>(i, j) = Kernel.at<float>(i, j - 1) - Kernel.at<float>(i, 0);
					count += Kernel.at<float>(i, j);
				}
				else {
					Kernel.at<float>(i, j) = Kernel.at<float>(i - 1, j) - Kernel.at<float>(0, j);
					count += Kernel.at<float>(i, j);
				}
				//cout << Kernel.at<float>(i, j) << "\t";
			}
			//cout << "\n";
		}
		Kernel /= count;
		filter2D(src, filter, CV_8UC1, Kernel);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";

		blind = filter;
	}
	private: System::Void cnfrmpyramidal_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		trackBar2->Value = 3;
	}

    		   //Circular Filter
	private: System::Void CircularFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
			static_cast<System::Int32>(static_cast<System::Byte>(35)));;
		this->button12->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
			static_cast<System::Int32>(static_cast<System::Byte>(35)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->label16->Visible = true;
			this->circularS->Visible = true;
			this->cnfrmCircular->Visible = true;
		}
	}
	private: System::Void circularS_Scroll(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();

		circularS->Maximum = 15;
		circularS->Minimum = 3;

		Mat filter;

		int count = 0;

		Mat Kernel = (Mat_<float>(circularS->Value, circularS->Value));
		for (int i = 0; i < circularS->Value; i++) {
			for (int j = 0; j < circularS->Value; j++) {
				if (((i == 0) && (j == 0)) || ((i == 0) && (j == circularS->Value - 1)) || ((i == circularS->Value - 1) && (j == 0)) || ((i == circularS->Value - 1) && (j == circularS->Value - 1))) {
					Kernel.at<float>(i, j) = 0;
					count += Kernel.at<float>(i, j);
				}
				else {
					Kernel.at<float>(i, j) = 1;
					count += Kernel.at<float>(i, j);
				}
				//cout << Kernel.at<float>(i, j) << "\t";
			}
			//cout << "\n";
		}
		Kernel /= count;
		filter2D(src, filter, CV_8UC1, Kernel);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";
		blind = filter;
	}
	private: System::Void cnfrmCircular_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		circularS->Value = 3;
	}

    		   //Cone Filter
	private: System::Void coneFilteR_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
			static_cast<System::Int32>(static_cast<System::Byte>(80)));;
		this->button11->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
			static_cast<System::Int32>(static_cast<System::Byte>(80)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->coneFilter->Visible = true;
			this->cnfrmCone->Visible = true;
		}
	}
	private: System::Void coneFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();

		Mat filter;
		Mat Kernel = (Mat_<float>(5, 5) << 0, 0, 1, 0, 0, 0, 2, 2, 2, 0, 1, 2, 5, 2, 1, 0, 2, 2, 2, 0, 0, 0, 1, 0, 0);
		Kernel /= 25;
		filter2D(src, filter, CV_8UC1, Kernel);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";
		blind = filter;
	}
	private: System::Void cnfrmCone_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
	}

    		   //Median Filter
	private: System::Void MedianFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->MedianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
			static_cast<System::Int32>(static_cast<System::Byte>(166)));;
		this->MedianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->MedianFilter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
			static_cast<System::Int32>(static_cast<System::Byte>(166)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->label16->Visible = true;
			this->MedianScroll->Visible = true;
			this->cnfrmMedian->Visible = true;
		}
	}
	private: System::Void MedianScroll_Scroll(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();

		if (MedianScroll->Value % 2 != 0) {
			MedianScroll->Maximum = 15;
			MedianScroll->Minimum = 3;
			Mat filter;
			medianBlur(src, filter, MedianScroll->Value);
			imwrite("filter.jpg", filter);
			pictureBox1->ImageLocation = "filter.jpg";
			blind = filter;
		}
	}
	private: System::Void cnfrmMedian_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind;
		MedianScroll->Value = 3;
	}

    		   //Gaussian Filter
	private: System::Void gaussianFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->gaussianFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
			static_cast<System::Int32>(static_cast<System::Byte>(56)));;
		this->gaussianFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->gaussianFilter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
			static_cast<System::Int32>(static_cast<System::Byte>(56)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->label16->Visible = true;
			this->gaussianFilterS->Visible = true;
			this->cnfrmGaussSave->Visible = true;
		}
	}
	private: System::Void gaussianFilterS_Scroll(System::Object^ sender, System::EventArgs^ e) {
		gaussianFilterS->Maximum = 15;
		gaussianFilterS->Minimum = 3;
		blind = src.clone();
		if (gaussianFilterS->Value % 2 != 0)
		{
			GaussianBlur(blind, blind, cv::Size(gaussianFilterS->Value, gaussianFilterS->Value), 0);
			imwrite("filter.jpg", blind);
			pictureBox1->ImageLocation = "filter.jpg";
		}
	}
	private: System::Void cnfrmGaussSave_Click(System::Object^ sender, System::EventArgs^ e) {
		gaussianFilterS->Value = 3;
		src = blind;
	}

    		   //Sobel Filter
	private: System::Void SobelFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->SobelFilter->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
			static_cast<System::Int32>(static_cast<System::Byte>(120)));;
		this->SobelFilter->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->SobelFilter->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
			static_cast<System::Int32>(static_cast<System::Byte>(120)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->applyingSobel->Visible = true;
		}

	}
	private: System::Void applyingSobel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->cnfrmSobel->Visible = true;
		this->Hlabel->Visible = true;
		this->Vlabel->Visible = true;
		this->Dlabel->Visible = true;
		this->Dbox->Visible = true;
		this->Vbox->Visible = true;
		this->Hbox->Visible = true;


		Mat  filter_h, filter_d, filter_v, filter;

		Mat kernel_h = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
		filter2D(src, filter_h, CV_8UC1, kernel_h);

		imwrite("filter_h.jpg", filter_h);
		Hbox->ImageLocation = "filter_h.jpg";

		Mat kernel_v = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
		filter2D(src, filter_v, CV_8UC1, kernel_v);



		imwrite("filter_v.jpg", filter_v);
		Vbox->ImageLocation = "filter_v.jpg";

		Mat kernel_d = (Mat_<int>(3, 3) << 2, 1, 0, 1, 0, -1, 0, -1, -2);
		filter2D(src, filter_d, CV_8UC1, kernel_d);

		imwrite("filter_d.jpg", filter_d);
		Dbox->ImageLocation = "filter_d.jpg";

		addWeighted(filter_v, 1, filter_h, 1, 0, filter);
		addWeighted(filter, 1, filter_d, 1, 0, filter);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		blind = filter.clone();
	}
	private: System::Void cnfrmSobel_Click(System::Object^ sender, System::EventArgs^ e) {
		src.copyTo(blind);
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
	}

    		   //Laplacian Filter
	private: System::Void laplac_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;
		this->button6->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->fLabel->Visible = true;
			this->laplacianFilters->Visible = true;
			this->selectLabel->Visible = true;
			this->SelectedLabel->Visible = true;
			this->applyingLaplacian->Visible = true;
			this->cnfrmLaplacian->Visible = true;

		}

	}
	private: System::Void laplacianFilters_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		SelectedLabel->Text = laplacianFilters->Text;
	}
	private: System::Void applyingLaplacian_Click(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		if (laplacianFilters->Text == "Type 4 filter")
		{
			Mat kernal_L = (Mat_<float>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
			filter2D(blind, blind, CV_8UC1, kernal_L);
		}
		else if (laplacianFilters->Text == "Type 8 filter")
		{
			Mat kernal_L = (Mat_<float>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
			filter2D(blind, blind, CV_8UC1, kernal_L);
		}
		else if (laplacianFilters->Text == "Type -4 filter")
		{
			Mat kernal_L = (Mat_<float>(3, 3) << 0, 1, 0, 1, -4, 1, 0, 1, 0);
			filter2D(blind, blind, CV_8UC1, kernal_L);
		}
		else if (laplacianFilters->Text == "Type -8 filter")
		{
			Mat kernal_L = (Mat_<float>(3, 3) << 1, 1, 1, 1, -8, 1, 1, 1, 1);
			filter2D(blind, blind, CV_8UC1, kernal_L);
		}
		else
		{
			MessageBox::Show("Please Select a filter");
		}
		imwrite("filter.jpg", blind);
		pictureBox1->ImageLocation = "filter.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
	}
	private: System::Void cnfrmLaplacian_Click(System::Object^ sender, System::EventArgs^ e) {
		src.copyTo(blind);
		imwrite("x.jpg", src);
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
	}

    		   //Laplacian in Edge Detection
	private: System::Void LaplacianDetection_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->LaplacianDetection->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;
		this->LaplacianDetection->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->LaplacianDetection->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->laplaceLabel->Visible = true;
			this->laplacianScroll->Visible = true;
			this->saveEdges->Visible = true;
		}
	}
	private: System::Void laplacianScroll_Scroll(System::Object^ sender, System::EventArgs^ e) {
		blind = src.clone();
		laplacianScroll->Minimum = 1;
		laplacianScroll->Maximum = 30;

		if (laplacianScroll->Value % 2 != 0)
		{
			Laplacian(blind, blind, CV_8UC1, laplacianScroll->Value);

			imwrite("filter.jpg", blind);
			pictureBox1->ImageLocation = "filter.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
		}
	}
	private: System::Void saveEdges_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
		laplacianScroll->Value = 1;
	}

    		   //Thresholding using thresh fn
	private: System::Void ThreshEdge_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button15->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
			static_cast<System::Int32>(static_cast<System::Byte>(97)));;
		this->button15->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(218)), static_cast<System::Int32>(static_cast<System::Byte>(219)),
			static_cast<System::Int32>(static_cast<System::Byte>(97)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->ThreshhHold->Visible = true;
			this->threshS->Visible = true;
			this->cnfrmThresholding->Visible = true;
		}
	}
	private: System::Void threshS_Scroll(System::Object^ sender, System::EventArgs^ e) {
		threshS->Minimum = 1;
		threshS->Maximum = 255;
		blind = src.clone();
		threshold(src, blind, threshS->Value, 255, THRESH_BINARY);
		imwrite("plane.jpg", blind);
		pictureBox1->ImageLocation = "plane.jpg";
	}
	private: System::Void cnfrmThresholding_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
	}

    		   //Sobel Edge Detection
	private: System::Void SobelEdges_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->SobelEdges->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
			static_cast<System::Int32>(static_cast<System::Byte>(120)));;
		this->SobelEdges->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->SobelEdges->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(89)),
			static_cast<System::Int32>(static_cast<System::Byte>(120)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->Sobel->Visible = true;
		}
	}
	private: System::Void Sobel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->SaveSobel->Visible = true;
		this->labelH->Visible = true;
		this->labelV->Visible = true;
		this->labelD->Visible = true;
		this->BoxD->Visible = true;
		this->BoxV->Visible = true;
		this->BoxH->Visible = true;


		Mat  filter_h, filter_d, filter_v, filter;

		Mat kernel_h = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
		filter2D(src, filter_h, CV_8UC1, kernel_h);

		imwrite("filter_h.jpg", filter_h);
		BoxH->ImageLocation = "filter_h.jpg";

		Mat kernel_v = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
		filter2D(src, filter_v, CV_8UC1, kernel_v);



		imwrite("filter_v.jpg", filter_v);
		BoxV->ImageLocation = "filter_v.jpg";

		Mat kernel_d = (Mat_<int>(3, 3) << 2, 1, 0, 1, 0, -1, 0, -1, -2);
		filter2D(src, filter_d, CV_8UC1, kernel_d);

		imwrite("filter_d.jpg", filter_d);
		BoxD->ImageLocation = "filter_d.jpg";

		addWeighted(filter_v, 1, filter_h, 1, 0, filter);
		addWeighted(filter, 1, filter_d, 1, 0, filter);

		imwrite("filter.jpg", filter);
		pictureBox1->ImageLocation = "filter.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
		blind = filter.clone();
	}
	private: System::Void SaveSobel_Click(System::Object^ sender, System::EventArgs^ e) {
		src = blind.clone();
	}

    		   //DFT Low Pass Filter
	private: System::Void Fourier_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Fourier->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;
		this->Fourier->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Fourier->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->FourierFilter->Visible = true;
			this->LPF->Visible = true;
			this->lowPass->Visible = true;
		}
	}
	private: System::Void FourierFilter_Scroll(System::Object^ sender, System::EventArgs^ e) {
		FourierFilter->Minimum = 1;
		FourierFilter->Maximum = 200;


		//expanding image to optimal size
		int m = getOptimalDFTSize(src.rows);
		int n = getOptimalDFTSize(src.cols);
		Mat padded;
		copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 0, Scalar(0));

		//converting image into floating and normalizing it in range of 0:1
		padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);

		//making places for both complex and real values
		Mat planes[2] = { padded,Mat::zeros(padded.size(),CV_32FC1) };
		Mat complexI;
		merge(planes, 2, complexI);

		//applying dft
		dft(complexI, complexI);

		//split(complexI, planes);

		//rearranging frequencies
		int cx = complexI.cols / 2;
		int cy = complexI.rows / 2;
		Mat p1(complexI, cv::Rect(0, 0, cx, cy));
		Mat p2(complexI, cv::Rect(cx, 0, cx, cy));
		Mat p3(complexI, cv::Rect(0, cy, cx, cy));
		Mat p4(complexI, cv::Rect(cx, cy, cx, cy));
		Mat temp;
		p1.copyTo(temp);
		p4.copyTo(p1);
		temp.copyTo(p4);
		p2.copyTo(temp);
		p3.copyTo(p2);
		temp.copyTo(p3);
		//split(complexI, planes);

		//filter function
		Mat Lfilter(complexI.size(), CV_32FC1);
		d0 = FourierFilter->Value;
		for (int i = 0; i < Lfilter.rows; i++)
			for (int j = 0; j < Lfilter.cols; j++)
			{

				double z1 = i - Lfilter.rows / 2;
				double z2 = j - Lfilter.cols / 2;
				if (sqrt(pow(z1, 2) + pow(z2, 2)) < d0)
					Lfilter.at<float>(i, j) = 1;
				else
					Lfilter.at<float>(i, j) = 0;
			}

		//applying filter function
		split(complexI, planes);
		Mat outR, outI;
		multiply(planes[0], Lfilter, outR);
		multiply(planes[1], Lfilter, outI);
		Mat out_planes[2] = { outR,outI };
		Mat out_complexI;
		merge(out_planes, 2, out_complexI);

		//applying idft
		idft(out_complexI, out_complexI);

		//calculating mag. and normalize image in range of 0:1
		split(out_complexI, planes);
		Mat out;
		magnitude(planes[0], planes[1], out);
		normalize(out, out, 1, 255, NORM_MINMAX);

		/*namedWindow(" ",0);
		imshow(" ",out);
		waitKey(0);*/

		blind = out;
		imwrite("filter.jpg", blind);
		pictureBox1->ImageLocation = "filter.jpg";
	}
	private: System::Void lowPass_Click(System::Object^ sender, System::EventArgs^ e) {
		FourierFilter->Value = 1;
		src = blind.clone();
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
	}

    		   //DFT High Pass Filter
	private: System::Void Fourier2_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Fourier2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;
		this->Fourier2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Fourier2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(10)),
			static_cast<System::Int32>(static_cast<System::Byte>(48)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			hideUnwanted();
			this->saveFFS->Visible = true;
			this->ffs->Visible = true;
			this->LPF->Visible = true;
		}
	}
	private: System::Void ffs_Scroll(System::Object^ sender, System::EventArgs^ e) {
		ffs->Minimum = 1;
		ffs->Maximum = 200;


		//expanding image to optimal size
		int m = getOptimalDFTSize(src.rows);
		int n = getOptimalDFTSize(src.cols);
		Mat padded;
		copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, 0, Scalar(0));

		//converting image into floating and normalizing it in range of 0:1
		padded.convertTo(padded, CV_32FC1, 1.0 / 255.0);

		//making places for both complex and real values
		Mat planes[2] = { padded,Mat::zeros(padded.size(),CV_32FC1) };
		Mat complexI;
		merge(planes, 2, complexI);

		//applying dft
		dft(complexI, complexI);

		//split(complexI, planes);

		//rearranging frequencies
		int cx = complexI.cols / 2;
		int cy = complexI.rows / 2;
		Mat p1(complexI, cv::Rect(0, 0, cx, cy));
		Mat p2(complexI, cv::Rect(cx, 0, cx, cy));
		Mat p3(complexI, cv::Rect(0, cy, cx, cy));
		Mat p4(complexI, cv::Rect(cx, cy, cx, cy));
		Mat temp;
		p1.copyTo(temp);
		p4.copyTo(p1);
		temp.copyTo(p4);
		p2.copyTo(temp);
		p3.copyTo(p2);
		temp.copyTo(p3);
		//split(complexI, planes);

		//filter function
		Mat Lfilter(complexI.size(), CV_32FC1);
		d0 = ffs->Value;
		for (int i = 0; i < Lfilter.rows; i++)
			for (int j = 0; j < Lfilter.cols; j++)
			{

				double z1 = i - Lfilter.rows / 2;
				double z2 = j - Lfilter.cols / 2;
				if (sqrt(pow(z1, 2) + pow(z2, 2)) > d0)
					Lfilter.at<float>(i, j) = 1;
				else
					Lfilter.at<float>(i, j) = 0;
			}

		//applying filter function
		split(complexI, planes);
		Mat outR, outI;
		multiply(planes[0], Lfilter, outR);
		multiply(planes[1], Lfilter, outI);
		Mat out_planes[2] = { outR,outI };
		Mat out_complexI;
		merge(out_planes, 2, out_complexI);

		//applying idft
		idft(out_complexI, out_complexI);

		//calculating mag. and normalize image in range of 0:1
		split(out_complexI, planes);
		Mat out;
		magnitude(planes[0], planes[1], out);
		normalize(out, out, 1, 255, NORM_MINMAX);

		/*namedWindow(" ",0);
		imshow(" ",out);
		waitKey(0);*/

		blind = out;
		imwrite("filter.jpg", blind);
		pictureBox1->ImageLocation = "filter.jpg";
	}
	private: System::Void saveFFS_Click(System::Object^ sender, System::EventArgs^ e) {
		ffs->Value = 1;
		src = blind.clone();
		pictureBox1->ImageLocation = "x.jpg";
		ofd->FileName = pictureBox1->ImageLocation;
	}

    		   //Detecting Shapes
	private: System::Void ShapeDetection_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->button18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;
		this->button18->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->button18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			blind = src.clone();
			hideUnwanted();
			this->Recog->Visible = true;
			cvtColor(blind, imgGray, COLOR_BGR2GRAY);
			GaussianBlur(imgGray, imgBlur, cv::Size(3, 3), 3, 0);
			Canny(imgBlur, imgCanny, 25, 75);
			Mat kernel = getStructuringElement(MORPH_RECT, cv::Size(3, 3));
			dilate(imgCanny, imgDil, kernel);

			getContours(imgDil, blind);

			imwrite("x.jpg", blind);
			Recog->ImageLocation = "x.jpg";
		}
	}

    		   //Adding Salt & Pepper Noise
	private: System::Void saltAndPepper_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->saltAndPepper->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;
		this->saltAndPepper->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->saltAndPepper->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{
			Add_salt_pepper_Noise(src, 0.2, 0.2);

			imwrite("noise.jpg", src);
			pictureBox1->ImageLocation = "noise.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
		}
	}

    		   //Adding Gaussian Noise
	private: System::Void GaussianNoise_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->GaussianNoise->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;
		this->GaussianNoise->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->GaussianNoise->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
			static_cast<System::Int32>(static_cast<System::Byte>(198)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() != 1)
		{
			MessageBox::Show("Please Convert image to the gray scale first ^_^");
		}
		else
		{

			/*Mat noise(img.size(), img.type());
			float m = (10, 12, 34);
			float sigma = (1, 5, 50);
			randn(noise, m, sigma);
			img += noise;*/
			Add_gaussian_Noise(src, 15, 15);

			imwrite("noise.jpg", src);
			pictureBox1->ImageLocation = "noise.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
		}
	}

    		   //Under Image Reset & Save & ARGB2Gray
	private: System::Void Reset3_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Reset3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;
		this->Reset3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Reset3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(154)),
			static_cast<System::Int32>(static_cast<System::Byte>(174)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else
		{
			hideUnwanted();
			src = imread(x);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			hideSave();
		}
		int n = 0;
		textBox1->Text = System::Convert::ToString(n);
		textBox2->Text = System::Convert::ToString(n);
		textBox3->Text = System::Convert::ToString(n);
		textBox4->Text = System::Convert::ToString(n);
		textBox5->Text = System::Convert::ToString(n);
		textBox6->Text = System::Convert::ToString(n);
		textBox7->Text = System::Convert::ToString(n);
		textBox8->Text = System::Convert::ToString(n);
	}

    	private: System::Void Save3_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->Save3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;
		this->Save3->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->Save3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
			static_cast<System::Int32>(static_cast<System::Byte>(165)));;

		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else {
			hideUnwanted();
			Savee();
		}
	}

    	private: System::Void RGB2Gray2_Click(System::Object^ sender, System::EventArgs^ e) {
		//coloring
		hideButtonColor();
		this->RGB2Gray2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
			static_cast<System::Int32>(static_cast<System::Byte>(117)));;
		this->RGB2Gray2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->RGB2Gray2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;
		this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
			static_cast<System::Int32>(static_cast<System::Byte>(117)));;

		hideUnwanted();
		if (src.empty())
		{
			MessageBox::Show("Please enter an image");
		}
		else if (src.channels() == 1)
		{
			MessageBox::Show("Picture is already Gray");
		}
		else
		{
			cvtColor(src, src, COLOR_BGR2GRAY);
			imwrite("x.jpg", src);
			pictureBox1->ImageLocation = "x.jpg";
			ofd->FileName = pictureBox1->ImageLocation;
			showSave();
		}
	}

    		   //Advanced Edits Guide
	private: System::Void pointProcessingGuide_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("1) Histogram is a graph, which shows intensity distribution of an image.\n 2)adjust Contrast(Histogram Equalization):It is a method which applied to a dark or \n washed out images in order to improve image contrast by spreading out the frequencies of the image.\n 3)Linear transformation(image negative):Used for enhancing white or grey detail embedded in dark regions of an image.\n 4)Blinding two images together \n 5)Adjust Brightness(Power Transformation):Used to map a narrow range of \n dark input values into a wider range of output values or vice versa depending on y value \n 6)Brighten Dark Images(LogTransformation):Used to map a narrow range of dark input values into a wider range of output values \n 7)image Slicing Level(BitPlaneSlicing):The main goals of bit plane slicing is: \n Converting a gray level image to a binary image. \n Image Compression (Representing an image with fewer bits) \n 8)Choose a certain detail(Thresholding):allows only a certain values to be displayed \n 9)Highlight Gray Range(Gray Level Slicing):It�s a way to highlight gray range of interest to a viewer");
	}

		   //Filters Guide
	private: System::Void FiltersGuide_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("1)traditional Fliter (Box Filter): low-pass filter that smooths the image by making each output pixel the average of the surrounding ones, removing details, noise and andedges from images \n 3)circular Filter(Remove high noise):removes high noises \n 5)Median Filter (extremely dark or bright values):removes salt and pepper noise \n 6)reducing high noises and blurring (gaussian filter):reducing noise (high frequency components) and blurring regions of an image. \n 7)Thick Sharpening (sobel filter): sharpen all edges's directions \n 8)Thin Sharpening (laplacian filter): sharpen edges with one symettrical direction  ");
	}

		   //Locate Objects & Boundaries Guide
	private: System::Void segmentationGuide_Click(System::Object^ sender, System::EventArgs^ e) {

		MessageBox::Show("1)Getting Thin edges : Laplacian Detector \n 2)detecting certain edges : threshold detector  \n 3)Detecting all Edges's Directions : sobel detector \n  4)Detecting the Main Object \n 5)Denying the Main Object   ");
	}

    		   //themes settings
	private: System::Void darkTheme_Click(System::Object^ sender, System::EventArgs^ e) {
		this->index->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->imageOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->PointProcessing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->NeighborhoodOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->ImageSegmentation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));;

	}
	private: System::Void greyTheme_Click(System::Object^ sender, System::EventArgs^ e) {
		this->index->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->imageOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->PointProcessing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->NeighborhoodOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->ImageSegmentation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;

		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));;
	}
	private: System::Void lightTheme_Click(System::Object^ sender, System::EventArgs^ e) {
		this->index->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->imageOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->PointProcessing->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->NeighborhoodOperations->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->ImageSegmentation->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;

		this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));;
	}
    
    }
}