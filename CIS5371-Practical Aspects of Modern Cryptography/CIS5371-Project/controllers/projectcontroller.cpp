#include "projectcontroller.h"

//#include "blog.h"


void ProjectController::index()
{
     render();
}

void ProjectController::tripleDES(const QString &id)
{
   render();
}

void ProjectController::des(const QString &id)
{
	render();

}

void ProjectController::elgamal(const QString &id)
{
	render();
}



// Don't remove below this line
T_DEFINE_CONTROLLER(ProjectController)
