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

    cout << "Выберите валюту для покупки:\n";
    cout << "1. Доллар\n";
    cout << "2. Евро\n";
    cout << "3. Юань\n";
    cout << "4. Фарит\n";
    cout << "5. Йена\n";
    cout << "Введите номер валюты (1-5): ";
}

float getExchangeRate(int choice) 
{
    if (choice == 1) return USD_RATE;        // Доллар 
    else if (choice == 2) return EUR_RATE;   // Евро 
    else if (choice == 3) return CNY_RATE;   // Юань 
    else if (choice == 4) return FAR_RATE;   // Фарит 
    else if (choice == 5) return JPY_RATE;   // Йена 
    return 0.0;                              // Неверный выбор 
}

int main() 
{
    setlocale(LC_ALL, "rus");

    do 
    {
        float rubles;
        cout << "Введите сумму в рублях: ";
        cin >> rubles;

        displayMenu();

        int choice;
        cin >> choice;

        float exchangeRate = getExchangeRate(choice);
        if (exchangeRate == 0.0) 
        {
            cout << "Неверный выбор валюты.\n";
            continue;
        }

        float commission = rubles * COMMISSION_RATE;
        float amountAfterCommission = rubles - commission;
        float amountBought = convertCurrency(amountAfterCommission, exchangeRate);

        cout << "Сумма комиссии: " << commission << " рублей\n";
        cout << "Вы можете купить: " << amountBought << " единиц(ы) выбранной валюты\n";

        cout << "Хотите ли вы повторить операцию? (y/n): ";
        char repeat;
        cin >> repeat;

        if (repeat != 'y' && repeat != 'Y') 
        {
            break;
        }

    } while (true);

    cout << "Спасибо за использование моего конвертера валют!\n";
    return 0;
}