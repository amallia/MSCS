#ifndef ProjectCONTROLLER_H
#define ProjectCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ProjectController : public ApplicationController
{
    Q_OBJECT
public:
    ProjectController() : ApplicationController() {}

public slots:
    void index();
    void tripleDES(const QString &id);
    void des(const QString &id);
    void elgamal(const QString &id);
};

#endif // ProjectCONTROLLER_H
