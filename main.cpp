#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int scoreDomicile = 0;
    int scoreExterieur = 0;

    std::cout << "[SYSTEME] Démarrage du serveur de match Esport en arrière-plan..." << std::endl;

    // Boucle infinie : le match tourne tout seul comme un vrai serveur
    for(int minute = 1; minute <= 90; minute += 5) {
        std::cout << "[LOG] Minute du match : " << minute << "'" << std::endl;

        int evenement = std::rand() % 10; // Génère un nombre entre 0 et 9

        if (evenement == 1) {
            scoreDomicile++;
            std::cout << "[METRIC] BUT_DOMICILE | Score: " << scoreDomicile << " - " << scoreExterieur << std::endl;
        } else if (evenement == 2) {
            scoreExterieur++;
            std::cout << "[METRIC] BUT_EXTERIEUR | Score: " << scoreDomicile << " - " << scoreExterieur << std::endl;
        } else if (evenement == 3) {
            std::cout << "[ALERTE] Carton Rouge distribué !" << std::endl;
        } else {
            std::cout << "[INFO] Possession de balle en cours..." << std::endl;
        }

        // Le programme attend 2 secondes avant la prochaine action
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "[SYSTEME] Fin du match. Arrêt du serveur." << std::endl;
    return 0;
}