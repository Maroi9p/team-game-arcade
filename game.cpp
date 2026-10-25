#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
// Состояние игры (базовые переменные)
int hp = 100;
int resources = 50; // Деньги / Мана / Патроны / Крышки
int score = 0; // Очки выживания (цель — рекорд)
int turn = 1;
void printHUD() {
 std::cout << "\n================ [ХОД: " << turn << " | СЧЕТ: " << score
<< "] ================\n";
 std::cout << "❤️ Здоровье: " << hp << "/100 |  Ресурсы: " <<
resources << "\n";
 std::cout << "--------------------------------------------------------\n";
}
void riskyOperation() {
 if (rand() % 100 < 50) {
  int scoreReward = 200 + rand() % 301;
  int resourceReward = 20 + rand() % 31;
  resources += resourceReward;
  score += scoreReward;
  std::cout << "\n[УСПЕХ] Куш! +" << scoreReward << " очков и +"
            << resourceReward << " ресурсов.\n";
 } else {
  int damage = 30 + rand() % 21;
  hp -= damage;
  std::cout << "\n[ПРОВАЛ] Операция сорвалась! -" << damage
            << " здоровья.\n";
 }
}
// -------------------------------------------------------------
// [МЕСТО ДЛЯ ФУНКЦИЙ РАЗРАБОТЧИКОВ ИЗ PULL REQUEST'ОВ]
// -------------------------------------------------------------
int main() {
 srand(time(NULL));
 int choice = 0;
 std::cout << ">>> ЗАПУСК СИМУЛЯЦИИ: БИТВА ЗА РЕКОРД <<<\n";
 while (hp > 0) {
 printHUD();
 std::cout << "1. Рискованная операция (Высокая награда / Высокий риск)\n";
 std::cout << "2. База / Лагерь (Лечение и обмен ресурсов)\n";
 std::cout << "3. Особое событие / Рулетка удачи\n";
 std::cout << "0. Сдаться и зафиксировать счет\n";
 std::cout << "Выберите действие >";
 if (!(std::cin >> choice)) break;
 switch (choice) {
 case 1:
 riskyOperation();
 break;
 case 2:
 // [РАЗРАБОТЧИК 2: ПОДКЛЮЧИТ МОДУЛЬ ОТХИЛА (ISSUE #2)]
 std::cout << "\n[!] Модуль лагеря еще в разработке (Issue#2).\n";
 break;
 case 3:
 // [РАЗРАБОТЧИК 3: ПОДКЛЮЧИТ РУЛЕТКУ/БОССА (ISSUE #3)]
 std::cout << "\n[!] Модуль событий еще в разработке (Issue#3).\n";
 break;
 case 0:
 hp = 0;
 break;
 default:
 std::cout << "\nНеизвестная команда!\n";
 break;
 }
 // Каждый успешный ход дает очки выживания
 if (hp > 0) {
 turn++;
 score += 10;
 }
 }
 std::cout << "\n💀 ИГРА ОКОНЧЕНА. Ваш итоговый рекорд: " << score << "очков!\n";
 return 0;
}

 
