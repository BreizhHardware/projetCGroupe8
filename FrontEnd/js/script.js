function validateformDirector(){
    let director = document.getElementById("director").value;

    //Definition l'expression régulière
    let directorRegex = /^[a-zA-Z]+$/;

    let isDirectorValid = directorRegex.test(director);

    let directorError = document.getElementById("directorError");

    if(isDirectorValid){
        directorError.innerHTML = "";
        unlockDirectorButton()
    }
    else{
        directorError.innerHTML = "Le nom du directeur doit contenir que des lettres et aucun espace";
        lockDirectorButton();
    }
}

function validateformDuree(){
    let duree = document.getElementById("duree").value;

    //Definition l'expression régulière
    let dureeRegex = /^[0-9]+$/;

    let isDureeValid = dureeRegex.test(duree);

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
    let categorie = document.getElementById("categorie").value;

    //Definition l'expression régulière
    let categorieRegex = /^[a-zA-Z]+$/;

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
    let film = document.getElementById("film").value;

    //Definition l'expression régulière
    let filmRegex = /^[a-zA-Z0-9 ]+$/;

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
    document.getElementById("directorButton").disabled = true;
}

function lockDureeButton(){
    document.getElementById("dureeButton").disabled = true;
}

function lockCategorieButton(){
    document.getElementById("categorieButton").disabled = true;
}

function lockFilmButton(){
    document.getElementById("filmButton").disabled = true;
}

function unlockDirectorButton(){
    document.getElementById("duree").value = "";
    document.getElementById("categorie").value = "";
    document.getElementById("film").value = "";
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    document.getElementById("filmButton").disabled = true;
    document.getElementById("directorButton").disabled = false;
}

function unlockDureeButton(){
    document.getElementById("director").value = "";
    document.getElementById("categorie").value = "";
    document.getElementById("film").value = "";
    document.getElementById("directorButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    document.getElementById("filmButton").disabled = true;
    document.getElementById("dureeButton").disabled = false;
}

function unlockCategorieButton(){
    document.getElementById("director").value = "";
    document.getElementById("duree").value = "";
    document.getElementById("film").value = "";
    document.getElementById("directorButton").disabled = true;
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("categorieButton").disabled = false;
}

function unlockFilmButton(){
    document.getElementById("director").value = "";
    document.getElementById("duree").value = "";
    document.getElementById("categorie").value = "";
    document.getElementById("directorButton").disabled = true;
    document.getElementById("dureeButton").disabled = true;
    document.getElementById("categorieButton").disabled = true;
    document.getElementById("filmButton").disabled = false;
}

//Ajouter les événements pour la validation
document.getElementById("director").addEventListener("keyup", validateformDirector);
document.getElementById("duree").addEventListener("keyup", validateformDuree);
document.getElementById("categorie").addEventListener("keyup", validateformCategorie);
document.getElementById("film").addEventListener("keyup", validateformFilm);