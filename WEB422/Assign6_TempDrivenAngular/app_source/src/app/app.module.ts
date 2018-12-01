import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { HttpModule } from '@angular/http';
import { AppRoutingModule } from './app-routing.module';

import { AppComponent } from './app.component';
import { HomeComponent } from './components/home-component/home-component.component';
import { EmployeesComponent } from './components/employees-component/employees-component.component';
import { PositionsComponent } from './components/positions-component/positions-component.component';
import { FooterComponent } from './components/footer-component/footer-component.component';
import { NavComponent } from './components/nav-component/nav-component.component';
import { ContentComponent } from './components/content-component/content-component.component';
import { PageNotFoundComponent } from './components/page-not-found-component/page-not-found-component.component';

import { HttpClientModule } from "@angular/common/http";
import { EmployeeService } from './components/employee.service';
import { PositionService } from './components/position.service';
import { EmployeeComponent } from './components/employee/employee.component';
import { PositionComponent } from './components/position/position.component';
@NgModule({
  declarations: [
    AppComponent,
    ContentComponent,
    FooterComponent,
    HomeComponent,
    EmployeesComponent,
    PositionsComponent,
    NavComponent,
    PageNotFoundComponent,
    EmployeeComponent,
    PositionComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpModule,
    AppRoutingModule,
    HttpClientModule
  ],
  providers: [PositionService, EmployeeService],
  bootstrap: [AppComponent]
})
export class AppModule { }
