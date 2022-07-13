#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

class Room {
public:
    Room(string n, double t) :name(n), temperature(t) {
    }
    void setTemperature(double temper) {
        temperature = temper;
    }
    void getTemperature() { cout << temperature << "°С / "; cout << (temperature * 9 / 5) + 32 << "°F" << endl; }
    int getName() {
        cout << name << endl;
    }
private:
    string name;
    double temperature;
};

void roomlist() {
    system("cls");
    cout << "1. Бухгалтерія" << endl
        << "2. Відділ кадрів" << endl
        << "3. ІТ-відділ" << endl
        << "4. Сервер" << endl
        << "5. Робочі офіси" << endl
        << "6. Кімната відпочинку" << endl
        << "7. Кабінет виконачого директора" << endl
        << "8. Зал" << endl
        << "9. Закінчити роботу" << endl;
}

void menu() {
    system("cls");
    cout << "1. Налаштування за замовчуванням" << endl
        << "2. Температура" << endl
        << "3. Налаштувати власноруч" << endl
        << "4. Повернутись до списку кімнат" << endl;
}

void regionSettingsMenu() {
    system("cls");
    cout << "1. Східна Європа" << endl <<
        "2. Західна Європа" << endl <<
        "3. Країни Середземномор'я" << endl <<
        "4. Країни Скандинавії" << endl <<
        "5. Повернутись в меню налаштувань" << endl;
}

void fSettingsMenu() {
    system("cls");
    cout << "1. Морський бриз" << endl <<
        "2. Літня прохолода" << endl <<
        "3. Весняна пора" << endl <<
        "4. Повернутись в меню налаштувань" << endl;
}

