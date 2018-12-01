import { Component, OnInit, OnDestroy } from '@angular/core';
import { EmployeeService } from '../employee.service';
import { Employee } from '../employee';
import { Router } from "@angular/router";

@Component({
  selector: 'app-employees',
  templateUrl: './employees-component.component.html',
  styleUrls: ['./employees-component.component.css']
})

export class EmployeesComponent implements OnInit, OnDestroy {

  private employees: Employee[];
  private getEmployeesSub;
  private loadingError: boolean = false;
  filteredEmployees: Employee[];

  constructor(private e: EmployeeService, private router: Router) { }

  ngOnInit() {
    this.getEmployeesSub = this.e.getEmployees().subscribe(data => {
      this.employees = data;
      this.filteredEmployees = data;
    },
      () => {
        this.loadingError = true;
      });
  }


  routeEmployee(id: string) {
    this.router.navigate(['/employee/', id]);
  }

  onEmployeeSearchKeyUP(event: any) {
    let substring: string = event.target.value.toLowerCase();
    this.filteredEmployees = this.employees.filter((em) => 
    ((em.FirstName.toLowerCase().indexOf(substring) != -1) || 
    (em.LastName.toLowerCase().indexOf(substring) != -1) ||
    (em.Position["PositionName"].toLowerCase().indexOf(substring) != -1)))

  }

  ngOnDestroy() {
    if(this.getEmployeesSub != 'undefined') {
      this.getEmployeesSub.unsubscribe();
    }
  }

}