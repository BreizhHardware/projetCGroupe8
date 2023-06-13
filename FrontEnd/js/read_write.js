// ------- WRITE FILE -------
function writeFile(id_form, func) {
    let element = document.createElement('a');
    let text1 = document.getElementById(id_form);
    let count = text1.elements.length;
    let textToSave = func;

    for (let i = 0; i < count - 1; i++) {
        textToSave += ";" + text1[i].value;
    }

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'requests.txt');
    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);

    return new Promise((resolve, reject) => {
        checkFile(resolve);
    });
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
        setTimeout(() => {
            xhr.open("GET", fileName, false);
            xhr.send(null);
        });

    }while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}


// -------- CHECK FILE --------

function checkFile(resolve) {
    if (readFileByName("../BackEnd/ready.txt") !== "") {
        resolve();
    } else {
        setTimeout(() => {
            checkFile(resolve);
        }, 5000);
    }
}


// ----------ON CLICK----------

document.getElementById('directorButton').addEventListener('click', function() {
    writeFile('formDirector', 'searchByDirector')
        .then(() => {
            // Envoi du formulaire formDirector
            document.getElementById('formDirector').submit();
        })
        .catch((error) => {
        });
});

document.getElementById('dureeButton').addEventListener('click', function() {
    writeFile('formDuree', 'searchByDuree')
        .then(() => {
            // Envoi du formulaire formDuree
            document.getElementById('formDuree').submit();
        })
        .catch((error) => {
        });
});

document.getElementById('categorieButton').addEventListener('click', function() {
    writeFile('formCategorie', 'searchByCategorie')
        .then(() => {
            // Envoi du formulaire formCategorie
            document.getElementById('formCategorie').submit();
        })
        .catch((error) => {
        });
});

document.getElementById('filmButton').addEventListener('click', function() {
    writeFile('formFilm', 'searchByFilm')
        .then(() => {
            // Envoi du formulaire formFilm
            document.getElementById('formFilm').submit();
        })
        .catch((error) => {
        });
});

document.getElementById('realMostMovie').addEventListener('click', function() {
    writeFile('formMostMovie', 'searchRealMostMovie')
        .then(() => {
            // Envoi du formulaire formRealMostMovie
            document.getElementById('formMostMovie').submit();
        })
        .catch((error) => {
        });
});