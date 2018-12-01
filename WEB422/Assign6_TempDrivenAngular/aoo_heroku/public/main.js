(window["webpackJsonp"] = window["webpackJsonp"] || []).push([["main"],{

/***/ "./src/$$_lazy_route_resource lazy recursive":
/*!**********************************************************!*\
  !*** ./src/$$_lazy_route_resource lazy namespace object ***!
  \**********************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

function webpackEmptyAsyncContext(req) {
	// Here Promise.resolve().then() is used instead of new Promise() to prevent
	// uncaught exception popping up in devtools
	return Promise.resolve().then(function() {
		var e = new Error("Cannot find module '" + req + "'");
		e.code = 'MODULE_NOT_FOUND';
		throw e;
	});
}
webpackEmptyAsyncContext.keys = function() { return []; };
webpackEmptyAsyncContext.resolve = webpackEmptyAsyncContext;
module.exports = webpackEmptyAsyncContext;
webpackEmptyAsyncContext.id = "./src/$$_lazy_route_resource lazy recursive";

/***/ }),

/***/ "./src/app/app-routing.module.ts":
/*!***************************************!*\
  !*** ./src/app/app-routing.module.ts ***!
  \***************************************/
/*! exports provided: AppRoutingModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppRoutingModule", function() { return AppRoutingModule; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var _components_home_component_home_component_component__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./components/home-component/home-component.component */ "./src/app/components/home-component/home-component.component.ts");
/* harmony import */ var _components_employees_component_employees_component_component__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./components/employees-component/employees-component.component */ "./src/app/components/employees-component/employees-component.component.ts");
/* harmony import */ var _components_positions_component_positions_component_component__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./components/positions-component/positions-component.component */ "./src/app/components/positions-component/positions-component.component.ts");
/* harmony import */ var _components_employee_employee_component__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./components/employee/employee.component */ "./src/app/components/employee/employee.component.ts");
/* harmony import */ var _components_position_position_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./components/position/position.component */ "./src/app/components/position/position.component.ts");
/* harmony import */ var _components_page_not_found_component_page_not_found_component_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./components/page-not-found-component/page-not-found-component.component */ "./src/app/components/page-not-found-component/page-not-found-component.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};








var routes = [
    { path: 'home', component: _components_home_component_home_component_component__WEBPACK_IMPORTED_MODULE_2__["HomeComponent"] },
    { path: 'employees', component: _components_employees_component_employees_component_component__WEBPACK_IMPORTED_MODULE_3__["EmployeesComponent"] },
    { path: 'positions', component: _components_positions_component_positions_component_component__WEBPACK_IMPORTED_MODULE_4__["PositionsComponent"] },
    { path: 'employee/:_id', component: _components_employee_employee_component__WEBPACK_IMPORTED_MODULE_5__["EmployeeComponent"] },
    { path: 'position/:_id', component: _components_position_position_component__WEBPACK_IMPORTED_MODULE_6__["PositionComponent"] },
    { path: '', redirectTo: '/home', pathMatch: 'full' },
    { path: '**', component: _components_page_not_found_component_page_not_found_component_component__WEBPACK_IMPORTED_MODULE_7__["PageNotFoundComponent"] }
];
var AppRoutingModule = /** @class */ (function () {
    function AppRoutingModule() {
    }
    AppRoutingModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["NgModule"])({
            imports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"].forRoot(routes)],
            exports: [_angular_router__WEBPACK_IMPORTED_MODULE_1__["RouterModule"]],
            providers: []
        })
    ], AppRoutingModule);
    return AppRoutingModule;
}());



/***/ }),

/***/ "./src/app/app.component.css":
/*!***********************************!*\
  !*** ./src/app/app.component.css ***!
  \***********************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiIuLi9hcHAuY29tcG9uZW50LmNzcyJ9 */"

/***/ }),

/***/ "./src/app/app.component.html":
/*!************************************!*\
  !*** ./src/app/app.component.html ***!
  \************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<app-nav></app-nav>\n<app-content></app-content>\n<app-footer></app-footer>"

/***/ }),

/***/ "./src/app/app.component.ts":
/*!**********************************!*\
  !*** ./src/app/app.component.ts ***!
  \**********************************/
/*! exports provided: AppComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppComponent", function() { return AppComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};

var AppComponent = /** @class */ (function () {
    function AppComponent() {
        this.title = 'my-dream-app';
    }
    AppComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-root',
            template: __webpack_require__(/*! ./app.component.html */ "./src/app/app.component.html"),
            styles: [__webpack_require__(/*! ./app.component.css */ "./src/app/app.component.css")]
        })
    ], AppComponent);
    return AppComponent;
}());



/***/ }),

/***/ "./src/app/app.module.ts":
/*!*******************************!*\
  !*** ./src/app/app.module.ts ***!
  \*******************************/
