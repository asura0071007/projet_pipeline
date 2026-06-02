#include <iostream>
#include <string>

// Codes ANSI pour les couleurs
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string RED = "\033[31m";
const std::string BLUE = "\033[34m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

void afficherInterface(int scoreEquipe1, int scoreEquipe2) {
    // Nettoie l'écran du terminal pour faire un effet de rafraîchissement
    std::cout << "\033[2J\033[1;1H";
    
    std::cout << BOLD << YELLOW << "=========================================" << RESET << std::endl;
    std::cout << BOLD << "      🏆 TOURNOI ESPORT - FINALE 🏆      " << RESET << std::endl;
    std::cout << BOLD << YELLOW << "=========================================" << RESET << std::endl;
    std::cout << "\n";
    std::cout << "      " << BLUE << "DOMICILE" << RESET << "       VS       " << RED << "EXTÉRIEUR" << RESET << std::endl;
    std::cout << "         " << BOLD << GREEN << scoreEquipe1 << RESET << "                 " << BOLD << GREEN << scoreEquipe2 << RESET << std::endl;
    std::cout << "\n";
    std::cout << BOLD << YELLOW << "=========================================" << RESET << std::endl;
    std::cout << " 1. ⚽ But Domicile (+1)" << std::endl;
    std::cout << " 2. ⚽ But Extérieur (+1)" << std::endl;
    std::cout << " 3. 🛑 Fin du match (Quitter)" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "▶ Choisissez une action (1, 2 ou 3) : ";
}

int main() {
    int score1 = 0;
    int score2 = 0;
    int choix = 0;

    // Boucle interactive
    while (choix != 3) {
        afficherInterface(score1, score2);
        std::cin >> choix;

        if (choix == 1) {
            score1++;
        } else if (choix == 2) {
            score2++;
        }
    }

    // Affichage final
    std::cout << "\nCoup de sifflet final ! Score officiel : " 
              << BOLD << BLUE << "Domicile " << score1 << RESET << " - " 
              << BOLD << RED << score2 << " Extérieur" << RESET << "\n\n";
    return 0;
}