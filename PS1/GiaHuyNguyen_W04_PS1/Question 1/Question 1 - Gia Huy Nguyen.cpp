#include<iostream>
#include<string>
using namespace std;

int main()
{
	int  UnitSold[4][3]; 																					//Khoi tao mang 2 chieu
	int  Sum_DashCammodel[4] = {0,0,0,0}; 				
	string Dash_Cam_model[4] = { "RS Pro with GPS", "Transcend Drive Pro", "H203 1080P", "Pioneer" };
	string Branch[3] = { "SJ Branch", "PJ Branch", "KL Branch" };
		for (int i = 0; i < 4; i++) {																		//Nhap vao phan tu cua mang
			for (int j = 0;j < 3;j++) {
				cout << "Sales figures for " << Dash_Cam_model[i] << " in " << Branch[j] << ": ";
				cin >> UnitSold[i][j];
				Sum_DashCammodel[i] = Sum_DashCammodel[i] + UnitSold[i][j]; 								//Tinh tong so luong tung loai Dash Cam
				cout << endl;
			}
		}
		
	int Price[4] = {730, 850, 150, 350};
	int income[3] = { 0, 0, 0 };	
		for (int i = 0; i < 3; i++) {																		//Tinh doanh thu cua tung Branch
			for (int j = 0; j < 4; j++) {
				UnitSold[j][i] *= Price[j];
				income[i] += UnitSold[j][i];
			}
		}
		
		for (int i = 0; i < 3; i++) {																	    //In ra man hinh doanh thu cua tung Branch
			cout << "Total gross sales for " << Branch[i]<<" is: " << income[i] << endl;
		}
		
		string brand_bestseller = Branch[0];
		for (int i = 0; i < 3; i++) {																		//Tim Branch co doanh thu cao nhat
			if (income[i] > income[0]) {
				income[0] = income[i];
				brand_bestseller = Branch[i];
			}
		}
		cout << "The highest sales figure is RM " << income[0] << " by Branch " << brand_bestseller << endl;
		
		string dashcam_bestseller;
			for (int i = 0; i < 3; i++) {																	//Tim loai Dash Cam ban chay nhat
				if (Sum_DashCammodel[0] <= Sum_DashCammodel[i]) {
					Sum_DashCammodel[0] = Sum_DashCammodel[i];
					dashcam_bestseller = Dash_Cam_model[i];
				}
			}
		cout << "The most popular dash cam model is " << dashcam_bestseller<< " with unit sold of " << Sum_DashCammodel[0] <<" units" << endl;
		return 0;
}

