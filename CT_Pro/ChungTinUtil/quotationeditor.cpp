#include "quotationeditor.h"

bool quotationEditorSetup()
{
    MainWindow* editor = new MainWindow();
    editor->setAttribute(Qt::WA_DeleteOnClose);  // Set the delete on close attribute
    editor->show();
    return true;
}
