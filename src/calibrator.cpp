// #include <Arduino.h>
// #include <GyverHX711.h>

// #define CLB_LIST 5 //Кількість обʼєктів для зважування
// double k[CLB_LIST] = {1, 1, 1, 1, 1}; // тут їх коефіцієнти(на початку поки не рухай)
// double weight_list[CLB_LIST] = {10, 100, 1000, 5000, 10000}; //Вага кожного обʼєкта в грамах
// long a; // буферна змінна

// GyverHX711 sensor(2, 3, HX_GAIN64_A);

// void waitForInput()
// {
//     while(true)
//     {
//         if(Serial.available())
//         {
//             char command = (char)Serial.read();
//             if(command == '1')
//             {
//                 while(Serial.available())
//                 {
//                     Serial.read();
//                 }
//                 return;
//             }
//         } 
//         else 
//         {
//             while(Serial.available())
//             {
//                 Serial.read();
//             }
//         }
//     }
// }

// struct Index
// {
// private:
//     int current = 0;
//     int maxValue;

// public:
//     Index(int max_value) : maxValue(max_value) {}
//     int next()
//     {
//         current++;
//         if (current >= maxValue)
//         {
//             current = 0;
//         }
//         return current;
//     }
//     int currentIndex()
//     {
//         return current;
//     }
// };
// Index index = Index(CLB_LIST);

// void setup()
// {
//     Serial.begin(9600);
//     delay(1000);
//     sensor.tare();

//     delay(500);
//     for (int i = 0; i < CLB_LIST; i++)
//     {
//         Serial.print("-------------------\nКалібровка для:"); Serial.println(weight_list[i]);
//         Serial.println(" \tПостав вагу і введи '1' щоб продовжити");
//         waitForInput();
//         Serial.print("\tАктивний коефіцієнт: "); Serial.println(k[i]);
//         a = sensor.read();
//         Serial.print("\tДані з сенсора: "); Serial.println(a / k[i]);
//         Serial.println("\tКоррекція");
//         k[i] = a / k[i];
//         Serial.print("\tНове значення коефіцієнта: "); Serial.println(k[i]);
//         a = sensor.read();
//         Serial.print("\tНові дані з сенсора: "); Serial.println(a / k[i]);
//         Serial.print("\tПохибка: "); Serial.println((a / k[i]) - weight_list[i]);
//         Serial.print("\tКалібровка для ваги "); Serial.print(weight_list[i]); Serial.println("гр закінчена\nВведи '1' щоб продовжити");
//         waitForInput();
//     }
//     Serial.println("\tКалібровка закінчена. Нові коефіцієнти:");
//     for (int i = 0; i < CLB_LIST; i++)
//     {
//         Serial.print(weight_list[i]); Serial.println("\t"); 
//     }
//     for (int i = 0; i < CLB_LIST; i++)
//     {
//         Serial.print(k[i]); Serial.println("\t"); 
//     }
// }

// void loop() {}