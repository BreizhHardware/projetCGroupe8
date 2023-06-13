function validateformDirector(){
    // Récupérer le nom du directeur
    let director = document.getElementById("director").value;

    //Definition l'expression régulière
    let directorRegex = /^[a-zA-Z]+$/;

    // Vérifier si le nom du directeur est valide
    let isDirectorValid = directorRegex.test(director);

    // Récupérer l'élément qui affiche l'erreur
    let directorError = document.getElementById("directorError");

    // Si le nom du directeur est valide, on affiche rien et on débloque le bouton
    if(isDirectorValid){
        directorError.innerHTML = "";
        unlockDirectorButton()
    }
    // Sinon, on affiche un message d'erreur et on bloque le bouton
    else{
        directorError.innerHTML = "Le nom du directeur doit contenir que des lettres et aucun espace";
        lockDirectorButton();
    }
}

function validateformDuree(){
    // Récupérer la durée
    let duree = document.getElementById("duree").value;

    //Definition l'expression régulière
    let dureeRegex = /^[0-9]+$/;

    // Vérifier si la durée est valide
    let isDureeValid = dureeRegex.test(duree);

    // Récupérer l'élément qui affiche l'erreur
    let dureeError = document.getElementById("dureeError");

    if(isDureeValid){
        dureeError.innerHTML = "";
        unlockDureeButton();
    }
    else{
        dureeError.innerHTML = "La durée doit être un nombre";
        lockDureeButton();
    }
}

function validateformCategorie(){
    // Récupérer la catégorie
    let categorie = document.getElementById("categorie").value;

    //Definition l'expression régulière
    let categorieRegex = /^[a-zA-Z]+$/;

    // Vérifier si la catégorie est valide
    let isCategorieValid = categorieRegex.test(categorie);

    let categorieError = document.getElementById("categorieError");

    if(isCategorieValid){
        categorieError.innerHTML = "";
        unlockCategorieButton();
    }
    else{
        categorieError.innerHTML = "La catégorie doit contenir que des lettres et aucun espace";
        lockCategorieButton();
    }
}

function validateformFilm(){
    // Récupérer le nom du film
    let film = document.getElementById("film").value;

    //Definition l'expression régulière
    let filmRegex = /^[a-zA-Z0-9 ]+$/;

    // Vérifier si le nom du film est valide
    let isFilmValid = filmRegex.test(film);

    let filmError = document.getElementById("filmError");

    if(isFilmValid){
        filmError.innerHTML = "";
        unlockFilmButton();
    }
    else{
        filmError.innerHTML = "Le nom du film doit contenir que des lettres et des chiffres";
        lockFilmButton();
    }
}

function lockDirectorButton(){
    // desactiver le bouton
    document.getElementById("directorButton").disabled = true;
}

function lockDureeButton(){
    // desactiver le bouton
    document.getElementById("dureeButton").disabled = true;
}

function lockCategorieButton(){
    // desactiver le bouton
    document.getElementById("categorieButton").disabled = true;
}

function lockFilmButton(){
    // desactiver le bouton
    document.getElementById("filmButton").disabled = true;
}

function unlockDirectorButton(){
    // vider les autres champs
    document.getElementById("duree").value = "";
    document.getElementById("categorie").value = "";
    document.getElementById("film").value = "";
    // desactiver les autres boutons
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    document.getElementById("filmButton").disabled = true;
    // activer le bouton
    document.getElementById("directorButton").disabled = false;
}

function unlockDureeButton(){
    // vider les autres champs
    document.getElementById("director").value = "";
    document.getElementById("categorie").value = "";
    document.getElementById("film").value = "";
    // desactiver les autres boutons
    document.getElementById("directorButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    document.getElementById("filmButton").disabled = true;
    // activer le bouton
    document.getElementById("dureeButton").disabled = false;
}

function unlockCategorieButton(){
    // vider les autres champs
    document.getElementById("director").value = "";
    document.getElementById("duree").value = "";
    document.getElementById("film").value = "";
    // desactiver les autres boutons
    document.getElementById("directorButton").disabled = true;
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("filmButton").disabled = true;
    // activer le bouton
    document.getElementById("categorieButton").disabled = false;
}

function unlockFilmButton(){
    // vider les autres champs
    document.getElementById("director").value = "";
    document.getElementById("duree").value = "";
    document.getElementById("categorie").value = "";
    // desactiver les autres boutons
    document.getElementById("directorButton").disabled = true;
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    // activer le bouton
    document.getElementById("filmButton").disabled = false;
}

//Ajouter les événements pour la validation
document.getElementById("director").addEventListener("keyup", validateformDirector);
document.getElementById("duree").addEventListener("keyup", validateformDuree);
document.getElementById("categorie").addEventListener("keyup", validateformCategorie);
document.getElementById("film").addEventListener("keyup", validateformFilm);