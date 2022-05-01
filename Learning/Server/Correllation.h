#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;

class Data
{
    public:
    int number_student=6;
    struct Information
    {
       int  ID_student;
       int  number_see_lecture;
       double  assement;
    };
    Information  information[6];
    Data()
    {
        information[0].ID_student=7000;
        for(int i=0;i<6;i++)
        {
        information[i].ID_student=i+7000;
        }
        information[0].number_see_lecture=11;
        information[1].number_see_lecture=13;
        information[2].number_see_lecture=18;
        information[3].number_see_lecture=12;
        information[4].number_see_lecture=16;
        information[5].number_see_lecture=14;


        information[0].assement=67;
        information[1].assement=73;
        information[2].assement=78;
        information[3].assement=71;
        information[4].assement=73;
        information[5].assement=70;


    }
    //Information  information[5];
    int get_Id(int i)
    {
        return information[i].ID_student;
    } 

    int get_lecture(int i)
    {
        return information[i].number_see_lecture;
    }
    double get_assesment(int i)
    {
 
     return information[i].assement;

    }  

};

class Carallestion
{
    public: 
    Data date;
    int num_stud;
    Carallestion()
    {   
        fstream file("correllation.txt", std::fstream::out);
        num_stud=date.number_student; 
        if(file.is_open())
        {
        file<<"Coreletion analisis\n";
        for (int i=0;i<num_stud;i++)
        	{
                
                file<<date.get_Id(i)<<"  "<<date.get_lecture(i)<<"  "<<date.get_assesment(i)<<endl;
            }
        }
        else cout<<"file not exist!"<<endl; 
    }
    int function_correllation()
    {
        fstream file("correllation.txt", std::fstream::out| std::fstream::app);
        double correlletion;
        //int num_stud=date.number_student; 
        double X=0, Y=0, XY=0, x_squer=0, y_squer=0;
        for (int i=0;i<num_stud;i++)
        {
            X=X+date.get_lecture(i);
            Y=Y+date.get_assesment(i);
            XY=XY+date.get_assesment(i)*date.get_lecture(i);
            x_squer=x_squer+(date.get_lecture(i)*date.get_lecture(i));
            y_squer=y_squer+(date.get_assesment(i)*date.get_assesment(i));
        }
        double A, B;
        A=(num_stud*x_squer)-pow(X,2);
        B=(num_stud*y_squer)-pow(Y,2);
        correlletion=((num_stud*XY)-(X*Y))/(sqrt(A*B));
        if(file.is_open())
        {
            file<<"Correlation analis is equal: "<<setprecision(2)<<correlletion<<"%"<<endl;
        } 
        return 4; 
    }

};