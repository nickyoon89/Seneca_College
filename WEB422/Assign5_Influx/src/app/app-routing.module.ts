import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { HomeComponent } from './components/home-component/home-component.component';
import { EmployeesComponent } from './components/employees-component/employees-component.component';
import { PositionsComponent } from './components/positions-component/positions-component.component';
import { PageNotFoundComponent } from './components/page-not-found-component/page-not-found-component.component';

const routes: Routes = [
  { path: 'home', component: HomeComponent },
  { path: 'employees', component: EmployeesComponent },
  { path: 'positions', component: PositionsComponent },
  { path: '', redirectTo: '/home', pathMatch: 'full' },
  { path: '**', component: PageNotFoundComponent }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule],
  providers: []
})
export class AppRoutingModule { }