/*! exports provided: AppModule */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "AppModule", function() { return AppModule; });
/* harmony import */ var _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/platform-browser */ "./node_modules/@angular/platform-browser/fesm5/platform-browser.js");
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_forms__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/forms */ "./node_modules/@angular/forms/fesm5/forms.js");
/* harmony import */ var _angular_http__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! @angular/http */ "./node_modules/@angular/http/fesm5/http.js");
/* harmony import */ var _app_routing_module__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ./app-routing.module */ "./src/app/app-routing.module.ts");
/* harmony import */ var _app_component__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! ./app.component */ "./src/app/app.component.ts");
/* harmony import */ var _components_home_component_home_component_component__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! ./components/home-component/home-component.component */ "./src/app/components/home-component/home-component.component.ts");
/* harmony import */ var _components_employees_component_employees_component_component__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! ./components/employees-component/employees-component.component */ "./src/app/components/employees-component/employees-component.component.ts");
/* harmony import */ var _components_positions_component_positions_component_component__WEBPACK_IMPORTED_MODULE_8__ = __webpack_require__(/*! ./components/positions-component/positions-component.component */ "./src/app/components/positions-component/positions-component.component.ts");
/* harmony import */ var _components_footer_component_footer_component_component__WEBPACK_IMPORTED_MODULE_9__ = __webpack_require__(/*! ./components/footer-component/footer-component.component */ "./src/app/components/footer-component/footer-component.component.ts");
/* harmony import */ var _components_nav_component_nav_component_component__WEBPACK_IMPORTED_MODULE_10__ = __webpack_require__(/*! ./components/nav-component/nav-component.component */ "./src/app/components/nav-component/nav-component.component.ts");
/* harmony import */ var _components_content_component_content_component_component__WEBPACK_IMPORTED_MODULE_11__ = __webpack_require__(/*! ./components/content-component/content-component.component */ "./src/app/components/content-component/content-component.component.ts");
/* harmony import */ var _components_page_not_found_component_page_not_found_component_component__WEBPACK_IMPORTED_MODULE_12__ = __webpack_require__(/*! ./components/page-not-found-component/page-not-found-component.component */ "./src/app/components/page-not-found-component/page-not-found-component.component.ts");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_13__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
/* harmony import */ var _components_employee_service__WEBPACK_IMPORTED_MODULE_14__ = __webpack_require__(/*! ./components/employee.service */ "./src/app/components/employee.service.ts");
/* harmony import */ var _components_position_service__WEBPACK_IMPORTED_MODULE_15__ = __webpack_require__(/*! ./components/position.service */ "./src/app/components/position.service.ts");
/* harmony import */ var _components_employee_employee_component__WEBPACK_IMPORTED_MODULE_16__ = __webpack_require__(/*! ./components/employee/employee.component */ "./src/app/components/employee/employee.component.ts");
/* harmony import */ var _components_position_position_component__WEBPACK_IMPORTED_MODULE_17__ = __webpack_require__(/*! ./components/position/position.component */ "./src/app/components/position/position.component.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};


















var AppModule = /** @class */ (function () {
    function AppModule() {
    }
    AppModule = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_1__["NgModule"])({
            declarations: [
                _app_component__WEBPACK_IMPORTED_MODULE_5__["AppComponent"],
                _components_content_component_content_component_component__WEBPACK_IMPORTED_MODULE_11__["ContentComponent"],
                _components_footer_component_footer_component_component__WEBPACK_IMPORTED_MODULE_9__["FooterComponent"],
                _components_home_component_home_component_component__WEBPACK_IMPORTED_MODULE_6__["HomeComponent"],
                _components_employees_component_employees_component_component__WEBPACK_IMPORTED_MODULE_7__["EmployeesComponent"],
                _components_positions_component_positions_component_component__WEBPACK_IMPORTED_MODULE_8__["PositionsComponent"],
                _components_nav_component_nav_component_component__WEBPACK_IMPORTED_MODULE_10__["NavComponent"],
                _components_page_not_found_component_page_not_found_component_component__WEBPACK_IMPORTED_MODULE_12__["PageNotFoundComponent"],
                _components_employee_employee_component__WEBPACK_IMPORTED_MODULE_16__["EmployeeComponent"],
                _components_position_position_component__WEBPACK_IMPORTED_MODULE_17__["PositionComponent"]
            ],
            imports: [
                _angular_platform_browser__WEBPACK_IMPORTED_MODULE_0__["BrowserModule"],
                _angular_forms__WEBPACK_IMPORTED_MODULE_2__["FormsModule"],
                _angular_http__WEBPACK_IMPORTED_MODULE_3__["HttpModule"],
                _app_routing_module__WEBPACK_IMPORTED_MODULE_4__["AppRoutingModule"],
                _angular_common_http__WEBPACK_IMPORTED_MODULE_13__["HttpClientModule"]
            ],
            providers: [_components_position_service__WEBPACK_IMPORTED_MODULE_15__["PositionService"], _components_employee_service__WEBPACK_IMPORTED_MODULE_14__["EmployeeService"]],
            bootstrap: [_app_component__WEBPACK_IMPORTED_MODULE_5__["AppComponent"]]
        })
    ], AppModule);
    return AppModule;
}());



/***/ }),

/***/ "./src/app/components/content-component/content-component.component.css":
/*!******************************************************************************!*\
  !*** ./src/app/components/content-component/content-component.component.css ***!
  \******************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJjb250ZW50LWNvbXBvbmVudC9jb250ZW50LWNvbXBvbmVudC5jb21wb25lbnQuY3NzIn0= */"

/***/ }),

/***/ "./src/app/components/content-component/content-component.component.html":
/*!*******************************************************************************!*\
  !*** ./src/app/components/content-component/content-component.component.html ***!
  \*******************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=container>\r\n    <router-outlet></router-outlet>\r\n  </div>"

/***/ }),

/***/ "./src/app/components/content-component/content-component.component.ts":
/*!*****************************************************************************!*\
  !*** ./src/app/components/content-component/content-component.component.ts ***!
  \*****************************************************************************/
/*! exports provided: ContentComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "ContentComponent", function() { return ContentComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var ContentComponent = /** @class */ (function () {
    function ContentComponent() {
    }
    ContentComponent.prototype.ngOnInit = function () {
    };
    ContentComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-content',
            template: __webpack_require__(/*! ./content-component.component.html */ "./src/app/components/content-component/content-component.component.html"),
            styles: [__webpack_require__(/*! ./content-component.component.css */ "./src/app/components/content-component/content-component.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], ContentComponent);
    return ContentComponent;
}());



/***/ }),

/***/ "./src/app/components/employee.service.ts":
/*!************************************************!*\
  !*** ./src/app/components/employee.service.ts ***!
  \************************************************/
/*! exports provided: EmployeeService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "EmployeeService", function() { return EmployeeService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var EmployeeService = /** @class */ (function () {
    function EmployeeService(http) {
        this.http = http;
        this.url = "https://web422-server.herokuapp.com";
    }
    EmployeeService.prototype.getEmployees = function () {
        return this.http.get(this.url + '/employees');
    };
    EmployeeService.prototype.saveEmployee = function (employee) {
        return this.http.put("https://web422-server.herokuapp.com/employee/" + employee._id, employee);
    };
    EmployeeService.prototype.getEmployee = function (id) {
        return this.http.get("https://web422-server.herokuapp.com/employee-raw/" + id);
    };
    EmployeeService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])(),
        __metadata("design:paramtypes", [_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"]])
    ], EmployeeService);
    return EmployeeService;
}());



/***/ }),

/***/ "./src/app/components/employee/employee.component.css":
/*!************************************************************!*\
  !*** ./src/app/components/employee/employee.component.css ***!
  \************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".center{ margin-top:40px; }\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImVtcGxveWVlL2VtcGxveWVlLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUEsU0FBUyxnQkFBZ0IsRUFBRSIsImZpbGUiOiJlbXBsb3llZS9lbXBsb3llZS5jb21wb25lbnQuY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLmNlbnRlcnsgbWFyZ2luLXRvcDo0MHB4OyB9Il19 */"

/***/ }),

