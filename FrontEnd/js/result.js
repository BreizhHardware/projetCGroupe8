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
