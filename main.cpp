// SignalAnalysis.cpp : �w�q�D���x���ε{�����i�J�I�C
//


#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include "gnuplot_i.h"
#include <string>
  

cv::Mat LoadData(char* filename);
void tracemat(cv::Mat target);
cv::Mat GaussianSmooth(cv::Mat original_data, char* filename);
cv::Mat PCA(cv::Mat AfterGSData, char* filename);
cv::Mat FeatureExtraction(cv::Mat countFeaturedata);
void PrintMatrix(cv::Mat *Matrix, int Rows, int Cols);
double volume(double a, double b, double c, double d, double e, double f);
int Sign(float x);
double DTW_Distance(cv::Mat mat_tmp, cv::Mat mat_src);
void PlotFigure(cv::Mat src, const std::string figurename);
void PlotInSameFigure(cv::Mat original, cv::Mat result, const std::string figurename, const std::string figurefilename);
float CalculateAllTmp(cv::Mat mat_tmplate, cv::Mat mat_src);
cv::Mat GetIntervalSignal(cv::Mat mat_src, int StartIndex, int EndIndex);
cv::Mat FindPeriod(cv::Mat src);
cv::Mat loadAlltemplate(char* filename);
cv::Mat calc_angle(cv::Mat mat_Eigenvec, cv::Mat mat_EigenvecTmp);

cv::Mat mat_Normailization;
int tmpNum;
/*20140423*/
cv::Mat User_PCA(cv::Mat UserGSData, char* filename);
float x = 0, y = 0, z = 0;
cv::Mat mat_UserMean;
cv::Mat mat_UserEigenvectors;


char filename[300] = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\";
char* tmp_1_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\�ӭK��_Ver.4.csv";
char* tmp_2_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\�Ԥ�y_Ver.4.csv";
char* tmp_3_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\�I����_Ver.4.csv";
char* tmp_4_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\���\_Ver.4.csv";
char* tmp_5_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\����_Ver.4.csv";
//char* tmp_6_filename = "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\��L_new3.csv";