/***/ "./src/app/components/employee/employee.component.html":
/*!*************************************************************!*\
  !*** ./src/app/components/employee/employee.component.html ***!
  \*************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"center\" *ngIf=\"employee\">\n  <h2>Employee: {{employee.FirstName}}&nbsp;{{employee.LastName}}</h2>\n  <p class=\"lead\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique bibendum.</p>\n</div>\n<div class=\"container\">\n<div class=\"row\">\n<div class=\"col-md-12\">\n  <form #f=\"ngForm\" (ngSubmit)=\"onSubmit(f)\">\n    <div class=\"row\">\n      <div class=\"col-md-6\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': FirstName.errors}\">\n          <label class=\"control-label\" for=\"FirstName\">First Name:</label>\n          <input #FirstName=\"ngModel\" class=\"form-control\" id=\"FirstName\" type=\"text\"  name=\"FirstName\"  [(ngModel)]=\"employee.FirstName\" required autofocus/>\n          <span class=\"help-block\" *ngIf=\"FirstName.errors && FirstName.errors.required\">First Name is Required</span>\n        </div>\n      </div>\n      <div class=\"col-md-6\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': LastName.errors}\">\n          <label class=\"control-label\" for=\"LastName\">Last Name:</label>\n          <input #LastName=\"ngModel\" class=\"form-control\" id=\"LastName\" type=\"text\" name=\"LastName\"  [(ngModel)]=\"employee.LastName\" required/>\n          <span class=\"help-block\" *ngIf=\"LastName.errors && LastName.errors.required\">Last Name is Required</span>\n        </div>\n      </div>\n    </div>\n    <div class=\"row\">\n      <div class=\"col-md-6\">\n        <div class=\"form-group\">\n          <label class=\"control-label\" for=\"Position\">Position:</label>\n          <select class=\"form-control\" id=\"Position\"  name=\"Position\"  [(ngModel)]=\"employee.Position\">\n            <option *ngFor=\"let p of positions\" [value]=\"p._id\">{{ p.PositionName }}</option>\n          </select>\n        </div>\n      </div>\n      <div class=\"col-md-6\">\n        <div class=\"form-group\">\n          <label class=\"control-label\" for=\"SalaryBonus\" >Salary Bonus</label>\n          <div class=\"input-group\">\n            <span class=\"input-group-addon\">$</span>\n            <input #SalaryBonus=\"ngModel\" class=\"form-control\" id=\"SalaryBonus\" type=\"Number\" name=\"SalaryBonus\" [(ngModel)]=\"employee.SalaryBonus\" required/>\n            <span class=\"help-block\" *ngIf=\"SalaryBonus.errors && SalaryBonus.errors.required\">Salary bonus is Required</span>\n          </div>\n        </div>\n      </div>\n    </div>\n    <div class=\"row\">\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': AddressStreet.errors}\">\n          <label class=\"control-label\" for=\"AddressStreet\" >Address (Street):</label>\n          <input #AddressStreet=\"ngModel\" class=\"form-control\" id=\"AddressStreet\" type=\"text\" name=\"AddressStreet\" [(ngModel)]=\"employee.AddressStreet\" required/>\n          <span class=\"help-block\" *ngIf=\"AddressStreet.errors && AddressStreet.errors.required\">Address street is Required</span>\n        </div>\n      </div>\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': AddressCity.errors}\">\n          <label class=\"control-label\" for=\"AddressCity\" >Address (City):</label>\n          <input #AddressCity=\"ngModel\" class=\"form-control\" id=\"AddressCity\" type=\"text\" name=\"AddressCity\" [(ngModel)]=\"employee.AddressCity\" required/>\n          <span class=\"help-block\" *ngIf=\"AddressCity.errors && AddressCity.errors.required\">Address city is Required</span>\n        </div>\n      </div>\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': AddressState.errors}\">\n          <label class=\"control-label\" for=\"AddressState\">Address (State):</label>\n          <input #AddressState=\"ngModel\" class=\"form-control\" id=\"AddressState\" type=\"text\" name=\"AddressState\" [(ngModel)]=\"employee.AddressState\" required/>\n          <span class=\"help-block\" *ngIf=\"AddressState.errors && AddressState.errors.required\">Address state is Required</span>\n        </div>\n      </div>\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': AddressZip.errors}\">\n          <label class=\"control-label\" for=\"AddressZip\">Address (Zip Code):</label>\n          <input #AddressZip=\"ngModel\" class=\"form-control\" id=\"AddressZip\" type=\"text\" name=\"AddressZip\" [(ngModel)]=\"employee.AddressZip\" required/>\n          <span class=\"help-block\" *ngIf=\"AddressZip.errors && AddressZip.errors.required\">Address zip is Required</span>\n        </div>\n      </div>\n    </div>\n    <div class=\"row\">\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': PhoneNum.errors}\">\n          <label class=\"control-label\" for=\"PhoneNum\">Phone Number:</label>\n          <input #PhoneNum=\"ngModel\" class=\"form-control\" id=\"PhoneNum\" type=\"text\" name=\"PhoneNum\" [(ngModel)]=\"employee.PhoneNum\" \n          pattern=\"\\+?[ ]*[1-9]?[ ]*\\-?[ ]*\\(?[ ]*[1-9][ ]*(\\d[ ]*){2}\\)?[ ]*\\-?[ ]*(\\d[ ]*){3}-[ ]*(\\d[ ]*){4}\"/>\n        </div>\n      </div>\n      <div class=\"col-md-3\">\n        <div class=\"form-group\" [ngClass]=\"{'form-group has-error': Extension.errors}\">\n          <label class=\"control-label\" for=\"Extension\">Extension:</label>\n          <input #Extension=\"ngModel\" class=\"form-control\" id=\"Extension\" type=\"Number\" name=\"Extension\" [(ngModel)]=\"employee.Extension\" required/>\n          <span class=\"help-block\" *ngIf=\"Extension.errors && Extension.errors.required\">Extension is Required</span>\n        </div>\n      </div>\n      <div class=\"col-md-6\">\n        <div class=\"form-group\" >\n          <label class=\"control-label\" for=\"HireDate\">Hire Date:</label>\n          <input class=\"form-control\" id=\"HireDate\" name=\"HireDate\" type=\"text\" value=\"HireDate\" [ngModel]=\"employee.HireDate|date:'longDate'\" readonly />\n        </div>\n      </div>\n    </div>\n    <hr />\n    <a [routerLink]=\"['/employees']\" class=\"btn btn-warning pull-left\">Return to Employee List</a>\n    <input type=\"submit\" class=\"btn btn-primary pull-right\" value=\"Update Employee\" [disabled]=\"!f.valid\"/>\n    <br />\n    <br />\n  </form>\n</div>\n</div>\n<br />\n<div class=\"alert alert-success\" *ngIf=\"successMessage==true&&employee\">\n  <strong>Success!</strong> {{employee.FirstName}}&nbsp;{{employee.LastName}}'s information was successfully saved.\n</div>\n<div class=\"alert alert-danger\" *ngIf=\"failMessage==true&&employee\" >\n  <strong>Error!</strong> {{employee.FirstName}}&nbsp;{{employee.LastName}}'s information could not be saved.\n</div>\n</div>\n<br /><br />"

/***/ }),

