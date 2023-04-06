#include <windows.h>
#include <winuser.h>
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

/*
��������ҵʵ�ֵ����ݣ�
���ƶ�һ��ȫ�ֱ�������¼��ǰ�ĽǶ�
��forward��������ǰǰ��һ����Եĳ���
��turn������ ˳ʱ��ʵ�ֽǶȵ�ת��
��move���������ŵ�ǰ�����ƶ����ʣ��������켣 
*/

double current_angle = 0.0;  

void forward(double distance);
void turn(double angle);
void move(double distance);

// �����Ǹ��ӵĺ�����ʵ����ģ�黯�Ŀ��� 

void initialize(); // ��ʼ��״̬���������Ƶ��м䣬���ҽ��Ƕ�����Ϊ0 
void SetColor(); // ������ɫ 

void DrawRhombus(double EdgeValue); // Ĭ���ڵ�ǰ���ʵ�λ�û���һ�����Σ��ܹ����ñߵĳ��� 
void DrawPolygon(int Edgenum, double EdgeValue);// ��һ������Σ��ܹ����ñ߳��ͱ��� 
void DrawExample(double SuperParameter);// ���ڸ���ҵ2��ͼ�ΰ£��ڻ����м仭 
void console();
void Main()
{
	SetWindowTitle("C Graphlib Homework");
	SetWindowSize(14.0, 10.0);
	InitGraphics();
	SetColor();
    initialize();
    console();
}

void console()
{
	InitConsole();
	printf("-------------------------------------------------------------\n");
	printf("����ͼ����ҵѡ����ǵڶ�����ҵ,������һ��14*10�Ĵ���\n"); 
	printf("��������õڶ�����ҵ����ͼ�δ�С�ĳ�����\n");
	printf("��������ĳ�������Ĭ��Ϊ1����\n");
	double sp;
	scanf("%lf", &sp);
	printf("���ͼ���Ѿ������ˣ���ͼ�δ��ڿ��ܻᱻ��������д����ڵ�(`^`)��������Ƶ�ǰ�����鿴�ˣ�\n");
	DrawExample(sp);
}

void DrawExample(double Superparameter)
{
	 int i;
    for (i = 0; i < 18; i++ )
    {
    	DrawRhombus(1.0 * Superparameter); 
    	turn(20);
    }
    move(2 * Superparameter);
    DrawPolygon(6, 2.0 * Superparameter);
    initialize();
	turn(20);
    move(2 * Superparameter);
    DrawPolygon(6, 2.0 * Superparameter);
    initialize();
    turn(40);
    move(2 * Superparameter);
    DrawPolygon(6, 2.0 * Superparameter);
}
// standard polygon functions
void DrawPolygon(int Edgenum, double EdgeValue)
{
	double PolyAngle = 360.0/Edgenum;
	turn( 180.0 - PolyAngle);
	int i;
	for ( i = 0; i < Edgenum; i++ )
	{
   		forward(EdgeValue);
   		turn(PolyAngle);
	}
	turn( 360.0 - PolyAngle);
}
void DrawRhombus(double EdgeValue)
{
	forward(EdgeValue);
	turn(60);
	forward(EdgeValue);
	turn(120);
	forward(EdgeValue);
	turn(60);
	forward(EdgeValue);
	turn(-240);

}

void SetColor()
{
	SetPenColor("Blue");
}

void initialize()
{
    MovePen(GetWindowWidth()/2.0, GetWindowHeight()/2.0);
    current_angle = 0.0;
}

void forward(double distance) 
{
    double dx = distance * cos(current_angle * M_PI / 180);
    double dy = distance * sin(current_angle * M_PI / 180);
    DrawLine(dx, dy);
    //MovePen(GetCurrentX() + dx, GetCurrentY() + dy);
}

void turn(double angle) 
{
    current_angle+=angle; 
}

void move(double distance) 
{
    double dx = distance * cos(current_angle * M_PI / 180);
    double dy = distance * sin(current_angle * M_PI / 180);
    MovePen(GetCurrentX() + dx, GetCurrentY() + dy);
}

