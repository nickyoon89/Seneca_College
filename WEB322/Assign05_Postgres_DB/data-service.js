var exports = module.exports = {};

const Sequelize = require('sequelize');
var sequelize = new Sequelize('dfva5fgj1r3vnf','swotfpraivoljq','dea810702079ca69f68be08b544969d613c4efad28d0beac90b7ef53d1621fc0',{
    host:'ec2-54-243-28-109.compute-1.amazonaws.com',
    dialect:'postgres',
    port: 5432,
    dialectOptions:{
        ssl: true
    }
});

var Employee = sequelize.define('Employee', {
    employeeNum: {
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    firstName:Sequelize.STRING,
    lastName:Sequelize.STRING,
    email:Sequelize.STRING,
    SSN:Sequelize.STRING,
    addressStreet:Sequelize.STRING,
    addressCity:Sequelize.STRING,
    addressState:Sequelize.STRING,
    addressPostal:Sequelize.STRING,
    martialStatus:Sequelize.STRING,
    isManager:Sequelize.BOOLEAN,
    employeeManagerNum:Sequelize.INTEGER,
    status:Sequelize.STRING,
    department:Sequelize.INTEGER,
    hireDate:Sequelize.STRING,
});

var Department = Sequelize.define('Department',{
    departmentId:{
        type:Sequelize.INTEGER,
        primaryKey:true,
        autoIncrement:true
    },
    departmentName: Sequelize.STRING
});

exports.initialize = function() {
    return new Promise((resolve, reject) => {
        sequelize.sync()
        .then(() => resolve())
        .catch(() => reject("unable to sync the database"));
    });
};

exports.getAllEmployees = function(){
    return new Promise((resolve, reject) => {
        Employee.findAll()
        .then(()=>resolve(Employee))
        .catch(()=>reject("no results returned")) 
    });
};

exports.getManagers = function(){
    return new Promise((resolve, reject) => {
        let filteredEmployees = Employee.filter(Employee => Employee.isManager == true);
        filteredEmployees.findAll()
        .then(()=>resolve(filteredEmployees))
        .catch(()=>reject("no results returned")) 
    });
};

exports.getDepartments = function(){
    Department.findAll()
    .then(()=>resolve(Department))
    .catch(()=>reject("no results returned")) 

};  

exports.addEmployee = function(employeeData){
    employeeData.isManager = (employeeData.isManager) ? true : false;
    employeeData.employeeNum = employees.length+1;
    for(prop in employeeData){
        if(prop=="") prop=null;
    }
    return new Promise((resolve, reject) => {
        Employee.create(employeeData)
        .then(()=>resolve(Employee))
        .catch(()=>reject("unable to create employee"))
    });
};

exports.getEmployeesByStatus = function(status){
    return new Promise((resolve, reject) => {
        let filteredEmployees = Employee.filter(Employee => Employee.status == status);
        filteredEmployees.findAll()
        .then(()=>resolve(filteredEmployees))
        .catch(()=>reject("no results returned")) 
    });
}

exports.getEmployeesByDepartment = function(department){
    return new Promise((resolve, reject) => {
        let filteredEmployees = Employee.filter(Employee => Employee.department == department);
        filteredEmployees.findAll(filteredEmployees)
        .then(()=>resolve())
        .catch(()=>reject("no results returned")) 
    });
}

exports.getEmployeesByManager = function(manager){
    return new Promise((resolve, reject) => {
        let filteredEmployees = Employee.filter(Employee => Employee.employeeManagerNum == manager);
        filteredEmployees.findAll()
        .then(()=>resolve(filteredEmployees))
        .catch(()=>reject("no results returned")) 
    });
}

exports.getEmployeesByNum = function(num){
    return new Promise((resolve, reject) => {
        let filteredEmployees = Employee.filter(Employee => Employee.employeeNum == num);
        filteredEmployees.findAll()
        .then(()=>resolve(filteredEmployees))
        .catch(()=>reject("no results returned")) 
    });
}

exports.updateEmployee = function(employeeData){
    employeeData.isManager = (employeeData.isManager) ? true : false;
    employeeData.employeeNum = employees.length+1;
    for(prop in employeeData){
        if(prop=="") prop=null;
    }
    return new Promise((resolve, reject) => {
        Employee.forEach(employee => {
            if (employee.employeeNum == employeeData.employeeNum) {
                employees.splice(employeeData.employeeNum - 1, 1, employeeData);
            }
        });
        Employee.update(Employee) 
        .then(()=>resolve(Employee))
        .catch(()=>reject("unable to update employee"))
    });
};