/***/ "./src/app/components/employee/employee.component.ts":
/*!***********************************************************!*\
  !*** ./src/app/components/employee/employee.component.ts ***!
  \***********************************************************/
/*! exports provided: EmployeeComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "EmployeeComponent", function() { return EmployeeComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
/* harmony import */ var _employee_service__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ../employee.service */ "./src/app/components/employee.service.ts");
/* harmony import */ var _position_service__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ../position.service */ "./src/app/components/position.service.ts");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};




var EmployeeComponent = /** @class */ (function () {
    function EmployeeComponent(route, employeeService, positionService) {
        this.route = route;
        this.employeeService = employeeService;
        this.positionService = positionService;
        this.successMessage = false;
        this.failMessage = false;
    }
    EmployeeComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.paramSubScription = this.route.params.subscribe(function (params) {
            _this.employeeSubscription = _this.employeeService.getEmployee(params['_id']).subscribe(function (emp) {
                _this.employee = emp[0];
                _this.getPositionsSub = _this.positionService.getPositions().subscribe(function (data) {
                    _this.positions = data;
                });
            });
        });
    };
    EmployeeComponent.prototype.onSubmit = function () {
        var _this = this;
        this.saveEmployeeSubscription = this.employeeService.saveEmployee(this.employee).subscribe(function () {
            _this.successMessage = true;
            // THERE WAS ONE LINE HERE BUT DELETE
            setTimeout(function () {
                _this.successMessage = false;
            }, 2500);
        }, function () {
            _this.failMessage = true;
            setTimeout(function () {
                _this.failMessage = false;
            }, 2500);
        });
    };
    EmployeeComponent.prototype.ngOnDestroy = function () {
        if (this.paramSubScription) {
            this.paramSubScription.unsubscribe();
        }
        if (this.employeeSubscription) {
            this.employeeSubscription.unsubscribe();
        }
        if (this.getPositionsSub) {
            this.getPositionsSub.unsubscribe();
        }
        if (this.saveEmployeeSubscription) {
            this.saveEmployeeSubscription.unsubscribe();
        }
    };
    EmployeeComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-employee',
            template: __webpack_require__(/*! ./employee.component.html */ "./src/app/components/employee/employee.component.html"),
            styles: [__webpack_require__(/*! ./employee.component.css */ "./src/app/components/employee/employee.component.css")]
        }),
        __metadata("design:paramtypes", [_angular_router__WEBPACK_IMPORTED_MODULE_1__["ActivatedRoute"], _employee_service__WEBPACK_IMPORTED_MODULE_2__["EmployeeService"], _position_service__WEBPACK_IMPORTED_MODULE_3__["PositionService"]])
    ], EmployeeComponent);
    return EmployeeComponent;
}());



/***/ }),

/***/ "./src/app/components/employees-component/employees-component.component.css":
/*!**********************************************************************************!*\
  !*** ./src/app/components/employees-component/employees-component.component.css ***!
  \**********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".center{ margin-top:40px; }\r\n.table-responsive{margin-bottom:60px;}\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImVtcGxveWVlcy1jb21wb25lbnQvZW1wbG95ZWVzLWNvbXBvbmVudC5jb21wb25lbnQuY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBLFNBQVMsZ0JBQWdCLEVBQUU7QUFDM0Isa0JBQWtCLG1CQUFtQixDQUFDIiwiZmlsZSI6ImVtcGxveWVlcy1jb21wb25lbnQvZW1wbG95ZWVzLWNvbXBvbmVudC5jb21wb25lbnQuY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLmNlbnRlcnsgbWFyZ2luLXRvcDo0MHB4OyB9XHJcbi50YWJsZS1yZXNwb25zaXZle21hcmdpbi1ib3R0b206NjBweDt9Il19 */"

/***/ }),

/***/ "./src/app/components/employees-component/employees-component.component.html":
/*!***********************************************************************************!*\
  !*** ./src/app/components/employees-component/employees-component.component.html ***!
  \***********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"center\">\n  <h2>Employees</h2>\n  <p class=\"lead\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique bibendum.</p>\n</div>\n\n<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-md-12\">\n      <input class=\"form-control\" id=\"EmployeeSearch\" name=\"EmployeeSearch\" type=\"text\" placeholder=\"Search Employees by Full Name or Position\" (keyup)=\"onEmployeeSearchKeyUP($event)\" /><br />\n\n      <div class=\"table-responsive\">\n        <table class=\"table table-condensed table-hover\">\n          <thead>\n            <td>Full Name</td>\n            <td>Address</td>\n            <td>Phone Number</td>\n            <td>Hire Date</td>\n          </thead>\n          <tbody >\n            <tr *ngFor=\"let employee of filteredEmployees\" (click)=\"routeEmployee(employee._id)\" [hidden]=\"hidden\">\n              <td>{{ employee.FirstName }} {{ employee.LastName }}</td>\n              <td>{{ employee.AddressStreet }}. {{ employee.AddressState }}, {{ employee.AddressCity }}. {{ employee.AddressZip }}</td>\n              <td>{{ employee.PhoneNum }} ext: {{ employee.Extension }}</td>\n              <td>{{ employee.HireDate | date:'longDate'}}</td>\n            </tr>\n          </tbody>\n        </table>\n      </div>\n\n    </div>\n  </div>\n</div>"

/***/ }),

/***/ "./src/app/components/employees-component/employees-component.component.ts":
/*!*********************************************************************************!*\
  !*** ./src/app/components/employees-component/employees-component.component.ts ***!
  \*********************************************************************************/
/*! exports provided: EmployeesComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "EmployeesComponent", function() { return EmployeesComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _employee_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../employee.service */ "./src/app/components/employee.service.ts");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var EmployeesComponent = /** @class */ (function () {
    function EmployeesComponent(e, router) {
        this.e = e;
        this.router = router;
        this.loadingError = false;
    }
    EmployeesComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.getEmployeesSub = this.e.getEmployees().subscribe(function (data) {
            _this.employees = data;
            _this.filteredEmployees = data;
        }, function () {
            _this.loadingError = true;
        });
    };
    EmployeesComponent.prototype.routeEmployee = function (id) {
        this.router.navigate(['/employee/', id]);
    };
    EmployeesComponent.prototype.onEmployeeSearchKeyUP = function (event) {
        var substring = event.target.value.toLowerCase();
        this.filteredEmployees = this.employees.filter(function (em) {
            return ((em.FirstName.toLowerCase().indexOf(substring) != -1) ||
                (em.LastName.toLowerCase().indexOf(substring) != -1) ||
                (em.Position["PositionName"].toLowerCase().indexOf(substring) != -1));
        });
    };
    EmployeesComponent.prototype.ngOnDestroy = function () {
        if (this.getEmployeesSub != 'undefined') {
            this.getEmployeesSub.unsubscribe();
        }
    };
    EmployeesComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-employees',
            template: __webpack_require__(/*! ./employees-component.component.html */ "./src/app/components/employees-component/employees-component.component.html"),
            styles: [__webpack_require__(/*! ./employees-component.component.css */ "./src/app/components/employees-component/employees-component.component.css")]
        }),
        __metadata("design:paramtypes", [_employee_service__WEBPACK_IMPORTED_MODULE_1__["EmployeeService"], _angular_router__WEBPACK_IMPORTED_MODULE_2__["Router"]])
    ], EmployeesComponent);
    return EmployeesComponent;
}());