int main(int _argc, char *argv[])
{
	
	//char buffer[50];// = argv[1];
	//strcpy(buffer, argv[1]);
	//strcat(filename, buffer);
	//printf("%s\n\n", argv[1]);

	/*Select template*/
	//char* tmp_filename = NULL;
	//switch (*argv[2])
	//{
	//case '1':
	//	tmp_filename = tmp_1_filename;
	//	tmpNum = 1;
	//	break;
	//case '2':
	//	tmp_filename = tmp_2_filename;
	//	tmpNum = 2;
	//	break;	
	//case '3':
	//	tmp_filename = tmp_3_filename;
	//	tmpNum = 3;
	//	break;	
	//case '4':
	//	tmp_filename = tmp_4_filename;
	//	tmpNum = 4;
	//	break;
	//case '5':
	//	tmp_filename = tmp_5_filename;
	//	tmpNum = 5;
	//	break;
	//case '6':
	//	tmp_filename = tmp_6_filename;
	//	tmpNum = 6;
	//	break;
	//default:
	//	break;
	//}

	/*template*/
	//cv::Mat mat_templatedata;
	//cv::Mat mat_GSTmpData;
	//cv::Mat mat_PCATmpData;

	//mat_templatedata = LoadData(tmp_filename);
	//mat_GSTmpData = GaussianSmooth(mat_templatedata, "TmpSmooth.csv");
	//mat_PCATmpData = PCA(mat_GSTmpData, "TmpPCA.csv");
	
	for (int m = 101; m < 102; m++){
		for (int n = 1; n < 2; n++){
			if (m == 83)
				continue;
			sprintf(filename, "C:\\Users\\ChiaHao\\Documents\\Visual Studio 2013\\Projects\\SignalAnalysis\\SignalAnalysis\\%d (%d).csv", m, n);
			
			float result_1, result_2, result_3, result_4, result_5;
			float result_correct_1, result_correct_2, result_correct_3, result_correct_4, result_correct_5;
			cv::Mat tmpData_1 = loadAlltemplate(tmp_1_filename);
			cv::Mat tmpData_2 = loadAlltemplate(tmp_2_filename);
			cv::Mat tmpData_3 = loadAlltemplate(tmp_3_filename);
			cv::Mat tmpData_4 = loadAlltemplate(tmp_4_filename);
			cv::Mat tmpData_5 = loadAlltemplate(tmp_5_filename);
			cv::Mat mat_EigenvecTmp_1 = User_PCA(tmpData_1, "tmp");
			cv::Mat mat_EigenvecTmp_2 = User_PCA(tmpData_2, "tmp");
			cv::Mat mat_EigenvecTmp_3 = User_PCA(tmpData_3, "tmp");
			cv::Mat mat_EigenvecTmp_4 = User_PCA(tmpData_4, "tmp");
			cv::Mat mat_EigenvecTmp_5 = User_PCA(tmpData_5, "tmp");

			/*User data*/
			cv::Mat mat_data;
			cv::Mat mat_GSData;
			cv::Mat mat_PCAData;

			mat_data = LoadData(filename);
			mat_GSData = GaussianSmooth(mat_data, "Smooth.csv");
			mat_PCAData = PCA(mat_GSData, "PCA.csv");
			cv::Mat mat_Eigenvec = User_PCA(mat_PCAData, "user");

			result_1 = CalculateAllTmp(tmpData_1, mat_PCAData);
			result_2 = CalculateAllTmp(tmpData_2, mat_PCAData);
			result_3 = CalculateAllTmp(tmpData_3, mat_PCAData);
			result_4 = CalculateAllTmp(tmpData_4, mat_PCAData);
			result_5 = CalculateAllTmp(tmpData_5, mat_PCAData);

			printf("result_1 = %f\n", result_1 * 10000);
			printf("result_2 = %f\n", result_2 * 10000);
			printf("result_3 = %f\n", result_3 * 10000);
			printf("result_4 = %f\n", result_4 * 10000);
			printf("result_5 = %f\n", result_5 * 10000);


			//PlotInSameFigure(mat_PCAData, tmpData_1, "tmpData_1", "original_1");
			//PlotInSameFigure(mat_PCAData, tmpData_2, "tmpData_2", "original_2");
			//PlotInSameFigure(mat_PCAData, tmpData_3, "tmpData_3", "original_3");
			//PlotInSameFigure(mat_PCAData, tmpData_4, "tmpData_4", "original_4");
			//PlotInSameFigure(mat_PCAData, tmpData_5, "tmpData_5", "original_5");

			//char *delim = ".";
			//char * pch;
			//pch = strtok(buffer, delim);

			cv::Mat mat_Rotate_1 = cv::Mat::zeros(3, 3, CV_64F);
			cv::Mat mat_Rotate_2 = cv::Mat::zeros(3, 3, CV_64F);
			cv::Mat mat_Rotate_3 = cv::Mat::zeros(3, 3, CV_64F);
			cv::Mat mat_Rotate_4 = cv::Mat::zeros(3, 3, CV_64F);
			cv::Mat mat_Rotate_5 = cv::Mat::zeros(3, 3, CV_64F);
			for (int i = 0; i < mat_Rotate_1.rows; i++){
				for (int j = 0; j < mat_Rotate_1.cols; j++){
					printf("%f ", mat_Rotate_1.at<double>(i, j));
				}
			}

			mat_Rotate_1 = calc_angle(mat_Eigenvec, mat_EigenvecTmp_1);
			//for (int i = 0; i < mat_Rotate_1.rows; i++){
			//	for (int j = 0; j < mat_Rotate_1.cols; j++){
			//		printf("%f ", mat_Rotate_1.at<double>(i, j));
			//	}
			//}
			mat_Rotate_2 = calc_angle(mat_Eigenvec, mat_EigenvecTmp_2);
			mat_Rotate_3 = calc_angle(mat_Eigenvec, mat_EigenvecTmp_3);
			mat_Rotate_4 = calc_angle(mat_Eigenvec, mat_EigenvecTmp_4);
			mat_Rotate_5 = calc_angle(mat_Eigenvec, mat_EigenvecTmp_5);


			cv::Mat mat_PCARotate_1;//= mat_PCAData.clone();
			cv::Mat mat_PCARotate_2;//= mat_PCAData.clone();
			cv::Mat mat_PCARotate_3;//= mat_PCAData.clone();
			cv::Mat mat_PCARotate_4;//= mat_PCAData.clone();
			cv::Mat mat_PCARotate_5;//= mat_PCAData.clone();


			mat_PCARotate_1 = mat_PCAData * mat_Rotate_1;
			mat_PCARotate_2 = mat_PCAData * mat_Rotate_2;
			mat_PCARotate_3 = mat_PCAData * mat_Rotate_3;
			mat_PCARotate_4 = mat_PCAData * mat_Rotate_4;
			mat_PCARotate_5 = mat_PCAData * mat_Rotate_5;


			result_correct_1 = CalculateAllTmp(tmpData_1, mat_PCARotate_1);
			result_correct_2 = CalculateAllTmp(tmpData_2, mat_PCARotate_2);
			result_correct_3 = CalculateAllTmp(tmpData_3, mat_PCARotate_3);
			result_correct_4 = CalculateAllTmp(tmpData_4, mat_PCARotate_4);
			result_correct_5 = CalculateAllTmp(tmpData_5, mat_PCARotate_5);
			/*PlotInSameFigure(mat_PCARotate_1, tmpData_1, "Result", "Result");*/

			printf("result_correct_1 = %f %%\n", result_correct_1 * 10000);
			printf("result_correct_2 = %f %%\n", result_correct_2 * 10000);
			printf("result_correct_3 = %f %%\n", result_correct_3 * 10000);
			printf("result_correct_4 = %f %%\n", result_correct_4 * 10000);
			printf("result_correct_5 = %f %%\n", result_correct_5 * 10000);

			//PlotInSameFigure(mat_PCARotate_1, tmpData_1, "tmpData_1", "original_R1");
			//PlotInSameFigure(mat_PCARotate_2, tmpData_2, "tmpData_2", "original_R2");
			//PlotInSameFigure(mat_PCARotate_3, tmpData_3, "tmpData_3", "original_R3");
			//PlotInSameFigure(mat_PCARotate_4, tmpData_4, "tmpData_4", "original_R4");
			//PlotInSameFigure(mat_PCARotate_5, tmpData_5, "tmpData_5", "original_R5");


			FILE * fp;
			fp = fopen("�פ����ƾ�_Ver.4-3.csv", "a+");
			fprintf(fp, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%d,%d\n", result_1, result_2, result_3, result_4, result_5, result_correct_1, result_correct_2, result_correct_3, result_correct_4, result_correct_5, m,n);
			fclose(fp);


			printf("\n%s\n", filename);
			//system("pause");
		}
	}
	return 0;
	//return result_1 * 10000;
} 

cv::Mat calc_angle(cv::Mat mat_Eigenvec, cv::Mat mat_EigenvecTmp)
{
	double angle, tmp, angle_degree;
	tmp = (mat_Eigenvec.at<double>(0, 0)*mat_EigenvecTmp.at<double>(0, 0) + mat_Eigenvec.at<double>(0, 1)*mat_EigenvecTmp.at<double>(0, 1) + mat_Eigenvec.at<double>(0, 2)*mat_EigenvecTmp.at<double>(0, 2)) / (sqrt(pow(mat_Eigenvec.at<double>(0, 0), 2) + pow(mat_Eigenvec.at<double>(0, 1), 2) + pow(mat_Eigenvec.at<double>(0, 2), 2))*sqrt(pow(mat_EigenvecTmp.at<double>(0, 0), 2) + pow(mat_EigenvecTmp.at<double>(0, 1), 2) + pow(mat_EigenvecTmp.at<double>(0, 2), 2)));

	angle = acos(tmp);
	angle_degree = (angle * 360) / 6.28;
	//printf("angle = %f\n\n", angle_degree);
	double mZ_rotate[3][3] = { { cos(angle), -sin(angle), 0 }, { sin(angle), cos(angle), 0 }, { 0, 0, 1 } };
	cv::Mat mat_ZRotate = cv::Mat(3, 3, CV_64F, mZ_rotate);
	//for (int i = 0; i < mat_ZRotate.rows; i++){
	//	for (int j = 0; j < mat_ZRotate.cols; j++){
	//		printf("%f", mat_ZRotate.at<double>(i, j));
	//	}
	//}
	/*rotate normalize*/
	return mat_ZRotate.clone();
}

cv::Mat loadAlltemplate(char *filename)
{
	cv::Mat mat_templatedata;
	cv::Mat mat_GSTmpData;
	cv::Mat mat_PCATmpData;

	mat_templatedata = LoadData(filename);
	mat_GSTmpData = GaussianSmooth(mat_templatedata, "TmpSmooth.csv");
	mat_PCATmpData = PCA(mat_GSTmpData, "TmpPCA.csv");

	return mat_PCATmpData;
}

void tracemat(cv::Mat target) 
{
	int i, j;
	double* pt_target = (double*)target.data;
	int h = target.rows;
	int w = target.cols;
	for (i = 0; i<h; i++)
	{
		printf("%d :", i);
		for (j = 0; j<w; j++)
			printf("%f,", pt_target[i*w + j]);
		printf("\n");
	}
}

cv::Mat LoadData(char* filename)
{
	int count = 0;
	cv::Mat mat_mdata;
	FILE *file;

	double a, b, c;
	int n;
	if ((file = fopen(filename, "r")) == NULL){
		printf("open fail\n");
		return mat_mdata;
	}
	
	do{
		n = fscanf(file, "%lf,%lf,%lf", &a, &b, &c);
		if (n == 3)
			count++;
	} while (n == 3);
	rewind(file);
	mat_mdata.create(count, 3, CV_64F);

	//file = fopen(filename, "r");
	for (int row = 0; row<count; row++){
		fscanf(file, "%lf,%lf,%lf\n", &a, &b, &c);
		mat_mdata.at<double>(row, 0) = a;
		mat_mdata.at<double>(row, 1) = b;
		mat_mdata.at<double>(row, 2) = c;
		//printf("%lf,%lf,%lf\n",  mat_mdata.at<double>(row, 0), mat_mdata.at<double>(row, 1), mat_mdata.at<double>(row, 2));
		
	}
	//printf("\n");
	fclose(file);
	//tracemat(mat_mdata);
	return mat_mdata;
	
}


cv::Mat GaussianSmooth(cv::Mat original_data,char* filename)
{
	cv::Mat matGS_outputData = cv::Mat::zeros(original_data.rows,original_data.cols,CV_64F);
	
	int kernelSize = 9;
	cv::Mat kernel;

	kernel = cv::getGaussianKernel(kernelSize, 0.3*((kernelSize - 1)*0.5 - 1) + 0.8, CV_64F);

	cv::filter2D(original_data, matGS_outputData, -1, kernel);
	//tracemat(matGS_outputData);
	////for prove rotation matrix X or Y or Z
	//FILE* file_dtw = fopen("Test_dtw.csv", "w");
	//float mDegree = -5;
	////please input degrees -360~360 degrees
	//float mX_rotate[3][3] = { { 1, 0, 0 }, { 0, cos(mDegree), -sin(mDegree) }, { 0, sin(mDegree), cos(mDegree) } };
	//float mY_rotate[3][3] = { { cos(mDegree), 0, sin(mDegree) }, { 0, 1, 0 }, { -sin(mDegree), 0, cos(mDegree) } };
	//float mZ_rotate[3][3] = { { cos(mDegree), -sin(mDegree), 0 }, { sin(mDegree), cos(mDegree), 0 }, { 0, 0, 1 } };
	////generate rotation matrix
	//cv::Mat mat_XRotate = cv::Mat(3, 3, CV_32F, mX_rotate);
	//cv::Mat mat_YRotate = cv::Mat(3, 3, CV_32F, mY_rotate);
	//cv::Mat mat_ZRotate = cv::Mat(3, 3, CV_32F, mZ_rotate);
	//mat_rotate = matGS_outputData.clone();
	//mat_rotate = matGS_outputData * mat_XRotate;	
	FILE* file2 = fopen(filename, "w");
	for (int i = 0; i < original_data.rows; i++){
		fprintf(file2, "%f,%f,%f\n", matGS_outputData.at<double>(i, 0), matGS_outputData.at<double>(i, 1), matGS_outputData.at<double>(i, 2));
	}
	//tracemat(matGS_outputData);
	//fclose(file1);
	fclose(file2);
	//fclose(file_dtw);

	return matGS_outputData;
}

cv::Mat PCA(cv::Mat AfterGSData, char* filename)
{
	cv::Mat mat_Shift;
	cv::Mat mat_Roatate;
	cv::Mat mat_Affine;
	mat_Shift.create(AfterGSData.rows, 3, CV_64F);
	mat_Affine.create(AfterGSData.rows, 3, CV_64F);
	mat_Normailization.create(AfterGSData.rows, 3, CV_64F);

	//translation invariance, find center , calculate shift
	//cv::Mat average;
	//average.zeros(1, 3, CV_64F);
	double x = 0, y = 0, z = 0;
	for (int i = 0; i < AfterGSData.rows; i++){
		x += AfterGSData.at<double>(i, 0);
		y += AfterGSData.at<double>(i, 1);
		z += AfterGSData.at<double>(i, 2);
	}
	x = x / AfterGSData.rows;
	y = y / AfterGSData.rows;
	z = z / AfterGSData.rows;
	//printf("%f, %f, %f\n",x,y,z);

	FILE* file_shift = fopen("circle_shift.csv", "w");
	FILE* file_rotate = fopen("circle_rotation.csv", "w");
	FILE* file_affine = fopen(filename, "w");

	for (int i = 0; i < AfterGSData.rows; i++){
		mat_Shift.at<double>(i, 0) = AfterGSData.at<double>(i, 0) - x;
		mat_Shift.at<double>(i, 1) = AfterGSData.at<double>(i, 1) - y;
		mat_Shift.at<double>(i, 2) = AfterGSData.at<double>(i, 2) - z;
		fprintf(file_shift, "%f,%f,%f \n", mat_Shift.at<double>(i, 0), mat_Shift.at<double>(i, 1), mat_Shift.at<double>(i, 2));
	}
	fclose(file_shift);

	cv::PCA pca(mat_Shift, cv::Mat(), CV_PCA_DATA_AS_ROW,3); //maxComponent

	cv::Mat mat_Mean = pca.mean.clone();
	cv::Mat mat_Eigenvalues = pca.eigenvalues.clone();
	cv::Mat mat_Eigenvectors = pca.eigenvectors.clone();

	//tracemat(mat_Eigenvectors);
	//mat_Affine = mat_Shift.clone();
	for (int i = 0; i < mat_Shift.rows; i++){
		mat_Affine.row(i) = mat_Shift.row(i) * mat_Eigenvectors;
	}
	
	/*20140423*/
	/*mat_UserMean = mat_Shift.clone();
	mat_UserEigenvectors = mat_Eigenvectors.clone();*/


	for (int i = 0; i < AfterGSData.rows; i++){
		fprintf(file_rotate, "%f,%f,%f \n", mat_Affine.at<double>(i, 0), mat_Affine.at<double>(i, 1), mat_Affine.at<double>(i, 2));
	}
	//return mat_Affine; //after rotation processing 
	fclose(file_rotate);

	
	 /*scaling invariance*/
	 /*scaling factor s = sqrt(Sx+Sy+Sz)*/
	double s, Sx = 0, Sy = 0, Sz = 0;
	for (int i = 0; i < AfterGSData.rows; i++){
		Sx += abs(mat_Affine.at<double>(i, 0));
		Sy += abs(mat_Affine.at<double>(i, 1));
		Sz += abs(mat_Affine.at<double>(i, 2));
	}
	Sx = Sx / AfterGSData.rows;
	Sy = Sy / AfterGSData.rows;
	Sz = Sz / AfterGSData.rows;
	s = sqrt(pow(Sx, 2) + pow(Sy, 2) + pow(Sz, 2) / 3);


	//reflection invariance
	cv::Mat mat_Reflection;
	mat_Reflection.create(AfterGSData.rows, 3, CV_64F);

	double Fx, Fy, Fz;
	for (int i = 0; i < AfterGSData.rows; i++){
		/*float s;
		s = Sign(mat_Affine.at<float>(i, 0));*/
		Fx = (Sign(mat_Affine.at<double>(i, 0)) * pow(mat_Affine.at<double>(i, 0), 2)) / AfterGSData.rows;
		Fy = (Sign(mat_Affine.at<double>(i, 1)) * pow(mat_Affine.at<double>(i, 1), 2)) / AfterGSData.rows;
		Fz = (Sign(mat_Affine.at<double>(i, 2)) * pow(mat_Affine.at<double>(i, 2), 2)) / AfterGSData.rows;

		mat_Reflection.at<double>(i, 0) = Sign(Fx); //  12/29  �ץ� �̫��i�hMAT�ݭn�A���@��sign
		mat_Reflection.at<double>(i, 1) = Sign(Fy);
		mat_Reflection.at<double>(i, 2) = Sign(Fz);
	}
	//tracemat(mat_Reflection);
	mat_Reflection = mat_Reflection.diag();
	//tracemat(mat_Reflection);

	cv::Mat mat_NewReflection = mat_NewReflection.zeros(3, 3, CV_64F);

	mat_NewReflection.at<double>(0, 0) = mat_Reflection.at<double>(0, 0);
	mat_NewReflection.at<double>(1, 1) = mat_Reflection.at<double>(1, 0);
	mat_NewReflection.at<double>(2, 2) = mat_Reflection.at<double>(2, 0);
	//tracemat(mat_NewReflection);

	mat_Normailization = (1.0 / s)* mat_Affine; //*mat_NewReflection;  //�����D��~~~~

	//mat_Normailization = (1.0 / s) * mat_Affine * mat_Reflection;
	//mat_Normailization = mat_Affine.clone();
	//printf("S = %f", 1.0 / s);
	//FILE* file = fopen("circle_NOR.csv", "w");

	//for (int i = 0; i < count; i++){
	//	fprintf(file, "%f \n", mat_Normailization.at<float>(i, 0), mat_Normailization.at<float>(i, 1), mat_Normailization.at<float>(i, 2));
	//}
	//fclose(file);
	//fclose(file_shift);
	//fclose(file_rotate);
	//fclose(file_affine);

	return mat_Normailization;
	
}
cv::Mat User_PCA(cv::Mat UserGSData, char* filename)
{
	cv::PCA pca(UserGSData, cv::Mat(), CV_PCA_DATA_AS_ROW, 3); //maxComponent

	cv::Mat mat_Mean = pca.mean.clone();
	cv::Mat mat_Eigenvalues = pca.eigenvalues.clone();
	cv::Mat mat_Eigenvectors = pca.eigenvectors.clone();
	//tracemat(mat_Eigenvectors.row(0));
	return mat_Eigenvectors.row(0);
}
cv::Mat FeatureExtraction(cv::Mat countFeaturedata)
{
	/*line segments --> 09J_Flexible signature descriptions for adaptive motion trajectory representation,perception and recognition*/
	/*K means cuvature approximation  ���@��otorsion  Center �X�󤤤�*/
	double a, b, c, s, delta, k;
	float H_plus, H_minus;
	double volume_plus, volume_minus;
	volume_plus = 0;
	volume_minus = 0;
	H_plus = 0;
	H_minus = 0;

	cv::Mat mat_center;
	cv::Mat mat_cuvature;
	cv::Mat mat_torsion;
	cv::Mat mat_distanceTocenter;
	cv::Mat mat_arcLength;


	mat_center.create(1, 3, CV_32F);
	mat_cuvature.create(countFeaturedata.rows, 1, CV_32F);
	mat_torsion.create(countFeaturedata.rows, 1, CV_64F);
	mat_distanceTocenter.create(countFeaturedata.rows, 1, CV_32F);
	mat_arcLength.create(countFeaturedata.rows, 1, CV_32F);

	/* Center = sum(x,y,z) / N points */
	
	float x = 0, y = 0, z = 0;
	for (int i = 0; i < countFeaturedata.rows; i++){
		x += mat_Normailization.at<float>(i, 0);
		y += mat_Normailization.at<float>(i, 1);
		z += mat_Normailization.at<float>(i, 2);
	}
	mat_center.at<float>(0, 0) = x / countFeaturedata.rows;
	mat_center.at<float>(0, 1) = y / countFeaturedata.rows;
	mat_center.at<float>(0, 2) = z / countFeaturedata.rows;
	//tracemat(mat_center);

	/* R = distance(center,point), S = distance between two successive points */
	float arc, R;
	for (int i = 0; i < countFeaturedata.rows; i++){
		R = cv::norm(mat_Normailization.row(i), mat_center.row(0), cv::NORM_L2);
		if (i != countFeaturedata.rows - 1){
			arc = cv::norm(mat_Normailization.row(i), mat_Normailization.row(i + 1), cv::NORM_L2);
		}
		mat_arcLength.at<float>(i, 0) = arc;
		mat_distanceTocenter.at<float>(i, 0) = R;
	}
	
	//tracemat(mat_arcLength);
	//tracemat(mat_distanceTocenter);

	/* cuvature && torision */
	for (int i = 1; i <= countFeaturedata.rows - 1; i++){

		a = cv::norm(mat_Normailization.row(i - 1), mat_Normailization.row(i), cv::NORM_L2);
		b = cv::norm(mat_Normailization.row(i + 1), mat_Normailization.row(i), cv::NORM_L2);
		c = cv::norm(mat_Normailization.row(i - 1), mat_Normailization.row(i + 1), cv::NORM_L2);

		s = (a + b + c) / 2;
		delta = sqrt(s * (s - a)*(s - b)*(s - c));
		k = 4 * (delta / (a * b * c));

		mat_cuvature.at<float>(i - 1, 0) = k;

		if (i >= 2){
			if (i >= countFeaturedata.rows - 2)
				break;

			double d, e, f, g, n, m ,torsion;
			d = cv::norm(mat_Normailization.row(i + 1), mat_Normailization.row(i + 2), cv::NORM_L2);
			e = cv::norm(mat_Normailization.row(i), mat_Normailization.row(i + 2), cv::NORM_L2);
			f = cv::norm(mat_Normailization.row(i - 1), mat_Normailization.row(i + 2), cv::NORM_L2);
			g = cv::norm(mat_Normailization.row(i - 1), mat_Normailization.row(i - 2), cv::NORM_L2);
			n = cv::norm(mat_Normailization.row(i), mat_Normailization.row(i - 2), cv::NORM_L2);
			m = cv::norm(mat_Normailization.row(i - 2), mat_Normailization.row(i + 1), cv::NORM_L2);

			volume_plus = volume(a, b, c, d, e, f);
			volume_minus = volume(a, b, c, g, n, m);

			H_plus = 3 * volume_plus / delta;
			H_minus = 3 * volume_minus / delta;

			torsion = 0.5 * ((6 * H_plus / d * e * f * k) + (6 * H_minus / g * n * m * k));
			mat_torsion.at<double>(i - 2, 0) = torsion;
		}		
	}
	return mat_torsion;//����

	
	//FILE* file = fopen("Circle_kuo_feature.csv", "w");
	//for (int i = 0; i < countFeaturedata.rows; i++){
	//	fprintf(file, "%f,%f,%f,%f \n", mat_cuvature.at<float>(i, 0), mat_torsion.at<double>(i, 0), mat_arcLength.at<float>(i,0),mat_distanceTocenter.at<float>(i,0));
	//	//printf("%f,%f,%f,%f \n", mat_cuvature.at<float>(i, 0), mat_torsion.at<double>(i, 0), mat_arcLength.at<float>(i, 0), mat_distanceTocenter.at<float>(i, 0));
	//}
	//fclose(file);
	//tracemat(mat_torsion);
}

double volume(double a, double b, double c, double d, double e, double f){
	//double a2 = a*a, b2 = b*b, c2 = c*c, d2 = d*d, e2 = e*e, f2 = f*f;
	///*need to be - 1 ~ 1 */
	//double tr1 = acos((c2 + b2 - f2) / (2 * b*c));
	//double tr2 = acos((a2 + c2 - e2) / (2 * a*c));
	//double tr3 = acos((a2 + b2 - d2) / (2 * a*b));
	//double tr4 = (tr1 + tr2 + tr3) / 2;
	//double temp = sqrt(sin(tr4)*sin(tr4 - tr1)*sin(tr4 - tr2)*sin(tr4 - tr3));
	//double sum = a*b*c*temp / 3;

	float formula = (4.0*a*a*b*b*c*c - a*a*(b*b + c*c - d*d)*(b*b + c*c - d*d) - b*b*(c*c + a*a - e*e)*(c*c + a*a - e*e) - c*c*(a*a + b*b - f*f)*(a*a + b*b - f*f) + (a*a + b*b - f*f)*(b*b + c*c - d*d)*(c*c + a*a - e*e));
	double sum = (double)sqrt(abs(formula)) / 12.0;
	return sum;
}


int Sign(float x)
{
	if (x < 0) return -1;
	else return 1;
}


double DTW_Distance(cv::Mat mat_tmp, cv::Mat mat_src) //mat_data, matGS_outputData
{
	
	int m = mat_tmp.rows; //template
	int n = mat_src.rows; // users 

	cv::Mat CostMatrix;

	CostMatrix = cv::Mat::zeros(m, n, CV_64F);

	CostMatrix.at<double>(0, 0) = cv::norm(mat_tmp.row(0), mat_src.row(0), cv::NORM_L2);
	//printf("(0,0) = %f", CostMatrix.at<double>(0, 0));
	
	for (int i = 1; i < m; i++){
		CostMatrix.at<double>(i, 0) = CostMatrix.at<double>(i - 1, 0) + cv::norm(mat_tmp.row(i), mat_src.row(0), cv::NORM_L2);
		//cprintf("(%d,0) = %f\n",i, CostMatrix.at<double>(i, 0));
	}

	for (int j = 1; j < n; j++){
		CostMatrix.at<double>(0, j) = CostMatrix.at<double>(0, j - 1) + cv::norm(mat_tmp.row(0), mat_src.row(j), cv::NORM_L2);
		//printf("(0,%d) = %f\n", j, CostMatrix.at<double>(0, j));
	}

	for (int i = 1; i < m; i++){
		for (int j = 1; j < n; j++){
			CostMatrix.at<double>(i, j) = cv::min(CostMatrix.at<double>(i - 1, j), cv::min(CostMatrix.at<double>(i, j - 1), CostMatrix.at<double>(i - 1, j - 1))) + cv::norm(mat_tmp.row(i), mat_src.row(j), cv::NORM_L2);
			//printf("(%d,%d) = %f\n", i,j, CostMatrix.at<double>(i, j));
		}
	}
	//tracemat(CostMatrix);
	//FILE* file = fopen("DTW.csv", "w");
	//for (int i = 0; i < count; i++){
	//	fprintf(file, "%lf,%lf,%lf,%lf \n", CostMatrix.at<double>(i, 0), CostMatrix.at<double>(i, 1), CostMatrix.at<double>(i, 2), CostMatrix.at<double>(i, 3));
	//}
	//fclose(file);

	return CostMatrix.at<double>(m - 1, n - 1);

}

//void DctTransform()
//{
//	int dct_count = count;
//	// 1-D DCT ����XYZ
//
//	cv::Mat matDct_intputdata_X;
//	cv::Mat matDct_intputdata_Y;
//	cv::Mat matDct_intputdata_Z;
//
//	cv::Mat matDct_outputdata_X;
//	cv::Mat matDct_outputdata_Y;
//	cv::Mat matDct_outputdata_Z;
//
//	//��0��(9/10�����ɹs�A�����R���̫�@��)
//	//cv::Mat mat_rowdata = cv::Mat::zeros(1,3,CV_32F);
//
//	//9/3�o��g���F,9/4�ק�//
//
//	if (count % 2 != 0){
//		matGS_outputData.pop_back();
//		dct_count = count - 1;
//	}
//
//	//tracemat(matGS_outputData);
//
//	matGS_outputData.col(0).copyTo(matDct_intputdata_X);
//	matGS_outputData.col(1).copyTo(matDct_intputdata_Y);
//	matGS_outputData.col(2).copyTo(matDct_intputdata_Z);
//
//
//	cv::dct(matDct_intputdata_X, matDct_outputdata_X);
//	cv::dct(matDct_intputdata_Y, matDct_outputdata_Y);
//	cv::dct(matDct_intputdata_Z, matDct_outputdata_Z);
//
//
//	//tracemat(matDct_outputdata_X);
//
//	FILE* file = fopen("���\_DCT.csv", "w");
//
//	for (int i = 0; i < dct_count; i++){
//		fprintf(file, "%f,%f,%f\n", matDct_outputdata_X.at<float>(i, 0), matDct_outputdata_Y.at<float>(i, 0), matDct_outputdata_Z.at<float>(i, 0));
//	}
//	fclose(file);
//
//}

//void DftTransform()
//{
//	cv::Mat matDft_intputdata_X;
//	cv::Mat matDft_intputdata_Y;
//	cv::Mat matDft_intputdata_Z;
//
//	cv::Mat matDft_outputdata_X;
//	cv::Mat matDft_outputdata_Y;
//	cv::Mat matDft_outputdata_Z;
//
//	matGS_outputData.col(0).copyTo(matDft_intputdata_X);
//	matGS_outputData.col(1).copyTo(matDft_intputdata_Y);
//	matGS_outputData.col(2).copyTo(matDft_intputdata_Z);
//
//	cv::Mat planes_X[] = { matDft_intputdata_X, cv::Mat::zeros(matDft_intputdata_X.size(), CV_32F) };
//	cv::Mat planes_Y[] = { matDft_intputdata_Y, cv::Mat::zeros(matDft_intputdata_Y.size(), CV_32F) };
//	cv::Mat planes_Z[] = { matDft_intputdata_Z, cv::Mat::zeros(matDft_intputdata_Z.size(), CV_32F) };
//
//	cv::Mat complex_X;
//	cv::Mat complex_Y;
//	cv::Mat complex_Z;
//
//	cv::merge(planes_X, 2, complex_X);
//	cv::merge(planes_Y, 2, complex_Y);
//	cv::merge(planes_Z, 2, complex_Z);
//
//	cv::dft(complex_X, complex_X, cv::DFT_COMPLEX_OUTPUT);
//	cv::dft(complex_Y, complex_Y, cv::DFT_COMPLEX_OUTPUT);
//	cv::dft(complex_Z, complex_Z, cv::DFT_COMPLEX_OUTPUT);
//
//	cv::split(complex_X, planes_X);
//	cv::split(complex_Y, planes_Y);
//	cv::split(complex_Z, planes_Z);
//
//
//	//tracemat(planes_Y[0]);
//	//tracemat(planes_Y[1]);
//
//
//	cv::magnitude(planes_X[0], planes_X[1], matDft_outputdata_X);
//	cv::magnitude(planes_Y[0], planes_Y[1], matDft_outputdata_Y);
//	cv::magnitude(planes_Z[0], planes_Z[1], matDft_outputdata_Z);
//
//	//tracemat(matDft_outputdata_X);
//
//	FILE* file = fopen("���\_DFT.csv", "w");
//
//	for (int i = 0; i < count; i++){
//		fprintf(file, "%f,%f,%f \n", matDft_outputdata_X.at<float>(i, 0), matDft_outputdata_Y.at<float>(i, 0), matDft_outputdata_Z.at<float>(i, 0));
//	}
//	fclose(file);
//
//
//	/*double min ,max;
//	cv::Point min_loc ,max_loc;
//	cv::minMaxLoc(matDft_outputdata_Y,&min, &max, &min_loc, &max_loc);
//	printf(" max = %f , max_loc = %d \n,min = %f ,min_loc = %d",max , max_loc.y,min ,min_loc.y);*/
//
//	/*float secondpoint;
//	cv::sort(matDft_outputdata_Y,matDft_outputdata_Y,CV_SORT_DESCENDING+CV_SORT_EVERY_COLUMN);
//	secondpoint = matDft_outputdata_Y.at<float>(1,0);
//	*/
//	float max = 0;
//	float sec_max = 0;
//	int index = 0;
//
//	for (int i = 0; i<count; i++){
//		if (matDft_outputdata_Z.at<float>(i, 0) > max){
//			sec_max = max;
//			max = matDft_outputdata_Z.at<float>(i, 0);
//		}
//		else if (matDft_outputdata_Z.at<float>(i, 0) > sec_max && matDft_outputdata_Z.at<float>(i, 0) < max){
//			sec_max = matDft_outputdata_Z.at<float>(i, 0);
//		}
//	}
//
//	for (int i = 0; i<count; i++){
//		if (matDft_outputdata_Z.at<float>(i, 0) == sec_max){
//			index = i + 1;
//			break;
//		}
//	}
//
//	printf("Peroid = %d samples\n", index);
//
//	FILE* file1 = fopen("�Ԥ�y_Peroid.csv", "w");
//
//	for (int i = 0; i < count; i++){
//		if (i%index == 0 && i != 0){
//			fprintf(file1, " ,  , \n", matGS_outputData.at<float>(i, 0), matGS_outputData.at<float>(i, 1), matGS_outputData.at<float>(i, 2));
//		}
//		else{
//			fprintf(file1, "%f,%f,%f \n", matGS_outputData.at<float>(i, 0), matGS_outputData.at<float>(i, 1), matGS_outputData.at<float>(i, 2));
//		}
//
//	}
//	fclose(file1);
//
//	//tracemat(matDft_outputdata_Y);
//}

//void K_CurvatureSegmentation()
//{
//	int k = 5;
//
//	std::vector<cv::Mat> axis_X;
//
//	axis_X.push_back(matGS_outputData.col(0));
//
//	for (int i = 0; i < axis_X.size(); i++){
//		
//	}
//}

cv::Mat FindPeriod(cv::Mat src)
{
	int tmp_times = 0;
	FILE *file = fopen("seg.csv", "w");
	cv::Mat mat_tmpIndex = cv::Mat::zeros(50, 1, CV_32S);

	for (int i = 2; i < src.rows - 2; i++){
		float pre_pre_S = src.at<double>(i - 2, 0);
		float pre_S = src.at<double>(i - 1, 0);
		float S = src.at<double>(i, 0);
		float next_S = src.at<double>(i + 1, 0);
		float next_next_S = src.at<double>(i + 2, 0);

		if (pre_pre_S < pre_S && pre_S < S && S >next_S && next_S > next_next_S){
			fprintf(file, "%d\n", i );
			mat_tmpIndex.at<int>(tmp_times, 0) = i;
			tmp_times = tmp_times + 1;
		}
	}
	cv::Mat mat_resizetmpIndex = cv::Mat::zeros(tmp_times, 1, CV_32S);
	for (int i = 0; i < tmp_times ; i++){
		for (int j = 0; j < mat_tmpIndex.cols; j++){
			mat_resizetmpIndex.at<int>(i, j) = mat_tmpIndex.at<int>(i, j);
			//printf("%d\n", mat_resizetmpIndex.at<int>(i, j));
		}
	}
	fclose(file);
	return mat_resizetmpIndex;

	
	//int tmp_times = 0;
	//int src_times = 0;
	//cv::Mat mat_srcIndex = cv::Mat::zeros(50, 1, CV_32S);
	//cv::Mat mat_tmpIndex = cv::Mat::zeros(50, 1, CV_32S);

	//FILE* file = fopen("circle_seg.csv", "w");
	//for (int i = 0; i < mat_periodIndex.rows; i++){
	//	printf("%d\n", mat_periodIndex.at<int>(i, 0));
	//}

	//// X axis period to segment another two axis
	//for (int i = 2; i < mat_tmp1.rows - 2; i++){
	//	float pre_pre_S = mat_tmp1.at<double>(i - 2, 0);
	//	float pre_S = mat_tmp1.at<double>(i - 1, 0);
	//	float S = mat_tmp1.at<double>(i, 0);
	//	float next_S = mat_tmp1.at<double>(i + 1, 0);
	//	float next_next_S = mat_tmp1.at<double>(i + 2, 0);

	//	if (pre_pre_S < pre_S && pre_S < S && S >next_S && next_S > next_next_S){
	//		//fprintf(file, "%d\n", i );
	//		mat_tmpIndex.at<int>(tmp_times, 0) = i;
	//		tmp_times = tmp_times + 1;
	//	}
	//}
	//printf("tmp_Times = %d\n", tmp_times);

	//for (int i = 2; i < mat_src.rows - 2; i++){
	//	float pre_pre_S = mat_src.at<double>(i - 2, 0);
	//	float pre_S = mat_src.at<double>(i - 1, 0);
	//	float S = mat_src.at<double>(i, 0);
	//	float next_S = mat_src.at<double>(i + 1, 0);
	//	float next_next_S = mat_src.at<double>(i + 2, 0);

	//	if (pre_pre_S < pre_S && pre_S < S && S >next_S && next_S > next_next_S){
	//		//fprintf(file, "%d\n", i );
	//		mat_srcIndex.at<int>(src_times, 0) = i;
	//		src_times = src_times + 1;
	//	}
	//}
	//printf("src_Times = %d\n", src_times);
}

float CalculateAllTmp(cv::Mat mat_tmplate, cv::Mat mat_src)
/*tmp && src period returns DTW distance*/
{
	cv::Mat mat_srcIndex;
	cv::Mat mat_periodDTWInput;
	cv::Mat mat_tmpIndex;
	cv::Mat mat_periodDTWtmp;

	float distance = 0 ,result ,weight;

	/*Get period*/
	mat_srcIndex = FindPeriod(mat_src);
	mat_tmpIndex = FindPeriod(mat_tmplate);

	/*select Tmplate to matching  ���ĤT(2-3)�өP�� */
	mat_periodDTWtmp = GetIntervalSignal(mat_tmplate, mat_tmpIndex.at<int>(1, 0), mat_tmpIndex.at<int>(2, 0));
	
	/*20150414*/
	/*matching calculate avg distance*/
	int rows = mat_srcIndex.rows;
	for (int n = 1; n < mat_srcIndex.rows ; n++){ 
		mat_periodDTWInput = GetIntervalSignal(mat_src, mat_srcIndex.at<int>(n - 1, 0), mat_srcIndex.at<int>(n, 0));
		distance += DTW_Distance(mat_periodDTWtmp, mat_periodDTWInput);
		//printf("Result%d = %f\n", n, distance);
	}
	int times = mat_srcIndex.rows - 1;
	result = distance / 5;

	printf("distance = %f ,times = %d ,avg_Result = %f ,", distance, times, result);

	//int zeroNum;
	//switch (tmpNum)
	//{
	//case 1:
	//	zeroNum = 1300;
	//	break;
	//case 2:
	//	zeroNum = 1300;
	//	break;
	//case 3:
	//	zeroNum = 1300;
	//	break;
	//case 4:
	//	zeroNum = 1300;
	//	break;
	//case 5:
	//	zeroNum = 1300;
	//	break;
	//case 6:
	//	zeroNum = 1300;
	//	break;
	//default:
	//	break;
	//}
	if (result <= 20){
		weight = 0.005;
		printf("weight = %f\n", weight);
	}
	else if(result > 20 && result <= 30){
		weight = 0.01;
		printf("weight = %f\n", weight);
	}
	else if(result > 30 && result <= 40){
		weight = 0.015;
		printf("weight = %f\n", weight);
	}
	else {
		weight = 0.02;
		printf("weight = %f\n", weight);
	}
	float percent = exp(result * -1 * weight);
	//printf("Percent = %f%%\n", percent * 100);
	return percent;
}


cv::Mat GetIntervalSignal(cv::Mat mat_src, int StartIndex, int EndIndex)
{
	char figurename[300];
	cv::Mat mat_period = cv::Mat((EndIndex - StartIndex) + 1, mat_src.cols, CV_64F);
	
	for (int i = StartIndex; i <= EndIndex; i++){
		for (int j = 0; j < mat_src.cols; j++){
			mat_period.at<double>(i - StartIndex, j) = mat_src.at <double>(i, j); //mat_period �n�q0�}�l 
		}
	}
	//tracemat(mat_period);
	//for (int i = 0; i < mat_period.rows; i++){
	//	sprintf(figurename, "Period_%d", i);
	//	PlotFigure(mat_period, figurename);
	//}
	
	//PlotFigure(mat_period, "Period");
	//PlotFigure(mat_period,"Period");
	return mat_period;
}


void PlotFigure(cv::Mat src, const std::string figurename)
{
	std::vector<double> x, y, z;
	for (int i = 0; i < src.rows; i++){
		x.push_back(src.at<double>(i, 0));
		y.push_back(src.at<double>(i, 1));
		z.push_back(src.at<double>(i, 2));
	}

	Gnuplot g1("lines");
	g1.set_title(figurename);
	g1.set_grid();
	g1.set_yautoscale();
	g1.plot_x(x, "X");
	g1.plot_x(y, "Y");
	g1.plot_x(z, "Z");
	//g1.showonscreen();
	//g1.savepng(figurename);
	//Gnuplot g2("lines");
	//g2.set_title(figurename);
	//g2.set_grid();
	//g2.plot_xyz(x, y, z,"3D");
	//g2.showonscreen();

	//system("pause");
	//g1.remove_tmpfiles();
}

void PlotInSameFigure(cv::Mat original, cv::Mat result, const std::string figurename, const std::string figurefilename)
{
	std::vector<double> a, b, c, x, y, z;
	for (int i = 0; i < result.rows; i++){
		x.push_back(result.at<double>(i, 0));
		y.push_back(result.at<double>(i, 1));
		z.push_back(result.at<double>(i, 2));
	}

	for (int i = 0; i < original.rows; i++){
		a.push_back(original.at<double>(i, 0));
		b.push_back(original.at<double>(i, 1));
		c.push_back(original.at<double>(i, 2));
	}

	Gnuplot g2("lines");
	g2.set_title(figurename);
	g2.set_grid();
	g2.plot_xyz(a, b, c, "User");
	g2.plot_xyz(x, y, z, "Template");
	//system("pause");
//	g2.savepng(figurefilename);
	g2.reset_all();
	//g2.remove_tmpfiles();

}
//Wikipedia

//int DTWDistance(s: array[1..n], t : array[1..m]) 
//{
//	DTW : = array[0..n, 0..m]
//
//    for i : = 1 to n
//        DTW[i, 0] : = infinity
//    for i : = 1 to m
//        DTW[0, i] : = infinity
//    DTW[0, 0] : = 0
//
//     for i : = 1 to n
//         for j : = 1 to m
//             cost : = d(s[i], t[j])
//             DTW[i, j] : = cost + minimum(DTW[i - 1, j],    // insertion
//                                         DTW[i, j - 1],    // deletion
//                                         DTW[i - 1, j - 1])    // match
//
//     return DTW[n, m]
//
//}