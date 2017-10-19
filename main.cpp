#include <QApplication>

#include "view.h"
#include "model.h"
#include "controller.h"

int main (int argc, char **argv){
   QApplication app(argc, argv);

   Model *model = new Model();
   View *view = new View();
   Controller *controller = new Controller();

   view->setModel(model);
   controller->setModel(model);
   view->show();

   return app.exec();
}
