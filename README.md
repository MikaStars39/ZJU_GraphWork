# 图形开发作业（题目2）

非常水的一份作业，也没有做Simple GUI，用命令行水了一下……请互评的同学手下留情🙏

我的Github: [MikaStars39 · GitHub](https://github.com/MikaStars39)

我的主页：mikastars39.github.io

### 模块设计

按照作业的要求，实现了以下函数：

```c
double current_angle = 0.0;    
void forward(double distance);  
void turn(double angle);  
void move(double distance);
```

实现了以下功能：



> 除了已有的笔的概念（有当前位置）之外，再增加一个表示当前角度的全局变量，初始值为0，表示坐标轴的横轴方向（正东）。
> 
> 然后实现以下两个函数：
> 
> void forward(double distance);
> 
> 沿当前方向画线，长度为distance，当distance为负数时后退
> 
> void turn (double angle); 
> 
> 顺时针旋转角度angle，角度单位为 DEG，当angle为负数时逆时针旋转
> 
> void move(double distance); 
> 
> 沿当前方向移动笔，长度为distance，当distance为负数时后退

同时，为了实现模块化的设计~~不一笔一笔画房子~~，实现了以下函数：

```c
void initialize(); 
void SetColor();
```

initialize 函数初始化了画笔的状态，将画笔移到整个窗口的中心

SetColor函数设置颜色

```c
void DrawRhombus(double EdgeValue); 
void DrawPolygon(int Edgenum, double EdgeValue);
```

DrawRhombus 函数画出一个菱形，能够设置边长

DrawPolygon 函数画出一个正多边形，能够设置边的长度和边的数量

```c
void DrawExample(double SuperParameter);
```

DrawExample 函数画出作业要求的图形，同时提供一个超参数用于调整图形整体的大小

```c
void console();
```

console 函数初始化控制台并启动画图

### 文件结构

解压 图形作业.zip 后，会得到一个Project文件夹

> Project ---- |document -------------|README.md
> 
>                     |code ------------------- | code 源代码
> 
>                                                         | DevC_Project 项目文件的储存地址
> 
>                                                         | libgraphics 图形库
> 
>                                                         | simpleGUI UI库

### 编译运行

直接进入DevC_Project中编译即可


