// Data for the "HTML Tables" Page

var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];

window.onload=function(){
    var tableContainer=document.querySelector("#tableContents");
    var table = '<table style="border:1px solid black;" class="border"><tr><th>First Name</th><th>Last Name</th><th>Age</th><th>Email</th></tr>';
    users.forEach(user => {
        table+="<tr>";
        table+="<td>"+user.first_name+"</td>";
        table+="<td>"+user.last_name+"</td>";
        table+="<td>"+user.age+"</td>";
        table+="<td>"+"<a href="+'mailto:"'+user.email+'">'+user.email+"</a>"+"</td>";
        table+="</tr>";
    });
    table+="</table>";
    tableContainer.innerHTML+=table;
}