#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <map>

class Compte
{
private:
    double solde;

    // Déclaration des transactions
    std::map<std::string, double> transactions;

    // Déclaration de la fonction enregistrerTransaction
    void enregistrerTransaction(double montant, const std::string &nom)
    {
        transactions[nom] += montant;
    }

public:
    // Constructeur
    Compte(double solde = 0.0) : solde(solde) {}

    // Fonction depot
    void deposerArgent(double montant, const std::string &nomTransaction)
    {
        solde += montant;
        enregistrerTransaction(montant, nomTransaction);
    }
    // Fonction retrait
    void retirerArgent(double montant, const std::string &nomTransaction)
    {
        if (montant <= solde)
        {
            solde -= montant;
            enregistrerTransaction(-montant, nomTransaction);
        }
        else
        {
            std::cout << "Solde insuffisant" << std::endl;
        }
    }

    // Fonction affichage du solde
    void afficherSolde() const
    {
        std::cout << "Solde actuel : " << solde << std::endl;
    }

    // Fonction d'affichage de l'historique des transactions
    void afficherTransactions() const
    {
        std::cout << "Historique des transactions :" << std::endl;
        for (const auto &transaction : transactions)
        {
            std::cout << "- " << transaction.first << " : " << transaction.second << " euros" << std::endl;
        }
    }

    void afficherMenu() const
    {
        std::cout << "Menu :\n";
        std::cout << "1. Afficher le solde\n";
        std::cout << "2. Déposer de l'argent\n";
        std::cout << "3. Retirer de l'argent\n";
        std::cout << "4. Afficher l'historique des transactions\n";
        std::cout << "0. Quitter\n";
    }
    void effectuerOpération()
    {
        int choix;
        double montant;
        std::string nomTransaction;

        afficherMenu();
        std::cout << "Effectuez votre choix : ";
        std::cin >> choix;

        switch (choix)
        {
        case 1:
            afficherSolde();
            break;

        case 2:
            std::cout << "Entrez le montant à déposer : ";
            std::cin >> montant;
            std::cout << "Entrez le nom de votre transaction : ";
            std::cin >> nomTransaction;
            deposerArgent(montant, nomTransaction);
            break;

        case 3:
            std::cout << "Entrez le montant à retirer : ";
            std::cin >> montant;
            std::cout << "Entrez le nom de votre transaction : ";
            std::cin >> nomTransaction;
            retirerArgent(montant, nomTransaction);
            break;

        case 4:
            afficherTransactions();
            break;

        case 0:
            std::cout << "Au revoir ! \n";

        default:
            std::cout << "Choix Invalide. Veuillez réessayer.\n";
            break;
        }
    }
    /*
        // Méthodes pour sauvegarder et charger depuis un fichier
        void sauvegarderDansFichier(const std::string &nomFichier) const
        {
            std::ofstream fichier(nomFichier);
            if (fichier.is_open())
            {
                fichier << solde << "\n";
                // Écrire d'autres données si nécessaire
                fichier.close();
            }
        }

        void chargerDepuisFichier(const std::string &nomFichier)
        {
            std::ifstream fichier(nomFichier);
            if (fichier.is_open())
            {
                fichier >> solde;
                // Lire d'autres données si nécessaire
                fichier.close();
            }
        }*/
};

int main()
{
    // Création du compte courant
    Compte Compte_courant;

    // Déclaration character continuer
    std::string continuer;

    // Déclaration variable nom transactions
    std::string nomTransaction;

    // Boucle do pour les opérations
    do
    {
        Compte_courant.effectuerOperation();

        std::cout << "Voulez vous faire une autre opération ? : (Oui/Non) : ";
        std::cin >> continuer;

    } while (continuer == "Oui" || continuer == "oui");

    return 0;
}
// cd "/Users/elie/Desktop/COURS/Code/C++ Projects/Comptes/" && g++ Compte.cpp -o Compte && "/Users/elie/Desktop/COURS/Code/C++ Projects/Comptes/"Compte
