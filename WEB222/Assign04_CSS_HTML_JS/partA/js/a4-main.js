/* Place all of your CSS Code in this file */

/********************************************************************************* 
*
* WEB222 – Assignment #4a
*
* I declare that this assignment is my own work in accordance with Seneca 
* Academic Policy. No part of this assignment has been copied manually or 
* electronically from any other source (including web sites) or distributed to 
* other students. 
* 
* Name: __Jihyun Yoon__ Student ID: _124558172_ Date: _2018/03/22_ 
* 
********************************************************************************/

var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)

function loadTableWithFilter() {
    var query=document.querySelector("#main-table-body");
        query.innerHTML="";
        petData.forEach(pet => {
        if((filterType==""||pet.type==filterType)&&pet.age>=filterAgeMin&&pet.age<=filterAgeMax){
            var tr, tdImg, img, tdDesc, h4, p, span;
            tr=document.createElement("tr");
            tdImg=document.createElement("td");
            img= document.createElement("img");
            img.src=pet.image.src;
            img.alt=pet.image.alt;
            img.height=pet.image.height;
            img.width=pet.image.width;
            tdImg.appendChild(img);
            
            tdDesc=document.createElement("td")
            h4=document.createElement("h4");
            h4.appendChild(document.createTextNode(pet.name));
            tdDesc.appendChild(h4);
            
            p= document.createElement("p");
            p.innerHTML=pet.description;
            tdDesc.appendChild(p);

            
            span=document.createElement("span");
            span.appendChild(document.createTextNode("Age: "+pet.age+" years old."));
            tdDesc.appendChild(span);
            tr.appendChild(tdImg);
            tr.appendChild(tdDesc);
            query.appendChild(tr);
        }   
    });
    
}

function filterDog(){
    filterType="dog";
    loadTableWithFilter();
}

function filterCat(){
    filterType="cat";
    loadTableWithFilter();
}

function filterBird(){
    filterType="bird";
    loadTableWithFilter();
}

function filter_zero_1(){
    filterAgeMin=0;
    filterAgeMax=1;
    loadTableWithFilter();
}

function filter_1_3(){
    filterAgeMin=1;
    filterAgeMax=3;
    loadTableWithFilter();
}

function filter_4_plus(){
    filterAgeMin=4;
    filterAgeMax=Number.MAX_VALUE;
    loadTableWithFilter();
}

function filterAllPets(){
    filterType="";
    filterAgeMin=0;
    filterAgeMax=Number.MAX_VALUE;
    loadTableWithFilter();
}