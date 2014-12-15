/*    This file is part of clim_city
      Copyright (C) 2014  Julien Thevenon ( julien_thevenon at yahoo.fr )

      This program is free software: you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation, either version 3 of the License, or
      (at your option) any later version.

      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.

      You should have received a copy of the GNU General Public License
      along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "clim_city.h"

#include "clim_city_motor.h"
#include "clim_city_situation_analyzer.h"

#include "action.h"
#include "sous_secteur.h"

#include <assert.h>

using namespace std;

clim_city::clim_city(void):FSM<clim_city_situation,clim_city_transition>("clim_city",new clim_city_motor(), new clim_city_situation_analyzer())
{
  setSituation(new clim_city_situation());
  
}

void clim_city::configure(void)
{
  action *l_action = NULL;
  sous_secteur *l_sous_secteur = NULL;

  l_sous_secteur = new sous_secteur("general");
  addAction(new action("next year",l_sous_secteur,-8,-10,-3));

  //--------------------------------
  //- Secteur Habitat et tertiaire -
  //--------------------------------
  // Habitat
  l_sous_secteur = new sous_secteur("Habitat");
  addAction(new action("Creer une association citoyenne",l_sous_secteur,0,0,6));
  addAction(new action("Maitriser la consommation",l_sous_secteur,0,0,10));
  addAction(new action("S equiper d appareils economes",l_sous_secteur,0,0,10));
  addAction(new action("Renover et isoler les habitations",l_sous_secteur,8,0,14));
  addAction(new action("Confort d ete",l_sous_secteur,2,0,6));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,4,0,8));
  addAction(new action("Chauffe eau solaire",l_sous_secteur,3,0,6));

  l_action = new action("Poeles a bois",l_sous_secteur,3,0,6);
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  addAction(l_action);

  addAction(new action("Pompes a chaleur",l_sous_secteur,4,0,8));
  addAction(new action("Trier les dechets",l_sous_secteur,0,0,6));
  addAction(new action("Compostage individuel",l_sous_secteur,0,0,6));

  // Supermarche
  l_sous_secteur = new sous_secteur("Supermarche");
  addAction(new action("Eco gestes",l_sous_secteur,0,3,0));
  addAction(new action("Eclairage",l_sous_secteur,0,4,0));
  addAction(new action("Isolation des batiments",l_sous_secteur,1,5,0));
  addAction(new action("Toiture vegetale",l_sous_secteur,0,4,0));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,2,4,0));
  addAction(new action("Recyclage",l_sous_secteur,0,4,0));
  addAction(new action("Generaliser l etiquette energie",l_sous_secteur,2,2,4));
  addAction(new action("Etiquette info clim",l_sous_secteur,2,4,4));
  addAction(new action("Produits locaux et de saisons",l_sous_secteur,2,2,4));
  addAction(new action("Commerces de proximite",l_sous_secteur,2,2,4));

  // Ecole
  l_sous_secteur = new sous_secteur("Ecole");
  addAction(new action("Chasser le gaspi a l ecole",l_sous_secteur,2,2,2));
  addAction(new action("Eco energie",l_sous_secteur,3,0,0));
  addAction(new action("Mon ecole ne rechauffe pas la planete",l_sous_secteur,5,0,0));
  addAction(new action("Chauffe eau solaire collectif",l_sous_secteur,4,0,0));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,4,0,0));
  addAction(new action("Pedibus",l_sous_secteur,0,1,3));
  addAction(new action("Cyclobus",l_sous_secteur,0,1,3));
  addAction(new action("Ramassage scolaire",l_sous_secteur,4,0,0));

  l_action = new action("Pile a combustible",l_sous_secteur,5,0,0); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  // Universite
  l_sous_secteur = new sous_secteur("Universite");
  addAction(new action("Fac econome",l_sous_secteur,2,2,2));
  addAction(new action("Investir dans des appareils economes",l_sous_secteur,6,0,0));
  addAction(new action("Une nouvelle enveloppe",l_sous_secteur,10,0,0));
  addAction(new action("Climatisation durable",l_sous_secteur,4,0,0));

  l_action = new action("Chaufferie bois",l_sous_secteur,6,0,0);
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  addAction(l_action);
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,5,0,0));
  addAction(new action("Statoeolienne",l_sous_secteur,5,0,0));
  addAction(new action("Tri des dechets",l_sous_secteur,2,2,4));

  l_action = new action("Pile a combustible",l_sous_secteur,8,0,0);
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  // Bureaux
  l_sous_secteur = new sous_secteur("Bureaux");
  addAction(new action("Gestes economes",l_sous_secteur,0,2,0));
  addAction(new action("Choisir des equipements economes",l_sous_secteur,0,3,0));
  addAction(new action("Renover les facades et les toitures",l_sous_secteur,4,12,0));
  addAction(new action("Protections solaires",l_sous_secteur,2,4,0));
  addAction(new action("Chauffe eau solaire collectif",l_sous_secteur,2,4,0));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,2,4,0));
  addAction(new action("Tri des dechets recyclage",l_sous_secteur,0,5,0));
  addAction(new action("Mise en place d un PDE",l_sous_secteur,0,3,0));
  addAction(new action("Mise en place d un PDA",l_sous_secteur,0,3,0));

  l_action = new action("Pile a combustible",l_sous_secteur,5,0,0); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  // Hopital
  l_sous_secteur = new sous_secteur("Hopital");
  addAction(new action("Formation du personnel",l_sous_secteur,2,2,0));
  addAction(new action("Nouveau materiel",l_sous_secteur,3,3,0));
  addAction(new action("Meilleure isolation",l_sous_secteur,6,2,0));
  addAction(new action("Hopital vegetal",l_sous_secteur,2,4,0));
  addAction(new action("Chauffe eau solaire collectif",l_sous_secteur,2,2,0));

  l_action = new action("Chaufferie bois",l_sous_secteur,4,4,0); 
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  addAction(l_action);
 
  addAction(new action("Panneaux solaires photo voltaiques",l_sous_secteur,2,2,0));
  addAction(new action("Tri des dechets hospitaliers",l_sous_secteur,3,3,0));
  addAction(new action("Plan canicule",l_sous_secteur,3,1,0));
  addAction(new action("Surveillance nouvelles maladies",l_sous_secteur,2,2,0));

  l_action = new action("Pile a combustible",l_sous_secteur,5,0,0); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  // Gare
  l_sous_secteur = new sous_secteur("Gare");
  addAction(new action("Ameliorer la gare urbaine",l_sous_secteur,8,4,0));
  addAction(new action("Renouvelec",l_sous_secteur,4,2,0));
  addAction(new action("Travaux d isolation",l_sous_secteur,8,2,0));

  l_action = new action("Chaufferie bois",l_sous_secteur,4,4,0); 
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  addAction(l_action);

  addAction(new action("Gare solaire",l_sous_secteur,4,2,0));
  addAction(new action("Bornes de tri",l_sous_secteur,2,0,2));
  addAction(new action("Campagne de com pour les transports en commun",l_sous_secteur,4,0,0));

  //Aeroport
  l_sous_secteur = new sous_secteur("Aeroport");
  addAction(new action("Aeroecolo",l_sous_secteur,1,4,0));
  addAction(new action("Eclairage durable",l_sous_secteur,0,4,0));
  addAction(new action("Isolation du Terminal 1",l_sous_secteur,3,6,0));
  addAction(new action("Nouveau systeme de climatisation",l_sous_secteur,2,4,0));

  l_action = new action("Chaufferie bois",l_sous_secteur,3,3,0); 
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  addAction(l_action);

  addAction(new action("Toiture solaire",l_sous_secteur,3,3,0));
  addAction(new action("Tri des dechets",l_sous_secteur,0,2,2));

  l_action = new action("Pile a combustible",l_sous_secteur,5,5,0); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  // Hotels
  l_sous_secteur = new sous_secteur("Hotels");
  addAction(new action("Hotels economes",l_sous_secteur,0,3,0));
  addAction(new action("Achat d appareils",l_sous_secteur,0,4,0));
  addAction(new action("Isolation des batiments",l_sous_secteur,2,6,0));
  addAction(new action("Changement des systemes de climatisation",l_sous_secteur,0,4,0));
  addAction(new action("Chauffe eau solaire collectif",l_sous_secteur,2,4,0));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,2,4,0));
  addAction(new action("Air rotor system",l_sous_secteur,2,3,0));
  addAction(new action("Tri des déchets",l_sous_secteur,0,3,0));

  l_action = new action("Pile a combustible",l_sous_secteur,2,8,0); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  addAction(new action("Construire un hotel",l_sous_secteur,4,12,0));

  // Stade
  l_sous_secteur = new sous_secteur("Stade");
  addAction(new action("Formation des employes",l_sous_secteur,0,2,0));
  addAction(new action("Changement des projecteurs",l_sous_secteur,6,2,0));
  addAction(new action("Toiture solaire",l_sous_secteur,8,2,0));
  addAction(new action("Nouveau systeme de chauffage",l_sous_secteur,2,2,0));

  //--------------------------------
  //- Secteur production d energie -
  //--------------------------------
  // Central thermique
  l_sous_secteur = new sous_secteur("Centrale Thermique");

  addAction(new action("Passage au fioul",l_sous_secteur,0,10,0));
  addAction(new action("Cogeneration au gaz naturel",l_sous_secteur,0,12,0));
  addAction(new action("Recherche capture et stockage de CO2",l_sous_secteur,5,5,0));

  l_action = new action("Captage de CO2",l_sous_secteur,8,10,0); 
  l_action->addDependancy("Recherche capture et stockage de CO2","Centrale Thermique");
  addAction(l_action);

  l_action = new action("Centrale biomasse",l_sous_secteur,10,12,0); 
  l_action->addDependancy("Lancement de la filiere Bois Energie","Sylviculture");
  l_action->addDependancy("Augmentation filiere Bois Energie","Sylviculture");
  addAction(l_action);

  // Centrale eolienne
  l_sous_secteur = new sous_secteur("Centrale Eolienne");
  addAction(new action("Amelioration de la puissance des eoliennes terrestres existantes",l_sous_secteur,2,4,0));
  addAction(new action("Recherche des sites eoliens de clim city",l_sous_secteur,2,2,0));

  l_action = new action("Parc eolien site 1",l_sous_secteur,5,8,0); 
  l_action->addDependancy("Recherche des sites eoliens de clim city","Centrale solaire");
  addAction(l_action);

  l_action = new action("Parc eolien site 2",l_sous_secteur,4,6,0); 
  l_action->addDependancy("Recherche des sites eoliens de clim city","Centrale solaire");
  addAction(l_action);

  l_action = new action("Implantation site manege eolien",l_sous_secteur,4,4,0); 
  l_action->addDependancy("Recherche des sites eoliens de clim city","Centrale solaire");
  addAction(l_action);

  l_action = new action("Implantation d eoliennes offshore",l_sous_secteur,8,8,0); 
  l_action->addDependancy("Recherche des sites eoliens de clim city","Centrale solaire");
  addAction(l_action);

  // Barrage Hydro electrique
  l_sous_secteur = new sous_secteur("Barrage Hydro Electrique");

  addAction(new action("Amelioration du rendement du barrage",l_sous_secteur,6,6,0));
  addAction(new action("Recherche de site pour micro centrale hydraulique",l_sous_secteur,2,2,0));

  l_action = new action("Construction de la micro centrale hydraulique",l_sous_secteur,4,4,0); 
  l_action->addDependancy("Recherche de site pour micro centrale hydraulique","Barrage Hydro Electrique");
  addAction(l_action);


  //Centrale solaire
  l_sous_secteur = new sous_secteur("Centrale solaire");
  addAction(new action("Recherche efficacite des panneaux photovoltaiques",l_sous_secteur,3,3,0));
  addAction(new action("Recherche centrale solaire",l_sous_secteur,6,8,0));

  l_action = new action("Construction centrale solaire a tour",l_sous_secteur,10,12,0); 
  l_action->addDependancy("Recherche centrale solaire","Centrale solaire");
  addAction(l_action);

  l_action = new action("Production d hydrogene",l_sous_secteur,5,5,0); 
  l_action->addDependancy("Construction centrale solaire a tour","Centrale solaire");
  addAction(l_action);

  // Energies marines
  l_sous_secteur = new sous_secteur("Energies marines");

  addAction(new action("Recherche technologies marines",l_sous_secteur,4,4,0));

  l_action = new action("Implantation champs d hydroliennes",l_sous_secteur,8,8,0); 
  l_action->addDependancy("Recherche technologies marines","Energies marines");
  addAction(l_action);

  l_action = new action("Implantation  de bouees electriques",l_sous_secteur,5,5,0); 
  l_action->addDependancy("Recherche technologies marines","Energies marines");
  addAction(l_action);

  l_action = new action("Implantation  serpent de mer",l_sous_secteur,4,4,0); 
  l_action->addDependancy("Recherche technologies marines","Energies marines");
  addAction(l_action);

  addAction(new action("Renforcement de la digue",l_sous_secteur,3,0,0));

  // Faille geothermique
  l_sous_secteur = new sous_secteur("Faille geothermique");

  addAction(new action("Recherche potentiel geothermique",l_sous_secteur,2,4,0));

  l_action = new action("Construction d'une centrale geothermique",l_sous_secteur,10,10,0); 
  l_action->addDependancy("Recherche potentiel geothermique","Faille geothermique");
  addAction(l_action);

  // Electrecite nucleaire
  l_sous_secteur = new sous_secteur("Electrecite nucleaire");
 
  addAction(new action("Inspection controle de la centrale",l_sous_secteur,2,4,0));

  l_action = new action("Renovation",l_sous_secteur,8,8,0); 
  l_action->addDependancy("Inspection controle de la centrale","Electrecite nucleaire");
  addAction(l_action);

  //---------------
  //- Agriculture -
  //---------------
  // Engins agricoles
  l_sous_secteur = new sous_secteur("Engins agricoles");

  addAction(new action("Top machines",l_sous_secteur,0,3,0));
  addAction(new action("Utilisation du biodiesel",l_sous_secteur,0,2,0));

  // Serres
  l_sous_secteur = new sous_secteur("Serres");
 
  addAction(new action("Plan serre energie",l_sous_secteur,3,3,0));
  addAction(new action("Serres solaires",l_sous_secteur,2,4,0));

  // Elevage et batiments d'elevage
  l_sous_secteur = new sous_secteur("Elevage et batiments d elevage");

  addAction(new action("Maitrise de la consommation",l_sous_secteur,0,2,0));
  addAction(new action("Renovation des batiments agricoles",l_sous_secteur,2,6,0));
  addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,0,2,0));
  addAction(new action("Reduction du chaptel de betail",l_sous_secteur,2,6,6));
  addAction(new action("Recherche scientifique pour reduire les rejets de methane",l_sous_secteur,3,3,0));
  addAction(new action("Surveillance des maladies animales",l_sous_secteur,2,2,0));

  // Champs et vignes
  l_sous_secteur = new sous_secteur("Champs et vignes");
  addAction(new action("Reduction des engrais",l_sous_secteur,1,6,0));
  addAction(new action("Utiliser des engrais bios",l_sous_secteur,0,4,0));
  addAction(new action("Recherche agronomique impact du changement climatique",l_sous_secteur,2,1,0));

  l_action = new action("Adaptation eau",l_sous_secteur,1,2,0); 
  l_action->addDependancy("Recherche agronomique impact du changement climatique","Champs et vignes");
  addAction(l_action);

  addAction(new action("Boisement des champs",l_sous_secteur,0,5,0));

  l_action = new action("Systemes chauffants",l_sous_secteur,0,2,0); 
  l_action->addDependancy("Recherche agronomique impact du changement climatique","Champs et vignes");
  addAction(l_action);

  // Sylviculture
  l_sous_secteur = new sous_secteur("Sylviculture");
  addAction(new action("Reglage des engins",l_sous_secteur,0,2,0));
  addAction(new action("Utilisation du biodiesel",l_sous_secteur,0,2,0));
  addAction(new action("Lancement de la filiere bois energie",l_sous_secteur,3,5,0));

  l_action = new action("Augmentation fileire bois energie",l_sous_secteur,0,4,0); 
  l_action->addDependancy("Lancement de la filiere bois energie","Sylviculture");
  addAction(l_action);

  addAction(new action("Especes resistantes",l_sous_secteur,2,2,0));
  addAction(new action("Prevention des incendies de foret",l_sous_secteur,2,0,0));

  // Agrocarburants
  l_sous_secteur = new sous_secteur("Agrocarburants");

  addAction(new action("Recherche bio carburants de 2eme generation",l_sous_secteur,4,4,0));

  // Fumier
  l_sous_secteur = new sous_secteur("Fumier");

  addAction(new action("Construction d une unite de methanisation",l_sous_secteur,4,6,0));

  l_action = new action("Valorisation du fumier",l_sous_secteur,0,2,0); 
  l_action->addDependancy("Construction d une unite de methanisation","Fumier");
  addAction(l_action);

  //---------
  //- Peche -
  //---------
  //Peche
  l_sous_secteur = new sous_secteur("Peche");

  addAction(new action("Amelioration des equipements",l_sous_secteur,2,4,0));
  addAction(new action("Sensibilisation des equipages",l_sous_secteur,1,2,0));
  addAction(new action("Etude scientifique deplacement des especes",l_sous_secteur,2,1,0));

  l_action = new action("Reduction de la peche",l_sous_secteur,2,2,2); 
  l_action->addDependancy("Produits locaux et de saison","Supermarches");
  addAction(l_action);

  //-----------------------
  //- Tourisme et loisirs -
  //-----------------------
  // Camping
  l_sous_secteur = new sous_secteur("Camping");

  addAction(new action("Agrandir et renover le camping littoral",l_sous_secteur,1,3,0));

  l_action = new action("Ecovacances",l_sous_secteur,0,0,5); 
  l_action->addDependancy("Tourisme vert","Tourisme montagne");
  l_action->addDependancy("Agrandir et renover le camping littoral","Camping");
  addAction(l_action);

  // Tourisme montagne
  l_sous_secteur = new sous_secteur("Tourisme montagne");
   
  addAction(new action("Canons a neige",l_sous_secteur,0,3,0));
  addAction(new action("Tourisme vert",l_sous_secteur,2,2,0));

  //----------------------------
  //- Transports -
  //--------------
  // Voitures 
  l_sous_secteur = new sous_secteur("Voitures");

  addAction(new action("Ameliorer l efficacite des moteurs",l_sous_secteur,5,5,4));
  addAction(new action("Formation ecoconduite",l_sous_secteur,1,0,2));
  addAction(new action("Limitation de la vitesse sur la rocade",l_sous_secteur,2,0,3));
  addAction(new action("Bonus malus a l achat des vehicules",l_sous_secteur,2,2,2));
  addAction(new action("Clim controle",l_sous_secteur,2,4,6));
  addAction(new action("Association voiture partagee",l_sous_secteur,2,0,3));
  addAction(new action("Peage urbain",l_sous_secteur,1,0,5));

  l_action = new action("Interdiction des voitures en ville",l_sous_secteur,2,0,4); 
  l_action->addDependancy("Reseau de tramway","Tramway");
  l_action->addDependancy("Amelioration du reseau de bus","Bus");
  addAction(l_action);

  l_action = new action("Developper des moteurs verts",l_sous_secteur,6,6,4); 
  l_action->addDependancy("Recherche bio carburants de 2eme generation","Agrocarburants");
  addAction(l_action);

  l_action = new action("Developper les voitures pile a combustible",l_sous_secteur,8,10,4); 
  l_action->addDependancy("Production d hydrogene","Centrale solaire");
  addAction(l_action);

  addAction(new action("Motorisations electriques",l_sous_secteur,6,6,4));

  // Pietons velos
  l_sous_secteur = new sous_secteur("Pietons velos");
  
  addAction(new action("Creation de voies pietons",l_sous_secteur,2,0,2));
  addAction(new action("Creation de pistes cyclables",l_sous_secteur,4,0,2));
  addAction(new action("Velo asso",l_sous_secteur,2,0,2));
  addAction(new action("Clim cycles",l_sous_secteur,3,0,0));

  // Bus
  l_sous_secteur = new sous_secteur("Bus");
   addAction(new action("Amelioration du reseau de bus",l_sous_secteur,5,2,2));

   l_action = new action("Motorisation biodiesel 2",l_sous_secteur,6,4,0); 
   l_action->addDependancy("Recherche bio carburants de 2eme generation","Agrocarburants");
   l_action->addDependancy("Amelioration du reseau de bus","Bus");
   addAction(l_action);
   
   l_action = new action("Motorisation hydrogene",l_sous_secteur,6,6,0); 
   l_action->addDependancy("Production hydrogene","Centrale solaire");
   l_action->addDependancy("Amelioration du reseau de bus","Bus");
   addAction(l_action);
   
   // Tramway
   l_sous_secteur = new sous_secteur("Tramway");
   
   addAction(new action("Reseau de tramway",l_sous_secteur,12,5,0));

   l_action = new action("Parking relais",l_sous_secteur,4,0,0); 
   l_action->addDependancy("Reseau de tramway","Tramway");
   addAction(l_action);

   // Trains
   l_sous_secteur = new sous_secteur("Trains");
   addAction(new action("Ligne TGV littoral",l_sous_secteur,10,5,0));
   addAction(new action("Ligne TGV rural montagne",l_sous_secteur,10,5,0));
   addAction(new action("Creation de lignes de ferroutage",l_sous_secteur,4,4,0));
   addAction(new action("Amelioration des locomotrices",l_sous_secteur,4,4,0));

   // Avions
   l_sous_secteur = new sous_secteur("Avions");
   
   addAction(new action("Compensation carbone",l_sous_secteur,0,0,6));
   addAction(new action("Formation eco atterissage",l_sous_secteur,0,2,0));
   addAction(new action("Remplacement des gazs de climatisation",l_sous_secteur,5,5,0));
   addAction(new action("Programme de recherches avion du futur",l_sous_secteur,6,10,0));

   // Cargos
   l_sous_secteur = new sous_secteur("Cargos");

   addAction(new action("Autoroute de la mer",l_sous_secteur,3,3,0));
   addAction(new action("Ameliorer les moteurs des cargos",l_sous_secteur,1,4,0));
   addAction(new action("Cargos a voile",l_sous_secteur,0,4,0));
   addAction(new action("Plan clim cargos",l_sous_secteur,2,4,0));

   // Camions
   l_sous_secteur = new sous_secteur("Camions");

   addAction(new action("Performance des moteurs",l_sous_secteur,4,8,0));
   addAction(new action("Remplissage",l_sous_secteur,0,4,0));

   l_action = new action("Ferroutage",l_sous_secteur,0,6,0); 
   l_action->addDependancy("Creation de lignes de ferroutages","Trains");
   addAction(l_action);

   addAction(new action("Plan clim camion",l_sous_secteur,2,6,0));
   addAction(new action("Eco routiers",l_sous_secteur,0,4,0));

   // Camionnettes
   l_sous_secteur = new sous_secteur("Camionnettes");
   addAction(new action("Camionnettes electriques",l_sous_secteur,0,2,0));
   addAction(new action("Remplissage des camionnettes",l_sous_secteur,0,2,0));

   // Plateforme transfert modal
   l_sous_secteur = new sous_secteur("Plateforme transfert modal");

   addAction(new action("Creation de la plateforme de transfert modal",l_sous_secteur,10,10,0));

   l_action = new action("Campagne de com transfert intermodal",l_sous_secteur,3,3,0); 
   l_action->addDependancy("Creation de la plateforme de transfert modal","Plateforme transfert modal");
   addAction(l_action);
   
   l_action = new action("Reduction des couts des transports",l_sous_secteur,6,3,0); 
   l_action->addDependancy("Creation de la plateforme de transfert modal","Plateforme transfert modal");
   addAction(l_action);
   
   //--------------
   //- Industries -
   //--------------
   // Industries
   l_sous_secteur = new sous_secteur("Industries");
   addAction(new action("Formation aux economies d energie",l_sous_secteur,0,8,0));
   addAction(new action("Diagnostic efficacite",l_sous_secteur,0,8,0));
   addAction(new action("Reglages optimises",l_sous_secteur,0,6,0));

   l_action = new action("Installation d une chaufferie biomasse",l_sous_secteur,3,3,0); 
   l_action->addDependancy("Lancement de la filiere bois energie","Sylviculture");
   addAction(l_action);

   addAction(new action("Panneaux solaires photovoltaiques",l_sous_secteur,4,4,0));
   addAction(new action("Destruction des gazs fluores",l_sous_secteur,0,12,0));
   addAction(new action("Recyclage des emission N2O",l_sous_secteur,0,10,0));
   addAction(new action("Recyclage des cendres de l incinerateur",l_sous_secteur,0,8,0));
   addAction(new action("Refroidissement de l incinerateur",l_sous_secteur,0,4,0));
   addAction(new action("Eco cooperation",l_sous_secteur,0,6,0));
   addAction(new action("Association des eco industriels",l_sous_secteur,0,2,0));
   

   //-----------
   //- Dechets -
   //-----------
   // Centre de recyclage
   l_sous_secteur = new sous_secteur("Centre de recyclage");
   addAction(new action("Amelioration du centre de recyclage",l_sous_secteur,6,4,0));
   addAction(new action("Campagne de sensibilisation au tri",l_sous_secteur,4,0,2));

   l_action = new action("Eco conception",l_sous_secteur,2,3,1); 
   l_action->addDependancy("Amelioration du centre de recyclage","Centre de recyclage");
   l_action->addDependancy("Campagne de sensibilisation au tri","Centre de recyclage");
   addAction(l_action);

   l_action = new action("Campagne de prevention des dechets",l_sous_secteur,2,3,1); 
   l_action->addDependancy("Amelioration du centre de recyclage","Centre de recyclage");
   l_action->addDependancy("Campagne de sensibilisation au tri","Centre de recyclage");
   l_action->addDependancy("Eco conception","Centre de recyclage");
   addAction(l_action);

   l_action = new action("Amelioration des camions de collecte",l_sous_secteur,0,3,0); 
   l_action->addDependancy("Recherche biocarburants de 2eme generation","Agrocarburants");
   addAction(l_action);

   l_action = new action("Amelioration des camions de collecte hydrogene",l_sous_secteur,0,5,0); 
   l_action->addDependancy("Peoduction d'hydrogene","Centrale solaire");
   addAction(l_action);

   // Decharge
   l_sous_secteur = new sous_secteur("Decharge");

   addAction(new action("Torcheres",l_sous_secteur,4,6,0));

   l_action = new action("Valorisation du biogaz",l_sous_secteur,4,6,0); 
   l_action->addDependancy("Torcheres","Decharge");
   addAction(l_action);

   l_action = new action("Fermeture de la decharge",l_sous_secteur,2,2,0); 
   l_action->addDependancy("Valorisation du biogaz","Torcheres");
   l_action->addDependancy("Amelioration du centre de recyclage","Centre de recyclage");
   l_action->addDependancy("Campagne de sensibilisation au tri","Centre de recyclage");
   l_action->addDependancy("Eco conception","Centre de recyclage");
   l_action->addDependancy("Campagne de prevention des dechets","Centre de recyclage");
   addAction(l_action);


   // Incinerateur
   l_sous_secteur = new sous_secteur("Incinerateur");

   addAction(new action("Valorisation de la chaleur",l_sous_secteur,6,6,0));

   l_action = new action("Cogeneration",l_sous_secteur,8,8,0); 
   l_action->addDependancy("Valorisation de la chaleur","Incinerateur");
   addAction(l_action);

   addAction(new action("Programme de reboisement",l_sous_secteur,4,4,0));

   //--------------------
   //- Autres -
   //----------
   // Mairie
   l_sous_secteur = new sous_secteur("Mairie");

   addAction(new action("Creation de l espace info energie",l_sous_secteur,4,0,0));
   addAction(new action("Loi eclairage durable",l_sous_secteur,4,2,0));
   addAction(new action("Loi fonction veille sur les appareils",l_sous_secteur,4,2,0));
   addAction(new action("Campagne de sobrierite et efficacite",l_sous_secteur,4,0,0));
   addAction(new action("Campagne de com renovations batiments",l_sous_secteur,4,0,0));
   addAction(new action("Campagne de com production d electricite renouvelables",l_sous_secteur,4,0,0));
   addAction(new action("Campagne de com production de chaleur renouvelables",l_sous_secteur,4,0,0));
   addAction(new action("Construction d un eco quartier",l_sous_secteur,14,6,6));
   
}

//--------------------------------------------------------------------------------------------------
const action * clim_city::getAction(const std::string &p_secteur_name,const std::string & p_action_name)
{
  std::map<std::pair<std::string,std::string>,const action*>::const_iterator l_iter = m_actions.find(pair<string,string>(p_secteur_name,p_action_name));
  assert(l_iter != m_actions.end());
  return l_iter->second;
}

//-----------------------------------------------------------------------------
string clim_city::toString(void)const
{
  return "not implemented";
}

//-----------------------------------------------------------------------------
void clim_city::addAction(const action *p_action)
{
  assert(m_actions.find(pair<string,string>(p_action->getSousSecteur(),p_action->getName()))==m_actions.end());
  m_actions.insert(map<pair<string,string>,const action*>::value_type(pair<string,string>(p_action->getSousSecteur(),p_action->getName()),p_action));
}

//-----------------------------------------------------------------------------
void clim_city::computeTransitionWeights(std::vector<FSM_weighted_transition_index_if*> &p_vector)const
{
  cout << "Not implemented" << endl ;
  exit(-1);
}

//-----------------------------------------------------------------------------
const map<pair<string,string>,const action*> & clim_city::getActions(void)
{
  return m_actions;
}

//-----------------------------------------------------------------------------
FSM_if* createClimCity()
{
  return new clim_city();
}

//-----------------------------------------------------------------------------
extern "C"
{
  void registerFsm(map<string,FSM_creator> *p_factory)
  {
    registerFsm("clim_city",createClimCity,p_factory);
  }
}

map<pair<string,string>,const action*> clim_city::m_actions;
//EOF
