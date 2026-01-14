document.addEventListener("DOMContentLoaded", () => {
    const urlParams = new URLSearchParams(window.location.search);
    const projetId = urlParams.get('id'); // Récupère l'ID du projet dans l'URL

    if (projetId) {
        // Si on est sur une page de projet spécifique, on affiche ses détails
        const projet = projets[projetId - 1]; // Les projets sont indexés à partir de 1, donc -1 pour l'indexation 0

        if (projet) {
            id_titre_projet.textContent     = projet.titre;
            id_matiere.textContent          = projet.matiere;
            id_competence.innerHTML         = projet.compétence.map(compétence => `<p>${compétence.libellé}</p>`).join("");
            id_texte_resume.textContent     = projet.résumer;
            id_liste_outils.innerHTML       = projet.outils.map(outil => `<li>${outil}</li>`).join("");
            id_liste_acquis.innerHTML       = projet.acquis.map(acquis => `<li>${acquis}</li>`).join("");
            id_liste_livrables.innerHTML    = projet.livrables.map(livrable => `<li><a href="${livrable.lien}">${livrable.nom}</a></li>`).join("");
        } else {
            id_titre_projet.textContent = "Projet non trouvé";
        }
    }
});
