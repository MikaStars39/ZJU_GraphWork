#include <windows.h>
#include <winuser.h>
#include <math.h>
#include "graphics.h"
#include "extgraph.h"
#include "imgui.h"
#include "linkedlist.h"

/*
以下是作业实现的内容：
·制定一个全局变量来记录当前的角度
·forward函数：向前前进一个相对的长度
·turn函数： 顺时针实现角度的转动
·move函数：沿着当前方向移动画笔，不画出轨迹 
*/

double current_angle = 0.0;  

void forward(double distance);
void turn(double angle);
void move(double distance);

// 以下是附加的函数，实现了模块化的开发 

void initialize(); // 初始化状态：将画笔移到中间，并且将角度设置为0 
void SetColor(); // 设置颜色 

void DrawRhombus(double EdgeValue); // 默认在当前画笔的位置画出一个菱形，能够设置边的长度 
void DrawPolygon(int Edgenum, double EdgeValue);// 画一个多边形，能够设置边长和边数 
void DrawExample(double SuperParameter);// 画内个作业2滴图形奥，在画面中间画 
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
	printf("本次图形作业选择的是第二个作业,会生成一个14*10的窗口\n"); 
	printf("你可以设置第二次作业所画图形大小的超参数\n");
	printf("请输入你的超参数（默认为1）：\n");
	double sp;
	scanf("%lf", &sp);
	printf("你的图形已经画好了！，图形窗口可能会被这个命令行窗口遮挡(`^`)，你可以移到前面来查看了！\n");
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

