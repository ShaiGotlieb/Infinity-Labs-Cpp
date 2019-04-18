#include <cstdlib>
#include <cstring>
#include <vector>

#include "test.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "line.hpp"
#include "group.hpp"
#include "glut_utils.h"

using namespace ilrd;

std::vector<Shape *> rain;

int drawCircle = 0;
int g_xCircle = 1;
int g_yCircle = 1;
int g_xRect = 1;
int g_yRect = 1;
int g_xSquare = 1;
int g_ySquare = 1;
int g_xLine = 1;
int g_yLine = 1;
int g_xGroup = 1;
int g_yGroup = 1;
int g_interval = 2;
int g_revolveAngle = 1;
double g_rotateDegree = 0.0;

Circle *newCircle = new Circle(Point(500, 500), COLOR_YELLOW, 0.0, 60.0);
Circle *circle = new Circle(Point(g_xCircle, g_yCircle), COLOR_YELLOW, 0.0, 60.0);
Group *group = new Group();
Circle *manHead = new Circle(Point(500, 850), COLOR_WHITE, 0.0, 20.0);

static int TimerFunction();
static void DrawFunction();
static int KeyboardFunction(unsigned char key, int x, int y);
static void InitRain();
static void checkIntersectRainWithMan();
static void generateMan();

int main(int argc, char** argv)
{
    DrawInit(argc, argv, 1000, 1000, DrawFunction);
    DrawSetTimerFunc(TimerFunction, 100);
    DrawSetKeyboardFunc(KeyboardFunction);

    generateMan();

    DrawMainLoop();
	
	return (EXIT_SUCCESS);
}

static void generateMan()
{
    group->AddShape(manHead);
    group->AddShape(new Line(Point(500,912), COLOR_WHITE, 1.55, 85.0));
    group->AddShape(new Line(Point(500,905), COLOR_WHITE, 0.0, 40.0));
    group->AddShape(new Line(Point(493,962), COLOR_WHITE, 2.0, 40.0));
    group->AddShape(new Line(Point(512,962), COLOR_WHITE, 4.0, 40.0));
}

static int KeyboardFunction(unsigned char key, int x, int y)
{
    if (key == 0x1b /* ESC */)
        return -1;
        
    if (key == 0x41 /* A - move left */)
        group->Move(-4,0);

    if (key == 0x44 /* D - move left */)
        group->Move(4,0);

    return 0;
}

static int TimerFunction()
{
    circle->Move(g_interval,g_interval);
    g_xCircle += g_interval;
    g_yCircle += g_interval;
    if (circle->GetCenter().GetX() >= 900 || circle->GetCenter().GetX() <= 0)
    {
        g_interval *= -1;
        circle->SetColor(COLOR_BLUE);
    }

    if(drawCircle)
    {
        newCircle->Move(g_interval,g_interval);
        newCircle->Draw();
    }

    for(size_t i = 0; i < rain.size(); i++)
    {
        rain.at(i)->Move(0, rand() % 10 + 1);
    }

    checkIntersectRainWithMan();

    
    return 1;  /* draw */
}

static void checkIntersectRainWithMan()
{
    for(size_t i = 0; i < rain.size(); i++)
    {
        if(rain.at(i)->GetCenter().GetX() >= manHead->GetCenter().GetX() - manHead->GetRadius() &&
            rain.at(i)->GetCenter().GetX() <= manHead->GetCenter().GetX() + manHead->GetRadius() &&
            rain.at(i)->GetCenter().GetY() <= manHead->GetCenter().GetY() + manHead->GetRadius() &&
            rain.at(i)->GetCenter().GetY() >= manHead->GetCenter().GetY() - manHead->GetRadius())
        {
            group->SetColor(COLOR_RED);
        }
    }
}
static void DrawFunction()
{
    /*ACTIVATE SUN CIRCLE */
    circle->Draw();

    /* ACTIVATE RAIN */
    InitRain();

    /* TEST MAN */
    group->Draw();

}

static void InitRain()
{
    while (rand() % 20 == 0)
    {
        rain.push_back(new Line(Point(rand() % 1000 ,100), COLOR_CYAN, 1.6, 15.0));
    }

    for(size_t i = 0; i < rain.size(); i++)
    {
        rain.at(i)->Draw();
    }
}