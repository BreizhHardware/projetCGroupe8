document.addEventListener("DOMContentLoaded", function(event) {
    //Add event listener to the checkboxes
    document.getElementById("directorCheck").addEventListener("change", function() {
        if(this.checked){
            document.getElementById("director").disabled = false;
            document.getElementById("director").style.opacity = "1";
            document.getElementById("duree").disabled = true;
            document.getElementById("duree").value = "";
            document.getElementById("duree").style.opacity = "0.5";
            document.getElementById("categorie").disabled = true;
            document.getElementById("categorie").value = "";
            document.getElementById("categorie").style.opacity = "0.5";
            document.getElementById("film").disabled = true;
            document.getElementById("film").value = "";
            document.getElementById("film").style.opacity = "0.5";
            document.getElementById("dureeCheck").checked = false;
            document.getElementById("categorieCheck").checked = false;
            document.getElementById("filmCheck").checked = false;
        }
    });

    document.getElementById("dureeCheck").addEventListener("change", function() {
        if(this.checked){
            document.getElementById("duree").disabled = false;
            document.getElementById("duree").style.opacity = "1";
            document.getElementById("director").disabled = true;
            document.getElementById("director").value = "";
            document.getElementById("director").style.opacity = "0.5";
            document.getElementById("categorie").disabled = true;
            document.getElementById("categorie").value = "";
            document.getElementById("categorie").style.opacity = "0.5";
            document.getElementById("film").disabled = true;
            document.getElementById("film").value = ""
            document.getElementById("film").style.opacity = "0.5";
            document.getElementById("directorCheck").checked = false;
            document.getElementById("categorieCheck").checked = false;
            document.getElementById("filmCheck").checked = false;
        }
    });

    document.getElementById("categorieCheck").addEventListener("change", function() {
        if(this.checked){
            document.getElementById("categorie").disabled = false;
            document.getElementById("categorie").style.opacity = "1";
            document.getElementById("director").disabled = true;
            document.getElementById("director").value = "";
            document.getElementById("director").style.opacity = "0.5";
            document.getElementById("duree").disabled = true
            document.getElementById("duree").value = "";
            document.getElementById("duree").style.opacity = "0.5";
            document.getElementById("film").disabled = true;
            document.getElementById("film").value = "";
            document.getElementById("film").style.opacity = "0.5";
            document.getElementById("directorCheck").checked = false;
            document.getElementById("dureeCheck").checked = false;
            document.getElementById("filmCheck").checked = false;
        }
    });

    document.getElementById("filmCheck").addEventListener("change", function() {
        if(this.checked){
            document.getElementById("film").disabled = false;
            document.getElementById("film").style.opacity = "1";
            document.getElementById("director").disabled = true;
            document.getElementById("director").value = "";
            document.getElementById("director").style.opacity = "0.5";
            document.getElementById("duree").disabled = true;
            document.getElementById("duree").value = "";
            document.getElementById("duree").style.opacity = "0.5";
            document.getElementById("categorie").disabled = true;
            document.getElementById("categorie").value = "";
            document.getElementById("categorie").style.opacity = "0.5";
            document.getElementById("directorCheck").checked = false;
            document.getElementById("dureeCheck").checked = false;
            document.getElementById("categorieCheck").checked = false;
        }
    });
});

window.addEventListener("load", function(event) {
    document.getElementById("director").disabled = false;
    document.getElementById("duree").disabled = true;
    document.getElementById("duree").value = "";
    document.getElementById("duree").style.opacity = "0.5";
    document.getElementById("categorie").disabled = true;
    document.getElementById("categorie").value = "";
    document.getElementById("categorie").style.opacity = "0.5";
    document.getElementById("film").disabled = true;
    document.getElementById("film").value = "";
    document.getElementById("film").style.opacity = "0.5";
    document.getElementById("directorCheck").checked = true;
    document.getElementById("dureeCheck").checked = false;
    document.getElementById("categorieCheck").checked = false;
    document.getElementById("filmCheck").checked = false;
});

// Recuperation des données du formulaire
function getFormData() {
    if(document.getElementById("directorCheck").checked){

}