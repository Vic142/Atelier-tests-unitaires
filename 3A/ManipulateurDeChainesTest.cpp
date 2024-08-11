#include <gtest/gtest.h>
#include "ManipulateurDeChaines.h"
#include "ChaineVideException.h"

/*
 * Exercices 3A
 * */
class ManipulateurDeChainesTest : public ::testing::Test {
    protected:
        // Vous pouvez ajouter des constantes ici
        const std::string CHAINE_VIDE = "";
        const std::string CHAINE_AVEC_UN_MOT = "Hello";

        const std::string CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS = "Hello there world";
        const int NB_MOTS_CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS = 3;
        const int NB_CARACTERES_CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS = 17;

        const std::string CHAINE_AVEC_CARACTERES_SPECIAUX_ET_PLUSIEURS_MOTS = "Hello$there#world";
        const int NB_MOTS_CHAINE_AVEC_CARACTERES_SPECIAUX_ET_PLUSIEURS_MOTS = 3;

        const std::string CHAINE_SANS_ESPACES = "Hellothereworld";

        const std::string CHAINE_AVEC_MAJUSCULES = "HeLLo THere WorlD";
        const std::string CHAINE_EN_MINUSCULE = "hello there world";
};

TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterCaracteres_AlorsLeResultatEstZero) {
    // Préparation
    std::string chaine = CHAINE_VIDE;

    // Action
    int nbCaracteres = ManipulateurDeChaines::compterCaracteres(chaine);

    // Validation
    EXPECT_EQ(nbCaracteres, 0);
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineNonVide_QuandCompterCaracteres_AlorsLeResultatEstLeBonNombreDeCaracteres) {
    // Préparation
    std::string chaine = CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS;

    // Action
    int nbCaracteres = ManipulateurDeChaines::compterCaracteres(chaine);

    // Validation
    EXPECT_EQ(nbCaracteres, NB_CARACTERES_CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS);

}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecEspaces_QuandSupprimerEspaces_AlorsLesEspacesSontSupprimes) {
    // Préparation
    std::string chaine = CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS;

    // Action
    std::string nouvelleChaine = ManipulateurDeChaines::enleverEspaces(chaine);

    // Validation
    EXPECT_STREQ(nouvelleChaine.c_str(), CHAINE_SANS_ESPACES.c_str());
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineSansEspaces_QuandSupprimerEspaces_AlorsLaChaineResteInchangee) {
    // Préparation
    std::string chaine = CHAINE_SANS_ESPACES;

    // Action
    std::string nouvelleChaine = ManipulateurDeChaines::enleverEspaces(chaine);

    // Validation
    EXPECT_STREQ(nouvelleChaine.c_str(), chaine.c_str());
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMajuscules_QuandConvertirEnMinuscules_AlorsLaChaineEstConvertieEnMinuscules) {
    // Préparation
    std::string chaine = CHAINE_AVEC_MAJUSCULES;

    // Action
    std::string nouvelleChaine = ManipulateurDeChaines::convertirEnMinuscules(chaine);

    // Validation
    EXPECT_STREQ(nouvelleChaine.c_str(), CHAINE_EN_MINUSCULE.c_str());
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineEnMinuscules_QuandConvertirEnMinuscules_AlorsLaChaineResteInchangee) {
    // Préparation
    std::string chaine = CHAINE_EN_MINUSCULE;

    // Action
    std::string nouvelleChaine = ManipulateurDeChaines::convertirEnMinuscules(chaine);

    // Validation
    EXPECT_STREQ(nouvelleChaine.c_str(), chaine.c_str());
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineVide_QuandCompterNombreDeMots_AlorsExceptionEstLevee) {
    // Préparation
    std::string chaine = CHAINE_VIDE;

    // Action et Validation
    EXPECT_THROW(ManipulateurDeChaines::compterNombreDeMots(chaine), ChaineVideException);
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecUnMot_QuandCompterNombreDeMots_AlorsLeCompteEstUn) {
    // Préparation
    std::string chaine = CHAINE_AVEC_UN_MOT;

    // Action
    int nbMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nbMots, 1);
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParEspaces_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation
    std::string chaine = CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS;

    // Action
    int nbMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nbMots, NB_MOTS_CHAINE_AVEC_ESPACES_ET_PLUSIEURS_MOTS);
}

// TODO: Écrire le test suivant avec le principe Préparation-Action-Validation
TEST_F(ManipulateurDeChainesTest, EtantDonneChaineAvecMotsSeparesParCaracteresSpeciaux_QuandCompterNombreDeMots_AlorsLeCompteEstCorrect) {
    // Préparation
    std::string chaine = CHAINE_AVEC_CARACTERES_SPECIAUX_ET_PLUSIEURS_MOTS;

    // Action
    int nbMots = ManipulateurDeChaines::compterNombreDeMots(chaine);

    // Validation
    EXPECT_EQ(nbMots, NB_MOTS_CHAINE_AVEC_CARACTERES_SPECIAUX_ET_PLUSIEURS_MOTS);
}
