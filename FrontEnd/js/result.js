// -----------fonction display-------------
function displayDirector(){
    const queryString = window.location.search;

    //Verifie si le parametre director est present dans l'url
    if(queryString.includes("director")){
    //Récupère la valeur du parametre director

        const urlParams = new URLSearchParams(queryString);

        const director = urlParams.get('director');

        let resultTitle = document.getElementById("resultTitle");

        resultTitle.innerHTML = "Film par " + director + " :<br> Temps de recherche : 1ms";

        readAndDisplay();

    }
}


function displayDuree(){
    const queryString = window.location.search;
    if(queryString.includes("duree")){
        const urlParms = new URLSearchParams(queryString);
        const duree = urlParms.get('duree');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de " + duree + " minutes :<br> Temps de recherche : 1ms";
        readAndDisplay();
    }
}

function displayCategorie(){
    const queryString = window.location.search;
    if(queryString.includes("categorie")){
        const urlParms = new URLSearchParams(queryString);
        const categorie = urlParms.get('categorie');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de la catégorie " + categorie + " :<br> Temps de recherche : 1ms";
        readAndDisplay();
    }
}

function displayFilm(){
    const queryString = window.location.search;
    if(queryString.includes("film")){
        const urlParms = new URLSearchParams(queryString);
        const film = urlParms.get('film');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film contenant " + film + " :<br> Temps de recherche : 1ms";
        readAndDisplay();
    }
}

function displayAll(){
    const queryString = window.location.search;
    if(queryString.includes("All")){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Tous les films :<br> Temps de recherche : 1ms";
        const result = readFileByName("../BackEnd/BD_big.txt");

        // Récupère le tableau de films
        films = result.split("\n");

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

        films.sort((a, b) => a[1].localeCompare(b[1]));

        // Calculer le nombre total de pages
        totalPages = Math.ceil(films.length / filmsPerPage);
        // Afficher la première page
        displayPage(currentPage);
    }
}

function displayMostMovies(){
    const queryString = window.location.search;
    if(queryString.includes("MostMovies")){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Réalisateur avec le plus de films :<br> Temps de recherche : 1ms";
        readAndDisplay();
    }
}

function displayFallBack(){
    const queryString = window.location.search;
    if(queryString.includes("director") === false && queryString.includes("duree") === false && queryString.includes("categorie") === false && queryString.includes("film") === false && queryString.includes("All") === false && queryString.includes("MostMovies") === false){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Aucun parametre trouvé";
    }
}

function returnToHome(){
    window.location.href = "index.html";
}

// ------- WRITE FILE -------

function writeFile(id_form,func) {

    let element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;
    for(let i = 0;i<count-1;i++){
        textToSave += ";" + text1[i].value;
    }

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);

    // text1.submit();
}
// -------------------------


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

function readFile(){
    readFileByName("ready.txt");
    return readFileByName("results.txt");
}
// -------------------------


function callWrite() {
    writeFile("form-findByDirector",  )
}

// ------- READ AND DISPLAY -------

let films = [];
let currentPage = 1;
const filmsPerPage = 20;

function readAndDisplay() {
    const result = readFileByName("../BackEnd/results.txt");

    // Récupère le tableau de films
    films = result.split("\n");

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
        let container = document.getElementById("resultContentContainer" + containerIndex);
        let resultContent = container.querySelector(".resultContent");

        if (resultContent.children.length >= 5) {
            // Si le conteneur est plein (déjà 5 cartes), passer au conteneur suivant
            containerIndex++;
            container = document.getElementById("resultContentContainer" + containerIndex);
            resultContent = container.querySelector(".resultContent");
        }

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
        resultContent.innerHTML = "";
    }
}

function updatePagination(page) {
    // Mettre à jour le numéro de page affiché
    let resultTitle = document.getElementById("pageNumbers");
    resultTitle.innerText = "Page " + page;

    // Afficher ou masquer les boutons de navigation en fonction de la page actuelle
    let previousButton = document.getElementById("previousButton");
    let nextButton = document.getElementById("nextButton");

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
    if (currentPage > 1) {
        currentPage--;
        displayPage(currentPage);
    }
}

function goToNextPage() {
    if (currentPage < totalPages) {
        currentPage++;
        displayPage(currentPage);
    }
}

function addCard(container, real, title, duree, categorie){
    let card = document.createElement("div");
    card.classList.add("card");
    card.innerHTML = "Titre : " + title + "<br>Realisateur : " + real + "<br>Durée : " + duree + "<br>Categorie : " + categorie;
    container.appendChild(card);
}

// -------------------------
//Appel des fonctions

displayDirector();
displayDuree();
displayCategorie();
displayFilm();
displayAll();
displayMostMovies();
displayFallBack();