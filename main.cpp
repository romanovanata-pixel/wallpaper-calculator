#include <math.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
double count_sum_rashod(
    int nomber_wall, 
    double roll_width, 
    vector<double> walls_length, 
    vector<double> walls_height
) {
    vector<double> rashod_vec;
    
    //вектор с расходом обоев на каждую стену по отдельности в метрах
    for (int i = 0; i < nomber_wall; ++i) {
        double rashod = (walls_length[i]/roll_width)*walls_height[i];
        rashod_vec.push_back(rashod);
    }
    
    // сумма значений вектора rashod_vec (суммарный расход обоев на все стены)
    double sum_rashod = 0;
    for(auto i:rashod_vec)
        sum_rashod +=i;
        
    return sum_rashod;    
}

double count_sum_empty_doors(int nomber_door, vector<double> door_length, vector<double> door_height) {
    //площадь выпадающих участков
    double sum_empty_door = 0;
    for (int i = 0; i < nomber_door; ++i) {
        double empty_door = door_length[i] * door_height[i];
        sum_empty_door += empty_door;
    }
    
    return sum_empty_door;
}

double count_sum_empty_winds(vector<double> wind_length, vector<double> wind_height, int nomber_wind ){
    double sum_empty_wind = 0;
    for (int i = 0; i < nomber_wind; ++i) {
        double empty_wind = wind_length[i] * wind_height[i];
        sum_empty_wind += empty_wind;
    }
   return sum_empty_wind;
}

int int_input(string message) {
    int input;
    
    cout << message << endl;
    cin >> input;
    
    while(input < 0 || input > 100) {
        if (input <= 0) {
            cout << "Ошибка! Число не может быть меньше 0" << endl;
        }
        
        if (input > 100) {
            cout << "Ошибка! Число не может быть больше 100" << endl;
        }
        
        cout << message << endl;
        cin >> input;
    }
    
    return input;
}


int main()
{
    double roll_length, roll_width, length, height, rashod, doors_length, winds_length, doors_height, winds_height;
    int a;
    vector<double> walls_length, walls_height, kol_polos, door_length, door_height, wind_height, wind_length;
    
    //ввод данных пользователем
    cout << "Введите длину рулона выбранных обоев (в метрах)" << endl;
    cin >> roll_length;
    cout << "Введите ширину рулона выбранных обоев (в метрах)" << endl;
    cin >> roll_width;
    
    int nomber_wall = int_input("Введите количество стен, которые необходимо покрыть обоями");
    
    //ввод данных пользователем + последовательная запись ширины и высоты комнаты в веторы
    for (int i = 0; i < nomber_wall; ++i) {
        cout << "Введите ширину " << i+1 << " стены (в метрах)" << endl;
        cin >> length;
        walls_length.push_back(length);
        cout << "Введите высоту " << i+1 << " стены (в метрах)" << endl;
        cin >> height;
        walls_height.push_back(height);
    }
    
    int nomber_door = int_input("Введите количество дверей в комнате");
    
    //ввод данных пользователем + последовательная запись ширины и высоты дверей в веторы
    for (int i = 0; i < nomber_door; ++i) {
        cout << "Введите ширину " << i+1 << " двери (в метрах)" << endl;
        cin >> doors_length;
        door_length.push_back(doors_length);
        cout << "Введите высоту " << i+1 << " двери (в метрах)" << endl;
        cin >> doors_height;
        door_height.push_back(doors_height);
    }
    
    
    int nomber_wind = int_input("Введите количество окон в комнате");
    
    //ввод данных пользователем + последовательная запись ширины и высоты окон в веторы
    for (int i = 0; i < nomber_door; ++i) {
        cout << "Введите ширину " << i+1 << " окна (в метрах)" << endl;
        cin >> winds_length;
        wind_length.push_back(winds_length);
        cout << "Введите высоту " << i+1 << " окна (в метрах)" << endl;
        cin >> winds_height;
        wind_height.push_back(winds_height);
    }
    
    double sum_rashod = count_sum_rashod(nomber_wall, roll_width, walls_length, walls_height);
    double sum_empty_doors = count_sum_empty_doors(nomber_door, door_length, door_height);
    double sum_empty_winds = count_sum_empty_winds(wind_length, wind_height, nomber_wind);
    
    double empty_area = sum_empty_doors + sum_empty_winds;
    
    //необходимое количество рулонов
    double rec_rolls = (sum_rashod - empty_area) / roll_length;
    
    double pl = sum_rashod - empty_area;
    cout << "Площадь, котоую необходимо покрыть обоями - " <<  pl << " квадратных метров" << endl;
    
    cout << "Необходимое количество рулонов - " << ceil(rec_rolls)<< endl;
    
    double price;
    cout << "Введите цену обоев за рулон в рублях" << endl;
    cin >> price;
    
    double total_price =  ceil(rec_rolls) * price;
    
    cout << "Цена за рулоны составит " << total_price << " руб.";
}

