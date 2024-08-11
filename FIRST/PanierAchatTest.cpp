#include <gtest/gtest.h>
#include "PanierAchat.h"
#include "LecteurDeConfigurations.cpp"

/*
 * Exercices FIRST
 * */
class PanierAchatTest : public ::testing::Test {
    protected:
        PanierAchat panierAchat;
        // Vous pouvez ajouter des constantes ici
        const double PRIX_ARTICLE_1_INITIAL = 100.0;
        const double PRIX_ARTICLE_2_INITIAL = 46.4;
        const double POURCENTAGE_REMISE = 25.0;
        const double PRIX_FINAL_1_APRES_REMISE = PRIX_ARTICLE_1_INITIAL * (100.0 - POURCENTAGE_REMISE) / 100.0;
        const std::string NOM_ARTICLE_1 = "Article X";
        const std::string NOM_ARTICLE_2 = "Article blabla";
};

// TODO: Trouvez le principe non respecté et corrigez le test suivant
// principe non respecté = Fast car beaucoup trop d'articles et cela ne rend pas le test plus important
// on va réduire le nombre d'articles
TEST_F(PanierAchatTest, EtantDonneDesArticles_QuandAjouterArticles_AlorsArticlesSontAjoutesAuPanier) {
    // Action
    //const int articles = 100000000;
    const int articles = 8;
    for (int i = 0; i < articles; ++i) {
        panierAchat.ajouterArticle("Article" + std::to_string(i), 10.0);
    }

    // Validation
    EXPECT_EQ(panierAchat.reqArticles().size(), articles);
}

// TODO: Trouvez le principe non respecté et corrigez le test suivant
// principe non respecté = Independant car le pourcentage de la remise appliqué dépend de la fonction lirePourcentageRemise
// et si son comportement devient invalide alors le test est invalidé. Cette fonction n'ayant aucun rapport avec le
// comportement de la fonction qui applique la remise, cela rend le test dépendant d'autres tests et fonctions
// on va supprimer l'appel de cette fonction et remplacer la valeur renvoyée par celle-ci par une valeur arbitraire

TEST_F(PanierAchatTest, EtantDonneUnPanierEtUnArticle_QuandAppliquerRemise_AlorsRemiseEstAppliquee) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE_1, PRIX_ARTICLE_1_INITIAL);

    // Action
    // double pourcentageRemise = LecteurDeConfigurations::lirePourcentageRemise();
    double pourcentageRemise = POURCENTAGE_REMISE;
    panierAchat.appliquerRemise(NOM_ARTICLE_1, pourcentageRemise);

    const std::vector<Article>& articles = panierAchat.reqArticles();
    Article articleAvecRemise;
    for (const auto& article : articles) {
        if (article.nom == NOM_ARTICLE_1) {
            articleAvecRemise = article;
        }
    }

    // Validation
    EXPECT_EQ(articleAvecRemise.prix, PRIX_FINAL_1_APRES_REMISE);
}

// TODO: Trouvez le principe non respecté et corrigez le test suivant
// principe non respecté = Self-validating car il n'y a aucun assert qui permet de savoir si le comportement obtenu
// est celui attendu ou non
// on va ajouter un EXPECT_ pour tester le comportement souhaité

TEST_F(PanierAchatTest, EtantDonneUnPanierAvecUnArticle_QuandAppliquerRemise_AlorsRemiseEstAppliquee) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE_1, PRIX_ARTICLE_1_INITIAL);

    // Action
    panierAchat.appliquerRemise(NOM_ARTICLE_1, POURCENTAGE_REMISE);

    // Validation
    const std::vector<Article>& articles = panierAchat.reqArticles();
    Article articleAvecRemise;
    for (const auto& article : articles) {
        if (article.nom == NOM_ARTICLE_1) {
            articleAvecRemise = article; //ajouté
            //std::cout << "Prix de remise pour Article X: " << article.prix << std::endl;
            break;
        }
    }

    EXPECT_EQ(articleAvecRemise.prix, PRIX_FINAL_1_APRES_REMISE);
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierVide_QuandReqPrixTotal_AlorsPrixTotalEstZero) {
    // Préparation

    // Action
    double prixPanier = panierAchat.reqPrixTotal();

    // Validation
    EXPECT_EQ(prixPanier, 0);
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierAvecPlusieursArticles_QuandReqPrixTotal_AlorsPrixTotalEstLaSommeDuPrixDesArticles) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE_1, PRIX_ARTICLE_1_INITIAL);
    panierAchat.ajouterArticle(NOM_ARTICLE_2, PRIX_ARTICLE_2_INITIAL);

    // Action
    double prixPanier = panierAchat.reqPrixTotal();

    // Validation
    EXPECT_EQ(prixPanier, PRIX_ARTICLE_1_INITIAL + PRIX_ARTICLE_2_INITIAL);
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierAvecUnArticle_QuandSupprimerArticle_AlorsArticleEstSupprime) {
    // Préparation
    panierAchat.ajouterArticle(NOM_ARTICLE_1, PRIX_ARTICLE_1_INITIAL);

    // Action
    panierAchat.supprimerArticle(NOM_ARTICLE_1);
    const std::vector<Article> listeArticles = panierAchat.reqArticles();

    // Validation
    EXPECT_EQ(listeArticles.size(), 0);
}

// TODO: Écrire le test suivant avec les principes vues dans l'atelier
TEST_F(PanierAchatTest, EtantDonneUnPanierSansArticle_QuandSupprimerArticle_AlorsExceptionEstLancee) {
    // Préparation

    // Action + Validation
    EXPECT_THROW(panierAchat.supprimerArticle(NOM_ARTICLE_1), std::runtime_error);
}
