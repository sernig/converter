#include <iostream> 
using namespace std;

const float COMMISSION_RATE = 0.05;
const float USD_RATE = 75.0;
const float EUR_RATE = 85.0;
const float CNY_RATE = 11.0;
const float FAR_RATE = 37.0;
const float JPY_RATE = 0.7;

float convertCurrency(float rubles, float exchangeRate) 
{
    return rubles / exchangeRate;
}

void displayMenu() 
{
    setlocale(LC_ALL, "rus");

    cout << "�������� ������ ��� �������:\n";
    cout << "1. ������\n";
    cout << "2. ����\n";
    cout << "3. ����\n";
    cout << "4. �����\n";
    cout << "5. ����\n";
    cout << "������� ����� ������ (1-5): ";
}

float getExchangeRate(int choice) 
{
    if (choice == 1) return USD_RATE;        // ������ 
    else if (choice == 2) return EUR_RATE;   // ���� 
    else if (choice == 3) return CNY_RATE;   // ���� 
    else if (choice == 4) return FAR_RATE;   // ����� 
    else if (choice == 5) return JPY_RATE;   // ���� 
    return 0.0;                              // �������� ����� 
}

int main() 
{
    setlocale(LC_ALL, "rus");

    do 
    {
        float rubles;
        cout << "������� ����� � ������: ";
        cin >> rubles;

        displayMenu();

        int choice;
        cin >> choice;

        float exchangeRate = getExchangeRate(choice);
        if (exchangeRate == 0.0) 
        {
            cout << "�������� ����� ������.\n";
            continue;
        }

        float commission = rubles * COMMISSION_RATE;
        float amountAfterCommission = rubles - commission;
        float amountBought = convertCurrency(amountAfterCommission, exchangeRate);

        cout << "����� ��������: " << commission << " ������\n";
        cout << "�� ������ ������: " << amountBought << " ������(�) ��������� ������\n";

        cout << "������ �� �� ��������� ��������? (y/n): ";
        char repeat;
        cin >> repeat;

        if (repeat != 'y' && repeat != 'Y') 
        {
            break;
        }

    } while (true);

    cout << "������� �� ������������� ����� ���������� �����!\n";
    return 0;
}