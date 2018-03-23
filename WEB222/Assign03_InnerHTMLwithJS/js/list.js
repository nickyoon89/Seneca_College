// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];
var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];

window.onload = function() {
    var fruitContainer = document.querySelector("#fruitsArray");
    var fruitList = "<ol>"
    for (var i = 0; i < fruits.length; i++) {
    fruitList += "<li>" + fruits[i] + "</li>";
    }
    fruitList += "</ol>";
    fruitContainer.innerHTML+=fruitList;

    var fileContainer = document.querySelector("#fileArray");
    var fileList = "<ul>";
    directory.forEach(file => {
        fileList+="<li>"+file.name
        if(file.type=="directory"){
            fileList+="<ul>"
            file.files.forEach(subfile => {
                fileList+="<li>"+subfile.name+"</li>";
            });
            fileList+="</ul>"
        }
        fileList+="</li>";    
    });
    fileList+= "</ul>";
    fileContainer.innerHTML+=fileList;
};

