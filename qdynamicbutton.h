#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QRadioButton>

class QDynamicButton : public QRadioButton
{
    Q_OBJECT
public:
    explicit QDynamicButton(QWidget *parent = 0);
    ~QDynamicButton();
    //static int ResID;   // A static variable counter buttons rooms
    //int getID();        // Function to return a local number buttons

public slots:

private:
    //int buttonID = 0;   // Local variable number of the button
};

#endif // QDYNAMICBUTTON_H