/***/ }),

/***/ "./src/app/components/footer-component/footer-component.component.css":
/*!****************************************************************************!*\
  !*** ./src/app/components/footer-component/footer-component.component.css ***!
  \****************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJmb290ZXItY29tcG9uZW50L2Zvb3Rlci1jb21wb25lbnQuY29tcG9uZW50LmNzcyJ9 */"

/***/ }),

/***/ "./src/app/components/footer-component/footer-component.component.html":
/*!*****************************************************************************!*\
  !*** ./src/app/components/footer-component/footer-component.component.html ***!
  \*****************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"color-border\"> </div>\n<footer id=\"footer\">\n  <div class=\"container\">\n    <div class=\"row\">\n      <div class=\"col-sm-6\">Copyright &copy; 2018 Jihyun Yoon (WEB422). Design by <a href=\"http://www.templategarden.com\" rel=\"nofollow\">TemplateGarden</a></div>\n      <div class=\"col-sm-6\">\n        <div class=\"follow-us\"> <a class=\"fa fa-facebook social-icon\" href=\"#\"></a> <a class=\"fa fa-twitter social-icon\" href=\"#\"></a> <a class=\"fa fa-linkedin social-icon\" href=\"#\"></a> <a class=\"fa fa-google-plus social-icon\" href=\"#\"></a> </div>\n      </div>\n    </div>\n  </div>\n</footer>\n<!--/#footer--> \n\n<script src=\"assets/js/jquery.js\"></script> \n<script src=\"assets/js/bootstrap.min.js\"></script> \n<script src=\"assets/js/jquery.prettyPhoto.js\"></script> \n<script src=\"assets/js/jquery.isotope.min.js\"></script> \n"

/***/ }),

/***/ "./src/app/components/footer-component/footer-component.component.ts":
/*!***************************************************************************!*\
  !*** ./src/app/components/footer-component/footer-component.component.ts ***!
  \***************************************************************************/
/*! exports provided: FooterComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "FooterComponent", function() { return FooterComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var FooterComponent = /** @class */ (function () {
    function FooterComponent() {
    }
    FooterComponent.prototype.ngOnInit = function () {
    };
    FooterComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-footer',
            template: __webpack_require__(/*! ./footer-component.component.html */ "./src/app/components/footer-component/footer-component.component.html"),
            styles: [__webpack_require__(/*! ./footer-component.component.css */ "./src/app/components/footer-component/footer-component.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], FooterComponent);
    return FooterComponent;
}());



/***/ }),

/***/ "./src/app/components/home-component/home-component.component.css":
/*!************************************************************************!*\
  !*** ./src/app/components/home-component/home-component.component.css ***!
  \************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "section {\r\n    padding: 70px 0;\r\n}\r\n.no-margin {\r\n    margin: 0;\r\n    padding: 0;\r\n} \r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbImhvbWUtY29tcG9uZW50L2hvbWUtY29tcG9uZW50LmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUE7SUFDSSxnQkFBZ0I7Q0FDbkI7QUFDRDtJQUNJLFVBQVU7SUFDVixXQUFXO0NBQ2QiLCJmaWxlIjoiaG9tZS1jb21wb25lbnQvaG9tZS1jb21wb25lbnQuY29tcG9uZW50LmNzcyIsInNvdXJjZXNDb250ZW50IjpbInNlY3Rpb24ge1xyXG4gICAgcGFkZGluZzogNzBweCAwO1xyXG59XHJcbi5uby1tYXJnaW4ge1xyXG4gICAgbWFyZ2luOiAwO1xyXG4gICAgcGFkZGluZzogMDtcclxufSAiXX0= */"

/***/ }),

/***/ "./src/app/components/home-component/home-component.component.html":
/*!*************************************************************************!*\
  !*** ./src/app/components/home-component/home-component.component.html ***!
  \*************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<section id=\"main-slider\" class=\"no-margin\">\n  <div class=\"carousel slide\">\n    <ol class=\"carousel-indicators\">\n      <li data-target=\"#main-slider\" data-slide-to=\"0\" class=\"active\"></li>\n      <li data-target=\"#main-slider\" data-slide-to=\"1\"></li>\n      <li data-target=\"#main-slider\" data-slide-to=\"2\"></li>\n    </ol>\n    <div class=\"carousel-inner\">\n      <div class=\"item active\" style=\"background-image: url(images/slider/bg1.jpg)\">\n        <div class=\"container\">\n          <div class=\"row slide-margin\">\n            <div class=\"col-sm-12\">\n              <div class=\"carousel-content\">\n                <h1>Welcome to <span class=\"logo\"><i class=\"fa fa-play-circle\"></i> API Demo</span></h1>\n                <h2>Lorem ipsum dolor sit amet, consectetuer adipiscing elit sed diam nonummy nibh euismod tincidunt\n                  laoreet</h2>\n              </div>\n            </div>\n          </div>\n        </div>\n      </div>\n      <!--/.item-->\n\n      <div class=\"item\" style=\"background-image: url(images/slider/bg2.jpg)\">\n        <div class=\"container\">\n          <div class=\"row slide-margin\">\n            <div class=\"col-sm-12\">\n              <div class=\"carousel-content\">\n                <h1>Typi non habent claritatem insitam</h1>\n                <h2>Lorem ipsum dolor sit amet, consectetuer adipiscing elit sed diam nonummy nibh euismod tincidunt\n                  laoreet</h2>\n                <a class=\"btn-slide\" href=\"about-us.html\">Read More</a>\n              </div>\n            </div>\n          </div>\n        </div>\n      </div>\n      <!--/.item-->\n\n      <div class=\"item\" style=\"background-image: url(images/slider/bg3.jpg)\">\n        <div class=\"container\">\n          <div class=\"row slide-margin\">\n            <div class=\"col-sm-12\">\n              <div class=\"carousel-content\">\n                <h1>Mirum est notare quam littera gothica</h1>\n                <h2>Lorem ipsum dolor sit amet, consectetuer adipiscing elit sed diam nonummy nibh euismod tincidunt\n                  laoreet</h2>\n                <a class=\"btn-slide\" href=\"about-us.html\">Read More</a>\n              </div>\n            </div>\n          </div>\n        </div>\n      </div>\n      <!--/.item-->\n    </div>\n    <!--/.carousel-inner-->\n  </div>\n  <!--/.carousel-->\n  <a class=\"prev hidden-xs\" href=\"#main-slider\" data-slide=\"prev\"> <i class=\"fa fa-chevron-left\"></i> </a> <a class=\"next hidden-xs\"\n    href=\"#main-slider\" data-slide=\"next\"> <i class=\"fa fa-chevron-right\"></i> </a>\n</section>\n<!--/#main-slider-->\n<div class=\"color-border\"> </div>\n<section id=\"feature\">\n  <div class=\"container\">\n    <div class=\"center\">\n      <h2>Featured Services</h2>\n      <p class=\"lead\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique\n        bibendum. Nunc quis semper sem.<br>\n        Morbi libero elit elementum quis faucibus ac, condimentum quis nibh.</p>\n    </div>\n    <div class=\"row\">\n      <div class=\"features\">\n        <div class=\"col-md-6 col-sm-6\">\n          <div class=\"feature-wrap\"> <i class=\"fa fa-desktop\"></i>\n            <h2>Employees</h2>\n            <h3>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique.</h3>\n          </div>\n        </div>\n        <!--/.col-md-4-->\n\n        <div class=\"col-md-6 col-sm-6\">\n          <div class=\"feature-wrap\"> <i class=\"fa fa-cogs\"></i>\n            <h2>Positions</h2>\n            <h3>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique.</h3>\n          </div>\n        </div>\n        <!--/.col-md-4-->\n      </div>\n      <!--/.services-->\n    </div>\n    <!--/.row-->\n  </div>\n  <!--/.container-->\n</section>\n<!--/#feature-->"

/***/ }),

