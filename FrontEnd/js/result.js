function displayDirector(){
    const queryString = window.location.search;

    //Verifie si le parametre director est present dans l'url
    if(queryString.includes("director")){
    //Récupère la valeur du parametre director

        const urlParams = new URLSearchParams(queryString);

        const director = urlParams.get('director');

        let resultTitle = document.getElementById("resultTitle");

        resultTitle.innerHTML = "Film par " + director + " :<br> Temps de recherche : 1ms";

    }
    else{
        console.warn("Parametre director non trouvé");
    }
}

function displayDuree(){
    const queryString = window.location.search;
    if(queryString.includes("duree")){
        const urlParms = new URLSearchParams(queryString);
        const duree = urlParms.get('duree');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de " + duree + " minutes :<br> Temps de recherche : 1ms";
    }
    else{
        console.warn("Parametre duree non trouvé");
    }
}

function displayCategorie(){
    const queryString = window.location.search;
    if(queryString.includes("categorie")){
        const urlParms = new URLSearchParams(queryString);
        const categorie = urlParms.get('categorie');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film de la catégorie " + categorie + " :<br> Temps de recherche : 1ms";
    }
    else{
        console.warn("Parametre categorie non trouvé");
    }
}

function displayFilm(){
    const queryString = window.location.search;
    if(queryString.includes("film")){
        const urlParms = new URLSearchParams(queryString);
        const film = urlParms.get('film');
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Film contenant " + film + " :<br> Temps de recherche : 1ms";
    }
    else{
        console.warn("Parametre film non trouvé");
    }
}

function displayAll(){
    const queryString = window.location.search;
    if(queryString.includes("All")){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Tous les films :<br> Temps de recherche : 1ms";
    }
    else{
        console.warn("Parametre all non trouvé");
    }
}

function displayMostMovies(){
    const queryString = window.location.search;
    if(queryString.includes("MostMovies")){
        let resultTitle = document.getElementById("resultTitle");
        resultTitle.innerHTML = "Réalisateur avec le plus de films :<br> Temps de recherche : 1ms";
    }
    else{
        console.warn("Parametre mostMovies non trouvé");
    }
}

function returnToHome(){
    window.location.href = "index.html";
}

displayDirector();
displayDuree();
displayCategorie();
displayFilm();
displayAll();
displayMostMovies();

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

function readAndDisplay(){
    const result =  readFileByName("../BackEnd/results.txt");

    // Récupère le tableau de films
    let films = result.split("\n");

    // Supprime le dernier element du tableau (vide)
    films.pop();

    // Retire le \r de chaque element du tableau
    for(let i = 0;i<films.length;i++){
        films[i] = films[i].replace("\r","");
    }

    console.log(films);

    // Split chaque element du tableau en un tableau de 4 elements
    for(let i = 0;i<films.length;i++){
        films[i] = films[i].split(";");
    }

    console.log(films);

    // Creation de la carte pour chaque film
    let containerIndex = 1;

    for(let i = 0; i < films.length;i++){
        let container = document.getElementById("resultContentContainer" + containerIndex);
        let resultContent = container.querySelector(".resultContent");

        if (resultContent.children.length >= 5){
            containerIndex++;
            container = document.getElementById("resultContentContainer" + containerIndex);
            resultContent = container.querySelector(".resultContent");
        }

        addCard(resultContent, films[i][0], films[i][1], films[i][2], films[i][3]);
    }
}

function addCard(container, real, title, duree, categorie){
    let card = document.createElement("div");
    card.classList.add("card");
    card.innerHTML = "Tire : " + title + "<br>Realisateur : " + real + "<br>Durée : " + duree + "<br>Categorie : " + categorie;
    container.appendChild(card);
}

readAndDisplay();