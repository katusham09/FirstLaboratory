#include "mainwindow.h"

Win::Win(QWidget *parent):QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");//устанавливает заголовок окна
    frame = new QFrame(this);// создаем новый объект QFrame
    frame->setFrameShadow(QFrame::Raised);//устанавливаем для объекта frame тень рамки
    frame->setFrameShape(QFrame::Panel);//устанавливаем для объекта frame форму рамки в виде прямоугольной с обычной панелью
    inputLabel = new QLabel("Введите число:", this);//создаем новый объект QLabel, который представляет метку с текстом "Введите число:"
    inputEdit = new QLineEdit("",this);// создаем новый объект QLineEdit, который представляет поле для ввода текста
    StrValidator *v=new StrValidator(inputEdit);//создаем новый объект StrValidator. Объект inputEdit является родительским для объекта StrValidator
    inputEdit->setValidator(v);//устанавливаем валидатор для проверки строки
    outputLabel = new QLabel("Результат:", this);//создаем новый объект QLabel, который представляет метку с текстом "Результат:"
    outputEdit = new QLineEdit("",this);// создаем новый объект QLineEdit, который представляет поле с ответом
    nextButton = new QPushButton("Следующее", this);//создаем кнопку nextButton с надписью "Следующее"
    exitButton = new QPushButton("Выход", this);//создаем кнопку exitButton с надписью "Выход"
    // компоновка приложения выполняется согласно рисунку 2
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//вертикальный компоновщик – управляет расположением виджетов в окне по вертикали;
    //все виджеты inputLabel, inputEdit, outputLabel, outputEdit будут отображаться вертикально друг под другом в порядке добавления в vLayout1
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch(); //"пружина". Виджеты, поджатые пружиной, при увеличении размеров окна остаются рядом.
    QVBoxLayout *vLayout2 = new QVBoxLayout();//вертикальный компоновщик – управляет расположением виджетов в окне по вертикали;
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();//"пружина". Виджеты, поджатые пружиной, при увеличении размеров окна остаются рядом.
    QHBoxLayout *hLayout = new QHBoxLayout(this);//горизонтальный компоновщик – управляет расположением виджетов в окне по горизонтали;
    hLayout->addWidget(frame);//добавляем рамку слева
    hLayout->addLayout(vLayout2);//и добавляем vLayout2 справа
    begin();//начальная настройка интерфейса

    //Сигнально-слотовые соединения
    //connect(&Отправитель, &Class_1::mysignal, &Адресат, &Class_2::myslot);
    connect(exitButton,&QPushButton::clicked,this,&Win::close);//при нажатии на кнопку exitButton и срабатывании сигнала clicked, будет вызываться метод close у объекта this типа Win
    connect(nextButton,&QPushButton::clicked,this,&Win::begin);//при нажатии на кнопку nextButton и срабатывании сигнала clicked, будет вызываться метод begin у объекта this типа Win
    connect(inputEdit,&QLineEdit::returnPressed,this,&Win::calc);//при нажатии клавиши Enter в текстовом поле inputEdit и срабатывании сигнала returnPressed, будет вызываться метод calc у объекта this типа Win
}

void Win::begin()//метод начальной настройки интерфейса
{
    inputEdit->clear();//Очищаем текстовое поле ввода, чтобы оно было готово для нового ввода.
    nextButton->setEnabled(false);//Отключаем кнопку "Следующее", чтобы предотвратить ненужные нажатия, кнопка становится не активна и серого цвета.
    nextButton->setDefault(false);//кнопка не реагирует на нажатие Enter
    inputEdit->setEnabled(true);//Включаем текстовое поле ввода, чтобы пользователь мог ввести новые данные.
    outputLabel->setVisible(false);//Скрываем метку вывода результата и текстовое поле вывода результата, так как на этом этапе результат еще не вычислен.
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);//Отключаем текстовое поле вывода результата, чтобы пользователь не мог изменять его значение.
    inputEdit->setFocus();//Устанавливает фокус на текстовое поле ввода, чтобы пользователь мог сразу начать вводить данные без необходимости щелкать мышью на поле.
}

void Win::calc()//метод реализации вычислений
{
    bool Ok=true;//флаг
    float r,a;
    QString str=inputEdit->text();//создаем объект QString с именем str и присваивает ему текст, который находится в текстовом поле inputEdit
    a=str.toDouble(&Ok);//преобразовываем строку str в число типа double и устанавливаем флаг Ok
    if (Ok)//Если преобразование прошло успешно, Ok будет равно true, иначе - false.
    {
        r=a*a;//вычисляем квадрат числа a
        str.setNum(r);//значение переменной r преобразуется в строку и устанавливается как новое значение переменной str.
        outputEdit->setText(str);//устанавливается текстовое значение в текстовое поле outputEdit, отображая результат вычисления квадрата.
        inputEdit->setEnabled(false);//отключается возможность редактирования текста в текстовом поле inputEdit.
        outputLabel->setVisible(true);//делаем видимыми метку и текстовое поле для вывода результата.
        outputEdit->setVisible(true);
        nextButton->setDefault(true);//устанавливается кнопка "Следующее" как кнопка по умолчанию, т.е. реагирует на нажатие Enter
        nextButton->setEnabled(true);//включается возможность использования кнопки "Следующее".
        nextButton->setFocus();//устанавливается фокус на кнопку "Следующее".
    }
    else//если преобразование строки в число не произошло
        if (!str.isEmpty())//и строка не пуста
        {
        QMessageBox::information(this, "Возведение в квадрат.", "Введено неверное значение.");
        //показывается информационное сообщение с заголовком "Возведение в квадрат." и текстом "Введено неверное значение.".
        //Это сообщение предупреждает пользователя о некорректном вводе данных.
        }
}