int getvariant(int count) {
    int variant;
    string input;
    getline(cin, input);

    while (sscanf_s(input.c_str(), "%d", &variant) != 1 || variant <1 || variant > count) {
        cout << "Введіть ще раз" << endl;
        getline(cin, input);
    }
    return variant;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    double temparray[8];
    for (int i = 0; i < 8; i++)
    {
        temparray[i] = 15 + rand() % 40;
    }
    Room Accounting1("Accounting", temparray[0]);
    Room HRDepartment2("HRDepartment", temparray[1]);
    Room ITDepartment3("ITDepartment", temparray[2]);
    Room Server4("Server", temparray[3]);
    Room WorkOffice5("WorkOffice", temparray[4]);
    Room RestRoom6("RestRoom", temparray[5]);
    Room CEORoom7("CEORoom", temparray[6]);
    Room Hall8("Hall", temparray[7]);
    int variant;
    do {
    returnpoint:
        roomlist();
        variant = getvariant(9);
        switch (variant) {
        case 1: cout << "Бухгалтерія" << endl;
        returnpointMenu:
            menu();
            int inputMenu1;
            do {
                inputMenu1 = getvariant(4);
                switch (inputMenu1) {
                case 1:
                returnpointSettings:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    Accounting1.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    Accounting1.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    Accounting1.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    Accounting1.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettings;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);

                                
                                    switch (fSetteings) {
                                    case 1:
                                        cout << "1. Морський бриз" << endl;
                                        Accounting1.setTemperature(21.5);
                                        break;
                                    case 2:
                                        cout << "Літня прохолода" << endl;
                                        Accounting1.setTemperature(22.6);
                                        break;
                                    case 3:
                                        cout << "Весняна пора" << endl;
                                        Accounting1.setTemperature(19.4);
                                        break;
                                        if (fSetteings != 4) system("pause");
                                    }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettings;
                        }
                    } while (defaultSettings != 3); goto returnpointMenu;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура в бухгалтерії - ";
                    Accounting1.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    Accounting1.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    Accounting1.getTemperature();
                    break;
                }
                if (inputMenu1 != 4) system("pause");
            } while (inputMenu1 != 4);
            goto returnpoint;
            break;
        case 2: cout << "Відділ кадрів" << endl;
        returnpointMenuHR:
            menu();
            int inputMenu2;
            do {
                inputMenu2 = getvariant(4);
                switch (inputMenu2) {
                case 1:
                returnpointSettingsHR:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    HRDepartment2.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    HRDepartment2.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    HRDepartment2.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    HRDepartment2.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsHR;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    HRDepartment2.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    HRDepartment2.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    HRDepartment2.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsHR;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuHR;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура у відділі кадрів - ";
                    HRDepartment2.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    HRDepartment2.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    HRDepartment2.getTemperature();
                    break;
                }
                if (inputMenu2 != 4) system("pause");
            } while (inputMenu2 != 4);
            goto returnpoint;
            break;
        case 3: cout << "ІТ-відділ" << endl;
        returnpointMenuIT:
            menu();
            int inputMenu3;
            do {
                inputMenu3 = getvariant(4);
                switch (inputMenu3) {
                case 1:
                returnpointSettingsIT:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    ITDepartment3.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    ITDepartment3.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    ITDepartment3.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    ITDepartment3.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsIT;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    ITDepartment3.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    ITDepartment3.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    ITDepartment3.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsIT;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuIT;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура в IT-відділі - ";
                    ITDepartment3.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    ITDepartment3.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    ITDepartment3.getTemperature();
                    break;
                }
                if (inputMenu3 != 4) system("pause");
            } while (inputMenu3 != 4);
            goto returnpoint;
            break;
        case 4: cout << "Сервер" << endl;
        returnpointMenuSERVER:
            menu();
            int inputMenu4;
            do {
                inputMenu4 = getvariant(4);
                switch (inputMenu4) {
                case 1:
                returnpointSettingsSERVER:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    Server4.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    Server4.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    Server4.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    Server4.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsSERVER;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    Server4.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    Server4.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    Server4.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsSERVER;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuSERVER;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура у серверній - ";
                    Server4.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    Server4.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    Server4.getTemperature();
                    break;
                }
                if (inputMenu4 != 4) system("pause");
            } while (inputMenu4 != 4);
            goto returnpoint;
            break;
        case 5: cout << "Робочі офіси" << endl;
        returnpointMenuOFFICE:
            menu();
            int inputMenu5;
            do {
                inputMenu5 = getvariant(4);
                switch (inputMenu5) {
                case 1:
                returnpointSettingsOFFICE:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    WorkOffice5.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    WorkOffice5.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    WorkOffice5.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    WorkOffice5.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsOFFICE;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    WorkOffice5.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    WorkOffice5.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    WorkOffice5.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsOFFICE;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuOFFICE;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура в офісах - ";
                    WorkOffice5.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    WorkOffice5.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    WorkOffice5.getTemperature();
                    break;
                }
                if (inputMenu5 != 4) system("pause");
            } while (inputMenu5 != 4);
            goto returnpoint;
            break;
        case 6: cout << "Кімната відпочинку" << endl;
        returnpointMenuRR:
            menu();
            int inputMenu6;
            do {
                inputMenu6 = getvariant(4);
                switch (inputMenu6) {
                case 1:
                returnpointSettingsRR:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    RestRoom6.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    RestRoom6.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    RestRoom6.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    RestRoom6.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsRR;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    RestRoom6.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    RestRoom6.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    RestRoom6.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsRR;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuRR;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура у кімнаті відпочинку - ";
                    RestRoom6.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    RestRoom6.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    RestRoom6.getTemperature();
                    break;
                }
                if (inputMenu6 != 4) system("pause");
            } while (inputMenu6 != 4);
            goto returnpoint;
            break;
        case 7: cout << "Кабінет виконавчого директора" << endl;
        returnpointMenuCEO:
            menu();
            int inputMenu7;
            do {
                inputMenu7 = getvariant(4);
                switch (inputMenu7) {
                case 1:
                returnpointSettingsCEO:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    CEORoom7.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    CEORoom7.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    CEORoom7.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    CEORoom7.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsCEO;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    CEORoom7.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    CEORoom7.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    CEORoom7.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsCEO;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuCEO;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура у кабінеті виконавчого директора - ";
                    CEORoom7.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    CEORoom7.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    CEORoom7.getTemperature();
                    break;
                }
                if (inputMenu7 != 4) system("pause");
            } while (inputMenu7 != 4);
            goto returnpoint;
            break;
        case 8: cout << "Зал" << endl;
        returnpointMenuHALL:
            menu();
            int inputMenu8;
            do {
                inputMenu8 = getvariant(4);
                switch (inputMenu8) {
                case 1:
                returnpointSettingsHALL:
                    //cout << "Налаштування за замовчуванням" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. За регіоном" << endl;
                        cout << "2. За відчуттям" << endl;
                        cout << "3. Повернутись в меню" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "За регіоном" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "Східна Європа" << endl;
                                    Hall8.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "Західна Європа" << endl;
                                    Hall8.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "Країни Середземномор'я" << endl;
                                    Hall8.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "Країни Скандинавії" << endl;
                                    Hall8.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsHALL;
                            int fSetteings;
                        case 2: cout << "За відчуттям" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. Морський бриз" << endl;
                                    Hall8.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "Літня прохолода" << endl;
                                    Hall8.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "Весняна пора" << endl;
                                    Hall8.setTemperature(19.4);
                                    break;
                                    if (fSetteings != 4) system("pause");
                                }

                                if (fSetteings != 4) system("pause");
                            } while (fSetteings != 4); goto returnpointSettingsHALL;
                        }
                    } while (defaultSettings != 3); goto returnpointMenuHALL;
                    break;
                case 2:
                    //cout << "Температура" << endl;
                    cout << "Температура у залі - ";
                    Hall8.getTemperature();
                    break;
                case 3:
                    //cout << "Налаштувати власноруч" << endl;
                    int changet = 0;
                    cout << "Введіть значення температури, яке ви бажаєте встановити - ";
                    cin >> changet;
                    if (changet < 15)
                    {
                        changet = 15;
                    }
                    else if (changet > 45)
                    {
                        changet = 45;
                    }
                    Hall8.setTemperature(changet);
                    cout << "Температуру змінено на - ";
                    Hall8.getTemperature();
                    break;
                }
                if (inputMenu8 != 4) system("pause");
            } while (inputMenu8 != 4);
            goto returnpoint;
            break;
        }
        if (variant != 9)
            system("pause");
    } while (variant != 9);
    return 0;
}