/***/ "./src/app/components/home-component/home-component.component.ts":
/*!***********************************************************************!*\
  !*** ./src/app/components/home-component/home-component.component.ts ***!
  \***********************************************************************/
/*! exports provided: HomeComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "HomeComponent", function() { return HomeComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var HomeComponent = /** @class */ (function () {
    function HomeComponent() {
    }
    HomeComponent.prototype.ngOnInit = function () {
    };
    HomeComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-home',
            template: __webpack_require__(/*! ./home-component.component.html */ "./src/app/components/home-component/home-component.component.html"),
            styles: [__webpack_require__(/*! ./home-component.component.css */ "./src/app/components/home-component/home-component.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], HomeComponent);
    return HomeComponent;
}());



/***/ }),

/***/ "./src/app/components/nav-component/nav-component.component.css":
/*!**********************************************************************!*\
  !*** ./src/app/components/nav-component/nav-component.component.css ***!
  \**********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJuYXYtY29tcG9uZW50L25hdi1jb21wb25lbnQuY29tcG9uZW50LmNzcyJ9 */"

/***/ }),

/***/ "./src/app/components/nav-component/nav-component.component.html":
/*!***********************************************************************!*\
  !*** ./src/app/components/nav-component/nav-component.component.html ***!
  \***********************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<nav class=\"navbar navbar-inverse\" role=\"banner\">\n  <div class=\"container\">\n    <div class=\"navbar-header\">\n      <button type=\"button\" class=\"navbar-toggle\" data-toggle=\"collapse\" data-target=\".navbar-collapse\">\n        <span class=\"sr-only\">Toggle navigation</span>\n        <span class=\"icon-bar\"></span>\n        <span class=\"icon-bar\"></span>\n        <span class=\"icon-bar\"></span>\n      </button>\n      <a class=\"navbar-brand\" routerLink=\"/home\">\n        <i class=\"fa fa-play-circle\"></i> Jihyun Yoon (API Demo)</a>\n    </div>\n    <div class=\"collapse navbar-collapse navbar-right\">\n      <ul class=\"nav navbar-nav\">\n        <li routerLinkActive=\"active\">\n          <a routerLink=\"/home\">Home</a>\n        </li>\n        <li routerLinkActive=\"active\">\n          <a routerLink=\"/employees\">Employees</a>\n        </li>\n        <li routerLinkActive=\"active\">\n          <a routerLink=\"/positions\">Positions</a>\n        </li>\n      </ul>\n    </div>\n  </div>\n</nav>"

/***/ }),

/***/ "./src/app/components/nav-component/nav-component.component.ts":
/*!*********************************************************************!*\
  !*** ./src/app/components/nav-component/nav-component.component.ts ***!
  \*********************************************************************/
/*! exports provided: NavComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "NavComponent", function() { return NavComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var NavComponent = /** @class */ (function () {
    function NavComponent() {
    }
    NavComponent.prototype.ngOnInit = function () {
    };
    NavComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-nav',
            template: __webpack_require__(/*! ./nav-component.component.html */ "./src/app/components/nav-component/nav-component.component.html"),
            styles: [__webpack_require__(/*! ./nav-component.component.css */ "./src/app/components/nav-component/nav-component.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], NavComponent);
    return NavComponent;
}());



/***/ }),

/***/ "./src/app/components/page-not-found-component/page-not-found-component.component.css":
/*!********************************************************************************************!*\
  !*** ./src/app/components/page-not-found-component/page-not-found-component.component.css ***!
  \********************************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IiIsImZpbGUiOiJwYWdlLW5vdC1mb3VuZC1jb21wb25lbnQvcGFnZS1ub3QtZm91bmQtY29tcG9uZW50LmNvbXBvbmVudC5jc3MifQ== */"

/***/ }),

/***/ "./src/app/components/page-not-found-component/page-not-found-component.component.html":
/*!*********************************************************************************************!*\
  !*** ./src/app/components/page-not-found-component/page-not-found-component.component.html ***!
  \*********************************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"colmd-12\">\n      Not Found\n    </div>\n  </div>\n</div>"

/***/ }),

/***/ "./src/app/components/page-not-found-component/page-not-found-component.component.ts":
/*!*******************************************************************************************!*\
  !*** ./src/app/components/page-not-found-component/page-not-found-component.component.ts ***!
  \*******************************************************************************************/
/*! exports provided: PageNotFoundComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PageNotFoundComponent", function() { return PageNotFoundComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};

var PageNotFoundComponent = /** @class */ (function () {
    function PageNotFoundComponent() {
    }
    PageNotFoundComponent.prototype.ngOnInit = function () {
    };
    PageNotFoundComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-page-not-found',
            template: __webpack_require__(/*! ./page-not-found-component.component.html */ "./src/app/components/page-not-found-component/page-not-found-component.component.html"),
            styles: [__webpack_require__(/*! ./page-not-found-component.component.css */ "./src/app/components/page-not-found-component/page-not-found-component.component.css")]
        }),
        __metadata("design:paramtypes", [])
    ], PageNotFoundComponent);
    return PageNotFoundComponent;
}());



