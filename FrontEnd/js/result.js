// -----------fonction display-------------
function displayDirector(time){
    const queryString = window.location.search;

    //Verifie si le parametre director est present dans l'url
    if(queryString.includes("director")){
    //Récupère la valeur du parametre director
        const urlParams = new URLSearchParams(queryString);

        const director = urlParams.get('director');

        let resultTitle = document.getElementById("resultTitle");
        // Affiche la recherche et le temps de recherche
        resultTitle.innerHTML = "Film par " + director + " :<br> Temps de recherche : " + time + "s";

        readAndDisplay();

    }
}


function displayDuree(time){
    const queryString = window.location.search;
    if(queryString.includes("duree")){
        const urlParms = new URLSearchParams(queryString);
        const duree = urlParms.get('duree');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de " + duree + " minutes :<br> Temps de recherche : " + time + "s";
        readAndDisplay();
    }
}

/*
function displayCategorie(time){
    const queryString = window.location.search;
    if(queryString.includes("categorie")){
        const urlParms = new URLSearchParams(queryString);
        const categorie = urlParms.get('categorie');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de la catégorie " + categorie + " :<br> Temps de recherche : " + time + "s";
        readAndDisplay();
    }
}
*/


function displayFilm(time){
    const queryString = window.location.search;
    if(queryString.includes("film")){
        const urlParms = new URLSearchParams(queryString);
        const film = urlParms.get('film');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film contenant " + film + " :<br> Temps de recherche : " + time + "s";
        readAndDisplay();
    }
}

function displayAll(){
    // Récupère le paramètre de l'URL
    const queryString = window.location.search;
    // Vérifie si le paramètre "All" est présent dans l'URL
    if(queryString.includes("All")){
        // Récupère le temps de recherche
        let start = new Date().getTime();
        // Récupère le contenu du fichier
        const result = readFileByName("../BackEnd/BD_big.txt");

        // Récupère le tableau de films
        films = result.split("\n");
        // Vérifie si aucun film n'a été trouvé
        if (films.length === 0) {
            let alert = document.getElementById("result");
            alert.innerHTML = "Aucun film trouvé";
            alert.style.display = "block";
            alert.style.color = "red";
            alert.style.textAlign = "center";
            alert.style.fontSize = "30px";
            return; // Arrête l'exécution si aucun film n'est trouvé
        }

        // Retire le \r de chaque élément du tableau
        for (let i = 0; i < films.length; i++) {
            films[i] = films[i].replace("\r", "");
        }

        // Split chaque élément du tableau en un tableau de 4 éléments
        for (let i = 0; i < films.length; i++) {
            films[i] = films[i].split(";");
        }
        // Trie le tableau par ordre alphabétique
        films.sort((a, b) => a[1].localeCompare(b[1]));

        // Calculer le nombre total de pages
        totalPages = Math.ceil(films.length / filmsPerPage);
        // Récupère le temps de recherche
        let end = new Date().getTime();
        // Calcul le temps de recherche en secondes
        let time = (end - start) / 1000;
        // Affiche la recherche et le temps de recherche
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Tous les films :<br> Temps de recherche : " + time + "s";
        // Afficher la première page
        displayPage(currentPage);
    }
}

function displayMostMovies(){
    const queryString = window.location.search;
    // Vérifie si le paramètre "MostMovies" est présent dans l'URL
    if(queryString.includes("MostMovies")){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Réalisateur avec le plus de films :<br> Temps de recherche : 1ms";
        readAndDisplay();
    }
}

function displayFallBack(){
    const queryString = window.location.search;
    // Vérifie si aucun paramètre n'est présent dans l'URL
    if(queryString.includes("director") === false && queryString.includes("duree") === false && queryString.includes("categorie") === false && queryString.includes("film") === false && queryString.includes("All") === false && queryString.includes("MostMovies") === false){
        let resultTitle = document.getElementById("resultTitle");
        // Dans ce cas affiche un message d'erreur
        resultTitle.innerHTML = "Aucun parametre trouvé";
    }
}

function returnToHome(){
    window.location.href = "index.html";
}



// ----------WRITE FILE STOP----------

function writeFileStop(func){
    let element = document.createElement('a');
    let textToSave = func;

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'requests.txt');
    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);
}


// ------- READ FILE -------
function readFileByName(fileName){

    let xhr = new XMLHttpRequest();
    do {
        xhr.open("GET", fileName, false);
        xhr.send(null);

    }while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}


// ------- READ AND DISPLAY -------
// Variables globales
let films = [];
let currentPage = 1;
const filmsPerPage = 20;

