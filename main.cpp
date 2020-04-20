//
//  Main program for LINuxLOGGER
//

#include <qapplication.h>
#include "javadloggui.h"

int main( int argc, char *argv[] )
{
  QApplication app( argc, argv );

  // Transfer control to the GUI
  Javadloggui gui;
  app.setMainWidget( &gui );
  gui.show();
  return app.exec();

}

