class Projet {
    static all_projets = Projet.fill_projets();

    constructor(titre, matiere, semestre, résumer, outils, compétence, acquis, livrables) {
        this.titre = titre;
        this.matiere = matiere;
        this.semestre = semestre;
        this.résumer = résumer;
        this.outils = outils;
        this.compétence = compétence;
        this.acquis = acquis;
        this.livrables = livrables
    }

    toString() {
        return `${this.titre} de la ressource ${this.matiere}`
    }

    static fill_projets() {
        // Tableau associatif all_projets dont les clés sont code et les valeurs sont des objets Projet.
        let all_projets = {};
        // Parcours la table contries du fichier projets.js
        projets.forEach(element => {
            all_projets[element.titre] = new Projet(element.titre, element.matiere, element.semestre, element.résumer, element.outils, element.compétence, element.acquis, element.livrables);
        });
        return all_projets;
    }
}