//#include <discpp.h>

#include <locale.h>
#include <cmath>
#include <vector>
#include <iostream>
#include "plant.h"
//#include "pch.h"
using namespace std;
using std::vector;


int main() {
	// ������������� ��.
	setlocale(0, "Russian");
	Plant plant;
	plant_init(plant);

	// ��������� ����������������� ������.
	//L=in_channel;
	//out_channel=M
	//value=U
	int out_channel, out_channel_research, in_channel, N;
	double U, M, sum_measured, x, S, X_sr, min_re_value, max_re_value, value, step;
	char contin;
	size_t k=0;


	vector<double> X;
	vector<int> out_ch;
	vector<double> val;

	cout << "����� ������������ ������� ���������� k ="; cin >> k;

	cout << "����� ������������ ������� ���������� Lk ="<<endl;
	for (int i=0; i<k; i++)
        {
           cout<<"L"<<i<<" =";cin>>out_channel;
           out_ch.push_back(out_channel);

        }
    cout<< "����� ��������� ��������� N ="; cin >>N;
    cout << "����� ������� (������ ������) ��� ��������� ���������� ="; cin >>in_channel ; cout<<'\n';


    bool f;
    do
    {
        k++;
        cout<< "�� ������ ������ L ���������� �������� ������������: L=";
        cin>>out_channel_research; cout<<endl;
        cout<<"����� ����������� �������� ���������� �� ������ L:";
        cin>>min_re_value; cout<<endl;
        cout<<"����� ������������ �������� ���������� �� ������ L:";
        cin>>max_re_value; cout<<endl;
        cout<<"� ����� ����� step ����� ������� ����������: step="; cin >>step;
        cout<<endl;

        cout<<'\t\t'<<"N "<<'\t\t'<<"Value "<<'\t\t'<<"X_sr"<<endl;
        //cout<<"����� �������� ���������� �������� �� ��������� �������"
        /*cout << "�������"<<k<<" �������� ����������� �����������"<<'\n';
        for (size_t i=0; i<k; i++)
        {
            cout<<"U"<<i<<" = ";
            cin>>value;
            val.push_back(value);
        }*/

        double R=static_cast<double>(max_re_value-min_re_value)/step;
        for (size_t i=min_re_value; i<max_re_value; i+=step)
        {

            val.push_back(i);
        }

        /*for (size_t i=0; i<k; i++)
        {
            plant_control(out_ch[i], val[i], plant);
        }*/
        for (size_t i=0; i<R; i++)
        {
            plant_control(out_channel_research, val[i], plant);
        }

/////////
        /*for (size_t i=0; i<N; i++)
        {
            x=plant_measure(in_channel,plant);
            //cout<<"X"<<i<<" = "<<x<<'\n';
            X.push_back(x);
        }
        sum_measured=0;
        for(double measure : X)
        {
            sum_measured+=measure;
        }

        //X_sr=0;
        X_sr=sum_measured/N;
        //cout<<"X_sr = "<<X_sr<<'\n';

        X.clear();*/
/////////
        //cout<<'\t\t'<<"N "<<'\t\t'<<"Value "<<'\t\t'<<"X_sr"<<endl;
        for (size_t j=min_re_value; j<max_re_value; j+=step)
        {
            for (size_t i=0; i<N; i++)
            {
                x=plant_measure(in_channel,plant);
            //cout<<"X"<<i<<" = "<<x<<'\n';
                X.push_back(x);
            }
            sum_measured=0;
            for(double measure : X)
            {
                sum_measured+=measure;
            }

            X_sr=sum_measured/N;

            //size_t k=0;
            cout<<'\t'<<k<<'\t'<<j<<'\t'<<X_sr<<endl;
            //k++;
        }

        X.clear();

        cout << "��������� ������ ���������? (Y/N) "<<endl;
        cin >> contin; cout<<endl;
        contin=tolower(contin);
        if (contin='N')
            f=false;
        else if (contin='Y')
            f;
    }
    while (!f);


	return 0;
}
