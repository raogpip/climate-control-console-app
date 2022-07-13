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
    void getTemperature() { cout << temperature << "�� / "; cout << (temperature * 9 / 5) + 32 << "�F" << endl; }
    int getName() {
        cout << name << endl;
    }
private:
    string name;
    double temperature;
};

void roomlist() {
    system("cls");
    cout << "1. ����������" << endl
        << "2. ³��� �����" << endl
        << "3. ��-����" << endl
        << "4. ������" << endl
        << "5. ������ �����" << endl
        << "6. ʳ����� ���������" << endl
        << "7. ������ ���������� ���������" << endl
        << "8. ���" << endl
        << "9. �������� ������" << endl;
}

void menu() {
    system("cls");
    cout << "1. ������������ �� �������������" << endl
        << "2. �����������" << endl
        << "3. ����������� ���������" << endl
        << "4. ����������� �� ������ �����" << endl;
}

void regionSettingsMenu() {
    system("cls");
    cout << "1. ������ ������" << endl <<
        "2. ������� ������" << endl <<
        "3. ����� �������������'�" << endl <<
        "4. ����� ��������⳿" << endl <<
        "5. ����������� � ���� �����������" << endl;
}

void fSettingsMenu() {
    system("cls");
    cout << "1. �������� ����" << endl <<
        "2. ˳��� ���������" << endl <<
        "3. ������� ����" << endl <<
        "4. ����������� � ���� �����������" << endl;
}

