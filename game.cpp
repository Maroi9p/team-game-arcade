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
void playRoulette() {
 int roll = rand() % 20 + 1;
 std::cout << "\n🎲 Вы бросаете D20... Выпало: " << roll << "\n";

 if (roll == 1) {
  std::cout << "💀 Критическое проклятие! -30 здоровья и -20 очков.\n";
  hp -= 30;
  score -= 20;
  if (score < 0) score = 0;
 } else if (roll == 20) {
  std::cout << "✨ ДЖЕКПОТ! +100 очков и +20 ресурсов!\n";
  score += 100;
  resources += 20;
 } else {
  int multiplier = roll <= 5 ? 1 : roll <= 10 ? 2 : roll <= 15 ? 3 : 4;
  int reward = multiplier * 10;
  std::cout << "🍀 Множитель x" << multiplier << "! Вы получаете +"
			<< reward << " очков.\n";
  score += reward;
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
 // [РАЗРАБОТЧИК 1: ПОДКЛЮЧИТ ФУНКЦИЮ РИСКА (ISSUE #1)]
 std::cout << "\n[!] Модуль риска еще в разработке (Issue#1).\n";
 break;
 case 2:
 // [РАЗРАБОТЧИК 2: ПОДКЛЮЧИТ МОДУЛЬ ОТХИЛА (ISSUE #2)]
 std::cout << "\n[!] Модуль лагеря еще в разработке (Issue#2).\n";
 break;
 case 3:
 playRoulette();
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

 
