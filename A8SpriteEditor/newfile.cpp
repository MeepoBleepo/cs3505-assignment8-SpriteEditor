/**
 * The dialog box that shows up when the user wants to create a new file.
 *
 * Github URL: https://github.com/UofU-CS3505/cs3505-assignment8-MeepoBleepo.git
 *
 * Created by Logan Wood, Nicholas Zamani, Dylan Kelly, Zachary Dinsmore, and Moliang Pan
 * March 31, 2025
 *
 * Checked by Nicholas Zamani, March 31, 2025
 **/

#include "newfile.h"
#include "ui_newfile.h"

NewFile::NewFile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewFile){
    ui->setupUi(this);

    //Connect buttons to slots
    connect(ui->confirmButton, &QDialogButtonBox::accepted, this, &NewFile::confirmButtonClicked);
    connect(ui->confirmButton, &QDialogButtonBox::rejected, this, &NewFile::rejectedButton);
    connect(ui->sizeInput, &QLineEdit::textChanged, this, &NewFile::badNumText);
    ui->smallerNumber->hide();
}

NewFile::~NewFile(){
    delete ui;
}

void NewFile::confirmButtonClicked(){

    QString input = ui->sizeInput->text();

    bool isInt;
    int numberInput = input.toInt(&isInt);

    // Case for invalid input
    if(!isInt){
        ui->smallerNumber->show();
        return; // An int was not input so do nothing
    }

    // Checks for a valid entry
    if (numberInput > 64 || numberInput < 1){
        ui->smallerNumber->show();
        return;
    }

    emit sendSize(numberInput);
    this->hide();
}

void NewFile::rejectedButton(){
    this->hide();
}

void NewFile::badNumText(){
    ui->smallerNumber->hide();
}