int getvariant(int count) {
    int variant;
    string input;
    getline(cin, input);

    while (sscanf_s(input.c_str(), "%d", &variant) != 1 || variant <1 || variant > count) {
        cout << "������ �� ���" << endl;
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
        case 1: cout << "����������" << endl;
        returnpointMenu:
            menu();
            int inputMenu1;
            do {
                inputMenu1 = getvariant(4);
                switch (inputMenu1) {
                case 1:
                returnpointSettings:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    Accounting1.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    Accounting1.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    Accounting1.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    Accounting1.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettings;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);

                                
                                    switch (fSetteings) {
                                    case 1:
                                        cout << "1. �������� ����" << endl;
                                        Accounting1.setTemperature(21.5);
                                        break;
                                    case 2:
                                        cout << "˳��� ���������" << endl;
                                        Accounting1.setTemperature(22.6);
                                        break;
                                    case 3:
                                        cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ��������� - ";
                    Accounting1.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    Accounting1.getTemperature();
                    break;
                }
                if (inputMenu1 != 4) system("pause");
            } while (inputMenu1 != 4);
            goto returnpoint;
            break;
        case 2: cout << "³��� �����" << endl;
        returnpointMenuHR:
            menu();
            int inputMenu2;
            do {
                inputMenu2 = getvariant(4);
                switch (inputMenu2) {
                case 1:
                returnpointSettingsHR:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    HRDepartment2.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    HRDepartment2.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    HRDepartment2.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    HRDepartment2.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsHR;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    HRDepartment2.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    HRDepartment2.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ���� ����� - ";
                    HRDepartment2.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    HRDepartment2.getTemperature();
                    break;
                }
                if (inputMenu2 != 4) system("pause");
            } while (inputMenu2 != 4);
            goto returnpoint;
            break;
        case 3: cout << "��-����" << endl;
        returnpointMenuIT:
            menu();
            int inputMenu3;
            do {
                inputMenu3 = getvariant(4);
                switch (inputMenu3) {
                case 1:
                returnpointSettingsIT:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    ITDepartment3.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    ITDepartment3.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    ITDepartment3.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    ITDepartment3.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsIT;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    ITDepartment3.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    ITDepartment3.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � IT-���� - ";
                    ITDepartment3.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    ITDepartment3.getTemperature();
                    break;
                }
                if (inputMenu3 != 4) system("pause");
            } while (inputMenu3 != 4);
            goto returnpoint;
            break;
        case 4: cout << "������" << endl;
        returnpointMenuSERVER:
            menu();
            int inputMenu4;
            do {
                inputMenu4 = getvariant(4);
                switch (inputMenu4) {
                case 1:
                returnpointSettingsSERVER:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    Server4.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    Server4.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    Server4.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    Server4.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsSERVER;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    Server4.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    Server4.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � �������� - ";
                    Server4.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    Server4.getTemperature();
                    break;
                }
                if (inputMenu4 != 4) system("pause");
            } while (inputMenu4 != 4);
            goto returnpoint;
            break;
        case 5: cout << "������ �����" << endl;
        returnpointMenuOFFICE:
            menu();
            int inputMenu5;
            do {
                inputMenu5 = getvariant(4);
                switch (inputMenu5) {
                case 1:
                returnpointSettingsOFFICE:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    WorkOffice5.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    WorkOffice5.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    WorkOffice5.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    WorkOffice5.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsOFFICE;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    WorkOffice5.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    WorkOffice5.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ������ - ";
                    WorkOffice5.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    WorkOffice5.getTemperature();
                    break;
                }
                if (inputMenu5 != 4) system("pause");
            } while (inputMenu5 != 4);
            goto returnpoint;
            break;
        case 6: cout << "ʳ����� ���������" << endl;
        returnpointMenuRR:
            menu();
            int inputMenu6;
            do {
                inputMenu6 = getvariant(4);
                switch (inputMenu6) {
                case 1:
                returnpointSettingsRR:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    RestRoom6.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    RestRoom6.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    RestRoom6.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    RestRoom6.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsRR;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    RestRoom6.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    RestRoom6.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ����� ��������� - ";
                    RestRoom6.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    RestRoom6.getTemperature();
                    break;
                }
                if (inputMenu6 != 4) system("pause");
            } while (inputMenu6 != 4);
            goto returnpoint;
            break;
        case 7: cout << "������ ����������� ���������" << endl;
        returnpointMenuCEO:
            menu();
            int inputMenu7;
            do {
                inputMenu7 = getvariant(4);
                switch (inputMenu7) {
                case 1:
                returnpointSettingsCEO:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    CEORoom7.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    CEORoom7.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    CEORoom7.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    CEORoom7.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsCEO;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    CEORoom7.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    CEORoom7.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ������ ����������� ��������� - ";
                    CEORoom7.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
                    CEORoom7.getTemperature();
                    break;
                }
                if (inputMenu7 != 4) system("pause");
            } while (inputMenu7 != 4);
            goto returnpoint;
            break;
        case 8: cout << "���" << endl;
        returnpointMenuHALL:
            menu();
            int inputMenu8;
            do {
                inputMenu8 = getvariant(4);
                switch (inputMenu8) {
                case 1:
                returnpointSettingsHALL:
                    //cout << "������������ �� �������������" << endl;
                    int defaultSettings;
                    do {
                        system("cls");
                        cout << "1. �� �������" << endl;
                        cout << "2. �� ��������" << endl;
                        cout << "3. ����������� � ����" << endl;
                        defaultSettings = getvariant(3);
                        switch (defaultSettings) {
                            int regionSettings;
                        case 1: cout << "�� �������" << endl;
                            do {
                                regionSettingsMenu();
                                regionSettings = getvariant(5);
                                switch (regionSettings) {
                                case 1:
                                    cout << "������ ������" << endl;
                                    Hall8.setTemperature(25.9);
                                    break;
                                case 2:
                                    cout << "������� ������" << endl;
                                    Hall8.setTemperature(27.4);
                                    break;
                                case 3:
                                    cout << "����� �������������'�" << endl;
                                    Hall8.setTemperature(28.1);
                                    break;
                                case 4:
                                    cout << "����� ��������⳿" << endl;
                                    Hall8.setTemperature(25.2);
                                    break;
                                    if (regionSettings != 5) system("pause");
                                }
                            } while (regionSettings != 5); goto returnpointSettingsHALL;
                            int fSetteings;
                        case 2: cout << "�� ��������" << endl;
                            do {
                                fSettingsMenu();
                                fSetteings = getvariant(4);


                                switch (fSetteings) {
                                case 1:
                                    cout << "1. �������� ����" << endl;
                                    Hall8.setTemperature(21.5);
                                    break;
                                case 2:
                                    cout << "˳��� ���������" << endl;
                                    Hall8.setTemperature(22.6);
                                    break;
                                case 3:
                                    cout << "������� ����" << endl;
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
                    //cout << "�����������" << endl;
                    cout << "����������� � ��� - ";
                    Hall8.getTemperature();
                    break;
                case 3:
                    //cout << "����������� ���������" << endl;
                    int changet = 0;
                    cout << "������ �������� �����������, ��� �� ������ ���������� - ";
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
                    cout << "����������� ������ �� - ";
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