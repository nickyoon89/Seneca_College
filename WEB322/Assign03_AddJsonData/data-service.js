var employees = new Array();
var departments = new Array();

var fs = require('fs');
var exports = module.exports = {};

exports.initialize = function() {
    fs.readFile('data/employees.json', 'utf-8', (err, data) => {employees = JSON.parse(data);});
    fs.readFile('data/departments.json', 'utf-8', (err, data) => {departments = JSON.parse(data);});

    return new Promise((resolve, reject) => {
        resolve("Init Success");
        reject("unable to read data");
    });
};

exports.getAllEmployees = function(){
    return new Promise((resolve, reject) => {
        resolve(employees);
        if(employees.length == 0)
        reject("no results returned");
    });
};

exports.getManagers = function(){
    return new Promise((resolve, reject) => {
        let managers = employees.filter(employees => employees.isManager == true);
        resolve(managers);
        if(employees.length == 0)
        reject("no results returned");
    });
};

exports.getDepartments = function(){
    return new Promise((resolve, reject) => {
        resolve(departments);
        if (departments.length == 0)
        reject("no results returned");
    });

};  

exports.addEmployee = function(employeeData){
    if(!employeeData.isManager) employeeData.isManager=false;
    else employeeData.isManager = true;
    employeeData.employeeNum = employees.length+1;
    employees.push(employeeData);
    return new Promise((resolve, reject) => {
        resolve(employees);
        if(employees.length == 0)
        reject("no results returned");
    });
};

exports.getEmployeesByStatus = function(status){
    return new Promise((resolve, reject) => {
        let filteredEmployees = employees.filter(employees => employees.status == status);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}

exports.getEmployeesByDepartment = function(department){
    return new Promise((resolve, reject) => {
        let filteredEmployees = employees.filter(employees => employees.department == department);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}

exports.getEmployeesByManager = function(manager){
    return new Promise((resolve, reject) => {
        let filteredEmployees = employees.filter(employees => employees.employeeManagerNum == manager);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}

exports.getEmployeesByNum = function(num){
    return new Promise((resolve, reject) => {
        let filteredEmployees = employees.filter(employees => employees.employeeNum == num);
        resolve(filteredEmployees);
        if(filteredEmployees.length == 0)
        reject("no results returned");
    });
}