function readAndDisplay() {
    // Lit le fichier
    const result = readFileByName("../BackEnd/results.txt");
    // Récupère le tableau de films a partir de la 2eme ligne
    films = result.split("\n");
    // Retire la première ligne du tableau (temps d'exécution)
    films.shift();
    // Vérifie si aucun film n'a été trouvé
    if (films.length <= 1) {
        let alert = document.getElementById("result");
        alert.innerHTML = "Aucun film trouvé";
        alert.style.display = "block";
        alert.style.color = "red";
        alert.style.textAlign = "center";
        alert.style.fontSize = "30px";
        return; // Arrête l'exécution si aucun film n'est trouvé
    }

    // Retire le \r de chaque élément du tableau
    for (let i = 0; i < films.length; i++) {
        films[i] = films[i].replace("\r", "");
    }
    // Retire le dernier élément du tableau (vide)
    films.pop();


    // Split chaque élément du tableau en un tableau de 4 éléments
    films = films.map(film => film.split(";"));

    // Trie le tableau par ordre alphabétique
    films.sort((a, b) => a[1].localeCompare(b[1]));


    // Calculer le nombre total de pages
    totalPages = Math.ceil(films.length / filmsPerPage);
    // Afficher la première page
    displayPage(currentPage);
}

function displayPage(page) {
    // Calculer l'indice de début et de fin des films pour la page spécifiée
    const startIndex = (page - 1) * filmsPerPage;
    const endIndex = startIndex + filmsPerPage;

    // Obtenir les films de la page actuelle
    const currentFilms = films.slice(startIndex, endIndex);

    // Vider le contenu des conteneurs
    clearContainers();

    // Création de la carte pour chaque film de la page actuelle
    let containerIndex = 1;
    let cardIndex = 0;

    for (let i = 0; i < currentFilms.length; i++) {
        // Récupérer le conteneur
        let container = document.getElementById("resultContentContainer" + containerIndex);
        let resultContent = container.querySelector(".resultContent");

        if (resultContent.children.length >= 5) {
            // Si le conteneur est plein (déjà 5 cartes), passer au conteneur suivant
            containerIndex++;
            container = document.getElementById("resultContentContainer" + containerIndex);
            resultContent = container.querySelector(".resultContent");
        }

        // Ajouter la carte au conteneur
        addCard(resultContent, currentFilms[i][0], currentFilms[i][1], currentFilms[i][2], currentFilms[i][3]);

        cardIndex++;
    }

    // Mettre à jour l'affichage de la pagination
    updatePagination(page);
}

function clearContainers() {
    for (let i = 1; i <= 4; i++) {
        let container = document.getElementById("resultContentContainer" + i);
        let resultContent = container.querySelector(".resultContent");
        // Vider le conteneur
        resultContent.innerHTML = "";
    }
}

function updatePagination(page) {
    // Mettre à jour le numéro de page affiché
    let pageNumber = document.getElementById("pageNumbers");
    pageNumber.innerText = "Page " + page;

    // Afficher ou masquer les boutons de navigation en fonction de la page actuelle
    let previousButton = document.getElementById("previousButton");
    let nextButton = document.getElementById("nextButton");

    // Afficher ou masquer les boutons de navigation en fonction de la page actuelle
    if (page === 1) {
        previousButton.style.display = "none";
    } else {
        previousButton.style.display = "block";
    }

    if (page === totalPages) {
        nextButton.style.display = "none";
    } else {
        nextButton.style.display = "block";
    }
}

function goToPreviousPage() {
    // Aller à la page précédente si la page actuelle n'est pas la première
    if (currentPage > 1) {
        currentPage--;
        displayPage(currentPage);
    }
}

function goToNextPage() {
    // Aller à la page suivante si la page actuelle n'est pas la dernière
    if (currentPage < totalPages) {
        currentPage++;
        displayPage(currentPage);
    }
}

function goToFirstPage() {
    // Aller à la première page
    currentPage = 1;
    displayPage(currentPage);
}

function goToLastPage() {
    // Aller à la dernière page
    currentPage = totalPages;
    displayPage(currentPage);
}

function addCard(container, real, title, duree, categorie){
    // Création de la carte
    let card = document.createElement("div");
    card.classList.add("card");
    card.innerHTML = "Titre : " + title + "<br>Realisateur : " + real + "<br>Durée : " + duree + "<br>Categorie : " + categorie;
    container.appendChild(card);
}



// -------------------------

const result = readFileByName("../BackEnd/results.txt");
// Récupère la première ligne du fichier
const firstLine = result.split("\n")[0];

//Appel des fonctions
displayDirector(firstLine);
displayDuree(firstLine);
//displayCategorie(firstLine);
displayFilm(firstLine);
displayMostMovies(firstLine);
displayFallBack(firstLine);
displayAll();