/***/ }),

/***/ "./src/app/components/position.service.ts":
/*!************************************************!*\
  !*** ./src/app/components/position.service.ts ***!
  \************************************************/
/*! exports provided: PositionService */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PositionService", function() { return PositionService; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_common_http__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/common/http */ "./node_modules/@angular/common/fesm5/http.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};


var PositionService = /** @class */ (function () {
    function PositionService(http) {
        this.http = http;
        this.url = "https://web422-server.herokuapp.com";
    }
    PositionService.prototype.getPositions = function () {
        return this.http.get(this.url + "/positions");
    };
    PositionService.prototype.savePosition = function (position) {
        return this.http.put("https://web422-server.herokuapp.com/position/" + position._id, position);
    };
    PositionService.prototype.getPosition = function (id) {
        return this.http.get("https://web422-server.herokuapp.com/position/" + id);
    };
    PositionService = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Injectable"])(),
        __metadata("design:paramtypes", [_angular_common_http__WEBPACK_IMPORTED_MODULE_1__["HttpClient"]])
    ], PositionService);
    return PositionService;
}());



/***/ }),

/***/ "./src/app/components/position/position.component.css":
/*!************************************************************!*\
  !*** ./src/app/components/position/position.component.css ***!
  \************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".center{ margin-top:40px; }\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInBvc2l0aW9uL3Bvc2l0aW9uLmNvbXBvbmVudC5jc3MiXSwibmFtZXMiOltdLCJtYXBwaW5ncyI6IkFBQUEsU0FBUyxnQkFBZ0IsRUFBRSIsImZpbGUiOiJwb3NpdGlvbi9wb3NpdGlvbi5jb21wb25lbnQuY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLmNlbnRlcnsgbWFyZ2luLXRvcDo0MHB4OyB9Il19 */"

/***/ }),

/***/ "./src/app/components/position/position.component.html":
/*!*************************************************************!*\
  !*** ./src/app/components/position/position.component.html ***!
  \*************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"center\">\n  <h2>Position: Position Name</h2>\n  <p class=\"lead\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique bibendum.</p>\n</div>\n<div class=\"container\">\n  <div class=\"row\">\n    <div class=\"col-md-12\">\n      <form #f=\"ngForm\" (ngSubmit)=\"onSubmit(f)\">\n        <div class=\"row\">\n          <div class=\"col-md-12\">\n            <div class=\"form-group\" [ngClass]=\"{'form-group has-error': PositionName.errors}\">\n              <label class=\"control-label\" for=\"PositionName\">Position Name:</label>\n              <input #PositionName=\"ngModel\" class=\"form-control\" id=\"PositionName\" type=\"text\" name=\"PositionName\"  [(ngModel)]=\"position.PositionName\" required/>\n              <span class=\"help-block\" *ngIf=\"PositionName.errors && PositionName.errors.required\">Position name is Required</span>\n            </div>\n          </div>\n        </div>\n        <div class=\"row\">\n          <div class=\"col-md-12\">\n            <div class=\"form-group\" [ngClass]=\"{'form-group has-error': PositionDescription.errors}\">\n              <label class=\"control-label\" for=\"PositionDescription\">Description:</label>\n              <textarea #PositionDescription=\"ngModel\" class=\"form-control\" id=\"PositionDescription\" rows=\"5\" name=\"PositionDescription\" [(ngModel)]=\"position.PositionDescription\" required></textarea>\n              <span class=\"help-block\" *ngIf=\"PositionDescription.errors && PositionDescription.errors.required\">Position Description is Required</span>\n            </div>\n          </div>\n        </div>\n        <hr />\n        <a [routerLink]=\"['/positions']\" class=\"btn btn-warning pull-left\">Return to Position List</a>\n        <input type=\"submit\" class=\"btn btn-primary pull-right\" value=\"Update Position\" [disabled]=\"!f.valid\" />\n        <br />\n        <br />\n      </form>\n    </div>\n  </div>\n<br />\n<div class=\"alert alert-success\" *ngIf=\"successMessage==true&&position\">\n  <strong>Success!</strong> Position: {{position.PositionName}} was successfully saved.\n</div>\n<div class=\"alert alert-danger\" *ngIf=\"failMessage==true&&position\">\n  <strong>Error!</strong> Position: {{position.PositionName}} could not be saved.\n</div>\n</div>\n<br /><br />"

/***/ }),

/***/ "./src/app/components/position/position.component.ts":
/*!***********************************************************!*\
  !*** ./src/app/components/position/position.component.ts ***!
  \***********************************************************/
/*! exports provided: PositionComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PositionComponent", function() { return PositionComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _position_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../position.service */ "./src/app/components/position.service.ts");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var PositionComponent = /** @class */ (function () {
    function PositionComponent(positionService, route) {
        this.positionService = positionService;
        this.route = route;
        this.successMessage = false;
        this.failMessage = false;
    }
    PositionComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.paramSubscription = this.route.params.subscribe(function (params) {
            _this.positionSubscription = _this.positionService.getPosition(params['_id']).subscribe(function (pos) {
                console.log(pos[0]);
                _this.position = pos[0];
            });
        });
    };
    PositionComponent.prototype.onSubmit = function () {
        var _this = this;
        this.savePositionSubscription = this.positionService.savePosition(this.position).subscribe(function () {
            _this.successMessage = true;
            setTimeout(function () {
                _this.successMessage = false;
            }, 2500);
        }, function () {
            _this.failMessage = true;
            setTimeout(function () {
                _this.failMessage = false;
            }, 2500);
        });
    };
    PositionComponent.prototype.ngOnDestroy = function () {
        if (this.paramSubscription) {
            this.paramSubscription.unsubscribe();
        }
        if (this.positionSubscription) {
            this.positionSubscription.unsubscribe();
        }
        if (this.savePositionSubscription) {
            this.savePositionSubscription.unsubscribe();
        }
    };
    PositionComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-position',
            template: __webpack_require__(/*! ./position.component.html */ "./src/app/components/position/position.component.html"),
            styles: [__webpack_require__(/*! ./position.component.css */ "./src/app/components/position/position.component.css")]
        }),
        __metadata("design:paramtypes", [_position_service__WEBPACK_IMPORTED_MODULE_1__["PositionService"], _angular_router__WEBPACK_IMPORTED_MODULE_2__["ActivatedRoute"]])
    ], PositionComponent);
    return PositionComponent;
}());



/***/ }),

