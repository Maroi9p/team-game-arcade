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
// Функция для лагеря (Case 2)
void handleCamp() {
    const int BASE_HEAL_COST = 5;      // Базовая стоимость 1 единицы лечения
    const int BONUS_CHANCE = 30;       // Шанс бонуса в процентах
    
    // Случайное количество лечения (от 15 до 40 HP)
    int healAmount = rand() % 26 + 15; 
    
    // Сколько здоровья реально нужно (чтобы не лечить сверх максимума)
    int neededHp = 100 - hp;
    if (neededHp <= 0) {
        std::cout << "\n[ЛАГЕРЬ] Вы полностью здоровы! Отдыхать пока не нужно.\n";
        return;
    }

    // Корректируем лечение, если оно больше необходимого
    if (healAmount > neededHp) {
        healAmount = neededHp;
    }

    // Расчет стоимости лечения
    int cost = healAmount * BASE_HEAL_COST;

    if (resources < cost) {
        std::cout << "\n[ЛАГЕРЬ] Недостаточно ресурсов для лечения!\n";
        std::cout << "Нужно: " << cost << ", у вас: " << resources << "\n";
        // Можно добавить вариант "Дешевое лечение" или просто отказ
        return;
    }

    // Применяем лечение
    hp += healAmount;
    resources -= cost;
    
    std::cout << "\n[ЛАГЕРЬ] Вы отдохнули и восстановили " << healAmount << " ❤️ HP.\n";
    std::cout << "Потрачено ресурсов: " << cost << ". Осталось: " << resources << "\n";

    // Шанс на бонусный лут/очки
    if (rand() % 100 < BONUS_CHANCE) {
        int bonusScore = rand() % 50 + 20;
        score += bonusScore;
        std::cout << "[ЛАГЕРЬ] 🎉 Бонус! Вы нашли тайник и получили +" << bonusScore << " очков!\n";
    }
}

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
  handleCamp();
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