/***/ "./src/app/components/positions-component/positions-component.component.css":
/*!**********************************************************************************!*\
  !*** ./src/app/components/positions-component/positions-component.component.css ***!
  \**********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = ".center{ margin-top:40px; }\r\n.table-responsive{margin-bottom:60px;}\r\n/*# sourceMappingURL=data:application/json;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbInBvc2l0aW9ucy1jb21wb25lbnQvcG9zaXRpb25zLWNvbXBvbmVudC5jb21wb25lbnQuY3NzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBLFNBQVMsZ0JBQWdCLEVBQUU7QUFDM0Isa0JBQWtCLG1CQUFtQixDQUFDIiwiZmlsZSI6InBvc2l0aW9ucy1jb21wb25lbnQvcG9zaXRpb25zLWNvbXBvbmVudC5jb21wb25lbnQuY3NzIiwic291cmNlc0NvbnRlbnQiOlsiLmNlbnRlcnsgbWFyZ2luLXRvcDo0MHB4OyB9XHJcbi50YWJsZS1yZXNwb25zaXZle21hcmdpbi1ib3R0b206NjBweDt9Il19 */"

/***/ }),

/***/ "./src/app/components/positions-component/positions-component.component.html":
/*!***********************************************************************************!*\
  !*** ./src/app/components/positions-component/positions-component.component.html ***!
  \***********************************************************************************/
/*! no static exports found */
/***/ (function(module, exports) {

module.exports = "<div class=\"center\">\n  <h2>Positions</h2>\n  <p class=\"lead\">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin non odio sed eros tristique bibendum.</p>\n  </div>\n\n<div class=\"container\">\n<div class=\"row\">\n  <div class=\"col-md-12\">\n    \n      <div class=\"table-responsive\">\n          <table class=\"table table-condensed table-hover\">\n            <thead> \n              <td>Position Title</td>\n              <td>Position Description</td>\n              <td>Salary</td>\n            </thead>\n            <tbody >\n              <tr *ngFor=\"let position of positions\" (click)=\"routePosition(position._id)\">\n                <td>{{ position.PositionName }}</td>\n                <td>{{ position.PositionDescription }}</td>\n                <td>${{ position.PositionBaseSalary | number:'.2' }}</td>\n              </tr>\n            </tbody>\n          </table>\n        </div>\n\n  </div>\n</div>\n</div>"

/***/ }),

/***/ "./src/app/components/positions-component/positions-component.component.ts":
/*!*********************************************************************************!*\
  !*** ./src/app/components/positions-component/positions-component.component.ts ***!
  \*********************************************************************************/
/*! exports provided: PositionsComponent */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "PositionsComponent", function() { return PositionsComponent; });
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _position_service__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! ../position.service */ "./src/app/components/position.service.ts");
/* harmony import */ var _angular_router__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! @angular/router */ "./node_modules/@angular/router/fesm5/router.js");
var __decorate = (undefined && undefined.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (undefined && undefined.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};



var PositionsComponent = /** @class */ (function () {
    function PositionsComponent(p, router) {
        this.p = p;
        this.router = router;
        this.loadingError = false;
    }
    PositionsComponent.prototype.ngOnInit = function () {
        var _this = this;
        this.getPositionSub = this.p.getPositions()
            .subscribe(function (positions) { return _this.positions = positions; }, function (e) { this.loadingError = true; });
    };
    PositionsComponent.prototype.routePosition = function (id) {
        this.router.navigate(['/position/', id]);
    };
    PositionsComponent.prototype.ngOnDestroy = function () {
        console.log(this.getPositionSub);
        if (this.getPositionSub != 'undefined') {
            this.getPositionSub.unsubscribe();
        }
    };
    PositionsComponent = __decorate([
        Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["Component"])({
            selector: 'app-positions',
            template: __webpack_require__(/*! ./positions-component.component.html */ "./src/app/components/positions-component/positions-component.component.html"),
            styles: [__webpack_require__(/*! ./positions-component.component.css */ "./src/app/components/positions-component/positions-component.component.css")]
        }),
        __metadata("design:paramtypes", [_position_service__WEBPACK_IMPORTED_MODULE_1__["PositionService"], _angular_router__WEBPACK_IMPORTED_MODULE_2__["Router"]])
    ], PositionsComponent);
    return PositionsComponent;
}());



/***/ }),

/***/ "./src/environments/environment.ts":
/*!*****************************************!*\
  !*** ./src/environments/environment.ts ***!
  \*****************************************/
/*! exports provided: environment */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony export (binding) */ __webpack_require__.d(__webpack_exports__, "environment", function() { return environment; });
// This file can be replaced during build by using the `fileReplacements` array.
// `ng build --prod` replaces `environment.ts` with `environment.prod.ts`.
// The list of file replacements can be found in `angular.json`.
var environment = {
    production: false
};
/*
 * For easier debugging in development mode, you can import the following file
 * to ignore zone related error stack frames such as `zone.run`, `zoneDelegate.invokeTask`.
 *
 * This import should be commented out in production mode because it will have a negative impact
 * on performance if an error is thrown.
 */
// import 'zone.js/dist/zone-error';  // Included with Angular CLI.


/***/ }),

/***/ "./src/main.ts":
/*!*********************!*\
  !*** ./src/main.ts ***!
  \*********************/
/*! no exports provided */
/***/ (function(module, __webpack_exports__, __webpack_require__) {

"use strict";
__webpack_require__.r(__webpack_exports__);
/* harmony import */ var _angular_core__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! @angular/core */ "./node_modules/@angular/core/fesm5/core.js");
/* harmony import */ var _angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! @angular/platform-browser-dynamic */ "./node_modules/@angular/platform-browser-dynamic/fesm5/platform-browser-dynamic.js");
/* harmony import */ var _app_app_module__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! ./app/app.module */ "./src/app/app.module.ts");
/* harmony import */ var _environments_environment__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./environments/environment */ "./src/environments/environment.ts");




if (_environments_environment__WEBPACK_IMPORTED_MODULE_3__["environment"].production) {
    Object(_angular_core__WEBPACK_IMPORTED_MODULE_0__["enableProdMode"])();
}
Object(_angular_platform_browser_dynamic__WEBPACK_IMPORTED_MODULE_1__["platformBrowserDynamic"])().bootstrapModule(_app_app_module__WEBPACK_IMPORTED_MODULE_2__["AppModule"])
    .catch(function (err) { return console.error(err); });


/***/ }),

/***/ 0:
/*!***************************!*\
  !*** multi ./src/main.ts ***!
  \***************************/
/*! no static exports found */
/***/ (function(module, exports, __webpack_require__) {

module.exports = __webpack_require__(/*! C:\Users\nicky\Documents\Github\Seneca_College\WEB422\Assign6_TempDrivenAngular\src\main.ts */"./src/main.ts");


/***/ })

},[[0,"runtime","vendor"]]]);
//# sourceMappingURL=main.js.map